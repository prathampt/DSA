#include <stdio.h>

void printArray(int arr[], int length);

void delete(int arr[], int length, int num);

int main(){
    int array[20] = {1, 3, 6, 2, 8, 4, 7};
    int len = 7;
    printf("Original array is:\n");
    printArray(array, len);

    int a;
    printf("Enter the number of integers to be deleted: ");
    scanf("%d", &a);

    while (a)
    {
        int num;
        printf("Enter the number to be deleted: ");
        scanf("%d", &num);

        delete(array, len, num);
        len--;
        a--;
    }
    
    printf("Updated array is: \n");
    printArray(array, len);

    return 0;
}

void printArray(int arr[], int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return;
}

void delete(int arr[], int length, int num){
    int a = 0;
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == num){
            arr[i] = arr[i+1];
            arr[i+1] = 0;
            a = 1;
        }
        else if (a)
        {
            arr[i] = arr[i+1];
            arr[i+1] = 0;
        }
    }
    return;
}