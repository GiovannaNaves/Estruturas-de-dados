#include "arvore.hpp"

void ArvoreExp::ConstruirArvore(std::string exp) {
    Pilha<TipoNo*> p;

    for (auto elemento : exp) {
        TipoNo* no = new TipoNo(elemento);

        if (isOperador(elemento)) {
            no.dir = p.Desempilha();
            no.esq = p.Desempilha();
        }

        p.Empilha(no);
    }
    
    this->raiz = p.Desempilha();
}

float ArvoreExp::Resolver() {

}



void ArvoreExp::PrintarPosOrdem(node) {
    if (node->left != NULL) {
        return Buscar(node->left)
    }
    
    if (node->right != NULL) {
        return Buscar(node->right)
    }

    printf(node->valor);
}


void ArvoreExp::PrintarEmOrdem(node) {
    printf("(");

    if (node->left != NULL) {
        return Buscar(node->left);
    }
    
    printf(node->valor);
    
    if (node->right != NULL) {
        return Buscar(node->right);
    }

    printf(")");
}