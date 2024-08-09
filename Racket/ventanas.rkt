#lang racket (require (lib "graphics.ss" "graphics"))
(open-graphics)


(define Ventana (open-viewport "miventana" 800 300))
((draw-viewport Ventana) "pink")

(define (evento)
    (define tecla (get-key-press Ventana))
    (define tecla1 (key-value tecla))
    (display tecla1)
)

(evento)ç