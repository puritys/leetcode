add digits
----------

https://leetcode.com/problems/add-digits/

Given a non-negative integer num, repeatedly add all its digits until the result has only one digit.

For example:

Given num = 38, the process is like: 3 + 8 = 11, 1 + 1 = 2. Since 2 has only one digit, return it.

Follow up:
Could you do it without any loop/recursion in O(1) runtime?



idea
-----
When we get the sum of two numbers. Then we check that it is bigger than 10 first,  if it is we shoud cut it by 10 and plus 1 because the second digit must be 1.

For example
-----------

<pre>
8 + 9 = 17  =>  do -10 + 1 ,  17 - 9 = 8

Given a number 45678
4 + 5 = 9
9 + 6 = 15,  15 - 9 = 6
6 + 7 = 13,  13 - 9 = 4
4 + 8 = 12,  12 - 9 = 3 

Got the answer 3.
</pre>

