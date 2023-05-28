#lang racket

;Tarea 1 Lenguajes-Racket;

;fibonacci;

(define (fib n)
    (if 
        (<= n 2)
        1
        (+ (fib ( - n 1))(fib (- n 2)))))

(fib 1)

;factorial;

(define (fac n)
    (if
        (= n 0)
        1
        ( * (fac(- n 1))n)))

(fac 8)

;miembro;

(define (miembro ele lista)
    (cond((null? lista)
        #f)
        ((equal? ele (car lista))
        #t)
        (else (miembro ele(cdr lista)))))

(miembro 'a '(a b c))
(miembro 'a '(x b c))

;Eliminar:

(define (eliminar ele lista)
    (cond((null? lista)

        lista)

        ((equal? ele (car lista))

        (cdr lista))

        (else 
        (cons (car lista)(eliminar ele(cdr lista))))))

(eliminar 'a '(a b c))
(eliminar 'a '(b c b))

;automovil;

(define (automovil list1 list2)
    (cond((null? list2)

        list
        )

        (else

        (list (cons(car list2)(car list1))(automovil (cdr list1)(cdr list2))))))

(automovil'(toyota rojo automatico) '(marca color tipo))

;Longitud;

(define (longitud listaEntrada)

    (define (cuenta listaEntrada num)
        (cond((null? listaEntrada)
            num
            )
            (else (cuenta(cdr listaEntrada) (+ num 1)))
            ))

    (cuenta listaEntrada 0))

(longitud '(uno dos tres cuatro))

;quicksort;

(define (qs listaD)
    (qsAux (car listaD)(cdr listaD)))

(define (qsAux pivot listaD)
    (cond((null? listaD)
            listaD)
        (( > pivot (car listaD))
            (write pivot)
            (append (pivot)(qs listaD)))
            
        (( < pivot (car listaD))
            (write pivot)
            (append (qs listaD)(pivot)))

        (else((qs (cdr listaD)))
        )))
        
;grafo;
;longituf 2;
;Arbol;
