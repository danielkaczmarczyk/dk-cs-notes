; syntax for if statements:
; (if <predicate> <consequent> <alternative>)

(define (abs x)
  (if (< x 0) (- x) x)
)
(abs -3)

