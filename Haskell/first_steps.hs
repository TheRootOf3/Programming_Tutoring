square :: Int -> Int 
square a = a * a

add :: Int -> Int -> Int
add a b = a + b

applyTwice :: (Int -> Int) -> Int -> Int 
applyTwice func a = func (func a)


firstElement :: [Int] -> Int 
firstElement [] = -1
firstElement (x:xs) = x


sumAllElements :: [Int] -> Int 
sumAllElements [] = 0
sumAllElements (x:xs) = x + sumAllElements xs
