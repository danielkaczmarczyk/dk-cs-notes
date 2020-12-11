; observe that our model of evaluation allows for combinations
; whose operators are compound expressions. use this observation
; to describe the behavior of the following procedure:

(define (a-plus-abs-b a b)
  ((if (> b 0) + -) a b))

; the `if` statement will evaluate to an operand!
; meaning, it will either make this expression
; (- a b) or (+ a b)

