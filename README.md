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

### Doxygen

Se quiser conferir e tiver instalado o Doxygen na sua máquina, abra o Doxyfile no diretório Playlist, procure por "OUTPUT_DIRECTORY" e "INPUT" com ctrl+f, mude o caminho para o que preferir, e finalmente insira no terminal:
```bash
doxygen
```
Após isso, abra a pasta html gerada no local configurado e abra o arquivo index.html com o navegador.

## Componentes

### Alunos

André de Oliveira Barbosa

João Antônio Costa Paiva Chagas

## Dificuldades

Dificuldades em definir e utilizar os operadores sobrecarregados.