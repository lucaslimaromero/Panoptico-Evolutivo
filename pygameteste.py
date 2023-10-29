import pygame
import random

# Inicialize o Pygame
pygame.init()

# Defina as dimensões da janela
largura, altura = 800, 600

# Crie a janela
janela = pygame.display.set_mode((largura, altura))
pygame.display.set_caption("Visualização do Algoritmo Evolutivo")

# Defina a cor de fundo (branca)
cor_fundo = (255, 255, 255)

# Loop principal
rodando = True
while rodando:
    for evento in pygame.event.get():
        if evento.type == pygame.QUIT:
            rodando = False

    # Preencha o fundo com a cor branca
    janela.fill(cor_fundo)

    # Desenhe a coroa circular preta no centro
    centro_x, centro_y = largura // 2, altura // 2
    raio_coroa = 250
    pygame.draw.circle(janela, (0, 0, 0), (centro_x, centro_y), raio_coroa)

    # Desenhe os pontos pretos em movimento aleatório
    num_pontos = 50
    for _ in range(num_pontos):
        x = random.randint(0, largura)
        y = random.randint(0, altura)
        pygame.draw.circle(janela, (0, 0, 0), (x, y), 5)

    # Atualize a janela
    pygame.display.update()

# Encerre o Pygame
pygame.quit()
