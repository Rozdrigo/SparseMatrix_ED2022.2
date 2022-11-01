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
    aux->abaixo = new Node(cont, 0, m_head, aux->abaixo, NULL);
    aux = aux->abaixo;
    cont++;
  }
}

SparseMatrix::~SparseMatrix(){
}

void SparseMatrix::insert(int i, int j, double value){
}

double SparseMatrix::get(int i, int j){
}

void SparseMatrix::print(){
}
