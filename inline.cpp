#include <stdio.h>

void draw(int width, int height, char body = 'X') {
	for (int h = 0; h < height; h++) {
		for (int w = 0; w < width; w++) {
			putchar(body);
		}
		putchar('\n');
	}
}

int main(void) {
	draw(2, 3);
	draw(4, 2, '-');

	list(4,6);
	// 4.
	// 5.
	// 6.
	list(4,10,3);
	// 4.
	// 7.
	// 10.

	return 0;
}

