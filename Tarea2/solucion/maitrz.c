#include "matriz.h"




int ** suma(int **matriz1, int **matriz2, int tamano){
    
    int ** result_suma = (int **)malloc( tamano * sizeof(int*));
    
    for(int i = 0; i < tamano; i++){
        result_suma[i] = (int *)malloc( tamano * sizeof(int));
    }
    
    for(int i = 0; i < tamano; i++){
        for(int j = 0; j < tamano; j++){
            result_suma[i][j] = matriz1[i][j] + matriz2[i][j];
        }
    }
    return result_suma;
}


int ** convolucion(int **matriz, int **filtro, int tamano){
    static int convLargo;
    convLargo = tamano - 2;
    int ** result_conv = (int **)malloc( convLargo * sizeof(int*));
    for(int i = 0; i < convLargo; i++){
        result_conv[i] = (int *)malloc( convLargo * sizeof(int));
    }
    
    for(int i = 1; i < tamano - 1; i++){
        for(int j = 1; j < tamano - 1; j++){
            int sumaConv = 0;
            int iterGau = 0;
            for(int ic = i-1; ic < i + 2; ic++){
                int jterGau = 0;
                for(int jc = j-1; jc < j + 2; jc++){
                    sumaConv += matriz[ic][jc] * filtro[iterGau][jterGau];
                    jterGau++;
                }
                iterGau++;
            }
            result_conv[i-1][j-1] = sumaConv;
        }
    }
    return result_conv;
}

void escrituraMatriz(char *filename, int **matriz, int size){
    
    FILE *fp; 
    fp = fopen(filename, "w");
    
    for(int i = 0; i < size; i++){
        for(int j = 0; j < size; j++){

            //Tambien podia incorporar la funcion join()
            if(j == size-1){
                if(i == size -1){
                    fprintf (fp, "%d", matriz[i][j]);    
                }else{
                    fprintf (fp, "%d\n", matriz[i][j]);    
                }
                
            }else{
                fprintf (fp, "%d;", matriz[i][j]);
            }
            
        }
    }
    fclose(fp);
    
}

int ** lecturaMatriz(char *filename, int size){
    
    int ** Matriz = (int **)malloc( size * sizeof(int*));
    
    for(int i = 0; i < size; i++){
        Matriz[i] = (int *)malloc( size * sizeof(int));;
    }

    FILE *fp; 
    fp = fopen(filename, "r");
    
    static char linea[5000];
    
    for(int i = 0; i < size; i++){
        
        fgets (linea, 5000, fp) != NULL;
        linea[strcspn(linea, "\r\n")] = 0;
        char delim[] = ";"; // define como delimitador ; para separar cada palabra
        char *palabra_num = strtok(linea, delim); // separa linea por delimitador (palabra por palabra) una vez
        
        for(int j = 0; j < size; j++){
            Matriz[i][j] = atoi(palabra_num);
            palabra_num = strtok(NULL, delim);
        }
    }
    fclose(fp);
    return Matriz;
}


int ** convolucion2(int **matriz, int **filtro, int tamano){
    static int convLargo;
    convLargo = tamano - 2;
    int ** result_conv = (int **)malloc( convLargo * sizeof(int*));
    for(int i = 0; i < convLargo; i++){
        result_conv[i] = (int *)malloc( convLargo * sizeof(int));
    }
    
    for(int i = 1; i < tamano - 1; i++){
        for(int j = 1; j < tamano - 1; j++){
            
            int sumaConv = 0;
            
            for(int ic = -1; ic < 2; ic++){
                for(int jc = -1; jc < 2; jc++){
                    sumaConv += matriz[i-ic][j-jc] * filtro[ic+1][jc+1];
                }
            }

            result_conv[i-1][j-1] = sumaConv;
        }
    }
    return result_conv;
}
