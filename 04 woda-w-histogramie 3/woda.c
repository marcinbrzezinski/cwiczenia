#include "woda.h"

int kiedyWzrasta(int popr, int nast, struct Wezel **pStos, int index){

}


int sprawdzPare(int popr, int nast, struct Wezel **pStos, int index){
    if(popr < nast){ //histogram wzrasta
        kiedyWzrasta(popr, nast, &pStos, index);
    }else if (popr > nast){        // histogram maleje
        struct Dane para = {index, popr};
        push(pStos, para);
    }else{
        return 0;
    }
}

int policzWode(int* histogram){
    int woda = 0;

    if(N < 3) return 0;

    for(int index = 1; index <N; ++index){
        int popr = histogram[index - 1;
        int nast = histogram[index];

        woda += sprawdzPare(popr, nast, &stos, index);
    }

    return woda;
}