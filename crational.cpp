#include <stdio.h>

template <class T> inline T abs(T v) {
	return v < 0 ? -v : v;
}


template <class T> class Interval {
private:
	T lower;
	T upper;
public:
	Interval( T a, T b );
	bool contains(T v);
};

template <class T> Interval<T>::Interval( T a, T b ) {
	if ( a < b ) {
		lower = a;
		upper = b;
	} else {
		lower = b;
		upper = a;
	}
}

template <class T> bool Interval<T>::contains(T v) {
	return !(v < lower) && !( upper < v );
	// return v >= lower && v <= upper;
}


class CRational {
private:
	int p;
	int q;
public:
	CRational(int i = 0) : p (i), q (1) {};
	CRational(int p, int q);
	int getP() const { return p; }
	int getQ() const { return q; }
	friend bool operator < ( const CRational &a, const CRational &b );
	CRational operator -() const;
};

CRational CRational::operator -() const {
	CRational neg ( -p, q );
	return neg;
}

bool operator < ( const CRational &a, const CRational &b ) {
	return a.p * b.q < b.p * a.q;
}

CRational::CRational(int p, int q) {
	int s = (p < 0) == (q < 0) ? +1 : -1;
	CRational::p = p = abs(p);
	CRational::q = q = abs(q);
	if ( q == 0 ) {
		throw "Nevező nem lehet 0!";
	} else if ( p == 0 ) {
		CRational::p = 0;
		CRational::q = 1;
	} else {
		while ( p != q ) {
			if ( p > q )
				p -= q;
			else
				q -= p;
		}
		CRational::p = CRational::p / p * s;
		CRational::q = CRational::q / p;
	}
}

int main() {
	CRational a ( 15, -42 );
	a = abs(a);
	printf("%d %d\n", a.getP(), a.getQ());

	Interval<CRational> itv ( a, -a );
	itv.contains( 0 );
	return 0;
}
