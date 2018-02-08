#include <stdio.h>
#include <malloc.h>

struct Dane{
    int indeks;
    int wartosc;
};

struct Wezel{
    struct Dane dane;
    struct Wezel *nast;
};

void push(struct Wezel **pTop, struct Dane dane){
    struct Wezel *wezel;

    wezel = (struct Wezel*)malloc(sizeof(struct Wezel));
    if(wezel ==NULL){
        printf("Brak pamieci!");
        exit(EXIT_FAILURE);
    }

    wezel->dane = dane;
    wezel->nast = NULL

}


int main() {



}