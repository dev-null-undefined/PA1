#ifndef __PROGTEST__

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <langinfo.h>
#include <limits.h>
#include "energy_calculator.h"

int x = 0;

void assertEquals(long long int b, long long int a) {
    if (a != b) {
        printf("Expected %lld got %lld", a, b);
    } else {
        printf("SUCCESS");
    }
    putchar('\n');
}

int main(int argc, char *argv[]) {
    long long int consumption;

    printf("1\n");
    assertEquals(energyConsumption(2021, 11, 1, 12, 0, 2021, 10, 1, 12, 01, &consumption), 0);
    printf("2\n");
    assertEquals(energyConsumption(2021, 10, 32, 12, 0, 2021, 11, 10, 12, 0, &consumption), 0);
    printf("3\n");
    assertEquals(energyConsumption(2100, 2, 29, 12, 0, 2100, 2, 29, 12, 0, &consumption), 0);
    printf("4\n");
    assertEquals(energyConsumption(2021, 10, 1, 0, 15, 2021, 10, 1, 0, 25, &consumption), 1);
    assertEquals(consumption, 2035LL);
    printf("5\n");
    assertEquals(energyConsumption(2021, 10, 1, 12, 0, 2021, 10, 1, 12, 0, &consumption), 1);
    assertEquals(consumption, 0LL);
    printf("6\n");
    assertEquals(energyConsumption(2021, 10, 1, 12, 0, 2021, 10, 1, 12, 1, &consumption), 1);
    assertEquals(consumption, 204LL);
    printf("7\n");
    assertEquals(energyConsumption(2400, 2, 29, 12, 0, 2400, 2, 29, 12, 0, &consumption), 1);
    assertEquals(consumption, 0LL);
    printf("8\n");
    assertEquals(energyConsumption(2021, 10, 1, 13, 15, 2021, 10, 1, 18, 45, &consumption), 1);
    assertEquals(consumption, 67116LL);
    printf("9\n");
    assertEquals(energyConsumption(2021, 10, 1, 13, 15,
                                      2021, 10, 2, 11, 20, &consumption), 1);
    assertEquals(consumption, 269497LL);
    printf("10\n");
    assertEquals(energyConsumption(2021, 1, 1, 13, 15, 2021, 10, 5, 11, 20, &consumption), 1);
    assertEquals(consumption, 81106033LL);
    printf("11\n");
    assertEquals(energyConsumption(2024, 1, 1, 13, 15, 2024, 10, 5, 11, 20, &consumption), 1);
    assertEquals(consumption, 81398919LL);
    printf("12\n");
    assertEquals(energyConsumption(1900, 1, 1, 13, 15, 1900, 10, 5, 11, 20, &consumption), 1);
    assertEquals(consumption, 81106033LL);
    printf("13\n");
    assertEquals(energyConsumption(2021, 10, 1, 0, 0, 2021, 10, 1, 12, 0, &consumption), 1);
    assertEquals(consumption, 146443LL);
    printf("14\n");
    assertEquals(energyConsumption(2074, 11, 15, 0, 15,
                                      2074, 11, 15, 1, 0, &consumption), 1);
    assertEquals(consumption, 9153LL);
    printf("15\n");
    assertEquals(energyConsumption(1904, 1, 4, 1, 22, 2166, 2, 15, 6, 16, &consumption), 1);
    assertEquals(consumption, 28040086770LL);
    return 0;
}


#endif /* __PROGTEST__ */
