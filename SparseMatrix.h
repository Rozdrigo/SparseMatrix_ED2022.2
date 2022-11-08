// ##################################################
// Francisco Gabriel da Silva Lima  Matricula: 514586
// Rodrigo Silva Coelho             Matricula: 542101
// ##################################################

#ifndef SPARSEMATRIX_H
#define SPARSEMATRIX_H

#include "node.h"

class SparseMatrix
{
private:
    Node *m_head;

    int lin;
    int col;

public:
    SparseMatrix(int m, int n);

    ~SparseMatrix();

    void insert(int i, int j, double value);

    double get(int i, int j);

    void print();

    SparseMatrix *somar(SparseMatrix &B);

    SparseMatrix *multiplicar(SparseMatrix &B);

};

#endif