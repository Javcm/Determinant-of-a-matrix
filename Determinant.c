/ *  Primer examen de la clase de programación y análisis de algoritmos parte 3.
 *  El código recibe  una matriz cuadrada de tamaño definido por el usuario y calcula su determinantee por menores.
 */
#include <stdio.h>
#include <stdlib.h>

float det(float A[50][50], int n);

float main()
{   
    
    float A[50][50];              //Definimos una matriz de tamaño máximo 50 (pero bastaría con cambiar los valores si se quiere algo más grande)
    int i,j,k,n;
    printf("Indique el tamaño de la matriz (máximo 50): \n");
    scanf("%d",&n);
    printf("Ingresar los valores uno a uno por filas:\n");
    
    //Bloque de código que escanea los valores de la matriz y las acomoda por filas
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            scanf("%f",&A[i][j]);
        }
    }
    /*//Bloque de código que imprime la matriz
    for(i = 0 ; i < n ; i++){
        for(j = 0 ; j < n ; j++){
            printf("%.2f",A[i][j]);
        }
        printf("\n");
    }*/

    printf("El valor del determinante es: %.2f\n", det(A,n));
}

float det(float A[50][50], int n){
    float menor[50][50];
    int i,j,k,c1,c2;
    float determinante;
    //int c[50];
    float signo=1;

    // Caso base para el cálculo del determinante 
    if(n == 2){
        determinante = 0;
        determinante = A[0][0]*A[1][1]-A[0][1]*A[1][0];
        return determinante;
    }

    //Calculo de menores de forma resursiva
    else{
        for(i = 0 ; i < n ; i++){
            c1 = 0, c2 = 0;
            for(j = 0 ; j < n ; j++){
                for(k = 0 ; k < n ; k++){
                    if(j != 0 && k != i){
                        menor[c1][c2] = A[j][k];
                        c2++;
                        if(c2>n-2){
                            c1++;
                            c2=0;
                        }
                    }
                }
            }
            determinante = determinante + signo*(A[0][i]*det(menor,n-1));
            signo=-1*signo;
        }
    }
    return (determinante);
}