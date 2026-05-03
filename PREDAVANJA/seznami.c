#include <stdlib.h>
#include <stdio.h>

typedef struct _node
{
    int value;
    struct _node* next;
    struct _node* prev;
} node;

node* makefromarray(int*, int, node*);

node* makefromarray(int* array, int len, node* thelastone) {
    node* this = (node*) calloc(1, sizeof(node));
    this -> value = array[0];
    this -> prev = thelastone;

    if (len == 1) {
        this -> next = NULL;
        return this;
    }

    this -> next = makefromarray(array + 1, len - 1, this);

    return this;
}

void printlist(node* list) {
    if (list -> prev != NULL) printf(", ");
    else printf("{");

    printf("%d", list -> value);

    if (list -> next == NULL) {
        printf("}\n");
        return;
    }

    printlist(list -> next);
}

int length(node* list) {
    int len = 1;
    while (list -> next != NULL) {
        len++;
        list = list -> next;
    }

    return len;
}

void sortlist(node* list) {
    node* a = list;
    node* b = list -> next;

    int len = length(list);
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < len; j++) {
            if (a -> value > b -> value) {}
        }
    }
}

int main() {
    int array[10] = {3,5,1,6,7,2,7,9,234,-7};

    node* list = makefromarray(array, 10, NULL);

    printlist(list);
}

