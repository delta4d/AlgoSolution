main = do
    n <- fmap read getLine :: IO Int
    if n == 1
        then print 0
        else do
            let m = n `div` 2
            print $ m * (n - m)
            putStrLn $ foldl1 (++) [(show x ++ " " ++ show y ++ "\n") | x <- [1..m], y <- [m+1..n]]

-- 7213840	2014-07-24 09:43:52	delta_4d	E - 3-cycles	Haskell	Accepted	374 ms	1100 KB
