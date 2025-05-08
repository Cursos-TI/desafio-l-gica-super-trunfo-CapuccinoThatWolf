#include <stdio.h>

int main() {
    // Variáveis para a primeira carta
    char estado1[3]; // 2 caracteres para a sigla do eestado (ex: SP)
    char codigo1[4]; // 3 caracteres para o código (ex: A01) + 1 para o caractere nulo '\0'
    char cidade1[50]; // não utilizar nnomes com acento!
    int populacao1;
    float area1;
    float pib1;
    int pontos_turisticos1;
    float densidadepop1;
    float pibpercapta1;
    float super_poder1;
    
    // Variáveis para a segunda carta
    char estado2[3];
    char codigo2[4];
    char cidade2[50];
    int populacao2;
    float area2;
    float pib2;
    int pontos_turisticos2;
    float densidadepop2;
    float pibpercapta2;
    float super_poder2;

    // Leitura dos dados da primeira carta
    printf("Digite os dados da primeira carta:\n");

    printf("Estado (Sigla): ");
    scanf("%2s", estado1);

    printf("Código da Carta (ex: A01): ");
    scanf("%3s", codigo1);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade1); // Lê uma linha inteira, incluindo espaços

    printf("População: ");
    scanf("%d", &populacao1);

    printf("Área (em km²): ");
    scanf("%f", &area1);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib1);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos1);

    // Cálculos para a primeira carta
    densidadepop1 = populacao1 / area1;
    pibpercapta1 = (pib1 * 1000000000) / populacao1;
    super_poder1 = populacao1 + area1 + pib1 + pontos_turisticos1 + pibpercapta1 + (1/densidadepop1);

    // Leitura dos dados da segunda carta
    printf("\nDigite os dados da segunda carta:\n");

    printf("Estado (Sigla): ");
    scanf("%2s", estado2);

    printf("Código da Carta (ex: B02): ");
    scanf("%3s", codigo2);

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade2);

    printf("População: ");
    scanf("%d", &populacao2);

    printf("Área (em km²): ");
    scanf("%f", &area2);

    printf("PIB (em bilhões de reais): ");
    scanf("%f", &pib2);

    printf("Número de Pontos Turísticos: ");
    scanf("%d", &pontos_turisticos2);

    // Cálculos para a segunda carta
    densidadepop2 = populacao2 / area2;
    pibpercapta2 = (pib2 * 1000000000) / populacao2;
    super_poder2 = populacao2 + area2 + pib2 + pontos_turisticos2 + pibpercapta2 + (1/densidadepop2);

    // Exibição dos dados da primeira carta
    printf("\nCarta 1:\n");
    printf("Estado: %s\n", estado1);
    printf("Código: %s\n", codigo1);
    printf("Nome da Cidade: %s\n", cidade1);
    printf("População: %d\n", populacao1);
    printf("Área: %.2f km²\n", area1);
    printf("PIB: %.2f bilhões de reais\n", pib1);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos1);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadepop1);
    printf("PIB Per Capita: %.2f reais\n", pibpercapta1);
    printf("Super Poder: %.2f\n", super_poder1);


    // Exibição dos dados da segunda carta
    printf("\nCarta 2:\n");
    printf("Estado: %s\n", estado2);
    printf("Código: %s\n", codigo2);
    printf("Nome da Cidade: %s\n", cidade2);
    printf("População: %d\n", populacao2);
    printf("Área: %.2f km²\n", area2);
    printf("PIB: %.2f bilhões de reais\n", pib2);
    printf("Número de Pontos Turísticos: %d\n", pontos_turisticos2);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadepop2);
    printf("PIB Per Capita: %.2f reais\n", pibpercapta2);
    printf("Super Poder: %.2f\n", super_poder2);

    // Comparações entre as cartas
    printf("\n----Comparação de atributos----\n");

    //Atributo População:
    printf("*População*\n");
    if(populacao1 > populacao2){
        printf("Carta 1 - %s (%s): %d\n", cidade1, estado1, populacao1);
        printf("Carta 2 - %s (%s): %d\n", cidade2, estado2, populacao2);
        printf("Carta 1 - %s (%s) Venceu!\n", cidade1, estado1);
    } else{
        printf("Carta 1 - %s (%s): %d\n", cidade1, estado1, populacao1);
        printf("Carta 2 - %s (%s): %d\n", cidade2, estado2, populacao2);
        printf("Carta 2 - %s (%s) Venceu!\n", cidade2, estado2);
    }

}
