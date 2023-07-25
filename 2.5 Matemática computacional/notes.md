#Cálculo numérico

## 1. Intro:
> Cálculo numérico ou métodos númericos é uma matéria/área que tenta achar soluções para as limitações dos computadores.

* Use case:
	Em várias linguagens de programação, se você soma 0.1 dez vezes, o resultado ao invés de ser 1 sera 0.999999... que é uma dizima periódica.
	*Metódos númericos* fornece o motivo e a solução para problemas desse tipo.

* informações úteis:
	* [Resolução de problemas na engenharia](/home/flp/Downloads/its about time/1.Material/P3/Cálculo númerico/pics/problemas-engenharia.png)
	* [Acurácia e Precisão](/home/flp/Downloads/its about time/1.Material/P3/Cálculo númerico/pics/acuracia-precisao.png)
	* [Símbolos usados em diagramas de fluxo](/home/flp/Downloads/its about time/1.Material/P3/Cálculo númerico/pics/diagrama-de-fluxo.png)

* python e numpy
	* As anotações vão tentar ser o mais generalista possivel mas esse curso normalmente é feito com a linguaem python e usando a biblioteca numpy.
	* Você pode tratar o numpy como o trabalho/resultado dos profissionais dessa matéria.
	* numpy é grande, serve para várias coisas, até como base para outras bibliotecas. 
	* Breve show off com matrizes:
		```python
		import numpy as np

		python_array = [[1,2,3], [4,5,6], [7,8,9]]
		np_array = np.array([[1,2,3], [4,5,6], [7,8,9]])

		R = np.random.rand(5,5)
		print(R[0:3, 3:])

		A = np_array
		B = np.array([[-6, 7, 3]])
		C = A@B.T
		D =B.T@B
		print(f"A x B = {C}")
		print(F"B(transposta) x B = {D}")
		print(C.shape)
		```

## 2. Aritmética de ponto flutuante:

1. Tudo é que é armazenado/interpretado pelo PC (sistemas digitais no geral) precisam/estão no formato binário. OBS: Existe uma modelo onde o primeiro digito denota o sinal do valor binário

2.  Para passar um número decimal para binário você:
	1. Separa a parte inteira da fracionaria (se existir).
	2. Usa o método de divisões sucessivas por 2 (pois a base é binária) na parte inteira.
	3. Usa o método de *multiplicações* sucessivas, por 2, na parte fracionaria.
	4. junte as 2 partes por uma vírgula.

3. Para passar de binário para decimal você:
	1. indendtifica o digito de index 0 (1 digito a esquerda da virgula)
	2. multiplica cada digito por 2 (pois a base é 2) elevado à potencia do index do digito.
	3. Depois basta somar todos os valores

4. **Ponto flutuante normalizado**:
	* De modo análogo a notação cientifica, é uma maneira deixar os números organizados.
	* Consiste em deixar os números com a parte inteira igual a zero, e a o primeiro digito após a virgula diferente de zero. 
	* O número de digitos após a virgula é a *precisão* do sistema computacional, e esse conjunto e digitos (parte a direita da virgula) é a *mantissa*
	* Ex: $$-3,625$$ (na base 10) ao passar para binario (base 2) fica como $$(-11,101)_2$$ e ao "normalizar" ele fica como: $$(-0,11101*2^2)$$

5. Sistema de Numeração: $$F(b,p,m,M)$$: 
	* Considere F uma maquina/PC. 'b' vai ser a base em que esse computador trabalha (10 ou 2), 'p' vai ser o número de digitos apos a virgula que ele suporta, 'm' é o menor expoente suportado e 'M' é o maior expoente suportando ($$[b^m, b^M]$$) 
	* Exemplo: *Escrever o número -3,625  no sistema F(2,5,-3,3)*:
		* 1 passo: passar para a base do sistema (nesse caso 2) ==> $$(-11,101)_2$$
		* 2 passo: Normalizar esse número ==> $$(-0,11101 * 2^2)$$
		* 3 passo: verifique se o tamanho da mantissa é menor ou igual ao 5 ("cabe" no sistema)
	* O menor número que esse sistema F pode representar é: x = b^(m-1)
	* O maior número que esse sistema F pode representar é x = (1-b^(-p))\*b^M
	
6. Aritmética de ponto flutuante: 
	* Em computadores, a operação X*(1/Z) é diferente de X/Z. No primeiro caso você está realizando 2 operações e é possivel que ocorra perca de dados/informação.
	* No geral, desde que os números estejam escritos na forma "normalizada" as operações são feitas da seguinte forma:
		* Multiplicação: Multiplica-se as mantissas e somam-se os expoentes
		* Divisão: Divide-se as mantissas e diminuem-se os expoentes
		* Soma e Subtração: Igualam-se os expoentes e então Soma-se/subtrai-se as mantissas

7. **Arredondamento** x **Truncamento**:
	1. Arredondamento: É o problema/erro relacionado à impossibilidade de representar o número em binário/digitalmente. Se o ultimo digito é maior igual à cinco você arredonda para cima, e o contrario, para baixo.
	2. Truncamento:  É o problema/erro de representação do resultado que ocorre quando tentamos aproximar uma soma matematica infinita para um procedimento finito. Quando te pedem para truncar, siginifica para cortar as casas decimais apartir do 5 digito.
8.  **erro absoluto** = módulo do (valor esperado - valor obtido)
9. **erro relativo** = erro absoluto/valor esperado
10. Todos os sistemas trabalham dentro de um intervalo de valores. Se algum número está abaixo desse intervalo ocorre um *underflow* e se estiver acima ocorre um *overflow*.
11. Cancelamento catastrófico
	1. É quando o sistema/linguagem 'arredonda' um valor numérico seja porque a mantissa é muito grande ou porque o número é dizima.
	2. Quando ocorre um cancelamento catastrófico, os valores das subsequentes operações apresentaram erros muito grandes. Ex: a = 2^(1/2); b = a^2; b-2 != 0;

12. Propragação de Erros:
	1. Você faz uma operação, ela tem um erro de arredondamento. Faz outra, mais um errinho, e assim vai. O erro relativo vai aumentando a medida que as operações são feitas.
	2. Um dos artificos matemáticos mais importantes e fortemente utilizados em calculo numérico são as **séries de taylor** e suas aplicações.
	3. Dada f(x), podemos fazer com taylor:
		* $$Δy = f'(x) Δx$$
		* $$K(x) = x f'(x)/f(x)$$
		* $$Δy/y = K(x)Δx/x$$
	4. [Exemplo de como pequenas mudanças afetam o valor, devido à propagação de erros.](/home/flp/Downloads/its about time/1.Material/P3/Cálculo númerico/pics/ex-propag-err.png)


