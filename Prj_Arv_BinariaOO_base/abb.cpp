//abb.cpp
//Implementa os m�todos de classe prototipados no .h, biblioteca OO para �rvore bin�ria de busca (abb)
//Por Irineu Lima, ED2 - FeMASS

#include "abb.h"
//Obs.: a ordem de m�todos descritos segue a mesma ordem da prototipa��o da classe no arquivo abb.h
//>>>>>>>>>> M�todos P�blicos - chamdados pelo main de forma direta (p�blica) <<<<<<<<<

//construtor
ArvBB::ArvBB(){
	this->root = abb_criavazia(); //construtor faz a inicializa��o de �rvore vazia
}

//destrutor
ArvBB::~ArvBB(){
	reiniciaTree(); //chama m�todo privado capaz de desalocar n�s-dado alocados e apontados por root
}

//insere novo n�-dado
void ArvBB::insere(int v){
	if (this->root != NULL) 
		abb_insere(this->root, v); //inser��o de demais n�s-dado ap�s root
	else
		this->root = abb_insere(this->root, v); //primeiro n�-dado inserido, root
	this->qtd++;	
}

//Desenha a �rvore para exibi��o de n�s-dados contidos
void ArvBB::displayTree(){ //baseado em displayTree, p.371 - Livro Robert Lafore, ED e Alg em Java - Ci�ncia Moderna, 2004.
	NoArvBB* a = this->root; //inicia do root
	stack<NoArvBB*> globalStack; //uso de bib stack.h da STD lib (cont�iner C++ LIFO)
	globalStack.push(a);
	int nBlanks = 32;
	bool isRowEmpty = false;
	cout << "Vis�o encadeada de �rvore: " << endl;
	
	while (isRowEmpty == false){
		stack<NoArvBB*> localStack; 
		isRowEmpty = true;
	
		for (int j=0; j<nBlanks; j++)
			cout << " ";
	
		while (globalStack.empty()== false){
			NoArvBB* temp = globalStack.top(); //pega topo da pilha global e...
			globalStack.pop(); //...e o remove em seguida
			
			if (temp != NULL){
				cout << temp->info;
				localStack.push(temp->esq);
				localStack.push(temp->dir);
				
				if ((temp->esq != NULL) || (temp->dir != NULL)){
					isRowEmpty = false;
				}	
			}else{
				cout << "-";	
				localStack.push(NULL);
				localStack.push(NULL);	
			}
			int fim = nBlanks*2 - 1;
			for (int j=0; j<fim; j++)
				cout << " ";
		} //fim-while do globalStack n�o vazio
		cout << endl;
		nBlanks = nBlanks / 2;
		while (localStack.empty() == false){
			globalStack.push(localStack.top()); //pega topo da pilha local e...
			localStack.pop(); //...e o remove em seguida
		}
	} //fim-while do isRowEmpty � falso
	cout << endl;
}

//retorna o n�-dado root
NoArvBB* ArvBB::getRoot(){
	return this->root;	
}

//libera e desaloca todos os n�s da �rvore, reiniciando em Null o ponteiro root
void ArvBB::reiniciaTree(){
	this->root = abb_libera(this->root);
}

//retorna true/false se �rvore � vazia?
bool ArvBB::vazia(){
	return no_abb_vazio(this->root);
}

void ArvBB::displayRoot(){
	if (this->root != NULL) 
		cout << "Root -> info: " << this->root->info << endl;
	else
		cout << "�rvore vazia! \n";
}


void ArvBB::busca(int v){
	NoArvBB* a = this->root;
	if(busca_valor(a,v) != NULL){
		printf("Valor encontrado!\n");
	}else{
		printf("Valor n�o encontrado!\n");
	}
}


int ArvBB::QtdNodos(NoArvBB* a){
if(a == NULL) return 0;
//	int qtdEsq = QtdNodos(a->esq);
//    int qtdDir = QtdNodos(a->dir);
//    this->qtd = qtdEsq + qtdDir;
 //   return (this->qtd);
	//cout << "Quantidade de nodos: " << this->qtd << endl;
	return 1 + QtdNodos(a->esq) + QtdNodos(a->dir);
	
}

void ArvBB::retira(int v){
	NoArvBB* a = this->root;
	if(RetiraNo(a,v) != NULL){
		printf("Valor removido!\n");
	}else{
		printf("Valor N�o localizado!\n");
	}
}



int ArvBB::nivel(){
	NoArvBB* a = this->root;
	int nivel = abb_nivel(a);
	return nivel;
}


void ArvBB::exibirEmOrdem(NoArvBB* a){
    if(a != NULL){
        exibirEmOrdem(a->esq);
        printf("%d - ", a->info);
        exibirEmOrdem(a->dir);
    }
}

void ArvBB::exibirPreOrdem(NoArvBB* a){
	if (a != NULL) {
		printf("%d - ", a->info);
		exibirPreOrdem(a->esq);
		exibirPreOrdem(a->dir);
	}
}

