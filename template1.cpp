#include <stdio.h>

template < class T > inline T Max(T a, T b) {
	T m = a > b ? a : b;
	return m;
}

inline char Max(char a, char b) {
	return a;
}

class CCurrency {
	long dollars;
	int cents;
public:
	long getDollars() const { return dollars; }
	int getCents() const { return cents; }
	CCurrency( long d, int c ) : dollars (d + c / 100 ), cents ( c % 100 ) {}
	bool operator>( const CCurrency &val ) const {
		return dollars * 100 + cents  > val.dollars * 100 + cents;
	}
};

int main() {
	int a = 3, b = 2;
	double x = 3.2, y = 5.7;
	printf("%d\n", Max(a,b));
	printf("%f\n", Max(x,y));
	printf("%c\n", Max('b','x'));
	CCurrency c ( 3, 275 ), d ( 5, 115 );
	CCurrency g = Max(c,d);
	printf("%d.%d\n", g.getDollars(), g.getCents());
	return 0;
}

