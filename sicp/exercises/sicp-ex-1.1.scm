;10
;12
;8
;3
;6
; value a is 3
; value of b is (+ a 1), thus its 4

(+ a b ( * a b )) 
; is a sum of three elements: a, b, and a * b.
; which makes it 7 + 12 = 19

(= a b) ;is #f

(if (and (> b a) (< b (* a b)))
b
a)
; the above evalates to a or b. if the predicate is true,
; it will evaluate to b, otherwise, to a.
; it evaluates to b, and b == 4

( cond ((= a 4) 6)
       ((= b 4) (+ 6 7 a))
       (else 25))
; this guy evalates to the second condition, since b == 4,
; the result is a sum of 6, 7, and 3. 16.

(+ 2 (if (> b a) b a ))
; that's a summation of two things. can be also written as:

(+ 2
   (if
     (> b a)
     b
     a))
; so it looks like we're going to add 2 to either b, or a.
; since b, is in fact greaater than a, the operation is:
; 2 + b, where b is 4. result is 6.

(* (cond ((> a b) a)
         ((< a b) b)
         (else -1))
   (+ a 1))

; in here, we've got multiplication of two values,
; and since b is greater than a, the first one is b, 4
; and the other one is 4.
; result: 16.


