#include "woda.h"

void policz_h_max_od_prawej(const int *histogram, int *h_prawy) {
    h_prawy[N - 1] = histogram[N - 1];
    for (int p = N - 2; p >= 0; --p) {
        h_prawy[p] = MAX(histogram[p], h_prawy[p + 1]);
    }
}

void policz_h_max_od_lewej(const int *histogram, int *h_lewy) {
    h_lewy[0] = histogram[0];
    for (int l = 1; l < N; ++l) {
        h_lewy[l] = MAX(h_lewy[l - 1], histogram[l]);
    }
}

int policzWode(int *histogram) {
    int h_lewy[N];
    int h_prawy[N];
    int woda = 0;

    policz_h_max_od_lewej(histogram, h_lewy);
    policz_h_max_od_prawej(histogram, h_prawy);

    for (int k = 0; k < N; ++k) {
        woda += MIN(h_lewy[k], h_prawy[k]) - histogram[k];
    }

    return woda;
}

