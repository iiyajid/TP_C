#include <stdio.h>
#include <stdlib.h>

int slong(char *s){
    int length = 0;

    while ( *s != 0){
        ++s;
        ++length;
    }

    return length;
}

int main() {
  char *chaine;
  chaine = (char *) malloc(100*sizeof(char));
  printf("Entrez une chaine de caractères: \n");
  scanf ("%100[^\n]%*c", chaine);
  //[^\n]:permet de lire tous les caractères entrés qui ne sont pas '\n'.
  //'*c' permet de se débarasser de tous les caractères qui suivent le '\n'.
  printf("longueur de %s = %d \n", chaine, slong(chaine));

  free(chaine);
  return 0;
}
