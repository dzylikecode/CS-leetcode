type OrdNum a b = (Num a, Ord b)

getElem :: (a, b) -> a
getElem = fst

getIndex :: (a, b) -> b
getIndex = snd

tupleIndex :: ((a1, a2), (a3, b), c) -> (a2, b)
tupleIndex (x, y, _) = (getIndex x, getIndex y)

getSum :: (a, b, c) -> c
getSum (_, _, sum) = sum

twoSum :: (Eq b, Num c, Num b, Enum b, Eq c) => [c] -> c -> (b, b)
twoSum nums target = tupleIndex . head . filter equalTarget . addlAll . generateOrdNum $ nums
  where
    equalTarget = (== target) . getSum

-- 虽然说可以优化为 1/2*n^2, 但是 n^2 也无所谓, 胜在简洁
addlAll :: (Eq b, Num c) => [(c, b)] -> [((c, b), (c, b), c)]
addlAll nums = [makePair x y | x <- nums, y <- nums, notTheSame x y]
  where
    notTheSame x y = getIndex x /= getIndex y
    makePair x y = (x, y, getElem x + getElem y)

generateOrdNum :: (Num b, Enum b) => [a] -> [(a, b)]
generateOrdNum nums = zip nums [0 ..]