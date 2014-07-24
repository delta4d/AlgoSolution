main = do
    let i = fmap (map read . words) getLine :: IO [Int]
    [n, b] <- i
    a <- i
    if n == 1
        then print b
        else print $ max b $ foldl1 max $ zipWith (\x y -> b`mod`x+b`div`x*y) (init a) (tail $ scanr1 max a)

-- 7210782	2014-07-23 20:30:45	delta_4d	B - Martian Dollar	Haskell	Accepted	60 ms	1100 KB
