#include "abb.h"
#include <conio.h>
using namespace std;

/* Prof. Irineu - Est. de Dados
Projeto de base para implementação de Árvore Binária de Busca (AVL). Supõe-se:
- main.cpp: front-end com usuário;
- abb.h e abb.cpp: prototipação OO de métodos de manipulação da árvore binária de busca (abb),
 contendo definição "struct" do nó-dado (campos info, filho_esquerda e filho_direita; como 
 também os métodos de manipulação como biblioteca OO.
Dica: referência de muitos métodos em: 
 https://www.ic.unicamp.br/~rocha/teaching/2016s1/mc202/aulas/arvore-binaria-busca-01.pdf  
 Livro Robert Lafore, ED e Alg em Java - Ciência Moderna, 2004.
Obs.: Recursos e métodos adicionais à biblioteca deverão ser desenvolvidos com base neste modelo.
*/
 
//função de interface com o usuário, apenas para facilitar mensagens sobre o estado da árvore 


void menu (){
	cout << "\n\n================================"<< endl;
	cout << "ARVORE BINARIA DE BUSCA OO" << endl;
	cout << "================================"<< endl;
	cout << "Escolha a opcao: " << endl;
	cout << " 1- Insere" << endl;
	cout << " 2- Imprime" << endl;
	cout << " 3- Busca" << endl;
	cout << " 4- Qtd de nós na arvore" << endl;
	cout << " 5- Imprime em Ordem" << endl;
	cout << " 6- Imprime em Pre-Ordem" << endl;
	cout << " 7- Imprime em Pós-Ordem" << endl;
	cout << " 8- Nivel da Arvore" << endl;
	cout << " 9- Retira valor" << endl;
	cout << "10- Balancear Arvore" << endl;
	cout << "11- Reiniciar Arvore" << endl;
	cout << "12- Imprimir raiz" << endl;
	cout << "13- SAIR" << endl;
	cout << "OPÇÃO: ";
	
}


int main(int argc, char** argv) {
	
	int opcao, aux;
	setlocale(LC_ALL, "Portuguese");

	ArvBB tree; //instancia objeto conforme a classe, construtor faz root = NULL

	
	do{
		menu();
		scanf("%d", &opcao);
		
		switch (opcao){
			
			case 1: 
				cout << "Informe um valor para ser inserido na arvore:";
				scanf("%d",& aux);
				tree.insere(aux);
				break;
				
			case 2: 
				cout << "Imprimindo arvore!" << endl;
				tree.displayTree();	
				break;
				
			case 3:
				cout << "Buscar elemento: " << endl;
				scanf("%d",& aux);
				tree.busca(aux);
				break;
			case 4: 
				cout << "Quantidade de nodos: " << tree.QtdNodos(tree.getRoot()) << endl;	
				break;
			case 5:
				tree.exibirEmOrdem(tree.getRoot());
				break;		
			case 6:
				tree.exibirPreOrdem(tree.getRoot());
				break;	
			case 7:
				tree.exibirPosOrdem(tree.getRoot());
				break;	
			case 8:
				printf("Nivel da arvore: %d",tree.nivel()+1);
				break;									
			case 9:
				printf("Retirar elemento:");
				scanf("%d",&aux);
				tree.retira(aux);
				break;
			case 10:
				tree.balancear(tree.getRoot());
				break;											
			case 11:
				cout << "Reiniciando arvor";
				tree.reiniciaTree();
				break;
				
			case 12:
				tree.displayRoot();
				break;
			default:
				cout<< "Opcao invalida";	
		}
	}while(opcao>=1 && opcao<=12);
	
	
	
	
	
	
	
	cout << "Fim de programa!" << endl;
	tree.~ArvBB(); //destrutor da árvore
	cout << "Árvore destruída (desalocada)\n";
	system("pause");

	return 0;
}
