/* ===================================================================== *
 *
 * fichier donnees.c
 * 
 * ===================================================================== */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tri.h"
#include "donnees.h"

/* ===================================================================== */
int isInt(char *num){
    int isNum = 0;
    while( *num ){
        if( (*num >= '0' && *num <= '9') || *num =='.')
            isNum = 1;
        else{
            return 0;
        }
        num++;
    }
    printf("%d %d",atoi(num), isNum);
    return isNum;
}

void Lire(ITEM items[], int *nb_items)
{
  int i;
  char age[6] = "aaaaa";

  printf("*** Entrer les donnees et taper . pour terminer\n\n");

  for (i = 0; TRUE; i++) {

    printf("> nom    : ");
    scanf("%20s", items[i].nom);
    if (items[i].nom[0] == '.') break;

    printf("> prenom : ");
    scanf("%*[^\n]\n");
    scanf("%20s", items[i].prenom);

    printf("> age    : ");
    scanf("%*[^\n]\n");
    scanf("%6s", age);
    while(isInt(age) == 0){
        printf("entrez un entier : \n");
        printf("> age    : ");
        scanf("%*[^\n]\n");
        scanf("%6s", age);
    }
    items[i].age = atoi(age);
    putchar('\n');
  }
  printf("--- Fin de la saisie\n\n");
  *nb_items = i;
}

/* ===================================================================== */

void Afficher(ITEM items[], int nb_items)
{
  int i;
  printf("\n*** Liste des donnees :\n\n");

  for (i = 0; i < nb_items; i++) {
    printf("Nom    : %s \n",   items[i].nom);
    printf("Prenom : %s \n",   items[i].prenom);
    printf("Age    : %d \n\n", items[i].age);
  }
}

/* ====================================================== The End ====== */


