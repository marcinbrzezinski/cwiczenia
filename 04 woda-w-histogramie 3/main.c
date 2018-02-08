#include <stdio.h>
#include "woda.h"

int main() {
    int histogram[N] = {1, 2, 1, 1, 4, 2, 1, 3, 1};

    printf("Maksymalny stan dla zgromadzonej wody wynosi: %d.\n",
           policzWode(histogram));

    return 0;
}
