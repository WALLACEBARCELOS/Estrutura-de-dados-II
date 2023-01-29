#include "abb.h"
#include <conio.h>
using namespace std;

/* Prof. Irineu - Est. de Dados
Projeto de base para implementa��o de �rvore Bin�ria de Busca (AVL). Sup�e-se:
- main.cpp: front-end com usu�rio;
- abb.h e abb.cpp: prototipa��o OO de m�todos de manipula��o da �rvore bin�ria de busca (abb),
 contendo defini��o "struct" do n�-dado (campos info, filho_esquerda e filho_direita; como 
 tamb�m os m�todos de manipula��o como biblioteca OO.
Dica: refer�ncia de muitos m�todos em: 
 https://www.ic.unicamp.br/~rocha/teaching/2016s1/mc202/aulas/arvore-binaria-busca-01.pdf  
 Livro Robert Lafore, ED e Alg em Java - Ci�ncia Moderna, 2004.
Obs.: Recursos e m�todos adicionais � biblioteca dever�o ser desenvolvidos com base neste modelo.
*/
 
//fun��o de interface com o usu�rio, apenas para facilitar mensagens sobre o estado da �rvore 


void menu (){
	cout << "\n\n================================"<< endl;
	cout << "ARVORE BINARIA DE BUSCA OO" << endl;
	cout << "================================"<< endl;
	cout << "Escolha a opcao: " << endl;
	cout << " 1- Insere" << endl;
	cout << " 2- Imprime" << endl;
	cout << " 3- Busca" << endl;
	cout << " 4- Qtd de n�s na arvore" << endl;
	cout << " 5- Imprime em Ordem" << endl;
	cout << " 6- Imprime em Pre-Ordem" << endl;
	cout << " 7- Imprime em P�s-Ordem" << endl;
	cout << " 8- Nivel da Arvore" << endl;
	cout << " 9- Retira valor" << endl;
	cout << "10- Balancear Arvore" << endl;
	cout << "11- Reiniciar Arvore" << endl;
	cout << "12- Imprimir raiz" << endl;
	cout << "13- SAIR" << endl;
	cout << "OP��O: ";
	
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
	tree.~ArvBB(); //destrutor da �rvore
	cout << "�rvore destru�da (desalocada)\n";
	system("pause");

	return 0;
}
