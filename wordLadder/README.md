Word Ladder
===========

https://leetcode.com/problems/word-ladder/

Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time
Each intermediate word must exist in the word list
For example,

    Given:
    beginWord = "hit"
    endWord = "cog"
    wordList = ["hot","dot","dog","lot","log"]
    As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
    return its length 5.

    Note:
    Return 0 if there is no such transformation sequence.
    All words have the same length.
    All words contain only lowercase alphabetic characters.

idea
======

Use shortest path algorithm to solve this question.
1. Find every transformations and set the distance to be 1 between that two string.
2. Use shortest path algorithm: BFS .

<pre>
 hit(1) -> hot(2)
 hot(2) -> dot(3)
        -> lot(3)
        -> hit(3) x
 dot(3) -> lot(4) x
        -> dog(4)
        -> hot(4) x
 lot(4) -> dot(5) x
        -> hot(5) x
        -> hot(5) x
 dog(4) -> log(5) 
        -> cog(5) Y
 log(5) -> cog(6) x
</pre>

