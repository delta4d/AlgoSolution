main = interact $ f 0
f _ "" = ""
f 0 (x:xs) = x:(f 1 xs)
f 1 ('d':'o':'t':xs) = '.':(f 1 xs)
f 1 ('a':'t':xs) = '@':(f 2 xs)
f 1 (x:xs) = x:(f 1 xs)
f 2 "dot\n" = "dot"
f 2 ('d':'o':'t':xs) = '.':(f 2 xs)
f 2 (x:xs) = x:(f 2 xs)

-- 7210700	2014-07-23 20:13:21	delta_4d	C - Email address	Haskell	Accepted	30 ms	0 KB
