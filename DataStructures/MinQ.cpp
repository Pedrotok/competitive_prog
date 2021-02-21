template<typename T>
struct MinDeque {
    int _size;
    deque<pair<T, int>> Q;
 
    MinDeque() {
        _size = 0;
    }
 
    void push(T val) {
        int cnt = 1;
        while(!Q.empty() && Q.front().ff >= val) {
            cnt += Q.front().ss;
            Q.pop_front();
        }
        Q.push_front(mp(val, cnt));
        _size++;
    }
 
    void pop() {
        if(Q.back().ss == 1) Q.pop_back();
        else Q.back().ss--;
        _size--;
    }
 
    T min() {
        return Q.back().ff;
    }
 
    int size() {
        return _size;
    }
};