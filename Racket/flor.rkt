#lang racket

;Lizeth Victoria Franco
;Stiven Tellez
;Santiago Castaño


(require (lib "Graphics.ss" "graphics"))
(require math)


(open-graphics)


(define posi-uno 250)
(define posi-dos 240)
(define punto-partida (make-posn posi-uno posi-dos))

(define ancho 600)
(define alto 600)
(define Ventana (open-viewport "miventana" ancho alto))

((draw-viewport Ventana) "pink")


(define (CrearFlor)
    ((draw-line Ventana) (make-posn 275 240) (make-posn 275 500) "brown")
    ((draw-ellipse Ventana) punto-partida 50 50 "yellow")
    
    ;Petalos
    ((draw-ellipse Ventana) punto-partida 110 50 "purple")
    (sleep 1)
    ((draw-ellipse Ventana)(make-posn 190 240) 110 50 "blue")
    (sleep 1)
    ((draw-ellipse Ventana) punto-partida 50 110 "red")
    (sleep 1)
    ((draw-ellipse Ventana) (make-posn 250 180) 50 110 "orange")
    (sleep 1)

    ;Solid

    ((draw-solid-ellipse Ventana) punto-partida 110 50 "purple")
    (sleep 1)
    ((draw-solid-ellipse Ventana)(make-posn 190 240) 110 50 "blue")
    (sleep 1)
    ((draw-solid-ellipse Ventana) punto-partida 50 110 "red")
    (sleep 1)
    ((draw-solid-ellipse Ventana) (make-posn 250 180) 50 110 "orange")
    (sleep 1)

    ((draw-solid-ellipse Ventana) punto-partida 50 50 "yellow")


    ;Hoja
    ((draw-ellipse Ventana) (make-posn 275 370) 30 40 "green")
    (sleep 1)
    ((draw-solid-ellipse Ventana) (make-posn 275 370) 30 40 "green")

    ; ((draw-solid-ellipse Ventana) punto-partida 110 50 "purple")



)
(CrearFlor)


