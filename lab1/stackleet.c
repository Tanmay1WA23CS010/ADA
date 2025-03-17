#include <stdio.h>
#include <stdlib.h>


int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int* stack = (int*)malloc(asteroidsSize * sizeof(int));
    int top = -1;


    for (int i = 0; i < asteroidsSize; i++) {
        int current = asteroids[i];
        int alive = 1;


        while (alive && top >= 0 && current < 0 && stack[top] > 0) {
            if (stack[top] > -current) {
                alive = 0;
            } else if (stack[top] == -current) {
                top--;
                alive = 0;
            } else {
                top--;
            }
        }


        if (alive) {
            stack[++top] = current;
        }
    }


    *returnSize = top + 1;
    return stack;
}

