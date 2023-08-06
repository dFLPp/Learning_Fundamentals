/*
É uma estrutura de dados do tipo LIFO (last-in first-out), onde o último elemento a ser inserido, será o primeiro a ser retirado.
Assim, uma pilha permite acesso a apenas um item por vez - o último a inserido.
Para processar o penúltimo item inserido, deve-se remover o último e assim sucessivamente.
Uma analogia seria com uma pilha de pratos onde o primeiro prato (valor) a ser colocado em uma mesa (vetor ou linked list) será o ultimo a ser retirado, se outros pratos forem colocados em cima dele (depois do primeiro).
Uma stack é caracterizada pela função push() para colocar valores na pilha e pop() para retirar valores
*/
#include <stdio.h>
#include <stdlib.h>

struct Pilha
{
	int topo; /* vai guardar a posição do elemento no topo */
	int capa;
	float *pElem;
};

void criarPilha(struct Pilha *p, int c)
{
	p->topo = -1;								   // passada uma struct do tipo Pilha. && Por padrão, a ultima posição SEMPRE é -1.
	p->capa = c;								   // usa-se "->" para se referir a uma propriedade dessa struct. "capa" é o tamanho da stack, passado na função como "c"
	p->pElem = (float *)malloc(c * sizeof(float)); // vai alocar/criar memória para a Stack/pilha de acordo com o tamanho maximo dela
}
int empty(struct Pilha *p)
{
	if (p->topo == -1)
		return 1; // se o primeiro elemento é -1 significa que ele também é o ultimo, logo a pilha está vazia
	else
		return 0;
}
int full(struct Pilha *p)
{
	if (p->topo == p->capa - 1)
		return 1; // se o "index" do ultimo elemento é igual ao tamanho definido para a pilha, então ela está cheia.
	else
		return 0;
}

void add(struct Pilha *p, float value)
{
	p->topo++;				   // aumenta o "index" do value antes de mesmo de atribuir algo à essa posição
	p->pElem[p->topo] = value; // value vai ser o valor do elemento da stack cujo index é igual ao "topo" atual.
}

float pop(struct Pilha *p)
{
	float aux = p->pElem[p->topo]; // salva o valor "mais alto" na stack
	p->topo--;					   //"diminue o indice" (aparentemente é o suficiente para desvincular/retirar o valor)
	return aux;					   // retorna o valor do "topo antigo"
}
float lastElem(struct Pilha *p)
{
	return p->pElem[p->topo]; // simplismente retorna o "valor mais alto" na stack
}

int main()
{
	struct Pilha pilha1;
	int size, fluxo;
	float value;

	printf("\nQual o tamanho da pilha? ");
	scanf("%d", &size);

	criarPilha(&pilha1, size); // lebre de que, quando se passa uma struct deve-se usar o seu endereço(&)

	while (1)
	{
		// loop infinito
		printf("\n1- Empilhar (push)\n");
		printf("2- Desempilhar (Pop)\n");
		printf("3- Mostrar o topo\n");
		printf("4- sair\n");
		printf("\n-> ");
		scanf("%d", &fluxo);

		switch (fluxo)
		{
		case 1: // push
			if (full(&pilha1) == 1)
				printf("\nSua pilha está cheia.\n");
			else
			{
				printf("\nValor para adicionar: ");
				scanf("%f", &value);
				add(&pilha1, value);
			}
			break;

		case 2: // pop
			if (empty(&pilha1) == 1)
				printf("\nSua pilha já está vazia\n");
			else
			{
				value = pop(&pilha1);
				printf("\n%.2f foi removido da pilha\n", value);
			}
			break;

		case 3: // mostrar o topo
			if (empty(&pilha1) == 1)
				printf("\nVocê ainda não adicionou nada!\n");
			else
			{
				value = lastElem(&pilha1);
				printf("\nO valor no topo da stack é: %.2f\n", value);
			}
			break;
		case 4:
			exit(0); // sai do programa, logo sai do loop infinito

		default:
			printf("\nOpção inválida\n");
		}
	}
}