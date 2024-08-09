#lang racket

;Escribir una función que imprima un mensaje de bienvenida por pantalla.

(define (welcomeMessage)
    (displayln "Holis")
)

(welcomeMessage)

(displayln "holis")

;Escribir una función que imprima tu nombre completo con dos var de función

(define (myName)
    (define firstName "Liz")
    (define lastName " Victoria")
    (display firstName)
    (displayln lastName)
)
(myName)


;Escribir una función que calcule el área de un triángulo dados su base y altura.
(define (triangleArea base height)
    (define operation (/( * base height) 2 )
    )
    operation
)

(triangleArea 4 6)


;Escribir una función que calcule el perímetro de un cuadrado

(define (squarePerimeter perimeter)
    (define operation ( * perimeter 4)
    ) 
    operation
)

(squarePerimeter 2)

;Escribir una función que convierta una temperatura en grados Fahrenheit a grados Celsius.

(define (temperature fahrenheit )
    (define convertion (/(- fahrenheit 32)5/9))
    convertion
)
(temperature 32)



(define (textWithReadFunction)
    (define text1 (read))
    (define text2 (read))
   (displayln (string-append text1 " " text2))
)

(textWithReadFunction)




#|
Crear funcion que reciba el nombre por dos parametros.
El symbol->string se usa para cambiar el tipo de dato de una variable
string-append se usa para concatenar textos/variables
|#
(define (fullName name last)
    (display "Mi nombre es: ")
    (define firstName name)
    (define convertionName(symbol->string firstName))
    (define lastName last)
    (define convertionLast (symbol->string lastName))     

    (define myName (string-append convertionName " " convertionLast))

    (display myName)
)

(fullName (read) (read))


#|
Misma funcion de arriba pero sin necesidad de cambiar el tipo de dato de la variable.
Para escribir el dato que se pide en la consola se deben poner entre comillas y 
sin espcacios para que asi la funcion string-append la reconozca como un string
|#
(define (fullName2 name last)
    (display "Mi nombre es: ")
    (define myName (string-append name " " last))
    (display myName)
)
(fullName2 (read) (read))


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

