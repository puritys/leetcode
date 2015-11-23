package com.leet;

import java.lang.*;
import java.io.*;

public class SolutionDP {
    public String minWindow(String s, String t) {

        match[] matchs = new match[s.length()];
        int[] ch = new int[128];
        boolean isMatch;
        int matchsIndex = 0;
        char tmp;
        int length = s.length(); 
        int tLength = t.length();
        for (int i = 0; i < 128; i++) {
            ch[i] = 0;
        }

        for (int i = 0; i < tLength; i++) {
            ch[t.charAt(i)]++;
        }
        for (int i = 0 ; i < length; i++) {
           tmp = s.charAt(i);
           isMatch = false;
           if (t.indexOf(tmp) != -1) {
               matchs[matchsIndex] = new match(ch, tLength);
               matchsIndex++;
               isMatch = true;
           }

           for (int j = 0; j < matchsIndex; j++) {
               if (!matchs[j].isFullMatch()) {
                   matchs[j].addNewLetter(tmp, isMatch, i);
               }
           }
        }

        int minLen = length + 1;
        String ans = "";
        for (int j = 0; j < matchsIndex; j++) {
            if (matchs[j].isFullMatch() && matchs[j].len < minLen) {
                ans = s.substring(matchs[j].left, matchs[j].left + matchs[j].len);
                minLen = matchs[j].len;
            }
        }
        return ans; 
    }

    private class match {
        public int[] needMatch;
        public int needMatchLen;
        public int left = -1;
        public int len = 0;
        public match(int[] ch, int needLen) {
            this.needMatch = new int[128];
            for(int i=0; i<128; i++){
                this.needMatch[i] = ch[i];
            }
            this.needMatchLen = needLen;
            this.len = 0;
        }
        public void addNewLetter(char c, boolean isMatch, int index) {

            if (true == isMatch && this.needMatch[c] > 0) {
                this.needMatch[c]--;
                this.needMatchLen--;
                if (this.left == -1) {
                    this.left = index;
                }
            }
            this.len++;
        }
        public boolean isFullMatch() {
            if (this.needMatchLen == 0) return true;
            return false;
        }
    }
}
