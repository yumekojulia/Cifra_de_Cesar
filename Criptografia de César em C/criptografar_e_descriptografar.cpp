#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

void criptografar(char *frase, int chave) {
    int i;
    for (i = 0; i < strlen(frase); i++) {
        char caractere = frase[i];
        if (isalpha(caractere)) {
            if (islower(caractere)) {
                frase[i] = 'a' + (caractere - 'a' + chave) % 26;
            } else if (isupper(caractere)) {
                frase[i] = 'A' + (caractere - 'A' + chave) % 26;
            }
        }
    }
}

void descriptografar(char *frase, int chave) {
    int i;
    for (i = 0; i < strlen(frase); i++) {
        char caractere = frase[i];
        if (isalpha(caractere)) {
            if (islower(caractere)) {
                frase[i] = 'a' + (caractere - 'a' - chave + 26) % 26;
            } else if (isupper(caractere)) {
                frase[i] = 'A' + (caractere - 'A' - chave + 26) % 26;
            }
        }
    }
}

int main(int argc, char *argv[])
{
    setlocale(LC_ALL, "portuguese-brazilian");
    char frase[101];
    int chave;

    printf("Digite uma frase: ");
    fgets(frase, sizeof(frase), stdin);

    frase[strcspn(frase, "\n")] = '\0';
    
    printf("Informe a chave de Criptografia (nº inteiro): ");
    scanf("%d", &chave);

    // Salva a frase original para comparação
    char fraseOriginal[101];
    strcpy(fraseOriginal, frase);

    // CRIPTOGRAFIA
    criptografar(frase, chave);
    printf("\nFrase criptografada: %s\n", frase);

    // DESCRIPTOGRAFIA
    descriptografar(frase, chave);
    printf("Frase descriptografada: %s\n", frase);

    return 0;
}

