; define a procedure that takes three arguments and returns
; the sum of the squares of the two larger numbers

(define (sq x) (* x x))

(define (sum-sq x y)
        (+ (sq x) (sq y)))

(define (get-larger x y)
        (cond ((> x y) x)
              (else y)))

(define (get-max-of-three x y z)
  (get-larger
    (get-larger x y)
    (get-larger y z)))

(define (get-smaller x y)
        (cond ((< x y) x)
        (else y)))

(define (get-min-of-three x y z)
  (get-smaller
    (get-smaller x y)
    (get-smaller y z)))

(define (is-neither x y z)
  (not
    (or
      (= x y)
      (= x z))))

(define (get-mid-of-three x y z)
  (define max (get-max-of-three x y z))
  (define min (get-min-of-three x y z))
  (cond
    ((is-neither x max min) x)
    ((is-neither y max min) y)
    ((is-neither z max min) z)))

(get-mid-of-three 1 2 3)

(define (sum-sqr-of-two-larger-nums x y z)
  (define max (get-max-of-three x y z))
  (define mid (get-mid-of-three x y z))
  (sum-sq max mid))

; test
(= 13 (sum-sqr-of-two-larger-nums 1 2 3))

