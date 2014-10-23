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

void Trier(ITEM items[], int nb_items)
{
  int i, j;
  ITEM swap;
  
  for (i = 0; i < nb_items; i++)
    for (j = i + 1; j < nb_items; j++)
      if (items[i].age > items[j].age) {
	swap = items[j];
	items[j] = items[i];
	items[i] = swap;
      }
}

/* ===================================================================== */
void Trier2(ITEM items[], int nb_items, char *p1, char *p2)
{
  int i, j;
  ITEM swap;
  int comp = strcmp(*p1, *p2);

  for (i = 0; i < nb_items; i++)
    for (j = i + 1; j < nb_items; j++)
      if (items[i].age > items[j].age) {
	swap = items[j];
	items[j] = items[i];
	items[i] = swap;
      }
}

/* ===================================================================== */

void Choix(ITEM items[], int nb_items)
{
  char cas[10];

  while (TRUE) {
    printf("*** Tri :\n");
    printf("- 1 ou A - numerique selon l'Age (croissant)\n");
    printf("- 2 ou D - numerique selon l'age (Decroissant)\n");
    printf("- 3 ou N - alphabetique sur le Nom\n");
    printf("- 4 ou P - alphabetique sur le Prenom\n");

    scanf("%s", cas);

    switch (cas[0]) {
    case '1': case 'A': case 'a':
      Trier(items, nb_items);
      return;

    default:
      printf("! Choix incorrect [%s] : entrer une autre valeur\n\n", cas);
    }
  }
}

/* ===================================================================== */

int main(int argc, char *argv[])
{
  ITEM items[MAX_ITEM];
  int nb_items;

  Lire(items, &nb_items);
  Choix(items, nb_items);
  Afficher(items, nb_items);
  exit(0);
}

/* ====================================================== The End ====== */

