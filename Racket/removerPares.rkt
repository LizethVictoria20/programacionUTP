#lang racket


(define (ListNew lista)
  (define head (car list))
  (display head)
)




(define (eliminar-pares numeros vacia)
  
  (define tamanio (length numeros))
  (display "tamanio ")(displayln tamanio)
  
  
  (cond
    [(> tamanio 0)
     (displayln "___________________________________________")
     (displayln "entro aqui")
     (displayln numeros)
     (displayln vacia)
     
    
     (cond
  
       [(even?(car numeros))
        (displayln "........................................")
        (define new-lista (remove (car numeros) numeros))
        (displayln new-lista)
        (eliminar-pares new-lista vacia)]

       [else
        (displayln "**************************************")
        (displayln "next index")
 
        (displayln (cdr numeros))
 
 
        (eliminar-pares (cdr numeros)(list (append vacia (car numeros))))
        ]
       )
     ]
    [else
     (displayln vacia)
     "termino esto"]
     
    )
  )

(eliminar-pares (list 1 2 3 4 5 6 7)(list))
(list? eliminar-pares)