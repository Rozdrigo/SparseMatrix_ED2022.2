// ##################################################
// Francisco Gabriel da Silva Lima  Matricula: 514586
// Rodrigo Silva Coelho             Matricula: 542101
// ##################################################

#include "SparseMatrix.h"
#include <iostream>

SparseMatrix::SparseMatrix(int m, int n){
  this->lin = m;
  this->col = n;

  m_head = new Node(0, 0, m_head, m_head, 0);

  //laço para inicializar as colunas
  int cont = 0;
  Node *aux = m_head;
  while(cont < col){
    aux->direita = new Node(0, cont, m_head, aux->direita, 0);
    aux = aux->direita;
    cont++;
  }

  //laço para inicializar as linhas
  cont = 0;
  aux = m_head;
  while(cont < lin){
    aux->abaixo = new Node(cont, 0, aux->abaixo, m_head, 0);
    aux = aux->abaixo;
    cont++;
  }
}

SparseMatrix::~SparseMatrix(){
  //Criando variaveis auxiliares de linha e coluna
  Node *aux_linha = m_head;
  Node *aux_coluna = m_head;

  //Criando variaveis referencia
  Node *referencia_i = m_head;
  Node *referencia_j = m_head;

  //Enquanto o nó abaixo do auxiliar for diferente de m_head faça;
  while (aux_linha->abaixo != m_head){
    //Definindo linha da coluna;
    aux_coluna = aux_linha;
    //Enquanto o nó a direita do auxiliar da coluna for diferente do nó sentinela da linha faça;
    while (aux_coluna->direita != aux_linha)
    {
      //Salvando uma referencia para o nó seguinte;
      referencia_j = aux_coluna->direita;
      //Liberando espaço de memoria que aux_coluna aponta;
      delete(aux_coluna);
      //Atribuindo a aux_coluna a referencia do elemento seguinte que foi salva;
      aux_coluna = referencia_j;
    }
    //Salvando uma referencia para o nó seguinte;
    referencia_i = aux_linha->abaixo;
    //Liberando espaço de memoria que aux_linha aponta;
    delete(aux_linha);
    //Atribuindo a aux_linha a referencia do elemento seguinte que foi salva;
    aux_linha = referencia_i;
  }
  
}

void SparseMatrix::insert(int i, int j, double value){

  //Tratativa de erro out-range
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
  while(aux_lin_j0->direita->coluna != j)
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
    aux_antes_do_inserido->direita = new Node(i, j, aux_antes_do_inserido->direita, aux_acima_do_inserido->abaixo, value);
    aux_acima_do_inserido->abaixo = aux_antes_do_inserido->direita;
  }

}

double SparseMatrix::get(int i, int j){
  Node *aux = m_head;

  //Percorre a matriz até encontrar a linha i;
  while (aux->linha != i)
    aux = aux->abaixo;

  //Percorre a linha i enquanto a coluna de aux for menor que j;
  while (aux->coluna < j)
    aux = aux->direita;
  
  //Verifica que foi possivel encontrar linha e coluna expecificada;
  //Se não retorna 0;
  if(aux->coluna == i && aux->linha == j){
    return aux->valor;
  }else return 0;
}

// Ainda precisa ser implementando uma forma de imprimir os nós que não
// foram preenchidos
// Dessa forma só imprime os nós que foram alocados
void SparseMatrix::print(){
  //Ponteiro que aponta para o início de cada linha
  Node *aux_lin = m_head->abaixo;
  //Ponteiro que vai percorrer cada elemento da linha
  Node *aux_col = aux_lin->direita;

  while(aux_lin != m_head){
    while(aux_col != aux_lin){
      std::cout << aux_col->valor << " ";
      aux_col = aux_col->direita;
    }
    std::cout << std::endl;
    aux_lin = aux_lin->abaixo;
    aux_col = aux_lin->direita;
  }
}