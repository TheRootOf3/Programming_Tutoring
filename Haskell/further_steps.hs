reverseList :: [a] -> [a]
reverseList [] = []
reverseList xs = last xs : reverseList (init xs)


-- Eliminate consecutive duplicates of list elements.
-- remove_duplicates [1,2,3,3,3,3,4,4,4,5,6,6,1] = [1,2,3,4,5,6,1]

removeDuplicates :: Eq b => [b] -> [b]
removeDuplicates [] = []
removeDuplicates [x] = [x]
-- removeDuplicates (x:y:xs) = if x == y then removeDuplicates (y:xs) else x : removeDuplicates (y:xs)

removeDuplicates (x:y:xs) | x == y = removeDuplicates (y:xs)
                          | otherwise = x : removeDuplicates (y:xs)


doRandomStuff :: Int -> Int 
doRandomStuff x | x == 3 = 3
                | x == 2 = 1000
                | x > 3 = x+1
                | otherwise = x-1
                