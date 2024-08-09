#lang racket

#|Crear un programa que solicite al usuario su género (masculino o femenino) y su edad. 
Si es hombre y su edad es mayor o igual a 18 años, mostrar un mensaje indicando que puede 
inscribirse en el servicio militar. Si es mujer, mostrar un mensaje indicando que no tiene que inscribirse.|#

(define (Genero)
    (display "Ingresa tu genero: ")
    (define genero (read))

    (cond
        [(symbol? genero)
            (define convertionDato (symbol->string genero))
            (define lowerCase (string-downcase convertionDato))
            lowerCase
        ]
        [else
            (displayln "Ingrese un texto") (Genero)
        ]
    )
)


(define (edad)
    (display "Ingrese la edad: ")
    (define valorEdad (read))
    (cond
        [(number? valorEdad)
            valorEdad
        ]
        [else (displayln "Ingresa un valor númerico") (edad)]
    )
)


(define (Servicio)
    (cond
        [(string=? (Genero) "masculino")
            (cond
                [(>= (edad) 18)
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

