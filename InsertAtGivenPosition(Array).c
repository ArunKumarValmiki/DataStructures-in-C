# include<stdio.h>

void insertElementAtPos(int arr[], int n, int pos, int ele) {
    
    for (int i = n -1 ; i >= pos - 1 ; i--) {
        arr[i+1] = arr[i];
    }
    
    arr[pos-1] = ele; 
}


int main() {
    
    int arr[100], n, pos, ele;
    
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
    
    printf("\nEnter the position to insert the element: ");
    scanf("%d",&pos);
    
    printf("Enter the element to insert: ");
    scanf("%d",&ele);
    
    insertElementAtPos(arr,n,pos,ele);
    
    n++;
    
    printf("Updated Array is : ");
    for(int i = 0 ; i < n ; i++) {
        printf("%d ",arr[i]);
    }
    
}