#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<windows.h>
#include<string.h>
#include<ctype.h>
#include"agenda.h"//biblioteca funçoes da agenda
void layout();//define nome na janela do prompt
/**************************************************************************/
void configtela(){//função q configura o tamanho da tela e do buffer      //
COORD outbuff;                                                            //
outbuff.X = 15; // tem que ser 1 maior que o tamanho X                    //
outbuff.Y = 5; // tem que ser 1 maior que o tamanho Y                     // Define um tamanho inicial pra janela
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);                        //
SetConsoleScreenBufferSize(hConsole, outbuff);                            // "Simular um celular"
SMALL_RECT windowSize = {0, 0, 40, 40};                                   //
SetConsoleWindowInfo(hConsole, TRUE, &windowSize);                        //
/**************************************************************************/
} 
main(){
       configtela();
       layout();
       OrdAlfa *P;
       P=inicializa();
       int M,N;
       char C;
       Beep(900,50);
       Beep(1000.5,50);
       Beep(900,50);
       do{
           system("color e1");
           system("cls");
           printf("*********** AGENDA TELEFONICA ***********\n\n"
                  "  OPCOES\n"
                  "   (1) Cadastrar contato\n"
                  "   (2) Ver contatos\n"
                  "   (3) Procurar contato\n"
                  "   (4) Editar contato\n\n"
                  "   (0) SAIR DA AGENDA\n"
                  "\n>> ");
           fflush(stdin);
           scanf("%d",&M);
           switch(M){
                     case 1:{
                          do{
                             system("cls");
                             system("color b1");
                             printf("*************** CADASTRO ****************");
                             P=cadastra(P);
                             Beep(5000,200);
                             printf("\n   Contato registrado com sucesso...");
                             Beep(5000,200);
                             Sleep(800);
                             fflush(stdin);
                             printf("\n\n**Cadastrar mais um contato?(s/n):");
                             scanf("%c",&C);
                             }while(C=='s');
                          break;
                          }
                     case 2:{
                          system("cls");
                          system("color a0");
                          printf("************ CONTATOS AGENDA ************\n\n");
                          ver(P);
                          break;
                          }
                     case 3:{
                          system("cls");
                          printf("********** PESQUISA DE CONTATO **********\n\n");
                          printf("Opcoes\n"
                                 " (1) Por nome?\n"
                                 " (2) Afabeto?\n"
                                 "Opcao>> ");
                          scanf("%d",&N);
                          system("color a0");
                          if(N==1){
                                   system("cls");

                                   printf("****** PESQUISA DE CONTATO POR NOME *****\n\n");
                                   procurarContatoPN(P);
                                   }
                          if(N==2){
                                   system("cls");
                                   printf("PESQUISA DE CONTATO POR LETRA ALFABETICA*\n\n");
                                   procurarContatoPI(P);
                                   }
                          break;
                          }
                     case 4:{
                          system("cls");
                          printf("************* EDITAR CONTATO ************\n\n");
                          printf("Opcoes\n"
                                 " (1) Favoritar/Desfavoritar contato\n"
                                 " (2) Excluir contato\n>> ");
                          scanf("%d",&N);
                          system("color a0");
                          if(N==1){
                                   editarContato(P);
                                   }
                          if(N==2){
                                   P=excluiContato(P);
                                   }
                          break;
                          }
                     case 0:{
                          printf("Saindo...");
                          Beep(7000,111);
                          Beep(6500,111);
                          Beep(6000,111);
                          Beep(5500,111);
                          Beep(5000,111);
                          break;
                          }
                     default:{
                              printf("Opcao invalida!");
                              Beep(1100.55,100);
                              Beep(1100,100);
                              Sleep(800);
                              }                          
                     }
       }while(M!=0);
}
void layout(){
     system("title Telefone - AGENDA");
     }
