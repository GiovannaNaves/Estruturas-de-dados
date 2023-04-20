#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Definição da classe TreeNode
class TreeNode {
public:
    char value; // Valor do nó (pode ser um operador ou um dígito)
    TreeNode *left; // Ponteiro para o filho esquerdo
    TreeNode *right; // Ponteiro para o filho direito

    // Construtor da classe
    TreeNode(char value) {
        this->value = value;
        left = nullptr;
        right = nullptr;
    }

    // Destrutor da classe
    ~TreeNode() {
        delete left;
        delete right;
    }
};

// Definição da classe Stack
template<class T>
class Stack {
private:
    T *stackArray;
    int top;
    int maxSize;

public:
    // Construtor da classe
    Stack(int maxSize) {
        stackArray = new T[maxSize];
        top = -1;
        this->maxSize = maxSize;
    }

    // Destrutor da classe
    ~Stack() {
        delete[] stackArray;
    }

    // Método para empilhar um elemento na pilha
    void push(T element) {
        if (top == maxSize - 1) {
            cout << "A pilha está cheia!" << endl;
        }
        else {
            top++;
            stackArray[top] = element;
        }
    }

    // Método para desempilhar um elemento da pilha
    T pop() {
        if (top == -1) {
            cout << "A pilha está vazia!" << endl;
            return NULL;
        }
        else {
            T element = stackArray[top];
            top--;
            return element;
        }
    }

    // Método para verificar se a pilha está vazia
    bool isEmpty() {
        return top == -1;
    }
};

// Função para verificar se um caractere é um operador
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Função para construir a árvore binária de expressão a partir da expressão posfixa
TreeNode* buildExpressionTree(string expression) {
    // Cria uma pilha vazia
    Stack<TreeNode*> nodeStack(expression.length());

    // Percorre a expressão caractere a caractere
    for (int i = 0; i < expression.length(); i++) {
        char c = expression[i];

        // Se o caractere for um dígito, cria um nó com esse valor e empilha na pilha de nós
        if (isdigit(c)) {
            TreeNode *node = new TreeNode(c);
            nodeStack.push(node);
        }
        // Se o caractere for um operador, desempilha dois nós da pilha e cria um novo nó com o operador,
        // usando os dois nós desempilhados como filhos esquerdo e direito
        else if (isOperator(c)) {
            TreeNode *rightNode = nodeStack.pop();
            TreeNode *leftNode = nodeStack.pop();
            TreeNode *node = new TreeNode(c);
            node->left = leftNode;
            node->right = rightNode;
            nodeStack.push(node);
        }
    }

    // O único nó restante na pilha é a raiz da árvore
    return nodeStack.pop();
}

// Função para avaliar uma árvore
int evaluateExpressionTree(TreeNode *root) {
// Se o nó for uma folha, retorna o seu valor (que deve ser um dígito)
if (root->left == nullptr && root->right == nullptr) {
return root->value - '0'; // Converte o caractere em um inteiro
}

// Avalia as subárvores esquerda e direita recursivamente
int leftValue = evaluateExpressionTree(root->left);
int rightValue = evaluateExpressionTree(root->right);

// Realiza a operação indicada pelo operador presente no nó raiz e retorna o resultado
switch (root->value) {
    case '+':
        return leftValue + rightValue;
    case '-':
        return leftValue - rightValue;
    case '*':
        return leftValue * rightValue;
    case '/':
        return leftValue / rightValue;
}

return 0;
}

int main() {
// Abre o arquivo contendo a expressão posfixa
ifstream inputFile("expressao.txt");
// Lê a expressão posfixa do arquivo
string expression;
getline(inputFile, expression);

// Fecha o arquivo
inputFile.close();

// Constrói a árvore binária de expressão
TreeNode *root = buildExpressionTree(expression);

// Avalia a expressão e imprime o resultado
cout << "Resultado: " << evaluateExpressionTree(root) << endl;

// Libera a memória alocada pela árvore
delete root;

return 0;
}