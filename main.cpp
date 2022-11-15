#include <iostream>
#include "SparseMatrix.h"
#include <fstream>
#include <string.h>
using namespace std;

SparseMatrix readSparseMatrix(std::string nome_do_arquivo){
  SparseMatrix *mat;
  int m = 0, n = 0, l = 0, c = 0;
  double val = 0.0;

  ifstream arquivo;
  string linha;

  arquivo.open(nome_do_arquivo);
  if(arquivo.is_open()){
    arquivo >> m >> n;
    mat = new SparseMatrix(m, n);
    while (arquivo >> l >> c >> val)
    {
      mat->insert(l, c, val);
    }
    arquivo.close();
  }else{
    cout << "Não foi possivel abrir o arquivo" << endl;
  }
  return *mat;
}

int main(){
  auto a = SparseMatrix(2, 2);
  auto b = SparseMatrix(2, 2);

  a.insert(1, 1, -1);
  a.insert(1, 2, 3);
  a.insert(2, 1, 4);
  a.insert(2, 2, 2);

  b.insert(1, 1, 1);
  b.insert(1, 2, 2);
  b.insert(2, 1, 3);
  b.insert(2, 2, 4);

  auto c = a.multiplicar(b);
}