# include<stdio.h>
# include<stdlib.h>

void deleteElementAtPos(int arr[],int n,int pos) {
    
    for (int i = pos - 1 ; i < n; i++) {
        arr[i] = arr[i+1];
    }
    
}


int main() {
    
    int arr[100], n, pos;
    
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
    
    printf("\nEnter the position to delete the element: ");
    scanf("%d",&pos);
    
    deleteElementAtPos(arr,n,pos);
    
    n--;
    
    
    printf("Updated Array is : ");
    for(int i = 0 ; i < n ; i++) {
        printf("%d ",arr[i]);
    }
    
}