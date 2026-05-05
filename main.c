#include <stdio.h>

char nome[50];
char placa[7];
int tipo_usuario;

int hr_inicio;
int duracao_min;
float potencia_kw;
float energia_kwh;
float tarifa;
float custo_total;
int sessao_iniciada = 0;
int sessao_calculada = 0;

int main() {
    int opcao;

    printf("\n========================= \n");
    printf("= SISTEMA SPRINT 1 =\n");
    printf("=========================\n");

    while(opcao != 5){
        printf("1 - INSERIR INFORMACOES DO USUARIO\n2 - INSERIR INFORMACOES DO CARRO\n3 - CALCULA SESSAO\n4 - EXIBE RESULTADO\n5 - SAIR\nDigite a opcao desejada: ");

        if (scanf("%d", &opcao) != 1){
            printf("OPCAO INVALIDA\n");
            while(getchar() != '\n')
                continue;
            continue;
        }

        switch(opcao){
            case 1: //Adiciona informacoes sobre usuario
                break;
            case 2: //Adiciona informacoes sobre o carro
                break;
            case 3: //Calcula sessao
                break;
            case 4: //Exibe resultado
                break;
            case 5:
                printf("FINALIZANDO...\n");
                break;
            default:
                printf("OPCAO INVALIDA\n");
        }
    }
    return 0;
}