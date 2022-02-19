## Sobre

Essa pasta contém algorítmos desenvolvidos no ano de 2021, para a disciplina de Cálculo Numérico  
realizada no curso de Sistemas de Informação, oferecido pela [FeMASS](https://macae.rj.gov.br/femass/conteudo/titulo/apresentacao) (Faculdade Professor Miguel Ângelo da Silva Santos).  

Foram desenvolvidos algorítmos simples, utilizando C++, para demonstração dos seguintes métodos
- Método de Gauss-Seidel
- Método de Gauss-Jacobi
- Método de Riemann
- Método do Trapézio


## Utilizando o Dev-C++

A IDE utilizada no desenvolvimento, originalmente, foi o Dev-C++, que pode ser encontraodo em:
https://www.bloodshed.net/

- Basta clonar o repositório https://github.com/patrickbindelli/sistemas-de-informacao.git
- E (com o Dev-C++ instalado) abrir os arquivos `.cpp` de cada método
- Rodar o arquivo no menu de contexto em `Execute > Compile & Run`

## Compilando via linha de comando

No `Windows`, você pode utiizar o [MinGW](https://nuwen.net/mingw.html) (ou qualquer outro compilador).

(Provavelmente será necessário adicionar a pasta `MinGW\bin` à sua variável de ambiente `%PATH%`,  
veja [Guia da Oracle Sobre Variávies de Ambiente](https://docs.oracle.com/en/database/oracle/machine-learning/oml4r/1.5.1/oread/creating-and-modifying-environment-variables-on-windows.html)
ou algum outro guia.)


Gerando os arquivos object `.o`:

```powershell
C:\...\caminhoProjeto> g++ -c metodoQueEstaCompilando.cpp
```

Gerando o arquivo executável `.exe` (substitua nomeDoProjeto):

```powershell
C:\...\caminhoProjeto> g++ metodoQueEstaCompilando.o -o nomeDoExecutavel.exe
```

