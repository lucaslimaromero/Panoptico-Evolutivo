#include "evolucao.h"
// Funcoes do sistema evolutivo

// Funcao de mutacao de um individuo
void mutacao(Individuo *ind){
    // Nao havera mudanca das coordenadas x e y

    // Mutacao na velocidade
    if ((rand() / (float)RAND_MAX) < TAXA_MUTACAO) {
        ind->vx += (float)(rand() % 21 - 10) / 1000.0f;
        ind->vy += (float)(rand() % 21 - 10) / 1000.0f;
    }

    // Mutacao no tipo de movimento (1, 2 ou 3)
    if ((rand() / (float)RAND_MAX) < TAXA_MUTACAO) 
        ind->tipoDeMovimento = rand() % 3 + 1;
    

    // Mutacao na taxa de decaimento
    if ((rand() / (float)RAND_MAX) < TAXA_MUTACAO) 
        // Adiciona um valor aleatório entre -0.001 e 0.001 à taxaDecaimento
        if(ind->taxaDecaimento + ((rand() % 11) / 10000.0f) <= 1.0)
            ind->taxaDecaimento += ((rand() % 11) / 10000.0f);
        else
            ind->taxaDecaimento = 1.0f;
    
}

// Vamos implementar a funcao de selecao dos pais
int selecaoTorneio(vector<Individuo>& individuos){
    int tamTorneio = 10; // Tamanho do torneio (quantos individuos participarao)
    int indiceVencedor = rand() % individuos.size(); // A priori, sorteia qualquer um

    for(int i = 0; i < tamTorneio; i++){
        int indiceCandidato = rand() % individuos.size();
        if(calcularFitness(&individuos[indiceCandidato]) > calcularFitness(&individuos[indiceVencedor])){
            indiceVencedor = indiceCandidato;
        }
    }
    // cout << "Indice vencedor: " << indiceVencedor << endl;
    return indiceVencedor;
}

// Genocidio
void genocidio(vector<Individuo>& individuos, float raioMenor, float raioMaior, float probMorte){
    cout << "Genocidio acontecendo" << endl;
    for (auto it = individuos.begin(); it != individuos.end(); ) {
        if (!dentroDaPrisao(&(*it), raioMenor, raioMaior) && (rand() / (float)RAND_MAX) < probMorte) {
            // Remove o indivíduo do vetor
            it = individuos.erase(it);
        } else {
            ++it;
        }
    }
}

// Funcao de reproducao (crossover)
Individuo crossover(const Individuo& pai1, const Individuo& pai2) {
    Individuo filho;

    // Crossover nas características dos pais (aleatoriamente escolhendo)
    if(rand() % 2 == 0){
        filho.x = pai1.x;
        filho.y = pai1.y;
    } else{
        filho.x = pai2.x;
        filho.y = pai2.y;
    }

    filho.vx = (rand() % 2 == 0) ? pai1.vx : pai2.vx;
    filho.vy = (rand() % 2 == 0) ? pai1.vy : pai2.vy;
    filho.tipoDeMovimento = (rand() % 2 == 0) ? pai1.tipoDeMovimento : pai2.tipoDeMovimento;
    filho.taxaDecaimento = (rand() % 2 == 0) ? pai1.taxaDecaimento : pai2.taxaDecaimento;

    return filho;
}

// Função para calcular o fitness de um indivíduo
float calcularFitness(Individuo *ind) {
    // 1- Componente baseada na posição (região da coroa)
    float fitnessPosicao = 1.0f;

    // Verifica se o indivíduo está dentro da coroa (ajuste os valores conforme necessário)
    if (!dentroDaPrisao(ind, RAIO_MENOR, RAIO_MAIOR)) {
        fitnessPosicao = 0.0f;  // Penaliza indivíduos fora da coroa
    }

    // 2- Componente baseada na taxa de decaimento
    float fitnessDecaimento = ind->taxaDecaimento;

    // Combina os dois componentes (pode ajustar pesos conforme necessário)
    float fitnessFinal = fitnessPosicao * fitnessDecaimento;

    return fitnessFinal;
}

