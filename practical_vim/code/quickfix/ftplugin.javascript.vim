setlocal makeprg=NODE_DISABLE_COLORS=1\ nodelint\ %

let &l:efm='%A'
let &l:efm.='%f\, '
let &l:efm.='line %l\, '
let &l:efm.='character %c:'
let &l:efm.='%m' . ','
let &l:efm.='%Z%.%#' . ','
let &l:efm.='%-G%.%#'
