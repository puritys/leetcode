//https://leetcode.com/problems/first-bad-version/
class main {
    public static void main(String [] args)
    {
        Solution o = new Solution();
        o.setBadVersion(1702766719);
        int v = o.firstBadVersion(2126753390);
        System.out.println("ret = " + v);
    }
}
