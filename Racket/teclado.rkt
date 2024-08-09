#lang racket

(require(lib "Graphics.ss""graphics"))

; apertura de la libreria
(open-graphics)

; definir una var tipo ventan
(define ventana(open-viewport "miventana" 800 500))
;((draw-viewport ventana))



(define (escribir i)
  (define teclado (get-key-press ventana))
  (define tecla (key-value teclado))
  (cond
    [(= i 100)"fin "]
    [else
      (display nueva)
      
      (escribir (+ i 1))
    ]
  )
)

(escribir 0)