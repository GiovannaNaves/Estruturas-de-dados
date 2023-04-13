#include "pilha.hpp"
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    Pilha p;
    srand(time(NULL));
    for (int i = 1; i <=10; i++){
        int num = rand() % 10;
        cout << num << endl;
        p.Empilhar(num); 
    }
    for (int i = 1; i <=10; i++){
        cout << p.Desempilhar() << endl;
    }
    return 0;
}
