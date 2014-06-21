import Data.List
main = do interact $ show . length . nub . del
    where   del [] = []
            del (x:xs)
                | 'a' <= x && x <= 'z' = x : del xs
                | otherwise            = del xs

-- 6925491	 2014-06-20 09:39:19	delta_4d	 A - Anton and Letters	 Haskell	Accepted	30 ms	0 KB
