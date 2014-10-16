#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>


#define ORDRE_MAX 100

void afficherMat(int ordre,int mat[ordre][ordre]){
    int i,j;
    
    for(i=0; i< ordre; i++){
        for(j=0; j< ordre; j++){
            printf("%d  ",mat[i][j]);
        }
        printf("\n");
    }
    printf("------------------\n");
}
void initialiserMat(int ordre, int mat[ordre][ordre], int val){
    int i,j;

    for(i=0; i< ordre; i++){
        for(j=0; j< ordre; j++){
            mat[i][j] = val; 
        }
    }
}
void lireMat(int ordre, int mat[ordre][ordre]){
    int i,j,val;

    for(i=0; i< ordre; i++){
        for(j=0; j< ordre; j++){
            printf("Donnez l'element (%d,%d) : ", i, j);
            scanf("%d", &val);
            mat[i][j] = val; 
        }
    }
}
void additionMat(int ordre, int matRes[ordre][ordre], int mat1[ordre][ordre], int mat2[ordre][ordre]){
    int i,j; 

    for(i=0; i< ordre; i++){
        for(j=0; j< ordre; j++){
            matRes[i][j] = mat1[i][j]+mat2[i][j];
        }
    }
}
void multiplicationMat(int ordre, int matRes[ordre][ordre], int mat1[ordre][ordre], int mat2[ordre][ordre]){
    int i,j,k; 
    initialiserMat(ordre, matRes, 0);

    for(i=0; i< ordre; i++){
        for(j=0; j< ordre; j++){
            for(k=0; k< ordre; k++){
                matRes[i][j] += mat1[i][k]*mat2[k][j];
            }
        }
    }
}
int main(int argc, char* argv[]) {

    int ordre,
        mat0[ordre][ordre],mat1[ordre][ordre],mat2[ordre][ordre];
    char op[100];

    printf("Donnez l'ordre de vos matrices:  ");
    scanf("%d",&ordre);
    printf("Quelle operation souhaitez vous effectuer:\n[L: lire], [A: afficher], [M: Multiplier], [P: Additonner], [Q: Quitter]\n");
    scanf("%s",op);
    
    while(1){
    
    switch(op[0]){
        case 'q':
        case 'Q':
            exit(0);
        case 'l':
        case 'L':
            printf("Lecture matrice 0:\n");
            lireMat(ordre,mat0);
            printf("Lecture matrice 1:\n");
            lireMat(ordre,mat1);
            break;
        case 'a':
        case 'A':
            printf("Matrice 0:\n");
            afficherMat(ordre, mat0);
            printf("Matrice 1:\n");
            afficherMat(ordre, mat1);
            break;
        case 'm':
        case 'M':
            printf("Multiplication des matrices 0 et 1:\n");
            multiplicationMat(ordre, mat2, mat0, mat1);
            afficherMat(ordre, mat2);
            break;
        case 'p':
        case 'P':
            printf("Addition des matrices 0 et 1:\n");
            additionMat(ordre, mat2, mat0, mat1);
            afficherMat(ordre, mat2);
            break;
        default:
            printf("Choix errone\n");
            break;
    }
    //Menu:
    printf("Quelle operation souhaitez vous effectuer:\n[L: lire], [A: afficher], [M: Multiplier], [P: Additonner], [Q: Quitter]\n");
    scanf("%s",op);
    }
    lireMat(ordre, mat0);
    afficherMat(ordre, mat0);
    lireMat(ordre, mat1);
    afficherMat(ordre, mat1);
    additionMat(ordre, mat2, mat0, mat1);
    afficherMat(ordre, mat2);
    multiplicationMat(ordre, mat2, mat0, mat1);
    afficherMat(ordre, mat2);


    return 0;


}
