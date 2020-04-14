#include <stdio.h>

int main(){
	
	char mi_string[]="Hola !!";
	int n = (sizeof(mi_string)/sizeof(mi_string[0]));
	int i,aux;
	int arreglo[n];

	for (i = 0; i < n; i++)
	{
		if (i>=2)
		{
			aux=arreglo[i-1]+arreglo[i-2];
			arreglo[i]=aux;
		}
		else
			arreglo[i]=i;
	}
	
	printf("Mi cadena en ascii es: \n");
	for (int i = 0; i < n; i++)
	{
		printf("%i >> ", mi_string[i]);
	}
	printf("\n");
	printf("Mis numeros fibo son: \n");
	
	for (i = 0; i < n; i++)
	{
		printf("%i >>",arreglo[i]);
	}
	printf("\n\n");
	
	int resta;
	for (i = 0; i < n; i++)
	{
		resta=((int)mi_string[i] - arreglo[i]);
		printf("%i >>", resta);
	}
	
	
	
	
	return 0;
}