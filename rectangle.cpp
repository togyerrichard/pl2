#include <stdio.h>

struct rectangle {
	int width;
	int height;
};

class Rectangle {
private: /* this is private by default */
	int width;
	int height;
public:
	Rectangle(int width, int height) {
		this->width = width;
		Rectangle::height = height;
		printf("Instance created;\n");
	}
	Rectangle(int d) : width (d), height (d) /* field initializer list */ {
		/* width = d; height = d; */
		puts("Square instantiated!");
	}
	~Rectangle() {
		printf("Rectangle %d * %d destroyed!\n", width, height);
	}
	void print(char fill = 'X');
};

void Rectangle::print(char fill) {
	for ( int h = 0; h < height; h++ ) {
		for ( int w = 0; w < width; w++ ) {
			printf("%c",fill);
		}
		putchar('\n');
	}
}

void draw( rectangle r, char fill = 'X' ) {
	for ( int h = 0; h < r.height; h++ ) {
		for ( int w = 0; w < r.width; w++ ) {
			printf("%c",fill);
		}
		putchar('\n');
	}
}

int main() {
	rectangle r = { 7, 3 };
	draw(r, '+');
	Rectangle q ( 5, 3 ), q2 = { 4, 2 };
	Rectangle s ( 4 ), s2 = {7}, s3 = 7;
	Rectangle *p = new Rectangle(1);
	delete p;
	s.print('O');
	q.print();
	return 0;
}

