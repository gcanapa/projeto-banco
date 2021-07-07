#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include "filaNormal.h"
#include "filaPrioridade.h"

struct clientes{
    char nome[30];
};

struct time{
    int tm_sec; //representa os segundos de 0 a 59
    int tm_min; //representa os minutos de 0 a 59
    int tm_hour; //representa as horas de 0 a 24
};

void limpaTela();
void cabecalho();

int main(){
    int op; //variavel para opção do switch case
    struct fila* filaNormal; //Variavel da fila Normal
    FilaPrio* filaPrioridade; //Variavel da fila Prioridade
    filaPrioridade = cria_FilaPrio(); //Cria a fila Prioridadae
    struct clientes clientes[30]; //Variavel para armazenar os nomes dos clientes
    criafila(filaNormal, 30); //Cria a fila Normal
    struct time *hora_atual; //Cria uma variavel do tipo time para o horario
    int tipoAtendimento, i = 0, aux = 0, valor_retirado, total_filaPrioridade, total_filaNormal; //Criação de variaveis auxiliares
    char name_random[30];
    int *random_number[30];
    srand(time(NULL)); //Para os valores variaveis sempre mudarem
    time_t segundos; //variavel do tipo time_t para armazenar o tempo em segundos
    time(&segundos); //obtendo o tempo em segundos
    hora_atual = localtime(&segundos); //para converter de segundos para o tempo local

    for( ; ; ){
        if(hora_atual->tm_hour  >= 10 && hora_atual->tm_hour <= 15){ // Verifica se o programa est� nos horarios condizentes com oque foi estipulado
            cabecalho(hora_atual);
            printf("\n[1] - Cadastro atendimento");
            printf("\n[2] - Atendimento");
            printf("\n[3] - Mostrar o total de pessoas na fila");
            printf("\n[4] - Sair do Banco");
            printf("\nSua opcao: ");
            scanf("%d", &op);
            total_filaPrioridade = tamanho_FilaPrio(filaPrioridade);
            total_filaNormal = Fila_Tamanho(filaNormal);
            switch(op){
                case 1:
                    limpaTela();
                    printf("============= Banco AG CORP aberto =============");
                    printf("\nSelecione seu metodo de atendimento Prioritario ou Normal (1/2): ");
                    scanf("%d",&tipoAtendimento);
                    for(int i=0; i<30; i++){
                        if(tipoAtendimento == 1){
                            printf("Me informe seu nome: ");
                            fflush(stdin);
                            scanf("%s", &clientes[i].nome);
                            fflush(stdin);
                            insere_FilaPrio(filaPrioridade, clientes[i].nome, 10);
                            printf("%s voce foi inserido na fila de prioridade", clientes[i].nome);
                            Sleep(2000);
                            limpaTela();
                            break;
                        }if(tipoAtendimento == 2){
                            printf("Me informe seu nome: ");
                            scanf("%s", &name_random);
                            fflush(stdin);
                            random_number[i] = rand() % 100;
                            fflush(stdin);
                            inserir_elemento(filaNormal, random_number[i]);
                            printf("%s o numero do seu ticket de atendimento e %d", name_random, random_number[i]);
                            Sleep(2000);
                            limpaTela();
                            break;
                        }else{
                            printf("Digite uma opcao valida!");
                            Sleep(1500);
                            limpaTela();
                            break;
                        }
                    }
                    break;
                case 2:
                    limpaTela();
                    while(tamanho_FilaPrio(filaPrioridade) != 0 || Fila_Tamanho(filaNormal) != 0){
                        if(total_filaPrioridade >= 1 && total_filaPrioridade < 30){
                            for(aux=0;aux<2;aux++){
                                if(total_filaPrioridade != 0){
                                    printf("Atendimento prioritario\n");
                                    imprime_UltimoFilaPrio(filaPrioridade); //Pega o nome da pessoa a ser retirada
                                    printf(" foi removido da fila prioridade\n");
                                    printf("Sera chamado o proximo da fila\n");
                                    remove_FilaPrio(filaPrioridade);
                                    total_filaPrioridade = total_filaPrioridade - 1 ;
                                    printf("================================================================\n");
                                    Sleep(1500);
                                }
                            }
                        }
                        if(total_filaNormal != 0){
                            printf("Atendimento nao prioritario\n");
                            valor_retirado = retirar_elemento(filaNormal);
                            printf("Pessoa com ticket de numero %d se dirigir ao caixa\n", valor_retirado);
                            printf("Sera chamado o proximo da fila\n");
                            total_filaNormal = total_filaNormal - 1;
                            printf("================================================================\n");
                            Sleep(3500);
                        }
                    }

                   Sleep(3500);
                   limpaTela();
                    break;
                case 3:
                    printf("A fila prioritaria tem tamanho de %d", tamanho_FilaPrio(filaPrioridade));
                    printf("\nO tamanho da fila nao prioritaria e: %d\n", Fila_Tamanho(filaNormal));
                    Sleep(2500);
                    limpaTela();
                    break;
                case 4:
                    exit(0);
                default:
                    printf("Opcao invalida\n");
                    Sleep(2000);
                    limpaTela();
                    break;
            }
        }else{
            //Apos a verificação de que náo está nos parametros de horarios do banco encerra o programa
            limpaTela();
            if(hora_atual->tm_hour < 10){
                printf("================================================");
                printf("\n             Banco AG CORP fechado!");
                printf("\n        Por favor volte em outro horario!");
                printf("\n   Atendimento das 10:00 horas as 16:00 horas");
                printf("\n              Hora Atual: 0%d:%d:%d",hora_atual->tm_hour, hora_atual->tm_min, hora_atual->tm_sec);
                printf("\n================================================");
                exit(0);
            }
            if(hora_atual->tm_min < 10){
                printf("================================================");
                printf("\n             Banco AG CORP fechado!");
                printf("\n        Por favor volte em outro horario!");
                printf("\n   Atendimento das 10:00 horas as 16:00 horas");
                printf("\n              Hora Atual: %d:0%d:%d",hora_atual->tm_hour, hora_atual->tm_min, hora_atual->tm_sec);
                printf("\n================================================");
                exit(0);
            }
            if(hora_atual->tm_sec < 10){
                printf("================================================");
                printf("\n             Banco AG CORP fechado!");
                printf("\n        Por favor volte em outro horario!");
                printf("\n   Atendimento das 10:00 horas as 16:00 horas");
                printf("\n              Hora Atual: %d:%d:0%d",hora_atual->tm_hour, hora_atual->tm_min, hora_atual->tm_sec);
                printf("\n================================================");
                exit(0);
            }
            if(hora_atual->tm_hour < 10 && hora_atual->tm_min < 10 && hora_atual->tm_sec < 10){
                printf("================================================");
                printf("\n             Banco AG CORP fechado!");
                printf("\n        Por favor volte em outro horario!");
                printf("\n   Atendimento das 10:00 horas as 16:00 horas");
                printf("\n              Hora Atual: 0%d:0%d:0%d",hora_atual->tm_hour, hora_atual->tm_min, hora_atual->tm_sec);
                printf("\n================================================");
                exit(0);
            }else{
                printf("================================================");
                printf("\n             Banco AG CORP fechado!");
                printf("\n        Por favor volte em outro horario!");
                printf("\n   Atendimento das 10:00 horas as 16:00 horas");
                printf("\n              Hora Atual: %d:%d:%d",hora_atual->tm_hour, hora_atual->tm_min, hora_atual->tm_sec);
                printf("\n================================================");
                exit(0);
            }

        }
    }
    libera_FilaPrio(filaPrioridade);
    return 0;
}

void limpaTela(){
    system("cls");
}

void cabecalho(struct time *hora_atual){
      if(hora_atual->tm_min < 10){
        printf("================================================");
        printf("\n           Bem-Vindo ao Banco AG CORP");
        printf("\n   Atendimento das 10:00 horas as 16:00 horas");
        printf("\n              Hora Atual: %d:0%d:%d",hora_atual->tm_hour, hora_atual->tm_min, hora_atual->tm_sec);
        printf("\n================================================");
      }else{
        printf("================================================");
        printf("\n           Bem-Vindo ao Banco AG CORP");
        printf("\n   Atendimento das 10:00 horas as 16:00 horas");
        printf("\n              Hora Atual: %d:%d:%d",hora_atual->tm_hour, hora_atual->tm_min, hora_atual->tm_sec);
        printf("\n================================================");
      }
}
