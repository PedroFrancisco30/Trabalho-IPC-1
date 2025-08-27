	#include <stdio.h>
	#include <stdlib.h>
	#include <time.h>
	
	#define MAX 10
	
	// Fun��o DFS (Depth-First Search / Busca em profundidade)
	// Essa fun��o busca um caminho do ponto atual (x, y) at� a posi��o de chegada (lin_saida, col_saida),
	// movendo-se apenas por espa�os livres e evitando rob�s e caminhos j� visitados.
	int dfs(char mapa[MAX][MAX], int nova_lin, int nova_col, int linhas, int colunas) {
	    int i = 0;
	
	    // Verifica se a posi��o est� fora dos limites da matriz
	    if (nova_lin < 0 || nova_lin >= linhas || nova_col < 0 || nova_col >= colunas){
	        return 0;//falso
		}
		
	    // Verifica se a c�lula atual � um obst�culo (rob�), j� foi visitada (*), ou � o ponto de partida (H)
	    // N�o podemos pisar nesses locais
	    if (mapa[nova_lin][nova_col] == 'R' || mapa[nova_lin][nova_col] == '*' || mapa[nova_lin][nova_col] == 'H'){
	        return 0;//falso
		}
		
	    // Se chegamos ao destino (Z), retorna sucesso
	    if (mapa[nova_lin][nova_col] == 'Z'){
	        return 1;//verdadeiro
		}
		
	    // Marca o caminho atual como visitado com um asterisco '*'
	    mapa[nova_lin][nova_col] = '*';
	
	    // Vetores de dire��o: cima, baixo, esquerda, direita
	    int dx[] = {-1, 1, 0, 0};
	    int dy[] = {0, 0, -1, 1};
	
	    // Tenta recursivamente seguir cada dire��o
	    for (i = 0; i < 4; i++) {
	        int prox_lin = nova_lin + dx[i]; // pr�xima linha
	        int prox_col = nova_col + dy[i]; // pr�xima coluna
	
	        // Se qualquer dire��o resultar em sucesso, retorna 1
	        if (dfs(mapa, prox_lin, prox_col, linhas, colunas))
	            return 1;//verdadeiro
	    }
	
	    // Se nenhuma dire��o for v�lida, desfaz a marca��o (backtracking)
	    mapa[nova_lin][nova_col] = ' ';
	    return 0; // Caminho sem sucesso
	}
	
	
	int main() {
	    int linhas, colunas, qtd_robos;
	    int i = 0, j = 0;
	    int lin_hum, col_hum, lin_saida, col_saida,lin_rob, col_rob;
	    char mapa[MAX][MAX];
	
	    do {
	        printf("Digite a quantidade de linhas do seu mapa(Maximo: %d): ", MAX);
	        scanf("%d", &linhas);
	        if (linhas < 4 || linhas > MAX)
	            printf("Numero invalido! Escolha entre 4 e %d.\n", MAX);//menor numero de linhas � 4
	    } while (linhas < 4 || linhas > MAX);
	
	    do {
	        printf("Digite a quantidade de colunas do seu mapa(Maximo: %d): ", MAX);
	        scanf("%d", &colunas);
	        if (colunas < 4 || colunas > MAX)
	            printf("Numero invalido! Escolha entre 4 e %d.\n", MAX);//menor numero de colunas � 4
	    } while (colunas < 4 || colunas > MAX);
	
	    for (i = 0; i < linhas; i++){
	    	 for (j = 0; j < colunas; j++){
	    	 	mapa[i][j] = ' ';//preenchendo os espa�os em branco da matriz
			 }
		}
	       
	    srand(time(NULL));//fun�ao de aleatorizar
	    int max_robos = linhas * colunas - 2;//maximo de robos possiveis
	
	    do {
	        printf("Quantos robos deseja adicionar? (maximo %d): ", max_robos);
	        scanf("%d", &qtd_robos);
	        if (qtd_robos > max_robos || qtd_robos < 0)
	            printf("N�mero invalido! Voc� pode escolher entre 0 e %d robos.\n", max_robos);
	    } while (qtd_robos > max_robos || qtd_robos < 0);
	
	    for (i = 0; i < qtd_robos; i++) {//colocando de maneira aleatoria os robos no mapa
	        do {
	            lin_rob = rand() % linhas;
	            col_rob = rand() % colunas;//os operadores de porcentagem limitam os numeros que a fun��o rand pega
	        } while (mapa[lin_rob][col_rob] != ' ');
	        mapa[lin_rob][col_rob] = 'R';
	    }
	
	    // POSI��O DO HUMANO (pode sobrepor rob�)
	    do {
	        printf("Digite a posicao que o humano estara (linha e coluna): ");
	        scanf("%d %d", &lin_hum, &col_hum);
	
	        if (lin_hum < 0 || lin_hum >= linhas || col_hum < 0 || col_hum >= colunas) {
	            printf("Posicao fora do mapa!\n");
	            continue;//continue repete a leitura ao inicio do while enquanto nao for digitado um valor valido
	        }
	
	        break;
	    } while (1);
	
	    mapa[lin_hum][col_hum] = 'H';//coloca o H na posi��o que foi definida a linha e a coluna do humano
	
	    // POSI��O DA SA�DA (pode sobrepor rob�)
	    do {
	        printf("Digite a posicao que a chegada estara (linha e coluna): ");
	        scanf("%d %d", &lin_saida, &col_saida);
	
	        if (lin_saida < 0 || lin_saida >= linhas || col_saida < 0 || col_saida >= colunas) {
	            printf("Posicao fora do mapa!\n");
	            continue;
	        }
	
	        if (mapa[lin_saida][col_saida] == 'H') {
	            printf("Ja existe alguem nessa posicao!\n");
	            continue;
	        }
	
	        break;
	    } while (1);
	
	    mapa[lin_saida][col_saida] = 'Z';//coloca o Z na posi��o que foi definida a linha e a coluna da saida
	
	    // IMPRIME O MAPA INICIAL
	    printf("\nMapa Inicial da Matriz\n");
	    for (i = 0; i < linhas; i++) {
	        for (j = 0; j < colunas; j++) {
	            printf("|%c|", mapa[i][j]);
	        }
	        printf("\n");
	    }
	
	    printf("\nBuscando caminho com DFS...\n");
	
	    // Vari�vel usada para indicar se foi encontrado um caminho at� a sa�da (1 = sim, 0 = n�o)
		int encontrou = 0;
	
		// Vetores de dire��o: dx e dy indicam os movimentos em linha e coluna
		// Ordem: cima (-1,0), baixo (+1,0), esquerda (0,-1), direita (0,+1)
			int dx[] = {-1, 1, 0, 0};
			int dy[] = {0, 0, -1, 1};
	
		// Vari�vel de controle do for
		int d;
	
		// Tenta iniciar a DFS a partir de cada uma das 4 dire��es vizinhas do ponto onde est� o humano
		for (d = 0; d < 4; d++) {
	    	// Calcula as coordenadas da c�lula vizinha em uma das dire��es
	    	int nova_lin = lin_hum + dx[d];  // nova linha
	    	int nova_col = col_hum + dy[d];  // nova coluna
	
	    	// Chama a DFS a partir dessa posi��o
	    	// Se a DFS encontrar um caminho at� 'Z', marca como encontrado e para o la�o
	    	if (dfs(mapa, nova_lin, nova_col, linhas, colunas)) {
	        	encontrou = 1;
	        	break;
	    	}
		}
	
	
	    if (encontrou) {
	        printf("Caminho encontrado!\n");
	    } else {
	        printf("Nao foi possivel encontrar um caminho.\n");
	    }
	
	    // IMPRIME O MAPA COM O CAMINHO
	    printf("\nMapa com caminho:\n");
	    for (i = 0; i < linhas; i++) {
	        for (j = 0; j < colunas; j++) {
	            printf("|%c|", mapa[i][j]);
	        }
	        printf("\n");
	    }
	
	    return 0;
	}

