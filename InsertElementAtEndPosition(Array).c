# include<stdio.h>

void insertLastPosition(int arr[], int n, int ele) {
    
    arr[n] = ele;
    
}


int main() {
    
    int arr[100],n,ele;
    
    printf("Enter the size of array : ");
    scanf("%d",&n);
    
    printf("Enter the elements of array : ");
    for (int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
    }
    
    printf("Array elements are : ");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
    
    printf("\nEnter the element to insert at last position: ");
    scanf("%d",&ele);
    
    insertLastPosition(arr,n,ele);
    
    n++;
    
    printf("Updated Array is : ");
    for (int i = 0; i < n; i++) {
        printf("%d ",arr[i]);
    }
}