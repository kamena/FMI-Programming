getMax a b = if a > b then a else b

myAbs x = if x < 0 then -x else x

fib 0 = 1
fib 1 = 1
fib x = fib(x - 1) + fib(x - 2)

--GCD
mygcd a 0 = a
mygcd a b = mygcd b (mod a b)

-- Heron's Formula
myP a b c = (a + b + c) / 2

heronFormula a b c = sqrt (myP a b c * (myP a b c - a) * (myP a b c - b) * (myP a b c - c) ) 

heronFormula2 a b c = sqrt (s * (s - a) * (s - b) * (s - c)) where s = (a + b + c) / 2

-- Is number prime

isPrime a = devide a 2

devide a x
	| x == a  =  "Yes"
	| mod a x == 0  =  "No"
	| otherwise  =  devide a (x + 1)



