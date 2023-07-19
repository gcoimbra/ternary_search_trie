## CMakeLists.txt documentation
O código TST.c é uma biblioteca que tem como propósito fornecer funcionalidades específicas para um determinado projeto. Essas funcionalidades são alcançadas através da implementação de funções e estruturas de dados relevantes para o projeto.

Um detalhe importante a ser mencionado é que essa biblioteca deve ser compilada antes de ser utilizada no projeto. Isso pode ser feito através do comando "gcc -o libTST.so -shared TST.c", que irá gerar um arquivo de biblioteca compartilhada chamado "libTST.so". Esse arquivo pode ser utilizado pelo projeto para acessar as funcionalidades implementadas na biblioteca.
## TST.c documentation
O código implementa uma árvore de busca ternária (TST - Ternary Search Tree) em C. O propósito dessa estrutura de dados é armazenar e pesquisar palavras de forma eficiente. 

A árvore é construída de forma recursiva, onde cada nó representa um caractere da palavra. Os nós são organizados em três subárvores: esquerda, meio e direita. A subárvore do meio contém os caracteres que são iguais ao caractere do nó atual, a subárvore da esquerda contém os caracteres menores e a subárvore da direita contém os caracteres maiores.

A inserção de uma palavra na árvore é feita percorrendo a árvore de forma recursiva e inserindo os caracteres em seus respectivos nós. Ao final da palavra, o nó correspondente é marcado como fim de palavra.

A pesquisa de uma palavra na árvore é feita percorrendo a árvore de forma recursiva, comparando os caracteres da palavra com os caracteres dos nós. Se a palavra for encontrada, a função retorna verdadeiro.

Algumas funções auxiliares também estão implementadas, como a função para imprimir todas as palavras da árvore, contar o número de nós na árvore, encontrar a altura da maior palavra na árvore e encontrar a altura de uma palavra específica na árvore.

Um detalhe importante é que a árvore é implementada usando ponteiros para ponteiros, o que permite a manipulação dos nós de forma eficiente.
## TST.h documentation
O código apresentado é uma implementação de uma árvore de busca ternária (TST - Ternary Search Tree) em linguagem C. O propósito dessa implementação é permitir a inserção, pesquisa e contagem de palavras em um dicionário.

A árvore de busca ternária é uma estrutura de dados que permite armazenar e pesquisar palavras de forma eficiente. Cada nó da árvore representa uma letra da palavra, e os nós são organizados em três caminhos possíveis: esquerda, meio e direita. O caminho da esquerda representa letras menores, o caminho do meio representa a letra atual e o caminho da direita representa letras maiores. Além disso, cada nó possui uma flag que indica se a letra é a última letra de uma palavra.

A implementação do código inclui funções para inserir palavras na árvore, imprimir a árvore, pesquisar palavras na árvore, contar o número de nós na árvore, encontrar a altura da maior palavra na árvore e encontrar a altura de uma palavra específica na árvore.

Um detalhe importante é que o código utiliza ponteiros para ponteiros para permitir a modificação dos nós da árvore durante a execução das funções. Isso é necessário para garantir que as alterações feitas na árvore sejam refletidas fora das funções.
