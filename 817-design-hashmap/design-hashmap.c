#include <stdlib.h>

#define MAX_KEY 1000001

typedef struct {
    int *data;
} MyHashMap;

/** Initialize your data structure here. */
MyHashMap* myHashMapCreate() {
    MyHashMap *obj = (MyHashMap *)malloc(sizeof(MyHashMap));
    obj->data = (int *)malloc(MAX_KEY * sizeof(int));

    for (int i = 0; i < MAX_KEY; i++)
        obj->data[i] = -1;

    return obj;
}

void myHashMapPut(MyHashMap* obj, int key, int value) {
    obj->data[key] = value;
}

int myHashMapGet(MyHashMap* obj, int key) {
    return obj->data[key];
}

void myHashMapRemove(MyHashMap* obj, int key) {
    obj->data[key] = -1;
}

void myHashMapFree(MyHashMap* obj) {
    free(obj->data);
    free(obj);
}

/**
 * Your MyHashMap struct will be instantiated and called as such:
 * MyHashMap* obj = myHashMapCreate();
 * myHashMapPut(obj, key, value);
 * int param_2 = myHashMapGet(obj, key);
 * myHashMapRemove(obj, key);
 * myHashMapFree(obj);
 */