#include"inverted.h"

int update_database(hash_t arr[],F_node **head)
{
    char str[100];
    printf("Enter the file name to update data: ");
    scanf(" %s",str);
    char *res=strstr(str,".");
    if(res&&strcmp(res,".txt")==0)
    {
        FILE *fp=fopen(str,"r");
        if(fp!=NULL)
        {
           fseek(fp,0,SEEK_END);
           long count=ftell(fp);
           rewind(fp);
          
           if(count!=0)
           {
                if(check_duplicates(*head,str)==0)
                {
                    char fname[100];
                    strcpy(fname,str);
                    insert_last(head,str);

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
                            strcpy(new_sub_node->filename,fname);
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
                                strcpy(new_sub->filename,fname);
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
                        
                                while(sub_temp!=NULL && strcmp(sub_temp->filename,fname)!=0)
                                {
                                    sub_prev=sub_temp;
                                    sub_temp=sub_temp->sub_link;
                                }
                                if(sub_temp==NULL)
                                {
                                    S_node *new_sub=malloc(sizeof(S_node));
                                    strcpy(new_sub->filename,fname);
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
                    return  SUCCESS;
                    
                }
                else
                {
                    printf("This file is already in database\n");
                    fclose(fp);
                    return FAILURE;
                }
           }
           else
           {
                printf("This file is empty\n");
                fclose(fp);
                return FAILURE;
           }
           
        }
       
        else
        {
            printf("File doesnot exist\n");
            return FAILURE;
        }
    }
    else
    {
        printf("Invalid file name\n");
        return FAILURE;
    }
    

}