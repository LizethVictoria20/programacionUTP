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
GAME_FONT = pygame.font.Font(None, 40) # Fuente simple (puedes cambiarla)

# --- Variables del Juego ---
GRAVITY = 0.25
bird_movement = 0 # <--- CORREGIDO: Nombre en minúsculas
FLAP_STRENGTH = -7 # Impulso hacia arriba (negativo porque Y aumenta hacia abajo)
GAME_ACTIVE = True # Controla si el juego está corriendo o en Game Over
SCORE = 0
HIGH_SCORE = 0 # Podríamos cargarlo/guardarlo de un archivo en una versión más avanzada

# Colores
WHITE = (255, 255, 255)
BLUE = (135, 206, 235) # Color cielo
GREEN = (0, 128, 0)   # Color tuberías
YELLOW = (255, 255, 0) # Color pájaro (simple rectángulo)
BLACK = (0, 0, 0)
RED = (255, 0, 0)     # Para Game Over

# --- Pájaro ---
# Usaremos un simple rectángulo por ahora. Más adelante se puede usar una imagen.
bird_rect = pygame.Rect(SCREEN_WIDTH // 4, SCREEN_HEIGHT // 2 - 50, 34, 24) # x, y, width, height

# --- Tuberías ---
pipe_list = []
PIPE_HEIGHTS = [200, 300, 400] # Alturas posibles para la tubería inferior
PIPE_GAP = 150 # Espacio vertical entre tuberías
PIPE_WIDTH = 70
PIPE_SPEED = 3

# Evento personalizado para generar tuberías periódicamente
SPAWNPIPE = pygame.USEREVENT
pygame.time.set_timer(SPAWNPIPE, 1200) # Generar una tubería cada 1.2 segundos (1200 ms)

# --- Funciones del Juego ---

def create_pipe():
    """Crea un par de rectángulos de tubería (superior e inferior) con una altura aleatoria."""
    random_pipe_pos = random.choice(PIPE_HEIGHTS)
    # Calcula la posición Y de la tubería inferior para que esté dentro de límites razonables
    bottom_pipe_y = random_pipe_pos
    # Calcula la posición Y de la tubería superior basándose en la inferior y el hueco
    top_pipe_y = bottom_pipe_y - PIPE_GAP - SCREEN_HEIGHT # Ajustamos altura para que se calcule desde arriba
    
    # Ajustar altura de la tubería superior para asegurar que cubra el espacio hasta arriba
    top_pipe_height = bottom_pipe_y - PIPE_GAP
    if top_pipe_height < 0: # Asegurarse que no tenga altura negativa si el hueco es grande
        top_pipe_height = 50 # O algún valor mínimo

    bottom_pipe = pygame.Rect(SCREEN_WIDTH + 50, bottom_pipe_y, PIPE_WIDTH, SCREEN_HEIGHT - bottom_pipe_y) # Empieza fuera de pantalla
    top_pipe = pygame.Rect(SCREEN_WIDTH + 50, 0, PIPE_WIDTH, top_pipe_height) # Empieza fuera de pantalla, desde y=0
    
    return bottom_pipe, top_pipe


def move_pipes(pipes):
    """Mueve todas las tuberías en la lista hacia la izquierda."""
    for pipe in pipes:
        pipe.centerx -= PIPE_SPEED
    # Filtra las tuberías que ya salieron de la pantalla para no acumularlas
    visible_pipes = [pipe for pipe in pipes if pipe.right > -50]
    return visible_pipes

def draw_pipes(pipes):
    """Dibuja todas las tuberías en la pantalla."""
    for pipe in pipes:
        pygame.draw.rect(SCREEN, GREEN, pipe)

def check_collision(pipes):
    """Verifica si el pájaro colisiona con alguna tubería o los límites de la pantalla."""
    # No necesitamos 'global bird_rect' aquí porque solo leemos su estado, no lo reasignamos.
    # La función puede acceder a variables globales para leerlas.

    # Colisión con tuberías
    for pipe in pipes:
        if bird_rect.colliderect(pipe):
            return True # Hubo colisión

    # Colisión con límites superior/inferior
    # Permitir que el pájaro toque el borde superior sin morir inmediatamente podría ser una opción
    # if bird_rect.top <= 0 or bird_rect.bottom >= SCREEN_HEIGHT:
    if bird_rect.bottom >= SCREEN_HEIGHT or bird_rect.top <= -50: # Dar un margen arriba
        return True # Hubo colisión

    return False # No hubo colisión

def update_score(pipes):
    """Actualiza la puntuación si el pájaro pasa entre un par de tuberías."""
    global SCORE, score_counted_pipes # Necesitamos modificar SCORE global

    passed_pipe = False
    bird_center_x = bird_rect.centerx

    # Iteramos sobre las tuberías de dos en dos (asumiendo que vienen en pares)
    # Es más seguro identificar las tuberías por su posición relativa al pájaro
    
    potential_scoring_pipes = [p for p in pipes if p.centerx < bird_center_x and p not in score_counted_pipes and p.width == PIPE_WIDTH]
    
    for pipe in potential_scoring_pipes:
        # Una forma sencilla es contar cuando el centro del pájaro pasa el borde derecho de la tubería
        if bird_center_x >= pipe.right:
            # Para evitar doble conteo, solo contamos las tuberías inferiores (una heurística)
             if pipe.top > SCREEN_HEIGHT / 2: # Asume que la tubería inferior está en la mitad inferior
                if pipe not in score_counted_pipes:
                     score_counted_pipes.add(pipe)
                     # Podríamos añadir también la tubería superior correspondiente si la tuviéramos referenciada
                     passed_pipe = True # Marcamos que hemos pasado *un* tubo (o par) en este frame

    if passed_pipe:
        # Solo incrementamos una vez por frame, incluso si pasa múltiples tuberías (poco probable)
        # Dividimos por 2 porque contamos una vez por par (pasando la tubería inferior)
        # Necesitamos una lógica más robusta aquí. Simplifiquemos por ahora:
        # Contaremos cada vez que el *centro* del pájaro pase el *centro* de una tubería
        # que no haya sido contada.
        
        score_increment = 0
        for pipe in pipes:
             # Comprobamos si el centro X del pájaro acaba de pasar el centro X de la tubería
             # y si esta tubería (identificada por su objeto) no ha sido contada aún.
             # Usamos solo la tubería inferior para contar una vez por par.
             is_bottom_pipe = pipe.bottom > SCREEN_HEIGHT / 2 # Heurística para tubería inferior
             if is_bottom_pipe and pipe.centerx < bird_center_x and pipe not in score_counted_pipes:
                 score_counted_pipes.add(pipe)
                 score_increment += 1
                 # print(f"Score! Passed pipe at {pipe.centerx}. Bird at {bird_center_x}") # Debug

        return score_increment

    return 0 # No incrementar


def display_score(game_state):
    """Muestra la puntuación actual o la final en la pantalla."""
    if game_state == 'main_game':
        score_surface = GAME_FONT.render(f'Score: {int(SCORE)}', True, BLACK) # Antialiasing activado (True)
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
    """Reinicia las variables del juego para una nueva partida."""
    # Necesitamos 'global' para modificar estas variables globales
    global bird_movement, SCORE, pipe_list, bird_rect, score_counted_pipes, GAME_ACTIVE

    bird_rect.center = (SCREEN_WIDTH // 4, SCREEN_HEIGHT // 2 - 50)
    bird_movement = 0 # <--- Asegúrate que usa el nombre correcto aquí también
    pipe_list.clear()
    score_counted_pipes.clear() # Reiniciar las tuberías contadas
    SCORE = 0
    GAME_ACTIVE = True # Reactiva el juego explícitamente
    # No es necesario devolver True, la activación se hace aquí


# --- Bucle Principal del Juego ---
score_counted_pipes = set() # Conjunto para rastrear tuberías ya puntuadas

while True:
    # 1. Manejo de Eventos
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            pygame.quit()
            sys.exit() # Cierra el programa limpiamente

        if event.type == pygame.KEYDOWN: # Si se presiona una tecla
            if event.key == pygame.K_SPACE:
                 if GAME_ACTIVE:
                     bird_movement = 0 # Resetea el movimiento para que el flap sea consistente
                     bird_movement = FLAP_STRENGTH # Aplica el impulso hacia arriba (no +=)
                 else: # Si no está activo, reiniciar
                      reset_game() # Llama a la función de reinicio

        # Generar tuberías solo si el juego está activo
        if event.type == SPAWNPIPE and GAME_ACTIVE:
            pipe_list.extend(create_pipe()) # Agrega el nuevo par de tuberías a la lista

    # 2. Lógica del Juego
    SCREEN.fill(BLUE) # Limpia la pantalla con el color de fondo

    if GAME_ACTIVE:
        # --- Pájaro ---
        bird_movement += GRAVITY
        bird_rect.centery += int(bird_movement) # Mueve el pájaro verticalmente
        pygame.draw.rect(SCREEN, YELLOW, bird_rect) # Dibuja el pájaro (rectángulo)

        # --- Tuberías ---
        pipe_list = move_pipes(pipe_list)
        draw_pipes(pipe_list)

        # --- Colisiones ---
        collision = check_collision(pipe_list)
        if collision:
            GAME_ACTIVE = False # Termina el juego
            # Actualizar high score al momento de la colisión
            if SCORE > HIGH_SCORE:
                HIGH_SCORE = SCORE

        # --- Puntuación ---
        # Solo actualiza la puntuación si el juego está activo
        score_increase = update_score(pipe_list)
        SCORE += score_increase
        display_score('main_game')

    else: # Pantalla de Game Over
        # Dibujar elementos estáticos
        draw_pipes(pipe_list) # Dibuja las tuberías donde quedaron
        pygame.draw.rect(SCREEN, YELLOW, bird_rect) # Pájaro en la posición de colisión
        display_score('game_over') # Muestra puntuación final y mensaje

    # 3. Actualizar Pantalla
    pygame.display.update()

    # 4. Controlar FPS
    CLOCK.tick(60) # Limita el juego a 60 fotogramas por segundo