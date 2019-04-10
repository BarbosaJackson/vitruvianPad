# vitruvianPad++

A simple text editor for class of design and analysis of Algorithms

# requeriments

  1. [ ok ] Ter a função de texto justificado com uma função de badness não linear
  2. [ ok ] Ter ‘find’ (sem Regex) e (sem busca completa)
  3. [ ok ] Ter sugestão de auto completar (sem busca completa)

- Estando no terminal do linux vá até a pasta do projeto através do comando **cd**
- estando na pasta do projeto rode o comando **make**
- após isso será gerado um arquivo chamado a.out, execute ele para utilizar as ferramentas do editor
- o arquivo a ser verificado é o input.txt contido na pasta **res** do projeto, caso queira, altere o arquivo, as buscas e o texto que será justificado será o que estiver no arquivo


# autocomplete

para utilizar o autocomplete adicione no texto do arquivo **input.txt** duas cerquilhas seguidos da palavra a qual você gostaria do procurar os possiveis 4 autocompletes deles, todos os autocompletes vão estar salvos no arquivo **suffix.txt** na pasta **res**.

# busca

para buscar uma palavra você insere 2 no menu inicial e digita a sub-string que deseja buscar, feito isso, será exibido na tela todas as ocorrencias dessa subpalavra no texto.


# justificar texto

para justificar o texto selecione a opção 3 e o programa vai pegar o texto contido no arquivo **input.txt** e vai justificá-lo inserindo o texto justificado no arquivo **justify.txt**, ambos na pasta **res**