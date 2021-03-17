#include <stdio.h>

// 비교연산 O(n^2)
void BubbleSort(int arr[], int n)
{
    int temp;
    
    for (int i=0; i<n-1; i++)
    {
        for (int j=0; j<(n-i)-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                
            }
        }
    }
}

int main(int argc, const char * argv[]) {
    
    int arr[] = {3, 2, 4, 1};
    
    BubbleSort(arr, sizeof(arr)/sizeof(int));
    
    for (int i=0; i<4; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
    return 0;
}
