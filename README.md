## Alocação de pessoas para postos de vacinação
### Trabalho prático da disciplina de Algoritmos I - Sistemas de Informação - UFMG - 2021/1

#### Instruções de execução

**Build**

```bash
make
```

**Execução**

```bash
./tp01 < <arquivo_de_entrada>
```

A entrada é lida da forma padrão; portanto, pode ser inserida manualmente ou via arquivo de texto.
Exemplos podem ser encontrados na pasta "testes"

#### Como funciona?

A primeira linha de entrada descreve o **número de postos de vacinação** (*m*). 
Em seguida, as próximas *m* linhas são compostas por atributos dos postos:
- capacidade
- abscissa
- cordenada

A próxima linha descreve o **número de pessoas que receberão as vacinas** (*n*).
As próximas *n* linhas são compostas por atributos das pessoas:
- idade
- abscissa
- coordenada


A priorização da vacina é feita pela idade e pelo cálculo da distância, priorizando as pessoas de maior idade e os postos mais perto.
