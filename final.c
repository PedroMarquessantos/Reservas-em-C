#include <stdio.h>
    #include <stdlib.h>


struct dados{
    int matricula,telefone,idade;
        char nome[20],genero;


};

struct dados ReservaDoFuncionario[32][20];

////////////////COLOCAR STRUCT/////////////////////

int Localivre (int dia){
    int vag=0;

    if(dia >=0 || dia <=31){
        while (ReservaDoFuncionario[dia]
    [vag].matricula!=0 && vag<19){

         vag++;
    }
     if (ReservaDoFuncionario[dia]  
[vag].matricula==0){
            return vag;
    }
     return -1;

}

}

int ReservasDia(struct dados infofuncionario, int dia)
{
    int Llivre;

    Llivre=Localivre(dia);

    if(Llivre==-1){
        return -1;
    }

    ReservaDoFuncionario[dia][Llivre]=infofuncionario;
    return 0;

}

struct dados procurar (int mat, int dia){
    int vag=0;

        struct dados retorno;

    retorno.matricula=-1;

if (dia >=0 || dia<=31){
     while (ReservaDoFuncionario[dia][vag].matricula!=mat &&vag<20){
        vag++;
    }
    if (ReservaDoFuncionario[dia][vag].matricula==mat){
        retorno = ReservaDoFuncionario[dia][vag];
    }
    
}
    return retorno;
}


//CONSULTA O CADASTRO///

void consulCadastro(){
    int matricula, dia;

struct dados ConsultadoFuncionario;

system("cls"); //FAZER LIMPEZA NA TELA//

printf("Digite o dia que deseja que seja consultado:\n");
    scanf("%d/%d",&dia);

printf("Digite a matricula do funcionario:\n");
    scanf("%d",&matricula);

    ConsultadoFuncionario = procurar(matricula, dia);

    if (ConsultadoFuncionario.matricula ==-1){
        printf("Funcionario com reservas inexistente:\n");
            system("pause");

        }else{

            printf("MATRICULA %d\n",ConsultadoFuncionario.matricula);
            printf("NOME:%s\n",ConsultadoFuncionario.nome);
            printf("IDADE:%d\n",ConsultadoFuncionario.idade);
            printf("TELEFONE:\n",ConsultadoFuncionario.telefone);
            printf("SEXUALIDADE:%c\n",ConsultadoFuncionario.genero);
            system("pause");
    }


}

// VISUALIZAR OS DIAS//

void VisuData(){
int dia, vag;

system("cls");
printf("EXIBIR DIAS SELECIONADO:\n");
scanf("%d",&dia);

if(dia >=0 && dia <=31){

for (vag=0;vag<20;vag++){

    if (ReservaDoFuncionario[dia][vag].matricula!=0){

            printf("MATRICULA %d\n",ReservaDoFuncionario[dia][vag].matricula);
            printf("NOME:%s\n",ReservaDoFuncionario[dia][vag].nome);
            printf("IDADE:%d\n",ReservaDoFuncionario[dia][vag].idade);
            printf("TELEFONE:\n",ReservaDoFuncionario[dia][vag].telefone);
            printf("SEXUALIDADE:%c\n",ReservaDoFuncionario[dia][vag].genero);
            system("pause");
    }  

}

}else{
  printf("A DATA ESTA INVALIDA\n");
  system("pause");
    
}

}

//CADASTRA OS FUNCIONARIOS//

void cadFuncionario(){

int legalizar, y;
struct dados ReservaDoFuncionario;

system("Cls");

printf("NOVOS DADOS DO FUNCIONARIO\n");
printf("dia:\n");
scanf("%d",&y);

printf("MATRICULA:\n");
scanf("%d",&ReservaDoFuncionario.matricula);

printf("NOME:\n");
scanf("%s",&ReservaDoFuncionario.nome);

printf("IDADE:\n");
scanf("%d",&ReservaDoFuncionario.idade);

printf("TELEFONE\n");
scanf("%d",&ReservaDoFuncionario.telefone);
    getchar(); //USADO QUANDO FOR NECESSARIO A ENTRADA DE UM UNICO CARACTERE
//PODERIA USAR TBM O FFLUSH(STDIN) LIMPAR (OU LIBERAR) O BUFFER DE SAIDA

printf("SEXUALIDADE M OU H:\n");
scanf("%c",&ReservaDoFuncionario.genero);

    legalizar = ReservasDia(ReservaDoFuncionario, y);


if(legalizar==-1){
printf("VAGAS INDISPONIVEIS PARA ESTA DATA:\n");
system("pause");

}else{
printf(" FUNCIONARIO CADASTRADO COM SUCESSO:\n");
system("pause");

    }


}

void iniciar(){

int p,z;
for (z=0;p<32;z++){
    for(p=0;p<20;p++){
        ReservaDoFuncionario[z][p].matricula=0;
    }

}


}


//MENU PRINCIPAL//
int main()
{
int opcao;

do{
    system("cls");
    printf("VAI DA TUDO CERTO\n\n");
    printf("1.>>>FAZER CADASTRO DE FUNCIONARIOS<<<\n");
    printf("2.>>>CONSULTA CADASTRO DO DIA<<<\n");
    printf("3.>>>VISUALIZAR SUAS RESERVAS<<<\n");
    printf("4.>>>ENCERRAR<<<\n\n");
    printf("ESCOLHA A OPCAO QUE DESEJA");

    scanf("%d",&opcao);

    switch (opcao)
    {
    case 1:
        cadFuncionario();
        break;

     case 2:
            consulCadastro();
            break;

    case 3:
            VisuData();
            break;

    case 4:
            printf("Adeus\n");
            break;
    
    default:
            printf("OPCAO INVALIDA\n");
            system("pause");
    };

}while(opcao!=3);



    return 0;

}
