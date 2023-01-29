#include "Lista.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void menu()
{
	cout << "\n________________________________\n";
	cout << "PROGRAMA LISTA ENCADEADA SIMPLES\n";
	cout << "__________________________________\n\n\n";
	cout << "Escolha opção:\n";
	cout << "1- Insere Inicio" << endl;  
	cout << "2- Imprime" << endl;
	cout << "3- Tamanho" << endl;  
	cout << "4- Libera" << endl;
	cout << "5- Buscar" << endl;
	cout << "6- Retira" << endl;
	cout << "7- Insere Fim" << endl;
	cout << "8- Retira Inicio" << endl;
	cout << "9- Retira Fim" << endl; 
	cout << "10- Imprime Inicio" << endl;
	cout << "11- Imprime Fim" << endl;
	cout << "12- Clean" << endl;  
	cout << "13- (X) para sair" << endl; 
	cout << "OPÇÃO: ";
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	
	Lista l; //instanciando objeto l conforme a classe Lista
	
	int op;
	do{
	
		
		menu();
		cin >> op;
		
		switch(op){
			case 1: //Insere inicio
				int x;
				cout << "Informe o numero a ser inserido no inicio: ";
				cin >> x;
				l.insere_inicio(x);
				break;
				
			case 2:
				l.imprime();
				break;
				
			case 3:
				l.tamanho();
				break;
				
			case 4:
				l.libera();
				break;
				
			case 5:
				int z;
				cout << "Informe o numero a ser buscado: ";
				cin >> z;
				l.busca(z);
				break;
			case 6:
				int a;
				cout << "Informe o numero a ser buscado: ";
				cin >> a;
				l.retira(a);
				break;
				
				
				
				
				
				
				
				
				
			default: cout <<  "Opção inválida e fim de programa!\n";
		}
	}while(op>=1 && op<=13);
		
	system("pause");
	
	return 0;
}
