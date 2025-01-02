// Copying one array into another array

# include <stdio.h> 

int main()
{
    int arr1[] = {10,20,30,40,50};
    int arr2[5];
    
    printf("%ld\n",sizeof(arr1));
    
    for (int i = 0; i < 5; i++)
    {
        arr2[i] = arr1[i];
    }
    
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",arr2[i]);
    }
}