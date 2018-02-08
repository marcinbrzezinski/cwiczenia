#include "stos.h"

struct Wezel* nowy(struct Dane dane){
    struct Wezel *wezel;

    wezel = (struct Wezel*)malloc(sizeof(struct Wezel));
    if(wezel == NULL){
        printf("Brak pamieci!");
        exit(EXIT_FAILURE);
    }

    wezel->dane = dane;
    wezel->popr = NULL;

    return wezel;
}

void push(struct Wezel **pTop, struct Dane dane){
    struct Wezel* wezel = nowy(dane);

    wezel->popr = *pTop; // w nowym wezle wskaz top
    *pTop = wezel; // top wskazuje teraz na nowy wezel

    printf("Para (%d, %d) odlozona na stosie\n",
           dane.indeks, dane.wartosc);
}

struct Dane pop(struct Wezel **pTop){
    struct Wezel *tymczasowy_wezel = *pTop;
    struct Dane odczytane_dane = tymczasowy_wezel->dane;
    *pTop = (*pTop)->popr;
    free(tymczasowy_wezel);

    return odczytane_dane;
}

struct Dane peek(struct Wezel *pTop){
    return pTop->dane;
}

int isEmpty(struct Wezel *top){
    return !top;
}

void print(struct Wezel *top){
    if(!isEmpty(top)){
        if(top->popr != NULL){
            print(top->popr);
        }
        print_dane(top->dane);
    }
}

