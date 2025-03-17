#include <stdbool.h>


typedef struct {
    int *data;
    int head;
    int tail;
    int size;
    int capacity;
} MyCircularQueue;


MyCircularQueue* myCircularQueueCreate(int k) {
    MyCircularQueue* obj = (MyCircularQueue*) malloc(sizeof(MyCircularQueue));
    obj->data = (int*) malloc(k * sizeof(int));
    obj->head = obj->tail = -1;
    obj->size = 0;
    obj->capacity = k;
    return obj;
}


void myCircularQueueFree(MyCircularQueue* obj) {
    if (obj) {
        free(obj->data);
        free(obj);
    }
}


bool myCircularQueueEnQueue(MyCircularQueue* obj, int value) {
    if (obj->size == obj->capacity) {
        return false;
    }
    if (obj->size == 0) {
        obj->head = obj->tail = 0;
    } else {
        obj->tail = (obj->tail + 1) % obj->capacity;
    }
    obj->data[obj->tail] = value;
    obj->size++;
    return true;
}


bool myCircularQueueDeQueue(MyCircularQueue* obj) {
    if (obj->size == 0) {
        return false;
    }
    if (obj->size == 1) {
        obj->head = obj->tail = -1;
    } else {
        obj->head = (obj->head + 1) % obj->capacity;
    }
    obj->size--;
    return true;
}


int myCircularQueueFront(MyCircularQueue* obj) {
    if (obj->size == 0) {
        return -1;
    }
    return obj->data[obj->head];
}


int myCircularQueueRear(MyCircularQueue* obj) {
    if (obj->size == 0) {
        return -1;
    }
    return obj->data[obj->tail];
}


bool myCircularQueueIsEmpty(MyCircularQueue* obj) {
    return obj->size == 0;
}


bool myCircularQueueIsFull(MyCircularQueue* obj) {
    return obj->size == obj->capacity;
}


