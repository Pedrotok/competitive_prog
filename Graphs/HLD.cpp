template<int size, int lg, typename T = long long>
struct HLD {
    vector<int> G[size+5];
    int label[size+5], sz[size+5], big[size+5], anc[size+5][lg+2], label_time, lvl[size+5], chain[size+5], N;

    HLD() {
        st = vector<T>(4*size+5, T(0));
    }

    // ------------------- HLD and LCA stuff -----------------------
    void dfs_size(int v, int p, int d) {
        sz[v] = 1;
        lvl[v] = d;
        anc[v][0] = p;
        big[v] = -1;

        for(int u : G[v]) {
            if(u == p) continue;
            dfs_size(u, v, d+1);
            if(big[v] == -1 || sz[u] > sz[big[v]])
                big[v] = u;
            sz[v] += sz[u];
        }
    }


    void dfs_chain(int v) {
        if(big[v] != -1)
            chain[big[v]] = chain[v];

        for(int u : G[v])
            if(u != anc[v][0])
                dfs_chain(u);
    }

    void dfs_label(T* arr, int v) {
        label[v] = label_time++;
        update(label[v], arr[v]);

        if(big[v] != -1)
            dfs_label(arr, big[v]);

        for(int u : G[v]) {
            if(u != anc[v][0] && u != big[v])
                dfs_label(arr, u);
        }
    }

    int LCA(int u, int v) {
        if(lvl[u] > lvl[v]) swap(u, v);

        for(int i = lg; i >= 0; i--)
            if(lvl[v] - (1<<i) >= lvl[u])
                v = anc[v][i];

        if(u == v) return u;

        for(int i = lg; i >= 0; i--)
            if(anc[u][i] != anc[v][i]) {
                v = anc[v][i];
                u = anc[u][i];
            }

        return anc[u][0];
    }

    int get_kth_ancestor(int v, int k) {
        for(int i = lg; k && i >= 0; i--)
            if(k & (1<<i)) {
                v = anc[v][i];
                k -= (1<<i);
            }

        return v;
    }

    // ------------------------ SEGTREE STUFF ------------------------
    vector<T> st;
 
    const T neutral = 0;
 
    inline T f(T a, T b) {
        return a^b;
    }
 
    void update(int L, int R, int i, T val, int p) {
        if(R < i or L > i) return;
        if(L >= i && R <= i) {
            st[p] = val;
            return ;
        }
 
        int M = (L+R)/2;
 
        update(L,M,i,val,2*p);
        update(M+1,R,i,val,2*p+1);
 
        st[p] = f(st[2*p], st[2*p+1]);
    }
 
    T query(int L, int R, int i, int j, int p) {
        if(R < i or L > j) return neutral;
        if(L >= i && R <= j) return st[p];
 
        int M = (L+R)/2;
 
        T l = query(L,M,i,j,2*p);
        T r = query(M+1,R,i,j,2*p+1);
 
        return f(l, r);
    }

    T query_chain(int v, int p) {
        T ans = neutral;
        while(lvl[v] > lvl[p]) {
            int top = chain[v];
            if(lvl[top] <= lvl[p]) {
                int diff = lvl[v] - lvl[p];
                top = get_kth_ancestor(v, diff-1);
            }
            ans = f(ans, query(label[top], label[v]));
            v = anc[top][0];
        }
        return ans;
    }

    T query_path(int u, int v) {
        int lc = LCA(u, v);
        T val = f(query_chain(u, lc), query_chain(v, lc));
        return f(val, query(label[lc], label[lc]));
    }

    void update_tree(int u, T val) {
        update(label[u], val);
    }

    void init(T* arr, int root, int _N) {
        N = _N;

        for(int i = 0; i < N; i++)
            chain[i] = i;
        dfs_size(root, root, 0);
        dfs_chain(root);
        dfs_label(arr, root);

        for(int j = 1; j <= lg; j++)
            for(int i = 0; i < N; i++)
                anc[i][j] = anc[ anc[i][j-1] ][j-1];
    }

    void update(int i, T val) {update(0, N-1, i, val, 1);}
 
    T query(int i, int j) {return query(0, N-1, i, j, 1);}
};