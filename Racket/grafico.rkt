#lang racket

(require (lib "Graphics.ss" "graphics"))
(require math)


(open-graphics)

(define azul-claro 0.2)
(define azul-oscuro 0.8)
(define rojo-claro 0.4)
(define azul 1)
(define verde 0.5)
(define no-verde 0)

(define color-uno (make-rgb rojo-claro verde azul))
(define color-dos (make-rgb rojo-claro no-verde azul-claro))
(define color-tres (make-rgb rojo-claro verde azul-oscuro))
(define color-cuatro (make-rgb rojo-claro no-verde azul))

(define lista-color (list color-uno color-dos color-tres color-cuatro))
(define lista-color-dos (list "white" "orange" "pink" "red"))

(define posi-uno 300)
(define posi-dos 300)
(define punto-partida (make-posn posi-uno posi-dos))

(define ancho 600)
(define alto 600)
(define Ventana (open-viewport "miventana" ancho alto))

((draw-viewport Ventana) "yellow")
(sleep 3)

(define (graficar-puntos indiceColor angulo longitud)
  (define tamanio (length lista-color))
  (define x (* longitud (cos angulo)))
  (define y (* longitud (sin angulo)))
  (define posicion (make-posn (+ posi-uno x) (+ posi-dos y)))
  ((draw-viewport Ventana) (list-ref lista-color-dos indiceColor))
  ((draw-line Ventana) punto-partida posicion (list-ref lista-color indiceColor))
  (sleep 1)
  (cond
    ;Caso base
    [(< angulo (* 2 pi)) 
      ;Aumenta el angulo
      ;                         1, 2 , 3 ,4
      (graficar-puntos (modulo (+ indiceColor 1) tamanio) (+ angulo 0.5) longitud)]
    [else 
      ((draw-string Ventana) (make-posn 250 150) "GAME OVER")]))

(graficar-puntos 0 0 100) ; Comenzar desde las 12 en punto (ángulo de pi/2 radianes). No funciona
(sleep 5)
(close-viewport Ventana)
(close-graphics)
