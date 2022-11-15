#include <iostream>
#include "SparseMatrix.h"
#include <fstream>
using namespace std;

SparseMatrix* readSparseMatrix(std::string nome_do_arquivo){
  SparseMatrix *mat;

  int m = 0, n = 0;
  int l = 0, c = 0;
  double val = 0.0;

  ifstream arquivo;
  string linha;

  arquivo.open(nome_do_arquivo);

  if(arquivo.is_open()){
    
    arquivo.close();
  }else{
    cout << "Não foi possivel abrir o arquivo" << endl;
  }
  return mat;
}


int main(){
  readSparseMatrix("matrixA.txt");
}