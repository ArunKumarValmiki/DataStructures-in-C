# include <stdio.h>
# define rows 3 
# define columns 3 

int main()
{
    int mat1[rows][columns],mat2[rows][columns], res[rows][columns];
    
    printf("Enter the elements of Matrix 1:\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            printf("Enter value of row %d, column %d : ",i+1,j+1);
            scanf("%d",&mat1[i][j]);
        }
    }
    
    printf("Enter the elements of Matrix 2:\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            printf("Enter value of row %d, column %d : ",i+1,j+1);
            scanf("%d",&mat2[i][j]);
        }
    }
    
    printf("Resultant matrix after adding two Arrays:\n");
    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < columns; j++)
        {
            res[i][j] = mat1[i][j] + mat2[i][j];
            printf("%d ",res[i][j]);
        }
        printf("\n");
    }
}