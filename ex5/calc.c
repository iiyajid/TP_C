#include <stdio.h>

//similaire à atoi()
//float calc0(int a, int b, int op){
//    switch (op){
//    case 1: return a+b;
//    case 2: return a-b;
//    case 3: return a*b;
//    case 4: return a/b;
//    }
//    return -1;
//}

//int operation(){
//    int op ;
//    printf("Choisissez un operateur arithmetique: \n1 : +\n2 : -\n3 : *\n4 : /\n");
//    scanf ("%d",&op);
//    return op;
//}

float calc(int a, int b, int op){
    switch (op){
    case '+': return a+b;break;
    case '-': return a-b;break;
    case 'x': return a*b;break;
    case '*': return a*b;break;
    case '/': return (float)a/(float)b;break;
    }
    return -1;
}


int s2i(char * s){
    int entier = 0;

    while ( *s != 0){
        entier = entier * 10 + *s -'0' ;
        ++s;
    }

    return entier;
}

int main(int argc, char *argv[]) {
    int a = s2i(argv[1]),
        b = s2i(argv[3]),
        i = s2i("123");
    int op=*argv[2];

    printf("valeur de i = %d \n", i);

    printf("Le resultat de l'operation est %f\n",calc(a,b,op));


    return 0;
}

// le symbole * est interpreté par le shell comme etant un wildcard.
// nous proposons alors les deux solutions suivantes:
// 1: utiliser x au lieu de *
// 2: ecrire \* au lieu de *
