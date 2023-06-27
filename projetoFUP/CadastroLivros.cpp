#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iomanip> // Biblioteca para manipulação de formatação

using namespace std;

const int maxLinhas = 10; // const indica que o valor da variável não pode ser alterado depois de atribuído

string idLivro[maxLinhas] = {};
string tituloLivro[maxLinhas] = {};
string nomeAutor[maxLinhas] = {};
string generoLivro[maxLinhas] = {};
string anoPublicacao[maxLinhas] = {};

void AbrirArquivo()//funcao com problema , explico na hora da apresentação!!!
{
    string linhas; // a armazenar cada linha do arquivo de texto

    ifstream arquivo("C:\\Users\\meloa\\OneDrive\\Documentos\\projetoFUP\\livros.txt"); // arquivo de texto que será aberto para leitura

    if (arquivo.is_open()) { // verifica se o arquivo está aberto

        int x = 0;
        while (getline(arquivo, linhas)){ // lê cada linha do arquivo de texto e a armazena na variável linhas usando a função getline()

            if (linhas.empty()){
                continue; // Ignora a linha vazia e vai para a próxima iteração do loop
            }

            int comp = linhas.length(); //armazena o compirmento da linha
            idLivro[x] = linhas.substr(0, 3);// extrai uma substring da linha

            if (comp >= 5){//verifica se o comprimento da linha é maior ou igual a 5
                tituloLivro[x] = linhas.substr(4, comp - 5);
                nomeAutor[x] = linhas.substr(6, comp - 32);
                generoLivro[x] = linhas.substr(30, comp - 35);
                anoPublicacao[x] = linhas.substr(36, comp - 35);

            }else {
                tituloLivro[x] = "";
                nomeAutor[x] = "";
                generoLivro[x] = "";
                anoPublicacao[x] = ""; // Define um valor padrão para o título caso a linha não tenha tamanho suficiente
            }

            x++;
        }

    }else {
        cout << "Erro ao abrir o Arquivo" << endl;
    }
}

void CadastarLivro()
{

    #ifdef _WIN32      // testa se o so é windows, se for windows, executa o comando: system("CLS");
    system("CLS"); // limpar a tela do console.

    #else // se o so for  Unix/Linux, executa o comando: system("clear");
    system("clear");         //// limpar a tela do console.
    #endif

    char id[5];
    char titulo[50];
    char autor[50];
    char genero[50];
    char ano[5];

    cin.ignore(); // limpa o buffer de entrada após a leitura de dados.

    cout << "Id do Livro: ";
    cin.getline(id, 5);

    cout << "Titulo do Livro: ";
    cin.getline(titulo, 100);

    cout << "Autor do Livro: ";
    cin.getline(autor, 50);

    cout << "Genero do Livro: ";
    cin.getline(genero, 10);

    cout << "Ano de publicacao do Livro: ";
    cin.getline(ano, 5);

    for (int i = 0; i < maxLinhas; i++)//percorre as linhas da tabela
    {

        if (idLivro[i] == "\0")
        {

            idLivro[i] = id;
            tituloLivro[i] = titulo;
            nomeAutor[i] = autor;
            generoLivro[i] = genero;
            anoPublicacao[i] = ano;

            cout << "Livro cadastrado com sucesso" << endl;
            break;
        }
    }
}

void VisualizarLivros()
{

    #ifdef _WIN32      // testa se o so é windows, se for windows, executa o comando: system("CLS");
    system("CLS"); // limpar a tela do console.

    #else // se o so for  Unix/Linux, executa o comando: system("clear");
    system("clear");         //// limpar a tela do console.
    #endif

    //cria uma tabela para mostrar os livros cadastrados
    cout << "Livos Cadastrados" << endl;
    cout << "-------------------------" << endl;

    cout << " No. |  ID Livro  |       Titulo do Livro       |   Nome do Autor   |   Genero do Livro   |  Ano  |" << endl
         << "----------------------------------------------------------------------------------------------------\n";

    int cont = 0;
    for (int i = 0; i < maxLinhas; i++)
    {

        if (idLivro[i] != "\0")
        {

            cont++;
            //preenche a tabela com os dados dos livros cadastardos pelo usuario
            cout << setw(4) << cont
                      << " | " << setw(10) << idLivro[i]
                      << " | " << setw(24) << tituloLivro[i]
                      << " | " << setw(17) << nomeAutor[i]
                      << " | " << setw(19) << generoLivro[i]
                      << " | " << setw(6) << anoPublicacao[i]
                      << " |" << endl;
                      //setw() = usado para especificar a largura do campo de exibição de cada valor.
        }
    }

    if (cont == 0)
    {
        cout << "Livro nao encontrado" << endl;
    }
}

