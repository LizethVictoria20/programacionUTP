#lang racket

;Creadores
;Lizeth Victoria Franco
;Santiago Castaño
;Stiven Tellez

(require (lib "Graphics.ss" "graphics"))
(require math)


(open-graphics)


(define posi-uno 250)
(define posi-dos 240)
(define punto-partida (make-posn posi-uno posi-dos))

(define ancho 600)
(define alto 600)
(define Ventana (open-viewport "Mi Paisaje" ancho alto))

;Colores
(define montains (make-rgb 0.6 0.8 0))
(define house (make-rgb 0.2 0.2 0))
(define roof (make-rgb 0.50 0.50 0.50))
(define skin (make-rgb 1 0.8 0.6))
(define dress (make-rgb 0.6 0.2 0.42))

((draw-viewport Ventana) (make-rgb 0.67 0.84 0.90))


(define (Sol)
    ;Sol
    ((draw-ellipse Ventana) (make-posn 175 80) 75 75 "yellow")
    (sleep 1)
    ((draw-solid-ellipse Ventana) (make-posn 175 80) 75 75 "yellow")
)

(define (Nubes)
    ;Nube 1
    ((draw-ellipse Ventana) (make-posn 100 100) 70 50 "black")
    ((draw-ellipse Ventana) (make-posn 120 90) 70 50 "black")
    ((draw-ellipse Ventana) (make-posn 140 100) 70 50 "black")
    (sleep 1)
    ((draw-solid-ellipse Ventana) (make-posn 100 100) 70 50 "white")
    ((draw-solid-ellipse Ventana) (make-posn 120 90) 70 50 "white")
    ((draw-solid-ellipse Ventana) (make-posn 140 100) 70 50 "white")
    (sleep 1)
    ;Nube 2
    ((draw-ellipse Ventana) (make-posn 230 100) 70 50 "black")
    ((draw-ellipse Ventana) (make-posn 250 90) 70 50 "black")
    ((draw-ellipse Ventana) (make-posn 270 100) 70 50 "black")
    (sleep 1)
    ((draw-solid-ellipse Ventana) (make-posn 230 100) 70 50 "white")
    ((draw-solid-ellipse Ventana) (make-posn 250 90) 70 50 "white")
    ((draw-solid-ellipse Ventana) (make-posn 270 100) 70 50 "white")

)

(define (Montanias)
    ;Montañas
    ((draw-rectangle Ventana) (make-posn 0 400) 600 200 "black")
    ((draw-ellipse Ventana) (make-posn 0 375) 200 70 "black")
    ((draw-ellipse Ventana) (make-posn 150 350) 170 100 "black")
    ((draw-ellipse Ventana) (make-posn 300 370) 190 70 "black")
    ((draw-ellipse Ventana) (make-posn 450 360) 200 70 "black")
    ((draw-ellipse Ventana) (make-posn 0 375) 50 50 "black")
    (sleep 1)
    ((draw-solid-rectangle Ventana) (make-posn 0 400) 600 200 montains)
    ((draw-solid-ellipse Ventana) (make-posn 0 375) 200 70 montains)
    ((draw-solid-ellipse Ventana) (make-posn 150 350) 170 100 montains)
    ((draw-solid-ellipse Ventana) (make-posn 300 370) 190 70 montains)
    ((draw-solid-ellipse Ventana) (make-posn 450 360) 200 70 montains)
    ((draw-solid-ellipse Ventana) (make-posn 0 375) 50 50 montains)

)

(define (Casa)
    ((draw-rectangle Ventana) (make-posn 50 370) 80 80 "black")
    ((draw-polygon Ventana) (list (make-posn 50 370 )
                                        (make-posn 90 310)
                                        (make-posn 130 370))
                                        (make-posn 0 0)  "black")
    (sleep 1)
    ((draw-solid-rectangle Ventana) (make-posn 50 370) 80 80 house)
    ((draw-solid-polygon Ventana) (list (make-posn 50 370 )
                                        (make-posn 90 310)
                                        (make-posn 130 370))
                                        (make-posn 0 0)  roof)
)

(define (Persona)
    ;Pies
    ((draw-line Ventana) (make-posn 440 400) (make-posn 440 450) "brown" )
    ((draw-line Ventana) (make-posn 450 400) (make-posn 450 450) "brown" )
    ;Brazos
    ((draw-line Ventana) (make-posn 440 380) (make-posn 475 360) "brown" )
    ((draw-line Ventana) (make-posn 440 380) (make-posn 410 360) "brown" )

    ;Vestido
    ((draw-polygon Ventana) (list (make-posn 410 400 )
                                        (make-posn 440 310)
                                        (make-posn 480 400))
                                        (make-posn 0 0)  "black")
    (sleep 1)
    ((draw-solid-polygon Ventana) (list (make-posn 410 400 )
                                        (make-posn 440 310)
                                        (make-posn 480 400))
                                        (make-posn 0 0)  dress)
    ((draw-solid-ellipse Ventana) (make-posn 415 300) 50 50 skin) 
)

(define (CreaPaisaje)
    (Sol) 
    (Nubes)
    (Montanias)
    (Casa)
    (Persona)
)
(CreaPaisaje)

(sleep 5) 
(close-viewport Ventana)
(close-graphics)
