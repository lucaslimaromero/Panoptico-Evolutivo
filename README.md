# Projeto da Disciplina SSC0713 - Sistemas Evolutivos

## Preâmbulo Teórico
O projeto se baseia na obra `"Vigiar e Punir"`, de _Michel Foucault_, mais especificamente no capítulo III da Terceira Parte, **Panoptismo**. A seguir, há uma explicação sobre a filosofia intrínseca ao tema, dedicada aos interessados que buscam se deleitar com a teoria.
- A obra, como um todo, se debruça sobre o `nascimento das prisões modernas`, em que a violência e o suplício comuns da Idade Média, foram substituídos por mecanismos disciplinares de controle dos corpos, como é visto na atualidade.
- `Panoptismo` é o conceito associado a outra palavra: o **Panóptico** (Pan: tudo; óptico: olhar, ao pé da letra seria um olhar geral). Este, por sua vez, é um modelo arquitetônico mais antigo, popularizado por um famoso filósofo utilitarista chamado _Jeremy Bentham_ (quem assistiu The Good Place, sabe).

Veja algumas representações desse espaço.

<div style="text-align: center;">
  <img src="https://universodafilosofia.com/wp-content/uploads/2017/12/panoptico.jpg" width="400" style="margin: auto;" />
  <img src="https://cdn.discordapp.com/attachments/602350214740967426/1176870342480896010/prisao_cuba_modelo_panoptico.png?ex=657070ea&is=655dfbea&hm=e0e72e4ee08afc370fab5a7fcf37f7e21bd90e0dbca7c8fa69255f7940d1594d&" width="400" style="margin: 0 auto;" />
</div>

A ideia desse local, é que:
- O `vigilante` vê, sem ser visto, no alto da torre, por meio de um jogo de luzes.
- O `vigiado` é visto sem ver e estão isolados nas sua celas.

A discrepância na capacidade de visão produz a desigualdade na `quantidade de poder`.
- O vigiado `nunca` sabe se está sendo visto ou não. Ele tem acesso apenas aos seus pensamentos e às tentativas de transgressão de outros vigiados, que são punidos (essa punição é necessária para que a dinâmica do sistema funcione, mas não implica necessariamente violência física).
- Portanto, na dúvida, ele se `autodisciplina` e não transgride. Isso é muito incondicionalmente mais vantajoso para o vigilante, basta um pra vigiar outros 1000, 10.000! Perceba que não é mais necessário carrascos, elevados gastos de energia, de dinheiro para exercer poder. Nesse sistema contemporâneo, são `os próprios vigiados que se vigiam!`

O Panóptico, no fim das contas, **não** é uma prisão! Ele é mais geral do que isso, é um dispositivo disciplinar, uma **"fábrica de produção de disciplina"**. Nas celas metafóricas, a sociedade contemporânea coloca presidiários (prisão), estudantes (escola), loucos (manicômio), trabalhadores (fábricas), doentes (hospitais), qualquer um. O conceito Panoptismo surge, a priori, a partir da prisão, mas extrapola para diversos locais!

## Associação com o Sistema Evolutivo

A ideia do projeto é baseado na implementação de uma interface gráfica que represente o Panóptico visto de cima, no caso de uma prisão, conforme o esboço a seguir.
<div align="center">
  <img src="https://cdn.discordapp.com/attachments/602350214740967426/1168285032624955402/image.png?ex=65513539&is=653ec039&hm=5ab7332ce9113959737801ea298a9469d58b94f33f049701018bc935a942789c&" width="400" style="margin: auto;" />
</div>

- A dinâmica do `panóptico evolutivo` é baseada na movimentação de pontos aleatórios na tela, representando os vigiados. Esses pontos podem ou não estar dentro da cela. Se não estiverem, **poderão ser punidos**.
- Será representada no centro a `torre de vigia` que estará teoricamente vigiando a todo momento.
- Isso será feito repetidamente até chegar num ponto satisfatório em que os prisioneiros estão dentro de suas telas, e a `"autodisciplina"` foi instaurada.

A seguir estão anexadas prints que evidenciam a **evolução** de uma população em `diferentes gerações`.

<div align="center">
    <img style="width: 40%;" src="https://cdn.discordapp.com/attachments/602350214740967426/1176706843599458364/ger4.png?ex=656fd8a5&is=655d63a5&hm=7a8a38ac0f6c0b5442f50ca77fbcec72f49b5cb9b92aed4fd7df13d89550db47&"/>
    <img style="width: 40%;" src="https://cdn.discordapp.com/attachments/602350214740967426/1176706843872084038/ger16.png?ex=656fd8a5&is=655d63a5&hm=3989f9effb921d35aa9caddee3290cf67ead5bbb09a4482c16464dcad4a99857&"/>
    <br>
    <img style="width: 40%;" src="https://cdn.discordapp.com/attachments/602350214740967426/1176706844123738302/ger22.png?ex=656fd8a5&is=655d63a5&hm=e96710f16d95acdb45db39c50a15f26c010d4235a23afdc34a5c1c17507d414a&"/>
    <img style="width: 40%;" src="https://cdn.discordapp.com/attachments/602350214740967426/1176706844429930606/ger27.png?ex=656fd8a5&is=655d63a5&hm=cc8f9439279d12bd4ba44d1e9468270cfd480623bea6cf806e58a30bc549c903&"/>
</div>

## Como rodar o projeto

Digite os seguintes comandos no seu terminal

### Instalação

Instalando os pacotes de desenvolvimento do OpenGL no Ubuntu

```
$ sudo apt-get install mesa-common-dev
$ sudo apt-get install freeglut3-dev
```

### Execução

Para compilar o programa

```
$ cd Panoptico-Evolutivo
$ make clean
$ make
```

Para rodar o programa
```
$ make run
```

## Considerações Finais

A elegância, aplicabilidade e nitidez dessa teoria na contemporaneidade foram alguns dos fatores motivadores que impulsionaram a reinterpretação e expansão do Panóptico para o âmbito `computacional` e tecnológico. Nesse contexto, o Panóptico transcende seu contexto original, transformando-se em um cenário conceitual que serve de **pano de fundo** para o estudo e desenvolvimento de `Algoritmos Evolutivos`.

A adaptação do Panóptico para a `esfera algorítmica` não apenas redefine seu escopo, mas também representa uma busca ativa por compreensão e inovação. Esse movimento reflete não apenas uma mudança conceitual, mas também destaca a **versatilidade e a relevância** contínua desse conceito seminal na era digital.

## Autor

| [<img loading="lazy" src="https://avatars.githubusercontent.com/u/101420277?v=4" width=115><br><sub>Lucas Lima Romero</sub>](https://github.com/lucaslimaromero) |
| :---: |

