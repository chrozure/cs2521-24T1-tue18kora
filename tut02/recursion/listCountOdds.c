#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#include "list.h"

void testListCountOdds(int values[], int size);
int listCountOdds(struct node *list);

int main(int argc, char *argv[]) {
    testListCountOdds((int[]){}, 0);
    testListCountOdds((int[]){1}, 1);
    testListCountOdds((int[]){2}, 1);
    testListCountOdds((int[]){1, 3}, 2);
    testListCountOdds((int[]){1, 3, 2}, 3);
    testListCountOdds((int[]){1, 3, 2, 5}, 4);
    testListCountOdds((int[]){2, 1, 3, 5, 4}, 5);
    testListCountOdds((int[]){-1}, 1);
}

void testListCountOdds(int values[], int size) {
    struct node *list = arrayToList(values, size);

    printf("List: ");
    listPrint(list);
    printf("\n");

    int numOdds = listCountOdds(list);
    printf("Number of odd values: %d\n\n", numOdds);

    listFree(list);
}

int listCountOdds(struct node *list) {
    // base case - empty list
    if (list == NULL) return 0;

    // int numOddsInRestOfList = listCountOdds(list->next);
    // // recursive case - value in current node is even
    // if (list->value % 2 == 0) {
    //     return numOddsInRestOfList;
    // }

    // // recursive case - value in current node is odd
    // else {
    //     return 1 + numOddsInRestOfList;
    // }

    return list->value % 2 + listCountOdds(list->next);
}
