# Sistema de Gerenciamento de Banco de Dados (SGBD) - Projeto de Introdução a Técnicas de Programação

## Descrição
O Sistema de Gerenciamento de Banco de Dados (SGBD) é um projeto desenvolvido em linguagem C pelos alunos Gabrielle Borja e Victor Gomes como parte da disciplina de Introdução a Técnicas de Programação no Instituto Metrópole Digital (IMD) da Universidade Federal do Rio Grande do Norte (UFRN). O principal objetivo do SGBD é fornecer uma plataforma simples e eficaz para a criação, manipulação e consulta de dados em um ambiente de banco de dados. 

## Requisitos
  - MinGw

## Funcionalidades

1. **Criar uma tabela**
   - Descrição: Permite criar uma nova tabela no banco de dados.
   - Solicita ao usuário que escolha o nome da tabela.
   - Verifica se já existe uma tabela com o mesmo nome.
   - Cria um arquivo de texto na pasta "arquivos/" com o nome da tabela.
   - Permite ao usuário definir o nome, tipo de dados e outras propriedades para cada coluna da tabela.
   - Atualiza o cabeçalho do arquivo com o número correto de colunas.

2. **Listar todas as tabelas**
   - Descrição: Exibe uma lista de todas as tabelas presentes no banco de dados.
   - Abre o diretório.
   - Ler todos os arquivos de tabelas removendo o sufixo ".txt".

3. **Criar uma linha**
   - Descrição: Adiciona uma nova linha (registro) a uma tabela existente.
   - Solicita ao usuário que escolha o nome da tabela.
   - Verifica se a tabela escolhida já existe no banco de dados.
   - Pede a chave primária da linha ao usuário.
   - Pede ao usuário os dados de cada coluna de acordo com o tipo da coluna.
   - Adiciona a linha e suas informações no arquivo.
   - Pergunta ao usuário se ele deseja adicionar mais linhas.

4. **Listar dados de uma tabela**
   - Descrição: Exibe os dados (linhas) de uma tabela específica.
   - Solicita ao usuário que escolha o nome da tabela a ser apresentada.
   - Verifica se a tabela existe.
   - Abre o arquivo e imprime toda a tabela.

5. **Pesquisar valor em uma tabela**
   - Descrição: Procura por um valor específico em uma tabela.
   Função não finalizada.

6. **Apagar uma tupla (registro ou linha) de uma tabela**
   - Descrição: Remove uma tupla específica de uma tabela.
   - Solicita ao usuário que escolha o nome da tabela.
   - Verifica se a tabela existe e abre o arquivo dela.
   - Solicita ao usuário a chave primária da linha a ser excluída
   - Abre um arquivo temporário e imprime nele todas as linhas menos a que será excluida.
   - Remove o arquivo original e renomeia o arquivo temporário como original.

7. **Apagar uma tabela**
   - Descrição: Exclui uma tabela do banco de dados.
   - Solicita ao usuário que escolha o nome da tabela a ser apagada.
   - Verifica se a tabela existe.
   - Apaga a tabela
   - Lista tabelas restantes.
   - Se a tabela pedida não existir oferece a lista de tabelas cadastradas e volta ao menu.

0. **Fechar**
   - Descrição: Encerra o programa.

## Como Executar

1. Certifique-se de ter o compilador e as dependências necessárias instaladas.
3. Compile o código-fonte.
   - Abra o terminal na pasta onde o programa se encontra
   - Execute o comando:
   ```bash
    gcc SGBD-ITP.c funcoes.c funcoes_aux.c -o main
   ```
   - O comando criará um arquivo main.exe, que pode ser executado através do comando:
   ```bash
   ./main 
   ```

## Descrição de desenvolvimento
 O projeto foi desenvolvido em conjunto, principalmente a criação das funções Criar Tabela e o esboço de Pesquisar valor. Ademais, as funções de Menu, Apagar tupla, Listar Dados e a modularização do projeto tem como desenvolvedor majoritário Victor Gomes. Já as funções de Listar tabelas, Criar linhas e Apagar tabelas foram majoritariamente desenvolvidas por Gabrielle Borja.

 A função de pesquisa de valor não foi completamente implementadas, por apresentar erros na leitura e impressão dos dados, em foco os de tipo inteiros, float e double.

 

