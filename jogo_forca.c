#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TENTATIVAS 6
#define MAX_PALAVRA 20

int main() {
    char palavra[MAX_PALAVRA];
    char palavraOculta[MAX_PALAVRA];
    int tentativas = 0;
    int letrasEncontradas = 0;
    int i, tamanho;

    printf("Bem-vindo ao Jogo da Forca!\n");
    printf("Digite a palavra a ser adivinhada: ");
    scanf("%s", palavra);

    system("clear"); // Limpa a tela (para sistemas Unix-like) - utilize "cls" para sistemas Windows

    tamanho = strlen(palavra);

    for (i = 0; i < tamanho; i++) {
        palavraOculta[i] = '_';
    }
    palavraOculta[i] = '\0';

    while (tentativas < MAX_TENTATIVAS && letrasEncontradas < tamanho) {
        printf("Palavra: %s\n", palavraOculta);
        printf("Tentativas restantes: %d\n", MAX_TENTATIVAS - tentativas);
        printf("Digite uma letra: ");
        
        char letra;
        scanf(" %c", &letra); // Espaço antes do %c para ignorar espaços em branco
        
        int encontrou = 0;
        for (i = 0; i < tamanho; i++) {
            if (palavra[i] == letra && palavraOculta[i] != letra) {
                palavraOculta[i] = letra;
                letrasEncontradas++;
                encontrou = 1;
            }
        }
        
        if (!encontrou) {
            tentativas++;
            printf("Letra incorreta! Tente novamente.\n");
        }
        
        printf("\n");
    }
    
    system("clear"); // Limpa a tela (para sistemas Unix-like) - utilize "cls" para sistemas Windows

    if (letrasEncontradas == tamanho) {
        printf("Parabéns! Você acertou a palavra: %s\n", palavra);
    } else {
        printf("Você perdeu! A palavra correta era: %s\n", palavra);
    }
    
    return 0;
}
