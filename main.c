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

void inserir_usuario(){
    printf("\nNome do motorista: ");
    scanf(" %[^\n]", nome);

    printf("Placa do viculo: ");
    scanf("%s", placa);

    printf("Tipos de usuario\n1 - Visitante\n2 - Mensalista\n3 - Premium\nDitige: ");
    scanf("%d", &tipo_usuario);

    if (tipo_usuario < 1 || tipo_usuario > 3){
        printf("Tipo usuario invalido!\nDefinido como Visitante\n");
        tipo_usuario = 1;
    }

    sessao_iniciada = 1;
    printf("Dados inseridos com sucesso!\n");
}

int main() {
    int opcao;

    printf("=========================\n");
    printf("===  SISTEMA SPRINT   ===\n");
    printf("=========================\n");

    while(opcao != 5){
        printf("\n1 - INSERIR INFORMACOES DO USUARIO\n2 - INSERIR INFORMACOES DO CARRO\n3 - CALCULA SESSAO\n4 - EXIBE RESULTADO\n5 - SAIR\n\nDigite a opcao desejada: ");

        if (scanf("%d", &opcao) != 1){
            printf("OPCAO INVALIDA\n");
            while(getchar() != '\n')
                continue;
            continue;
        }

        switch(opcao){
            case 1: 
                inserir_usuario();
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