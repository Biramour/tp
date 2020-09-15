#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "puissance4.h"
 
#define TAB_LENGTH 5
 
 
void fill_table(int table[])
{
    for(int i=0;i<TAB_LENGTH;i++)
    {
        printf("Entrez un nombre : ");
        scanf("%d",&table[i]);
    }
}
 
void print_table(int table[][5])
{
    if(TAB_LENGTH <=0)
    {
        return;
    }
 
    for(int i=0;i<TAB_LENGTH;i++)
    {
        for(int j=0; j<TAB_LENGTH;j++)
        {
            printf("| %d ", table[i][j]);
        }
        printf("\n");
    }
 
    printf("\n");
}

bool align_by_3(int tab [][5])
{
    bool b = false;

    for(int i =1; i < TAB_LENGTH-1; i++)
    {
        for(int j=1; j < TAB_LENGTH-1; j++)
        {
            if(tab[i-1][j+1]==tab[i][j]==tab[i+1][j-1])
            {
                printf("Puissance 3 en [%d][%d] \n",i,j);
                b = true;
                return b;
            }
        }
    }
    printf("Pas de puissance 3 pour l'instant ! Continuez\n");
    return b;
}

 
/********************************************************************/
 
int main (){

    int grille[5][5] = { { 3, 1, 1, 0, 1 },
                     { 2, 1, 5, 4, 2 },
                     { 1, 2, 4, 5, 3 },
                     { 3, 3, 2, 3, 5 },
                     { 0, 6, 3, 3, 7 } };

    print_table(grille);
    align_by_3(grille);
    return EXIT_SUCCESS;
 
}