#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

unsigned long  Matias_A(char input[], int k){
  //printf("%d %s \n",strlen(input),input);
  int i = 0;
  unsigned long hash = 0;
  for(i=0; i<strlen(input); i++){
    //printf("%d %c %d *%d* | ",i, input[i], input[i], input[i]*k^i);
    hash += input[i]*pow(k,i);
  }
  
  return hash;
}

unsigned long Matias_Hash1(char input[], int k){
  unsigned long hash_calculado = Matias_A(input, k);
  
  if(hash_calculado >= 1000000){
    return hash_calculado % 1000000 ;
  }
  else {
    return hash_calculado;
  }
}

int main(void) {

  static int palabras[1000000];
  FILE *fp; 
  FILE *fout;
  fp = fopen("entrada.txt", "r");
  fout = fopen("salida.txt", "w");
  

  for (int i=0; i<1000000; i++){
    palabras[i]=0;
  }
  int count_linea=0;
  int count_palabra=0;
  int valor_k ;

  char linea[5000];
  char delim[] = " "; // define como delimitador el espacio para separar cada palabra

  while ( fgets (linea, 1000, fp) != NULL ) { // Lee el archivo linea por linea
    
    linea[strcspn(linea, "\r\n")] = 0; // elimina el salto de linea de la palabra
    
    if (count_linea == 0){
      //obtener k
      valor_k = atoi(linea);
      printf("EL VALOR DE K ES %d \n", valor_k);
    }
    else if(count_linea == 1){
      // leer el texto de entrada
      
      char *palabra = strtok(linea, delim); // separa linea por delimitador (palabra por palabra) una vez
      while(palabra != NULL){   // recorre palabra a palabra
        /*
        En este punto, usted puede acceder a palabra
        */
        
        unsigned int hash = Matias_Hash1(palabra, valor_k);
        //[hash]++;
        //printf("'%s' %lu\n", palabra, hash);
        palabras[hash]++;
        
        palabra = strtok(NULL, delim); // vuelve a separar palabra a palabra. Si usted elimina esta linea el programa no se detiene
      }
    }
    else if(count_linea == 2){
      // cantidad de palabras
    }
    else if(count_linea >= 3){
      //cada palabra a preguntar
      char *palabra = strtok(linea, delim); // separa linea por delimitador (palabra por palabra) una vez
      while(palabra != NULL){   // recorre palabra a palabra
        /*
        En este punto, usted puede acceder a palabra
        */
        unsigned int hash = Matias_Hash1(palabra, valor_k);
        //[hash]++;
        //printf("'%s' %lu\n", palabra, hash);
        printf("%d %d\n",hash, palabras[hash] );
       
        palabra = strtok(NULL, delim); // vuelve a separar palabra a palabra. Si usted elimina esta linea el programa no se detiene
        //fprintf(fout, "%d %d\n", hash, palabras[hash]);
      }
      
    }    
    count_linea++;
  }
  
  fclose(fout);
  fclose(fp); // cierra el archivo de entrada 

  return 0;
}