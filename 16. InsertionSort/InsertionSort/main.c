#include <stdio.h>

void InsertSort(int arr[], int n)
{
    int i, j;
    int insData;
    
    for(i=1; i<n; i++)
    {
        insData = arr[i];
        
        for (j=i-1; j>=0; j--)
        {
            if (arr[j] > insData)
                arr[j+1] = arr[j];
            else
                break;
        }
        
        arr[j+1] = insData;
    }
}

int main(int argc, const char * argv[]) {
    int arr[] = {6, 4, 10, 2};
    
    InsertSort(arr, sizeof(arr) / sizeof(int));
    for (int i=0; i<4; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
    return 0;
}
