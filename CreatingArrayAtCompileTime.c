// Program to create a fixed size Array at compile time
// Memory is allocated at compile time

# include<stdio.h>
# define size 5

int main() {
    int arr[size] = {1,2,3,4,5};            // try with less and more elements   
    
    printf("Array elements are :\n");
    
    for (int i = 0 ; i < size ; i++) {
        printf("%d ",arr[i]);
    }
    printf("\n");
    
    return 0;
}



