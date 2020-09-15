#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "puissance4.h"
 
#define TAB_LENGTH 10
 
 
void fill_table(int table[])
{
    for(int i=0;i<TAB_LENGTH;i++)
    {
        printf("Entrez un nombre : ");
        scanf("%d",&table[i]);
    }
}
 
void print_table(int table[])
{
    if(TAB_LENGTH <=0)
    {
        return;
    }
 
    for(int i=0;i<TAB_LENGTH;i++)
    {
        printf("| %d |", table[i]);
    }
 
    printf("\n");
}
 
/********************************************************************/
 
int main (){
     
    int table [TAB_LENGTH];
    print_table(table);
    fill_table(table);
    print_table(table);
    printf("%d",table[5]);

    int grille[5][5] = { { 3, 1, 1, 0, 1 },
                     { 2, 1, 5, 4, 2 },
                     { 1, 2, 4, 5, 3 },
                     { 3, 4, 2, 3, 5 },
                     { 0, 6, 3, 3, 7 } };
    return EXIT_SUCCESS;
 
}