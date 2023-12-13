# Sistema de Gerenciamento de Banco de Dados (SGBD) - Projeto de Introdução a Técnicas de Programação

# Descrição
    O Sistema de Gerenciamento de Banco de Dados (SGBD) é um projetodesenvolvido em linguagem C pelos alunos Gabrielle Borja e Victor Gomes como parte da disciplina de Introdução a Técnicas de Programação no Instituto Metrópole Digital (IMD) da Universidade Federal do Rio Grande do Norte (UFRN). O principal objetivo do SGBD é fornecer uma plataforma simples e eficaz para a criação, manipulação e consulta de dados em um ambiente de banco de dados. 

## Funcionalidades

1. **Criar uma tabela**
   - Descrição: Permite criar uma nova tabela no banco de dados. O comando 

2. **Listar todas as tabelas**
   - Descrição: Exibe uma lista de todas as tabelas presentes no banco de dados.

3. **Criar uma linha**
   - Descrição: Adiciona uma nova linha (registro) a uma tabela existente.

4. **Listar dados de uma tabela**
   - Descrição: Exibe os dados (linhas) de uma tabela específica.

5. **Pesquisar valor em uma tabela**
   - Descrição: Procura por um valor específico em uma tabela.

6. **Apagar uma tupla (registro ou linha) de uma tabela**
   - Descrição: Remove uma tupla específica de uma tabela.

7. **Apagar uma tabela**
   - Descrição: Exclui uma tabela do banco de dados.

0. **Fechar**
   - Descrição: Encerra o programa.

## Como Executar

1. Certifique-se de ter o compilador e as dependências necessárias instaladas.
3. Compile o código-fonte.
   - Abra o terminal na pasta onde o programa se encontra
   - Execute o comando:
   ```bash
    gcc SGBD-ITP.c funcoes.c -o main
   ```
   - O comando criará um arquivo main.exe, que pode ser executado através do comando:
   ```bash
   ./main 
   ```