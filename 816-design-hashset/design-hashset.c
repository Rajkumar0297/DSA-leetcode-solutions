#include <stdlib.h>
#include <stdbool.h>

#define MAX_KEY 1000001

typedef struct {
    bool *data;
} MyHashSet;

/** Initialize your data structure here. */
MyHashSet* myHashSetCreate() {
    MyHashSet *obj = (MyHashSet *)malloc(sizeof(MyHashSet));
    obj->data = (bool *)calloc(MAX_KEY, sizeof(bool));
    return obj;
}

void myHashSetAdd(MyHashSet* obj, int key) {
    obj->data[key] = true;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    obj->data[key] = false;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    return obj->data[key];
}

void myHashSetFree(MyHashSet* obj) {
    free(obj->data);
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 * myHashSetRemove(obj, key);
 * bool param_3 = myHashSetContains(obj, key);
 * myHashSetFree(obj);
 */