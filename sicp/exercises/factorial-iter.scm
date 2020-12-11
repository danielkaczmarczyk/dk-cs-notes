(define (fact-iter product counter max-count)
  (if (> counter max-count)
     product
     (fact-iter
      (* counter product)
      (+ counter 1)
      max-count)))

(define (factorial x)
  (fact-iter 1 1 x))

(factorial 3)

