#ifndef HEAD_H_INCLUDED
#define HEAD_H_INCLUDED
#include <stdio.h>
typedef struct node
{
    char *data;
    struct node *next;
}node;

FILE *open_file_read();
void append_list_from_file(FILE *fp,node **head);
void append(node **head, char *data);
int delete_node(int num, node **head);
int count(node *head);
void  display(node *head);
node *set_head(node *head);


#endif // HEAD_H_INCLUDED
