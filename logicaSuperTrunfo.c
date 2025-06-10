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

// Função para exibir o menu de atributos, ocultando a opção já selecionada
void exibirMenuAtributos(int atributoExcluido) {
    printf("\nEscolha um atributo para comparação:\n");
    if (atributoExcluido != 1) printf("1. População\n");
    if (atributoExcluido != 2) printf("2. Área\n");
    if (atributoExcluido != 3) printf("3. PIB\n");
    if (atributoExcluido != 4) printf("4. Pontos Turísticos\n");
    if (atributoExcluido != 5) printf("5. Densidade Populacional\n");
    if (atributoExcluido != 6) printf("6. PIB per capita\n");
    if (atributoExcluido != 7) printf("7. Super Poder\n");
    printf("0. Voltar\n");
    printf("Escolha uma opção: ");
}

int main() {
    // Variáveis para a primeira carta
    char estado1[3] = "SP";
    char codigo1[4] = "A01";
    char cidade1[50] = "São Paulo";
    int populacao1 = 12325232;
    float area1 = 1521.11;
    float pib1 = 714.0;
    int pontos_turisticos1 = 150;
    float densidadepop1 = populacao1 / area1;
    float pibpercapta1 = (pib1 * 1000000000) / populacao1;
    float super_poder1 = populacao1 + area1 + pib1 + pontos_turisticos1 + pibpercapta1 + (1/densidadepop1);
    
    // Variáveis para a segunda carta
    char estado2[3] = "RJ";
    char codigo2[4] = "B02";
    char cidade2[50] = "Rio de Janeiro";
    int populacao2 = 6747815;
    float area2 = 1200.27;
    float pib2 = 338.0;
    int pontos_turisticos2 = 200;
    float densidadepop2 = populacao2 / area2;
    float pibpercapta2 = (pib2 * 1000000000) / populacao2;
    float super_poder2 = populacao2 + area2 + pib2 + pontos_turisticos2 + pibpercapta2 + (1/densidadepop2);

    // Exibição resumida das cartas
    printf("=== Cartas Cadastradas ===\n");
    printf("Carta 1: %s (%s) - Código: %s\n", cidade1, estado1, codigo1);
    printf("Carta 2: %s (%s) - Código: %s\n", cidade2, estado2, codigo2);

    // Menu principal
    int opcao;
    do {
        printf("\n=== MENU PRINCIPAL ===\n");
        printf("1. Comparar por um atributo\n");
        printf("2. Comparar por dois atributos\n");
        printf("3. Exibir dados completos das cartas\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: { // Comparação por um atributo
                int atributo;
                do {
                    printf("\n=== Comparação por Um Atributo ===\n");
                    printf("1. População\n");
                    printf("2. Área\n");
                    printf("3. PIB\n");
                    printf("4. Pontos Turísticos\n");
                    printf("5. Densidade Populacional\n");
                    printf("6. PIB per capita\n");
                    printf("7. Super Poder\n");
                    printf("0. Voltar\n");
                    printf("Escolha um atributo: ");
                    scanf("%d", &atributo);

                    if (atributo == 0) break;

                    printf("\n=== Resultado da Comparação ===\n");
                    printf("%s (%s) vs %s (%s)\n", cidade1, estado1, cidade2, estado2);

                    switch(atributo) {
                        case 1: // População
                            printf("Atributo: População\n");
                            printf("%s: %d habitantes\n", cidade1, populacao1);
                            printf("%s: %d habitantes\n", cidade2, populacao2);
                            
                            if(populacao1 > populacao2) {
                                printf("Vencedor: %s (%s)\n", cidade1, estado1);
                            } else if(populacao2 > populacao1) {
                                printf("Vencedor: %s (%s)\n", cidade2, estado2);
                            } else {
                                printf("Empate!\n");
                            }
                            break;
                            
                        case 2: // Área
                            printf("Atributo: Área\n");
                            printf("%s: %.2f km²\n", cidade1, area1);
                            printf("%s: %.2f km²\n", cidade2, area2);
                            
                            if(area1 > area2) {
                                printf("Vencedor: %s (%s)\n", cidade1, estado1);
                            } else if(area2 > area1) {
                                printf("Vencedor: %s (%s)\n", cidade2, estado2);
                            } else {
                                printf("Empate!\n");
                            }
                            break;
                            
                        case 3: // PIB
                            printf("Atributo: PIB\n");
                            printf("%s: %.2f bilhões de reais\n", cidade1, pib1);
                            printf("%s: %.2f bilhões de reais\n", cidade2, pib2);
                            
                            if(pib1 > pib2) {
                                printf("Vencedor: %s (%s)\n", cidade1, estado1);
                            } else if(pib2 > pib1) {
                                printf("Vencedor: %s (%s)\n", cidade2, estado2);
                            } else {
                                printf("Empate!\n");
                            }
                            break;
                            
                        case 4: // Pontos Turísticos
                            printf("Atributo: Pontos Turísticos\n");
                            printf("%s: %d pontos\n", cidade1, pontos_turisticos1);
                            printf("%s: %d pontos\n", cidade2, pontos_turisticos2);
                            
                            if(pontos_turisticos1 > pontos_turisticos2) {
                                printf("Vencedor: %s (%s)\n", cidade1, estado1);
                            } else if(pontos_turisticos2 > pontos_turisticos1) {
                                printf("Vencedor: %s (%s)\n", cidade2, estado2);
                            } else {
                                printf("Empate!\n");
                            }
                            break;
                            
                        case 5: // Densidade Populacional (quanto menor, melhor)
                            printf("Atributo: Densidade Populacional\n");
                            printf("%s: %.2f hab/km²\n", cidade1, densidadepop1);
                            printf("%s: %.2f hab/km²\n", cidade2, densidadepop2);
                            
                            if(densidadepop1 < densidadepop2) {
                                printf("Vencedor: %s (%s)\n", cidade1, estado1);
                            } else if(densidadepop2 < densidadepop1) {
                                printf("Vencedor: %s (%s)\n", cidade2, estado2);
                            } else {
                                printf("Empate!\n");
                            }
                            break;
                            
                        case 6: // PIB per capita
                            printf("Atributo: PIB per capita\n");
                            printf("%s: R$ %.2f\n", cidade1, pibpercapta1);
                            printf("%s: R$ %.2f\n", cidade2, pibpercapta2);
                            
                            if(pibpercapta1 > pibpercapta2) {
                                printf("Vencedor: %s (%s)\n", cidade1, estado1);
                            } else if(pibpercapta2 > pibpercapta1) {
                                printf("Vencedor: %s (%s)\n", cidade2, estado2);
                            } else {
                                printf("Empate!\n");
                            }
                            break;
                            
                        case 7: // Super Poder
                            printf("Atributo: Super Poder\n");
                            printf("%s: %.2f\n", cidade1, super_poder1);
                            printf("%s: %.2f\n", cidade2, super_poder2);
                            
                            if(super_poder1 > super_poder2) {
                                printf("Vencedor: %s (%s)\n", cidade1, estado1);
                            } else if(super_poder2 > super_poder1) {
                                printf("Vencedor: %s (%s)\n", cidade2, estado2);
                            } else {
                                printf("Empate!\n");
                            }
                            break;
                            
                        default:
                            printf("Opção inválida! Tente novamente.\n");
                    }
                } while (atributo != 0);
                break;
            }
                
            case 2: { // Comparação por dois atributos
                int atributo1, atributo2;
                float valor1_carta1, valor1_carta2, valor2_carta1, valor2_carta2;
                char nome_atributo1[30], nome_atributo2[30];
                
                // Seleção do primeiro atributo
                printf("\n=== Comparação por Dois Atributos ===\n");
                printf("Selecione o primeiro atributo:\n");
                exibirMenuAtributos(0);
                scanf("%d", &atributo1);
                
                if (atributo1 == 0) break;
                
                // Seleção do segundo atributo (diferente do primeiro)
                printf("\nSelecione o segundo atributo (diferente do primeiro):\n");
                exibirMenuAtributos(atributo1);
                scanf("%d", &atributo2);
                
                if (atributo2 == 0 || atributo2 == atributo1) {
                    printf("Atributo inválido ou igual ao primeiro. Operação cancelada.\n");
                    break;
                }
                
                // Determinar valores dos atributos para cada carta
                // Atributo 1
                switch(atributo1) {
                    case 1:
                        valor1_carta1 = populacao1;
                        valor1_carta2 = populacao2;
                        strcpy(nome_atributo1, "População");
                        break;
                    case 2:
                        valor1_carta1 = area1;
                        valor1_carta2 = area2;
                        strcpy(nome_atributo1, "Área");
                        break;
                    case 3:
                        valor1_carta1 = pib1;
                        valor1_carta2 = pib2;
                        strcpy(nome_atributo1, "PIB");
                        break;
                    case 4:
                        valor1_carta1 = pontos_turisticos1;
                        valor1_carta2 = pontos_turisticos2;
                        strcpy(nome_atributo1, "Pontos Turísticos");
                        break;
                    case 5:
                        valor1_carta1 = densidadepop1;
                        valor1_carta2 = densidadepop2;
                        strcpy(nome_atributo1, "Densidade Populacional");
                        break;
                    case 6:
                        valor1_carta1 = pibpercapta1;
                        valor1_carta2 = pibpercapta2;
                        strcpy(nome_atributo1, "PIB per capita");
                        break;
                    case 7:
                        valor1_carta1 = super_poder1;
                        valor1_carta2 = super_poder2;
                        strcpy(nome_atributo1, "Super Poder");
                        break;
                }
                
                // Atributo 2
                switch(atributo2) {
                    case 1:
                        valor2_carta1 = populacao1;
                        valor2_carta2 = populacao2;
                        strcpy(nome_atributo2, "População");
                        break;
                    case 2:
                        valor2_carta1 = area1;
                        valor2_carta2 = area2;
                        strcpy(nome_atributo2, "Área");
                        break;
                    case 3:
                        valor2_carta1 = pib1;
                        valor2_carta2 = pib2;
                        strcpy(nome_atributo2, "PIB");
                        break;
                    case 4:
                        valor2_carta1 = pontos_turisticos1;
                        valor2_carta2 = pontos_turisticos2;
                        strcpy(nome_atributo2, "Pontos Turísticos");
                        break;
                    case 5:
                        valor2_carta1 = densidadepop1;
                        valor2_carta2 = densidadepop2;
                        strcpy(nome_atributo2, "Densidade Populacional");
                        break;
                    case 6:
                        valor2_carta1 = pibpercapta1;
                        valor2_carta2 = pibpercapta2;
                        strcpy(nome_atributo2, "PIB per capita");
                        break;
                    case 7:
                        valor2_carta1 = super_poder1;
                        valor2_carta2 = super_poder2;
                        strcpy(nome_atributo2, "Super Poder");
                        break;
                }
                
                // Exibir comparação
                printf("\n=== Resultado da Comparação ===\n");
                printf("%s (%s) vs %s (%s)\n", cidade1, estado1, cidade2, estado2);
                printf("\nAtributos selecionados:\n");
                printf("1. %s\n", nome_atributo1);
                printf("2. %s\n", nome_atributo2);
                
                // Comparação do primeiro atributo
                printf("\nComparação por %s:\n", nome_atributo1);
                if (atributo1 == 5) { // Densidade Populacional (quanto menor, melhor)
                    printf("%s: %.2f hab/km²\n", cidade1, valor1_carta1);
                    printf("%s: %.2f hab/km²\n", cidade2, valor1_carta2);
                    
                    if(valor1_carta1 < valor1_carta2) {
                        printf("Vencedor: %s (%s)\n", cidade1, estado1);
                    } else if(valor1_carta2 < valor1_carta1) {
                        printf("Vencedor: %s (%s)\n", cidade2, estado2);
                    } else {
                        printf("Empate!\n");
                    }
                } else { // Demais atributos (quanto maior, melhor)
                    if (atributo1 == 1) {
                        printf("%s: %d habitantes\n", cidade1, (int)valor1_carta1);
                        printf("%s: %d habitantes\n", cidade2, (int)valor1_carta2);
                    } else if (atributo1 == 4) {
                        printf("%s: %d pontos\n", cidade1, (int)valor1_carta1);
                        printf("%s: %d pontos\n", cidade2, (int)valor1_carta2);
                    } else {
                        printf("%s: %.2f\n", cidade1, valor1_carta1);
                        printf("%s: %.2f\n", cidade2, valor1_carta2);
                    }
                    
                    if(valor1_carta1 > valor1_carta2) {
                        printf("Vencedor: %s (%s)\n", cidade1, estado1);
                    } else if(valor1_carta2 > valor1_carta1) {
                        printf("Vencedor: %s (%s)\n", cidade2, estado2);
                    } else {
                        printf("Empate!\n");
                    }
                }
                
                // Comparação do segundo atributo
                printf("\nComparação por %s:\n", nome_atributo2);
                if (atributo2 == 5) { // Densidade Populacional (quanto menor, melhor)
                    printf("%s: %.2f hab/km²\n", cidade1, valor2_carta1);
                    printf("%s: %.2f hab/km²\n", cidade2, valor2_carta2);
                    
                    if(valor2_carta1 < valor2_carta2) {
                        printf("Vencedor: %s (%s)\n", cidade1, estado1);
                    } else if(valor2_carta2 < valor2_carta1) {
                        printf("Vencedor: %s (%s)\n", cidade2, estado2);
                    } else {
                        printf("Empate!\n");
                    }
                } else { // Demais atributos (quanto maior, melhor)
                    if (atributo2 == 1) {
                        printf("%s: %d habitantes\n", cidade1, (int)valor2_carta1);
                        printf("%s: %d habitantes\n", cidade2, (int)valor2_carta2);
                    } else if (atributo2 == 4) {
                        printf("%s: %d pontos\n", cidade1, (int)valor2_carta1);
                        printf("%s: %d pontos\n", cidade2, (int)valor2_carta2);
                    } else {
                        printf("%s: %.2f\n", cidade1, valor2_carta1);
                        printf("%s: %.2f\n", cidade2, valor2_carta2);
                    }
                    
                    if(valor2_carta1 > valor2_carta2) {
                        printf("Vencedor: %s (%s)\n", cidade1, estado1);
                    } else if(valor2_carta2 > valor2_carta1) {
                        printf("Vencedor: %s (%s)\n", cidade2, estado2);
                    } else {
                        printf("Empate!\n");
                    }
                }
                
                // Soma dos atributos (ajustando para densidade populacional)
                float soma_carta1 = (atributo1 == 5 ? 1/valor1_carta1 : valor1_carta1) + 
                                   (atributo2 == 5 ? 1/valor2_carta1 : valor2_carta1);
                float soma_carta2 = (atributo1 == 5 ? 1/valor1_carta2 : valor1_carta2) + 
                                   (atributo2 == 5 ? 1/valor2_carta2 : valor2_carta2);
                
                printf("\nSoma dos atributos (ajustados):\n");
                printf("%s: %.2f\n", cidade1, soma_carta1);
                printf("%s: %.2f\n", cidade2, soma_carta2);
                
                if(soma_carta1 > soma_carta2) {
                    printf("\nVencedor geral: %s (%s)\n", cidade1, estado1);
                } else if(soma_carta2 > soma_carta1) {
                    printf("\nVencedor geral: %s (%s)\n", cidade2, estado2);
                } else {
                    printf("\nEmpate geral!\n");
                }
                break;
            }
                
            case 3: // Exibir dados completos
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
