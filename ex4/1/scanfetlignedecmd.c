#include <stdio.h>

int slong(char *s){
    int length = 0;

    while (*s != 0){
        ++s;
        ++length;
    }

    return length;
}

int main(int argc, char *argv[]) {

  int i ;

  if (argc < 2){
      printf("Pas de chaine a calculer!\n");
      return -1;
  }
  else{
      int totalLen=0;
      int wordLen =0;

      for(i = 1; i < argc; i++){
          wordLen=slong(argv[i]);
          printf("longueur de %s = %d \n", argv[i], wordLen);
          totalLen += wordLen;
      }
      printf("longueur totale : %d \n", argc -2 + totalLen);
      return 0;
  }
}
