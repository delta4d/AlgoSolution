main = do
    let i = fmap (map read . words) getLine :: IO [Int]
    [x, y] <- i
    n <- fmap head i :: IO Int
    print $ f ((n-1)`mod`6) x y
f m x y
    | m == 0 = g $ x `mod` mm
    | m == 1 = g $ y `mod` mm
    | m == 2 = g $ (y - x) `mod` mm
    | m == 3 = g $ (-x) `mod` mm
    | m == 4 = g $ (-y) `mod` mm
    | m == 5 = g $ (-y + x) `mod` mm
    where mm = 1000000007
g x
    | x < 0 = x + mm
    | otherwise = x
    where mm = 1000000007

-- 7177301	2014-07-19 20:58:32	delta_4d	B - Jzzhu and Sequences	Haskell	Accepted	46 ms	0 KB
