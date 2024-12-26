# include<stdio.h>
# include<stdlib.h>

void deleteElementAtEnd(int arr[],int n) {
    
    arr[n-1] = 0;
    
}


int main() {
    
    int arr[100], n;
    
    printf("Enter the number of elements in array: ");
    scanf("%d",&n);
    
    printf("Enter the elements of array : ");
    for(int i = 0 ; i < n ; i++) {
        scanf("%d",&arr[i]);
    }
    
    printf("Array elements are : ");
    for(int i = 0 ; i < n ; i++) {
        printf("%d ",arr[i]);
    }
    
    
    deleteElementAtEnd(arr,n);
    
    n--;
    
    
    printf("\nUpdated Array is : ");
    for(int i = 0 ; i < n ; i++) {
        printf("%d ",arr[i]);
    }
    
}