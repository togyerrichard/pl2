#include <stdio.h>

class CCurrency {
	long dollars;
	int cents;
public:
	long getDollars() const { return dollars; }
	int getCents() const { return cents; }

	CCurrency(long dollars, int cents);
	CCurrency(long dollars) : dollars (dollars), cents (0) {
//		this->dollars = dollars;
//		CCurrency::dollars = dollars;
//		cents = 0;
	}

	CCurrency(double amount);
	friend CCurrency operator+(const CCurrency &a, const CCurrency &b);

	CCurrency operator*( int a ) const;
};


CCurrency operator+(const CCurrency &a, const CCurrency &b) {
	CCurrency sum ( a.dollars + b.dollars, a.cents + b.cents );
	return sum;
}

CCurrency CCurrency::operator*( int a ) const {
	CCurrency mul ( dollars * a, cents * a );
	return mul;
}


CCurrency::CCurrency(long dollars, int cents) {
	CCurrency::dollars = dollars + cents / 100;
	CCurrency::cents = cents % 100;
}

CCurrency::CCurrency(double amount) {
	CCurrency::dollars = (long) amount;
	CCurrency::cents = ( (int) (amount * 100) ) % 100;
}

CCurrency operator* ( int i, const CCurrency &c ) { return c * i; /* c.opartos*(i) */ }

int main() {   //   5.70         5.00      7.50
	CCurrency a ( 3L, 270 ), b ( 5L ), c ( 7.5 );
	const CCurrency s = a + b;
	CCurrency s1 = 2L + a, s2 = b + 4L;
	CCurrency m = 2 * s;  // s.operator*(2);

	printf("%d.%2d", m.getDollars(), m.getCents());
	return 0;
}
