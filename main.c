#include <stdio.h>
#include <stdlib.h>

typedef struct _personagem
{
    int id;
    char nome[20];
    char papel[20];
} Personagem;

typedef struct _filme
{
    int id;
    char nome[20];
    char genero[20];
    int ano_lancamento;
    int classificacao_indicativa;
    Personagem *personagens[20];
    int numPersonagens;
} Filme;

typedef struct _ator
{
    int id;
    char nome[20];
    char nacionalidade[20];
    int ano_nasc;
    Filme *filmes[20];
    int numFilmes;
} Ator;

Ator cadastrarAtor(int idAtor)
{
    Ator novoAtor;
    novoAtor.id = idAtor;
    printf("Nome do Ator: ");
    scanf(" %[^\n]s", novoAtor.nome);
    printf("Pais de nascimento do Ator: ");
    scanf(" %[^\n]s", novoAtor.nacionalidade);
    printf("Ano de Nascimento do Ator: ");
    scanf(" %d", &novoAtor.ano_nasc);

    novoAtor.numFilmes = 0;

    return novoAtor;
}

void listarAtores(Ator *atores[], int numAtores)
{
    for (int i = 0; i < numAtores; i++)
    {
        printf("\nId: %d\n", atores[i]->id);
        printf("Nome: %s\n", atores[i]->nome);
        printf("Nacionalidade: %s\n", atores[i]->nacionalidade);
        printf("Ano de Nascimento: %d\n", atores[i]->ano_nasc);
        printf("Numero de Filmes: %d\n", atores[i]->numFilmes);
    }

    printf("\n\n");
}

Filme cadastrarFilme(int idFilme)
{
    Filme novoFilme;
    novoFilme.id = idFilme;
    printf("Titulo do Filme: ");
    scanf(" %[^\n]s", novoFilme.nome);
    printf("Genero do Filme: ");
    scanf(" %[^\n]s", novoFilme.genero);
    printf("Ano de lancamento do Filme: ");
    scanf("%d", &novoFilme.ano_lancamento);
    printf("Classificacao Indicativa do Filme: ");
    scanf("%d", &novoFilme.classificacao_indicativa);

    novoFilme.numPersonagens = 0;

    return novoFilme;
}

void listarFilmes(Filme *filmes[], int numFilmes)
{
    for (int i = 0; i < numFilmes; i++)
    {
        printf("\nId: %d\n", filmes[i]->id);
        printf("Titulo: %s\n", filmes[i]->nome);
        printf("Genero: %s\n", filmes[i]->genero);
        printf("Ano de Lancamento: %d\n", filmes[i]->ano_lancamento);
        printf("Classificacao Indicativa: %d\n", filmes[i]->classificacao_indicativa);
        printf("Numero de Personagens: %d\n", filmes[i]->numPersonagens);
    }

    printf("\n\n");
}

void listarAtoresComFilmes(Ator *atores[], int numAtores)
{
    for (int i = 0; i < numAtores; i++)
    {
        printf("\nId: %d\n", atores[i]->id);
        printf("Nome: %s\n", atores[i]->nome);
        printf("Nacionalidade: %s\n", atores[i]->nacionalidade);
        printf("Ano de Nascimento: %d\n", atores[i]->ano_nasc);
        printf("Numero de Filmes: %d\n", atores[i]->numFilmes);

        listarFilmes(atores[i]->filmes, atores[i]->numFilmes);
    }

    printf("\n\n");
}

Personagem cadastrarPersonagem(int idPersonagem)
{
    Personagem novoPersonagem;
    novoPersonagem.id = idPersonagem;
    printf("Nome do Personagem: ");
    scanf(" %[^\n]s", novoPersonagem.nome);
    printf("Papel do Personagem: ");
    scanf(" %[^\n]s", novoPersonagem.papel);

    return novoPersonagem;
}

void listarPersonagens(Personagem *personagens[], int numPersonagens)
{
    for (int i = 0; i < numPersonagens; i++)
    {
        printf("\nId: %d\n", personagens[i]->id);
        printf("Nome: %s\n", personagens[i]->nome);
        printf("Papel: %s\n", personagens[i]->papel);
    }

    printf("\n\n");
}

void listarFilmesComPersonagens(Filme *filmes[], int numFilmes)
{
    for (int i = 0; i < numFilmes; i++)
    {
        printf("\nId: %d\n", filmes[i]->id);
        printf("Titulo: %s\n", filmes[i]->nome);
        printf("Genero: %s\n", filmes[i]->genero);
        printf("Ano de Lancamento: %d\n", filmes[i]->ano_lancamento);
        printf("Classificacao Indicativa: %d\n", filmes[i]->classificacao_indicativa);
        printf("Numero de Personagens: %d\n", filmes[i]->numPersonagens);

        listarPersonagens(filmes[i]->personagens, filmes[i]->numPersonagens);
    }

    printf("\n\n");
}

