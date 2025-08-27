#include <stdio.h>
#include <stdlib.h>

int busca_fibonacci(int x,int N){
	
	int termo[N];
	termo[0] = 0;
	termo[1] = 1;
	int i=0;
	
	//fazendo as contas para descobrir os termos da sequencia
	for(i=2;i<N;i++){
		termo[i] = termo[i-2]+termo[i-1];
	}
	
	//imprimindo os termos da sequencia 
	for(i=0;i<N;i++){
		printf("[%d] ",termo[i]);
	}
	
	//busca binaria
	
	int fim = N-1,inicio=0;
	int meio = 0;
	
	while(inicio <= fim){ //while rodando enquanto o indice do inicio nao chegar ate igual o fim
		
		meio = inicio + (fim - inicio) / 2;//calculando o termo do meio da sequencia 
	
		if(termo[meio] == x){//compara o elemento no meio da sequencia com o numero buscado
			printf(" \n Achou seu numero %d na posicao %d,parabens!!!",x,meio+1);
			return meio;
		}
	
		if(termo[meio] < x){ //se o elemento � menor aumenta o inicio ,se nao diminui o fim 
			inicio = meio + 1; 
		} else{
			fim = meio - 1;
		}
	}
	
	printf(" \n N�O ACHOU O NUMERO : %d \n", x);
    return -1; // Elemento n�o encontrado
	
}


int main(){
	
	int	x,N;
	
	printf("Digite quantos numeros voce vai querer na sequencia de fibonacci: ");
	scanf("%d",& N);
	
	printf("Digite qual numero voce vai querer achar na sequencia de fibonacci: ");
	scanf("%d",& x);
	
	busca_fibonacci(x,N);
}
