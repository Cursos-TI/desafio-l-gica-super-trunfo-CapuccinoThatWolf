#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Função para limpar o buffer de entrada
void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para exibir os dados de uma carta
void exibirCarta(char estado[], char codigo[], char cidade[], int populacao, float area, 
                float pib, int pontos_turisticos, float densidadepop, float pibpercapta, 
                float super_poder) {
    printf("\n--- Dados da Carta ---\n");
    printf("Estado: %s\n", estado);
    printf("Código: %s\n", codigo);
    printf("Cidade: %s\n", cidade);
    printf("População: %d habitantes\n", populacao);
    printf("Área: %.2f km²\n", area);
    printf("PIB: %.2f bilhões de reais\n", pib);
    printf("Pontos Turísticos: %d\n", pontos_turisticos);
    printf("Densidade Populacional: %.2f hab/km²\n", densidadepop);
    printf("PIB per capita: R$ %.2f\n", pibpercapta);
    printf("Super Poder: %.2f\n", super_poder);
}

int main() {
    // Variáveis para a primeira carta
    char estado1[3];
    char codigo1[4];
    char cidade1[50];
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
    printf("=== Cadastro da Primeira Carta ===\n");

    printf("Estado (Sigla): ");
    scanf("%2s", estado1);
    limparBuffer();

    printf("Código da Carta (ex: A01): ");
    scanf("%3s", codigo1);
    limparBuffer();

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade1);
    limparBuffer();

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
    printf("\n=== Cadastro da Segunda Carta ===\n");

    printf("Estado (Sigla): ");
    scanf("%2s", estado2);
    limparBuffer();

    printf("Código da Carta (ex: B02): ");
    scanf("%3s", codigo2);
    limparBuffer();

    printf("Nome da Cidade: ");
    scanf(" %[^\n]", cidade2);
    limparBuffer();

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

    // Exibição resumida das cartas
    printf("\n=== Cartas Cadastradas ===\n");
    printf("Carta 1: %s (%s) - Código: %s\n", cidade1, estado1, codigo1);
    printf("Carta 2: %s (%s) - Código: %s\n", cidade2, estado2, codigo2);

    // Menu interativo
    int opcao;
    do {
        printf("\n=== MENU DE COMPARAÇÃO ===\n");
        printf("1. Comparar por População\n");
        printf("2. Comparar por Área\n");
        printf("3. Comparar por PIB\n");
        printf("4. Comparar por Pontos Turísticos\n");
        printf("5. Comparar por Densidade Populacional\n");
        printf("6. Comparar por PIB per capita\n");
        printf("7. Comparar por Super Poder\n");
        printf("8. Exibir dados completos das cartas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: // População
                printf("\n=== Comparação por População ===\n");
                printf("%s (%s): %d habitantes\n", cidade1, estado1, populacao1);
                printf("%s (%s): %d habitantes\n", cidade2, estado2, populacao2);
                
                if(populacao1 > populacao2) {
                    printf("Vencedor: %s (%s)\n", cidade1, estado1);
                } else if(populacao2 > populacao1) {
                    printf("Vencedor: %s (%s)\n", cidade2, estado2);
                } else {
                    printf("Empate!\n");
                }
                break;
                
            case 2: // Área
                printf("\n=== Comparação por Área ===\n");
                printf("%s (%s): %.2f km²\n", cidade1, estado1, area1);
                printf("%s (%s): %.2f km²\n", cidade2, estado2, area2);
                
                if(area1 > area2) {
                    printf("Vencedor: %s (%s)\n", cidade1, estado1);
                } else if(area2 > area1) {
                    printf("Vencedor: %s (%s)\n", cidade2, estado2);
                } else {
                    printf("Empate!\n");
                }
                break;
                
            case 3: // PIB
                printf("\n=== Comparação por PIB ===\n");
                printf("%s (%s): %.2f bilhões de reais\n", cidade1, estado1, pib1);
                printf("%s (%s): %.2f bilhões de reais\n", cidade2, estado2, pib2);
                
                if(pib1 > pib2) {
                    printf("Vencedor: %s (%s)\n", cidade1, estado1);
                } else if(pib2 > pib1) {
                    printf("Vencedor: %s (%s)\n", cidade2, estado2);
                } else {
                    printf("Empate!\n");
                }
                break;
                
            case 4: // Pontos Turísticos
                printf("\n=== Comparação por Pontos Turísticos ===\n");
                printf("%s (%s): %d pontos\n", cidade1, estado1, pontos_turisticos1);
                printf("%s (%s): %d pontos\n", cidade2, estado2, pontos_turisticos2);
                
                if(pontos_turisticos1 > pontos_turisticos2) {
                    printf("Vencedor: %s (%s)\n", cidade1, estado1);
                } else if(pontos_turisticos2 > pontos_turisticos1) {
                    printf("Vencedor: %s (%s)\n", cidade2, estado2);
                } else {
                    printf("Empate!\n");
                }
                break;
                
            case 5: // Densidade Populacional (quanto menor, melhor)
                printf("\n=== Comparação por Densidade Populacional ===\n");
                printf("%s (%s): %.2f hab/km²\n", cidade1, estado1, densidadepop1);
                printf("%s (%s): %.2f hab/km²\n", cidade2, estado2, densidadepop2);
                
                if(densidadepop1 < densidadepop2) {
                    printf("Vencedor: %s (%s)\n", cidade1, estado1);
                } else if(densidadepop2 < densidadepop1) {
                    printf("Vencedor: %s (%s)\n", cidade2, estado2);
                } else {
                    printf("Empate!\n");
                }
                break;
                
            case 6: // PIB per capita
                printf("\n=== Comparação por PIB per capita ===\n");
                printf("%s (%s): R$ %.2f\n", cidade1, estado1, pibpercapta1);
                printf("%s (%s): R$ %.2f\n", cidade2, estado2, pibpercapta2);
                
                if(pibpercapta1 > pibpercapta2) {
                    printf("Vencedor: %s (%s)\n", cidade1, estado1);
                } else if(pibpercapta2 > pibpercapta1) {
                    printf("Vencedor: %s (%s)\n", cidade2, estado2);
                } else {
                    printf("Empate!\n");
                }
                break;
                
            case 7: // Super Poder
                printf("\n=== Comparação por Super Poder ===\n");
                printf("%s (%s): %.2f\n", cidade1, estado1, super_poder1);
                printf("%s (%s): %.2f\n", cidade2, estado2, super_poder2);
                
                if(super_poder1 > super_poder2) {
                    printf("Vencedor: %s (%s)\n", cidade1, estado1);
                } else if(super_poder2 > super_poder1) {
                    printf("Vencedor: %s (%s)\n", cidade2, estado2);
                } else {
                    printf("Empate!\n");
                }
                break;
                
            case 8: // Exibir dados completos
                printf("\n=== Dados Completos ===\n");
                printf("\n--- Carta 1 ---\n");
                exibirCarta(estado1, codigo1, cidade1, populacao1, area1, pib1, 
                           pontos_turisticos1, densidadepop1, pibpercapta1, super_poder1);
                
                printf("\n--- Carta 2 ---\n");
                exibirCarta(estado2, codigo2, cidade2, populacao2, area2, pib2, 
                           pontos_turisticos2, densidadepop2, pibpercapta2, super_poder2);
                break;
                
            case 0: // Sair
                printf("Encerrando o programa...\n");
                break;
                
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while(opcao != 0);

    return 0;
}
