#include "head.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
///Jokubas Vaisnoras
///lsp-2016056
///jokkbas@gmail.com
///4 uzduotisSudaryti vienpusį sąrašą. Parašyti procedūrą, kuri išmeta numeriu nurodytą elementą.
/// Jeigu tokio elemento nėra, turi būti išvestas atitinkamas pranešimas.
///(Spėjimas)užduoties atlikimas laikas - 4,5h
///1. išmokti dirbti su list -1,5h
///2. išmokti small things(makefile, kelios .c programos) - 0,5h
///3. pati programa 1h
///4. bugai 1,5h

FILE *open_file_read();
void append_list_from_file(FILE *fp,node **head);
void append(node **head, char *data);
int delete_node(int num, node **head);
int count(node *head);
void  display(node *head);
node *set_head(node *head);

int  main(){

    FILE *fp=NULL;
    int num;
    char raide;
    node *head=NULL;
    int i;

    while(1)
    {   printf("Enter a number between 0-5 (0 is menu)\n");
        if(scanf("%d%c", &i, &raide) !=2 || raide != '\n')
        {
            scanf("%*[^\n]");
            printf("Enter a number between 0-5 (0 is menu)!!!\n");
            continue;
        }
        if(i>5 || i<0)
            continue;

            switch(i)
            {
            case 1:
               fp=open_file_read(fp);
                break;
            case 2:
                 if(head==NULL)
                printf("List is Empty\n");
                 else
                {
                    int c =count(head);
                    while(1)
                    {
                        printf("Enter a number between 1 and %d\n",c);
                        if(scanf("%d%c", &num, &raide) !=2 || raide != '\n')
                        {
                            scanf("%*[^\n]");
                            continue;
                        }
                        else
                        {
                            if(num<=c && num>=1)
                                break;
                            else
                                continue;
                        }
                    }

                    if(delete_node(num,&head))
                        printf("%d deleted successfully\n",num);
                    else
                        printf("%d not found in the list\n",num);
                 }
                    break;
            case 3:
                if(head==NULL)
                    printf("List is Empty\n");
                else
                {
                    printf("Element(s) in the list are : \n");
                    display(head);
                }
                break;
            case 4:
                printf("ending programme...");
                exit(0);
                break;
            case 5:
                if(fp==NULL)
                {
                    printf("give a filename first, press 1 \n");
                    break;
                }
                append_list_from_file(fp,&head);
                break;



            default:
                puts("\nList Operations  ===============");
                puts("1.Open file for reading   2.Delete  element       3.Display List");
                puts("4.Exit                    5.Append Open to List");
            }

    }
    return 0;
}

