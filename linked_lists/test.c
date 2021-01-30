#include "head.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<assert.h>
int main()
{
    char *temp=(char*)calloc(10,sizeof(char));
    strcpy(temp,"hello");

    node *test=NULL;
    append(&test,temp);
    assert(strcmp(test->data,temp)== 0);
    strcpy(temp,"why");
    append(&test,temp);
    assert(strcmp(test->next->data,temp)== 0);

    delete_node(1,&test);///deletinam 1 elementa hello
    assert(strcmp(test->data,temp)== 0);/// tikrinam ar istryneme
    printf("test successful!");


}
