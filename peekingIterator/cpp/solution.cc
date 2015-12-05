
class PeekingIterator : public Iterator {
private:
    int nextValue;
    bool hasNextValue;
public:
    PeekingIterator(const vector<int>& nums) : Iterator(nums) {
        // **DO NOT** save a copy of nums and manipulate it directly.
        // You should only use the Iterator interface methods.
        preloadNext();
    }
    void preloadNext() {
        if (Iterator::hasNext()) {
            hasNextValue = true;
            nextValue = Iterator::next();
        } else {
            hasNextValue = false;
            nextValue = 0;
        }
    }
    // Returns the next element in the iteration without advancing the iterator.
    int peek() {
        return nextValue; 
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    int next() {
        int ret = nextValue;
        preloadNext();
        return ret;      
    }

    bool hasNext() const {
        return hasNextValue; 
    }
};
