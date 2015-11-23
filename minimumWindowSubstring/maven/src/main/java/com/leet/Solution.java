
package com.leet;

import java.lang.*;
import java.io.*;

public class Solution {
    public String minWindow(String s, String t) {
        int[] subString = new int[128];
        int[] matchedString = new int[128];
        int matchedNum = 0, startIndex = 0;
        char tmp;
        String minString = "";
        int length = s.length(); 
        int tLength = t.length();
        int minLength = length +1;
        // convert string to char ASCII number for compare
        for (int i = 0; i < tLength; i++) subString[t.charAt(i)]++;

        for (int i = 0 ; i < length; i++) {
           tmp = s.charAt(i);
           if (subString[tmp] > 0) { // match the sub string
               // increase the character on  matched string
               if (matchedString[tmp] < subString[tmp]) matchedNum++;
               matchedString[tmp]++;
           }
           while (matchedNum == tLength) {
               tmp = s.charAt(startIndex);
               if (subString[tmp] <= 0) {
                   // find the first char that match the sub string.
                   // example: xxxabxc, abxc is the string we want, so skip xxx
                   startIndex++; continue;
               }

               if (i - startIndex < minLength) {
                   minLength = i - startIndex;
                   minString = s.substring(startIndex, i + 1);
               }
               matchedString[tmp]--;
               if (matchedString[tmp] < subString[tmp]) {
                   matchedNum--;
               }
               startIndex++;
           }
        }
        return minString;
    }
}