void ArvBB::exibirPosOrdem(NoArvBB* a){
	    if(a != NULL){
        exibirPosOrdem(a->esq);
        exibirPosOrdem(a->dir);
        printf("%d - ", a->info);
    }
}


void ArvBB::balancear(NoArvBB* a){
	//criar ponteiro auxilioar oara executar a��o
	int aux;
    if (a == NULL){
        return;
    }
    if(fb(a) == 2){
        if(fb(a->esq) == -1){
            rotacaodireitaesquerda(a->esq);
        }
        //aux = rotacaoesquerdadireita(a);
        //a = aux;
    } else if(fb(a) == -2){
        if (fb(a->dir) == 1){
            rotacaoesquerdadireita(a->dir);
        }
       // aux = rotacaoesquerdadireita(a);
        //a = aux;
    }
    return;
};


NoArvBB* ArvBB::abb_criavazia(){
	return NULL;
}

// m�todo de cria��o: retorna n� criado (alocado)
NoArvBB* ArvBB::abb_cria(int c, NoArvBB* sae, NoArvBB* sad){
	//NoArv* p=(NoArv*)malloc(sizeof(NoArv));
	NoArvBB* p = new NoArvBB(c, this->root);
	
	if(p==NULL){
		cout << "FALHA DE ALOCA��O EM MEM�RIA!\n";
		exit(1);
	} 
	p->info = c;
	p->esq = sae;
	p->dir = sad;
	return p;
}

//M�todo de controle de inser��o de novo n�-dado - garante l�gica de inser��o de ABB
NoArvBB* ArvBB::abb_insere(NoArvBB* a, int v){
	if (a == NULL) //primeira inser��o, insira n� root
		a = abb_cria (v, NULL, NULL);
	else if (v < a->info)
		a->esq = abb_insere(a->esq,v); //insere como filho � esquerda
	else /*sen�o, temos: v >= a->info */
		a->dir = abb_insere(a->dir,v); //insere como filho � direita
	return a;
}

//M�todo recursivo que desaloca n�s-dado da �rvore, retornando NULL
NoArvBB* ArvBB::abb_libera(NoArvBB* a){
	if (!no_abb_vazio(a)){
		abb_libera(a->esq); /* libera sae */
		abb_libera(a->dir); /* libera sad */
		free(a); /* libera raiz */
	}
	return NULL;
}

//M�todo que verifica se um n�-dado � nulo?
bool ArvBB::no_abb_vazio(NoArvBB* a){
	return a == NULL;
}

NoArvBB* ArvBB::busca_valor(NoArvBB* a,int v){
	if (a == NULL)
	 	return NULL;
	else if (a->info > v)
	 	return busca_valor(a->esq, v);
	else if (a->info < v)
	 	return busca_valor(a->dir, v);
	else return a;
}


NoArvBB* ArvBB::RetiraNo(NoArvBB* a,int v) {
	
	if (a == NULL) {
		return NULL;
	}
	if (busca_valor(a,v) == NULL){
		//cout << "Elemento n�o localizado";
		return 0;
	}
	else if (a->info > v) {
		a->esq = RetiraNo(a->esq, v);
	}
	else if (a->info < v) {
		a->dir = RetiraNo(a->dir, v);
	}
	else {
		if (a->esq == NULL && a->dir == NULL) {  //sem filhos
		free(a);
		a = NULL;
	}
		else if (a->esq == NULL) { //filho a direita apenas 
			NoArvBB* temp = a;
			a = a->dir;
			free(temp);
		}
		else if (a->dir == NULL) { //filho a esquerda apenas
			NoArvBB* temp = a;
			a = a->esq;
			free(temp);
		}
		else { //tem nos dois lados
			NoArvBB* f = a->esq;
			while (f->dir != NULL) {
				f = f->dir;
			}
			a->info = f->info;
			f->info = v;
			a->esq = RetiraNo(a->esq, v);
		}
	}
	
	return a;
}

int ArvBB::abb_nivel (NoArvBB* a) {
   if (a == NULL) 
      return -1; // altura da �rvore vazia
   else {
      int he = abb_nivel (a->esq);
      int hd = abb_nivel (a->dir);
      if (he < hd) return hd + 1;
      else return he + 1;
   }
}


void ArvBB::rotacaodireita(NoArvBB* a){
	NoArvBB* aux = a;
	a = aux->esq;
	aux->esq = a->dir; 
	a->dir = aux;
}

void ArvBB::rotacaoesquerda(NoArvBB* a){
	NoArvBB* aux = a;
	a = aux->dir;
	aux->dir = a->esq; 
	a->esq = aux;
}

void ArvBB::rotacaoesquerdadireita(NoArvBB* r){
	rotacaoesquerda(r->esq);
	rotacaodireita(r); 
}

void ArvBB::rotacaodireitaesquerda(NoArvBB* a){
	rotacaodireita(a->dir);
	rotacaoesquerda(a);
}

int ArvBB::fb(NoArvBB* a){
	int hd = abb_nivel(a->dir);
	int he = abb_nivel(a->esq);
	return hd-he;   
}


