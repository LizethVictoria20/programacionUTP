#lang racket

#|Crear un programa que solicite al usuario su edad y determine si es mayor o menor de edad.|#


;Función que valida si el valor que ingresa el usuario es un numero.
(define (validarNumero)
    (displayln "Ingrese tu edad: ")
    (define numero (read))
    (cond
        [(number? numero)
            (EsMayor numero)
        ]
        [else 
            (displayln "No es un número, ingrese un valor correcto.")
            (validarNumero)
        ]
    )
)

(displayln "Ingresa un número para saber si eres mayor de edad")
(define (EsMayor edad)
    (cond 
        [(>= edad 18)
            (displayln "Eres mayor de edad")
        ]
        [else
            (displayln "No eres mayor de edad")
        ]
        
    )
)
(validarNumero)

#|
Crear un programa que pida al usuario un número y determine si es positivo, negativo o cero.|#
(displayln "Ingresa un número para saber si es positivo, negativo o si es cero.")
(define (ClasificarNumero number)
    (cond 
        [(number? number)
            (cond
            [(> number 0)
                (display "El número ")
                (display number)
                (displayln " es positivo")
            ]
            [(< number 0)
                (display "El número ")
                (display number)
                (displayln " es negativo")
            ]
            [(= number 0)
                (display "El número ")
                (display number)
                (displayln " es cero")
            ]
            [else
                (displayln "Ingresa un número correcto ")
            ]
        )]
    [else 
        (displayln "Por favor ingrese un número valido: ")(ClasificarNumero (read))
    ])
    
)

(display "Ingresa numero: ")
(define numero (read))
(ClasificarNumero numero)


#|Crear un programa que solicite dos números y determine cuál es el mayor de los dos.|#
(displayln "Ingrese dos número para saber cúal es el mayor.")
(define (NumeroMayor n1 n2)
    (cond
        [(and ( number? n1 ) (number? n2))
            (cond
                [(> n1 n2)
                    (display n1)
                    (display " es mayor que ")
                    (display n2)
                ]
                [else
                    (display n1)
                    (display " es menor que ")
                    (display n2)
                ]
            )
        ]
        [else 
            (display "Uno de los dos datos ingresado es incorrecto, ingresa un valor númerico: " )(NumeroMayor (read) (read))
        ]
    )
)
(display "Ingresa primer número: ")
(define n1 (read))
(display "Ingresa segundo número: ")
(define n2 (read))
(NumeroMayor n1 n2)



#|Crear un programa que pida al usuario un número y determine si es par o impar.|#
(display "Ingrese un número para saber si es par o impar: ")
(define (ParOImpar n)
    (cond
        [(number? n)
            (cond
                [(= (remainder n 2) 0)
                    (display "El número ")
                    (display n)
                    (display " es un número par ")
                ]
                [else 
                    (display "El número ")
                    (display n)
                    (display " es un número impar ")
                ]
        )]
        [else (displayln "Por favor ingrese un número valido: ") (ParOImpar (read))]
    )
)
(ParOImpar (read))


#|Crear un programa que solicite al usuario su género (masculino o femenino) y su edad. 
Si es hombre y su edad es mayor o igual a 18 años, mostrar un mensaje indicando que puede 
inscribirse en el servicio militar. Si es mujer, mostrar un mensaje indicando que no tiene que inscribirse.|#



(define (Genero)
    (display "Ingresa tu genero: ")
    (define genero (read))
    (define convertionDato (symbol->string genero))
    (define lowerCase (string-downcase convertionDato))
    (cond
        [(string? lowerCase)
            lowerCase
        ]
        [else
            (display "Ingresa un genero valido")
        ]
    )
)


(define (ValidarNumero)
    (display "Ingrese un número: ")
    (define valorNumerico (read))
    (cond
        [(number? valorNumerico)
            valorNumerico
        ]
        [else (displayln "Ingresa un valor númerico") (ValidarNumero)]
    )
)


(define (Servicio)
    (cond
        [(string=? (Genero) "masculino")
            (cond
                [(>= (ValidarNumero) 18)
                    (display "Eres apto")
                ]
                [else (display "No eres apto")]
            )
        ]
        [(string=? (Genero) "femenino")
            (display "No es obligatorio")
        ]
        [else (display "Ingrese masculino o femenino")]
    )

)
(Servicio)


