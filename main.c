//count me out

#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 50
#define MAX_PROFESSORES 50
#define MAX_DISCIPLINAS 50
#define MAX_ALUNOS_POR_DISCIPLINA 50

// ESTRUTURAS

typedef struct {
    int dia, mes, ano;
} Data;

typedef struct {
    int matricula;
    char nome[50];
    char sexo;
    Data dataNascimento;
    char cpf[15];
} Aluno;

typedef struct {
    int matricula;
    char nome[50];
    char sexo;
    Data dataNascimento;
    char cpf[15];
} Professor;

typedef struct {
    char codigo[20];
    int matriculaProfessor;
    int matriculasAlunos[MAX_ALUNOS_POR_DISCIPLINA];
    int quantidadeAlunos;
} Disciplina;


// FUNÇÕES AUXILIARES

void lerTexto(char *texto){
    scanf(" %[^\n]", texto);
}

char lerSexoValido(){
    char sexo;
    do{
        printf("Sexo (M/F): ");
        scanf(" %c", &sexo);
        if(sexo != 'M' && sexo != 'F'){
            printf("Opcao invalida! Digite M ou F.\n");
        }
    } while(sexo != 'M' && sexo != 'F');
    return sexo;
}

int buscarIndiceAluno(Aluno lista[], int total, int matricula){
    for(int i = 0; i < total; i++){
        if(lista[i].matricula == matricula)
            return i;
    }
    return -1;
}

int buscarIndiceProfessor(Professor lista[], int total, int matricula){
    for(int i = 0; i < total; i++){
        if(lista[i].matricula == matricula)
            return i;
    }
    return -1;
}

int compararDatas(Data a, Data b){
    if(a.ano != b.ano) return a.ano - b.ano;
    if(a.mes != b.mes) return a.mes - b.mes;
    return a.dia - b.dia;
}

int cpfValido(char *cpf){
    int len = strlen(cpf);
    if(len != 11) return 0;
    for(int i = 0; i < len; i++){
        if(cpf[i] < '0' || cpf[i] > '9') return 0;
    }
    return 1;
}

int dataValida(int dia, int mes, int ano){
    if(mes < 1 || mes > 12) return 0;
    if(dia < 1 || dia > 31) return 0;
    if(ano < 1900 || ano > 2100) return 0;
    return 1;
}


// CRUD ALUNO

void cadastrarAluno(Aluno lista[], int *total){

    printf("\n--- CADASTRO ALUNO ---\n");

    printf("Matricula: ");
    scanf("%d", &lista[*total].matricula);

    printf("Nome: ");
    lerTexto(lista[*total].nome);

    lista[*total].sexo = lerSexoValido();

    do{
        printf("Data nascimento (dd mm aaaa): ");
        scanf("%d %d %d",
            &lista[*total].dataNascimento.dia,
            &lista[*total].dataNascimento.mes,
            &lista[*total].dataNascimento.ano);
        if(!dataValida(lista[*total].dataNascimento.dia,
                       lista[*total].dataNascimento.mes,
                       lista[*total].dataNascimento.ano)){
            printf("Data invalida! Tente novamente.\n");
        }
    } while(!dataValida(lista[*total].dataNascimento.dia,
                        lista[*total].dataNascimento.mes,
                        lista[*total].dataNascimento.ano));

    do{
        printf("CPF (somente 11 digitos): ");
        lerTexto(lista[*total].cpf);
        if(!cpfValido(lista[*total].cpf)){
            printf("CPF invalido! Digite exatamente 11 numeros.\n");
        }
    } while(!cpfValido(lista[*total].cpf));

    (*total)++;
}

void listarAlunos(Aluno lista[], int total){

    printf("\n--- LISTA DE ALUNOS ---\n");

    for(int i = 0; i < total; i++){
        printf("%d | %s | %c | %02d/%02d/%d\n",
            lista[i].matricula,
            lista[i].nome,
            lista[i].sexo,
            lista[i].dataNascimento.dia,
            lista[i].dataNascimento.mes,
            lista[i].dataNascimento.ano);
    }
}

