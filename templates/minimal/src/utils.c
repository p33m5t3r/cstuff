#include <stdlib.h>
#include <time.h>

int randint(int bound) {
    srand(time(NULL));
    if (bound) return rand() % bound;
    return rand();
}
