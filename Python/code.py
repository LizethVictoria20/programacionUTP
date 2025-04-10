import pygame
import random
import sys

# --- Inicialización de Pygame ---
pygame.init()

# --- Constantes del Juego ---
SCREEN_WIDTH = 400
SCREEN_HEIGHT = 600
SCREEN = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Flappy Bird Base")

CLOCK = pygame.time.Clock()
GAME_FONT = pygame.font.Font(None, 40)

# --- Variables del Juego ---
GRAVITY = 0.25
bird_movement = 0
FLAP_STRENGTH = -7
GAME_ACTIVE = True
SCORE = 0
HIGH_SCORE = 0

# Colores
WHITE = (255, 255, 255)
BLUE = (135, 206, 235)
GREEN = (0, 128, 0)
YELLOW = (255, 255, 0)
BLACK = (0, 0, 0)
RED = (255, 0, 0)

# --- Pájaro ---
bird_rect = pygame.Rect(SCREEN_WIDTH // 4, SCREEN_HEIGHT // 2 - 50, 34, 24)

# --- Tuberías ---
pipe_list = []
PIPE_HEIGHTS = [200, 300, 400]
PIPE_GAP = 150
PIPE_WIDTH = 70
PIPE_SPEED = 3

# Evento personalizado
SPAWNPIPE = pygame.USEREVENT
pygame.time.set_timer(SPAWNPIPE, 1200)

# --- Funciones ---

def create_pipe():
    """Crea un par de tuberías (arriba y abajo) y les asigna un ID único."""
    random_pipe_pos = random.choice(PIPE_HEIGHTS)
    bottom_pipe = pygame.Rect(SCREEN_WIDTH + 50, random_pipe_pos, PIPE_WIDTH, SCREEN_HEIGHT - random_pipe_pos)
    top_pipe_height = max(random_pipe_pos - PIPE_GAP, 50)
    top_pipe = pygame.Rect(SCREEN_WIDTH + 50, 0, PIPE_WIDTH, top_pipe_height)
    pipe_id = random.randint(0, 1000000)
    return (bottom_pipe, top_pipe, pipe_id)

def move_pipes(pipes):
    new_pipes = []
    for bottom_pipe, top_pipe, pipe_id in pipes:
        bottom_pipe.centerx -= PIPE_SPEED
        top_pipe.centerx -= PIPE_SPEED
        if bottom_pipe.right > -50:
            new_pipes.append((bottom_pipe, top_pipe, pipe_id))
    return new_pipes

def draw_pipes(pipes):
    for bottom_pipe, top_pipe, _ in pipes:
        pygame.draw.rect(SCREEN, GREEN, bottom_pipe)
        pygame.draw.rect(SCREEN, GREEN, top_pipe)

def check_collision(pipes):
    for bottom_pipe, top_pipe, _ in pipes:
        if bird_rect.colliderect(bottom_pipe) or bird_rect.colliderect(top_pipe):
            return True
    if bird_rect.bottom >= SCREEN_HEIGHT or bird_rect.top <= -50:
        return True
    return False

def update_score(pipes):
    global SCORE, score_counted_pipes
    for bottom_pipe, top_pipe, pipe_id in pipes:
        if bottom_pipe.right < bird_rect.left and pipe_id not in score_counted_pipes:
            score_counted_pipes.add(pipe_id)
            SCORE += 1
            print(f"Punto! SCORE: {SCORE}")

def display_score(game_state):
    if game_state == 'main_game':
        score_surface = GAME_FONT.render(f'Score: {int(SCORE)}', True, BLACK)
        score_rect = score_surface.get_rect(center=(SCREEN_WIDTH // 2, 50))
        SCREEN.blit(score_surface, score_rect)
    elif game_state == 'game_over':
        score_surface = GAME_FONT.render(f'Score: {int(SCORE)}', True, BLACK)
        score_rect = score_surface.get_rect(center=(SCREEN_WIDTH // 2, 50))
        SCREEN.blit(score_surface, score_rect)

        high_score_surface = GAME_FONT.render(f'High Score: {int(HIGH_SCORE)}', True, BLACK)
        high_score_rect = high_score_surface.get_rect(center=(SCREEN_WIDTH // 2, SCREEN_HEIGHT - 100))
        SCREEN.blit(high_score_surface, high_score_rect)

        game_over_surface = GAME_FONT.render('GAME OVER', True, RED)
        game_over_rect = game_over_surface.get_rect(center=(SCREEN_WIDTH // 2, SCREEN_HEIGHT // 2 - 50))
        SCREEN.blit(game_over_surface, game_over_rect)

        restart_surface = GAME_FONT.render('Press SPACE to Restart', True, BLACK)
        restart_rect = restart_surface.get_rect(center=(SCREEN_WIDTH // 2, SCREEN_HEIGHT // 2 + 20))
        SCREEN.blit(restart_surface, restart_rect)

def reset_game():
    global bird_movement, SCORE, pipe_list, bird_rect, score_counted_pipes, GAME_ACTIVE
    bird_rect.center = (SCREEN_WIDTH // 4, SCREEN_HEIGHT // 2 - 50)
    bird_movement = 0
    pipe_list.clear()
    score_counted_pipes.clear()
    SCORE = 0
    GAME_ACTIVE = True

# --- Estado de puntuación ---
score_counted_pipes = set()

# --- Bucle principal ---
while True:
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit()

        if event.type == pygame.KEYDOWN:
            if event.key == pygame.K_SPACE:
                if GAME_ACTIVE:
                    bird_movement = 0
                    bird_movement = FLAP_STRENGTH
                else:
                    reset_game()

        if event.type == SPAWNPIPE and GAME_ACTIVE:
            pipe_list.append(create_pipe())

    SCREEN.fill(BLUE)

    if GAME_ACTIVE:
        bird_movement += GRAVITY
        bird_rect.centery += int(bird_movement)
        pygame.draw.rect(SCREEN, YELLOW, bird_rect)

        pipe_list = move_pipes(pipe_list)
        draw_pipes(pipe_list)

        if check_collision(pipe_list):
            GAME_ACTIVE = False
            if SCORE > HIGH_SCORE:
                HIGH_SCORE = SCORE

        update_score(pipe_list)
        display_score('main_game')

    else:
        draw_pipes(pipe_list)
        pygame.draw.rect(SCREEN, YELLOW, bird_rect)
        display_score('game_over')

    pygame.display.update()
    CLOCK.tick(60)
