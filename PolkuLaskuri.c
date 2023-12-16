#include <stdio.h>
#include <stdint.h>
#include <math.h>

struct piste {
    int koordinaatit[3];
    struct piste *seuraava;
};

struct polku {
    double matka;
    struct piste *pisteet;
};

double etaisyys(struct piste *p1, struct piste *p2);

void laske_kuljettu_matka(struct polku *polku);


double etaisyys(struct piste *p1, struct piste *p2) {
    double summa = 0.0;

    for (int i = 0; i < 3; i++) {
        double erotus = p1->koordinaatit[i] - p2->koordinaatit[i];
        summa += erotus * erotus;
    }
    return sqrt(summa);
}

void laske_kuljettu_matka (struct polku *polku) {
    if (polku == NULL || polku->pisteet == NULL || polku->pisteet->seuraava == NULL) {
        polku->matka = 0.0;
        return;
    }

    struct piste *current = polku->pisteet;
    struct piste *next = current->seuraava;
    double distance = 0.0;

    while (next != NULL) {
        distance += etaisyys(current, next);
        current = next;
        next = current->seuraava;
    }

    polku->matka = distance;
}
