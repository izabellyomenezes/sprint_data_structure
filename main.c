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

    printf("\nTipos de usuario\n1 - Visitante\n2 - Mensalista\n3 - Premium\nDigite: ");
    scanf("%d", &tipo_usuario);

    if (tipo_usuario < 1 || tipo_usuario > 3){
        printf("\nTipo usuario invalido!\nDefinido como Visitante\n");
        tipo_usuario = 1;
    }

    sessao_iniciada = 1;
    printf("\nDados inseridos com sucesso!\n");
}

void inserir_sessao(){
    if (!sessao_iniciada) {
        printf("insira os dados do usuario primeiro\n");
        return;
    }

    printf("Hora de inicio (0 a 23): ");
    scanf("%d", &hr_inicio);

    if (hr_inicio < 0 || hr_inicio > 23) {
        printf("Hora invalida! Definido como 0.\n");
        hr_inicio = 0;
    }

    printf("Duracao de recarga em minutos: ");
    scanf(("%d"), &duracao_min);

    if (duracao_min <= 0){
        printf("Duracao invalida! Definido como 30 minutos\n");
        duracao_min = 30;
    }

    printf("Modo de recarga:\n1 -  7.4 kW (Lento)\n2 - 11.0 kW (Medio)\n3 - 22.0 kW (Rapido)\nDigite:");

    int modo;
    scanf("%d", &modo);

    switch(modo){
        case 1:
            potencia_kw = 7.4;
            break;
        case 2:
            potencia_kw = 11.0;
            break;
        case 3:
            potencia_kw = 22.0;
            break;
        default:
            printf("\nModo invalido! Definido como lento.\n");
            potencia_kw = 7.4;
    }

    printf("\nSessao configurada com sucesso.\n");
}

void calc_sessao(){
    if(!sessao_iniciada){
        printf("\nInsira os dados do usuario primeiro\n");
        return;
    }

    float horas = duracao_min/60.0;
    energia_kwh = potencia_kw * horas;

    if(hr_inicio >= 18 && hr_inicio < 21){
        tarifa = 1.85;
    } else if (hr_inicio >= 22 || hr_inicio < 6){
        tarifa = 0.85;
    } else {
        tarifa = 1.20;
    }

    custo_total = energia_kwh * tarifa;

    if (tipo_usuario == 1){
        custo_total = custo_total + 5.00;
    } else if (tipo_usuario == 3) {
        custo_total = custo_total + 5.00;
        custo_total = custo_total * 0.85;
}
    sessao_calculada = 1;
    printf("\nCalculo realizado com Sucesso!\n");
}

void exibir_resultado(){
    if(!sessao_iniciada){
        printf("\nNenhuma sessao iniciada!\n");
        return;
    }

    if(!sessao_calculada){
        calc_sessao();
    }

    printf("\n===== RESULTADO DA SESSAO =====\nMotorista : %s\nPlaca     : %s\n", placa, nome);
    
    if(tipo_usuario ==1){
        printf("Perfil    : Visitante\n");
    } else if(tipo_usuario ==1){
        printf("Perfil    : Mensalista\n");
    } else{
        printf("Perfil    : Premium\n");
    }

    printf("\n--- Sessao ---\nHora inicio: %02dh\nDuracao    : %d minutos\nPotencia   : %.1f kW\nEnergia    : %.2f kWh\n", hr_inicio, duracao_min, potencia_kw, energia_kwh);

    printf("\n--- Cobranca ---\n");

    if (hr_inicio >= 18 && hr_inicio < 21)
        printf("Periodo    : PONTA\n");
    else if (hr_inicio >= 22 || hr_inicio < 6)
        printf("Periodo    : FORA DE PONTA\n");
    else
        printf("Periodo    : NORMAL\n");

    printf("Tarifa     : R$ %.2f/kWh\n", tarifa);

    if (tipo_usuario == 1)
        printf("Taxa servico: R$ 5.00\n");
    else if (tipo_usuario == 2)
        printf("Taxa servico: ISENTO\n");
    else {
        printf("Taxa servico: R$ 5.00\n");
        printf("Desconto   : 15%%\n");
    }

    printf("TOTAL      : R$ %.2f\n", custo_total);
    printf("===============================\n");
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
            case 2:
                inserir_sessao();
                break;
            case 3:
                calc_sessao();
                break;
            case 4:
                exibir_resultado();
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