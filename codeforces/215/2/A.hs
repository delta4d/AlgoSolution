import Data.List
main = do
    (n:d:t) <- fmap (map read . words) getContents :: IO [Int]
    let a = scanl1 (+) $ sort $ init t
    let m = last t
    print $ if m <= n then a !! (m - 1) else (last a) - (m - n) * d

-- 7343603	2014-08-04 13:35:30	delta_4d	A - Sereja and Coat Rack	Haskell	Accepted	15 ms	0 KB
