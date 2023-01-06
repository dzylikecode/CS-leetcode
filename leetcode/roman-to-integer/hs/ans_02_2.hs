romanToInt :: (Num c, Ord c) => [Char] -> c
romanToInt = sum . prefixSign . map singleRomanToInt

singleRomanToInt :: Num a => Char -> a
singleRomanToInt ch = case ch of
  'I' -> 1
  'V' -> 5
  'X' -> 10
  'L' -> 50
  'C' -> 100
  'D' -> 500
  'M' -> 1000

prefixSign :: (Ord a, Num a) => [a] -> [a]
prefixSign (x : y : rest)
  | x < y = -x : prefixSign (y : rest)
  | otherwise = x : prefixSign (y : rest)
prefixSign x = x