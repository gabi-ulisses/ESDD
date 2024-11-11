#include <stdio.h>

int verificarSubstring(const char *str1, const char *str2) {
    while (*str1) {
        const char *s1 = str1, *s2 = str2;
        while (*s1 && *s2 && (*s1 == *s2)) {
            s1++;
            s2++;
        }
        if (!*s2) {  // Se s2 chegou ao final, é uma substring
            return 1;
        }
        str1++;
    }
    return 0;  // Não encontrou a substring
}

int main() {
    char str1[100], str2[100];
    
    // Lê as duas strings
    printf("Digite a primeira string: ");
    scanf("%99s", str1);
    
    printf("Digite a segunda string: ");
    scanf("%99s", str2);
    
    if (verificarSubstring(str1, str2)) {
        printf("A segunda string ocorre dentro da primeira.\n");
    } else {
        printf("A segunda string não ocorre dentro da primeira.\n");
    }
    
    return 0;
}
