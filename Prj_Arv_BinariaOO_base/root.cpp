//no_dado.cpp
#include "root.h"

//contrutor
NoArvBB::NoArvBB(){
	this->dir = 0;
	this->esq = 0; 
}

//atribuição de valor
NoArvBB::NoArvBB(int i, NoArvBB* abb){
	this->dir = abb;
	this->esq = abb;
	this->info = i;
}
