#lang racket

#|
Disyunción al menos una es verdadera para que sea igual a verdad
Conjunción si o si ambas deben de ser verdaderas
|#
 (and (number? 3)(not (number? "3"))) #t
 (and (= 3 8)(not (number? "3"))) #f
 (or (= 3 8)(not (number? "3"))) #t
 (or (= 3 8)(string? '3)) #f


;condicionales
 (define salario 1000)
 (and ( < salario 2000) (> salario 1500 ))


 #|
 Definir funcion que reciba uan parametro n
 Utilizar los ejemplos de condiciones que estan en la diapositiva
 [(< n 10) 5.0]
 |#

 (define (greaterThan n)
     (cond
         [(< n 10) 5.0]
         [(< n 20) 5]
         [(< n 30) true]
         [else (display "n es menor")]
     )
 )
 (greaterThan (read))


#|
Definir funcion que tome 4 parametros para sacar el promedio porcentual de una materia 
|#


(define (notaFinal materia primerParcial segundoParcial quiz)
    (cond
        [(symbol=? materia 'Calculo) 
            (define promedio (+ (* primerParcial 0.3) (* segundoParcial 0.3) (* quiz 0.4)))
            (display promedio)
        ]
        [(symbol=? materia 'Ingles) 
            (define promedio (+ (* primerParcial 0.5) (* segundoParcial 0.2) (* quiz 0.3)))
            (display promedio)
        ]
        [(symbol=? materia 'Deportes) 
            (define promedio (+ (* primerParcial 0.7) (* segundoParcial 0.2) (* quiz 0.1)))
            (display promedio)
        ]

        [else (display "Ingrese una asignatura correcta")]
    )
)


(display "Ingrese la materia que quiere promediar: ")
(define materia (read))
(display "Ingrese la primera nota del primer parcial: ")
(define primerParcial (read))
(display "Ingrese la segunda nota del segundo parcial: ")
(define segundoParcial (read))
(display "Ingrese la nota del parcial final : ")
(define parcialFinal (read))


(notaFinal materia primerParcial segundoParcial parcialFinal)



#|
Misma funcion de arriba pero definida de una manera menos eficiente
|#

(define (notaFinal)
    (display "Ingresa el nombre de la materia: ")
    (define calculo 'M1)
    (define ingles 'M2)
    (define fundamentos 'M3)
    (define deportes 'M4)
    (define codigoMateria (read))(newline)
    (display "Ingresar nota parcial 1: ")
    (define notaP1 (read))(newline)
    (display "Ingresar nota parcial 2: ")
    (define notaP2 (read))(newline)
    (display "Ingresar nota parcial 3: ")
    (define notaP3 (read))(newline)
    (display "Ingresar nota parcial 4: ")
    (define notaP4 (read))(newline)
    (display "Ingresar nota quiz: ")
    (define quiz (read))(newline)
    (display "Esta es tu nota final: ")

    (cond
        [(symbol=? codigoMateria 'M1)
            (+ (+ (* notaP1 0.3) (* notaP2 0.3) (* quiz 0.4)))
        ]
        [(symbol=? codigoMateria 'M2)
            (+ (+ (* notaP1 0.3) (* notaP2 0.3) (* quiz 0.4)))
        ]
        [(symbol=? codigoMateria 'M3)
            (+ (+ (* notaP1 0.3) (* notaP2 0.3) (* quiz 0.4)))
        ]
    )
)
(notaFinal)


(define (validarNumero)
    (displayln "Ingrese tu edad: ")
    (define numero (read))
    (cond
        [(number? numero)
            (EsMayor numero)
        ]
        [else 
            (displayln "No es un número, ingrese un valor correcto")
            (validarNumero)
        ]
    )
)


#|
Escribe un programa que verifique si una persona es mayor de edad. 
Considera la mayoría de edad a partir de los 18 años.
|#

(define (EsMayor edad)
    (cond 
        [(>= edad 18)
            (display "Eres mayor de edad")
        ]
        [else
            (display "No eres mayor de edad")
        ]
        
    )
)
(validarNumero)




#|
Desarrolla una función que clasifique un número como ‘positivo’, ‘negativo’ o ‘cero’.
|#
(define (ClasificarNumero number)
    (cond
        [(> number 0)
            (display "El numero ")
            (display number)
            (display " es positivo")
        ]
        [(< number 0)
            (display "El numero ")
            (display number)
            (display " es negativo")
        ]
        [(= number 0)
            (display "El numero ")
            (display number)
            (display " es cero")
        ]
        [else
            (display "Ingresa un número correcto ")
        ]

    )

)
(display "Ingresa numero: ")
(define numero (read))
(ClasificarNumero numero)




#|Los años divisibles entre 100 y entre 400 sí que son bisiestos.
Todos los años bisiestos son divisibles entre 4. 
Aquellos años que son divisibles entre 4, pero no entre 100, son bisiestos. 
Los años que son divisibles entre 100, pero no entre 400, no son bisiestos. 
|#

(define (Bisiesto anio)
    (define divisibleCuatro (remainder anio 4))
    (display divisibleCuatro)

    (cond 
        [(= divisibleCuatro 0)
            (display "Es un año bisiesto.")
            ;100, 200, 300, 500, 600, 700
            ;son divisibles entre 100, pero no entre 400, no son bisiestos
        ]
        [(not (= divisibleCuatro 0))
            (display "No es un año bisiesto.")
            ;4, 8, 12, 16, 20, 24, 28
            ;son divisibles entre 4, pero no entre 100
        ]
        [else 
            (display "Ninguna")
        ]
    )
)
(Bisiesto (read))



(display "Ingresa 1 para suma, 2 para resta, 3 para multiplicacion y 4 para división: ")
(define (Calculadora operador num1 num2)
    (cond 
        [(= operador 1) 
            (+ num1 num2)
        ]
        [(= operador 2) 
            (- num1 num2)
        ]
        [(= operador 3) 
            (* num1 num2)
        ]
        [(= operador 4) 
            (/ num1 num2)
        ]
    
    )
)


(define operador (read))
(define num1 (read))
(define num2 (read))
(display "El resultado de la operación dada es: ")
(Calculadora operador num1 num2)
