typedef struct maxHeap
{
    int *A;
    int size;
    int rear;
} MaxHeap;

typedef struct minHeap
{
    int *A;
    int size;
    int rear;
} MinHeap;

void swap(int *a, int *b);

int isEmptyMax(MaxHeap h);
int isFullMax(MaxHeap h);

int isEmptyMin(MinHeap h);
int isFullMin(MinHeap h);

void initMax(MaxHeap *h, int size);
void MaxHeapSort(int *arr, int size);
void insetMax(MaxHeap *h, int value);
int removeMax(MaxHeap *h);
void maxHeapify(MaxHeap *h, int index);

void initMin(MinHeap *h, int size);
void MinHeapSort(int *arr, int size);
void insetMin(MinHeap *h, int value);
int removeMin(MinHeap *h);
void minHeapify(MinHeap *h, int index);
