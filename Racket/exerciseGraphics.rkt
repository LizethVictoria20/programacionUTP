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


(define (randomCircle indice)
    ((draw-ellipse Ventana) punto-partida 100 50 "pink")

)

(randomCircle 0)