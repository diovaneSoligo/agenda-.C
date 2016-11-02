 // biblioteca "agenda.h"
/***************************************************************/
struct id{                                                     //
       char nome[20];                                          //
       char sobrenome[30];                                     //
       char apelido[40];                                       //
       };                                                      //
struct fone{                                                   //
       char tipo[15];                                          //
       int area;                                               //
       int numero;                                             //
       };                                                      //
struct end{                                                    //
       char email[30];                                         //
       char residencial[50];                                   //
       char trabalho[50];                                      //
       };                                                      //
struct cont{                                                   //
       struct id pessoaID;                                     //
       struct fone pessoaF;                                    //
       struct end pessoaE;                                     //
       struct cont *prox;                                      //
       int favorito;                                           //
       };                                                      //
typedef struct cont Contato;                                   //
                                                               //
struct ordem{                                                  //
       struct cont *LC; //acessa o contato                     //
       struct ordem *prox;// acessa proxima letra alfabeto     //
       char LA;  //armazena primeira letra do nome             //
       };                                                      //
typedef struct ordem OrdAlfa;                                  //
/**************************************************************//************************************************************************/
OrdAlfa *cadastra(OrdAlfa *L){                                                                                                          //
        OrdAlfa *p,*aux;                                                                                                                //
        p=L;                                                                                                                            //
        aux=L;                                                                                                                          //
                                                                                                                                        //
        Contato *fila; //fila de contatos                                                                                               //
        fila=(Contato*)malloc(sizeof(Contato));                                                                                         //
                                                                                                                                        //
        fflush(stdin);                                                                                                                  //
        printf("\nNome: ");gets(fila->pessoaID.nome);                                                                                   //
        printf("Sobrenome: ");gets(fila->pessoaID.sobrenome);                                                                           //
        printf("quem eh?: ");gets(fila->pessoaID.apelido);                                                                              //
        fflush(stdin);                                                                                                                  //
        printf("Tipo (celular/residencial): ");gets(fila->pessoaF.tipo);                                                                //
        printf("Area: ");scanf("%d",&fila->pessoaF.area);                                                                               //  
        printf("Numero: ");scanf("%d",&fila->pessoaF.numero);                                                                           //
        fflush(stdin);                                                                                                                  //
        printf("E-mail: ");gets(fila->pessoaE.email);                                                                                   //
        printf("End. trabalho: ");gets(fila->pessoaE.trabalho);                                                                         //
        printf("End. casa: ");gets(fila->pessoaE.residencial);                                                                          //
        printf("Favorito?(0-nao/1-sim): ");                                                                                             //
        scanf("%d",&fila->favorito);                                                                                                    //
        if(fila->favorito != 1){//caso digite outro valor é declarado como nao favorito                                                 //
              fila->favorito=0;                                                                                                         //
              }                                                                                                                         //
        strupr(fila->pessoaID.nome);strupr(fila->pessoaID.sobrenome);//deixa nome e sobrenome com letra maiúscula                       //
        fila->prox=NULL;                                                                                                                //
                                                                                                                                        //
        if(L==NULL){//caso seja o primeiro a ser inserido cria a ordem alfabetica, isere e retorna                                      //
              OrdAlfa *ordem; //lista encadeada com ordem alfabetica                                                                    //
              ordem=(OrdAlfa*)malloc(sizeof(OrdAlfa));                                                                                  //
              ordem->prox=NULL;//proximo da lista alfabetica e NULL                                                                     //
              ordem->LC=fila;//armazena o endereço da fila dos contatos                                                                 //
              ordem->LA=fila->pessoaID.nome[0];//armazena a 1ª letra do nome                                                            //
              return ordem;                                                                                                             //
              }                                                                                                                         //
                                                                                                                                        //
        while(p->prox != NULL){//verifica se ja contem a 1ª letra na lista encadeada, se tiver, insere e retorna                        //
              if(p->LA == fila->pessoaID.nome[0]){//se iniciais forem iguais ok                                                         //
                      if(fila->favorito==1){//se favorito, faz os demais procedimentos                                                  //
                             if(p->LC->favorito == 1){//verificar se ja existe algum favorito, se sim executa                           //
                                      Contato *aux2,*aux3;                                                                              //
                                      aux3=p->LC;//guarda end. de um anterior, pra nao perde-lo                                         //
                                      aux2=p->LC;//guarda end. 1º favorito pra manipulação                                              //
                                      while(aux2->favorito!=0){                                                                         //
                                            aux3=aux2;                                                                                  //
                                            if(aux2->prox==NULL){                                                                       //
                                                   aux2->prox=fila;                                                                     //
                                                   return L;                                                                            //
                                                   }                                                                                    //
                                            aux2=aux2->prox;                                                                            // 
                                            }                                                                                           //
                                      fila->prox=aux2;                                                                                  //
                                      aux3->prox=fila;                                                                                  //
                                      }                                                                                                 //
                               else{//se nao existe nenhum favorito o coloca no inicio da fila                                          //
                                    fila->prox=p->LC;                                                                                   //
                                    p->LC=fila;                                                                                         //
                                    }                                                                                                   //
                              return L;                                                                                                 //
                              }                                                                                                         //
                      else{//caso nao seja favorito apenas coloca-o no fim da fila                                                      //
                           Contato *C;                                                                                                  //
                           C=p->LC;                                                                                                     //
                            while(C->prox!=NULL){                                                                                       //
                                   C=C->prox;                                                                                           //
                                   }                                                                                                    //
                            C->prox=fila;                                                                                               //
                           }                                                                                                            //
                return L;                                                                                                               //
                }                                                                                                                       //
          p=p->prox;//se as iniciais nao forem iguais testa o proximo                                                                   //
          }                                                                                                                             //
              if(p->LA == fila->pessoaID.nome[0]){//se iniciais forem iguais ok                                                         //
                      if(fila->favorito==1){//se favorito, faz os demais procedimentos                                                  //
                             if(p->LC->favorito == 1){//verificar se ja existe algum favorito, se sim executa                           //
                                      Contato *aux2,*aux3;                                                                              //
                                      aux3=p->LC;//guarda end. de um anterior, pra nao perde-lo                                         //
                                      aux2=p->LC;//guarda end. 1º favorito pra manipulação                                              //
                                      while(aux2->favorito!=0){                                                                         //
                                            aux3=aux2;                                                                                  //
                                            if(aux2->prox==NULL){                                                                       //
                                                   aux2->prox=fila;                                                                     //
                                                   return L;                                                                            //
                                                   }                                                                                    //
                                            aux2=aux2->prox;                                                                            //
                                            }                                                                                           //
                                      fila->prox=aux2;                                                                                  //
                                      aux3->prox=fila;                                                                                  //
                                      }                                                                                                 //
                               else{//se nao existe nenhum favorito o coloca no inicio da fila                                          //
                                    fila->prox=p->LC;                                                                                   //
                                    p->LC=fila;                                                                                         //
                                    }                                                                                                   //
                              return L;                                                                                                 //
                              }                                                                                                         //
                      else{//caso nao seja favorito apenas coloca-o no fim da fila                                                      //
                           Contato *C;                                                                                                  //
                           C=p->LC;                                                                                                     //
                            while(C->prox!=NULL){                                                                                       //
                                   C=C->prox;                                                                                           //
                                   }                                                                                                    //
                            C->prox=fila;                                                                                               //
                           }                                                                                                            //
                return L;                                                                                                               //
                }                                                                                                                       //
        //se chegou até aqui é pq nao existe nenhuma letra na lista encadeada igual a 1ª letra do nome cadastrado                       //
        //entao se cria um "campo" na lista encadeada para ela                                                                          //
        p=aux;//aux contem o end. do 1ºda lista e como p foi alterado entao volta "ao normal", para poder manipula-lo novamente         //
                                                                                                                                        //
        OrdAlfa *ordem; //lista encadeada com ordem alfabetica                                                                          //
        ordem=(OrdAlfa*)malloc(sizeof(OrdAlfa));                                                                                        //
        ordem->LA=fila->pessoaID.nome[0];//armazena a 1ª letra do nome                                                                  //
        ordem->LC=fila;                                                                                                                 //
                                                                                                                                        //
        if(p->LA > ordem->LA){ //caso letra seja menor q a existente coloca-o no inicio da lista alfabetica                             //
              ordem->prox=p;                                                                                                            //
              return ordem;//retorna o novo inicio do alfabeto                                                                          //
              }                                                                                                                         //
        while(p->LA<ordem->LA){ //testa até achar seu lugar                                                                             //
              if(p->prox == NULL){//se for fim da lista, o torna o novo fim                                                             //
                    p->prox=ordem;                                                                                                      //
                    ordem->prox=NULL;                                                                                                   //
                    return L;                                                                                                           //
                    }                                                                                                                   //
              aux=p;                                                                                                                    //
              p=p->prox;                                                                                                                //
              }                                                                                                                         //
        ordem->prox=p; // achando sua posição o insere e faz os devidos reapontamentos                                                  //
        aux->prox=ordem;                                                                                                                //
        return L;                                                                                                                       //
        }                                                                                                                               //
                                                                                                                                        //
