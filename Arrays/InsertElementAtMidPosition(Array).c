# include<stdio.h>

void insertBeginning(int arr[], int n, int mid,int ele) {
    
    for (int i = n - 1; i >= mid ; i--) {
        arr[i+1] = arr[i];
    }
    
    arr[mid] = ele;
    
    
}


int main() {
    
    int arr[100], n , ele;
    
    printf("Enter the number of elements in array: ");
    scanf("%d",&n);
    
    printf("Enter the elements of array: ");
    for (int i = 0; i < n ;i++) {
        scanf("%d",&arr[i]);
    }
    
    printf("Enter the element to insert at mid position: ");
    scanf("%d",&ele);
    
    int mid = n / 2;
    
    printf("Array elements are: ");
    for (int i = 0; i < n ;i++) {
        printf("%d ",arr[i]);
    }
    
    insertBeginning(arr, n , mid, ele);
    
    n++;
    
    printf("\nUpdated Array is :");
    
    for (int i = 0; i < n ;i++) {
        printf("%d ",arr[i]);
    }
    
    return 0;
    
    
}