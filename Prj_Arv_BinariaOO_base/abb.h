//abb.h
//Define a classe e protótipo de métodos OO para biblioteca de árvore binária de busca (abb)
//Por Irineu Lima, ED2 - FeMASS

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stack> //aplicada para função abb_displayTree - contâiner C++ LIFO
#include "root.h"
using namespace std;

class ArvBB{
	//Declarar atributos
	//public:
	private:
		NoArvBB* root; //controle de ponteiro para nó-dado raiz
		int qtd;
	
	//Declarar cabeçalhos de métodos
	public:
		ArvBB(); //Construtor - método de mesmo nome da classe, não se usa a previsão de retorno
		~ArvBB(); //Destrutor - método executado ao fim ou término de uso do objeto de classe
		void insere(int v);
		void displayTree();
		NoArvBB* getRoot();
		void reiniciaTree();
		bool vazia();
		void displayRoot();
		void busca(int v);
		//void ImprimirQtdNodos();
		int QtdNodos(NoArvBB* a);
		int nivel();
		void exibirEmOrdem(NoArvBB* a);
		void exibirPreOrdem(NoArvBB* a);
		void exibirPosOrdem(NoArvBB* a);
		void retira(int v);
		void balancear(NoArvBB* a);
		
		
	//metodos auxiliares
	private:
		NoArvBB* abb_criavazia();
		NoArvBB* abb_cria (int c, NoArvBB* e, NoArvBB* d);
		NoArvBB* abb_insere(NoArvBB* a, int v);
		NoArvBB* abb_libera(NoArvBB* a);
		bool no_abb_vazio(NoArvBB* a);
		NoArvBB* busca_valor(NoArvBB* a,int v);
		int abb_nivel(NoArvBB* a);
		NoArvBB* RetiraNo(NoArvBB* a,int v);
		void rotacaodireita(NoArvBB* a);
		void rotacaoesquerda(NoArvBB* a);
		void rotacaoesquerdadireita(NoArvBB* a);
		void rotacaodireitaesquerda(NoArvBB* a);
		int fb(NoArvBB* a);
}; //toda classe encerra com ; (padrão da linguagem)

