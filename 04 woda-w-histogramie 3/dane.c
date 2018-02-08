#include <stdio.h>
#include "dane.h"

void print_dane(struct Dane dane) {
    printf("(%d, %d) ", dane.indeks, dane.wartosc);
}
