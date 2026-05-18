#include <stdlib.h>
#include <stdio.h>

typedef struct _node
{
     int value;
     struct _node *next;
     struct _node *prev;
} node;

void printarray(int* array, int len) {
     printf("[%d", array[0]);
     for (int i = 1; i < len; i++) {
          printf(", %d", array[i]);
     }
     printf("]\n");
}

node *makefromarray(int *array, int len, node *thelastone) {
     node *this = (node *)calloc(1, sizeof(node));
     this->value = array[0];
     this->prev = thelastone;

     if (len == 1)
     {
          this->next = NULL;
          return this;
     }

     this->next = makefromarray(array + 1, len - 1, this);

     return this;
}

void printlist(node *list) {
     if (list->prev != NULL)
          printf(", ");
     else
          printf("{");

     printf("%d", list->value);

     if (list->next == NULL)
     {
          printf("}\n");
          return;
     }

     printlist(list->next);
}

int issorted(int* array, int len) {
     for (int i = 1; i < len; i++) {
          if (array[i] < array[i-1]) return 0;
     }

     return 1;
}

void swap(int* array, int a, int b) {
     int temp = array[a];
     array[a] = array[b];
     array[b] = temp;
}

void swapnode(node* a, node* b) {
     int temp = a -> value;
     a -> value = b -> value;
     b -> value = temp;
}

void selectionsort(int* array, int len) {
     for (int i = 0; i <= len - 2; i++) {
          int minindex = i;
          for (int j = i+1; j <= len - 1; j++) {
               if (array[j] < array[minindex]) minindex = j;
          }
          swap(array, i, minindex);
     }
}

node* selectionsortlist(node* a) {
     if (a -> next == NULL) return a;

     node* minnode = a;
     for (node* i = a; i != NULL; i = i -> next) {
          if (i -> value < minnode -> value) {
               minnode = i;
          }
     }
     swapnode(a, minnode);
     a -> next = selectionsortlist(a -> next);

     return a;
}

int main() {
     int array[] = {12,61,46,157,1,23,543,6,57,45,214,4,36,57,4,58,6314,246,547,345,1,215,7,8,34,135,325,1436,7,34,21,6,78,34,235,7,15,357,214,613,6143,75,8,234,2,75,4,24,36,7,8,134,37,548,246,8356,254,8,56,8542,585,6,2,5243,62537,486,1,-1};
     int ogarray[] = {12, 61, 46, 157, 1, 23, 543, 6, 57, 45, 214, 4, 36, 57, 4, 58, 6314, 246, 547, 345, 1, 215, 7, 8, 34, 135, 325, 1436, 7, 34, 21, 6, 78, 34, 235, 7, 15, 357, 214, 613, 6143, 75, 8, 234, 2, 75, 4, 24, 36, 7, 8, 134, 37, 548, 246, 8356, 254, 8, 56, 8542, 585, 6, 2, 5243, 62537, 486, 1, -1};

     int len = 1;
     for (int i = 0; array[i] != -1; i++) {
          len++;
     }

     node* list = makefromarray(array, len, NULL);

     selectionsort(array, len);
     printarray(array, len);

     list = selectionsortlist(list);
     printlist(list);

     return 1;
}
