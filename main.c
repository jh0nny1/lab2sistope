#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *f(void *args){
	//int num = args[0];
	int *num =(int *)args;
	printf("numero = %i\n",*num);
}
//A=0,B=1,C=2,D=3 ....
int *llenar_letras(int letra_inicial, int largo){
	int *array_letras = (int *)malloc(sizeof(int)*largo);
	int i,letra_a_poner;
	letra_a_poner=letra_inicial;
	for(i=0;i<=largo+1;i++){
		if(letra_a_poner==letra_inicial){
			letra_a_poner++;
			if(letra_a_poner+1>16){
				letra_a_poner=0;
				if(letra_a_poner==letra_inicial){
					array_letras[i]=letra_a_poner;
				}
			}
			else{
				array_letras[i]=letra_a_poner;
			}
		}
		else{
			if(letra_a_poner+1>16){
				letra_a_poner=0;
				if(letra_a_poner==letra_inicial){
					letra_a_poner++;
					array_letras[i]=letra_a_poner;
				}
			}
			else{
	printf("awd\n");
				letra_a_poner++;
				array_letras[i]=letra_a_poner;
			}
			
		}
	}
	return array_letras;
}


int main(){
	int cant_mensajes = 36;
	int i,n=18;
	pthread_t *pt_array = (pthread_t*)malloc(sizeof(pthread_t)*n);
	/*for(i=1;i<n+1;i++){
//		num[i]=i;
		int creado;
		creado = pthread_create(&pt_array[i],NULL,*f,&i);
		pthread_join(pt_array[i],NULL);
	}*/
	int *array = (int *)malloc(sizeof(int)*cant_mensajes);
	array = llenar_letras(0,cant_mensajes);
	int j;
	for(j=0;j<cant_mensajes;j++){
		printf("array[%i]=%i\n",j,array[j]);
	}
	printf("TERMINO\n");
}
