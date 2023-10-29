import pygame
import random

# Dimensões da janela
largura, altura = 800, 800

# Configuração do Pygame
pygame.init()
janela = pygame.display.set_mode((largura, altura))
pygame.display.set_caption("Visualização de Algoritmo Evolutivo")

# Cores
branco = (255, 255, 255)
preto = (0, 0, 0)

# Configuração da simulação
celula_raio = 30
torre_raio = 50
num_individuos = 50

# Função para desenhar o mapa
def desenhar_mapa(population):
    janela.fill(branco)
    
    # Desenhar as células
    for i in range(10):
        for j in range(10):
            pygame.draw.rect(janela, preto, (i * celula_raio, j * celula_raio, celula_raio, celula_raio), 1)

    # Desenhar a torre de vigilância
    pygame.draw.circle(janela, preto, (largura // 2, altura // 2), torre_raio)

    # Desenhar os indivíduos
    for indiv in population:
        if indiv.alive:
            pygame.draw.circle(janela, preto, (indiv.x * celula_raio, indiv.y * celula_raio), 5)

    pygame.display.update()

# Função para criar a população
def criar_populacao():
    population = []
    for _ in range(num_individuos):
        x = random.randint(0, 9)
        y = random.randint(0, 9)
        population.append(Individual(x, y, True))
    return population

# Classe para representar um indivíduo
class Individual:
    def __init__(self, x, y, alive):
        self.x = x
        self.y = y
        self.alive = alive

# Inicialização
population = criar_populacao()
desenhar_mapa(population)

# Loop principal
rodando = True
while rodando:
    for evento in pygame.event.get():
        if evento.type == pygame.QUIT:
            rodando = False

# Encerrar o Pygame
pygame.quit()