## 3. Solução de equações 1 uma variável:
* Esse parte tem como objetivo demonstrar metodologias para resolver equações algebricas com uma única variável.
* Bibliotecas que seram usadas:
	```
	from __future__ import division
	import numpy as np
	import matplotlib.pyplot as plt
	import scipy as sci
	from scipy import optimize
	```

###Condição de existência de raizes
1. Teorema de Bolzano:
	* Consequência do teorema do valor intermediário (cálc. 1)
	* *Dado um intervalo fechado \[a,b\], existe uma raiz da função $$f(x)$$ dentro desse intervalo se $$f(a)f(b)<0$$*
2. Teste da derivada:
	* Se a função $$f(x)$$ seguir o teorema de Bolzano no intervalo  \[a,b\] **e se** a derivada de $$f(x)$$, ($$f'(x)$$) for positiva (ou negativa) para *Todos* os valores nesse intervalo, então existe uma raiz.


### Construindo gráficos
* Exemplo de código (você só vai pegar o fealing testando):
    ```python
	import numpy as np
	import matplotlib.pyplot as plt
	from sympy import Symbol, diff, lambdify

	x = Symbol('x')
	range = np.linspace(-2.5,5,1000)

	y = np.euler_gamma**(x**2 -3*x + 2)
	dy = y.diff()

	f = lambdify(x, y, 'numpy')
	df = lambdify(x, dy, 'numpy')

	print(y, f(2))
	print(dy, df(2))

	plt.plot(range, f(range)); plt.plot(range, df(range));
	plt.grid(); plt.show();
    ```
	
###Métodos:
0. Alguns criterios de parada recorrentes:
	Dado \[a,b\]
	* abs(b-a)/2 > E (E = erro aproximado)
	* abs(b-a) > I (I = amplitude)
	* abs(f((a+b)/2)) > P (P = precisão)

1. **Método da bisseção**:
	* Dada $$f(x)$$ continua em um intervalor \[a,b\], vamos calcular o ponto medio do intevalo e verificar se o valor está apartir do meio para cima, ou do meio para baixo.
	* O critério de parada pode ser várias coisas (num. de iterações, diferença $$(b-a)/2 < criterio$$, entre outras)
	* Ex:
		```python
		import math

		def f(x): return math.sin(x) + math.log(x)
		a = 0.2
		b = 0.8
		Err = 1e-10
	
		#verificando se existe raiz (bolzano)
		if f(a)*f(b) < 0:
		  #criterio de parada do exemplo
		  while math.fabs(b-a) > Err:
			mid = (a+b)/2
            
			#decidindo qual 'lado' do intervalo diminuir
			if f(a)*f(mid) < 0: b = mid
			elif f(mid)*f(b) < 0: a = mid

		  print(f"a raiz de f é {mid}\nf({mid}) = {f(mid)}")
		else: print(f"Não existe raiz no intervalo [{a},{b}]")
		```
	* Ex 2:
	```
	f = lambda x: (2.718281828459045**x)-(x+2)
		def bissec(f, a, b, stop):
			if f(a)*f(b) < 0:
			  while abs(b-a)/2 > stop:
				med = (a+b)/2
				if(f(a)*f(med) < 0):
				  b = med;
				else:
				  a = med;
			print(f"A raiz entre [-2,0] é: {med}\nf({med})={round(f(med), 4)}")

		bissec(f, -2, 0, 0.0001)
	```


2. **Método das Codas (falsa posição)**:
	* Assim como o da bisseção, é um metodo de quebra de intervalos, só que você vai quebrar o intervalo com outro critério:
	* Dado o intervalo \[a,b\] e a função f(x), iterativamente vamos calcular $$ x = (a*f(b) - b*f(a))/f(b)-f(a)$$
	* Esse método consiste em aproximar a curva f(x) a uma reta que, ao intersectar o eixo x, vai dar a raiz que queremos.
	* Tem uma aproximação melhor que o método da bisseção, mas realiza mais iterações.
	* Fluxograma:
		1. Aplica bolzano em \[a,b\]
		2. calcula x pelo método acima, e então faz bolzano para \[x,b\] e \[a,x\]
		3. Uma vez encontrado o intervalo da raiz, repete-se o passo 2 até alcançar o criterio de parada
	
	*Ex:
	```
	import numpy as np
	import matplotlib.pyplot as plt

	f = lambda x: (x**2)-2.5*x-3

	def ploting(f, range):
	  plt.plot(range, f(range));
	  plt.grid()
	  plt.show()

	def cordas(f, a, b, stop):
	  A = a
	  B = b
	  if (f(a)*f(b)) < 0:
		while abs(b-a)/2 > stop:
		  med = ((a*f(b))-(b*f(a)))/(f(b)-f(a))
		  if f(a)*f(med) < 0:
			b = med;
		  elif f(med)*f(b) < 0:
			a = med;
		print(f"A raiz entre [{A}, {B}] é: {med}\nf({med})={round(f(med), 4)}")
	  else: print("bananas")

	cordas(f, -2.5, 0, 0.0001)
	cordas(f, 0, 5, 0.0001)
	ploting(f, np.linspace(-2.5,5))
	```

3. **Método iterativo linear (MIL)**:
	* É método de ponto fixo. Ao invés de dar um intervalo bem definido, você vai dar um valor inicial para x, e  código vai achar a raiz
	* Ao invés de achar 0 x tal que f(x)=0, nesse método você isola o "x" então define uma função g(x) = x
	* O método então consiste em fazer $$x_n+_1 = g(x_n)$$
	* Outra maneira para achar g(x) (se isolar o x for complicado) é: $$ x = g(x) = x - α*f(x)$$ dai então você varia 0 α para ajustar a iteração. A única dificuldade, se é que existe, é achar essa g(x).
	* Ex:
	```
	import math
	f = lambda x: math.exp(x)-x-2
	g = lambda x: math.exp(x)-2

	def il(g, x0, n):
	  for _ in range(0, n+1): x0 = g(x0)
	  return x0
	print(f"A raiz é {il(g,0.5,20)}\n f(x) = {f(il(g,0.5,20))}")
	```
	* Também é importante saber quando a utilização desse método é rentavel (condições de convergência)
	* .
	* .
	* .

4. **Método de Newton-Raphson**:
	* Dado um valor inicial x0 e uma função f(x), você vai fazer uma iteração, com um criterio de parada, e exeuctar: $$x_i = (x_0-f(x_0))/f'(x_0)$$
	* Ex:
	```
	from sympy import Symbol, diff, lambdify
	## criando as funções que seram usadas
	def fun(x, y):
	  f = lambdify(x, y, 'numpy')
	  df = lambdify(x, y.diff(), 'numpy')
	  return f, df

	## criando algumas variáveis
	def bananas():
	  err = 1
	  i = 0
	  x = Symbol('x');
	  f, df = fun(x, x**3 - 9*x + 3);
	  return err, i, x, f, df

	## aplicando o método
	def raphson(xo, n, minErr):
	  err, i, x, f, df = bananas()  

	  while i <= n and abs(err) > minErr:
		xi = xo;
		if df(xi) == 0: break
		xi = xi-f(xi)/df(xi)
		err = abs(xi-xo)
		xo = xi
		i+=1
	  return xi, err, i-1 # primeira iteração não conta

	## printando resultados
	xi, err, i = raphson(0.5, 100, 0.01)
	print(f"Raiz: {xi}\nError: {err}\nnúmero de iterações: {i}")
	```
	* Esse é o método mais eficiente que um iniciante pode usar, mas ele não serve sempre. Se f'(x) for igual a zero, não haverá convergencia. Nesses casos utiliza-se o proximo método.

5. **Métodos das Secantes**:
	* Quando f'(x) é igual a zero, ou quando é muito complexa de calcular, usa-se esse método, alternativamente ao de Newton-Raphson
	* Você aproximará $$f'(x)$$ para $$(f(x)-f(x_0))/(x-x_0)$$
	* Esse metodo é uma mistura do método das cordas com o método de newton
	* O proximo x seria: $$x_n+_1 = (x_n-_1*f(x_n) - x_n*f(x_n-_1))/(f(x_n)-f(x_n-_1))$$
	* Ex:
	```
	f = lambda x: x**3-9*x+3
	def sec(f, a, b, Err):
	  if f(a)*f(b) < 0:
		i = 0
		while abs(b-a) > Err:
		  ##aplicando o método
		  c = (a*f(b) - b*f(a))/(f(b)-f(a))
		  a = b; b = c; i += 1;
		return c, i-1, abs(b-a) #A primeira iteração não conta
	  else: print('bananas')

	x, i, err = sec(f, 0, 1, 1e-12)
	print(f"raiz: {x}\niteração: {i}\nPrecisão: {err}")
	```

Outro exemplo:
```
import math

def init(): 
    f = lambda x: 4*math.cos(x) - math.exp(x)
    df = lambda x: -4*math.sin(x) - math.exp(x)
    return f, df

def newt(xo):
    xi = 0
    err = abs(xi-xo); 
    f, df = init()
    while abs(err) >= 1e-2:
      xi = xo;
      if df(xi) == 0: break
      xi = xi-f(xi)/df(xi)
      err = abs(xi-xo)
      xo = xi
    return xi


def secan(a, b):
    f, df = init()
    if f(a)*f(b) < 0:
        while math.fabs(b-a) >= 1e-2:
            c = (a*f(b)-b*f(a))/(f(b)-f(a))
            a = b; b = c;
        return c, abs(b-a)
    

xN = newt(0.5)
xS, errN = secan(0, 1)

print(f"Newton:  Raiz: {xN}")
print(f"Secante: Raiz: {xS}")
print(round(abs(xN-xS), 10))
```

## 4. Solução de sistemas lineares

Dado um sistema linear (conjunto de equações com variáveis em comum) podemos calcular soluções para ele ao utilizar da representação matricial.

O procedimento mais direto porém arcáico é a **Eliminação Gaussiana** (aka: *Escalonamento*)

Como você deve lembrar de algebra linear, o escalonamento consiste em você "zerar" as colunas de modo a formar um "triangulo" de zeros na matriz. No papel nos fazemos isso livremente, mas no computador precisamos achar um padrão, por isso usamos um pivô. O pivô é o primeiro elemento não-nulo de uma linha. Vamos usar o pivô e uma das operações elementares para escalonar um sistema no código abaixo:

```python
import numpy as np
import copy as cp

np.random.seed(2)
A = np.random.rand(5,5)
b = np.random.rand(5,1)

Acp = cp.copy(A)
bcp = cp.copy(b)

print(f"A:\n{A}\n")
print(f"b:\n{b}\n")

# Començando o escalonamento:
#1. Definir um pivo
#2. Definir o fato multiplicativo ideal para zerar cada elem.
pivo = A[0,0]
m = -A[1,0]/pivo
A[1] = A[1] + m*A[0]
b[1] = b[1] + m*b[0]

m = -A[2,0]/pivo
A[2] = A[2] + m*A[0]
b[2] = b[2] + m*b[0]

m = -A[3,0]/pivo
A[3] = A[3] + m*A[0]
b[3] = b[3] + m*b[0]

m = -A[4,0]/pivo
A[4] = A[4] + m*A[0]
b[4] = b[4] + m*b[0]

#Depois da primeira leva de operações
print(f"A:\n{A}\n")
#O objetivo é criar aquele "triangulo de zeros na base na matriz"
```
Repare que existe um certo padrão ai, um padrão que encaixa perfeitamente em um nested loop.
Antes de mostrar o codigo, perceba que isso não é tudo. Depois que escalonarmos a matriz, ainda será necessário calcular manualmente os valores de x1, x2, x3, x4, x5. Mas uma vez, também existe uma forma mais compacta de fazer isso.
Uma observação que, dada a natureza do escalonamento, primeiro é calculado o x5 depois o x4, x3, x2 e finalmente o x1, pois esse ultimo precisa de todos as outras icognitas.

```python
import numpy as np
import pandas as pd

def escalonamento(matriz_coeficientes, termos_independentes):
    A = np.copy(matriz_coeficientes)
    b = np.copy(termos_independentes)
    tamanho = len(A)
    
    for j in range(0, tamanho-1):
		# pivoteamento ocorreria aqui
        pivo = A[j,j]
        for k in range(j+1, tamanho):
            m = -A[k,j]/pivo
            A[k] = A[k] + m*A[j]
            b[k] = b[k] + m*b[j]
            A[k,j] = 0 #"garantindo" que o elem. foi zerado.

    return A,b

def incognitas(matriz_A_escalonada, matriz_b_escalonada):
    tamanho = len(matriz_A_escalonada)
    A = np.copy(matriz_A_escalonada)
    b = np.copy(matriz_b_escalonada)
    
    x = np.zeros(tamanho)
    #calculando manualmente a ultima raiz, já que é uma divisão simples
    x[tamanho-1] = b[tamanho-1]/A[tamanho-1,tamanho-1]
    
    #calculando todas as outras raizes, que seguem um padrão de somatorio
    for k in range(tamanho-2, -1 ,-1):
        soma = b[k]
        for t in range(k, tamanho):
            soma = soma - (A[k,t]*x[t])
        x[k] = soma/A[k,k]
    return x
    
    
    
np.random.seed(10)
A = np.random.rand(10,10)
b = np.random.rand(10,1)
Ars, brs = escalonamento(A,b)
x = incognitas(Ars, brs)

#repare no triangulo de zeros
print(f"Matriz A escalonada:\n{pd.DataFrame(Ars)}\n\n")

#verificando a resposta
print(f"\n\nA x incognitas:\n{A@x}\n\ntermos independentes\n{b}")
```

### Pivoteamento:
O código anterior é valido, mas falho em alguns casos. Se algum dos pivôs for 0 ou um número muito pequeno, ocorrerá um erro numérico que resultará em um *encerramento castastrófico*.
Para evitar isso usa-se do pivoteamento no escalonamento. Pivoteamento é o processo de mudar a linha ou coluna da matriz de modo a obter um pivô ideal.

* Sem pivoteamento: Escalonamento normal. Não altera o valor do pivô. Sujeito a erro de divisão por 0
* Pivoteamento Parcial: Ocorre troca de linhas da matriz para que o pivô seja o maior possivel.
* Pivoteamento total: Ocorre troca de colunas inteiras para que o pivô seja ideal.

Vamos nos focar no Pivoteamento Parcial. Basicamente, antes de você começar a zerar uma coluna, você tem que verificar se o elemento que será o pivô é o maior número dessa coluna, em módulo. Para isso basta fazer ```np.argmax(np.abs(A[i,j]))``` para achar o indice do maior valor da coluna, e então trocar a linha do pivô padrão pela desse novo pivô.
```
def pivoteamento(A,b,j):
    novoPivo = np.argmax(np.abs(A[j:, j])) + j
    A[[novoPivo, j]] = A[[j, novoPivo]]
    b[[novoPivo, j]] = b[[j, novoPivo]]
```
Basicamente só precisamos executar essa função dentro da função de escalonamento, dentro do loop dela.

Versão compacta:
```
import numpy as np
import pandas as pd

def gss(Ao,bo):
    s = len(Ao)
    A = np.copy(Ao)
    b = np.copy(bo)
    
    for i in range(0, s-1):
        #pivoteamento
        index = np.argmax(np.abs(A[i:,i]))+i 
        A[[index, i]] = A[[i, index]]
        b[[index, i]] = b[[i, index]]
        
        pivo = A[i,i];
        for j in range(i+1, s):
            k = -A[j, i]/pivo
            A[j] = A[j] + k*A[i]
            b[j] = b[j] + k*b[i]
            A [j,i] = 0
    
    return A,b

def res(A, b):
    s = len(A)
    x = np.zeros(s)
    
    #ultima raiz
    x[s-1] = b[s-1]/A[s-1,s-1]
    
    #outras
    for i in range(s-2, -1, -1):
        sum = b[i]
        for j in range(i, s):
            sum = sum - (A[i,j]*x[j])
        x[i] = sum/A[i,i]
    return x

np.random.seed(5)
Ao = np.random.rand(5,5)
bo = np.random.rand(5,1)

A, b = gss(Ao, bo)
x = res(A, b)
print(pd.DataFrame(A))
print(pd.DataFrame(b))
print(pd.DataFrame(A@x))
```

#### Fatoração LU
Dada uma matriz quadrada A semi-positiva, você vai decompor ela em uma matriz triangular inferior L, que possue os fatores multiplicativos de cada iteração do processo de escalonamento, e uma matriz que triangular superior U, que é o resultado do processo de escalonamento, de modo que **A = L\*U)**. Além disso, podemos calcular pois **L\*Y = b** e **U\*X = Y**

