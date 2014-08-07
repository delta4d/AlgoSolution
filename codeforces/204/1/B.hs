import Data.List
main=do
 (_:a)<-fmap (map read . words) getContents::IO [Int]
 let m=length [(x,y)|(x:ys)<-tails a,y<-ys,x>y]
 print $ (div m 2)*3+(m-(div m 2))

-- 7352801	2014-08-05 17:13:28	delta_4d	B - Jeff and Furik	Haskell	Accepted	124 ms	1084 KB