void adicionarFilmeAtor(Ator *ator, Filme *filme)
{
    ator->filmes[ator->numFilmes] = filme;
    ator->numFilmes++;
}

void adicionarPersonagemFilme(Filme *filme, Personagem *personagem)
{
    filme->personagens[filme->numPersonagens] = personagem;
    filme->numPersonagens++;
}

int main()
{

    Ator *atores[20];
    Filme *filmes[20];
    Personagem *personagens[20];
    int op = 1.0;
    int numAtores = 0, numFilmes = 0, numPersonagens = 0;
    int idFilme, idAtor, idPersonagem;

    while (op != 0)
    {

        printf("1 - Inserir novo Ator\n");
        printf("2 - Listar Atores\n");
        printf("3 - Inserir novo Filme\n");
        printf("4 - Listar Filmes\n");
        printf("5 - Inserir Novo Personagem\n");
        printf("6 - Listar Personagens\n");
        printf("7 - Adicionar Filme para Ator\n");
        printf("8 - Adicionar Personagem para Filme\n");
        printf("9 - Listar Ator com Filme\n");
        printf("10 - Listar Filme com Personagem\n");
        printf("0 - Sair\n");
        scanf("%d", &op);
        system("cls");

        switch (op)
        {
        case 1:
            atores[numAtores] = (Ator *)malloc(sizeof(Ator));
            *atores[numAtores] = cadastrarAtor(numAtores);
            numAtores++;

            system("cls");
            printf("Operacao Concluida com sucesso!\n\n");

            break;

        case 2:

            if (numAtores > 0)
            {
                printf("ATORES CADASTRADOS:\n");
                listarAtores(atores, numAtores);
            }

            break;

        case 3:
            filmes[numFilmes] = (Filme *)malloc(sizeof(Filme));
            *filmes[numFilmes] = cadastrarFilme(numFilmes);
            numFilmes++;

            system("cls");
            printf("Operacao Concluida com sucesso!\n\n");

            break;

        case 4:

            if (numFilmes > 0)
            {
                printf("FILMES CADASTRADOS:\n");
                listarFilmes(filmes, numFilmes);
            }

            break;

        case 5:
            personagens[numPersonagens] = (Personagem *)malloc(sizeof(Personagem));
            *personagens[numPersonagens] = cadastrarPersonagem(numPersonagens);
            numPersonagens++;

            system("cls");
            printf("Operacao Concluida com sucesso!\n\n");

            break;

        case 6:

            if (numPersonagens > 0)
            {
                printf("PERSONAGENS CADASTRADOS:\n");
                listarPersonagens(personagens, numPersonagens);
            }

            break;

        case 7:

            if (numFilmes > 0 && numAtores > 0)
            {
                listarFilmes(filmes, numFilmes);
                printf("\nDigite o id do filme: ");
                scanf("%d", &idFilme);
                system("cls");

                listarAtores(atores, numAtores);
                printf("\nDigite o id do ator: ");
                scanf("%d", &idAtor);

                adicionarFilmeAtor(atores[idAtor], filmes[idFilme]);
                system("cls");
                printf("Operacao Concluida com sucesso!\n\n");
            }

            break;

        case 8:

            if (numPersonagens > 0 && numFilmes > 0)
            {
                listarPersonagens(personagens, numPersonagens);
                printf("\nDigite o id do personagem: ");
                scanf("%d", &idPersonagem);
                system("cls");

                listarFilmes(filmes, numFilmes);
                printf("\nDigite o id do filme: ");
                scanf("%d", &idFilme);

                adicionarPersonagemFilme(filmes[idFilme], personagens[idPersonagem]);
                system("cls");
                printf("Operacao Concluida com sucesso!\n\n");
            }

            break;

        case 9:

            if (numAtores > 0 && numFilmes > 0)
            {
                printf("LISTA DE ATORES E FILMES EM QUE ATUARAM:\n");
                listarAtoresComFilmes(atores, numAtores);
            }

            break;

        case 10:

            if (numFilmes > 0 && numPersonagens > 0)
            {
                printf("LISTA DE FILMES E SEUS PERSONAGENS:\n");
                listarFilmesComPersonagens(filmes, numFilmes);
            }

            break;

        case 0:
            op == 0;
            system("cls");

            break;

        default:
            printf("Operacao Invalida\n");
            break;
        }
    }

    return 0;
}
