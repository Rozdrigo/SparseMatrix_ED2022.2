#ifndef SPARSEMATRIX.H
#define SPARSEMATRIX .H

#include "NODE.H"

class SparseMatrix
{
private:
    Node *m_head;
    Node *right;
    Node *down;

    int lin;
    int col;
    int value;

public:
    SparseMatrix(int m, int n);

    ∼SparseMatrix();

    void insert(int i, int j, double value);

    double get(int i, int j);

    void print();
}

#endif