/* ===================================================================== *
 *
 * fichier tri.c
 * 
 * ===================================================================== */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "tri.h"
#include "donnees.h"

/* ===================================================================== */

int compareNomCroiss(ITEM *a, ITEM *b){
    return strcmp(a->nom, b->nom);
}
int comparePrenomCroiss(ITEM *a, ITEM *b){
    return strcmp(a->prenom, b->prenom);
}
int compareAgeCroiss(ITEM *a, ITEM *b){
    return (a->age - b->age);
}
int compareNomDec(ITEM *a, ITEM *b){
    return -strcmp(a->nom, b->nom);
}
int comparePrenomDec(ITEM *a, ITEM *b){
    return -strcmp(a->prenom, b->prenom);
}
int compareAgeDec(ITEM *a, ITEM *b){
    return -(a->age - b->age);
}

ITEM *listSwap( ITEM * i1, ITEM * i2){
    i1->suiv = i2->suiv;
    i2->suiv = i1;
    
    return i2;
}

/* ===================================================================== */
ITEM * Trier(ITEM *items, int (*compar)(ITEM *,ITEM *)){
  ITEM *tete, *listI, *listJ;
  int change = 1;

  if( (tete = malloc(sizeof(ITEM))) == NULL){
      printf("Erreur d'allocation de memoire.\n");
      exit(1);
  }

  tete->suiv = items;
  if(items != NULL && items->suiv != NULL){

      while( change ){
          change = 0;
          listI = tete;
          listJ = tete->suiv;
          while( listJ->suiv != NULL ){
              if(compar(listJ,listJ->suiv) > 0){
                  listI->suiv = listSwap(listJ,listJ->suiv);
                  change = 1;
              }
              listI = listJ;
              if (listJ->suiv != NULL )
                  listJ = listJ->suiv;
          }
      }
  }
  listJ = tete->suiv;
  free(tete);
  return listJ;
}

/* ===================================================================== */

void Choix(ITEM *items)
{
  char cas[10];

    printf("*** Tri :\n");
    printf("- 1 ou A - numerique selon l'Age (croissant)\n");
    printf("- 2 ou B - numerique selon l'age (Decroissant)\n");
    printf("- 3 ou C - alphabetique croissant sur le Nom\n");
    printf("- 4 ou D - alphabetique decroissant sur le Nom\n");
    printf("- 5 ou E - alphabetique croissant sur le Prenom\n");
    printf("- 6 ou F - alphabetique decroissant sur le Prenom\n");
    printf("----\n");
    printf("- 7 ou G - ajouter element en fin de liste\n");
    printf("- 8 ou F - afficher sans trier\n");
    printf("- 0 ou Q - sortir\n");

    scanf("%s", cas);

    switch (cas[0]) {
    case '1': case 'A': case 'a':
      items = Trier(items, compareAgeCroiss); 
      break;
    case '2': case 'B': case 'b':
      items = Trier(items, compareAgeDec); 
      break;
    case '3': case 'C': case 'c':
      items = Trier(items,compareNomCroiss);
      break;
    case '4': case 'D': case 'd':
      items = Trier(items, compareNomDec);
      break;
    case '5': case 'E': case 'e':
      items = Trier(items, comparePrenomCroiss);
      break;
    case '6': case 'F': case 'f':
      items = Trier(items, comparePrenomDec);
      break;
    case '7': case 'G': case 'g':
      items = Lire(items);
      break;
    case '8': case 'H': case 'h':
      Afficher(items);
      break;
    case '0': case 'Q': case 'q':
      exit(0);

    default:
      printf("! Choix incorrect [%s] : entrer une autre valeur\n\n", cas);
    }
}

/* ===================================================================== */

int main(int argc, char *argv[])
{
  ITEM * items;

  items = NULL;
  int continuer = 1;

  while (continuer){
      items = Lire(items);
      printf("Continuer (0/1)?  :");
      scanf("%d",&continuer);
  }
  while(TRUE){
    Choix(items);
  }


  exit(0);
}

/* ====================================================== The End ====== */

