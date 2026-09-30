#include"inverted.h"
void search_database(hash_t arr[])
{
    char str[30];
    printf("Enter the word to search: ");
    scanf(" %s",str);

    int index=get_index(str);

    if(arr[index].link==NULL)
    {
        printf("Error: Index is empty\n");
        return;
    }

    M_node *mtemp=arr[index].link;
    while(mtemp!=NULL)
    {
        if(strcmp(mtemp->word,str)==0)
        {
            printf("Word %s is present in %d file(s)\n",mtemp->word,mtemp->f_count);

            S_node *stemp=mtemp->sub_link;

            while(stemp!=NULL)
            {
                printf("In file %s %d time(s)\n",stemp->filename,stemp->w_count);
                stemp=stemp->sub_link;
            }
            return;
        }
        mtemp=mtemp->main_link;
    }

    printf("Word %s is not Found\n",str);
}