// ##################################################
// Francisco Gabriel da Silva Lima  Matricula: 514586
// Rodrigo Silva Coelho             Matricula: 542101
// ##################################################

#include "SparseMatrix.h"
#include <iostream>

SparseMatrix::SparseMatrix(int m, int n) {
  this->lin = m;
  this->col = n;

  m_head = new Node(0, 0, nullptr, nullptr, 0);

  // laço para inicializar as colunas
  int cont = 1;
  Node *aux = m_head;
  while (cont <= col) {
    aux->direita = new Node(0, cont, m_head, nullptr, 0);
    aux = aux->direita;
    aux->abaixo = aux;
    cont++;
  }

  // laço para inicializar as linhas
  cont = 1;
  aux = m_head;
  while (cont <= lin) {
    aux->abaixo = new Node(cont, 0, nullptr, m_head, 0);
    aux = aux->abaixo;
    aux->direita = aux;
    cont++;
  }
}

SparseMatrix::~SparseMatrix() {
  // Criando variaveis auxiliares de linha e coluna
  Node *aux_linha = m_head;
  Node *aux_coluna = m_head;

  // Criando variaveis referencia
  Node *referencia_i = m_head;
  Node *referencia_j = m_head;

  // Enquanto o nó abaixo do auxiliar for diferente de m_head faça;
  while (aux_linha->abaixo != m_head) {
    // Definindo linha da coluna;
    aux_coluna = aux_linha;
    // Enquanto o nó a direita do auxiliar da coluna for diferente do nó
    // sentinela da linha faça;
    while (aux_coluna->direita != aux_linha) {
      // Salvando uma referencia para o nó seguinte;
      referencia_j = aux_coluna->direita;
      // Liberando espaço de memoria que aux_coluna aponta;
      delete (aux_coluna);
      // Atribuindo a aux_coluna a referencia do elemento seguinte que foi
      // salva;
      aux_coluna = referencia_j;
    }
    // Salvando uma referencia para o nó seguinte;
    referencia_i = aux_linha->abaixo;
    // Liberando espaço de memoria que aux_linha aponta;
    delete (aux_linha);
    // Atribuindo a aux_linha a referencia do elemento seguinte que foi salva;
    aux_linha = referencia_i;
  }
}

void SparseMatrix::insert(int i, int j, double value) {
  // Tratativa de erro out-range
  if (i > lin || j > col || i < 0 || j < 0) {
    throw std::invalid_argument("Posição fora da matriz");
  }

  // Inicializa dois nós auxiliares na posição [0, 0];
  Node *aux_col_0i = m_head;
  Node *aux_lin_j0 = m_head;

  // Encontra sentinela da linha i;
  while (aux_col_0i->linha != i)
    aux_col_0i = aux_col_0i->abaixo;

  // Inicializa um nó auxiliar na posição [0, i];
  Node *aux_antes_do_inserido = aux_col_0i;

  // Encontra e atribui a aux_antes_do_inserido a maior posição menor que j;
  while (aux_antes_do_inserido->direita->coluna < j &&
         aux_antes_do_inserido->direita != aux_col_0i)
    aux_antes_do_inserido = aux_antes_do_inserido->direita;

  // Encontra sentinela da coluna j;
  while (aux_lin_j0->coluna != j)
    aux_lin_j0 = aux_lin_j0->direita;

  // Inicializa um no auxiliar na posição [j, 0];
  Node *aux_acima_do_inserido = aux_lin_j0;

  // Encontra e atribui a aux_lin_j0 a maior posição menor que i;
  while (aux_acima_do_inserido->abaixo->linha < i &&
         aux_acima_do_inserido->abaixo != aux_lin_j0)
    aux_acima_do_inserido = aux_acima_do_inserido->abaixo;

  // Atualiza o valor de um nó existente ou cria um novo e adiciona-o à lista;
  if (aux_antes_do_inserido->direita->linha == i &&
      aux_antes_do_inserido->direita->coluna == j) {
    aux_antes_do_inserido->direita->valor = value;
  } else {
    Node *aux = new Node(i, j, aux_antes_do_inserido->direita, aux_acima_do_inserido->abaixo, value);
    aux_antes_do_inserido->direita = aux;
    aux_acima_do_inserido->abaixo = aux;
  }
}

double SparseMatrix::get(int i, int j) {
  Node *aux = m_head;

  // Percorre a matriz até encontrar a linha i;
  while (aux->linha < i && aux->abaixo->linha != 0)
    aux = aux->abaixo;

  // Percorre a linha i enquanto a coluna de aux for menor que j;
  while (aux->coluna < j && aux->direita->coluna != 0)
    aux = aux->direita;

  // Verifica que foi possivel encontrar linha e coluna expecificada;
  // Se não retorna 0;

  if (aux->coluna == j && aux->linha == i) {
    return aux->valor;
  }
  return 0;
}

void SparseMatrix::print() {
  Node *aux = m_head->abaixo;
  for (int i = 1; i <= lin; i++) {
    Node *colaux = aux->direita;
    for (int j = 1; j <= col; j++) {
      if (colaux->coluna == j) {
        std::cout << colaux->valor << " ";
        colaux = colaux->direita;
      } else
        std::cout << 0 << " ";
    }
    std::cout << std::endl;
    aux = aux->abaixo;
  }
}

SparseMatrix SparseMatrix::somar(SparseMatrix &B) {
  if (this->lin == B.lin && this->col == B.col) {
    for (int i = 1; i <= lin; i++) {
      for (int j = 1; j <= col; j++) {
        this->insert(i, j, this->get(i, j) + B.get(i, j));
      }
    }
    return *this;
  } else {
      throw std::invalid_argument("Operação invalida");
  }
}

SparseMatrix SparseMatrix::multiplicar(SparseMatrix &B) {
  if (this->col == B.lin) {
    for (int i = 1; i <= B.lin; i++) {
      for (int j = 1; j <= this->col; j++) {
        double soma = 0;
        for (int k = 1; k <= B.lin; k++) {
          soma += this->get(i, k) * B.get(k, j);
        }
        this->insert(i, j, soma);
      }
    }
    return *this;
  } else {
    throw std::invalid_argument("Operação invalida");
  }
}