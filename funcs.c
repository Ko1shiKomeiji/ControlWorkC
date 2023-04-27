#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "funcs.h"

int llength(node *head) {
    node *tmp = head;
    int len = 0;
    if (head == NULL) return 0;
    while (tmp != NULL) {
        len++;
        tmp = tmp->next;
    }
    return len;
};

void lprint(node *head) {
    int i;
    node *tmp = head;
    printf("--- %4d ---\n", llength(head));
    if (head == NULL) {
        printf("[%p]\n", head);
        return;
    }
    while (tmp) {
        printf("[%14p]<-[%14p]->[%14p] ", tmp->prev, tmp, tmp->next);
        printf("data: [%f] s: [", tmp->data.f);
        for (i = 0; i < N; i++)
            printf("%c", tmp->data.s[i]);
        printf("]\n");
        tmp = tmp->next;
    }
    printf("-----------\n");
};

node *add_head(node *head, struct Data *data) {
    node *new = NULL;
    if ((new = malloc(sizeof(node))) == NULL) {
        perror("malloc : NULL");
        exit(2);
    }
    if (data != NULL)
        memcpy(&(new->data), data, sizeof(struct Data));
    new->prev = NULL;
    if (head == NULL)
        new->next = head;
    else {
        new->next = head;
        head->prev = new;
    }
    return new;
};

int checker(node *L1, node *L2) {
    int i;
    int counter = 0;
    if (L2 == NULL) {
        return 0;
    }
    while (L1) {
        counter = 0;
        for (i = 0; i < N; i++) {
            if ((char)(L1->data.s[i]) == (char)(L2->data.s[i])) {
                counter += 1;
            }
        }
        if (counter == 40) {
            while (L2->next) {
                counter = 0;
                L1 = L1->next;
                L2 = L2->next;
                for (i = 0; i < N; i++) {
                    if ((char)(L1->data.s[i]) == (char)(L2->data.s[i])) {
                        counter += 1;
                    }
                }
                if (counter != 40) {
                    return 0;
                }
            }
            return 1;
        }
        L1 = L1->next;
    }
}