// Program to create a fixed array size at run time
// MEMORY IS ALLOCATED AT RUN TIME(dynamicaly allocated memory)

/* Creating an array at run time in C involves dynamically allocating memory for the array using 
functions like malloc or calloc from the standard library. 
This allows the array size to be determined during the execution of the program, rather than at compile time */

# include<stdio.h>
# include<stdlib.h>

int main() {
    
    int n;
    int *array;
    
    printf("Enter the size of array : ");
    scanf("%d",&n);
    
    // dynamically allocating memory. 
    
    array = (int *)malloc(n * sizeof(int));
    
    printf("Enter the numbers: ");
    for(int i = 0; i < n ; i++) {
        scanf("%d",&array[i]);
    }
    
    
    printf("The numbers are : ");
    
    for(int i = 0; i < n; i++) {
        printf("%d ",array[i]);
    }
    

    return 0;
}