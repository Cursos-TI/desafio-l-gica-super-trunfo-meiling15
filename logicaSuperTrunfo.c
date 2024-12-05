#include <stdio.h>
#include <string.h>

// Estrutura da carta - informações dos países
typedef struct {
    char estado[25]; // Nome do estado
    char codigo[4]; // Código da carta (exemplo: A01, B02)
    int populacao; // População do país
    float area; // Área do país em km²
    float pib; // PIB do país
    int pontos_turisticos; // Número de pontos turísticos do país
    float densidade_populacional; // Densidade populacional (população / área)
    float pib_per_capita; // PIB per capita (PIB / população)
} carta;

// Função para cadastrar a carta
void cadatrarcarta(carta* c) {
    // Solicitar nome do país
    printf("\nDigite o nome do Estado (maximo 20 caracteres): ");
    scanf(" %[^\n]s", c->estado); // Permite ler espaços no nome do país

    // Solicitar código da carta (exemplo: A01, B02)
    do {
        printf("Digite o codigo da carta (letra do estado seguida de numero 01 a 04, exemplo: A01, B02): ");
        scanf("%3s", c->codigo);
        // Validar o formato do código
        if (strlen(c->codigo) != 3 || c->codigo[1] < '0' || c->codigo[1] > '9' || c->codigo[2] < '1' || c->codigo[2] > '4') {
            printf("Codigo invalido. Digite novamente (exemplo: A01, B02,...)\n");
        }
    } while (strlen(c->codigo) != 3 || c->codigo[1] < '0' || c->codigo[1] > '9' || c->codigo[2] < '1' || c->codigo[2] > '4');

    // Solicitar população (validar se é um número positivo)
    do {
        printf("Digite a populaçao: ");
        scanf("%d", &c->populacao);
        if (c->populacao < 0) {
            printf("Populaçao invalida. Digite um numero positivo.\n");
        }
    } while (c->populacao < 0);

    // Solicitar área em km²
    do {
        printf("Digite o tamanho da area em km²: ");
        scanf("%f", &c->area);
        if (c->area <= 0) {
            printf("Area inválida. A area deve ser um valor positivo.\n");
        }
    } while (c->area <= 0);

    // Solicitar PIB (validar se é um número positivo)
    do {
        printf("Digite o valor do PIB do pais: ");
        scanf("%f", &c->pib);
        if (c->pib < 0) {
            printf("PIB invalido. Digite um numero positivo.\n");
        }
    } while (c->pib < 0);

    // Solicitar pontos turísticos (validar se é um número não negativo)
    do {
        printf("Digite a quantidade de pontos turisticos: ");
        scanf("%d", &c->pontos_turisticos);
        if (c->pontos_turisticos < 0) {
            printf("Numero de pontos turisticos invalido. Digite um numero nao negativo.\n");
        }
    } while (c->pontos_turisticos < 0);

    // Calcular a densidade populacional (população / área)
    c->densidade_populacional = c->populacao / c->area;

    // Calcular o PIB per capita (PIB / população)
    c->pib_per_capita = c->pib / c->populacao;

    // Exibir os dados cadastrados
    printf("\nCarta cadastrada com sucesso!\n");
    printf("Estado: %s\n", c->estado);
    printf("Codigo da carta: %s\n", c->codigo);
    printf("Populaçao: %d habitantes\n", c->populacao);
    printf("Area: %.3f km²\n", c->area);
    printf("PIB: R$ %.2f reais\n", c->pib);
    printf("Pontos turisticos: %d\n", c->pontos_turisticos);
    printf("Densidade populacional: %.2f habitantes por km²\n", c->densidade_populacional);
    printf("PIB per capita: R$ %.2f por habitante\n", c->pib_per_capita);
}

// Função para comparar atributos
void comparar_atributos(carta c1, carta c2) {
    int opcao1, opcao2;
    
    // Menu para escolher atributos
    printf("\nEscolha o primeiro atributo para comparação:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos turísticos\n");
    printf("5. Densidade populacional\n");
    scanf("%d", &opcao1);

    printf("Escolha o segundo atributo para comparação:\n");
    printf("1. População\n");
    printf("2. Área\n");
    printf("3. PIB\n");
    printf("4. Pontos turísticos\n");
    printf("5. Densidade populacional\n");
    scanf("%d", &opcao2);

    // Comparando os atributos escolhidos
    switch (opcao1) {
        case 1: // População
            switch (opcao2) {
                case 1: // População vs População
                    printf("Empate! Ambos têm a mesma população.\n");
                    break;
                case 2: // População vs Área
                    printf("%s vence! População: %d vs Área: %.3f km²\n", c1.populacao > c2.populacao ? c1.estado : c2.estado, c1.populacao, c2.populacao);
                    break;
                case 3: // População vs PIB
                    printf("%s vence! População: %d vs PIB: %.2f\n", c1.populacao > c2.populacao ? c1.estado : c2.estado, c1.populacao, c2.pib);
                    break;
                case 4: // População vs Pontos turísticos
                    printf("%s vence! População: %d vs Pontos turísticos: %d\n", c1.populacao > c2.populacao ? c1.estado : c2.estado, c1.populacao, c2.pontos_turisticos);
                    break;
                case 5: // População vs Densidade populacional
                    printf("%s vence! População: %d vs Densidade populacional: %.2f\n", c1.populacao > c2.populacao ? c1.estado : c2.estado, c1.populacao, c2.densidade_populacional);
                    break;
            }
            break;
        case 2: // Área
            // Adicionar lógica similar para cada combinação de comparação
            break;
        // Continuar as opções restantes
    }
}

// Função principal
int main() {
    int num_cartas;
    
    // Perguntar ao usuário quantas cartas deseja cadastrar
    printf("Bem-vindo ao jogo Super Trunfo\n");
    printf("Quantas cartas voce deseja cadastrar? ");
    scanf("%d", &num_cartas);
    
    // Verificar se o número de cartas é válido
    if (num_cartas <= 0 || num_cartas > 32) {
        printf("Numero invalido. Digite um valor entre 1 e 32.\n");
        return 1;
    }

    carta cartas[num_cartas]; // Criação do vetor de cartas com o número definido pelo usuário
    int i;

    // Cadastro das cartas
    for (i = 0; i < num_cartas; i++) {
        printf("\nCadastro da carta %d:\n", i + 1);
        cadatrarcarta(&cartas[i]);
    }

    printf("\nTodas as cartas foram cadastradas com sucesso!\n");

    // Comparação de cartas
    printf("\nEscolha as cartas para comparação:\n");
    int carta1, carta2;
    printf("Digite o número da primeira carta (1 a %d): ", num_cartas);
    scanf("%d", &carta1);
    printf("Digite o número da segunda carta (1 a %d): ", num_cartas);
    scanf("%d", &carta2);
    
    // Chamando função para comparar os atributos
    comparar_atributos(cartas[carta1 - 1], cartas[carta2 - 1]);

    return 0;
}
