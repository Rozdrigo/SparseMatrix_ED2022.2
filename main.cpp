#include "SparseMatrix.h"
#include <iostream>
using namespace std;

int main(){
  SparseMatrix *mat = new SparseMatrix(2, 2);
  SparseMatrix *mat1 = new SparseMatrix(2, 2);

  mat->insert(1, 1, 2);
  mat->insert(1, 2, 2);
  mat->insert(2, 2, 2);


  mat1->insert(1, 1, 5);
  mat1->insert(1, 2, 5);
  mat1->insert(2, 2, 5);

  mat->print();
  cout << endl;
  mat1->print();
  cout << endl;
  mat->somar(*mat1);
  cout << endl;
  cout << mat->get(1, 1);
}