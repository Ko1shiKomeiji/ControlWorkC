#include "funcs.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {
    node *L1 = NULL;
    node *L2 = NULL;
    struct Data data;
    int i, j;

    srand(time(NULL));

    while ((data.f = (rand()%100)) < 90) {
        for (i = 0; i < N; i++)
            data.s[i] = ((char)(65 + rand()%25));
        L1 = add_head(L1, &data);
    }

    while ((data.f = (rand()%100)) < 90) {
        for (i = 0; i < N; i++)
            data.s[i] = ((char)(65 + rand()%25));
        L1 = add_head(L1, &data);
        L2 = add_head(L2, &data);
    }

    while ((data.f = (rand()%100)) < 90) {
        for (i = 0; i < N; i++)
            data.s[i] = ((char)(65 + rand()%25));
        L1 = add_head(L1, &data);
    }

    lprint(L1);
    lprint(L2);
    printf("%d", checker(L1, L2));

    return 0;
}