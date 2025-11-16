#include "logic.c"

int main() {

    int n;

    printf("Enter the number of integers: ");
    scanf("%d", &n);

    int * arr = (int *) malloc(sizeof(int) * n);

    printf("Enter the integers: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", arr + i);
    }

    MaxHeapSort(arr, n);

    printf("Sorted array using max heap: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    MinHeapSort(arr, n);

    printf("Sorted array using min heap: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