void atualizarAluno(Aluno lista[], int total){

    int matricula;
    printf("Matricula: ");
    scanf("%d", &matricula);

    int indice = buscarIndiceAluno(lista, total, matricula);

    if(indice == -1){
        printf("Aluno nao encontrado!\n");
        return;
    }

    printf("Novo nome: ");
    lerTexto(lista[indice].nome);

    lista[indice].sexo = lerSexoValido();

    do{
        printf("Nova data (dd mm aaaa): ");
        scanf("%d %d %d",
            &lista[indice].dataNascimento.dia,
            &lista[indice].dataNascimento.mes,
            &lista[indice].dataNascimento.ano);
        if(!dataValida(lista[indice].dataNascimento.dia,
                       lista[indice].dataNascimento.mes,
                       lista[indice].dataNascimento.ano)){
            printf("Data invalida! Tente novamente.\n");
        }
    } while(!dataValida(lista[indice].dataNascimento.dia,
                        lista[indice].dataNascimento.mes,
                        lista[indice].dataNascimento.ano));
}

void excluirAluno(Aluno lista[], int *total){

    int matricula;
    printf("Matricula: ");
    scanf("%d", &matricula);

    int indice = buscarIndiceAluno(lista, *total, matricula);

    if(indice == -1){
        printf("Aluno nao encontrado!\n");
        return;
    }

    for(int i = indice; i < *total - 1; i++){
        lista[i] = lista[i + 1];
    }

    (*total)--;
}


// CRUD PROFESSOR

void cadastrarProfessor(Professor lista[], int *total){

    printf("\n--- CADASTRO PROFESSOR ---\n");

    printf("Matricula: ");
    scanf("%d", &lista[*total].matricula);

    printf("Nome: ");
    lerTexto(lista[*total].nome);

    lista[*total].sexo = lerSexoValido();

    do{
        printf("Data nascimento (dd mm aaaa): ");
        scanf("%d %d %d",
            &lista[*total].dataNascimento.dia,
            &lista[*total].dataNascimento.mes,
            &lista[*total].dataNascimento.ano);
        if(!dataValida(lista[*total].dataNascimento.dia,
                       lista[*total].dataNascimento.mes,
                       lista[*total].dataNascimento.ano)){
            printf("Data invalida! Tente novamente.\n");
        }
    } while(!dataValida(lista[*total].dataNascimento.dia,
                        lista[*total].dataNascimento.mes,
                        lista[*total].dataNascimento.ano));

    do{
        printf("CPF (somente 11 digitos): ");
        lerTexto(lista[*total].cpf);
        if(!cpfValido(lista[*total].cpf)){
            printf("CPF invalido! Digite exatamente 11 numeros.\n");
        }
    } while(!cpfValido(lista[*total].cpf));

    (*total)++;
}

void listarProfessores(Professor lista[], int total){

    printf("\n--- LISTA DE PROFESSORES ---\n");

    for(int i = 0; i < total; i++){
        printf("%d | %s\n", lista[i].matricula, lista[i].nome);
    }
}

void atualizarProfessor(Professor lista[], int total){

    int matricula;
    printf("Matricula: ");
    scanf("%d", &matricula);

    int indice = buscarIndiceProfessor(lista, total, matricula);

    if(indice == -1){
        printf("Professor nao encontrado!\n");
        return;
    }

    printf("Novo nome: ");
    lerTexto(lista[indice].nome);

    lista[indice].sexo = lerSexoValido();

    do{
        printf("Nova data (dd mm aaaa): ");
        scanf("%d %d %d",
            &lista[indice].dataNascimento.dia,
            &lista[indice].dataNascimento.mes,
            &lista[indice].dataNascimento.ano);
        if(!dataValida(lista[indice].dataNascimento.dia,
                       lista[indice].dataNascimento.mes,
                       lista[indice].dataNascimento.ano)){
            printf("Data invalida! Tente novamente.\n");
        }
    } while(!dataValida(lista[indice].dataNascimento.dia,
                        lista[indice].dataNascimento.mes,
                        lista[indice].dataNascimento.ano));
}

