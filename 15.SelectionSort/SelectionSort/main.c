#include <stdio.h>

// 오름차순 정렬
// O(n^2)
void SelSort(int arr[], int n)
{
    int i, j;
    int maxIdx;
    int temp;
    
    for (i=0; i<n-1; i++){
        maxIdx = i;
        
        for (j=i+1; j<n; j++)
        {
            if (arr[j] < arr[maxIdx])
                maxIdx = j;
        }
        temp = arr[i];
        arr[i] = arr[maxIdx];
        arr[maxIdx] = temp;
    }
}

int main(int argc, const char * argv[]) {
    int arr[] = {6, 4, 10, 2};
    
    SelSort(arr, sizeof(arr) / sizeof(int));
    for (int i=0; i<4; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
    return 0;
}
