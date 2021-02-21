template<typename T>
struct Stack {
    stack<T> S, M;
 
    bool empty() {
        return S.empty();
    }
 
    void push(T val) {
        S.push(val);
        if(M.empty()) M.push(val);
        else M.push(__gcd(M.top(), val));
    }
 
    void pop() {
        S.pop();
        M.pop();
    }
 
    T gcd() {
        if(M.empty()) return 0;
        return M.top();
    }
 
    T top() {
        return S.top();
    }
};
 
template<typename T>
struct GcdQueue {
    Stack<T> S1, S2;
 
    void push(T val) {
        S1.push(val);
    }
 
    int empty() {
        return S1.empty() && S2.empty();
    }
 
    void pop() {
        if(S2.empty()) {
            while(!S1.empty()) {
                S2.push(S1.top());
                S1.pop();
            }
        }
        S2.pop();
    }
 
    T gcd() {
        if(S1.empty()) return S2.gcd();
        if(S2.empty()) return S1.gcd();
        return __gcd(S1.gcd(), S2.gcd());
    }
};
 