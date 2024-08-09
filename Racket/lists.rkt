#lang racket
(define (AddLists)
  (define myList1 (list 1 2 3 4 5))


  (define myList2 (list 1 3 1 2 9))
                   ;(list 9 2 1 3 1)
  (define myList2Reverse (reverse myList2))


  (define add (list-ref myList1 0) )
  (define add1 (list-ref myList2Reverse 0))
  (define addFirstPosition (+ add add1))

  (define add2 (list-ref myList1 1))
  (define add22 (list-ref myList2Reverse 1))
  (define addSecondPosition (+ add2 add22))

  (define add3 (list-ref myList1 2))
  (define add33 (list-ref myList2Reverse 2))
  (define addThirdPosition (+ add3 add33))
    
  (define add4 (list-ref myList1 3))
  (define add44 (list-ref myList2Reverse 3))
  (define addFourthPosition (+ add4 add44))

  (define add5 (list-ref myList1 4))
  (define add55 (list-ref myList2Reverse 4))
  (define addFifthPosition (+ add5 add55))
  
  (define totalAdd (list addFirstPosition addSecondPosition addThirdPosition
                        addFourthPosition addFifthPosition))

  totalAdd

)

(AddLists)



Delete pair numbers

(define (EsImpar lista)
  (define firstNumber (list-ref myList 0))
  (define sencodNumber (list-ref myList 1))
  (define thirdNumber (list-ref myList 2))
  (define fourthNumber (list-ref myList 3))
  (define fifthNumber (list-ref myList 4))
  (define sixthNumber (list-ref myList 5))
  (define seventhNumber (list-ref myList 6))
  (define eighthNumber (list-ref myList 7))
  (define ninthNumber (list-ref myList 8))
  (define tenthNumber (list-ref myList 9))


  (define residuo (remainder firstNumber 2))
  (define residuo2 (remainder sencodNumber 2))
  (define residuo3 (remainder thirdNumber 2))
  (define residuo4 (remainder fourthNumber 2))

 
  (cond
    [(= residuo 0)
      (define deleteElem (remove firstNumber myList))
      (display deleteElem)
    ]
    [(= residuo2 0)
      (define deleteElem (remove sencodNumber myList))
      (display deleteElem)
    ]
    [(= residuo3 0)
      (define deleteElem (remove thirdNumber myList))
      (display "holi")
    ]
    [(= residuo4 0)
      (define deleteElem (remove fourthNumber myList))
      (display deleteElem)
    ]
  )
)
  (define myList (list 1 2 3 4 5 6 7 8 9 10))

(EsImpar myList)



(define (myLista)
    (define lista (list 1 2 3 4 5 6 7 8 9 10))
    lista

)

(myLista)


(define (hallarParametro a b)
    (+ (* a 2) (b 2))
)


(define (DarPerimetro as bs)
   (map hallarParametro as bs)
)

(define as (list 1 2 3 4 5))
(define bs (list 4 8 4 2 3))

(DarPerimetro as bs)


(define as (list 1 2 3 4 5))
(define bs (list 4 8 4 2 3))

(define (DamePerimetro2 as bs)
   (map (lambda (as bs) 
            (+ (* as 2) (* bs 2))
        )
    as bs
    )
)
(DamePerimetro2 as bs)


(define (IsEven number)
    (cond
        [(even? number)
            display(number)
        ]
        [else
            (display "Holis")
        ]
    )
)
(IsEven 2)



(define (isEven2 lista)
  (define ciclo (map IsEven lista))
  (display ciclo)

)

(isEven2 list(1 2 3 4 5 6))



; Hacer funcion donde se tenga una lista que solo se dajan numeros impares y multiplos de 3 con lambda 
; y con algun iteradores que henos visto



(define (OddAndMult)
(filter 
    (lambda (lista)
        (and (odd? lista) (= (remainder lista) 0))
    )
    list(1 2 3 4 5 6)
))


