#include <search.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    char *name;
    int middle;
    int final;
};

#define TABLESIZE 50
char nametable[TABLESIZE*20]; /* 이름을 저장할 테이블 */
struct node *root = NULL; /* 루트 노드 */

int compare(const void *cp1, const void *cp2)
{
    return strcmp(((struct node *)cp1)->name, ((struct node *)cp2)->name);
}

void print_node(const void *nodeptr, VISIT order, int level)
{
    if (order == preorder || order == leaf)
        printf("이름 = %s, 중간점수 = %d, 기말점수 = %d\n", (*(struct node **)nodeptr)->name, (*(struct node **)nodeptr)->middle, (*(struct node **)nodeptr)->final);
}

int main(int argc, char *argv[])
{
    if(argc<2){
        printf("Usage: student count\n"); 
        exit(1); 
    }
    int treesize=atoi(argv[1]);
    char *nameptr = nametable;
    struct node *nodeptr = malloc(treesize*sizeof(struct node));//nodetable;
    struct node **ret;

    int i=0;
    while(i<treesize)
    {
        scanf("%s%d%d", nameptr, &nodeptr->middle, &nodeptr->final);
        nodeptr->name = nameptr;
        /* 트리에 넣기 */
        ret = (struct node **) tsearch((void *) nodeptr, (void **) &root, compare);
        printf("\"%s\" 님이 ", (*ret)->name);
        if (*ret == nodeptr)
        {
            printf("트리에 추가되었습니다.\n");
            i++;
        }
        else
            printf("트리에 이미 존재합니다.\n");
        nameptr += strlen(nameptr) + 1;
        nodeptr++;
    }
    twalk((void *) root, print_node);
}
