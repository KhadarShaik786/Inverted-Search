#ifndef INVERTED_H
#define INVERTED_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define SUCCESS 1
#define FAILURE 0

typedef struct file
{
    char f_name[20];
    struct file *link;
}F_node;

typedef struct sub
{
    char filename[30];
    int w_count;
    struct sub *sub_link;
}S_node;

typedef struct main
{
    char word[25];
    int f_count;
    S_node *sub_link;
    struct main *main_link;
}M_node;

typedef struct hash
{
    int index;
    struct main *link;
}hash_t;



void validate_files(char *argv[],F_node **head);
int check_duplicates(F_node *head,char *f_name);
int insert_last(F_node **head,char *f_name);
void print_filenames(F_node *head);
int get_index(char *str);

void create_database(hash_t arr[],F_node *head);
void display_database(hash_t arr[]);
void save_database(hash_t arr[]);
void search_database(hash_t arr[]);
int update_database(hash_t arr[],F_node **head);

#endif


