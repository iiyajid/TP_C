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
    return isNum;
}

//Ajout en fin
ITEM * Lire(ITEM *tete)
{
  char age[6] = "aaaaa";
  ITEM *nv, *fin, *retour;

  if( (nv = malloc(sizeof(ITEM))) == NULL ){
      printf("Espace memoire insuffisant\n");
      exit(1);
  }

  if (tete == NULL ){
      retour = nv;
  }
  else {
      retour = tete;
      fin = tete;
      while (fin->suiv != NULL)
          fin = fin->suiv;
      fin->suiv = nv;
  }
  //**********Lecture des données*********
  printf("> nom    : ");
  scanf("%20s", nv->nom);
  printf("> prenom : ");
  scanf("%*[^\n]\n");
  scanf("%20s", nv->prenom);
  printf("> age    : ");
  scanf("%*[^\n]\n");
  scanf("%6s", age);
  while(isInt(age) == 0){
      printf("entrez un entier : \n");
      printf("> age    : ");
      scanf("%*[^\n]\n");
      scanf("%6s", age);
  }
  nv->age = atoi(age);
  putchar('\n');
  //**********Fin de lecture********** 
  nv->suiv = NULL;
  
  return retour;

}

/* ===================================================================== */

void Afficher(ITEM *items)
{
  printf("\n*** Liste des donnees :\n\n");

  while ( items != NULL){
    printf("Nom    : %s \n",   items->nom);
    printf("Prenom : %s \n",   items->prenom);
    printf("Age    : %d \n\n", items->age);
    items = items->suiv;
  }
}

/* ====================================================== The End ====== */


