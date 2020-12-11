
; (define (<= x y)
;   (or (< x y) (= x y))
; )

(define (<= x y)
  (not (> x y))
)

(<= 3 4)
