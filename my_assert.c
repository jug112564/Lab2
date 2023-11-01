#include <stdio.h> 
#include <assert.h> 
#include <stdlib.h> 

char* filename;

void my_assert(int expression,int line,char*func,char* strexpression)
{
    if(!expression)
    {
        printf("%s: %s:%d: %s: Assertion '%s' failed.\n",filename,__FILE__,line,func,strexpression);
        abort();
    }
}
void foo(int num) 
{ 
    my_assert(((num >= 0) && (num <= 100)),__LINE__,"foo","((num >= 0) && (num <= 100))");
    printf("foo: num = %d\n", num); 
} 
 
void main(int argc, char *argv[]) 
{ 
    int num; 
 
    if (argc < 2) { 
        fprintf(stderr, "Usage: assert_test aNumber\n(0 <= aNumber <= 100)\n");
        exit(1); 
    } 
    filename="my_assert";
    num = atoi(argv[1]); 
    foo(num); 
    return;
} 