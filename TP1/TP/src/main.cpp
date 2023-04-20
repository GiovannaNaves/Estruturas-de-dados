

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Função para construir a árvore binária de expressão a partir da expressão posfixa
TipoNo* buildExpressionTree(string expression) {
    // Cria uma pilha vazia
    Pilha<TipoNo*> nodePilha(expression.length());

    // Percorre a expressão caractere a caractere
    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];

        // Se o caractere for um dígito, cria um nó com esse valor e empilha na pilha de nós
        if (isdigit(c)) {
            TipoNo *node = new TipoNo(c);
            nodePilha.Empilha(node);
        }
        // Se o caractere for um operador, desempilha dois nós da pilha e cria um novo nó com o operador,
        // usando os dois nós desempilhados como filhos esquerdo e direito
        else if (isOperator(c)) {
            TipoNo *dirNode = nodePilha.Desempilha();
            TipoNo *esqNode = nodePilha.Desempilha();
            TipoNo *node = new TipoNo(c);
            node->esq = esqNode;
            node->dir = dirNode;
            nodePilha.Empilha(node);
        }
    }

    // O único nó restante na pilha é a raiz da árvore
    return nodePilha.Desempilha();
}

// Função para avaliar uma árvore binária de expressão
int evaluateExpressionTree(TipoNo *raiz) {
// Se o nó for uma folha, retorna o seu valor (que deve ser um dígito)
if (raiz->esq == nullptr && raiz->dir == nullptr) {
return raiz->value - '0'; // Converte o caractere em um inteiro
}
// Avalia as subárvores esquerda e direita recursivamente
int esqValue = evaluateExpressionTree(raiz->esq);
int dirValue = evaluateExpressionTree(raiz->dir);

// Realiza a operação indicada pelo operador presente no nó raiz e retorna o resultado
switch (raiz->value) {
    case '+':
        return esqValue + dirValue;
    case '-':
        return esqValue - dirValue;
    case '*':
        return esqValue * dirValue;
    case '/':
        return esqValue / dirValue;
}
return 0; 
}

int main() {
    ifstream inputFile("expressao.txt");

    string expression;
    getline(inputFile, expression);

    inputFile.close();

    // Constrói a árvore binária de expressão
    TipoNo *raiz = buildExpressionTree(expression);

    cout << "Resultado: " << evaluateExpressionTree(raiz) << endl;

    delete raiz;

    return 0;
}