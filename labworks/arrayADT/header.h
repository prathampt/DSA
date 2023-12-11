typedef struct array
{
    int * A;
    int size;
    int length;
}Array;

void init(Array *arr, int size);
void fill(Array * arr);
void display(Array arr);
void append(Array *arr, int element);
void insert(Array *arr, int element, int position);
int removeElement(Array *arr, int element);
int removeAtIndex(Array *arr, int index);
void reverse(Array *arr);
int min(Array arr);
int max(Array arr);
Array join(Array arr1, Array arr2);
void sort(Array *arr);