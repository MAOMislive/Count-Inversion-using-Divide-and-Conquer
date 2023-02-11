
#include <stdio.h>

int N; ///Globally declaring no of elements in the array

int countInv(int arr[], int start, int end)  /// a shortcut function to count inversions
{
    int count =0;

    for(int i=0; i<N; i++)
    {
        for(int j=i+1; j<N; j++)
        {
            if(arr[i] > arr[j])
            {
                count++;
            }
        }
    }
    return count;
}

int merge(int arr[], int low, int mid, int high) /// Merging two arrays
{
    int temp[N];
    int i = low;
    int k = low;
    int j = mid + 1;
    int count = 0;
    while((i <= mid) && (j <= high))
    {
        if(arr[i] <= arr[j])
        {
            temp[k++] = arr[i++]; //count += ((mid+1)- i); ///count as for descending order
        }

        if(arr[j] <= arr[i])
        {
            temp[k++] = arr[j++];
            count += ((mid+1)- i); ///counting for ascending order
        }
    }

    while(i <= mid) temp[k++] = arr[i++];

    while(j <= high) temp[k++] = arr[j++];

    for(i = low; i <= high; i++)
    {
        arr[i] = temp[i];
    }

    return count;
}


int MergeSort(int arr[], int low, int high)
{
    int mid;
    int count = 0;
    if(low != high)
    {
        mid=(low+high)/2;
        count += MergeSort(arr, low, mid); ///Recursively sending up to mid elements to same function
        count += MergeSort(arr, mid+1, high); ///Recursively sending up mid+1 to last elements to same function
        count += merge(arr, low, mid, high); ///Calling merge functions to merge the two arrays
    }
    return count;
}

void main()
{
    int n;
    printf("Enter the size of the array: ");
    scanf("%d", &n);

    N = n;

    int arr[n];
    printf("Enter the unsorted element: ");

    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int count = MergeSort(arr, 0, n-1); ///DivAndCon is a function which runs merge sort(a divide and conquer process)
    
    printf("\nPrinting the sorted array: ");
    for(int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    
    printf("\nThe count inversion : %d", count);
}
