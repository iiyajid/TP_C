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

int compareNomCroiss(ITEM a, ITEM b){
    return strcmp(a.nom, b.nom);
}
int comparePrenomCroiss(ITEM a, ITEM b){
    return strcmp(a.prenom, b.prenom);
}
int compareAgeCroiss(ITEM a, ITEM b){
    return (a.age - b.age);
}
int compareNomDec(ITEM a, ITEM b){
    return -strcmp(a.nom, b.nom);
}
int comparePrenomDec(ITEM a, ITEM b){
    return -strcmp(a.prenom, b.prenom);
}
int compareAgeDec(ITEM a, ITEM b){
    return -(a.age - b.age);
}
/* ===================================================================== */
void Trier(ITEM items[], int nb_items, int (*compar)(ITEM,ITEM))
{
  int i, j;
  ITEM swap;
  
   for (i = 0; i < nb_items; i++)
      for (j = i + 1; j < nb_items; j++)
          if (compar(items[i],items[j]) > 0) {
              swap = items[j];
              items[j] = items[i];
              items[i] = swap;
          }
}

/* ===================================================================== */

void Choix(ITEM items[], int nb_items)
{
  char cas[10];

    printf("*** Tri :\n");
    printf("- 1 ou A - numerique selon l'Age (croissant)\n");
    printf("- 2 ou B - numerique selon l'age (Decroissant)\n");
    printf("- 3 ou C - alphabetique croissant sur le Nom\n");
    printf("- 4 ou D - alphabetique decroissant sur le Nom\n");
    printf("- 5 ou E - alphabetique croissant sur le Prenom\n");
    printf("- 6 ou F - alphabetique decroissant sur le Prenom\n");
    printf("- 0 ou Q - sortir\n");

    scanf("%s", cas);

    switch (cas[0]) {
    case '1': case 'A': case 'a':
      Trier(items, nb_items,compareAgeCroiss); 
      break;
    case '2': case 'B': case 'b':
      Trier(items, nb_items,compareAgeDec); 
      break;
    case '3': case 'C': case 'c':
      Trier(items, nb_items,compareNomCroiss);
      break;
    case '4': case 'D': case 'd':
      Trier(items, nb_items,compareNomDec);
      break;
    case '5': case 'E': case 'e':
      Trier(items, nb_items,comparePrenomCroiss);
      break;
    case '6': case 'F': case 'f':
      Trier(items, nb_items,comparePrenomDec);
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
  ITEM items[MAX_ITEM];
  int *nb_items;
  FILE *f;
  
  nb_items = malloc(sizeof(int));
  *nb_items = 0;
  
  Lire(items, nb_items);
  while(TRUE){
      f = fopen("file.txt", "r");
      if(*nb_items>0)
          while( fread(items+(*nb_items), sizeof(ITEM), 1, f) )
              (*nb_items)++;
      fclose(f);
      Choix(items, *nb_items);
      Afficher(items, *nb_items);
      f = fopen("file.txt", "w");
      fwrite(items, *nb_items, sizeof(ITEM), f);
      fclose(f);
  }

  exit(0);
}

/* ====================================================== The End ====== */

