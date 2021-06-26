main :: IO()
main = do
    print(let (x:y):z = ["Curry"] in (x,y,z)) -- ('C',"urry",[])

    -- filter by char
    print (filterByChar 'o' ["cat", "cow", "dog"])
filterByChar :: Char -> [[Char]] -> [[Char]]
filterByChar c ls = filter(c `elem`) ls
