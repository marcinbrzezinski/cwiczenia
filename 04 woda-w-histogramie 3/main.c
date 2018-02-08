#include <stdio.h>
#include "woda.h"

int main() {
    int histogram[12] = {0, 1, 0, 2, 1, 0, 1, 5, 2, 1, 2, 1};

    printf("Maksymalny stan dla zgromadzonej wody wynosi: %d.\n", policzWode(histogram));

    return 0;
}
