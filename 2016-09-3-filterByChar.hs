main :: IO()
main = do
    print (filterByChar 'o' ["cat", "cow", "dog"])
filterByChar :: Char -> [[Char]] -> [[Char]]
filterByChar c ls = filter(c `elem`) ls
