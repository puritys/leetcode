
public class VersionControl {
    public int badVersion = 9999999;
    
    public boolean isBadVersion(int version) {
        return (this.badVersion <= version);
    }

    public void setBadVersion(int version) {
        this.badVersion = version;
    }
}
