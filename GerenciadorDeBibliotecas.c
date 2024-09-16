/*
Exercício 2. Faça um programa em Linguagem C para controlar o cadastro e consulta aos livros de
uma livraria online. Cada livro possui: código, título, primeiro autor, editora, ano de publicação e
preço. Elabore um menu com as opções de Cadastro de livro, Consulta do livro por código ou
título, Consulta de livros com preço inferior ao informado pelo usuário, Consultar o número de
livros cadastrados de um autor escolhido pelo usuário, Relatório de livros (mostrar todos os livros
cadastrados) e Sair do programa.
Observação: O programa poderá armazenar até 50 livros.
Atenção: utilize o conceito de registro (struct) e funções para refinar, organizar e otimizar seu
código.
certo certo
*/

#define maximo 50

typedef struct {
    int codigo;
    char titulo[50];
    char primeiroAutor[50];
    char editora[50];
    int anoPublicacao;
    float preco;
} livro;

//1
void cadastro(livro livroIndvidual[maximo], int qtd);
//2
void colsutarPorCodigoTitulo(livro livroIndvidual[maximo], int qtd);

//3
void colsutarPorValorMaximo(livro livroIndvidual[maximo], int qtd, float filtroValor);

//4
void colsutarPorAutor(livro livroIndvidual[maximo], int qtd);

//5
void mostrarTudo(livro livroIndvidual[maximo], int qtd);

//6 sair

void main(){
    livro livroIndividual[maximo];
    int opcao = -1, numDeLivros = -1;
    float valorFiltroMaximo;


    do
    {
        printf("\nBem vindo ao menu da livraria");
        printf("\n[1] cadastro de livros");
        printf("\n[2] colsutar livros por codigo ou titulo");
        printf("\n[3] filtrar livros por um valor");
        printf("\n[4] colsutar os livros de um autor");
        printf("\n[5] mostrar todos os livros");
        printf("\n[6] Sair");
        printf("\nEscolha: ");
        scanf("%d", &opcao);
        
        if(opcao == 1){
            numDeLivros++; cadastro(livroIndividual, numDeLivros);
        }

        if(opcao == 2){
            colsutarPorCodigoTitulo(livroIndividual, numDeLivros);
        }

        if(opcao == 3){
            printf("\nQual o valor maximo para filtrar os livros: ");
            scanf("%f", &valorFiltroMaximo);
            colsutarPorValorMaximo(livroIndividual, numDeLivros, valorFiltroMaximo);
        }

        if(opcao == 4){
            
            colsutarPorAutor(livroIndividual, numDeLivros);
        }

        if(opcao == 5) {
            mostrarTudo(livroIndividual, numDeLivros);
        }
        
        } while (opcao != 6);
}

//1 cadastro
void cadastro(livro livroIndvidual[maximo], int qtd){
    int erro;
    int codigoReserva;

    // falta fazer para nao poder repetir o livro no codigo
    do {
        printf("\nQual o codigo do livro: ");
        scanf("%d", &codigoReserva);
        erro = 0;       
        for (int i = 0; i <= qtd; i++){         
            if(livroIndvidual[i].codigo == codigoReserva){
                printf("\nErro ja existe esse codigo\n");
                erro = 1;
                i = qtd;
            } 
        }
    } while (erro);
    
    livroIndvidual[qtd].codigo = codigoReserva;

    printf("\nQual o titulo do livro: ");
    scanf("%s", &livroIndvidual[qtd].titulo);
    printf("\nQual o primeiro autor do livro: ");
    scanf("%s", &livroIndvidual[qtd].primeiroAutor);
    printf("\nQual a editora do livro: ");
    scanf("%s", &livroIndvidual[qtd].editora);
    printf("\nQual o ano de publicacao do livro: ");
    scanf("%d", &livroIndvidual[qtd].anoPublicacao);
    printf("\nQual o preco do livro: ");
    scanf("%f", &livroIndvidual[qtd].preco);   
    
}


