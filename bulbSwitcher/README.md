Bulb switcher
-------------

https://leetcode.com/problems/bulb-switcher/


There are n bulbs that are initially off. You first turn on all the bulbs. Then, you turn off every second bulb. On the third round, you toggle every third bulb (turning on if it's off or turning off if it's on). For the nth round, you only toggle the last bulb. Find how many bulbs are on after n rounds.

Example:
Given n = 3. 

At first, the three bulbs are [off, off, off].
After first round, the three bulbs are [on, on, on].
After second round, the three bulbs are [on, off, on].
After third round, the three bulbs are [on, off, off]. 

So you should return 1, because there is only one bulb is on.


Explain question on programming concept
------------------------

1th : set all on
2th : toggle every second bulb
3th : toggle every third bulb
4th : toggle every fourth bulb
5th : toggle every fifth bulb
.
.
nth : toggle every nth bulb






idea
------

Any prime numbers will be off. Because the number only divides by one and himself.
Any numbers, if it's square number is a integer without point, then it will be on.
Any numbers who can be divided by two different numbers, it will have even amount of divider so the bulb will be off.

Finally, which one bulb's light is on: 1^2, 2^2, 3^2, 4^2  = 1,4,9,16 

1: on
2: 1 x 2 = off
3: 1 x 3 = off
4: 2 x 2 = on (square)
5: 1 x 5 = off
6: 1, 2 x 3,  6 = off
7: 1 x 7 = off
8: 1, 2, 4, 8 = off
9: 1, 3, 9 = on
10: 1, 2, 5, 10 = off






