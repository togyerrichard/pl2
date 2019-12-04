#include <stdio.h>

template < class T, int N > class CArray {
	T data[N];
public:
	CArray(T def);
	T & operator [] (int i) { return data[i]; }
	T sum() const;
	template <int M> void copy( CArray<T,M> & val ) const;
};

template < class T, int N > CArray<T,N>::CArray(T def) {
	for ( int i = 0; i < N; i++ ) {
		data[i] = def;
	}
}

template <class T, int N > T CArray<T,N>::sum() const {
	T s = 0;
	for ( int i = 0; i < N ; i++ ) {
		s += data[i];
	}
	return s;
}


template <class T, int N> template <int M> void CArray<T,N>::copy( CArray<T,M> & val ) const {
	for ( int i = 0; i < N && i < M; i++ )
		val[i] = data[i];
}


struct book { char title[100]; };

int main(int argc, char **argv) {
	CArray<double, 5> arr(1.2);
	CArray<double, 3> brr(3.2);

	brr.copy(arr);

	//arr[2] = 7.2;
//	arr[1] = 3.4;
	printf("%f\n", arr.sum());
	CArray<char, 3> chs('A');

	book b = { "Mi a címe ennek a könyvnek?" };
	CArray<book, 3> barr (b);
	//barr.sum();

	return 0;
}

