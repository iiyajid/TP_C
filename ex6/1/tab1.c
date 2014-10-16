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

#define TAB_MAX	100
#define TRUE	1
#define FALSE	0


void PrintTab(int tab[], int card) {
  int k = 0;

  printf("\n************************************************************\n");
  printf("Nombre d'elements: %d \n", card);

  for (k = 0; k < card; k++)
    printf("tab[%d] = %d, ", k, tab[k]);

  printf("\n************************************************************\n");
}


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */


int Chercher(int tab[], int tabLen, int val) {     /* A COMPLETER */
    int i;
    for (i = 0; i < tabLen; i++){
        if (tab[i] == val){
            return i;
        }
    }
    return -1;
}


/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */

void Change (int tab[],int posI, int posJ){
    int tmp;
    tmp = tab[posI];
    tab[posI] = tab[posJ];
    tab[posJ] = tmp;
}

void Supprime (int tab[], int *tabLen, int val){
    if(Chercher(tab,*tabLen,val) == -1){
        printf("L'element %d n'existe pas\n",val);
    }
    else{
        int posVal = Chercher(tab,*tabLen,val), i;
        for (i=posVal; i< *tabLen ; i++){
            tab[i]=tab[i+1];
        }
        (*tabLen)--;

    }
}

void SupprimeTout(int tab[], int *tabLen, int val){
    while(Chercher(tab,*tabLen,val) >= 0){
        Supprime(tab,tabLen,val);
    }

}

/* - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - */
void InsertVal(int tab[], int *tabLen, int val, int pos){
    if (Chercher(tab,*tabLen,val) >= 0){
        printf("Cette valeur existe deja dans le tableau\n");

    }
    else{
        if (pos >=0 && pos <= *tabLen && *tabLen < TAB_MAX){// insertion à l'interieur du tableau
            int i;

            for (i=*tabLen;i>pos;i--){
                tab[i]=tab[i-1];
            }
            tab[pos]=val;
            (*tabLen)++;
        }
        else{
            printf("Mauvaise position\n");
        }

    }
}

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