void excluirProfessor(Professor lista[], int *total){

    int matricula;
    printf("Matricula: ");
    scanf("%d", &matricula);

    int indice = buscarIndiceProfessor(lista, *total, matricula);

    if(indice == -1){
        printf("Professor nao encontrado!\n");
        return;
    }

    for(int i = indice; i < *total - 1; i++){
        lista[i] = lista[i + 1];
    }

    (*total)--;
}


// DISCIPLINA

void cadastrarDisciplina(Disciplina lista[], int *total){

    printf("\n--- CADASTRO DISCIPLINA ---\n");

    printf("Codigo: ");
    lerTexto(lista[*total].codigo);

    printf("Matricula do professor: ");
    scanf("%d", &lista[*total].matriculaProfessor);

    lista[*total].quantidadeAlunos = 0;

    (*total)++;
}

int alunoJaNaDisciplina(Disciplina d, int matricula){
    for(int i = 0; i < d.quantidadeAlunos; i++){
        if(d.matriculasAlunos[i] == matricula)
            return 1;
    }
    return 0;
}

void inserirAlunoNaDisciplina(Disciplina lista[], int totalDisc, Aluno alunos[], int totalAlunos){

    char codigoDisciplina[20];
    int matriculaAluno;

    printf("Codigo disciplina: ");
    lerTexto(codigoDisciplina);

    for(int i = 0; i < totalDisc; i++){

        if(strcmp(lista[i].codigo, codigoDisciplina) == 0){

            printf("Matricula aluno: ");
            scanf("%d", &matriculaAluno);

            if(buscarIndiceAluno(alunos, totalAlunos, matriculaAluno) == -1){
                printf("Aluno nao existe!\n");
                return;
            }

            if(alunoJaNaDisciplina(lista[i], matriculaAluno)){
                printf("Aluno ja matriculado!\n");
                return;
            }

            lista[i].matriculasAlunos[lista[i].quantidadeAlunos++] = matriculaAluno;
            printf("Aluno inserido!\n");
            return;
        }
    }

    printf("Disciplina nao encontrada!\n");
}

void excluirAlunoDaDisciplina(Disciplina lista[], int totalDisc, Aluno alunos[], int totalAlunos){

    char codigoDisciplina[20];
    int matriculaAluno;

    printf("Codigo disciplina: ");
    lerTexto(codigoDisciplina);

    for(int i = 0; i < totalDisc; i++){

        if(strcmp(lista[i].codigo, codigoDisciplina) == 0){

            printf("Matricula aluno: ");
            scanf("%d", &matriculaAluno);

            if(buscarIndiceAluno(alunos, totalAlunos, matriculaAluno) == -1){
                printf("Aluno nao existe!\n");
                return;
            }

            for(int j = 0; j < lista[i].quantidadeAlunos; j++){
                if(lista[i].matriculasAlunos[j] == matriculaAluno){
                    for(int k = j; k < lista[i].quantidadeAlunos - 1; k++){
                        lista[i].matriculasAlunos[k] = lista[i].matriculasAlunos[k + 1];
                    }
                    lista[i].quantidadeAlunos--;
                    printf("Aluno removido da disciplina!\n");
                    return;
                }
            }

            printf("Aluno nao esta nessa disciplina!\n");
            return;
        }
    }

    printf("Disciplina nao encontrada!\n");
}

// RELATÓRIOS

void relatorioDisciplinasSimples(Disciplina lista[], int total){

    printf("\n--- DISCIPLINAS ---\n");

    for(int i = 0; i < total; i++){
        printf("Codigo: %s | Professor: %d\n",
            lista[i].codigo,
            lista[i].matriculaProfessor);
    }
}

void relatorioDisciplinaCompleta(Disciplina lista[], int totalDisc, Aluno alunos[], int totalAlunos){

    char codigo[20];
    printf("Codigo: ");
    lerTexto(codigo);

    for(int i = 0; i < totalDisc; i++){

        if(strcmp(lista[i].codigo, codigo) == 0){

            printf("\nDisciplina %s\n", codigo);

            for(int j = 0; j < lista[i].quantidadeAlunos; j++){

                int indice = buscarIndiceAluno(alunos, totalAlunos, lista[i].matriculasAlunos[j]);

                if(indice != -1){
                    printf("%s\n", alunos[indice].nome);
                }
            }
            return;
        }
    }

    printf("Disciplina nao encontrada\n");
}

