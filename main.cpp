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
    getline(arquivo, linha);
    m = linha[0];
    n = linha[1];
    cout << m << " " << n << endl;
    mat = new SparseMatrix(m, n);
    while(getline(arquivo, linha)){
      l = linha[0];
      c = linha[1];
      val = linha[2];
      cout << l << " " << c << " " << val << endl;
      mat->insert(l, c, val);
    }
    arquivo.close();
  }else{
    cout << "Não foi possivel abrir o arquivo" << endl;
  }
  return mat;
}


int main(){
  readSparseMatrix("matrixA.txt");
}
