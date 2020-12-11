; formula for a better guess is 
; (value / guess) + guess
; -----------------------
;            2

(define (square x) (* x x))

(define (average x y) (/ (+ x y) 2))

(define (get-better-guess guess value)
  (average (/ value guess) guess))

(define (good-enough guess value)
  (< (abs (- value (square guess)))
     0.001))

(define (sqrt guess value)
  (if (good-enough guess value)
    guess
    (sqrt (get-better-guess guess value)
          value)))

