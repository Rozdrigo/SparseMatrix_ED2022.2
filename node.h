// ##################################################
// Francisco Gabriel da Silva Lima  Matricula: 514586
// Rodrigo Silva Coelho             Matricula: 542101
// ##################################################
#ifndef NODE.H
#define NODE.H

struct Node
{
    Node *direita;
    Node *abaixo;
    int linha;
    int coluna;
    double valor;

    Node(int lin, int col, Node *dir, Node *aba, double val){
        linha = lin;
        coluna = col;
        direita = dir;
        abaixo = aba;
        valor = val;
    }
};

#endif
