#include"inverted.h"
void save_database(hash_t arr[])
{
    char str[50];
    printf("Enter the file name to store the data: ");
    scanf(" %s",str);
    char *res=strstr(str,".");
    if(res&&strcmp(res,".txt")==0)
    {
        FILE *fp=fopen(str,"r");
        if(fp==NULL)
        {
            fp=fopen(str,"w");
            for(int i=0;i<27;i++)
            {
                if(arr[i].link!=NULL)
                {
                    M_node *mtemp=arr[i].link;
                    while(mtemp!=NULL)
                    {
                        S_node *stemp=mtemp->sub_link;
                        while(stemp!=NULL)
                        {
                            fprintf(fp,"#%d;%s;%d;%s;%d#\n",i,
                                        mtemp->word,mtemp->f_count,stemp->filename,stemp->w_count);
                            stemp=stemp->sub_link;
                        }
                        mtemp=mtemp->main_link;
                    }
                }
            }
            fclose(fp);
            printf("Database saved to %s\n",str);
        }
        else
        {
            fseek(fp,0,SEEK_END);
            int count=ftell(fp);
            rewind(fp);
            fclose(fp);

            if(count==0)
            {
                fp=fopen(str,"w");
                for(int i=0;i<27;i++)
                {
                    if(arr[i].link!=NULL)
                    {
                        M_node *mtemp=arr[i].link;
                        while(mtemp!=NULL)
                        {
                            S_node *stemp=mtemp->sub_link;
                            while(stemp!=NULL)
                            {
                                fprintf(fp,"#%d;%s;%d;%s;%d#\n",i,
                                        mtemp->word,mtemp->f_count,stemp->filename,stemp->w_count);
                                stemp=stemp->sub_link;
                            }
                            mtemp=mtemp->main_link;
                        }
                    }
                }
                fclose(fp);
                printf("Database saved to %s\n",str);
            }
            else
            {
                char ch;
                printf("File exists and has data. Overwrite? (y/n): ");
                scanf(" %c",&ch);
                if(ch=='y'||ch=='Y')
                {
                    fp=fopen(str,"w");
                    for(int i=0;i<27;i++)
                    {
                        if(arr[i].link!=NULL)
                        {
                            M_node *mtemp=arr[i].link;
                            while(mtemp!=NULL)
                            {
                                S_node *stemp=mtemp->sub_link;
                                while(stemp!=NULL)
                                {
                                    fprintf(fp,"#%d;%s;%d;%s;%d#\n",i,
                                        mtemp->word,mtemp->f_count,stemp->filename,stemp->w_count);
                                    stemp=stemp->sub_link;
                                }
                                mtemp=mtemp->main_link;
                            }
                        }
                    }
                    fclose(fp);
                    printf("Database saved to %s\n",str);
                }
                else
                {
                    printf("Save cancelled\n");
                }
            }
        }
    }
    else
    {
        printf("Invalid file name — must end in .txt\n");
    }
}