/*****************************************************************//********************************************************************/
OrdAlfa *inicializa(){                                           //
        return NULL;                                             //
        }                                                        //
/****************************************************************//********************************************************************/
void ver(OrdAlfa *L){                                                   //Mostra todo conteudo da agenda                               //
     if(L==NULL){                                                       //                                                             //
                 Beep(4000,200);                                        //mas como o prompt tem uma quantidade X pra mostrar linhas    //
                 printf("\n\n   ERRO!\n"                                //pode acontecer de mostrar somente os últimos contatos        //
                 " <>   Nao existem contatos na agenda  <>\n\n"         /**************************************************************/
                 "Selecione a opcao 1 do menu para inserir!");                                                                         //
                 Beep(4000,200);                                                                                                       //
                 Sleep(1600);                                                                                                          //
                 return;                                                                                                               //
                 }                                                                                                                     //
     OrdAlfa *p;                                                                                                                       //
     Contato *c;                                                                                                                       //
     p=L;                                                                                                                              //
     char Ncompl[50];                                                                                                                  //
     while(p->prox!=NULL){                                                                                                             //
                          printf("\n******************> %c <******************\n",p->LA);//mostra inicial dos nomes A B C ...          //
                          c=p->LC;                                                                                                     //
                          while(c->prox!=NULL){                                                                                        //
                                               printf("\n");                                                                           //
                                               if(c->favorito==1){printf("*F*\n");}//se favorito coloca um *F* pra sinaliza            //
                                               strcpy(Ncompl,c->pessoaID.nome);                                                        //
                                               strcat(Ncompl," ");                                                                     //
                                               strcat(Ncompl,c->pessoaID.sobrenome);                                                   //
                                               puts(Ncompl);                                                                           //
                                               printf("quem eh?: ");puts(c->pessoaID.apelido);                                         //
                                               printf("(%d)%d ",c->pessoaF.area,c->pessoaF.numero);                                    //
                                               puts(c->pessoaF.tipo);                                                                  //
                                               printf("E-mail: ");puts(c->pessoaE.email);                                              //
                                               printf("End. trab.: ");                                                                 //
                                               puts(c->pessoaE.trabalho);                                                              //
                                               printf("End. casa: ");                                                                  //
                                               puts(c->pessoaE.residencial);                                                           //
                                               c=c->prox;                                                                              //
                                               }                                                                                       //
                                               //mostra ultimo da fila                                                                 //
                                               printf("\n");                                                                           //
                                               if(c->favorito==1){printf("*F*\n");}//se favorito coloca um *F* na frente do nome       //
                                               strcpy(Ncompl,c->pessoaID.nome);                                                        //
                                               strcat(Ncompl," ");                                                                     //
                                               strcat(Ncompl,c->pessoaID.sobrenome);                                                   //
                                               puts(Ncompl);                                                                           //
                                               printf("quem eh?: ");puts(c->pessoaID.apelido);                                         //
                                               printf("(%d)%d ",c->pessoaF.area,c->pessoaF.numero);                                    //
                                               puts(c->pessoaF.tipo);                                                                  //
                                               printf("E-mail: ");puts(c->pessoaE.email);                                              //
                                               printf("End. trab.: ");                                                                 //
                                               puts(c->pessoaE.trabalho);                                                              //
                                               printf("End. casa: ");                                                                  //
                                               puts(c->pessoaE.residencial);                                                           //
                          p=p->prox;                                                                                                   //
                          }                                                                                                            //
     printf("\n******************> %c <******************\n",p->LA);//mostra inicial dos nomes A B C ...                               //
                          c=p->LC;                                                                                                     //
                          while(c->prox!=NULL){                                                                                        //
                                               printf("\n");                                                                           //
                                               if(c->favorito==1){printf("*F*\n");}//se favorito coloca um *F* na frente do nome       //
                                               strcpy(Ncompl,c->pessoaID.nome);                                                        //
                                               strcat(Ncompl," ");                                                                     //
                                               strcat(Ncompl,c->pessoaID.sobrenome);                                                   //
                                               puts(Ncompl);                                                                           //
                                               printf("quem eh?: ");puts(c->pessoaID.apelido);                                         //
                                               printf("(%d)%d ",c->pessoaF.area,c->pessoaF.numero);                                    //
                                               puts(c->pessoaF.tipo);                                                                  //
                                               printf("E-mail: ");puts(c->pessoaE.email);                                              //
                                               printf("End. trab.: ");                                                                 //
                                               puts(c->pessoaE.trabalho);                                                              //
                                               printf("End. casa: ");                                                                  //
                                               puts(c->pessoaE.residencial);                                                           //
                          c=c->prox;                                                                                                   //
                          }                                                                                                            //
                          //mostra ultimo da fila                                                                                      //
                          printf("\n");                                                                                                //
                          if(c->favorito==1){printf("*F*\n");}//se favorito coloca um *F* na frente do nome                            //
                          strcpy(Ncompl,c->pessoaID.nome);                                                                             //
                          strcat(Ncompl," ");                                                                                          //
                          strcat(Ncompl,c->pessoaID.sobrenome);                                                                        //
                          puts(Ncompl);                                                                                                //
                          printf("quem eh?: ");puts(c->pessoaID.apelido);                                                              //
                          printf("(%d)%d ",c->pessoaF.area,c->pessoaF.numero);                                                         //
                          puts(c->pessoaF.tipo);                                                                                       //
                          printf("E-mail: ");puts(c->pessoaE.email);                                                                   //
                          printf("End. trab.: ");                                                                                      //
                          puts(c->pessoaE.trabalho);                                                                                   //
                          printf("End. casa: ");                                                                                       //
                          puts(c->pessoaE.residencial);                                                                                //
     getch();                                                                                                                          //
     }                                                                                                                                 //
