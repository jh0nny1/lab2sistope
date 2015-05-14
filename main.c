#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct structurita {
	int id_hebra;
	int n_lan;
	int *letras_array;
} struct_thread;

int *llenar_letras(int letra_inicial, int largo);
pthread_t *pt_array;
struct_thread *stct_array;
pthread_barrier_t barrera;

void *f(void *args){
	int *num =(int *)args;
	pthread_barrier_wait(&barrera);
	printf("Ejecutando hebra id = %i\n",stct_array[*num].id_hebra);

	/* ---- codigo ----- */
	
}

int main(){	
	int cant_mensajes = 22;
	int i,n=18;//n=cantidad de computadores y bridges en la red
	pt_array = (pthread_t*)malloc(sizeof(pthread_t)*n);//Arreglo de threads.
	int *array_aux = (int *)malloc(sizeof(int)*cant_mensajes);//Arreglo auxiliar de llenado de numeros
	stct_array = (struct_thread*)malloc(sizeof(struct_thread)*19);
	pthread_barrier_init(&barrera,NULL,18);//inicializar barrera para que hebras empiecen al mismo tiempo.
	int *array_de_numeros = (int*)malloc(sizeof(int)*18);
	for(i=0;i<18;i++){
		array_de_numeros[i]=i+1;
	}
	for(i=1;i<n+1;i++){
		int creado;
		creado = pthread_create(&pt_array[i],NULL,*f,&array_de_numeros[i-1]);//se crean las hebras 1 a 1.
		printf("HEBRA CREADA\n");
		if(n<17){
			array_aux = llenar_letras(i,cant_mensajes);//se llena array "letras_array" con los numeros en orden de los computadores a los que se le tiene que enviar mensajes
			stct_array[i].id_hebra=i;
			stct_array[i].letras_array=array_aux;

			//Estableciendo el numero de LAN a la cual pertenecen
			if(n>=1&&n<=4){
				stct_array[i].n_lan=1;
			}
			else if(n>=5&&n<=8){
				stct_array[i].n_lan=1;
			}
			else if(n>=9&&n<=12){
				stct_array[i].n_lan=1;
			}
			else if(n>=13&&n<=16){
				stct_array[i].n_lan=1;
			}
		}
		else{
			stct_array[i].id_hebra=i;
		}
		array_aux = llenar_letras(i,cant_mensajes);//se llena array "letras_array" con los numeros en orden de los computadores a los que se le tiene que enviar mensajes
		stct_array[i].id_hebra=i;
		stct_array[i].letras_array=array_aux;
	}
	//Se espera a que todas las hebras terminen para continuar con el main
	for(i=1;i<n+1;i++){
		pthread_join(pt_array[i],NULL);
	}
}

//A=0,B=1,C=2,D=3 ....
int *llenar_letras(int letra_inicial, int largo){
	int *array_letras = (int *)malloc(sizeof(int)*largo);
	int i,letra_a_poner;
	letra_a_poner=letra_inicial;
	for(i=0;i<largo;i++){
		letra_a_poner++;
		if(letra_a_poner==letra_inicial){
			letra_a_poner++;
			if(letra_a_poner>16){
				letra_a_poner=1;
				array_letras[i]=letra_a_poner;
				}
			else{
				array_letras[i]=letra_a_poner;
			}
		}
		else{
			if(letra_a_poner>16){
				letra_a_poner=1;
				if(letra_a_poner==letra_inicial){
					letra_a_poner++;
					array_letras[i]=letra_a_poner;
				}
				else{
					array_letras[i]=letra_a_poner;
				}
			}
			else{
				array_letras[i]=letra_a_poner;
			}	
		}
	}
	return array_letras;
}
