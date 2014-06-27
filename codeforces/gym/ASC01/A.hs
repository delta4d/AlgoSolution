main = do
    n <- fmap read $ readFile "china.in" :: IO Integer
    writeFile "china.out" (show . head $ filter (\x -> gcd x n == 1) [n `div` 2, n `div` 2 - 1..])

-- 6959039	 2014-06-25 20:58:13	delta_4d	 A - Chinese Girls' Amusement	 Haskell	Accepted	60 ms	204 KB
