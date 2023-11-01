#include <iostream>
#include <vector>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{ 
    if (argc < 3) { 
        fprintf(stderr, "Usage: matrix matrix_width matrix_height\n");
        exit(1); 
    } 
    int m1_width=atoi(argv[1]);
    int m1_height=atoi(argv[2]);
    std::vector<std::vector<int>> matrix1;
    std::vector<std::vector<int>> matrix2;
    std::vector<std::vector<int>> result;

    matrix1.reserve(m1_height);
    matrix2.reserve(m1_height);
    result.reserve(m1_height);
    //input
    printf("input matrix1 data :");
    for(int i=0; i<m1_height; i++)
    {
        for(int j=0; j<m1_width; j++)
        {
            int num;
            std::cin>>num;
            matrix1[i].push_back(num);
        } 
    }

    printf("input matrix2 data :");
    for(int i=0; i<m1_height; i++)
    {
        for(int j=0; j<m1_width; j++)
        {
            int num;
            std::cin>>num;
            matrix2[i].push_back(num);
        } 
    }

    for(int i=0; i<m1_height; i++)
    {
        for(int j=0; j<m1_width; j++)
        {
            result[i].push_back(matrix1[i][j]+matrix2[i][j]);
        }
    }

    printf("<result>\n");
    for(int i=0; i<m1_height; i++)
    {
        for(int j=0; j<m1_width; j++)
        {
            std::cout<<result[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}