//2 colsutarPorCodigoTitulo
void colsutarPorCodigoTitulo(livro livroIndvidual[maximo], int qtd){
    int opcaoPorTituloOuCodigo = -1;
    do{
        
        printf("\nDigite [1] para pesquisar por codigo do livro ou [2] por titulo: ");
        scanf("%d", &opcaoPorTituloOuCodigo);

    } while (opcaoPorTituloOuCodigo < 1 || opcaoPorTituloOuCodigo > 2);

    //por codigo
    if(opcaoPorTituloOuCodigo == 1){
        int codigoLivro = -1, existeCodigoLivro = -1;
        do{
            printf("\nDigite o codigo do livro ");
            scanf("%d", &codigoLivro);
            existeCodigoLivro = 1;
            
            for (int i = 0; i <= qtd; i++){
                if(codigoLivro == livroIndvidual[i].codigo){
                    printf("\nCodigo: %d Titulo: %s Primeiro Autor: %s Editora: %s Ano de publicacao: %d Preco: %.2f\n", livroIndvidual[i].codigo, livroIndvidual[i].titulo, livroIndvidual[i].primeiroAutor, livroIndvidual[i].editora, livroIndvidual[i].anoPublicacao, livroIndvidual[i].preco);
                    existeCodigoLivro = 0;
                }
            }  
        } while (existeCodigoLivro);       
    }

    // por titulo
    else if(opcaoPorTituloOuCodigo == 2){
        int achouTitulo = 0;
        char titulo[30];
        
        do{
            printf("\nDigite o titulo que esta buscando: ");
            scanf("%s", &titulo);
            achouTitulo = 1;
            for (int i = 0; i <= qtd; i++){
                if(strcmp(titulo, livroIndvidual[i].titulo) == 0){
                    printf("\nCodigo: %d Titulo: %s Primeiro Autor: %s Editora: %s Ano de publicacao: %d Preco: %.2f\n", livroIndvidual[i].codigo, livroIndvidual[i].titulo, livroIndvidual[i].primeiroAutor, livroIndvidual[i].editora, livroIndvidual[i].anoPublicacao, livroIndvidual[i].preco);
                    achouTitulo = 0;
                    getchar();
                    i = qtd;
                }
            }
        } while (achouTitulo);
    
    }
}


//3 filtrar livros por um valor
void colsutarPorValorMaximo(livro livroIndvidual[maximo], int qtd, float filtroValor){
    int encontrou = 0;
    for (int i = 0; i <= qtd; i++){
        if(livroIndvidual[i].preco < filtroValor){
            encontrou++;
            printf("\nCodigo: %d Titulo: %s Primeiro Autor: %s Editora: %s Ano de publicacao: %d Preco: %.2f\n", livroIndvidual[i].codigo, livroIndvidual[i].titulo, livroIndvidual[i].primeiroAutor, livroIndvidual[i].editora, livroIndvidual[i].anoPublicacao, livroIndvidual[i].preco);
        }
    }
    if(encontrou == 0){
        printf("\nNao temos livros abaixou desse preço\n");
    }
}


//4 colsutar os livros de um autor
void colsutarPorAutor(livro livroIndvidual[maximo], int qtd) {
    int achouAutor;
    char autor[50];


    printf("\nDigite o Autor que está buscando: ");
    scanf(" %[^\n]s", autor);  

    for (int i = 0; i <= qtd; i++) { 
        if(strcmp(autor, livroIndvidual[i].primeiroAutor) == 0) {
            printf("\nCodigo: %d Titulo: %s Primeiro Autor: %s Editora: %s Ano de publicacao: %d Preco: %.2f\n", livroIndvidual[i].codigo, livroIndvidual[i].titulo, livroIndvidual[i].primeiroAutor, livroIndvidual[i].editora, livroIndvidual[i].anoPublicacao, livroIndvidual[i].preco);
            achouAutor++;       
        }
    }
        if(achouAutor == 0){
            printf("\nNao foi encontrado");
        }
    
    
}


//5 mostrarTudo
void mostrarTudo(livro livroIndvidual[maximo], int qtd){
    for (int i = 0; i <= qtd; i++){
        printf("\nlivro = %d", i);
        printf("\nCodigo: %d", livroIndvidual[i].codigo);
        printf("\nTitulo: %s",livroIndvidual[i].titulo);
        printf("\nPrimeiro Autor: %s",livroIndvidual[i].primeiroAutor);
        printf("\nEditora: %s",livroIndvidual[i].editora);
        printf("\nAno de Publicacao: %d",livroIndvidual[i].anoPublicacao);
        printf("\nPreco: %.2f\n\n",livroIndvidual[i].preco);   

    }
    
}