Você vai realizar o escalonamento normalmente a matriz resultante de vai ser U. Durante o processo você vai salvar todos os fatores multiplicativos, e então vai montar com eles a matriz inferior triangular L. OBS: Todos os elementos de de L são negativos, tipo, os elementos são $$-m_ij)$$
Lembrando que o *fator multiplicativo* citado é um valor $$m = - A[i+1][i]/A[i][i]$$. Você pega o valor na linha de baixo, na mesma coluna, e divide pela valor negativo do elem. de cima. Dessa forma quando você realizar a operação elementar para escalonar essa segunda linha, esse primeiro termo vai sumir.


#### Fatoração Cholesky
É usada para encontrar a solução de sistemas lineares cuja matriz dos coeficientes não é quadrada. Vamos  ter A = L\*L^T. Ao invés de resolver o problema, vamos aproximar a distancia da resposta desse sistema (que pode nao ter solução) para um sistema que tem solução. Esse é o metodo de minimos quadrados de algebra linear. Ou seja, queremos minimar o modulo (A\*X - B)². No final temos a equação: **(A^T)\*A\*X = (A^T)\*b**.

Apartir disso, se A é uma matriz simetrica (A = A^T) e se A é positiva definida (os dets das matrizes quadradas que começam no canto sup. esq. e vão crescendo são todas positivas) então temos com consequencia que **A = (L^T) * L**



