main = do
    [n, m] <- fmap (map read . words) getLine :: IO [Double]
    print $ if n*m==1 then 1 else (2*m*n-m-n)/(n*(m*n-1))

-- 7273809	2014-07-28 07:51:33	delta_4d	C - Magic Trick	Haskell	Accepted	15 ms	0 KB
