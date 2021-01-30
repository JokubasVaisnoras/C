#include "head.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void  display(node *head)
{
    if(head==NULL)
        return ;
    printf("%s \n",head->data);
    display(head->next);

    // list node contents from first to last
    //struct node *r=head;
    //int i=0;

    //if(r==NULL)
    //{
    //    return;
    //}
    //while(r!=NULL)
    //{
     //   i++;
      //  printf("%d:%s\n",i,r->data);
        //printf("%s\n",*r->data);
      //  r=r->next;
   // }
    //printf("\n");
}

void append(node **head, char *data)
{
    node *temp,*right;
    // create a new temp node
    temp= (struct node *)malloc(sizeof(struct node)); //create temp node
    temp->data=data;  //set temp value
    temp->next=NULL; // set as end of list

    right= *head;

    if (right==NULL)
    {
        // then no head node exists yet, so set temp as head
        *head=temp;
    }
    else
    {
        // find end of current list
        while(right->next != NULL)
            right=right->next;
        right->next =temp;
    }

}
FILE *open_file_read(FILE *fp)
{
    int line_size= 256;
    char *filename_input=malloc(line_size*sizeof(char));
    while(1)
    {
        printf("Enter file input name without .txt \n");

        scanf("%256s",filename_input);
        strcat(filename_input,".txt");
            if ((fp = fopen(filename_input, "r")) == NULL)
            {
                printf("Error! opening file please check if you entered the file correctly");
            }
            else
            {
                printf("file opened for reading succesfully \n");
                break;
            }
   }
        return fp;
}



void append_list_from_file(FILE *fp,node **head)
{
/// head parsiuncia null kaip ir turetu but daba
    int line_size=256;

    char *line =(char*)calloc(line_size,sizeof(char));
    char *token;
    char *read=NULL;
    char s[]=" \n";
    while(fgets(line, line_size, fp) != NULL)
    {
        read = (char *)calloc(strlen(line),sizeof(char ));//!!! realloc
        strcpy(read, line);//!!!
        token = strtok(read, s);

        while( token != NULL )
        {
            printf( "%s\n", token );
            append(head,token);
            token = strtok(NULL,s);
        }
    }

    printf("All element in the list are : \n");
    display(*head);

    return;
}
int delete_node(int num, node **head)
{
    node *temp= *head;
    if(num == 1)
    {
        *head = temp->next;
        free(temp);
        return 1;
    }

    for(int i=0; i<num-2; ++i)
        temp= temp->next;

       node *temp1 = temp->next;
       temp->next = temp1 -> next;
       free(temp1);

       return 1;
    }
int count(node *head)
{
   // scan list and count how many nodes
    node *n;
    int c=0;
    n=head;
    while(n!=NULL)
    {
        n=n->next;
        c++;
    }
    return c;
}
