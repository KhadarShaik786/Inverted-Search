#include"inverted.h"
void display_database(hash_t arr[])
{
    for(int i=0;i<27;i++)
    {
        if(arr[i].link!=NULL)
        {
            M_node *mtemp=arr[i].link;

            while(mtemp!=NULL)
            {
                S_node *stemp=mtemp->sub_link;
                int first=1;
                while(stemp!=NULL)
                {
                    if(first)
                    {
                        printf("%-5d | %-12s | %-10d | %-11s | %-10d\n", i, 
                            mtemp->word, mtemp->f_count, stemp->filename, stemp->w_count);

                            first=0;
                    }
                    else
                    {
                        printf("%-5s | %-12s | %-10s | %-11s | %-10d\n", "", 
                           "", "", stemp->filename, stemp->w_count);
                       
                    }
                    stemp=stemp->sub_link;
                }
                mtemp=mtemp->main_link;
            }
        }
    }
}