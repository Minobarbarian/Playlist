# 🎶 Playlist

## 🚀 Getting started

Projeto Base da dupla: Tobias Daniel Siqueira e Hosana Iasmin Castro dos Santos.

Clone o projeto e acesse a pasta Playlist.

```bash
git clone https://github.com/Minobarbarian/Playlist.git

cd Playlist

```

Observação: Verifique se a versão do cmake da sua máquina condiz com o configurado no CMakeLists.txt

Para rodar o projeto pela primeira vez, digite os seguintes comandos no terminal:

```bash
cmake .

make

./program Arquivo.txt
```

Se quiser rodar novamente após modificações, insira:
```bash
make

./program Arquivo.txt

```

Se quiser rodar sem alterações, insira:
```bash
./program Arquivo.txt
```

Se quiser trabalhar com listas vazias, insira:
```bash
./program
```

### Doxygen

Se quiser conferir e tiver instalado o Doxygen na sua máquina, abra o Doxyfile no diretório Playlist, procure por "OUTPUT_DIRECTORY" e "INPUT" com ctrl+f, mude o caminho para o que preferir, e finalmente insira no terminal:
```bash
doxygen
```
Após isso, abra a pasta html gerada no local configurado e abra o arquivo index.html com o navegador.

## Demandas
### Demandas atendidas
#### Questão 5
A demanda da questão 5 foi cumprida, e pode ser testada com:
##### Leitura
```bash
./program Arquivo.txt
2
5
2
Orakel
3
```
##### Escrita
```bash
./program Arquivo.txt
2
1
Vario
2
Vario
1
Splinter
Savant
1
Vario
Savant
0
0
0
```
Após encerrar confira Arquivo.txt em Playlist para ver se salvou o que foi feito.
### Demandas não atendidas
#### Questão 1
O código referente aos itens A, B e C da questão 1 foi escrito na Lista.h mas não está funcional.

Particularmente, o item A é chamado no item A da questão 3 e não apresenta nenhum erro de compilação nem Segmentation Fault mas não altera nada.
Quanto ao item B, não foi utilizado apesar de ter sido escrito.
Quanto ao item C, é utilizado nos não utilizados itens A da Questão 2 e B da Questão 1, e no não-funcional item A da questão 4.
#### Questão 2
O código referente aos itens A, B e C da questão 2 foi escrito na Lista.h mas não está funcional.

Quanto ao item A, não foi utilizado apesar de ter sido escrito.
Quanto ao item B, não foi utilizado apesar de ter sido escrito.
Quanto ao item C, não foi utilizado apesar de ter sido escrito.
#### Questão 3
O código referente aos itens A, B e C da questão 3 foi escrito na Playlist.h e Playlist.cpp mas não está funcional.

Particularmente, o item A é utilizado na interface de Gerenciamento de Playlists (Funcs.cpp), na função managePlaylists, caso 8, só que não altera nada e não gera erros.
Quanto ao item B, não foi utilizado apesar de ter sido escrito.
Particularmente, o item C é utilizado no não utilizado item B da questão 4
#### Questão 4
O código referente aos itens A, B, C e D da questão 4 foi escrito na Playlist.h e Playlist.cpp mas não está funcional.

Particularmente, o item A é utilizado na interface de Gerenciamento de Playlists (Funcs.cpp), na função managePlaylists, caso 9, só que gera Segmentation Fault após execução.
Quanto ao item B, não foi utilizado apesar de ter sido escrito.
Quanto ao item C, não foi utilizado apesar de ter sido escrito.
Quanto ao item D, não foi utilizado apesar de ter sido escrito.
#### Vazamento de Memória
O código está vazando memória, mais precisamente, 30 allocs não são liberados após término de execução quando ./program Arquivo.txt é executado e saindo imediatamente dos menus.

## Dificuldades

Dificuldades em definir e utilizar os operadores sobrecarregados.

Dificuldades em achar e corrigir erros de memória.

Dificuldades em tratar os vazamentos de memória.

## Componentes

### Alunos

André de Oliveira Barbosa

João Antônio Costa Paiva Chagas