###Métodos iterativos
Aqui nós queremos criar uma função/algoritimo do p(x), onde você obtem o x2 ao fazer p(x1)
É usado quando a matriz dos coeficientes tem muitos 0's ou quando o sistema é muito grande
Como normalmente os sistemas são grandes, nos guardamos as respotas, x1, x2, ..., xn em um vetor (do python)

#### Jacobi:
Dado um sistemas de equação, se você pega um valor de x e isola ele, basicamente você vai ter a figura a seguir:
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/jacobi-compacto.png)
Basicamente nos estamos isolando um xi e calculando ele em função de todos os outros x. Podemos colocar isso na forma de matriz:
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/jacobi-forma-matricial.png)
Aqui da pra ver mais claramente. Em cada linha, você pegar o coeficiente que está na diagonal principal (a) e utilizar o fator multiplicativo $$-1*1/a$$ depois disso você faz uma operação elementar de modo a deixar a diagonal principal igual à zero.
Repare que uma matriz c é criada, nela você simplismente divide o termo independente pelo coeficiente (a).
Você vai começar com valores iniciais de x e como qualquer outro método iterativo, isso pode convergir ou divergir. Uma das maneiras de verificar se o algoritimo vai convergir é calcular todos os autovalores (de algebra linear) e se todos eles forem, em módulo, menor que 1 (0 ponto alguma coisa) então ele converge.
Os criterios de parada mais comum são número max. de iterações e erro máximo menor que algo.

