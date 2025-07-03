#include <stdio.h>

int main() {
	float contador;
	contador = 0;
	while (contador < 3) {
		printf("%f\n", contador);
		contador = (contador + 1);
	}
	float i;
	for (i = 5; (i > 0); i = (i - 1)) {
		printf("%f\n", i);
	}

	return 0;
}