void PesquisarLivro(string pesquisa)
{

    #ifdef _WIN32      // testa se o so é windows, se for windows, executa o comando: system("CLS");
    system("CLS"); // limpar a tela do console.

    #else // se o so for  Unix/Linux, executa o comando: system("clear");
    system("clear");         //// limpar a tela do console.
    #endif

    cout << "Livro" << endl;
    cout << "-------------------------" << endl;
    cout << " No. |  ID Livro  |       Titulo do Livro       |   Nome do Autor   |   Genero do Livro   |  Ano  |" << endl
         << "----------------------------------------------------------------------------------------------------\n";

    int cont = 0;
    for (int i = 0; i < maxLinhas; i++)
    {

        if (idLivro[i] == pesquisa)
        {

            cont++;
            cout << setw(4) << cont
                      << " | " << setw(10) << idLivro[i]
                      << " | " << setw(24) << tituloLivro[i]
                      << " | " << setw(17) << nomeAutor[i]
                      << " | " << setw(19) << generoLivro[i]
                      << " | " << setw(6) << anoPublicacao[i]
                      << " |" << endl;

            break;
        }
    }

    if (cont == 0)
    {
        cout << "Livro nao Encontrado" << endl;
    }
}

void AtualizarLivro(string atualizar)
{

    int opcaoAtualizar;
    int cont = 0;

    #ifdef _WIN32      // testa se o so é windows, se for windows, executa o comando: system("CLS");
    system("CLS"); // limpar a tela do console.

    #else // se o so for  Unix/Linux, executa o comando: system("clear");
    system("clear");         //// limpar a tela do console.
    #endif

    char id[5];
    char titulo[50];
    char autor[50];
    char genero[50];
    char ano[5];

    cout << " No. |  ID Livro  |       Titulo do Livro       |   Nome do Autor   |   Genero do Livro   |  Ano  |" << endl;
    cout << "----------------------------------------------------------------------------------------------------\n"
         << endl;

    for (int i = 0; i < maxLinhas; i++)
    {

        if (idLivro[i] == atualizar)
        {

            cont++;
            cout << setw(4) << cont
                      << " | " << setw(10) << idLivro[i]
                      << " | " << setw(24) << tituloLivro[i]
                      << " | " << setw(17) << nomeAutor[i]
                      << " | " << setw(19) << generoLivro[i]
                      << " | " << setw(6) << anoPublicacao[i]
                      << " |" << endl;

            break;
        }
    }

    //menu para a escolha do valor que o usuario que atualizar
    cout << "----------------------------------------------------------------------------------------------------\n"
         << endl;

    cout << "1-Id do livro" << endl;
    cout << "2-Titulo do livro" << endl;
    cout << "3-Autor do livro" << endl;
    cout << "4-Genero do livro" << endl;
    cout << "5-Ano de Publicacao do livro" << endl;

    cout << "----------------------------------------------------------------------------------------------------\n"
         << endl;

    cout << "Escolher a informacao do livro que deseja atualizar: ";
    cin >> opcaoAtualizar;

    cin.ignore();

    switch (opcaoAtualizar)
    {
    case 1:
        for (int i = 0; i < maxLinhas; i++)
        {

            if (idLivro[i] == atualizar)
            {
                cont++;

                cout << "Novo Id: ";
                cin.getline(id, 5);

                idLivro[i] = id;

                cout << "Id Atualizado com sucesso" << endl;
                break;
            }
        }
        break;

    case 2:
        for (int i = 0; i < maxLinhas; i++)
        {

            if (idLivro[i] == atualizar)
            {
                cont++;

                cout << "Novo Titulo: ";
                cin.getline(titulo, 50);

                tituloLivro[i] = titulo;

                cout << "Titulo Atualizado com sucesso" << endl;
                break;
            }
        }
        break;

    case 3:
        for (int i = 0; i < maxLinhas; i++)
        {

            if (idLivro[i] == atualizar)
            {
                cont++;

                cout << "Novo Autor: ";
                cin.getline(autor, 50);

                nomeAutor[i] = autor;

                cout << "Nome do Autor Atualizado com sucesso" << endl;
                break;
            }
        }
        break;

    case 4:
        for (int i = 0; i < maxLinhas; i++)
        {

            if (idLivro[i] == atualizar)
            {
                cont++;

                cout << "Novo Genero do Livro: ";
                cin.getline(genero, 50);

                generoLivro[i] = genero;

                cout << "Genero do Livro Atualizado com sucesso" << endl;
                break;
            }
        }
        break;

    case 5:
        for (int i = 0; i < maxLinhas; i++)
        {

            if (idLivro[i] == atualizar)
            {
                cont++;

                cout << "Novo Ano de Publlicacao: ";
                cin.getline(ano, 5);

                anoPublicacao[i] = ano;

                cout << "Ano de Publicacao Atualizado com sucesso" << endl;
                break;
            }
        }

    default:
        break;
    }

    if (cont == 0)
    {
        cout << "Id do Livro nao encontrado" << endl;
    }
}

