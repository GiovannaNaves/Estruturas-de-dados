#define MAXN 101010

struct No{
	long valor;
	// No* next;
	No* pai;
	int rank;
	
	No(long valor, int rank){
		this->valor = valor;
		// this->next = next;
		this->pai = this;
		this->rank = rank;
	}
};

class ConjuntoDisjunto {
private:
	int pai[MAXN];
	No* conj[MAXN];

public:	
	ConjuntoDisjunto();
	~ConjuntoDisjunto();
	void makeSet(long x);
	void unionSet(long x, long y);
	long findSet(long x);
};