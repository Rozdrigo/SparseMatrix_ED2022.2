#ifndef NODE.H
#define NODE .H

struct Node
{
    Node *direita;
    Node *abaixo;
    int linha;
    int coluna;
    double valor;
};

#endif
