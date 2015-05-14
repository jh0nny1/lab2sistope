#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct structurita {
	int id_hebra;
	int *pt_array;
} struct_thread;

int *llenar_letras(int letra_inicial, int largo);
pthread_t *pt_array;
struct_thread *stct_array;

void *f(void *args){
	int *num =(int *)args;
	printf("\nHebra numero = %i\n",*num);
}

int main(){	
	int cant_mensajes = 22;
	int i,n=18;//n=cantidad de computadores y bridges en la red
	pt_array = (pthread_t*)malloc(sizeof(pthread_t)*n);
	stct_array = (struct_thread*)malloc(sizeof(struct_thread)*18);
	int *array_aux = (int *)malloc(sizeof(int)*cant_mensajes);
	for(i=1;i<n+1;i++){
		int creado;
		creado = pthread_create(&pt_array[i],NULL,*f,&i);
		pthread_join(pt_array[i],NULL);
		array_aux = llenar_letras(i,cant_mensajes);
		stct_array[i].id_hebra=i;
		stct_array[i].pt_array=array_aux;
	}
	int *array = (int *)malloc(sizeof(int)*cant_mensajes);
}

//A=0,B=1,C=2,D=3 ....
int *llenar_letras(int letra_inicial, int largo){
	int *array_letras = (int *)malloc(sizeof(int)*largo);
	int i,letra_a_poner;
	letra_a_poner=letra_inicial;
	printf("---------- Inicio llenado --------\n");
	for(i=0;i<=largo;i++){
		if(letra_a_poner==letra_inicial){
			letra_a_poner++;
			if(letra_a_poner>16){
				letra_a_poner=1;
				if(letra_a_poner==letra_inicial){
					letra_a_poner++;
					printf("letra_a_poner=%i\n",letra_a_poner);
					array_letras[i]=letra_a_poner;
				}
				else{
					array_letras[i]=letra_a_poner;
				}
			}
			else{
				printf("letra_a_poner=%i\n",letra_a_poner);
				array_letras[i]=letra_a_poner;
			}
		}
		else{
			if(letra_a_poner+1>16){
				letra_a_poner=1;
				if(letra_a_poner==letra_inicial){
					letra_a_poner++;
					printf("letra_a_poner=%i\n",letra_a_poner);
					array_letras[i]=letra_a_poner;
				}
				else{
					array_letras[i]=letra_a_poner;
				}
			}
			else{
				letra_a_poner++;
				printf("letra_a_poner=%i\n",letra_a_poner);
				array_letras[i]=letra_a_poner;
			}	
		}
	}
	return array_letras;
}