Ou seja, para resolver um problema pelo método de jacobi, você vai transformar os matrizes iniciais A, b nas matrizes D e c, calcular o proximo valor de x com base na equação matricial e então calcular o erro desse x em especifico com o seu anterior.
Claro que você não precisa montar a matriz certinha, fazer o produto de matrizes e etc, você pode usar a formula da imagem 1 para todos os x em uma única iteração.
Repare que como calculamos o erro para cada iteração, o números de "erros"/precisão vai ser igual ao número de variáveis.

####Gauss-Seidel:
É jeito mais rapido. Ele vai se aproveitar da "Proceduralidade" das linguagens. Quando você ver o código vai perceber que o novo valor de x1 (da iteração) vai ser calculado. Depois vai ocorrer o mesmo com o x2, ..., xn e isso é feito usando os valores iniciais.
O que o gauss-seidel faz é: já que você já calculou o novo x1 antes de calcular o x2, no calculo do x2 ao invés de usar o x1 antigo, vou usar o novo (da iteração)
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/gauss-seidel-compacto.png)
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/forma-matricial-gauss-seidel.png)

```
import numpy as np

def inp():
    n = int(input())
    A = np.zeros((n,n), float)
    b = np.zeros(n, float)
    err = np.zeros(2, float)
    for i in range(n):
        for j in range(n):
            A[i][j] = float(input())
    for k in range(n):
        b[k] = float(input())
    err[0] = float(input())
    err[1] = float(input())
    lim = 100
    return A, b, n, err, lim

def metamorfosis(A, b, n):
    D = np.zeros((n,n), float)
    c = np.zeros(n, float)
    coef = np.diag(A)
    
    for i in range(n):
        c[i] = b[i]/coef[i]
        for j in range(n):
            D[i,j] = -A[i,j]/coef[i]
            if i == j: D[i, j] = 0 #mesmo esquema do pivot.
    
    return D, c

def jacobi(D, c, lim, err, n):
    stp = 0; prec = 1;
    xi = np.zeros(n)
    xo = np.zeros(n)
    
    while (stp < lim) and (prec > err[0]) and (prec < err[1]):
        for i in range(n):
            xi[i] = c[i]
            for j in range(n):
                xi[i] += D[i][j]*xo[j]
        
        prec = np.sum((1 - xi)**2)**(1/2)
        xo = np.copy(xi) #pointers >> python
        stp += 1
    return xi, stp, prec

def gauss_seidel(D, c, lim, err, n):
    stp = 0; prec = 1;
    xi = np.zeros(n)
    xo = np.zeros(n)
    Di = np.triu(D)
    Ds = np.tril(D)
    while (stp < lim) and (prec > err[0]) and (prec < err[1]):
        for i in range(n):
            xi[i] = c[i]
            for j in range(n):
                xi[i] += Ds[i][j]*xi[j]
                xi[i] += Di[i][j]*xo[j]
        
        prec = np.sum((1 - xi)**2)**(1/2)
        xo = np.copy(xi) #pointers >> python
        stp += 1
    return xi, stp, prec

```

#### Convergência e mal condicionamento
Se TODOS os autovalores da matriz D forem, em módulo, maior que 1, então tanto jacobi quanto gauss-seidel vão convergir (chegar na solução correta).
Se essa condição não for comprida, nada pode-se dizer. Ou seja, mesmo que que exista algum autovalor maior que 1, é possivel que o sistema convirja.

Outra maneira de verificar a convergencia é analisar a *Dominância* da matriz. Uma matriz é dita dominante por linha se o elemento da linha que está na diagonal principal é maior que a soma de todos os elementos da linha.
Analogamente é dominante por coluna se TODOS os elementos da diagonal são maiores que a soma, em modulo, dos elementos de suas respectivas colunas.

Se é dominante ou por linha ou por coluna (ou pelos 2) o sistema vai convergir nos métodos de jacobi e gauss-seidel.
Em alguns casos será necessário trocar as linhas da matriz (ordem das equações) para que exista dominância. Como boa prática, teste a dominância na matriz inicial, se não der certo, permute as linhas da matriz e tente, e se não der certo permute as colunas da matriz.
No caso de permutar as colunas você vai precisar trocar a ordem do vetor incognitas x.

Uma matriz (sistema) é mal condicionado, se pequenas mudanças nos coeficientes geram grandes alterações na solução. Uma maneira de medir o condicionamento de uma matriz é calcular o cond(A) e verificar que, se cond(A) >> 1, então a matriz provavelmente está mal condicionada: cond(A) = ||A|| * ||Inversa(A)|| Onde Inversa(A) é a matriz inversa de A. E estamos calculando a norma dessas matrizes (não é o determinante)

O calculo da norma de uma matriz pode ser feita de várias maneiras:
1. Você soma o módulo dos elems. de todas as linhas. A soma-linha que for maior é o modulo (Norma inf)
2. Você soma o módulo dos elems. de cada coluna. A soma-coluna que for maior é o módulo (Norma 1)




## 5. Ajustamento e Interpolação
(intro à machine learning)

Existem situações onde nos temos os valores de x, e os valores de f(x), mas não sabemos qual é a função f que relaciona esses valores. Isso normalmente acontece no mundo real quando se está fazendo observações em um exprimento, ou uma enquente sobre um determinado produto, ou um relatorio de vendas, etc.
Normalmente esses dados apresentam-se tabelados, em excel ou etc. O procedimento varia dependendo do método, mas nesse curso vamos utilizar o seguinte:
- Dados os valores de xi e f(xi), vamos aproximar a função f por uma função P, onde $$P = a_0 * G_0 + a_1 * G_1 + ... + a_n * G_n$$ onde os "a's" são constantes/parametros e os "G's" são funções continuas/já conhecidas.
- Esse curso não tem como objetivo achar qual a  função $$G_i$$ é a ideal; Se detem em achar os melhores parâmetros "a" para que o problema seja bem aproximado. E para os probelmas simples, vistos aqui, recaimos em sistemas de equações lineares (seção anterior)

