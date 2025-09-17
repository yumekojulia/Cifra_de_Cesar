#include <stdio.h>
#include <locale.h>
#include <string.h>
#include <ctype.h>

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
    char fraseCriptografada[101];

    printf("Digite a frase criptografada: ");
    fgets(fraseCriptografada, sizeof(fraseCriptografada), stdin);
    fraseCriptografada[strcspn(fraseCriptografada, "\n")] = '\0';
    
    printf("\nTeste de todas as chaves...\n");

    for (int chave = 1; chave <= 26; chave++) {
        char copiaFrase[101];
        strcpy(copiaFrase, fraseCriptografada);
        
        descriptografar(copiaFrase, chave);
        
        printf("Chave %2d: %s\n", chave, copiaFrase);
    }

    return 0;
}

