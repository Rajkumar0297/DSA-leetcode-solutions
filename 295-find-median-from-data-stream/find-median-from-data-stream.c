#include <stdlib.h>

typedef struct {
    int *arr;
    int size;
    int capacity;
} Heap;

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// Max Heap functions
void maxPush(Heap *h, int val) {
    int i = h->size++;
    h->arr[i] = val;

    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->arr[p] >= h->arr[i])
            break;
        swap(&h->arr[p], &h->arr[i]);
        i = p;
    }
}

int maxPop(Heap *h) {
    int res = h->arr[0];
    h->arr[0] = h->arr[--h->size];

    int i = 0;

    while (1) {
        int l = 2*i + 1;
        int r = 2*i + 2;
        int largest = i;

        if (l < h->size && h->arr[l] > h->arr[largest])
            largest = l;

        if (r < h->size && h->arr[r] > h->arr[largest])
            largest = r;

        if (largest == i)
            break;

        swap(&h->arr[i], &h->arr[largest]);
        i = largest;
    }

    return res;
}


// Min Heap functions
void minPush(Heap *h, int val) {
    int i = h->size++;
    h->arr[i] = val;

    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->arr[p] <= h->arr[i])
            break;
        swap(&h->arr[p], &h->arr[i]);
        i = p;
    }
}

int minPop(Heap *h) {
    int res = h->arr[0];
    h->arr[0] = h->arr[--h->size];

    int i = 0;

    while (1) {
        int l = 2*i + 1;
        int r = 2*i + 2;
        int smallest = i;

        if (l < h->size && h->arr[l] < h->arr[smallest])
            smallest = l;

        if (r < h->size && h->arr[r] < h->arr[smallest])
            smallest = r;

        if (smallest == i)
            break;

        swap(&h->arr[i], &h->arr[smallest]);
        i = smallest;
    }

    return res;
}


// MedianFinder structure
typedef struct {
    Heap left;   // Max heap
    Heap right;  // Min heap
} MedianFinder;


MedianFinder* medianFinderCreate() {

    MedianFinder* obj = malloc(sizeof(MedianFinder));

    obj->left.arr = malloc(sizeof(int) * 50000);
    obj->right.arr = malloc(sizeof(int) * 50000);

    obj->left.size = 0;
    obj->right.size = 0;

    return obj;
}


void medianFinderAddNum(MedianFinder* obj, int num) {

    if (obj->left.size == 0 || num <= obj->left.arr[0])
        maxPush(&obj->left, num);
    else
        minPush(&obj->right, num);


    // Balance heaps
    if (obj->left.size > obj->right.size + 1) {
        minPush(&obj->right, maxPop(&obj->left));
    }

    if (obj->right.size > obj->left.size) {
        maxPush(&obj->left, minPop(&obj->right));
    }
}


double medianFinderFindMedian(MedianFinder* obj) {

    if (obj->left.size > obj->right.size)
        return obj->left.arr[0];

    return (obj->left.arr[0] + obj->right.arr[0]) / 2.0;
}


void medianFinderFree(MedianFinder* obj) {
    free(obj->left.arr);
    free(obj->right.arr);
    free(obj);
}