* Ajustamento: 
	- Tem como objetivo modelar o comportamento dos dados ao aproximar dos pontos. Basicamente nos vamos criar uma função $$P$$ que vai se aproximar ao ao comportamento teório dos dados ($$f$$). 
	- Essa aproximação é feita ao tentar reduzir a distância/minimizar a diferença entre $$P(x) - f(x)$$, esse é um dos processos mais comuns/diretos, conhecido como o método dos minimos quadrados (MMQ).
	- Justamente por ser uma aproximação de f, podemos *estrapolar* essas aproximações para cenários onde não temos dados, é dai que vem a parte preditiva dos algoritimos de machine learning, tudo fundamentado matematicamente.

* Interpolação:
	- Aqui o objetivo é criar uma função que passa exatamente por cima dos pontos. Nós não queremos uma função que aproxime, queremos uam função que descreva precisamente o comportamento dos dados.
	- Esse método é ideal para estimar o valor de f dentro de um intervalo finito de \[a,b\].
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/inter-ajus.png)


#### Método para ajustamento

Você vai aproximar a função f por $$P = \sum_{n=1} ^{m} a_i * G_i(x)$$ onde $$a_i$$ são os coeficientes que precisamos encontrar. O procedimento consiste em montar uma tabela, completar os valores, somar o valor de algumas colunas e resolver um sistema. Antes de mostrar isso vamos entender como avaliar se essa aproximação é boa.

Para saber se um modelo é bom você precisa comparar ele com pelo menos outro. A ideia é verificar a precisão do modelo ao calcular o valor P(xi) - f(xi) onde f(xi) é um valor tabelado (que vc já sabe). Ou seja temos que reduzir todos os $$R(x_i) = P(x_i) - f(x_i)$$ erros simultaneamente. Como valor de R pode ser negativo precisariamos achar o módulo, mas o módulo não é diferenciável para x = 0, por isso e outros pontos nos buscamos minimizar a função: $$σ(a_1, ..., a_n) = \sum_{i=0} ^{n} R^2(x_i) $$

Esse curso não cobre o *ajustamento não linear*, mas é valido saber que, em algums casos podemos converter uma eq não linear para uma linear.
Algo importante para notar é que a *linearidade* se refere as coeficientes, ou seja, você pode ter ln(x), x^(e^-2), etc, desde que os coeficientes se mantanhem lineares.
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/ajus-nLinear.png)

######Exemplo:
Uma pizzaria tem os dados da margem bruta captada (em milhares) de acordo com o número de clientes ativos (que executaram no mín 1 pedido) (também em milhares) em um determinado trimestre representados na tabela:
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/ajus-d1.png)

Sabendo disso desenvolva um modelo preditivo para estimar o valor vendido quando a população é 30 nos seguintes casos:

a) Usando uma representação do tipo $$ax + b$$

b) Usando uma representação do tipo $$b + a*ln(x)$$


######Resolução:
######a) pelo modelo do tipo $$ax + b$$. 

1. Comparar esse modelo com a representação teórica de P:
	* $$P = \sum_{n=1} ^{m} a_i * G_i(x)$$, verificamos que $$P = a_1 * G_1(x) + a_0 * G_0(x)$$ onde $$a_0 = b$$, $$G_0(x) = 1$$, $$a_1 = a$$,  $$G_1(x) = x$$. 
	* Uma convenção é fazer os sub-indeces decrecescentes, ou seja, você soma $$a_3 + a_2 + a_1$$ ao invés de $$a_1 + a_2 + a_3$$, mas isso não altera o resultado.
	* Opcional: Plotar um gráfico para visualizar os dados.

2. Montamos a tabela (de acordo com o número de termos em P):
	* ![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/tabela1-q1-ajustamento.png)
	* Os valores xi e f(xi) são os valores da tabela e os valores $$g_0$$ e $$g_1$$ são as imagens
	* Os demais termos/colunas são caracteriscos do Método dos mínimos quadrados (MMQ) e vc deve fazer o somátorio dos valores dessas colunas
	* Faça o somatório de todas as colunas e salve esses valores

3. Monte e resolva o sistema para achar os coefs:
	* Você vai usar os valores obtidos nos somatorios anteriores. Atenção à ordem: As ultimas 2 ou 3 (depende do num. de eqs) são os elementos b\[0\], b\[1\], b\[2\] respectivamente da matriz dos termos independentes. Os valores $$g_0^2$$, $$g_1^2$$, etc pertencem à diagonal principal, e o ultimos/outros valores que sobram são elementos simetricos em relação à diagonal principal da matriz (tipo, são o mesmo valor mas com a posição espelhada)
	* ![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/sist-q1.png)
	* Resolvendo esse sistema temos que a = 5 e b = 60
	
4. Defina P(x):
	* Com os valores "ideais" de a e b em mãos, Podemos montar $$P(x) = 5*x + 60$$
	* ![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/graf-q1-a.png)



######b) pelo modelo do tipo $$b + a*ln(x)$$ 
Uma vez que o passo a passo já foi ilustrado, a resolução vai ser mais curta (e terá o código)
1. $$P(x) = a*G_1(x) + b*G_0(x)$$ onde $$G_1(x) = ln(x)$$ e $$ G_0(x) = 1$$
2. Os dados são os mesmos:
	* ![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/tabela-2-q1-ajustamento.png)
3. Resolvendo o sistema: a = 11.62 e b = 48.83, logo $$P(x) = 48.83 + 11.62*ln(x)$$
	* ![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/graf2-q1.png)




Agora, como saber qual a melhor representação? Vamos utilizar aquela ideia teórica de somar todos os R(xi) = P(xi) - f(xi) (residuos) onde xi e f(xi) são valores da tabela, e então comparar Aquele que tiver o menor erro quadratico medio $$r^2$$ será o mais ideal.
Uma formula para calcular o $$r^2$$ é:
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/erro-quadratico-medio.png)
Você pode achar esses somatórios ao fazer aquelas tabelas, ou ao calcular manualmente. A ideia de usar tabelas é se aproveitar de ferramentas altamente produtivas para esse tipo de atividade como execel, R, ou python.
Se você calcular, verá que o $$r^2$$ de $$P_1$$ (modelo linear) é mais proximo de 1, ou seja, o termo subtraido de 1 é menor, logo o erro é menor.

