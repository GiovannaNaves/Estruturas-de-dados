#include "pilha.hpp"
#include <cstdlib>
#include <ctime>

using namespace std;

int main(){
    srand(time(NULL));
    Pilha p;
    for (int i = 1; i <=5; i++){
        int num = rand() % 10;
        cout << num << endl;
        p.Empilhar(num); 
    }
    for (int i = 1; i <=5; i++){
        cout << p.Desempilhar() << endl;
    }
    return 0;
}
