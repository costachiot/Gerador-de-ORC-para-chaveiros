#include <stdio.h>
#include <stdlib.h>

void limpar_tela() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

int main() {
    int fechadura_tipo, fechadura_mais_de_uma, fechadura_quantidade=0, simples=0, dupla=0, tripla=0;
    int horario, hora, valor_horario, minuto;
    int valor=0, taxa_visita = 50;
    int cep, cep_completo, valor_regiao;
    int i;

    valor = valor + taxa_visita;

    printf("\n| ORCAMENTO DE ABERTURA DE PORTA |\n\nDigite\n\n1 - PORTA COM 1 FECHADURA\n2 - PORTA COM MULTIPLAS FECHADURAS\n\nSua resposta: ");
    scanf("%d", &fechadura_mais_de_uma);

    if (fechadura_mais_de_uma == 2){
        limpar_tela();
        printf("\nORCAMENTO PARA ABERTURA DE PORTA COM MULTIPLAS FECHADURAS\n---------------------------------------------------------");
        printf("\n\nQuantas fechaduras a sua porta tem?\n\nSua resposta: ");
        scanf("%d", &fechadura_quantidade);

        if(fechadura_quantidade>1){
            limpar_tela();
            printf("\nORCAMENTO PARA ABERTURA DE PORTA COM %d FECHADURAS\n-------------------------------------------------", fechadura_quantidade);


            for (i=1;i<fechadura_quantidade+1;i++){

                printf("\n\nDigite o tipo da fechadura %d\n\n1 - fechadura SIMPLES\n2 - fechadura DUPLA\n3 - fechadura TRIPLA\n\nSua resposta: ", i);
                scanf("%d", &fechadura_tipo);

                if (fechadura_tipo==1) {
                    valor = valor + 30;
                    simples = simples + 1;
                }
                else if (fechadura_tipo==2) {
                    valor = valor + 45;
                    dupla = dupla + 1;
                }
                else if (fechadura_tipo==3) {
                    valor = valor + 60;
                    tripla = tripla +1;
                }
                else{
                    printf("\n---------------------------------------\nERRO: Opcao invalida. Digite 1, 2 ou 3\n---------------------------------------\n");
                    return 1;
                }
            }
        }
        else if (fechadura_quantidade == 1){
            printf("\n-----------------------------------------------------------------\nERRO: Quantidade invalida. Aceito: MULTIPLAS FECHADURAS. Real: 1\n-----------------------------------------------------------------\n");
                return 1;
        }
        else {
            printf("\n----------------------------------------------------------\nERRO: Quantidade invalida. Digite um valor maior que zero\n----------------------------------------------------------\n");
                return 1;
        }
    }

    else if (fechadura_mais_de_uma == 1){
            limpar_tela();
            printf("\nORCAMENTO PARA ABERTURA DE PORTA COM 1 FECHADURA\n------------------------------------------------");
            printf("\n\nDigite o tipo da fechadura\n\n1 - fechadura SIMPLES\n2 - fechadura DUPLA\n3 - fechadura TRIPLA\n\nSua resposta: ");
            scanf("%d", &fechadura_tipo);

        if (fechadura_tipo==1) {
            valor = valor + 30;
            simples = simples + 1;
        }
        else if (fechadura_tipo==2) {
            valor = valor + 45;
            dupla = dupla + 1;
        }
        else if (fechadura_tipo==3) {
            valor = valor + 60;
            tripla = tripla +1;
        }
        else{
            printf("\n---------------------------------------\nERRO: Opcao invalida. Digite 1, 2 ou 3\n---------------------------------------\n");
            return 1;
        }
    }

    else{
        printf("\n------------------------------------\nERRO: Opcao invalida. Digite 1 ou 2\n------------------------------------\n");
        return 1;
    }
    limpar_tela();

    if(fechadura_mais_de_uma == 1){
        printf("\nORCAMENTO PARA ABERTURA DE PORTA COM 1 FECHADURA\n------------------------------------------------");
    }
    else if (fechadura_mais_de_uma == 2){
        printf("\nORCAMENTO PARA ABERTURA DE PORTA COM %d FECHADURAS\n-------------------------------------------------", fechadura_quantidade);
    }

    printf("\n\nDigite o seu CEP (somente numeros)\n\nCEP: ");
    scanf("%d", &cep_completo);

    cep = cep_completo / 1000;

    if((cep > 94999) && (cep <= 95049)){
        valor = valor + 15;
        valor_regiao = 15;
    }
    else if((cep > 95049) && (cep <= 95099)){
        valor = valor + 20;
        valor_regiao = 20;
    }
    else if((cep > 95099) && (cep <= 95120)){
        valor = valor + 25;
        valor_regiao = 25;
    }
    else if((cep > 95120) && (cep <= 95149)){
        valor = valor + 50;
        valor_regiao = 50;
    }
    else{
        printf("\n--------------------------------------------------------------------\nERRO: CEP fora da area de cobertura. Insira um CEP de Caxias do Sul\n--------------------------------------------------------------------\n");
        return 1;
    }

    limpar_tela();

    if(fechadura_mais_de_uma == 1){
        printf("\nORCAMENTO PARA ABERTURA DE PORTA COM 1 FECHADURA\n------------------------------------------------");
    }
    else if (fechadura_mais_de_uma == 2){
        printf("\nORCAMENTO PARA ABERTURA DE PORTA COM %d FECHADURAS\n-------------------------------------------------", fechadura_quantidade);
    }

    printf("\n\nDigite o horario que o servico sera realizado\nSomente numeros, no formato 24h ex.\n\n");
    printf("0412 para 04:12 a.m.\n1245 para meio-dia e 45min\n1521 para 15:21 p.m.\n\n");
    printf("*Se o servico for realizado imediatamente apos\naprovacao do orcamento, digite o horario atual\n\nHorario: ");
    scanf("%04d", &horario);

    hora = horario /100;
    minuto = horario %100;

    if((hora<0||hora>23)||(minuto<0||minuto>59)){
        printf("\n\n--------------------------------------------------------------\nERRO: horario invalido. Digite um horario entre 00:00 e 23:59\n--------------------------------------------------------------\n\n");
        return 1;
    }

    if(hora>=06&&hora<=18){
        valor_horario = 0;
    }
    else if(hora>18&&hora<24){
        valor = valor + 50;
        valor_horario = 50;
    }
    else if(hora>=00&&hora<06){
        valor = valor + 100;
        valor_horario = 100;
    }
    limpar_tela();

    if(fechadura_mais_de_uma == 1){
        printf("\nORCAMENTO PARA ABERTURA DE PORTA COM 1 FECHADURA\n------------------------------------------------");
    }
    else if (fechadura_mais_de_uma == 2){
        printf("\nORCAMENTO PARA ABERTURA DE PORTA COM %d FECHADURAS\n-------------------------------------------------", fechadura_quantidade);
    }

    printf("\n\n                   RESULTADO\n\nTotal de fechaduras:\n");

    if(simples>0 && simples<2) printf("        SIMPLES: %d                    R$30,00\n", simples);
    else if(simples>1) printf("        SIMPLES: %d                    R$30,00 un\n", simples);

    if(dupla>0 && dupla<2) printf("        DUPLA:   %d                    R$45,00\n", dupla);
    else if(dupla>1) printf("        DUPLA:   %d                    R$45,00 un\n", dupla);

    if(tripla>0 && tripla<2) printf("        TRIPLA:  %d                    R$60,00\n", tripla);
    if(tripla>1) printf("        TRIPLA:  %d                    R$60,00 un\n", tripla);

    printf("\nDeslocamento:\n");
    printf("        Seu CEP: %d-%03d            R$%d,00\n", cep, cep_completo % 1000, valor_regiao);
    printf("        Horario da visita: %02d:%02d      R$%d,00\n", hora, horario % 100, valor_horario);
    printf("\n*Taxa fixa:                           R$50,00\n");
    printf("\n-----------------------------------------------\nValor total do servico:               R$%d,00\n-----------------------------------------------\n\n\n", valor);

return 0;
}