Quebra-galho para não ter que fazer uma tabela gigante:
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/ex-complex-ajust.png)
(é ate 23 pq são 23 valores para x nesse exemplo)



### Métodos para interpolação:
Revisando brevemente, a interpolação tem como objetivo passar *exatamente* pelos pontos da tabela. A função que é a interpolação de uma função é o **Polinômio interpolador**.
Se o grau (números de pontos - 1 (x'ses na tabela - 1)) da função f é n, então $$P_n$$ é o polinômio interpolador de f se e somente si, o grau de  $$P_n$$ for menor ou igual ao de f e se  $$P_n(xi) = f(xi)$$ 

Ou seja, para que P seja polinômio interpolador ele não pode ter grau maior que n. Repare que o grau de P não precisa ser n, na realidade, existem algumas situações onde o grau ser muito elevado é mais prejudicial do que benéfico.
Além disso, essa abordagem só pode ser usado quandos os valores da tabela são confiáveis.

####Lagrange
Dada uma tabela com os valores de x e f(x), um polinomio interpolador de lagrange é
$$P_n = \sum_{i=0} ^{n} f(x_i)*L^n_i(x)$$
$$L^n_i(x) = \prod^n_j (x-x_j)/(x_i - x_j)$$ 
$$L^n_i(x) = \frac{(x-x_0) * (x-x_1) * (...) * (x-x_n)}{(x_i-x_0) * (x_i-x_1) * (...) * (x_i-x_n)}$$
Ex:
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/ex-lagrange.png)

O metodo de lagrange não é necessáriamente o melhor. Quanto se tem muitos pontos, ele tente a ser uma curva instavel e os valores nas caldas (beiras do intervalo de valores) é bem varável o que piora a credibilidade das aproximações.

Código raiz
```
def Lagrange(i,x,t):
	##calculo do produtorio
	"""
	obs:
	i é a iteração do somatorio
	x é um vetor com todos valores de x na tabela
	t é um valor para qual queremos aproximar. 
	Tipo: "quanto é g(2)?" t = 2 nesse caso.
	"""
	
    produto=1
    for l in range(len(x)):
        if (l!=i) :
            produto = produto*(t-x[l])/(x[i]-x[l])
    return produto

def g(t):
  soma = 0
  for i in range(len(x)):
  	#somatorio de f(x)*L(x)
    soma = soma + y[i]*Lagrange(i,x,t)
  return soma
```
Código nutela
```
from scipy.interpolate import lagrange
x = [0, 1, 2, 3]
y = [1, 3, 2, 0]
f = lagrange(x, y)
print(f)
```

####newton e gregory-newton

Para você utilizar esses metódos você precisa entender um operador chamado **diferença** e seus dois tipos.

1. Diferença dividida:
	![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/diferencaDivididaDEF.png)
2. Diferença simples:
	OBS: Para o caso de diferenças simples é necessário saber se a distribuição dos pontos é equidistante, ou seja, x1-x0 = x2-x1 (etc)
	![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/diferencaSimplesDEF.png)
OBS: As duas diferenças são calculadas de forma recursiva, onde normalmente você cria uma tabela cujo os valores vão formando uma piramide invertida crescente.

######Ex:
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/exDifSimples.png)
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/exDifDiv.png)

#####Fórmula do polinômio de newton:
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/PolimNEWT.png)
Onde todos os f(x) são obtidos através de diferenças divididas

#####Fórmula do polinômio de gregory-newton:
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/polimGreg.png)
Onde todos os f(x) são obtidos através de diferenças simples
OBS: Ou seja, os valores de x devem ser equidistantes

####Interpolação por partes:
Os outros metodos citados são sensiveis a mudanças. Se um dos valores tabelados muda, toda o polinômio se altera. Além disso, um maior número de valores tabelados não garante mais precisão.

#####Linear
A iterpolação linear por partes consiste em, para cada 2 pontos da tabela, criar uma reta que liga esses 2 pontos e então ligar todas essas retas. Com um grande número de valores tabelados essa interpolação de "ligar bolinhas" se aproximará da original

![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/iterLiPar.png)

UM dos problemas desse método é que não existe garantia de que os pontos desse polinômio tem derivadas de 1 e segunda ordem. Isso é um problema pois além de não podermos inferir informações relevantes (curvatura, maximos, min, etc) ela, assim como os outros métodos, vai se alterar muito para qualquer alteração nos pontos tabelados.

#####Spline Cúbico:
Ao invés de segmentos de reta usamos segmentos de curva, isso resolve o problemas das derivadas de 1 e 2 ordem e o problema da instabilidade.

![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/diferencaInterPar.png)
Dado n pontos, obtemos n-1 polinomios-curvas (BTW o grau delas é 3)

######Ex:
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/splineEx-p1.png)
Perceba:
- Nós construimos o sistema apartir dos valores tabelados (S0 contém x0 e x1)(S1 contem X1 e X2)
- Temos 8 incognitas e só 4 eqs. Precisamos analizar as derivadas de primeira e segunda ordem desses S's nos seus pontos de intersecão, ou sejam no ponto x1 (0,5), pois sabemos que nesse ponto suas derivadas são iguais
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/SplineEx-p2.png)
Temos 6eqs, precisamos de mais 2. Vamos as obter ao igualar as derivadas de segunda ordem, nos pontos extremos (1 e ultimos valores de x na tabela) à zero.
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/SplineEx-p3.png)
Com todas equações em mãos basta resolver o sistema(Eu acho que você pode resolver 2 sistemas separadamente, ao inves de um super gigante)
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/SplineEx-p4.png)


## 6. Integração numérica
É o processo de calcular uma integral usando métodos computacionais. Existem diversas opções de problemas, as mais comum involvem: 
- Você tem a função f(x) e o intevalo de integração
- É fornecido os dados tabelados (x, f(x)) e vc calcula a integral por essa tabela.
Os 2 métodos utilizados no curso são: Método dos trapézios (você aproxima a area em baixo da curva ao somar area de trapezios, quanto maior o número de trapezios melhor aproximação, mas quando esse número tende a infinito as vantagens deixam de aparecer); Método de Simpsons (é mesmo é?)

