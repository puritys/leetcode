/* The isBadVersion API is defined in the parent class VersionControl.
      boolean isBadVersion(int version); */

public class Solution extends VersionControl {

    public int firstBadVersion(int n) {
        long left = 1, right = n, ret = 0, middle;
        while(true) {
            middle = (right + left)/2;
            if (this.isBadVersion((int)middle)) {
                ret = middle;
                right = middle - 1;
            } else {
                left = middle + 1;
            }
            if (right < left) break;
        }
        return (int)ret;
    }
}
