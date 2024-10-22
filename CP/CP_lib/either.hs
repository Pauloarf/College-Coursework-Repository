let alter1 = i1("CP", True)
let alter2 = i2("Lei",1)

f = undistr . either (alter1) (alter2)





-------------------------------------------------
*Cp> cata g = g . (id -|- cata g) . out
*Cp> exp a = cata (either (const 1) (a*))
*Cp> exp 2 5
*** Exception: stack overflow
*Cp> -- Nao consegui definir o out
*Cp> mul a = cata (either (const 0) (a+))
*Cp> init = const (1,1)
*Cp> body(x,y) = (x+1,x*y)
*Cp> 
*Cp> f = cata (either init body)
*Cp> 
*Cp> fac = p2 . cata (either init body)
*Cp> -- Para que serve o init?
*Cp> 
*Cp> for body init = cata (either (const init) body)
*Cp> fac = p2 . for body (1,1)
*Cp> 
----------------------------------------------------



