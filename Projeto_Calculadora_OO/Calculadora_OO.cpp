//Calculadora_OO.cpp
//Objetiva implementar os métodos de classe prototipados no .h
#include "Calculadora_OO.h"

Calculadora_OO::Calculadora_OO(){
	this->n1 = this->n2 = 0;
}

Calculadora_OO::Calculadora_OO(float nn1, float nn2){
	this->n1 = nn1;
	this->n2 = nn2;
}

Calculadora_OO::~Calculadora_OO(){
	//comandos úteis ao destrutor, se necessário, para desalocar recursos...
}

float Calculadora_OO::soma(){
	return this->n1 + this->n2;
}

float Calculadora_OO::soma(float nn1, float nn2){
	this->n1 = nn1;
	this->n2 = nn2;
	return this->soma();
	//return Calculadora_OO::soma();
}

float Calculadora_OO::subtracao(){
	return this->n1 - this->n2;
}

float Calculadora_OO::subtracao(float nn1, float nn2){
	this->n1 = nn1;
	this->n2 = nn2;
	return this->subtracao();
	//return Calculadora_OO::subtracao();
}

float Calculadora_OO::multiplicacao(){
	return this->n1 * this->n2;
}

float Calculadora_OO::multiplicacao(float nn1, float nn2){
	this->n1 = nn1;
	this->n2 = nn2;
	return this->multiplicacao();
	//return Calculadora_OO::multiplicacao();
}

float Calculadora_OO::divisao(){
	return this->n1 / this->n2;
}

float Calculadora_OO::divisao(float nn1, float nn2){
	this->n1 = nn1;
	this->n2 = nn2;
	return this->divisao();
	//return Calculadora_OO::divisao();
}

float Calculadora_OO::raizn1(){
	return sqrt(this->n1);
}

float Calculadora_OO::raizn1(float nn1){
	this->n1 = nn1;
	return this->raizn1();
}

float Calculadora_OO::potencia(){
	return pow(this->n1, this->n2);
}

float Calculadora_OO::potencia(float nn1, float nn2){
	this->n1 = nn1;
	this->n2 = nn2;
	return this->potencia();
}

