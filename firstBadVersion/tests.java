import static org.junit.Assert.assertEquals;
import org.junit.Test;

public class tests {
    @Test
    public void normal1() {
        Solution o = new Solution();
        o.setBadVersion(12);
        int v = o.firstBadVersion(99);
        assertEquals(12, v);
    }
    @Test
    public void normal2() {
        Solution o = new Solution();
        o.setBadVersion(22);
        int v = o.firstBadVersion(23);
        assertEquals(22, v);
    }
    @Test
    public void empty() {
        Solution o = new Solution();
        //o.setBadVersion(0);
        int v = o.firstBadVersion(23);
        assertEquals(0, v);
    }

    @Test
    public void notfound() {
        Solution o = new Solution();
        o.setBadVersion(99);
        int v = o.firstBadVersion(23);
        assertEquals(0, v);
    }

    @Test
    public void bigNumber() {
        Solution o = new Solution();
        o.setBadVersion(1702766719);
        int v = o.firstBadVersion(2126753390);
        assertEquals(1702766719, v);
    }

}
