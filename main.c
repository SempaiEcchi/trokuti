#include <stdio.h>
#include <math.h>


static const double oneRadInDeg = 57.296;

///Type defs
double izracunajPovrsinu(double a, double b, double c, int izbor);

double izracunajOpseg(double a, double b, double c, int izbor);

void unosIspis(int izbor, double *a, double *b, double *c);

double izracunajPovrsinu(double a, double b, double c, int izbor) {
    double povrsina;

    if (izbor == 1) {
        double s = (a + b + c) / 2;
        povrsina = sqrt(s * (s - a) * (s - b) * (s - c));
    } else if (izbor == 2) {
        c = c / oneRadInDeg;
        povrsina = a * b * sin(c) / 2;

    } else if (izbor == 3) {
        b = b / oneRadInDeg;
        c = c / oneRadInDeg;
        povrsina = a * a * sin(b) * sin(c) / (2 * sin(3.14159 - b - c));
    }

    return povrsina;
}

double izracunajOpseg(double a, double b, double c, int izbor) {
    double opseg;

    if (izbor == 1) {
        opseg = a + b + c;
    } else if (izbor == 2) {
        c = c / oneRadInDeg;
        c = sqrt(a * a + b * b - 2 * a * b * cos(c));
        opseg = a + b + c;

    } else if (izbor == 3) {
        double alfa = (180 - b - c) / oneRadInDeg;
        b = b / oneRadInDeg;
        c = c / oneRadInDeg;
        b = a * sin(b) / sin(alfa);
        c = a * sin(c) / sin(alfa);
        opseg = a + b + c;
    }

    return opseg;
}

int main() {
    int izbor;
    char unosZaPonavljanje;
    while (1) {

        printf("1.Duzinom tri stranice\n");
        printf("2.dužinom dvije stranice i kutom između njih\n");
        printf("3.dužinom jedne stranice i dva, njoj priležeća kuta.\n");
        printf("Unesite neki broj od 1-3\n");
        scanf(" %d", &izbor);

        switch (izbor) {
            case 1: {
                double a, b, c;
                printf("Upisite stranice\n");
                unosIspis(izbor, &a, &b, &c);

            }

                break;

            case 2: {
                double a, b, c;
                printf("Upisite dvije stranice i kut\n");
                unosIspis(izbor, &a, &b, &c);

            }
                break;

            case 3: {
                double a, b, c;
                printf("Upisite jednu stranicu i dva kuta\n");
                unosIspis(izbor, &a, &b, &c);
            }

            default:
                printf("Krivi unos");
        }


        start:
        printf("Upisi Y za ponovno računanje, N za zaustavljanje programa\n");
        scanf(" %c", &unosZaPonavljanje);
        if (unosZaPonavljanje == 'Y') {
            printf("Novi upis : \n");
        } else if (unosZaPonavljanje == 'N') {
            break;
        } else {
            goto start;
        }
    }

    return 0;
}

void unosIspis(int izbor, double *a, double *b, double *c) {

    scanf("%lf", a);
    scanf("%lf", b);
    scanf("%lf", c);
    printf("Povrsina je %lf\n", izracunajPovrsinu((*a), (*b), (*c), izbor));
    printf("Opseg je %lf\n", izracunajOpseg((*a), (*b), (*c), izbor));
}

