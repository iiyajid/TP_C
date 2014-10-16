/* ===================================================================== *
 *
 *  Programme tab1.c
 *  Manipulation des elements d'un tableau
 *
 * ===================================================================== */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "tab2.h"

#define TAB_MAX	100
#define TRUE	1
#define FALSE	0





/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */



int main(int argc, char* argv[]) {
  int tab[TAB_MAX] = {23, 17, 64, 41, 5, 17, 80};
  int indice, count = 7;
  int valeur;
  char rep[100];

  PrintTab(tab, count);

  while (TRUE) {

    printf("\nIndiquez l'operation a effectuer [Quit/Aff/Cher/Sup/Ins]: ");
    scanf("%s", rep);

    switch(rep[0]) {

    case 'q':
    case 'Q':
      exit(0);		/* fin du programme */

    case 'a':
    case 'A':
      PrintTab(tab, count);
      break;

    case 'c':
    case 'C':
      printf("\nEntrez la valeur cherchee = ");
      scanf("%d", &valeur);		/* Attention: ne pas oublier le & */

      indice = Chercher(tab,count,valeur);

      if (indice < 0) printf("Valeur non trouvee ! \n");
      else printf("Indice = %d , valeur = %d \n", indice, tab[indice]);

      break;

    case 's':
    case 'S':
      printf("\nEntrez la valeur a supprimer = ");
      scanf("%d", &valeur);
      //Supprime(tab,&count,valeur);
      SupprimeTout(tab,&count,valeur);



      /* ....... */

      break;

    case 'i':
    case 'I':
      printf("\nEntrez la valeur a inserer et la position correspondante = ");
      scanf("%d %d", &valeur, &indice);
      InsertVal(tab,&count,valeur,indice);
      /* ....... */

      break;

    default:
      printf("Choix incorrect !\n");
    }
  }
}

