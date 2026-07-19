#include <stdlib.h>

#define MAXN 20005

typedef struct {
    int x;
    int h;
    int end;
} Event;

typedef struct {
    int h;
    int end;
} HeapNode;

HeapNode heap[MAXN];
int heapSize;

void push(HeapNode node) {
    int i = heapSize++;
    heap[i] = node;

    while (i > 0) {
        int p = (i - 1) / 2;
        if (heap[p].h >= heap[i].h)
            break;

        HeapNode temp = heap[p];
        heap[p] = heap[i];
        heap[i] = temp;

        i = p;
    }
}

void pop() {
    heap[0] = heap[--heapSize];

    int i = 0;

    while (1) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        int largest = i;

        if (left < heapSize && heap[left].h > heap[largest].h)
            largest = left;

        if (right < heapSize && heap[right].h > heap[largest].h)
            largest = right;

        if (largest == i)
            break;

        HeapNode temp = heap[i];
        heap[i] = heap[largest];
        heap[largest] = temp;

        i = largest;
    }
}

int cmp(const void *a, const void *b) {
    Event *x = (Event *)a;
    Event *y = (Event *)b;

    return x->x - y->x;
}

int** getSkyline(int** buildings, int buildingsSize, int* buildingsColSize, int* returnSize, int** returnColumnSizes) {

    Event *events = malloc(sizeof(Event) * buildingsSize * 2);

    int count = 0;

    for (int i = 0; i < buildingsSize; i++) {
        int l = buildings[i][0];
        int r = buildings[i][1];
        int h = buildings[i][2];

        events[count++] = (Event){l, h, r};
        events[count++] = (Event){r, 0, r};
    }

    qsort(events, count, sizeof(Event), cmp);

    int **ans = malloc(sizeof(int*) * (count + 1));
    *returnColumnSizes = malloc(sizeof(int) * (count + 1));

    int ansSize = 0;

    heapSize = 0;

    push((HeapNode){0, 2147483647});

    int prevHeight = 0;

    int i = 0;

    while (i < count) {

        int x = events[i].x;

        while (i < count && events[i].x == x) {
            if (events[i].h > 0)
                push((HeapNode){events[i].h, events[i].end});

            i++;
        }

        while (heapSize > 0 && heap[0].end <= x)
            pop();

        int currHeight = heap[0].h;

        if (currHeight != prevHeight) {
            ans[ansSize] = malloc(sizeof(int) * 2);
            ans[ansSize][0] = x;
            ans[ansSize][1] = currHeight;

            (*returnColumnSizes)[ansSize] = 2;

            ansSize++;

            prevHeight = currHeight;
        }
    }

    *returnSize = ansSize;

    free(events);

    return ans;
}