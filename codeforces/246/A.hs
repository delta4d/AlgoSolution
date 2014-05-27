main = do
    [n,k] <- fmap (map read . words) getLine :: IO [Int]
    y <- fmap (map read . words) getLine :: IO [Int]
    print $ (length $ filter (<= 5 - k) y) `div` 3

-- 6716766	 May 26, 2014 8:05:20 PM	delta_4d	 A - Choosing Teams	 Haskell	Accepted	 30 ms	 0 KB
