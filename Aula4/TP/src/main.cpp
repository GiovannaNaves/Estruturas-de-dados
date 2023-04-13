#include "pilha.hpp"
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    Pilha p;
    for (int i = 1; i <= 10; i++)
    {
        int num = rand() % 10;
        cout << "empilhando o numero " << num << endl;
        p.Empilhar(num);
    }
    for (int i = 1; i <= 10; i++)
    {
        cout << "desempilhando o numero " << p.Desempilhar() << endl;
    }
    return 0;
}
