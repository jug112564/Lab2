#include <stdio.h>
#include <stdlib.h>

void main(int argc, char *argv[]) 
{ 
    if (argc < 3) { 
        fprintf(stderr, "Usage: matrix matrix_width matrix_height\n");
        exit(1); 
    } 
    int m1_width=atoi(argv[1]);
    int m1_height=atoi(argv[2]);
    int** matrix1;
    int** matrix2;
    int** result;

    matrix1=(int**)malloc(sizeof(int*)*m1_height);
    for(int i=0; i<m1_height; i++)
    {
        matrix1[i]=(int*)malloc(sizeof(int*)*m1_width);
    }

    matrix2=(int**)malloc(sizeof(int*)*m1_height);
    for(int i=0; i<m1_height; i++)
    {
        matrix2[i]=(int*)malloc(sizeof(int*)*m1_width);
    }

    result=(int**)malloc(sizeof(int*)*m1_height);
    for(int i=0; i<m1_height; i++)
    {
        result[i]=(int*)malloc(sizeof(int*)*m1_width);
    }

    //input
    printf("input matrix1 data :");
    for(int i=0; i<m1_height; i++)
    {
        for(int j=0; j<m1_width; j++)
        {
            scanf("%d",&matrix1[i][j]);
        }
    }

    printf("input matrix2 data :");
    for(int i=0; i<m1_height; i++)
    {
        for(int j=0; j<m1_width; j++)
        {
            scanf("%d",&matrix2[i][j]);
        }
    }

    for(int i=0; i<m1_height; i++)
    {
        for(int j=0; j<m1_width; j++)
        {
            result[i][j]=matrix1[i][j]+matrix2[i][j];
        }
    }

    printf("<result>\n");
    for(int i=0; i<m1_height; i++)
    {
        for(int j=0; j<m1_width; j++)
        {
            printf("%d ",result[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<m1_height; i++)
    {
        free(matrix1[i]);
        free(matrix2[i]);
        free(result[i]);
    }
    free(matrix1);
    free(matrix2);
    free(result);
}