import Data.List (elemIndex)

tooSum :: (Eq t, Num t) => [t] -> t -> Maybe (Int, Int)
tooSum = findOne 0

findOne :: (Eq t, Num t) => Int -> [t] -> t -> Maybe (Int, Int)
findOne initIndex arr@(x : xs) target =
  case findHeadPair initIndex arr target of
    Just pair -> Just pair
    Nothing -> findOne (initIndex + 1) xs target
findOne _ _ _ = Nothing

findHeadPair :: (Eq a, Num a) => Int -> [a] -> a -> Maybe (Int, Int)
findHeadPair initIndex (x : xs) target =
  case (target - x) `elemIndex` xs of
    Just index -> Just (initIndex, initIndex + index + 1)
    Nothing -> Nothing