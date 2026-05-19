#include <stdio.h>
#include <string.h>

#define TAXA_VISITANTE 5.00f
#define TAXA_PREMIUM 5.00f
#define DESC_PREMIUM 0.85f

char nome[50];
char placa[8];
int  tipo_usuario;
int hr_inicio;
int duracao_min;
float potencia_kw;
float energia_kwh;
float tarifa;
float custo_total;
int sessao_iniciada = 0;
int sessao_configurada = 0;

void limpar_buffer() {
    while (getchar() != '\n')
        continue;
}

void inserir_usuario() {
    printf("\nNome do motorista: ");
    scanf(" %49[^\n]", nome);

    do {
        printf("Placa do veiculo (7 caracteres): ");
        scanf(" %49s", placa);
        limpar_buffer();

        if (strlen(placa) != 7)
            printf("\nPlaca invalida! Digite exatamente 7 caracteres. Tente novamente.\n");

    } while (strlen(placa) != 7);

    do {
        printf("\nTipos de usuario\n"
               "  1 - Visitante\n"
               "  2 - Mensalista\n"
               "  3 - Premium\n"
               "Digite: ");

        if (scanf("%d", &tipo_usuario) != 1) {
            limpar_buffer();
            tipo_usuario = 0;
        }

        if (tipo_usuario < 1 || tipo_usuario > 3)
            printf("Tipo invalido! Tente novamente.\n");

    } while (tipo_usuario < 1 || tipo_usuario > 3);

    sessao_iniciada    = 1;
    sessao_configurada = 0;
    printf("Dados inseridos com sucesso!\n");
}

void inserir_sessao() {
    if (!sessao_iniciada) {
        printf("Insira os dados do usuario primeiro (opcao 1).\n");
        return;
    }

    do {
        printf("Hora de inicio (0-23): ");
        if (scanf("%d", &hr_inicio) != 1) {
            limpar_buffer();
            hr_inicio = -1;
        }
        if (hr_inicio < 0 || hr_inicio > 23)
            printf("Hora invalida! Tente novamente.\n");

    } while (hr_inicio < 0 || hr_inicio > 23);

    do {
        printf("Duracao da recarga em minutos: ");
        if (scanf("%d", &duracao_min) != 1) {
            limpar_buffer();
            duracao_min = 0;
        }
        if (duracao_min <= 0)
            printf("Duracao invalida! Tente novamente.\n");

    } while (duracao_min <= 0);

    int modo = 0;
    do {
        printf("Modo de recarga:\n"
               "  1 -  7.4 kW (Lento)\n"
               "  2 - 11.0 kW (Medio)\n"
               "  3 - 22.0 kW (Rapido)\n"
               "Digite: ");
        if (scanf("%d", &modo) != 1) {
            limpar_buffer();
            modo = 0;
        }

        switch (modo) {
            case 1: potencia_kw = 7.4f;
            break;

            case 2: potencia_kw = 11.0f;
            break;

            case 3: potencia_kw = 22.0f;
            break;
        
            default: printf("Modo invalido! Tente novamente.\n");
        }
    } while (modo < 1 || modo > 3);

    float horas = duracao_min / 60.0f;
    energia_kwh = potencia_kw * horas;

    if (hr_inicio >= 18 && hr_inicio < 21)
        tarifa = 1.85f;
    else if (hr_inicio >= 22 || hr_inicio < 6)
        tarifa = 0.85f;
    else
        tarifa = 1.20f;

    custo_total = energia_kwh * tarifa;

    if (tipo_usuario == 1) {
        custo_total += TAXA_VISITANTE;
    } else if (tipo_usuario == 3) {
        custo_total = (custo_total * DESC_PREMIUM) + TAXA_PREMIUM;
    }

    sessao_configurada = 1;
    printf("Sessao configurada e calculada com sucesso.\n");
}

void exibir_resultado() {
    if (!sessao_iniciada) {
        printf("Nenhuma sessao iniciada!\n");
        return;
    }
    if (!sessao_configurada) {
        printf("Configure a sessao primeiro (opcao 2).\n");
        return;
    }

    const char *perfil;
    if(tipo_usuario == 1) perfil = "Visitante";
    else if (tipo_usuario == 2) perfil = "Mensalista";
    else perfil = "Premium";

    const char *periodo;
    if (hr_inicio >= 18 && hr_inicio < 21) periodo = "PONTA";
    else if (hr_inicio >= 22 || hr_inicio < 6) periodo = "FORA DE PONTA";
    else periodo = "NORMAL";

    printf("\n===== RESULTADO DA SESSAO =====\n");
    printf("Motorista : %s\n", nome);
    printf("Placa     : %s\n", placa);
    printf("Perfil    : %s\n", perfil);
    
    printf("\n--- Sessao ---\n");
    printf("Hora inicio: %02dh\n", hr_inicio);
    printf("Duracao    : %d minutos\n", duracao_min);
    printf("Potencia   : %.1f kW\n", potencia_kw);
    printf("Energia    : %.2f kWh\n", energia_kwh);

    printf("\n--- Cobranca ---\n");
    printf("Periodo     : %s\n", periodo);
    printf("Tarifa      : R$ %.2f/kWh\n", tarifa);
    if (tipo_usuario == 1)
        printf("Taxa servico: R$ 5.00\n");
    else if (tipo_usuario == 2)
        printf("Taxa servico: ISENTO\n");
    else {
        printf("Desconto    : 15%% (sobre energia)\n");
        printf("Taxa servico: R$ 5.00\n");
    }
    printf("TOTAL       : R$ %.2f\n", custo_total);
    printf("===============================\n");
}

int main() {
    int opcao = 0;

    printf("==========================\n");
    printf("===  SISTEMA SPRINT 1  ===\n");
    printf("==========================\n");

    while (opcao != 4) {
        printf("\n1 - INSERIR INFORMACOES DO USUARIO\n"
               "2 - INSERIR INFORMACOES DA SESSAO\n"
               "3 - EXIBIR RESULTADO\n"
               "4 - SAIR\n"
               "\nDigite a opcao desejada: ");

        if (scanf("%d", &opcao) != 1) {
            limpar_buffer();
            opcao = 0;
            printf("OPCAO INVALIDA\n");
            continue;
        }

        switch (opcao) {
            case 1: inserir_usuario();  
            break;

            case 2: inserir_sessao();   
            break;

            case 3: exibir_resultado(); 
            break;

            case 4: printf("FINALIZANDO...\n"); 
            break;

            default: printf("OPCAO INVALIDA\n");
        }
    }
    return 0;
}