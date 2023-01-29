#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include "no_dado.h"

using namespace std;

class Lista{
	private:
			no_dado* cabeca;
			no_dado* last;
			int qtd;
	
	public:
			Lista();
			~Lista();
			void insere_ordenado(int i);
			void imprime_inicio();
			void imprime_fim();
			void libera();
			void remove_inicio();
			void remove_fim();
			void remove_elemento(int i);
			void buscar_elemento(int i);	
}; 


