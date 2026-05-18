#include <stdlib.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>

int size;
int buffers[] = {-1,-1,-1};
int _garbage_bin;
int current_dir;

char slikica[999999];

typedef struct _thing {
     struct _thing* prev;
     struct _thing* next;
     int whatami; // 0-head, 1-bodi, 2-apol
     int whereamilooking;
     int amieatingapol;
     void (*whatdoido)(struct _thing*);
     int x;
     int y;
} thing;

thing* snakeass;
thing* snakehed;
thing* whereismyfood;

// 0:👆, 1:👉, 2:👇, 3:👈
char* whatdoilooklike🤔[] = {"\U0001F446", "\U0001F449", "\U0001F447", "\U0001F448", ":)", "🮋🮋"};
thing*** game;

void waiteranotherapolplease();

void putbroonthemap(thing* him) {
    game[him->y][him->x] = him;
}

void iamapple(thing* me) {
    putbroonthemap(me);
}

void movesnek(thing* me) {
    if (me == snakeass && snakeass != snakehed) {
        int oldx = me->x;
        int oldy = me->y;

        me->x = (snakehed->x + (1 - (current_dir & 2)) * (current_dir & 1) + size) % size;
        me->y = (snakehed->y + ((current_dir & 2) - 1) * ((current_dir & 1) ^ 1) + size) % size;

        if (me->x == whereismyfood->x && me->y == whereismyfood->y) {
            thing* tail = (thing*)calloc(1, sizeof(thing));
            tail->whatami = 1;
            tail->x = oldx;
            tail->y = oldy;
            tail->whatdoido = movesnek;
            tail->next = me->next;
            me->next->prev = tail;
            snakeass = tail;

            waiteranotherapolplease();
        } else {
            snakeass = me->next;
            snakeass->prev = NULL;
        }

        snakehed->next = me;
        me->prev = snakehed;
        me->next = NULL;
        
        snakehed->whereamilooking = current_dir;
        snakehed->whatami = 1;

        me->whatami = 0;
        me->whereamilooking = current_dir;
        
        snakehed = me;
    }
}

void printboard() {
     printf("\x1b[H");

     printf("Aplel: %d %d\r\n", whereismyfood->x, whereismyfood->y);

     for (int y = 0; y < size; y++) {
          for (int x = 0; x < size; x++) {
               if (game[y][x]) {
                    int sprite = game[y][x]->whatami == 0 ? game[y][x]->whereamilooking : 
                                 game[y][x]->whatami == 2 ? 4 : 5;
                    printf("%s", whatdoilooklike🤔[sprite]);
                    if (game[x][y] == snakehed) printf("\x1b[A");
                    game[y][x] = NULL;
               } else {
                    printf("  ");
               }
          }
          printf("\r\n");
     }

     fflush(stdout);
}

void dosomebullshit() {
     struct termios 🖳;
     tcgetattr(0, &🖳);
     🖳.c_lflag &= ~(ICANON | ECHO); 
     tcsetattr(0, 0, &🖳);
     fcntl(0, F_SETFL, fcntl(0, F_GETFL) | O_NONBLOCK);

     setvbuf(stdout, slikica, _IOFBF, sizeof(slikica));
}

void GETKEYS() {
    for(char 🚾; read(0,&🚾,1)>0;)
        if(🚾=='w'||🚾=='a'||🚾=='s'||🚾=='d')
            *( (*buffers<0) ? buffers : (1[buffers]<0) ? buffers+1 : (2[buffers]<0) ? buffers+2 : &_garbage_bin ) = (🚾>>1&3)^3;
}

void SHIFTBUFFER() {
    *buffers=1[buffers], 1[buffers]=2[buffers], 2[buffers]=-1;
}

void waiteranotherapolplease() {
    thing* apol = (thing*) calloc(1, sizeof(thing));
    apol->whatami = 2;
    apol->whatdoido = &iamapple;

    yummy:
    apol->x = (int) rand() / (double) RAND_MAX * size;
    apol->y = (int) rand() / (double) RAND_MAX * size;

    for (thing* snek = snakeass; snek->next != NULL; snek = snek->next) {
        if (snek->x == apol->x && snek->y == apol->y) goto yummy;
    }

    printf("Aplel: %d %d\r\n", apol->x, apol->y);
    fflush(stdout);

    putbroonthemap(apol);

    whereismyfood = apol;
}

int main() {
    srand(time(NULL));

    void* john = &john;
    current_dir = 1;

    printf("How beef? => ");
    scanf("%d", &size);

    game = (thing***) calloc(size, sizeof(thing**));
    for (int i = 0; i < size; i++) {
         game[i] = (thing**) calloc(size, sizeof(thing*));
    }

    snakehed = (thing*)calloc(1, sizeof(thing));
    snakehed->whatami = 0;
    snakehed->whereamilooking = 1;
    snakehed->x = size / 2;
    snakehed->y = size / 2;
    snakehed->whatdoido = movesnek;

    thing* body = (thing*)calloc(1, sizeof(thing));
    body->whatami = 1;
    body->x = size / 2 - 1;
    body->y = size / 2;
    body->whatdoido = movesnek;
    body->next = snakehed;
    snakehed->prev = body;

    thing* tail = (thing*)calloc(1, sizeof(thing));
    tail->whatami = 1;
    tail->x = size / 2 - 2;
    tail->y = size / 2;
    tail->whatdoido = movesnek;
    tail->next = body;
    body->prev = tail;
    
    snakeass = tail;

    dosomebullshit();

    int hi = 0;

    waiteranotherapolplease();

    while (1) {
        if (hi > 10) {
            hi = 0;
            system("head -c 4000 /dev/urandom | aplay -c 1 -q -t raw -f U8 -r 44100 2>/dev/null &");
        } hi++;

        for(int i=0; i<size; i++) for(int j=0; j<size; j++) game[i][j] = NULL;

        GETKEYS(); 
        
        if (*buffers != -1) {
            int new_dir = *buffers;
            SHIFTBUFFER();
             
            if ((current_dir ^ new_dir) != 2) {
                current_dir = new_dir;
            }
        }

        if (snakeass) snakeass->whatdoido(snakeass);
        if (whereismyfood) whereismyfood->whatdoido(whereismyfood);
        
        for (thing* p = snakeass; p; p = p->next) {
            putbroonthemap(p);
        }

        printboard();
        
        usleep(70000);
    }
}