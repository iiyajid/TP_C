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
  gets (chaine);
  printf("longueur de %s = %d \n", chaine, slong(chaine));

  return 0;
}
