-- solved by copilot
romanToInt :: String -> Int
romanToInt s = romanToInt' s 0
  where
    romanToInt' [] acc = acc
    romanToInt' (x : xs) acc = romanToInt' xs (acc + romanToInt'' x xs)
    romanToInt'' x xs
      | x == 'I' && (xs /= [] && head xs == 'V') = 4
      | x == 'I' && (xs /= [] && head xs == 'X') = 9
      | x == 'X' && (xs /= [] && head xs == 'L') = 40
      | x == 'X' && (xs /= [] && head xs == 'C') = 90
      | x == 'C' && (xs /= [] && head xs == 'D') = 400
      | x == 'C' && (xs /= [] && head xs == 'M') = 900
      | x == 'I' = 1
      | x == 'V' = 5
      | x == 'X' = 10
      | x == 'L' = 50
      | x == 'C' = 100
      | x == 'D' = 500
      | x == 'M' = 1000
      | otherwise = 0