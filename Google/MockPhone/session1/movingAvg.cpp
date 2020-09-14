

class MovingAverage {
private:
    queue<int> window;
    double sum = 0;
    int size;
public:
    /** Initialize your data structure here. */
    MovingAverage(int _size) : size(_size) {
        
    }
    
    double next(int val) {
        window.push(val);
        sum += val;
        if (window.size() > size) {
            sum -= window.front();
            window.pop();
        }
        return sum / window.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */