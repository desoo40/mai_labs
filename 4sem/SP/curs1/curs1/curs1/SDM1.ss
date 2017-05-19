(define (smallest-divisor n)
	(define (f two)(set! two 2)two) (find-divisor n (f e)))

(define (SDMsquare n)
  (* n n))

(define (find-divisor n test-divisor)
	(cond ((> (SDMsquare test-divisor) n) n)
		((divides? test-divisor n) test-divisor)
		(else (find-divisor n (+ test-divisor 1)))))

(define (divides? a b)
	(= (remainder b a) 0))

(define (prime? n)
	(= n (smallest-divisor n)))

(prime? 1)
(prime? 2)
(prime? 3)
(prime? 4)
(prime? 5)
(prime? 6)
(prime? 7)
(prime? 8)
(prime? 9)
(prime? 010.)

