#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#define MAX 80

void verificar_palindromo(char word[], char wordN[]) {
    if (strcmp(word, wordN) == 0) {
        printf("True\n");
    } else {
        printf("False\n");
    }
}

int main() {
    setlocale(LC_ALL, "Portuguese_Portugal.UTF-8");
    char palavra[MAX], palavraL[MAX],palavraN[MAX];
    int i=0,j=0,tam=0;
    
    printf("Digite sua palavra: ");
    fgets(palavra,MAX,stdin);
    
    if (palavra[strlen(palavra) - 1] == '\n') {
    	palavra[strlen(palavra) - 1] = '\0';//substitui o \n por \0
	}
    
    if (strlen(palavra) == 0) {
        printf("Erro: nenhuma palavra digitada.\n");
        return 1;
    }
    
   
    for (i = 0; palavra[i]; i++) {
        palavra[i] = tolower(palavra[i]);// Converte para min�scula
        if (isalnum(palavra[i])) { // Se for letra ou n�mero, 1 (true) se c for letra (A-Z ou a-z) ou n�mero (0�9) e 0 se for qualquer outra coisa
            palavraL[j++] = palavra[i];// Adiciona � string limpa
        }
    }
    palavraL[j] = '\0';
    
    j=0;
    tam = strlen(palavraL);
    for (i = tam - 1; i >= 0; i--) {//copianda para a palavraN a invers�o da palavraL
        palavraN[j++] = palavraL[i];
    }
    palavraN[j] = '\0';
    
    verificar_palindromo(palavra, palavraN);
    printf("STRING: %s\n", palavra);
    printf("STRING INVERTIDA: %s\n", palavraN);
    
    return 0;
}
