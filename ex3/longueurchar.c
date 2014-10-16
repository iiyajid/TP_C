#include <stdio.h>

int slong(char *s){
    int length = 0;

    while (*s != 0){
        ++s;
        ++length;
    }

    return length;
}

int main() {
  char *s1  = "ceci est litteral";
  char s2[] = "ceci est un tableau";

  printf("longueur de %s = %d \n", s1, slong(s1));
  printf("longueur de %s = %d \n", s2, slong(s2));
  return 0;
}
