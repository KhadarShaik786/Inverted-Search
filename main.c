#include"inverted.h"
int main(int argc,char* argv[])
{
        hash_t arr[27];
        for(int i=0;i<27;i++)
        {
                arr[i].index=i;
                arr[i].link=NULL;
        }
        F_node *head=NULL;
        if(argc<1)
        {
                printf("Pass the arguments like a.out <file_name.txt>\n");
                return FAILURE;
        }
        validate_files(argv,&head);
        
        print_filenames(head);
        
        int create_flag=0;
        int update_flag=0;
        int option;
        do
        {
                printf("Select your choice among the following:\n1.Create Database\n2.Display Database\n3.Save Database\n4.Search\n5.Update Database\n6.Exit\nEnter your choice: ");
                scanf("%d",&option);

                switch(option)
                {
                case 1:
                        if(update_flag==1)
                        {
                                printf("Cannot create — update already modified the database\n");
                        }
                        else if(create_flag==1)
                        {
                                printf("Database is already created\n");
                        }
                        else
                        {
                                create_database(arr,head);
                                create_flag=1;
                                printf("Database created successfully\n");
                        }
                         break;
                case 2:
                         display_database(arr);
                         break;
                case 3:
                         save_database(arr);
                         break;
                case 4:
                         search_database(arr);
                         break;
                case 5:
                        if(update_database(arr,&head)==SUCCESS)
                        {
                                update_flag=1;
                        }
                        break;
                case 6:
                         break;
                default :
                         printf("Please enter the valid option!!\n");
                }
        }while(option!=6);
}
