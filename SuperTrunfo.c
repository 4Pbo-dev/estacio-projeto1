#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Country {
    char name[50];
    float idh;
    float population;
    float gdp;
    float area;
    float density;
};

float getAttribute(struct Country c, int attr) {
    switch(attr) {
        case 1: return c.idh;
        case 2: return c.population;
        case 3: return c.gdp;
        case 4: return c.area;
        case 5: return c.density;
        default: return -1.0;
    }
}

const char* getAttributeName(int attr) {
    switch(attr) {
        case 1: return "IDH";
        case 2: return "População";
        case 3: return "PIB";
        case 4: return "Área";
        case 5: return "Densidade Demográfica";
        default: return "Desconhecido";
    }
}

int main() {
    struct Country card1 = {"Brasil", 0.758, 213.9e6, 1.609e12, 8.516e6, 25.08};
    struct Country card2 = {"Argentina", 0.842, 45.38e6, 445.5e9, 2.78e6, 16.37};

    int attr1, attr2;
    char buffer[100];

    // Escolha do primeiro atributo
    do {
        printf("Escolha o primeiro atributo (1-5):\n");
        for(int i = 1; i <= 5; i++) {
            printf("%d. %s\n", i, getAttributeName(i));
        }
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%d", &attr1) != 1) {
            printf("Entrada inválida. Digite um número entre 1 e 5.\n");
        }
    } while (attr1 < 1 || attr1 > 5);

    // Escolha do segundo atributo
    do {
        printf("Escolha o segundo atributo (diferente de %d):\n", attr1);
        for(int i = 1; i <= 5; i++) {
            if(i != attr1) {
                printf("%d. %s\n", i, getAttributeName(i));
            }
        }
        fgets(buffer, sizeof(buffer), stdin);
        if (sscanf(buffer, "%d", &attr2) != 1) {
            printf("Entrada inválida. Digite um número entre 1 e 5, diferente de %d.\n", attr1);
            continue;
        }
    } while (attr2 < 1 || attr2 > 5 || attr2 == attr1);

    // Obtém os valores dos atributos
    float c1_attr1 = getAttribute(card1, attr1);
    float c2_attr1 = getAttribute(card2, attr1);
    float c1_attr2 = getAttribute(card1, attr2);
    float c2_attr2 = getAttribute(card2, attr2);

    // Determina os vencedores de cada atributo usando operador ternário
    int result_attr1 = (attr1 == 5) ? 
        (c1_attr1 < c2_attr1 ? 1 : (c2_attr1 < c1_attr1 ? 2 : 0)) :
        (c1_attr1 > c2_attr1 ? 1 : (c2_attr1 > c1_attr1 ? 2 : 0));
    
    int result_attr2 = (attr2 == 5) ? 
        (c1_attr2 < c2_attr2 ? 1 : (c2_attr2 < c1_attr2 ? 2 : 0)) :
        (c1_attr2 > c2_attr2 ? 1 : (c2_attr2 > c1_attr2 ? 2 : 0));

    // Exibe os resultados da comparação
    printf("\nPaíses: %s vs %s\n", card1.name, card2.name);
    
    printf("\nAtributo 1: %s\n", getAttributeName(attr1));
    printf("%s: %.2f\n", card1.name, c1_attr1);
    printf("%s: %.2f\n", card2.name, c2_attr1);
    printf(result_attr1 == 1 ? "%s vence!\n" : 
           result_attr1 == 2 ? "%s vence!\n" : "Empate!\n", 
           result_attr1 == 1 ? card1.name : card2.name);

    printf("\nAtributo 2: %s\n", getAttributeName(attr2));
    printf("%s: %.2f\n", card1.name, c1_attr2);
    printf("%s: %.2f\n", card2.name, c2_attr2);
    printf(result_attr2 == 1 ? "%s vence!\n" : 
           result_attr2 == 2 ? "%s vence!\n" : "Empate!\n", 
           result_attr2 == 1 ? card1.name : card2.name);

    // Calcula e compara as somas
    float sum1 = c1_attr1 + c1_attr2;
    float sum2 = c2_attr1 + c2_attr2;

    printf("\nSoma dos atributos:\n");
    printf("%s: %.2f\n", card1.name, sum1);
    printf("%s: %.2f\n", card2.name, sum2);

    if(sum1 > sum2) {
        printf("\n%s venceu a rodada!\n", card1.name);
    } else if(sum2 > sum1) {
        printf("\n%s venceu a rodada!\n", card2.name);
    } else {
        printf("\nEmpate!\n");
    }

    return 0;
}