#include <stdio.h>

int fact1(int n){
    int factoriel = 1, i;

    if (n==0){
        return 1;
    }
    else{
        for ( i = n ; i > 0 ; i--){
                factoriel *= i;
            }
        return factoriel;
    }
}

int fact2(int n){
    int factoriel = 1, i = n;

    if (n==0){
        return 1;
    }
    else{
        while ( i > 0 ){
                factoriel *= i;
                i--;
            }
        return factoriel;
    }
}
int main() {
    int n;
    printf("Donner un entier : ");
    scanf ("%d",&n);
    printf("Le factoriel de %d est %d\n",n,fact2(n));
   return 0;
}
