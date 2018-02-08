#include "woda.h"

int sprawdzPare(int popr, int nast, struct Wezel **pStos, int index);

int slupWiekszyNizNaStosie(int popr, int nast, struct Wezel **pStos, int index){
    int tmpPopr = peek(*pStos).wartosc;
    int akumulator = (index - peek(*pStos).indeks)
                     * (tmpPopr - popr);
    pop(pStos);

    return akumulator + sprawdzPare(tmpPopr, nast, pStos, index);
}

int slupMniejszyNizNaStosie(int popr, int nast, struct Wezel **pStos, int index){
    return (index - peek(*pStos).indeks) * (nast - popr);
}

int kiedyWzrasta(int popr, int nast, struct Wezel **pStos, int index) {
    if(isEmpty(*pStos)){
        return 0;
    } else if(peek(*pStos).wartosc <= nast){
        // sprawdzamy czy element na stosie
        // jest mniejszy od aktualnego Slupa
        return slupWiekszyNizNaStosie(popr, nast, pStos, index);
    } else{
        return slupMniejszyNizNaStosie(popr, nast, pStos, index);
    }
}

int sprawdzPare(int popr, int nast, struct Wezel **pStos, int index){
    if(popr < nast) { //histogram wzrasta
        kiedyWzrasta(popr, nast, pStos, index);
    } else if (popr > nast) { //histogram maleje
        struct Dane para = {index, popr};
        push(pStos, para);
        return 0;
    } else {
        return 0;
    }
}

int policzWode(int* histogram){
    int woda = 0;
    struct Wezel *stos = NULL;

    if(N < 3) return 0;

    for(int index = 1; index < N; ++index){
        int popr = histogram[index - 1];
        int nast = histogram[index];

        woda += sprawdzPare(popr, nast, &stos, index);
    }

    return woda;
}