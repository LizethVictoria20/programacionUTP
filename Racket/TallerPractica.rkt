#lang racket


; Implementa una función que tome dos listas de números y devuelva una nueva lista que contenga 
; la suma de los elementos correspondientes de cada lista. Utiliza la función map y lambda.

; (define (ListaNumeros a b)
;     (define nuevaSuma (map (lambda (lista1 lista2)
;         (+ lista1 lista2))
;             a b)
;     )
;        (display nuevaSuma)
; )

; (ListaNumeros (list 1 3 4) (list 4 5 2))


; Implementa una función que tome una lista de números y devuelva una nueva lista que contenga 
; sólo los números pares. Utiliza la función filter y lambda.
; (define (miLista)
    
;     (filter (lambda  (palabra)
;         (define letra1 (substring palabra 0 1))
;            (cond
;             [(string=? letra1 "m")
;                0
;                 (displayln palabra)        
;             ]
;         )                  
;     )'("mariposa" "daniel" "mango" "peraa"))  

; )
; (miLista)


; Diseñe un programa para obtener el grado de eficiencia de un empleado de una fábrica de zapatos, 
; de acuerdo a las siguientes condiciones, que se le imponen para un período de prueba:
; a. Menos de 150 zapatos defectuosos. 
; b. Más de 8000 zapatos producidos.  
; El grado de eficiencia se determina de la siguiente manera:

;          Si no cumple ninguna de las condiciones, grado 5.
;          Si sólo cumple la primera condición, grado 6.
;          Si sólo cumple la segunda condición, grado 7.
;          Si cumple las dos condiciones, grado 8. ---



; (define (Eficiencia zapDefectuosos zapProducidos)
;     (cond
;         [(> zapProducidos 8000)
;             (display "Es grado 7")
;         ]
;         [(< zapDefectuosos 150)
;             (display "Es grado 6")
;         ]
;         [(and (< zapDefectuosos 150) (> zapProducidos 8000))
;             (display "Es grado 8")
;         ]
;         [else
;             (display "Es grado 5")
;         ]
    
;     )

; )
; (display "Ingrese la cantidad de zapatos defectuosos: ")
; (define zapDefectuosos (read))
; (display "Ingrese la cantidad de zapatos producidos: ")
; (define zapProducidos (read))
; (Eficiencia zapDefectuosos zapProducidos)


; Una compañía dedicada al alquiler de motos cobra un valor fijo de $100.000 para los primeros 100 Km de recorrido.
; Para más de 100 Km y hasta 500 Km, cobra un valor adicional de $3000 por cada kilómetro en exceso sobre 100 KM. 
; Para más de 500 Km. cobra un monto adicional de $ 1000 por cada kilómetro en exceso sobre 500 KM. Los precios 
; NO incluyen el 16% del IVA. Diseñe un algoritmo que determine el valor a pagar por el alquiler de la moto  con el IVA.


; (define (alquilerDeMotos a)

;     (define masde100 (+ 100000(* (- a 100) 3000)))
;     (define masde500 (+ (+ ( * 400 3000) 100000)(* (- a 500) 1000)))
;     (define iva (* masde100 0.16))
;     (define iva500 (* masde500 0.16))

;     (cond
;             [(<= a 100)
;                 (displayln "Son $100,000")
;             ]
;             [(and (> a 100)(<= a 500)) 
;                 (displayln (+ masde100 iva))
;             ]
;             [(> a 500)
;                 (displayln (+ masde500 iva500))
;             ]
;             [else 
;                 (displayln "Ingrese un valor correcto" (alquilerDeMotos))
;             ]
;         )
; )

; (alquilerDeMotos (read))



;Crea un programa el cual quite de una lista de juguetes aquellos que superen el precio limite dado por el usuario.

; (define (ListaJuguetes lista)

;    (define juguetes (map (lambda (unJuguete)
;          (display unJuguete))
;        lista))
    

;     (display juguetes)

; )

; (define juguetitos (list "carrito" "caballito" " osito" "trencito"))

; (ListaJuguetes juguetitos)





; (define (Fibonacci length n num)
;    (cond
;       [(= length 0)
;          (define "end")
;       ]
;       [(= n 1)
;          1
;       ]
;       [else
;             ;3 - 1 = 2          3 - 2 = 1
            
         
;          (+ (Fibonacci(- n 1)) (Fibonacci(- n 2)))
;       ]
;    )
; )


; Crear algoritmo que de forma recursiva pasar un número arabico (5) 
;imprimirlo en númeración roman (V)


(define (decimal-a-romano n)
  (cond
      ((= n 1) "I")
      ((= n 5) "V")
      ((= n 10) "X")
      ((= n 50) "L")
      ((= n 100) "C")
      ((= n 500) "D")
      ((= n 1000) "M")
      ((< n 1) "")
      ((>= n 1000) (string-append "M" (decimal-a-romano (- n 1000))))
      ((>= n 900) (string-append "CM" (decimal-a-romano (- n 900))))
      ((>= n 500) (string-append "D" (decimal-a-romano (- n 500))))
      ((>= n 400) (string-append "CD" (decimal-a-romano (- n 400))))
      ((>= n 100) (string-append "C" (decimal-a-romano (- n 100))))
      ((>= n 90) (string-append "XC" (decimal-a-romano (- n 90))))
      ((>= n 50) (string-append "L" (decimal-a-romano (- n 50))))
      ((>= n 40) (string-append "XL" (decimal-a-romano (- n 40))))
      ((>= n 10) (string-append "X" (decimal-a-romano (- n 10))))
      ((>= n 9) (string-append "IX" (decimal-a-romano (- n 9))))
      ((>= n 5) (string-append "V" (decimal-a-romano (- n 5))))
      ((>= n 4) (string-append "IV" (decimal-a-romano (- n 4))))
      (else (string-append "I" (decimal-a-romano (- n 1))))
   )
)

(displayln (decimal-a-romano 333))