#include <stdio.h>

int main() {
	int idade;
	float altura;
	char letra_favorita;
	printf("%s\n", "Digite sua idade");
	scanf("%d", &idade);
	printf("%s\n", "Digite sua altura");
	scanf(" %f", &altura);
	printf("%s\n", "Digite sua letra favorita");
	scanf(" %c", &letra_favorita);
	printf("%d\n", idade);
	printf("%f\n", altura);
	printf("%c\n", letra_favorita);

	return 0;
}
