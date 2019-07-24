# Explain my idea

Using recursion 相加，直到某一端結束，在進位的時候要考慮給下一項加1，所有多一項常數C

另一種想法，跟遞迴類似但是直接相加，並同時處理進位（朋友的做法，這比較好）：

    (2 -> 4 -> 3)       
 
"+" (5 -> 6 -> 4)     

     7 -> 0 -> 8

## 注意
考慮進位的問題 ＆ 判斷None，是用結構本身(listnode = ListNode()的listnode)