###Método dos trapézios:
Esse método calcula a integral de uma função f(x) dado uma tabela (x, f(x)) mas também pode calcular a integral se f(x) e os limites de integração forem dados. No primeiro caso temos a formula:
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/metTrap.png)
h é o "Passo" dos pontos, ou seja x1 - x0. Idealmente os pontos são equidistantes e h é constante, em caso diferente você usa esse método paras os grupos cujo h é igual e depois soma os resultados.
- E é a soma das imagens dos valores extremos do intervalo (f(0) + f(xn));
- P é a soma das imagens dos valores de indices pares (n inclue os extremos)
- I é a soma das imagens dos valores de indices impares (n inclue os extremos)

Uma pergunta que pode surgir é: quantos trapezios necessários para obter um erro menor que E? Desenvolva o codigo dos métodos dos trapezios e use:
```
n = 1
while abs(MTrapezio(x, y, n) - MTrapezio(x, y, n*2)) > E:
	n += 1
print(n)
# n é o número de trapezios usados pelo algoritimo
```

Exemplo de função de trapezios onde f(x) e os intevalos de integração são fornecidos:
```
def trap(n, a, b):
	#n = número de trapezios
	#a = intevalo inferior
	#b = intevalo superior
	h = (b-a)/float(n)
	integral = (h/2) * (f(a) + f(b)) #calculo nos extremos
	for i in range(1, int(n)): integral += h*(f(a + i*h))
	return integral
```

###Método de Simpson:
Diferente do método dos trapezios (que aproxima uma curva por trapezios/segmentos de reta, tendo baixa precisão), o método de simpson usa partes de parabolas para se aproximar dar curva. Nesse caso o número de pontos tabelados deve ser par.
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/poupaTempo-p1.png)
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/poupaTempo-p2.png)
```
def Simpson(listax,listay):
  import math
  tam = len(listax)
  div=tam-1
  h=((listax[div])-listax[0])/div
  somafunc=0
  for i in range(1,div):
    if (i%2)!= 0:
      somafunc=somafunc+(4*(listay[i]))
    else:
      somafunc=somafunc+(2*(listay[i]))
  res=(h/3)*(somafunc+(listay[0])+(listay[div]))
  return res 
print(Simpson(x,y))
```

Em resumo:
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/poupaTempo-p3.png)

### Erros associados à cada método:
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/poupaTempo-p4.png)
No método dos trapezios precisamos avaliar a segunda derivada da função e dentro dos valores tabelados de x, saber qual tem o maior valor absoluto na imagem (f(x)). Depois temos o erro. No método de Simpson fazemos o mesmo processo mas na 4 derivada de f(x).
Codigos:
```
from sympy import *
init_printing()
var('x,y')

def ErroTrapezio(listax,listay):
  tam=len(listax)
  div=tam-1
  h=((listax[div])-listax[0])/div
  n= div
  Max2 = abs(diff(diff(f(x), x), x).subs(x,listax[0]))
  for i in listax:
    M2 = abs(diff(diff(f(x), x), x).subs(x,i))
    if M2 > Max2:
      Max2 = M2
  erro= ((n*h**(3))*Max2)/12
  return erro
print(ErroTrapezio(listax,listay))

def ErroSimpson(listax,listay):
  tam=len(listax)
  div=tam-1
  h=((listax[div])-listax[0])/div
  n= div
  Max4 = abs(diff(diff(diff(diff(f(x), x), x), x), x).subs(x,listax[0]))
  for i in listax:
    M4 = abs(diff(diff(diff(diff(f(x), x), x), x), x).subs(x,i))
    if M4 > Max4:
      Max4 = M4
  erro= ((n*h**(5))*Max4)/180
  return erro
print(ErroSimpson(listax,listay))
```

##EDO
Equações diferenciais ordinarias, são usadas para modelar vários fenomenos naturais, por exemplo, sistemas massa-mola, circuitos RC e RL, etc.
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/edo-p1.png)
A ideia das EDO's é encontrar essa função f(x) desconhecida de modo que ela satisfaça o sistema. A solução analatica só consegue ser feita em EDO's de ordem 1. Um teorema diz que uma EDO de ordem N pode ser decomposta em um sistema com N EDO's de ordem 1, mas para EDO's quaisquer, utilizam-se metodos numericos.
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/edo-p2.png)

###Método de Euler (simples)
Ao usar uma expansão de taylor e aproximando $$y(x_n) = y_n$$, onde y = f(x) temos a expressão:
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/edo-p3.png)
onde os x são pontos do grafico, os y's são as imagens, y(x) = f(x), e h é o passo, a distancia entre os pontos. Os pontos não precisam ser equidistantes, dessa forma calcula-se o h para cada nova iteração. Quanto menor o valor de h melhor a aproximação.
* OBS: O termo f(x, y) pode ser substituido por y' (a derivada de primeira ordem de f(x), no mesmo ponto)

Exemplo:
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/edo-p4.png)
A questão nos dá a condição/ponto inicial (x = 0) e nos pede o valor em ponto de interesse (x = 1), desse modo, como o número de passos é 2, temos h = 0.5, logo:
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/edo-p5.png)
Ao aumentar o número de passos, h se torna menor e mais "iterações" são feitas, de modo que o erro absoluto diminue.

###Método de Heun (Euler modificado):
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/edo-p6.png)
Esse método consiste em fazer a correção dos erros ao achar um reta s(x) então achar uma reta m, ao tirar a media da reta s(x) com a r(x) (que é o metodo de euler simples). Depois disso vai ser necessário transduzir a reta m(x) para que possa "iterpolar" a função y(x) analitica. A eq resultante fica então definida como na figura.
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/poupaT-edo.png)
Vejamos o mesmo exemplo feito com o "euler simples" para poder comparar os metodos (O enunciado é o mesmo):
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/eulerDoidao-p1.png)
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/eulerDoidao-p2.png)
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/eulerDoidao-p3.png)

###Métodos de Runge-Kutta:
Os métodos de Runge-Kutta são métodos de passo simples, ou seja, y de (k+1) é determinado usando apenas de x de k e y de k. Diferentes dos 2 métodos anteriores ele não precisa saber de nenhuma derivada de f, mas sim de uma função phi. Os metodos de runge-kutta são classificados por ordens p. O de ordem p=1 é quando phi = f(x), ou seja, é um metodo de euler simples. Quando p=2 temos que phi = (1/2)*(f(x) + f(x+h, y + h*f(x))), que é o metodo de Heun (euler modificado).
Vamos trabalhar com o método de runge-kutta de 4 ordem (p = 4)
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/metodoRungeKutta.png)

#####Exemplo:
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/ex1-MRK.png)
![alt text](/home/flp/Downloads/its about time/1.Material/P3/CN/pics/ex2-MRK.png)

