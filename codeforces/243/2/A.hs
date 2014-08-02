main = do
 (n:s:a) <- fmap (map read . words) getContents :: IO [Int]
 putStrLn $ if sum a - maximum a <= s then "YES" else "NO"

-- 7243829	2014-07-25 20:06:03	delta_4d	A - Sereja and Mugs	Haskell	Accepted	15 ms	0 K