/**************************************************************************************************************************************/
void procurarContatoPN(OrdAlfa *L){ //procura e mostra contato pelo nome                                                               //
     if(L==NULL){Beep(4000,200);                                                                                                       //
                 printf("\n<> Nao existem contatos registrados <>");Beep(4000,200);                                                    //
                 Sleep(1100);                                                                                                          //
                 return;                                                                                                               //
                 }                                                                                                                     //
     char procurado[20];	                                                                                                           //
     printf("Procurar pelo nome:\n>> ");                                                                                               //
     fflush(stdin);		                                                                                                               //
     gets(procurado);//le nome procurado                                                                                               //
     strupr(procurado);//deixa letras maiúsculas                                                                                       //
		                                                                                                                               //
     OrdAlfa *aux;                                                                                                                     //
     Contato *percorre;                                                                                                                //
	 int contador=0;                                                                                                                   //
		                                                                                                                               //
	 for(aux = L; aux!=NULL; aux=aux->prox){                                                                                           //
			for(percorre = aux->LC; percorre!=NULL; percorre=percorre->prox){                                                          //
				                       if(strcmp(procurado, percorre->pessoaID.nome)==0){                                              //
					                                        printf("\n*****************************************\n");                   //
					                                        contador++;                                                                //
					                                        char Ncompl[50];                                                           //
					                                                                                                                   //
					                                        printf("\n");                                                              //                               
                                                            if(percorre->favorito==1){printf("*F*\n");}                                //
                                                            strcpy(Ncompl,percorre->pessoaID.nome);                                    //
                                                            strcat(Ncompl," ");                                                        //                                 
                                                            strcat(Ncompl,percorre->pessoaID.sobrenome);                               //                                         
                                                            puts(Ncompl);                                                              //                                  
                                                            printf("quem eh?: ");puts(percorre->pessoaID.apelido);                     //                                          
                                                            printf("(%d)%d ", percorre->pessoaF.area, percorre->pessoaF.numero);       //                                                  
                                                            puts(percorre->pessoaF.tipo);                                              //                                         
                                                            printf("E-mail: "); puts(percorre->pessoaE.email);                         //                                          
                                                            printf("End. trab.: ");                                                    //                                  
                                                            puts(percorre->pessoaE.trabalho);                                          //                                         
                                                            printf("End. casa: ");                                                     //                                 
                                                            puts(percorre->pessoaE.residencial);                                       //
				                                            }                                                                          //
			                                             }                                                                             //
		                                              }                                                                                //
		if(contador==0){                                                                                                               //
			printf("\n      <> Nome nao encontrado <>.\n");                                                                            //
			Sleep(1500);                                                                                                               //
		   }                                                                                                                           //
		else{                                                                                                                          //
			printf("\n    <> %d pessoa(s) encontrada(s) <>", contador);                                                                //
            getch();                                                                                                                   //
            }                                                                                                                          //
}                                                                                                                                      //
/***************************************************************************************************************************//*********/
void procurarContatoPI(OrdAlfa *L){//procura e mostra contatos apartir da letra inicial do nome                             //
     if(L==NULL){Beep(4000,200);                                                                                            //
                 printf("\n<> Nao existem contatos registrados <>");Beep(4000,200);                                         //
                 Sleep(1100);                                                                                               //
                 return;                                                                                                    //
                 }                                                                                                          //
                                                                                                                            //
     OrdAlfa *p;                                                                                                            //
     Contato *c;                                                                                                            //
     p=L;                                                                                                                   //
                                                                                                                            //
     char Ncompl[50];                                                                                                       //
     char letra;                                                                                                            //
                                                                                                                            //
     printf("Letra inicial do nome:\n>> ");                                                                                 //
     fflush(stdin);                                                                                                         //
     scanf("%c",&letra);                                                                                                    //
     letra=toupper(letra);//deixa letra escolida maiúscula para comparação                                                  //
                                                                                                                            //
     while(p->prox!=NULL){                                                                                                  //
                          if(p->LA==letra){                                                                                 //
                                           c=p->LC;                                                                         //
                                           while(c->prox!=NULL){                                                            //
                                                                printf("\n*****************************************\n\n");  //
                                                                if(c->favorito==1){printf("*F*\n");}                        //
                                                                strcpy(Ncompl,c->pessoaID.nome);                            //
                                                                strcat(Ncompl," ");                                         //
                                                                strcat(Ncompl,c->pessoaID.sobrenome);                       //
                                                                puts(Ncompl);                                               //
                                                                printf("quem eh?: ");puts(c->pessoaID.apelido);             //
                                                                printf("(%d)%d ",c->pessoaF.area,c->pessoaF.numero);        //
                                                                puts(c->pessoaF.tipo);                                      //
                                                                printf("E-mail: ");puts(c->pessoaE.email);                  //
                                                                printf("End. trab.: ");                                     //
                                                                puts(c->pessoaE.trabalho);                                  //
                                                                printf("End. casa: ");                                      //
                                                                puts(c->pessoaE.residencial);                               //
                                                                c=c->prox;                                                  //
                                                                }                                                           //
                                           //mostra ultimo da fila                                                          //
                                           printf("\n*****************************************\n\n");                       //
                                           if(c->favorito==1){printf("*F*\n");}                                             //
                                           strcpy(Ncompl,c->pessoaID.nome);                                                 //
                                           strcat(Ncompl," ");                                                              //
                                           strcat(Ncompl,c->pessoaID.sobrenome);                                            //
                                           puts(Ncompl);                                                                    //
                                           printf("quem eh?: ");puts(c->pessoaID.apelido);                                  //
                                           printf("(%d)%d ",c->pessoaF.area,c->pessoaF.numero);                             //
                                           puts(c->pessoaF.tipo);                                                           //
                                           printf("E-mail: ");puts(c->pessoaE.email);                                       //
                                           printf("End. trab.: ");                                                          //
                                           puts(c->pessoaE.trabalho);                                                       //
                                           printf("End. casa: ");                                                           //
                                           puts(c->pessoaE.residencial);                                                    //
                                           getch();                                                                         //
                                           return;                                                                          //
                                           }                                                                                //
                          p=p->prox;                                                                                        //
                          }                                                                                                 //
       if(p->LA==letra){                                                                                                    //
                        c=p->LC;                                                                                            //
                        while(c->prox!=NULL){                                                                               //
                                             printf("\n*****************************************\n\n");                     //
                                             if(c->favorito==1){printf("*F*\n");}                                           //
                                             strcpy(Ncompl,c->pessoaID.nome);                                               //
                                             strcat(Ncompl," ");                                                            //
                                             strcat(Ncompl,c->pessoaID.sobrenome);                                          //
                                             puts(Ncompl);                                                                  //
                                             printf("quem eh?: ");puts(c->pessoaID.apelido);                                //
                                             printf("(%d)%d ",c->pessoaF.area,c->pessoaF.numero);                           //
                                             puts(c->pessoaF.tipo);                                                         //
                                             printf("E-mail: ");puts(c->pessoaE.email);                                     //
                                             printf("End. trab.: ");                                                        //
                                             puts(c->pessoaE.trabalho);                                                     //
                                             printf("End. casa: ");                                                         //
                                             puts(c->pessoaE.residencial);                                                  //
                                             c=c->prox;                                                                     //
                                             }                                                                              //
                        //mostra ultimo da fila                                                                             //
                        printf("\n*****************************************\n\n");                                          // 
                        if(c->favorito==1){printf("*F*\n");}//se favorito coloca um *F* na frente do nome                   //
                        strcpy(Ncompl,c->pessoaID.nome);                                                                    //
                        strcat(Ncompl," ");                                                                                 //
                        strcat(Ncompl,c->pessoaID.sobrenome);                                                               //
                        puts(Ncompl);                                                                                       //
                        printf("quem eh?: ");puts(c->pessoaID.apelido);                                                     //
                        printf("(%d)%d ",c->pessoaF.area,c->pessoaF.numero);                                                //
                        puts(c->pessoaF.tipo);                                                                              //
                        printf("E-mail: ");puts(c->pessoaE.email);                                                          //
                        printf("End. trab.: ");                                                                             //
                        puts(c->pessoaE.trabalho);                                                                          //
                        printf("End. casa: ");                                                                              //
                        puts(c->pessoaE.residencial);                                                                       //
                        getch();                                                                                            //
                        return;                                                                                             //
                        }                                                                                                   //
       printf("\n\n  <>  NADA ENCONTRADO  <>");//Caso a letra digitada nao foi encotrada exibe mensagem e retorna!          //
       Sleep(1500);                                                                                                         //
       return;                                                                                                              //
}                                                                                                                           //
/***************************************************************************************************************************/
void realocar(OrdAlfa *L, Contato *percorre)//realocar favoritar-desfavoritar                                               //
{                                                                                                                           //
		Contato *passar;                                                                                                    //
		Contato *auxiliar;                                                                                                  //
		if(percorre->favorito==1){ // Se o contato editado ficar favoritado                                                 //
			Contato *anterior=NULL; // Vai guardar endereço anterior ao contato editado                                     //
			for(passar=L->LC; passar!=NULL; passar=passar->prox){                                                           //
				if(passar==percorre){                                                                                       //
					break;  // sair do laço quando chegar no contato                                                        //
				}                                                                                                           //
				anterior = passar; // Endereço do contato anterior se existir                                               //
			}                                                                                                               //
         if(anterior!=NULL){ // Existe contatos anteriores                                                                  //
				if(anterior->favorito==0){                                                                                  //
					if(percorre->prox==NULL){ // Ultimo da lista                                                            //
						anterior->prox = NULL; // Isola o contato editado                                                   //
						Contato *guardar = NULL; // Guardará o contato anterior                                             //
						for(passar=L->LC; passar!=NULL; passar=passar->prox){                                               //
							if(passar->favorito==0){ // percorre até o contato que for não favorito                         //
								break;                                                                                      //
							}                                                                                               //
							guardar = passar; // guarda o anterior se tiver                                                 //
						}                                                                                                   //
						if(guardar==NULL){ // Contato não favorito é o primeiro                                             //
							percorre->prox = L->LC; // Contato editado aponta para o antigo primeiro da lista               //
							L->LC = percorre; // Contato favoritado fica como primeiro da  lista                            //
						}                                                                                                   //
						else{ // Contato não favorito não é o primeiro                                                      //
							percorre->prox = passar; // Irá ficar antes do antigo anterior                                  //
							guardar->prox = percorre;	// ficará após ao contato editado;                                  //
						}		                                                                                            //
					}                                                                                                       //
					else{ // Se o contato não for o ultimo da lista                                                         //
						anterior->prox = percorre->prox; // Contato anterior aponta para o próximo ao contato editado       //
						Contato *guardar = NULL; // Guardará o contato anterior                                             //
						for(passar=L->LC; passar!=NULL; passar=passar->prox){                                               //
							if(passar->favorito==0){ // percorre até o contato que for não favorito                         //
								break;                                                                                      //
							}                                                                                               //
							guardar = passar; // guarda o anterior se tiver                                                 //
						}                                                                                                   //
						if(guardar==NULL){ // Contato não favorito é o primeiro                                             //
							percorre->prox = L->LC; // Contato editado aponta para o antigo primeiro da lista               //
							L->LC = percorre; // Contato favoritado fica como primeiro da  lista                            //
						}                                                                                                   //
						else{ // Contato não favorito não é o primeiro                                                      //
							percorre->prox = passar; // Contato editado irá apontar para o elemento                         //
							guardar->prox = percorre;	// ficará após ao contato editado;                                  //
						}			                                                                                        //
					}                                                                                                       //
				}                                                                                                           //
			}                                                                                                               //
			else{                                                                                                           //
				return; // Retorna como favorito na primeira posição                                                        //
                }	                                                                                                        //
		}                                                                                                                   //
		else{ // Se o contato editado não ficar favoritado                                                                  //
			Contato *anterior=NULL; // Vai guardar endereço anterior ao contato editado                                     //
			for(passar=L->LC; passar!=NULL; passar=passar->prox){                                                           //
				if(passar==percorre){                                                                                       //
					break;                                                                                                  //
				}                                                                                                           //
				anterior = passar;                                                                                          //
			}                                                                                                               //
			if(anterior!=NULL){                                                                                             //
				if(percorre->prox!=NULL){ // Se existirem contatos após o contato editado	                                //
					anterior->prox = percorre->prox; // Contato anterior recebe o próximo ao contato editado                //
					for(passar=anterior; passar!=NULL; passar=passar->prox){                                                //
						if(passar->prox==NULL){                                                                             //
							break;                                                                                          //
						}                                                                                                   //
					}                                                                                                       //
					passar->prox = percorre;  // coloca o contato editado no final da lista de contatos                     //
					percorre->prox = NULL; // último contato                                                                //
				}	                                                                                                        //
			}                                                                                                               //
			else{ // Contato editado é o primeiro da lista                                                                  //
				if(percorre->prox!=NULL){ // Existe outros contatos na lista                                                //
					for(passar=percorre->prox; passar!=NULL; passar=passar->prox){                                          //
						if(passar->prox==NULL){                                                                             //
							break;                                                                                          //
						}                                                                                                   //
					}                                                                                                       //
					L->LC = percorre->prox;                                                                                 //
					passar->prox = percorre;  // coloca o contato editado no final da lista de contatos                     //
					percorre->prox = NULL; // último contato                                                                //
				}	                                                                                                        //
			}                                                                                                               //
		}                                                                                                                   //
}																					                                        //
/***************************************************************************************************************************//******************/
void editarContato(OrdAlfa *L)//função - favorita e desfavorita                                                                                //
{                                                                                                                                              //
        if(L==NULL){Beep(4000,200);                                                                                                            //
			printf("\n  Lista de contatos vazia!\n");Beep(4000,200);                                                                           //
			Sleep(1100);                                                                                                                       //
			return;                                                                                                                            //
		}                                                                                                                                      //
		char procuradoNome[20];                                                                                                                //
		system("cls");                                                                                                                         //
		printf("*****************************************\n");                                                                                 //
		printf("Nome:\n>> ");                                                                                                                  //
		fflush(stdin);		                                                                                                                   //
		gets(procuradoNome);                                                                                                                   //
		strupr(procuradoNome);                                                                                                                 //
		                                                                                                                                       //
		OrdAlfa *aux;                                                                                                                          //
		Contato *percorre;                                                                                                                     //
	                                                                                                                                           //
		int contador=0;                                                                                                                        //
		                                                                                                                                       //
		char Ncompl[40];                                                                                                                       //
		char procuradoSobre[20];                                                                                                               //
		printf("\nContato(s):\n\n");                                                                                                           //
		for(aux = L; aux!=NULL; aux=aux->prox){                                                                                                //
			for(percorre = aux->LC; percorre!=NULL; percorre=percorre->prox){                                                                  //
				if(strcmp(procuradoNome, percorre->pessoaID.nome)==0){                                                                         //
					contador++;                                                                                                                //
					if(percorre->favorito==1){printf("*F*\n");}                                                                                //
                    strcpy(Ncompl, percorre->pessoaID.nome);                                                                                   //
                    strcat(Ncompl," ");                                                                                                        //
                    strcat(Ncompl, percorre->pessoaID.sobrenome);                                                                              //
					puts(Ncompl);                                                                                                              //
					printf("(%d)%d ", percorre->pessoaF.area, percorre->pessoaF.numero);                                                       //
					printf("\n\n");                                                                                                            //
				}                                                                                                                              //
			}                                                                                                                                  //
		}                                                                                                                                      //
		if(contador==0){                                                                                                                       //
			printf("\n        <> Nome nao encontrado. <>\n");                                                                                  //
			Sleep(1200);                                                                                                                       //
			return;                                                                                                                            //
		}                                                                                                                                      //
		else{                                                                                                                                  //
			printf("\n <> Existem %d pessoas com este nome. <>\n", contador);                                                                  //
			if(contador>1)                                                                                                                     //
			{                                                                                                                                  //
				printf("\nDigite o sobrenome:\n>> ");                                                                                          //
				fflush(stdin);                                                                                                                 //
				gets(procuradoSobre);                                                                                                          //
				strupr(procuradoSobre);	                                                                                                       //
			}                                                                                                                                  //
		}                                                                                                                                      //
			Contato *guardar;                                                                                                                  //
			OrdAlfa *comeco;                                                                                                                   //
			int contador2=0;                                                                                                                   //
			for(aux = L; aux!=NULL; aux=aux->prox){                                                                                            //
				for(percorre = aux->LC; percorre!=NULL; percorre=percorre->prox){                                                              //
					if(contador>1){                                                                                                            //
						if(strcmp(procuradoNome, percorre->pessoaID.nome)==0 && strcmp(procuradoSobre, percorre->pessoaID.sobrenome)==0){      //
							comeco = aux;                                                                                                      //
							guardar = percorre;                                                                                                //
							contador2++;                                                                                                       //
							break;                                                                                                             //
						}                                                                                                                      //
					}                                                                                                                          //
					else{                                                                                                                      //
						if(strcmp(procuradoNome, percorre->pessoaID.nome)==0){                                                                 //
							comeco = aux;                                                                                                      //
							guardar = percorre;                                                                                                //
							contador2++;                                                                                                       //
							break;                                                                                                             //
						}	                                                                                                                   //
					}                                                                                                                          //
				}                                                                                                                              //
			}                                                                                                                                  //
				if(contador2>0){                                                                                                               //
					int auxiliar;                                                                                                              //
					system("cls");                                                                                                             //
					printf("\n*****************************************\n\n");                                                                 //
					printf("Informacoes do Contato: \n\n");                                                                                    //
		            if(guardar->favorito==1){printf("*F*\n");}//se favorito coloca um *F* na frente do nome                                    //
					char Ncompl[50];                                                                                                           //
		            strcpy(Ncompl, guardar->pessoaID.nome);                                                                                    //
		            strcat(Ncompl, " ");                                                                                                       //
			        strcat(Ncompl, guardar->pessoaID.sobrenome);                                                                               //
			        puts(Ncompl);                                                                                                              //
			        printf("Quem eh?: "); puts(guardar->pessoaID.apelido);                                                                     //
	                printf("(%d)%d ", guardar->pessoaF.area, guardar->pessoaF.numero);                                                         //
                                                                                                                                               //
						   	printf("\n\nOpcoes\n");                                                                                            //
						    if(guardar->favorito==1){                                                                                          //
						    	printf(" (1) Desfavoritar\n");                                                                                 //
                               }                                                                                                               //
						   	else{	                                                                                                           //
						   		printf(" (1) Favoritar\n");                                                                                    //
                             }                                                                                                                 //
							printf(" (2) Sair sem alterar o contato\n>> ");		;                                                              //
					    	scanf("%d", &auxiliar);                                                                                            //
					    	switch(auxiliar)                                                                                                   //
					    	{                                                                                                                  //
					    		printf("\n");                                                                                                  //
					    		case 1:{                                                                                                       //
										if(guardar->favorito==1){                                                                              //
						    			printf("Deseja desfavoritar?(1)Sim (0)Nao\n>> ");                                                      //
										scanf("%d", &auxiliar);                                                                                //
											if(auxiliar!=1){                                                                                   //
											guardar->favorito=1;                                                                               //
											}                                                                                                  //
											else{                                                                                              //
											guardar->favorito=0;                                                                               //
											realocar(comeco, guardar);                                                                         //
                                            return;	                                                                                           //
											}                                                                                                  //
											break;	                                                                                           //
						    			}	                                                                                                   //
										printf("Deseja favoritar?(1)Sim (0)Nao\n>>");                                                          //
										scanf("%d", &auxiliar);                                                                                //
										if(auxiliar!=1){                                                                                       //
											guardar->favorito=0;                                                                               //
										}                                                                                                      //
										else{                                                                                                  //
											percorre->favorito=1;                                                                              //
											realocar(comeco, guardar);	                                                                       //
										}                                                                                                      //
						    			break;                                                                                                 //
						    		case 2:{                                                                                                   //
						    			printf("\n   <> Voltando ao menu principal...  <>\n");                                                 //
                                        Sleep(1200);                                                                                           //
                                        return;                                                                                                //
						    		}                                                                                                          //
						    		default:{                                                                                                  //
						    			printf("   Opcao invalida... Voltando ao Menu...\n");                                                  //
						    			Sleep(1200);                                                                                           //
                                        return;                                                                                                //
						    		}	                                                                                                       //
							}//fecha switch                                                                                                    //
                }                                                                                                                              //
		}                                                                                                                                      //
        else{                                                                                                                                  //
             printf("\n <> Nao encontrado <>\n\n <> voltando ao menu... <>");                                                                  //
             Sleep(1200);                                                                                                                      //
             return;                                                                                                                           //
             }					                                                                                                               //
}                             		                                                                                                           //                 
/**********************************************************************************************************************************************/
OrdAlfa *realocarExcluir(OrdAlfa *L, OrdAlfa *letra, Contato *percorre)                                                                        //
{                                                                                                                                              //
		Contato *passar;                                                                                                                       //
		Contato *anterior=NULL;                                                                                                                //
                                                                                                                                               //
		for(passar=letra->LC; passar!=NULL; passar=passar->prox){ //Laço de repetição para achar o contato na fila de contatos de mesma letra  //
			if(passar==percorre){                                                                                                              //
				break;                                                                                                                         //
			}                                                                                                                                  //
			anterior = passar;                                                                                                                 //
		}                                                                                                                                      //
		                                                                                                                                       //
		if(anterior==NULL){ // Elemento a ser excluído é o primeiro da fila de contatos de mesma letra                                         //
			if(percorre->prox!=NULL){ // Existem contatos após ele                                                                             //
				letra->LC = percorre->prox; // Atualizar o começo da fila de contatos de mesma letra                                           //
				free(percorre); // Excluindo o contato desejado                                                                                //
				return L;                                                                                                                      //
			}                                                                                                                                  //
			else{ // Não existem contatos após ele                                                                                             //
				OrdAlfa *procurar;                                                                                                             //
				OrdAlfa *campoAnterior=NULL;                                                                                                   //
				for(procurar=L; procurar!=NULL; procurar=procurar->prox){ // Laço para procurar onde está o campo letra inicial do contato     //
					if(procurar==letra){                                                                                                       //
						break;                                                                                                                 //
					}                                                                                                                          //
					campoAnterior = procurar; // Armazena o campo anterior                                                                     //
				}                                                                                                                              //
				if(campoAnterior==NULL){ // Campo letra é o primeiro da lista de letras                                                        //
					if(procurar->prox!=NULL){ // Existem campos após ao campo do contato                                                       //
						L = L->prox; // Atualizando começo da lista de letras da Agenda                                                        //
						free(percorre); // excluindo o contato                                                                                 //
						free(letra); // excluindo o campo letra inicial (elemento da lista que acessa os contatos com mesma letra inicial)     //
                                                                                                                                               //
						return L;                                                                                                              //
					}                                                                                                                          //
					else{ // Há apenas um campo com 1 contato na Agenda                                                                        //
							free(percorre); // excluindo o contato                                                                             //
							free(letra); // excluindo o campo letra inicial (elemento da lista que acessa os contatos com mesma letra inicial) //
							L = NULL;                                                                                                          //
							return L;                                                                                                          //
						}                                                                                                                      //
					}                                                                                                                          //
					                                                                                                                           //
				else{ // Existem campos anteriores ao campo em que o contato está                                                              //
					if(procurar->prox!=NULL){ // existem elementos                                                                             //
						campoAnterior->prox = procurar->prox; // Isolando o campo do contato a ser excluido	                                   //
					}                                                                                                                          //
					else{                                                                                                                      //
						campoAnterior->prox = NULL;                                                                                            //
					}                                                                                                                          //
							                                                                                                                   //
					free(percorre); // excluindo o contato                                                                                     //
					free(letra); // excluindo o campo letra inicial (elemento da lista que acessa os contatos com mesma letra inicial)         //
					return L;                                                                                                                  //
				}	                                                                                                                           //
			}                                                                                                                                  //
		}	                                                                                                                                   //
		else{ //Elemento a ser excluído não é o primeiro da fila de contatos de mesma letra                                                    //
			if(percorre->prox==NULL){ // Se contato for o último da fila                                                                       //
				anterior->prox = NULL; // Anterior aponta para NULL, sendo o novo último                                                       //
				free(percorre); // Excluindo contato desejado                                                                                  //
				return L;                                                                                                                      //
			}                                                                                                                                  //
			else{ //Se o contato a ser excluído está no meio da fila                                                                           //
				anterior->prox = percorre->prox; // Isolando o contato a ser excluído                                                          //
				free(percorre); // Excluindo contato desejado                                                                                  //
				return L;                                                                                                                      //
			}	                                                                                                                               //
		}	                                                                                                                                   //
}                                                                                                                                              //
/*****************************************************************//***************************************************************************/
OrdAlfa *excluiContato(OrdAlfa *L)                                                                                                             //
{                                                                                                                                              //
		if(L==NULL){Beep(4000,200);                                                                                                            //
			printf("\nLista de contatos vazia!\n");Beep(4000,200);                                                                             //
			Sleep(1100);                                                                                                                       //
			return L;                                                                                                                          //
		}                                                                                                                                      //
		else{                                                                                                                                  //
			char procuradoNome[20];                                                                                                            //
			printf("*****************************************\n");                                                                             //
		    printf("Nome:\n>> ");                                                                                                              //
			fflush(stdin);		                                                                                                               //
			gets(procuradoNome);                                                                                                               //
			strupr(procuradoNome);                                                                                                             //
			                                                                                                                                   //
			OrdAlfa *aux;                                                                                                                      //
			Contato *percorre;                                                                                                                 //
		                                                                                                                                       //
			int contador=0;                                                                                                                    //
			                                                                                                                                   //
			char Ncompl[40];                                                                                                                   //
			char procuradoSobre[20];                                                                                                           //
			printf("\nContato(s):\n\n");                                                                                                       //
			for(aux = L; aux!=NULL; aux=aux->prox){                                                                                            //
				for(percorre = aux->LC; percorre!=NULL; percorre=percorre->prox){                                                              //
					if(strcmp(procuradoNome, percorre->pessoaID.nome)==0){                                                                     //
						contador++;                                                                                                            //
						if(percorre->favorito==1){printf("*F*\n");}                                                                            //
	                    strcpy(Ncompl, percorre->pessoaID.nome);                                                                               //
	                    strcat(Ncompl, " ");                                                                                                   //
	                    strcat(Ncompl, percorre->pessoaID.sobrenome);                                                                          //
						puts(Ncompl);                                                                                                          //
						printf("(%d)%d ", percorre->pessoaF.area, percorre->pessoaF.numero);                                                   //
						printf("\n\n");                                                                                                        //
					}                                                                                                                          //
				}                                                                                                                              //
			}                                                                                                                                  //
			if(contador==0){                                                                                                                   //
				printf("\n        <> Nome nao encontrado. <>\n");                                                                              //
			    Sleep(1200);                                                                                                                   //
				return L;                                                                                                                      //
			}                                                                                                                                  //
			else{                                                                                                                              //
				printf("\n <> Existem %d pessoas com este nome. <>\n", contador);                                                              //
				if(contador>1)                                                                                                                 //
				{                                                                                                                              //
					printf("\nDigite o sobrenome:\n>> ");                                                                                      //
					fflush(stdin);                                                                                                             //
					gets(procuradoSobre);                                                                                                      //
					strupr(procuradoSobre);	                                                                                                   //
				}                                                                                                                              //
			}                                                                                                                                  //
				Contato *guardar;                                                                                                              //
				OrdAlfa *comeco;                                                                                                               //
				int contador2=0;                                                                                                               //
				for(aux = L; aux!=NULL; aux=aux->prox){                                                                                        //
					for(percorre = aux->LC; percorre!=NULL; percorre=percorre->prox){                                                          //
						if(contador>1){                                                                                                        //
							if(strcmp(procuradoNome, percorre->pessoaID.nome)==0 && strcmp(procuradoSobre, percorre->pessoaID.sobrenome)==0){  //
								comeco = aux;                                                                                                  //
								guardar = percorre;                                                                                            //
								contador2++;                                                                                                   //
								break;                                                                                                         //
							}                                                                                                                  //
						}                                                                                                                      //
						else{                                                                                                                  //
							if(strcmp(procuradoNome, percorre->pessoaID.nome)==0){                                                             //
								comeco = aux;                                                                                                  //
								guardar = percorre;                                                                                            //
								contador2++;                                                                                                   //
								break;                                                                                                         //
							}	                                                                                                               //
						}                                                                                                                      //
					}                                                                                                                          //
				}                                                                                                                              //
					if(contador2>0){                                                                                                           //
						int auxiliar;                                                                                                          //
						system("cls");                                                                                                         //
						printf("\n*****************************************\n\n");                                                             //
						printf("Informacoes do Contato: \n\n");                                                                                //            
			            if(guardar->favorito==1){printf("*F*\n");}//se favorito coloca um *F* na frente do nome                                //
						char Ncompl[50];                                                                                                       //
			            strcpy(Ncompl, guardar->pessoaID.nome);                                                                                //
			            strcat(Ncompl, " ");                                                                                                   //
				        strcat(Ncompl, guardar->pessoaID.sobrenome);                                                                           //
				        puts(Ncompl);                                                                                                          //
				        printf("Quem eh?: "); puts(guardar->pessoaID.apelido);                                                                 //
		                printf("(%d)%d ", guardar->pessoaF.area, guardar->pessoaF.numero);                                                     //   
                                                                                                                                               //
						printf("\n\nDeseja excluir contato?(1)Sim (0)Nao\n>> ");                                                               //
						scanf("%d", &auxiliar);                                                                                                //
						if(auxiliar==1){                                                                                                       //
							L = realocarExcluir(L, comeco, guardar);                                                                           //
							printf(" <> Excluido com sucesso... <>\n\n  Voltando ao menu!");                                                   //
							Sleep(1200);                                                                                                       //
							return L;                                                                                                          //
						}                                                                                                                      //
						else{                                                                                                                  //
							printf(" <> Voltando ao menu principal... <>");                                                                    //
							Sleep(1200);                                                                                                       //
							return L;                                                                                                          //
						}                                                                                                                      //
					}                                                                                                                          //
					else{                                                                                                                      //
						printf("\n <> Nao encontrado <>\n\n <> voltando ao menu... <>");                                                       //
                        Sleep(1200);                                                                                                           //
                        return L;                                                                                                              //
					}		                                                                                                                   //
		}                                                                                                                                      //
}                                                                                                                                              //
/**********************************************************************************************************************************************/
//FIM
