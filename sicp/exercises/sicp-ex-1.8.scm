(define (square x) (* x x))

(define (get-new-guess value current-guess)
  (/
    (+ (/ value (square current-guess)) (* 2 current-guess))
    3))

(define (cube x) (* x x x))

(define (good-enough value guess)
  (< (abs (- value (cube guess))) 0.001))

;(good-enough 5 1.709975946676697)

(define (croot guess value)
  (if (good-enough value guess)
      guess
      (croot (get-new-guess value guess) value)))

(croot 1 5)
  
