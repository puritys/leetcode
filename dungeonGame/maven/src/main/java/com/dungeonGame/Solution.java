package com.dungeonGame;
import java.lang.*;

public class Solution {

    public int calculateMinimumHP(int[][] dungeon) {
        int minHP = 1;
        int rows = 0, cols = 0, x, y;
        rows = dungeon.length - 1;
        cols = dungeon[0].length - 1;
        for (x = rows; x >= 0; x--) {
            for (y = cols; y >=0 ; y--) {
                if (y < cols && x < rows) {
                    dungeon[x][y] += Math.max(dungeon[x+1][y], dungeon[x][y + 1]);
                } else if (x < rows) {
                    dungeon[x][y] += dungeon[x+1][y];
                } else if (y < cols) {
                    dungeon[x][y] += dungeon[x][y + 1];
                } 
                if (dungeon[x][y] > 0) dungeon[x][y] = 0;
            }
        }
        minHP = Math.abs(dungeon[0][0]) + 1;
        return minHP;
    }
}
