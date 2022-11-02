// ##################################################
// Francisco Gabriel da Silva Lima  Matricula: 514586
// Rodrigo Silva Coelho             Matricula: 542101
// ##################################################

#include "SparseMatrix.h"
#include <iostream>

SparseMatrix::SparseMatrix(int m, int n){
  this->lin = m;
  this->col = n;

  m_head = new Node(0, 0, m_head, m_head, NULL);

  //laço para inicializar as colunas
  int cont = 0;
  Node *aux = m_head;
  while(cont < col){
    aux->direita = new Node(0, cont, m_head, aux->direita, NULL);
    aux = aux->direita;
    cont++;
  }

  //laço para inicializar as linhas
  cont = 0;
  aux = m_head;
  while(cont < lin){
    aux->abaixo = new Node(cont, 0, aux->abaixo, m_head, NULL);
    aux = aux->abaixo;
    cont++;
  }
}

SparseMatrix::~SparseMatrix(){
}

void SparseMatrix::insert(int i, int j, double value){

  //Tratativa de erro outrange
  if(i > lin || j > col || i < 0 || j < 0){
    throw std::invalid_argument("Posição fora da matriz");
  }

  //Inicializa dois nós auxiliares na posição [0, 0];
  Node *aux_col_0i = m_head;
  Node *aux_lin_j0 = m_head;

  //Encontra sentinela da linha i;
  while(aux_col_0i->linha != i)
    aux_col_0i = aux_col_0i->abaixo;

  //Inicializa um nó auxiliar na posição [0, i];
  Node *aux_antes_do_inserido = aux_col_0i;

  //Encontra e atribui a aux_antes_do_inserido a maior posição menor que j;
  while(aux_antes_do_inserido->direita->coluna < j && aux_antes_do_inserido->direita != aux_col_0i)
    aux_antes_do_inserido = aux_antes_do_inserido->direita;

  //Encontra sentinela da coluna j;
  while(aux_lin_j0->direita != j)
    aux_lin_j0 = aux_lin_j0->direita;

  //Inicializa um no auxiliar na posição [j, 0];
  Node *aux_acima_do_inserido = aux_lin_j0;

  //Encontra e atribui a aux_lin_j0 a maior posição menor que i;
  while(aux_acima_do_inserido->abaixo->linha < i && aux_acima_do_inserido->abaixo != aux_lin_j0)
    aux_lin_j0 = aux_lin_j0->abaixo;

  //Atualiza o valor de um nó existente ou cria um novo e adiciona-o à lista;
  if(aux_antes_do_inserido->direita->linha == i && aux_antes_do_inserido->direita->coluna == j){
    aux_antes_do_inserido->direita->valor = value;
  }else{
    aux_antes_do_inserido->direita = new Node(i, j, aux_antes_do_inserido->direita, aux_lin_j0->abaixo, value);
    aux_acima->abaixo = aux_antes_do_inserido->direita;
  }

}

double SparseMatrix::get(int i, int j){
}

void SparseMatrix::print(){
}
