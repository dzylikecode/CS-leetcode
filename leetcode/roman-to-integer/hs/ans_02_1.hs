romanToInt :: (Num c, Ord c) => [Char] -> c
romanToInt = sum . judgeSign . map singleRomanToInt

singleRomanToInt :: Num a => Char -> a
singleRomanToInt ch = case ch of
  'I' -> 1
  'V' -> 5
  'X' -> 10
  'L' -> 50
  'C' -> 100
  'D' -> 500
  'M' -> 1000

judgeSign :: (Ord a, Num a) => [a] -> [a]
judgeSign [] = []
judgeSign [x] = [x]
judgeSign (x : y : rest)
  | x < y = -x : judgeSign (y : rest)
  | otherwise = x : judgeSign (y : rest)