#|Crear un programa que pida al usuario un número del 1 al 7 y muestre el día de la semana correspondiente 
(por ejemplo, si el usuario ingresa 1, el programa debe mostrar "Lunes"). Si el usuario ingresa un número 
fuera de ese rango, el programa debe mostrar un mensaje de error.|#

(define (Week day)
    (cond
        [(number? day)
            (cond
                [(= day 1)
                    (display "Lunes")
                ]
                [(= day 2)
                    (display "Martes")
                ]
                [(= day 3)
                    (display "Miercoles")
                ]
                [(= day 4)
                    (display "Jueves")
                ]
                [(= day 5)
                    (display "Viernes")
                ]
                [(= day 6)
                    (display "Sabado")
                ]
                [(= day 7)
                    (display "Domingo")
                ]
                [else
                    (display "Ingrese un numero del 1 al 7: ") (Week (read))
                ])
        ]
        [else
            (display "Ingrese un número ") (Week (read))
        ]
        
    )

)

(display "Ingresa un número del 1 al 7 para saber el día de la semana: ")
(define day (read))
(Week day)


#|Crear un programa que solicite al usuario su salario mensual y determine si 
está por encima o por debajo del salario mínimo actual.|#

(define (SalarioMinino salarioUsuario)
    (define salario 1300000)
    (cond
        [(number? salarioUsuario)
            (cond
                [( > salarioUsuario salario)
                    (display "Salario por encima")
                ]
                [( < salarioUsuario salario)
                    (display "Salario por debajo")
                ]
                [( = salarioUsuario salario)
                    (display "Salario iguales")
                ]
            )
        ]
        [else
            (display "Ingrese un valor numerico: ") (SalarioMinino (read))
        ]
        
    )
)
(display "Ingrese salario: ")
(SalarioMinino (read))


#|Crear un programa que pida al usuario un número y determine si es 
divisible entre 3 y 5 al mismo tiempo.|#

(define (NumeroDivisible n)
    (define divisible1 (remainder n 3))
    (define divisible2 (remainder n 5))
    (cond 
        [(and (= divisible1 0) (= divisible2 0))
            (display "El número ")
            (display  n)
            (display  " es divisible por 3 y por 5 al mismo tiempo.")
        ]
        [else
            (display "El número ")
            (display  n)
            (display  " NO es divisible por 3 y por 5 al mismo tiempo.")
        ]
    )
)

(NumeroDivisible (read))


#|Crear un programa que solicite al usuario su nombre y su edad. 
Si la edad ingresada es menor a 18 años, mostrar un mensaje de bienvenida
 y mencionar que su contenido es apto solo para mayores de edad. 
 Si la edad es mayor o igual a 18, mostrar un mensaje de bienvenida 
 sin restricciones.|#


(define (MayorDeEdad nombre edad)
(cond
    [(number? edad)
        (cond
            [(>= edad 18)
                (display "Bienvenido ")
                (display nombre)
                (display ", puedes ver todo el contenido sin restricciones")
            ]
            [else
                (display "Bienvenido ")
                (display nombre)
                (display ", no puedes ver el  contenido. Solo es apto para mayores de edad.")
            ]
        )
    ]
    [else 
        (display "Ingrese una edad válida: ")
    ]

)
)
(display "Ingrese nombre: ")
(define name (read))
(display "Ingrese edad: ")
(define edad (read))

(MayorDeEdad name edad)



#|Crear un programa que pida al usuario dos números y determine
si el segundo es múltiplo del primero. Si es múltiplo, mostrar el 
resultado|#

(define (NumeroPar n1 n2)
    (define multiplo (modulo n2 n1))
    (cond
        [(and (number? n1) (number? n2))
            (cond
                [(= multiplo 0)
                    (display n2)
                    (display " es multiplo ")
                    (display n1)
                ]
                [else
                    (display n2)
                    (display " no es multiplo ")
                    (display n1)
                ]
            )
        ]
        [else
            (display "Ingrese valores númericos.")
        ]
        
    )
)
(display "Ingres el primer número")
(define n1 (read))
(display "Ingres el segundo número")
(define n2 (read))
(NumeroPar n1 n2)