void relatorioAlunosPorSexo(Aluno lista[], int total){

    char sexo = lerSexoValido();

    for(int i = 0; i < total; i++){
        if(lista[i].sexo == sexo){
            printf("%s\n", lista[i].nome);
        }
    }
}

void relatorioAlunosOrdenadosNome(Aluno lista[], int total){

    Aluno temp;

    for(int i = 0; i < total - 1; i++){
        for(int j = 0; j < total - 1 - i; j++){
            if(strcmp(lista[j].nome, lista[j + 1].nome) > 0){
                temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }

    listarAlunos(lista, total);
}

void relatorioAlunosOrdenadosData(Aluno lista[], int total){

    Aluno temp;

    for(int i = 0; i < total - 1; i++){
        for(int j = 0; j < total - 1 - i; j++){
            if(compararDatas(lista[j].dataNascimento, lista[j + 1].dataNascimento) > 0){
                temp = lista[j];
                lista[j] = lista[j + 1];
                lista[j + 1] = temp;
            }
        }
    }

    listarAlunos(lista, total);
}

void relatorioAniversariantes(Aluno lista[], int total){

    int mes;
    printf("Mes: ");
    scanf("%d", &mes);

    for(int i = 0; i < total; i++){
        if(lista[i].dataNascimento.mes == mes){
            printf("%s\n", lista[i].nome);
        }
    }
}

void relatorioBusca(Aluno alunos[], int totalA, Professor profs[], int totalP){

    char busca[50];
    int tipo;

    printf("Buscar: 1-Aluno  2-Professor  3-Ambos: ");
    scanf("%d", &tipo);

    if(tipo < 1 || tipo > 3){
        printf("Opcao invalida!\n");
        return;
    }

    printf("Digite no minimo 3 letras: ");
    lerTexto(busca);

    if(strlen(busca) < 3){
        printf("Entrada invalida!\n");
        return;
    }

    if(tipo == 1 || tipo == 3){
        for(int i = 0; i < totalA; i++){
            if(strstr(alunos[i].nome, busca)){
                printf("Aluno: %s\n", alunos[i].nome);
            }
        }
    }

    if(tipo == 2 || tipo == 3){
        for(int i = 0; i < totalP; i++){
            if(strstr(profs[i].nome, busca)){
                printf("Professor: %s\n", profs[i].nome);
            }
        }
    }
}

void relatorioAlunosMenos3(Aluno alunos[], int totalA, Disciplina disc[], int totalD){

    int encontrou = 0;

    for(int i = 0; i < totalA; i++){

        int contador = 0;

        for(int j = 0; j < totalD; j++){
            for(int k = 0; k < disc[j].quantidadeAlunos; k++){
                if(disc[j].matriculasAlunos[k] == alunos[i].matricula){
                    contador++;
                }
            }
        }

        if(contador > 0 && contador < 3){
            printf("%s (%d disciplinas)\n", alunos[i].nome, contador);
            encontrou = 1;
        }
    }

    if(!encontrou){
        printf("Nenhum aluno com menos de 3 disciplinas.\n");
    }
}

void relatorioDisciplinasLotadas(Disciplina disc[], int totalD, Professor profs[], int totalP){

    int encontrou = 0;

    for(int i = 0; i < totalD; i++){

        if(disc[i].quantidadeAlunos > 40){

            int indiceProf = buscarIndiceProfessor(profs, totalP, disc[i].matriculaProfessor);

            printf("Disciplina %s | Professor: %s | Alunos: %d\n",
                disc[i].codigo,
                indiceProf != -1 ? profs[indiceProf].nome : "Nao encontrado",
                disc[i].quantidadeAlunos);

            encontrou = 1;
        }
    }

    if(!encontrou){
        printf("Nenhuma disciplina lotada.\n");
    }
}

// MENU RELATÓRIOS

void menuRelatorios(Aluno alunos[], int totalA, Professor profs[], int totalP, Disciplina disc[], int totalD){

    int opcao;

    do{
        printf("\n--- RELATORIOS ---\n");
        printf("1-Disciplinas simples\n");
        printf("2-Disciplina completa\n");
        printf("3-Alunos por sexo\n");
        printf("4-Alunos por nome\n");
        printf("5-Alunos por data\n");
        printf("6-Aniversariantes\n");
        printf("7-Busca\n");
        printf("8-Alunos <3 disciplinas\n");
        printf("9-Disciplinas lotadas\n");
        printf("0-Voltar\n");

        scanf("%d", &opcao);

        switch(opcao){
            case 1: relatorioDisciplinasSimples(disc, totalD); break;
            case 2: relatorioDisciplinaCompleta(disc, totalD, alunos, totalA); break;
            case 3: relatorioAlunosPorSexo(alunos, totalA); break;
            case 4: relatorioAlunosOrdenadosNome(alunos, totalA); break;
            case 5: relatorioAlunosOrdenadosData(alunos, totalA); break;
            case 6: relatorioAniversariantes(alunos, totalA); break;
            case 7: relatorioBusca(alunos, totalA, profs, totalP); break;
            case 8: relatorioAlunosMenos3(alunos, totalA, disc, totalD); break;
            case 9: relatorioDisciplinasLotadas(disc, totalD, profs, totalP); break;
        }

    }while(opcao != 0);
}

// MAIN

int main(){

    Aluno alunos[MAX_ALUNOS];
    Professor professores[MAX_PROFESSORES];
    Disciplina disciplinas[MAX_DISCIPLINAS];

    int totalAlunos = 0;
    int totalProfessores = 0;
    int totalDisciplinas = 0;

    int opcao;

    do{
        printf("\n1-Aluno\n2-Professor\n3-Disciplina\n4-Relatorios\n0-Sair\n");
        scanf("%d", &opcao);

        switch(opcao){

            case 1:{
                int op;
                do{
                    printf("\n1-Cadastrar\n2-Listar\n3-Atualizar\n4-Excluir\n0-Voltar\n");
                    scanf("%d", &op);

                    if(op==1) cadastrarAluno(alunos,&totalAlunos);
                    if(op==2) listarAlunos(alunos,totalAlunos);
                    if(op==3) atualizarAluno(alunos,totalAlunos);
                    if(op==4) excluirAluno(alunos,&totalAlunos);

                }while(op!=0);
                break;
            }

            case 2:{
                int op;
                do{
                    printf("\n1-Cadastrar\n2-Listar\n3-Atualizar\n4-Excluir\n0-Voltar\n");
                    scanf("%d", &op);

                    if(op==1) cadastrarProfessor(professores,&totalProfessores);
                    if(op==2) listarProfessores(professores,totalProfessores);
                    if(op==3) atualizarProfessor(professores,totalProfessores);
                    if(op==4) excluirProfessor(professores,&totalProfessores);

                }while(op!=0);
                break;
            }

            case 3:{
                int op;
                do{
                    printf("\n1-Cadastrar\n2-Inserir aluno\n3-Listar\n4-Excluir aluno\n0-Voltar\n");
                    scanf("%d", &op);

                    if(op==1) cadastrarDisciplina(disciplinas,&totalDisciplinas);
                    if(op==2) inserirAlunoNaDisciplina(disciplinas,totalDisciplinas,alunos,totalAlunos);
                    if(op==3) relatorioDisciplinasSimples(disciplinas,totalDisciplinas);
                    if(op==4) excluirAlunoDaDisciplina(disciplinas,totalDisciplinas,alunos,totalAlunos);

                }while(op!=0);
                break;
            }

            case 4:
                menuRelatorios(alunos,totalAlunos,professores,totalProfessores,disciplinas,totalDisciplinas);
                break;
        }

    }while(opcao != 0);

    return 0;
}