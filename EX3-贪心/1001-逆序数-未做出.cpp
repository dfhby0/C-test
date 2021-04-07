/*
逆序数
Description

一个序列 a_1, a_2, \cdots, a_na 
1
​	
 ,a 
2
​	
 ,⋯,a 
n
​	
  中的逆序对指的是对于下标 i,j(1\leq i\leq j \leq n)i,j(1≤i≤j≤n), 有 a_i &gt; a_ja 
i
​	
 >a 
j
​	
 . 所有这样的逆序对的数量称为该序列的逆序数.

现在有一个序列 p_1,p_2,\cdots,p_np 
1
​	
 ,p 
2
​	
 ,⋯,p 
n
​	
 , 可以对于序列中的一些数乘上 -1−1, 使得这个序列中的逆序数最小, 求最小的逆序数.


Input
输入包含两行, 第一行为一个正整数 n \in [1,2000]n∈[1,2000], 第二行为用空格隔开的 nn 个正整数组成的序列 p_1,p_2,\cdots,p_np 
1
​	
 ,p 
2
​	
 ,⋯,p 
n
​	
 , 其中 |p_i| \leq 100000∣p 
i
​	
 ∣≤100000

Output
输出单独一行, 表示最小的逆序数


Sample Input 1 

9
1 -1 -1 0 -1 0 1 1 1
Sample Output 1

1
Sample Input 2 

8
0 1 2 -1 -2 1 -2 2
Sample Output 2

3
*/
