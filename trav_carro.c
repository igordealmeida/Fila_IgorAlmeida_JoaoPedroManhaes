#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
#include "biblio_fila.h"
#include <windows.h> 

int main(){

    struct sfila  filaC_G, filaG_C;
    int  contD=0, numeroselecao; 
    char x;  

    qinit(&filaC_G);
    qinit(&filaG_C);

    do{
        printf("\n1 - Cadastrar Campos->Guarus\n");
        printf("\n2 - Cadastrar Guarus->Campos\n");
        printf("\n3 - Liberar Carro\n");
        printf("\n4 - Encerrar Programa\n");       
        printf("\nIndique o numero  da execucao do programa desejado: \n");
        scanf("%d", &numeroselecao);
        x = 'S';  
        switch (numeroselecao){
            case 1: while ((x != 'N') && (x != 'n')){ 
                        if(qisFull(&filaC_G)){
                            printf("\nFila de carros Campos->Guarus cheia.\n");
                        }
                        else{
                        printf("\nEntre com a placa do carro: \n");
                        scanf(" %c", &x);
                        enqueue(&filaC_G, x); 
                        printf("Ultimo: %c \n",last(&filaC_G)); 
                        } 
                        printf("\nDeseja Cadastrar mais algum carro Campos->Guarus ? (S/N)\n");
                        scanf(" %c", &x);
                    }
                    break;                     
            case 2: while ((x != 'N') && (x != 'n')){
                        if(qisFull(&filaG_C)){
                            printf("\nFila de carros Guarus->Campos cheia.\n");
                        }
                        else{
                        printf("\nEntre com a placa do carro: \n");
                        scanf(" %c", &x);
                        enqueue(&filaG_C, x); 
                        printf("Ultimo: %c \n",last(&filaG_C)); 
                        } 
                        printf("\nDeseja Cadastrar mais algum carro Guarus->Campos ? (S/N)\n");
                        scanf(" %c", &x);
                    }
                    break;
            case 3: while ((x != 'N') && (x != 'n')) {         
                        printf("\n------Liberando Travessia------\n");
                        printf("     Sentido Campos->Guarus\n");
                        if(!qisEmpty(&filaC_G)){
                            printf("     Atravessando carro: %c\n\n", first(&filaC_G));
                            dequeue(&filaC_G);
                            sleep(5); 
                        }
                        else{
                            printf("     Nenhum carro aguardando.\n\n");
                        }
                        printf("     Sentido Guarus->Campos\n");
                        if(!qisEmpty(&filaG_C)){
                            printf("     Atravessando carro: %c\n\n", first(&filaG_C));
                            dequeue(&filaG_C);
                            sleep(5);
                        }
                        else{
                        printf("     Nenhum carro aguardando.\n\n");
                        }
                        printf("\n     Deseja Prosseguir ? (S/N)\n");
                        scanf(" %c", &x); 
                    }
                    break;
            case 4: printf("\nPrograma encerrado\n");
                    contD++;
                    break;
            default: printf("\nO numero informado nao corresponde a nenhuma operacao\n");
        }
    } while(contD < 1);
    return 0;