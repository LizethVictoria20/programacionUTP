#lang racket
 
#|
Multiline comments
|#

; It's true or false
#t
#f

;Simple text wir duoble quote
(define silence "Shhhhh")
silence

;Define a variable with a number value
(define age 93)
age

;Define square 
(sqrt 4)


;Add
(define add (+ 2 3))
add


;When define double parenthesis it's call a list 
;(define ())

(define (media a b)
    (/ (+ a b ) 2 ))

(media 3 5)


(define (addSeveralNumbers a b c)
    (+ a b c))

(addSeveralNumbers 2 2 2)


;Know if a number is exact or no it'll result is true or false
(exact? 5)
(exact? 5.2)


;text escapar quotes. Display solo se usa cuanndo se quieren imprimer simbolos especiales para escapar.
(display "He told me \"yes\"\n")

;Salto de linea
(display "I am\nYou are")




; command /Applications/Racket\ v8.11.1/bin/racket extract.rkt