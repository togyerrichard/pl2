#include <stdio.h>

class CRational {
private:
	int p;
	int q;
public:
	int getP() const {
		return p;
	}
	int getQ() const {
		return q;
	}
	static int abs(int a) {
		return a < 0 ? -a : a;
	}
	static int gcd(int a, int b);
	CRational(int p, int q);
	CRational(int i = 0) :
			p(i), q(1) {
	}
	friend CRational operator +(const CRational &a, const CRational &b);
	friend CRational operator -(const CRational &a, const CRational &b);
	CRational operator *(const CRational &a) const;
	int operator ~() const {
		return p / q;
	}
//	CRational operator- () const { CRational neg (-p,q); return neg; }
	CRational & operator++() { p = p + q; return *this; }
	CRational operator++(int) { CRational copy (p,q); p = p + q; return copy; }
};
CRational operator -(const CRational &a) { return 0 - a; }
CRational operator -(const CRational &a, const CRational &b) {
	CRational sub(a.p * b.q - b.p * a.q, a.q * b.q);
	return sub;
}

int CRational::gcd(int a, int b) {
	if (a == 0 || b == 0)
		return 0;
	while (a != b) {
		if (a > b)
			a = a - b;
		else
			b = b - a;
	}
	return a;
}

CRational::CRational(int p, int q) {
	int s = (p < 0) == (q < 0) ? +1 : -1;
	int d = gcd(p = abs(p), q = abs(q));
	CRational::p = s * p / d;
	CRational::q = q / d;
}

CRational operator +(const CRational &a, const CRational &b) {
	CRational sum = { a.p * b.q + b.p * a.q, a.q * b.q };
	return sum;
}

CRational CRational::operator *(const CRational &a) const{
	CRational mul = { p * a.p, q * a.q };
	return mul;
}

int main() {
	CRational x(1, 3), y(1, -2);
	x++;
	++x;
	CRational s = -x + 5 + y * 2;
	CRational t = operator +(x, operator +(2, y));
	CRational s1 = 2 + y;
	CRational s2 = (CRational) 2 * y;
	CRational s3 = y * 3;
	printf("%d / %d, \ninteger part: %d \n", s.getP(), s.getQ(), ~s);
}
