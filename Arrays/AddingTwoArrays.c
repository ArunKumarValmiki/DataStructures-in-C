# include <stdio.h>
# define size 5 

int main()
{
    int a[size], b[size], c[size];
    
    printf("Enter the elements of First Array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&a[i]);
    }
    
    printf("Enter the elements of Second Array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&b[i]);
    }
    
    printf("Array after adding two arrays: ");
    for(int i = 0; i < size; i++)
    {
        c[i] = a[i] + b[i];                  
        printf("%d ",c[i]);
    }
}