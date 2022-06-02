// Algumas constantes ?teis
#define ERRO_PILHA_VAZIA -1
#define ERRO_PILHA_CHEIA -2
#define TAMANHO_PALAVRA 5

typedef struct{
   int *dados;		// dados da pilha 
   int topo;		// indica o ?ndice do topo
   int capacidade;	// capacidade do vetor alocado
} Pilha;

void inicializa_pilha ( Pilha *p, int c );
int pilha_vazia ( Pilha p );
int pilha_cheia ( Pilha p );
int empilha ( Pilha *p, int info );
int desempilha ( Pilha *p, int *info );
void mostra_pilha ( Pilha p );
void desaloca_pilha( Pilha *p );

int **inicializa_grafo(int dimensao);
void mostra_grafo(int **grafo, int dimensao);