void Excluirlivro(string excluir)
{

    #ifdef _WIN32      // testa se o so é windows, se for windows, executa o comando: system("CLS");
    system("CLS"); // limpar a tela do console.

    #else // se o so for  Unix/Linux, executa o comando: system("clear");
    system("clear");         //// limpar a tela do console.
    #endif

    int cont = 0;

    for (int i = 0; i < maxLinhas; i++)
    {

        if (idLivro[i] == excluir)
        {

            cont++;

            idLivro[i] = "";
            tituloLivro[i] = "";
            nomeAutor[i] = "";
            generoLivro[i] = "";
            anoPublicacao[i] = "";
            anoPublicacao[i] = "";

            cout << "Livro excluido com sucesso" << endl;
            break;
        }
    }

    if (cont == 0)
    {
        cout << "livro não encontrado" << endl;
    }
}

void SalvarArquivo()
{

    ofstream arquivo;

    arquivo.open("C:\\Users\\meloa\\OneDrive\\Documentos\\projetoFUP\\livros.txt");

    for (int i = 0; i < maxLinhas; i++)
    {

        if (idLivro[i] == "\0")
        {

            break;
        }
        else
        {

            arquivo << idLivro[i] << "\t" << tituloLivro[i] << "\t" << nomeAutor[i] << "\t" << generoLivro[i] << "\t" << anoPublicacao[i] << endl;
            //"\t" =  convenção usada para separar os campos de dados
        }
    }
}

int main()
{

    cout << "MENU\n";
    int opcao; // armazena a operação(cadastrar, visualizar/pesquisar, atualizar, excluir) escolhida pelo usuario
    string id;

    #ifdef _WIN32// testa se o so é windows, se for windows, executa o comando: system("CLS");
    system("CLS"); // limpar a tela do console.

    #else // se o so for  Unix/Linux, executa o comando: system("clear");
    system("clear");// limpar a tela do console.
    #endif

    AbrirArquivo();

    do
    {

        cout << "-------------------------" << endl;
        cout << "1-Cadastrar novo Livro" << endl;
        cout << "2-Atualizar informacoes do Livro" << endl;
        cout << "3-Deletar Livro" << endl;
        cout << "4-Pesquisar Livro" << endl;
        cout << "5-Visualizar Livros" << endl;
        cout << "6-Sair e Salvar" << endl; // função para salvar dados em um arquivo de texto

        cout << "-------------------------" << endl;

        cout << "Escolher opcao:" << endl;
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            CadastarLivro();
            // cin.ignore();

            #ifdef _WIN32              // testa se o so é windows, se for windows, executa o comando: system("CLS");
            system("CLS"); // limpar a tela do console.

            #else // se o so for  Unix/Linux, executa o comando: system("clear");
            system("clear"); //// limpar a tela do console.
            #endif

            break;

        case 2:
            cin.ignore();
            cout << "Digite o Id do livro que deseja atualizar as informacoes: ";
            getline(cin, id);
            AtualizarLivro(id);

            #ifdef _WIN32              // testa se o so é windows, se for windows, executa o comando: system("CLS");
            system("CLS"); // limpar a tela do console.

            #else // se o so for  Unix/Linux, executa o comando: system("clear");
            system("clear"); //// limpar a tela do console.
            #endif

            break;

        case 3:
            cin.ignore();
            cout << "Digite o id do livro que deseja excluir: ";
            getline(cin, id);
            Excluirlivro(id);
            cin.ignore();

            #ifdef _WIN32              // testa se o so é windows, se for windows, executa o comando: system("CLS");
            system("CLS"); // limpar a tela do console.

            #else // se o so for  Unix/Linux, executa o comando: system("clear");
            system("clear"); //// limpar a tela do console.
            #endif

            break;

        case 4:
            cin.ignore();
            cout << "Digite o Id do livro que procura: ";
            getline(cin, id);
            PesquisarLivro(id);
            break;

        case 5:
            VisualizarLivros();
            break;

        default:
            break;
        }

    } while (opcao != 6);

    SalvarArquivo();
    cout << "Saindo... Livros salvos no arquivo de texto!" << endl;

    return 0;
}