#include"inverted.h"

void validate_files(char *argv[],F_node **head)
{
    int i=1;
    
    while(argv[i]!=NULL)
    {
        char *res=strstr(argv[i],".");
        if(res&&strcmp(res,".txt")==0)
        {
            FILE *fp=fopen(argv[i],"r");
            if(fp!=NULL)
            {
                fseek(fp,0,SEEK_END);
                long count=ftell(fp);
                rewind(fp);

                if(count!=0)
                {
                    if(check_duplicates(*head,argv[i])==0)
                    {
                        insert_last(head,argv[i]);
                        printf("%s=> Inserted successfully\n",argv[i]);
                    }
                    else
                    {
                        printf("%s=> this file is repeated\n",argv[i]);
                    }
                }
                else
                {
                    printf("%s=> This file is empty\n",argv[i]);
                }
                fclose(fp);
            }
            else
            {
                printf("%s=>This file doesnot exist\n",argv[i]);
            }


        }
        i++;

    }
   
}

int check_duplicates(F_node *head,char *f_name)
{
    F_node *temp=head;
    while(temp!=NULL)
    {
        if(strcmp(temp->f_name,f_name)==0)
        return 1;
        temp=temp->link;
    }
    return 0;
}
int insert_last(F_node **head,char *f_name)
{
    F_node *new=malloc(sizeof(F_node));
    if(new==NULL)
    {
        return FAILURE;
    }
    strcpy(new->f_name,f_name);
    new->link=NULL;

    if(*head==NULL)
    {
        *head=new;
        return SUCCESS;
    }
    F_node *temp=*head;
    while(temp->link!=NULL)
    {
        temp=temp->link;
    }
    temp->link=new;
    return SUCCESS;
}
void print_filenames(F_node *head)
{
	if (head == NULL)
	{
		printf("INFO : List is empty\n");
	}
    else
    {
	    while (head)		
	    {
		    printf("%s -> ", head -> f_name);
		    head = head -> link;
	    }

	    printf("NULL\n");
    }
}
int get_index(char *str)
{
    if(str[0]>= 'a' && str[0] <= 'z')
    {
        return str[0]-'a';
    }
    else if(str[0]>='A' && str[0]<= 'Z')
    {
       return str[0]-'A';
    }
    else
    {
        return 26;
    }

}