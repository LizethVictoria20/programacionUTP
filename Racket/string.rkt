#lang racket

; Investigar sub-string
; Hacer ejercicio que diga basandose en esa funcion usando lambda y un iterador automatico hacer proceso que 
; tome una lista de cadenas y con el resultado tener una lista de la mitad de las palabras Eje "Bolsa de agua"  "hola"
; con mas de dos palabras y que me imprima "Bolsa" y "agua" 


; (define (SubString text)
;     (define lista (string->list text))
;     (map (lambda (caracter) 
;             caracter
;             (cond
;                 [(char=? caracter #\space)
;                     (display (substring (list-ref lista 1) (list-ref lista 2)))
;                 ]
;             )
;             ) lista
;     )
; )



; ; (define (Spaces n)
; ;     (define value (SubString n))
; ;     (cond
; ;         [(string=? value " ")
; ;             (display n)
; ;         ]
; ;     )

; ; )




; ; ; (define (SubString)
; ; ;     (define text "Holis como estas")
; ; ;     (define sub (substring text 1 4))
; ; ;     (display sub)
; ; ; )
; (SubString "Hola como estas")

; (define list1 (list "perro azul" "marlo grande"))
; (map(lambda (palabra)
; (substring palabra 0 4 ))
; list1)


(define (sumaNaturales n)
  (if (= n 0)
      0


      5 + 4 = 9
      4 + 3
      3 + 2
      2 + 1
      1 + 0
      0

      (+ n (sumaNaturales (- n 1)))))


(sumaNaturales 5)

