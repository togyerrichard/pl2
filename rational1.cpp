#include <stdio.h>

class CRational {
private:
	static const int POSITIVE;
	static const int NEGATIVE;
	static int instanceCounter;
	int q;
public:
	int p;
	const int &P;
	const int &Q;
	static int getInstanceCount() { return instanceCounter; }
	int getP() const { return p; } /* implicit inline  */
	inline int getQ() const { return q; }
	// general constructor
	CRational(int p, int q);
	// conversion constructor
	CRational(int i = 0);
	// copy constructor
	CRational(const CRational &origin);
	// destructor
	~CRational();
	friend CRational add(const CRational &a, const CRational &b);
};

CRational add(const CRational &a, const CRational &b) {
	CRational sum ( a.p * b.q + b.p * a.q, a.q * b.q );
	return sum;
}

int main() {
	CRational a ( 2, -4 ), b = { 12, 4 };
	CRational s = add(a,5);
	return 0;
}


const int CRational::POSITIVE = +1;
const int CRational::NEGATIVE = -1;
int CRational::instanceCounter = 0;

inline int abs(int a) {
	/*static*/ int counter = 0;
	return a < 0 ? -a : a;
}

int gcd(int a, int b) {
	while ( a != b ) {
		if ( a > b )
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

CRational::CRational(int p, int q) : P (CRational::p), Q (this->q) {
	int s = (p < 0) == (q < 0) ? POSITIVE : NEGATIVE;
	p = abs(p);
	q = abs(q);
	int d = gcd(p,q);
	CRational::p = s * p / d;
	CRational::q = q / d;
	printf("New rational instance (%d/%d) created.\n", P, Q);
	instanceCounter++;
}

CRational::CRational(int i) : P (p), Q (q), p (i), q (1) {
	printf("New integer instance (%d) created.\n", P);
	instanceCounter++;
}

CRational::CRational(const CRational &origin) : P (p), Q (q), p (origin.p), q(origin.getQ()) {
	printf("New copy of (%d/%d) created.\n", P, Q);
	instanceCounter++;
}

CRational::~CRational() {
	printf("Instance (%d/%d) destroyed.\n", P, Q);
	instanceCounter--;
}

void show(CRational &r) {
	r.p++;
	printf("Rational number: %d/%d\n", r.P, r.getQ());
}

CRational global = -1;


