#lang racket

;Delete pair numbers




; (define (EsImpar)
;   (define myList (list 1 2 3 4 5 6 7 8 9 10))
;   (define firstNumber (list-ref myList 0))
;   (define sencodNumber (list-ref myList 1))
;   (define thirdNumber (list-ref myList 2))
;   (define fourthNumber (list-ref myList 3))
;   (define fifthNumber (list-ref myList 4))
;   (define sixthNumber (list-ref myList 5))
;   (define seventhNumber (list-ref myList 6))
;   (define eighthNumber (list-ref myList 7))
;   (define ninthNumber (list-ref myList 8))
;   (define tenthNumber (list-ref myList 9))


;   (define residuo (remainder firstNumber 2))
;   (define residuo2 (remainder sencodNumber 2))
;   (define residuo3 (remainder thirdNumber 2))
;   (define residuo4 (remainder fourthNumber 2))

;   (cond

;     [(= residuo 0)
;       (define deleteElem (remove firstNumber myList))
;       (display deleteElem)
;     ]
;     [(= residuo2 0)
;       (define deleteElem (remove sencodNumber myList))
;       (display deleteElem)
;     ]
;     [(= residuo3 0)
;       (define deleteElem (remove thirdNumber myList))
;       (display "holi")
;     ]
;     [(= residuo4 0)
;       (define deleteElem (remove fourthNumber myList))
;       (display deleteElem)
;     ]
;   )
; )

; (EsImpar)


; (define (EsImpar lista)
; (define myList (list 1 2 3 4 5 6 7 8 9 10))

;   (define firstNumber (list-ref myList 0))
;   (define sencodNumber (list-ref myList 1))
;   (define thirdNumber (list-ref myList 2))
;   (define fourthNumber (list-ref myList 3))
;   (define fifthNumber (list-ref myList 4))
;   (define sixthNumber (list-ref myList 5))
;   (define seventhNumber (list-ref myList 6))
;   (define eighthNumber (list-ref myList 7))
;   (define ninthNumber (list-ref myList 8))
;   (define tenthNumber (list-ref myList 9))


;   (define residuo (remainder firstNumber 2))
;   (define residuo2 (remainder sencodNumber 2))
;   (define residuo3 (remainder thirdNumber 2))
;   (define residuo4 (remainder fourthNumber 2))

 
;   (cond
;     [(= residuo 0)
;       (define deleteElem (remove firstNumber myList))
;       (display deleteElem)
;     ]
;     [(= residuo2 0)
;       (define deleteElem (remove sencodNumber myList))
;       (display deleteElem)
;     ]
;     [(= residuo3 0)
;       (define deleteElem (remove thirdNumber myList))
;       (display "holi")
;     ]
;     [(= residuo4 0)
;       (define deleteElem (remove fourthNumber myList))
;       (display deleteElem)
;     ]
;   )
; )

; (EsImpar myList)



; (define (isEven lista)
;   (define ciclo )
;   (display ciclo)

; )

; (isEven list(1 2 3 4 5 6))


; (define (sumaNaturales n)
;   (cond
;     [ (= n 0) 0]
;     [else (+ n (sumaNaturales (- n 1)))]
    
;   ))
; (sumaNaturales 10)


; 5+4 
; 4+3
; 3+2
; 2+1
; 1+0

(define (MiLista lista n size)
  ;5
  (cond
    [(= n size)
      0
    ]
    [else 
      (+ (list-ref lista n) (MiLista lista (+ n 1)))
    ]
  )
)

(define lista (list 1 2 3 4 5 6 7 8 9 10))
(MiLista lista 0 (length lista))


;Resolver funcion de Fibonacci, factoria y potencia de 2