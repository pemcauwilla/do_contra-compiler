#include <stdio.h>

int main() {
	int numero;
	printf("%s\n", "Digite um numero");
	scanf("%d", &numero);
	if (numero < 10) {
		printf("%s\n", "Menor que 10");
	} else {
		printf("%s\n", "Maior que 10");
	}
	int resto;
	resto = (numero % 2);
	switch (resto) {
		case 0:
			printf("%s\n", "O numero eh par");
			break;
		
		case 1:
			printf("%s\n", "O numero eh impar");
			break;
	}

	return 0;
}
