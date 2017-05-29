(define (two) 2)
(define (one) 1)
(define (six) 6)
(define (twelwe) 12)
(define (thirteen) 13)
(define (twenty-nine) 23)
(define (thirty) 30)

(define (smallest-divisor n)
	 (find-divisor n (two)))

(define (SDMsquare n)
  (* n n))

(define (find-divisor n test-divisor)
	(cond ((> (SDMsquare test-divisor) n) n) 
              (#t (cond ((divides? test-divisor n) test-divisor)
		(#t (find-divisor n (+ test-divisor (one))))))))

(define (divides? a b)
	(= (remainder b a) 0))

(define (prime? n)
	(= n (smallest-divisor n)))

(prime? (one))
(prime? (two))
(prime? (six))
(prime? (twelwe))
(prime? (thirteen))
(prime? (twenty-nine))
(prime? (thirty))
