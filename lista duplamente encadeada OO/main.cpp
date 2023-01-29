#include <iostream>
#include "L_dupla_OO.h"
#include <locale>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */


void menu()
{
	cout << "\n________________________________\n";
	cout << "PROGRAMA LISTA ENCADEADA SIMPLES\n";
	cout << "__________________________________\n\n\n";
	cout << "Escolha opção:\n";
	cout << "1- Insere Ordenado" << endl;  
	cout << "2- Remove Inicio" << endl;  
	cout << "3- Remove Fim" << endl;
	cout << "4- Remove Elemento" << endl;
	cout << "5- Imprime Fim" << endl;
	cout << "6- Imprime Inicio" << endl;
	cout << "7- Busca Elemento" << endl;
	cout << "8- Libera" << endl;  
	cout << "(X) para sair" << endl; 
	cout << "OPÇÃO: ";
}


int main(int argc, char** argv) {
	
	setlocale(LC_ALL, "Portuguese");
	
	Lista l; 
	
	int op;
	
	do{
	
		
		menu();
		cin >> op;
		
		switch(op){
			case 1:
				int x;
				cout << "Informe o numero a ser inserido ordenado: ";
				cin >> x;
				l.insere_ordenado(x);
				break;
				
			case 2:
				l.remove_inicio();
				break;
				
			case 3:
				l.remove_fim();
				break;
				
			case 4:
				cout << "Informe o numero a ser Removido: ";
				cin >> x;
				l.remove_elemento(x);
				break;
				
			case 5:
				int z;
				l.imprime_inicio();
				break;
				
			case 6:
				l.imprime_fim();
				break;
				
			case 7:
				cout << "Informe o numero a ser Buscado: ";
				cin >> x;
				l.buscar_elemento(x);
				break;	
				
			case 8:
				l.libera();
				break;	
				
				
			default: cout << "Opção inválida e fim de programa!\n";	
		}
	}while(op>=1 && op<=8);
	
	cout << "Fim de programa!\n";
	system("pause");
	return 0;			
			
}


