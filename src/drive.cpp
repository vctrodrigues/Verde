#include "../include/verde.hpp"

#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>

using namespace verde;

#define BRD "\033[1;31m"
#define GRN "\033[0;32m"
#define BLU "\033[0;34m"
#define RST "\033[0m"

void printMenu();
void readTree(const char *path, AVL &tree);
int enterCommandsMode(AVL &tree);

int main(int argc, char *argv[])
{

  if (argc > 2)
  {
    int idx = 1;
    if (strcmp(argv[1], "--commands") == 0 || strcmp(argv[1], "-commands") == 0 || strcmp(argv[1], "--c") == 0 || strcmp(argv[1], "-c") == 0)
    {
      idx = 2;
    }

    //Creating tree
    AVL tree;
    readTree(argv[idx], tree);

    //Commands mode
    return enterCommandsMode(tree);
  }
  else if (argc > 1)
  {

    if (strcmp(argv[1], "--commands") == 0 || strcmp(argv[1], "-commands") == 0 || strcmp(argv[1], "--c") == 0 || strcmp(argv[1], "-c") == 0)
    {
      //Commands mode
      AVL tree;
      return enterCommandsMode(tree);
    }
    else
    {
      //Creating tree
      AVL tree;
      readTree(argv[1], tree);
    }
  }
  else
  {
    std::cout << BRD
              << ">>> ERRO: Comandos insuficientes.\n"
              << GRN
              << "\n    Use:" << RST << "\n    ./bin/verde <arquivo_entrada>\n    ./bin/verde -commands\n    ./bin/verde --c"
              << std::endl;
  }

  std::cout << GRN << ">>> Finalizando o programa..." << RST << std::endl;
}

void printMenu()
{
  std::cout << GRN << ">>> Modo de comandos..." << RST << std::endl;

  std::cout << GRN << "    {" << BLU " insert " << GRN << "}" << std::endl;
  std::cout << GRN << "    {" << BLU " find   " << GRN << "}" << std::endl;
  std::cout << GRN << "    {" << BLU " print  " << GRN << "}" << std::endl;
  std::cout << GRN << "    {" << BLU " help   " << GRN << "}" << std::endl;
  std::cout << GRN << "    {" << BLU " exit   " << GRN << "}" << std::endl;

  std::cout << RST << "\n    Digite um dos comandos acima..." << std::endl;
}

void readTree(const char *path, AVL &tree)
{
  //Reading input file
  FILE *inputFile;
  inputFile = fopen(path, "r");

  if (inputFile != NULL)
  {
    while (!feof(inputFile))
    {
      int key;
      fscanf(inputFile, "%d", &key);

      std::cout << GRN ">>> Inserindo {" << BLU << key << GRN << "} na árvore." << std::endl;
      tree.add(key);
    }

    std::cout << GRN
              << ">>> Imprimindo árvore..." << std::endl;
    std::cout << BLU << "\t" << tree.toString() << RST << std::endl;
  }
  else
  {
    std::cout << BRD << ">>> ERRO: Arquivo inexistente." << RST << std::endl;
  }
}

int enterCommandsMode(AVL &tree)
{
  printMenu();

  char op[100];
  while (strcmp(op, "exit"))
  {

    std::cout << GRN << "\n>>> " << RST;
    scanf("%s", op);
    if (strcmp(op, "insert") == 0)
    {
      std::cout << GRN << "    Qual valor deseja inserir? " << RST;
      
      int k;
      scanf("%d", &k);

      std::cout << GRN ">>> Inserindo {" << BLU << k << GRN << "} na árvore." << std::endl;
      tree.add(k);
    }
    else if (strcmp(op, "print") == 0)
    {
      std::cout << GRN
                << ">>> Imprimindo árvore..." << std::endl;
      std::cout << BLU << "\t" << tree.toString() << RST << std::endl;
    }
    else if (strcmp(op, "find") == 0)
    {
      std::cout << GRN << "    Qual valor deseja buscar? " << RST;
      
      int k;
      scanf("%d", &k);

      Node *n = tree.find(k);
      if(n != nullptr)
      {
        std::cout << GRN
                  << ">>> Nó encontrado: "
                  << BLU
                  << "{" << n->key << "}"
                  << "(L" << n->height << ")" << RST << std::endl;
      }
      else 
      {
        std::cout << BRD ">>> O valor não existe..." << std::endl;
      }
    }
    else if (strcmp(op, "help") == 0)
    {
      std::cout << GRN
                << ">>> Ajuda:\n"
                << BLU
                << "    insert\n"
                << RST
                << "    > Para inserir qualquer valor na árvore\n"
                << "      basta digitar { insert } (sem chaves)\n"
                << "      e, em seguida, o valor desejado.\n\n"
                << "      EX.:\n"
                << "      insert\n"
                << "      10\n\n"
                
                << BLU
                << "    print\n"
                << RST
                << "    > Para imprimir a árvore por nível\n"
                << "      basta digitar { print } (sem chaves).\n\n"
                << "      EX.:\n"
                << "      print\n\n"
                
                << BLU
                << "    exit\n"
                << RST
                << "    > Para encerrar o programa, basta\n"
                << "      digitar { exit } (sem chaves).\n\n"
                << "      EX.:\n"
                << "      exit\n\n"

                << BLU
                << "    usos\n"
                << RST
                << "    > O VERDE tem três modos de uso:\n"
                << BLU "      - input " RST "> Lê um arquivo de entrada\n"
                << "                no formato ( x1, x2, ..., xn ).\n"
                << "              - ./bin/verde <caminho_arquivo>\n\n"
                << BLU "      - cmd   " RST "> Utiliza comandos para formar a árvore\n"
                << "              - ./bin/verde --c ou ./bin/verde -commands\n\n"
                << BLU "      - both  " RST "> Lê um arquivo e monta uma árvore e\n"
                << "                utiliza comandos para formar a árvore.\n"
                << "              - ./bin/verde --c <caminho_arquivo> ou\n"
                << "                ./bin/verde <caminho_arquivo> -commands\n\n"

                << GRN
                << ">>> Fim da ajuda...\n\n";
    }
    else if(strcmp(op, "exit") != 0) 
    {
      std::cout << BRD 
                << ">>> Comando inválido... Tente novamente." << RST << std::endl;
    }
  }
  return 0;
}