//count me out

#include <stdio.h>
#define tamaluno 3 

int main(void){

    int listaaluno[tamaluno];
    int qtdaluno = 0;
    int opcao;
    int sair = 0; //falso

    while (!sair){

        printf("Projeto escola\n");
        printf("0 - Sair\n");
        printf("1 - Aluno\n");
        printf("2 - Professor\n");
        printf("3 - Disciplina\n");

        scanf("%d", &opcao);

        switch (opcao){
            case 0:{
                sair = 1;
                break;
            }
            case 1:{

                printf("MODULO ALUNO\n");

                int sairaluno = 0;
                int opcaoaluno;

                while (!sairaluno){
                    printf("0 - Voltar\n");
                    printf("1 - Cadastrar aluno\n");
                    printf("2 - Listar aluno\n");            
                    printf("3 - Atualizar aluno\n");
                    printf("4 - Excluir aluno\n");
                    scanf("%d" &opcaoaluno);

                    switch (opcaoaluno){
                        case 0:{
                            sair = 1;
                            break;
                        }
                        case 1:{
                            printf("Cadastrar aluno\n");
                            printf("Digite a matrícula:\n");
                            int matricula
                            scanf("%d", &matricula);
                            if(matricula < 0){
                                printf("matricula invalida\n")
                            }else{
                                if(qtdaluno == tamaluno){
                                    printf("lista de aluno cheia");
                                }else{
                                    listaaluno[qtdaluno] = matricula;
                                    qtdaluno++;
                                }
                            }
                            break;
                        }
                        case 2:{
                            printf("2 - Listar aluno\n"); 
                            break;
                        }
                        case 3:{
                            printf("3 - Atualizar aluno\n");
                            break;
                        }                        
                        case 4:{
                            printf("4 - Excluir aluno\n");
                            break;
                        }default:{
                            printf("Opcao invalida\n");
                        }


                break;
            }
            case 2:{
                printf("MODULO PROFESSOR\n");
                break;
            }
            case 3:{
                printf("MODULO DISCIPLINA\n");
                break;
            }default:{
                printf("OPÇÃO INVÁLDA");
            }                       
        }
    }

}