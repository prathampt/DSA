#include <stdio.h>
#include "header.h"

void readDistance(Distance *d) {
    printf("Enter the distance in kms and meters: ");
    scanf("%d %d", &d->kms, &d->meters);
}

void displayDistance(Distance d) {
    printf("%d kms %d meters\n", d.kms, d.meters);
}

Distance addDistances(Distance d1, Distance d2) {
    Distance result;
    result.kms = d1.kms + d2.kms;
    result.meters = d1.meters + d2.meters;
    if (result.meters >= 1000) {
        result.kms += result.meters / 1000;
        result.meters %= 1000;
    }
    return result;
}

Distance subtractDistances(Distance d1, Distance d2) {
    Distance result;
    result.kms = d1.kms - d2.kms;
    result.meters = d1.meters - d2.meters;

    if (result.kms < 0) {
        printf("Subtracting first distance form second as second distance is larger:\n");
        result.kms = - result.kms;
        result.meters = - result.meters;

    }
    if (result.meters < 0) {
        result.kms--;
        result.meters += 1000;
    }
    return result;
}