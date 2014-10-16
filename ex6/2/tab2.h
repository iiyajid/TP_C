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

