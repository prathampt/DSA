#include <stdio.h>

int main(){
    int n;
    printf("Enter the size of array: ");
    scanf("%d", &n);

    int arr[20]; // it is not recommended to put n here...

    for (int i = 0; i < n; i++)
    {
        printf("Enter arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    int max1 = arr[0];
    int max2 = arr[1];

    if (max1 < max2)
    {
        max1 = max2;
        max2 = arr[0];
    }
    
    for (int i = 0; i < n; i++)
    {
        if (max2<arr[i])
        {
            if (max1<arr[i])
            {

                max2 = max1;
                max1 = arr[i];
            }
            else if (max1!=arr[i])
            {
                max2 = arr[i];
            }
             
        }        
    }

    printf("The average of largest two of given numbers is: %.2f\n", (float) (max1 + max2)/2);
    
    return 0;
}