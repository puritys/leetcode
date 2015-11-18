package com.dungeonGame;

import java.io.*;
import junit.framework.Test;
import junit.framework.TestCase;
import junit.framework.TestSuite;
import com.dungeonGame.*;


/**
 * Unit test for simple App.
 */
public class MainTest 
    extends TestCase
{
    /**
     * Create the test case
     *
     * @param testName name of the test case
     */
    public MainTest( String testName )
    {
        super( testName );
    }

    /**
     * @return the suite of tests being tested
     */
    public static Test suite()
    {
        return new TestSuite( MainTest.class );
    }

    public void testFromCase()
    {
        String files[] = {
            "target/test-classes/dungeonGame/case/normal1",
            "target/test-classes/dungeonGame/case/normal2",
            "target/test-classes/dungeonGame/case/single1"
        };
        for (int j = 0; j < files.length; j++) {
            try {
            // String current = new java.io.File( "." ).getCanonicalPath();
            // System.out.println("Current dir:"+current);

                String file = files[j];
                FileReader f = new FileReader(file);
                BufferedReader buf = new BufferedReader(f);

                String line;
                int lineIndex = 0, rows, cols, i, ans;
                line = buf.readLine();
                String dimension[] = line.split("x");
                rows = Integer.parseInt(dimension[0].trim());
                cols = Integer.parseInt(dimension[1].trim());
                int[][] pos = new int[rows][cols];

                line = buf.readLine();
                ans = Integer.parseInt(line.trim());

                while ((line = buf.readLine()) != null) {
                    line = line.trim();
                    String v[]= line.split(" ");
                    if (v.length <= 0 || v[0].isEmpty()) break;
                    for (i = 0; i < v.length; i++) {
                        pos[lineIndex][i] = Integer.parseInt(v[i]);
                    }
                    lineIndex++;
                }
                Solution obj = new Solution();

                int minHP = obj.calculateMinimumHP(pos);
                assertEquals(ans, minHP);
            } catch (FileNotFoundException e) {
                System.err.println("File not found: " + e.getMessage());
            } catch (IOException e) {
                System.err.println("exception " + e.getMessage());
            }
        }
    }

    public void testApp()
    {
        Solution obj = new Solution();
        int[][] pos = new int[][]{
            {-2,  -3,  3},
            {-5, -10,  1},
            {10,  30, -5},
        };

        int minHP = obj.calculateMinimumHP(pos);
        assertEquals(7, minHP);
    }

    public void testApp2()
    {
        Solution obj = new Solution();
        int[][] pos = new int[][]{
            {-2,  -3,  3 ,1},
            {-5, -10,  3 ,1},
            {10,  30, -5, 2},
        };

        int minHP = obj.calculateMinimumHP(pos);
        assertEquals(6, minHP);
    }
//    public void testApp3()
//    {
//        Solution obj = new Solution();
//        int[][] pos = new int[][]{
//        };
//
//        int minHP = obj.calculateMinimumHP(pos);
//        assertEquals(1, minHP);
//    }


}
