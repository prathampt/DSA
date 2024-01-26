#include <stdio.h>

void printArray(int arr[], int length);

void insert(int arr[], int length, int num, int pos);

int main(){
    int array[20] = {1, 3, 6, 2, 8, 4, 7};
    int len = 7;
    printf("Original array is:\n");
    printArray(array, len);

    int a;
    printf("Enter the number of integers to be added: ");
    scanf("%d", &a);

    while (a)
    {
        int num, pos;
        printf("Enter the number to be added: ");
        scanf("%d", &num);
        printf("Enter the position to add above number: ");
        scanf("%d", &pos);

        insert(array, len, num, pos);
        len++;
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

void insert(int arr[], int length, int num, int pos){
    int a = 0, temp, t;
    for (int i = 0; i < length+1; i++)
    {
        if (i == pos){
            temp = arr[i];
            arr[i] = num;
            a = 1;
        }
        else if (a)
        {
            t = arr[i];
            arr[i] = temp;
            temp = t;
        }
    }
    return;
}