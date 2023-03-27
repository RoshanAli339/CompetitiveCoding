#include <stdio.h>
#include <stdlib.h>

int** transpose(int **mat, int m, int n)
{
    int **transpose = (int**)malloc(n*sizeof(int*));
    for (int i = 0; i < n; ++i)
    {
        transpose[i] = (int*)malloc(m*sizeof(int));
        for (int j = 0; j < m; ++j)
        {
            transpose[i][j] = mat[j][i];
        }
    }
    return transpose;
}

void printMatrix(int **mat, int m, int n)
{
    printf("matrix is: \n");
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int m = 3, n = 2;
    int **mat = (int**)malloc(m*sizeof(int*));
    for (int i = 0; i < m; ++i)
        mat[i] = (int*)malloc(n*sizeof(int));

    printf("Enter the elements of the matrix: \n");
    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            scanf("%d", &mat[i][j]);
        }
    }
    printf("hi\n");
    mat = transpose(mat, m, n);
    int temp = m;
    m = n;
    n = temp;
    printf("After transpose ");
    printMatrix(mat, m, n);

    for (int i = 0; i < m; ++i)
    {
        for (int j = 0; j < n/2; ++j)
        {
            int temp = mat[i][j];
            mat[i][j] = mat[i][n-j-1];
            mat[i][n-j-1] = temp;
        }
    }

    printf("After rotating ");
    printMatrix(mat, m, n);
}