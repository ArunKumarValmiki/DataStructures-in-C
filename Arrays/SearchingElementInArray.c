# include<stdio.h>
# include<stdlib.h>

int findElement(int arr[], int n, int key) {
    
    for (int i = 0; i < n ; i++) {
        if (arr[i] == key) {
            return i;
        }
    }
    
    return -1;
}


int main() {
    
    int arr[100], n, key;
    
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
    
    printf("\nEnter the element to search in array: ");
    scanf("%d",&key);
    
    int res = findElement(arr,n,key);
    
    if (res >= 0) {
        printf("Element found at index %d",res);
    }
    
    else {
        printf("Element is not found");
    }
}