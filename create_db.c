#include"inverted.h"

void create_database(hash_t arr[],F_node *head)
{
    char str[100];
    while(head)
    {
        FILE *fp=fopen(head->f_name,"r");
        if(fp!=NULL)
        {
            while(fscanf(fp,"%s",str)!=EOF)
            {
                int index=get_index(str);
                if(arr[index].link==NULL)
                {
                    M_node *new_main=malloc(sizeof(M_node));
                    strcpy(new_main->word,str);
                    new_main->f_count=1;
                    new_main->main_link=NULL;
                    new_main->sub_link=NULL;

                    S_node *new_sub_node=malloc(sizeof(S_node));
                    strcpy(new_sub_node->filename,head->f_name);
                    new_sub_node->w_count=1;
                    new_sub_node->sub_link=NULL;

                    new_main->sub_link=new_sub_node;

                    arr[index].link=new_main;
                    //printf("NEW WORD : %s (index %d)\n",new_main->word,index);
                }
                else
                {
                    M_node *temp=arr[index].link;
                    M_node *prev=NULL;
                    while(temp!=NULL && strcmp(temp->word,str)!=0)
                    {
                        prev=temp;
                        temp=temp->main_link;
                    }
                    if(temp==NULL)
                    {
                        M_node *new_main=malloc(sizeof(M_node));
                        strcpy(new_main->word,str);
                        new_main->f_count=1;
                        new_main->sub_link=NULL;
                        new_main->main_link=NULL;

                        S_node *new_sub=malloc(sizeof(S_node));
                        strcpy(new_sub->filename,head->f_name);
                        new_sub->w_count=1;
                        new_sub->sub_link=NULL;

                        new_main->sub_link=new_sub;
                        prev->main_link=new_main;
                        //printf("NEW WORD : %s (index %d)\n",new_main->word,index);
                    }
                    else
                    {
                        S_node *sub_temp=temp->sub_link;
                        S_node *sub_prev=NULL;
                        
                        while(sub_temp!=NULL && strcmp(sub_temp->filename,head->f_name)!=0)
                        {
                            sub_prev=sub_temp;
                            sub_temp=sub_temp->sub_link;
                        }
                        if(sub_temp==NULL)
                        {
                            S_node *new_sub=malloc(sizeof(S_node));
                            strcpy(new_sub->filename,head->f_name);
                            new_sub->w_count=1;
                            new_sub->sub_link=NULL;

                            sub_prev->sub_link=new_sub;
                            temp->f_count++;
                        }
                        else
                        {
                            sub_temp->w_count++;
                        }

                    }
                }
            }
            fclose(fp);
        }
        head=head->link;
    }
}