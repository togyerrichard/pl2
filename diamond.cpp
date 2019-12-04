#include <stdio.h>

class Reference {
public:
	char title[1000];
	virtual void print() = 0;
};


class Book : public virtual Reference {
public:
	char author[200];
	void print() { printf("%s %s", title, author); }
};

class URL : public virtual Reference {
public:
	char url[500];
	void print() { printf("%s %s", title, url); }
};

class OnlineBook : public Book, public URL {
	void print() { /*  URL::print(); */ printf("%s %s %s", title, url, author); }
};


int main() {
	printf("%d\n", sizeof(Reference));
	printf("%d\n", sizeof(Book));
	printf("%d\n", sizeof(URL));
	printf("%d\n", sizeof(OnlineBook));
	//Reference a;
	OnlineBook ob;
	ob.Book::title[0] = 'A';
	ob.URL::title[0] = 'B';
	ob.title[0] = 'B';
	printf("%c %c\n", ob.Book::title[0], ob.URL::title[0]);
}
