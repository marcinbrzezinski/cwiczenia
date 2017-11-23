/* == Rozwiązywanie układu równań  == */
/* == a1x + b1y = c1  == */
/* == a2x + b2y = c2  == */
/* == Autor: mł. asp. Marcin Brzeziński == */
/* == Wyższa Szkoła Policji w Szczytnie == */ 
/* == Data: 23.11.2017 ==*/

#include <stdio.h>

void wczytaj(double *a1, double *b1, double *c1,
	     double *a2, double *b2, double *c2)
{
	puts("Podaj współczynik a1: ");
        scanf("%lf", a1);
        puts("Podaj współczynnik b1: ");
        scanf("%lf", b1);
        puts("Podaj współczynnik c1: ");
        scanf("%lf", c1);
        puts("Podaj współczynnik a2: ");
        scanf("%lf", a2);
        puts("Podaj współczynnik b2: ");
        scanf("%lf", b2);
        puts("Podaj współczynnik c2: ");
	scanf("%lf", c2);
}

double wyznacznik_glowny(double a1, double a2, double b1, double b2){
	return a1*b2 - b1*a2;
}

double wyznacznik_x(double b1, double b2, double c1, double c2){
	return c1*b2 - b1*c2;
}

double wyznacznik_y(double a1, double a2, double c1, double c2){
	return a1*c2 - c1*a2;
}

int main()
{
	printf("\n\n");
        printf("==================================\n");
        printf("== Rozwiązywanie układu równań  ==\n");
	printf("==        a1x + b1y = c1        ==\n");
	printf("==        a2x + b2y = c2        ==\n");
        printf("==================================\n\n");
        printf("Autor: mł. asp. Marcin Brzeziński\n");
        printf("Wyższa Szkoła Policji w Szczytnie\n");
        printf("Data: 23.11.2017\n");
	printf("---------------------------------\n\n\n");


	double a1, b1, c1, a2, b2, c2;
	double w, wx, wy;

	wczytaj(&a1, &b1, &c1, &a2, &b2, &c2);

	w = wyznacznik_glowny(a1, a2, b1, b2);
	wx = wyznacznik_x(c1, c2, b1, b2);
	wy = wyznacznik_y(a1, a2, c1, c2);

        if(w!=0)
	{
		printf("x = %lf\n", wx/w);
		printf("y = %lf\n", wy/w);
        }

        return 0;
}
