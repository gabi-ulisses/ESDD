#include <stdio.h>
#include "queue.h"

int main() {
    int a, b;
    T_Queue queueA = init(5);
    enqueue(queueA, 2);
    enqueue(queueA, 3);
    enqueue(queueA, 5);
    enqueue(queueA, 7);
    enqueue(queueA, 12);

    T_Queue queueB = init(8);
    enqueue(queueB, 3);
    enqueue(queueB, 6);
    enqueue(queueB, 5);
    enqueue(queueB, 7);
    enqueue(queueB, 10);
    enqueue(queueB, 11);
    enqueue(queueB, 13);
    enqueue(queueB, 0);

    T_Queue auxiliarA = init(5);
    T_Queue auxiliarB = init(8);

    printf("Relatório 1\n");
    while (!is_empty(queueA)) {
        dequeue(queueA, &a);
        enqueue(auxiliarA, a);
        while (!is_empty(queueB)) {
            dequeue(queueB, &b);
            enqueue(auxiliarB, b);

            if (a == b) {
                printf("%d\n", a);
            }
        }
        while (!is_empty(auxiliarB)) {
            dequeue(auxiliarB, &b);
            enqueue(queueB, b);
        }
    }
    while (!is_empty(auxiliarA)) {
        dequeue(auxiliarA, &a);
        enqueue(queueA, a);
    }


    return 0;
}