struct Seg {
    int tree[3030];
    int bias;
    void init(int n) {
        bias = 1;
        while (bias < n)
            bias <<= 1;
    }
    void update(int x, int v) {
        x += bias;
        tree[x] = v;
        while (x >>= 1) {
            tree[x] = tree[x << 1] + tree[x << 1 | 1];
        }
    }
    int query(int l, int r) {
        l += bias, r += bias;
        int ret = 0;
        while (l < r) {
            if (l & 1)
                ret += tree[l++];
            if (!(r & 1))
                ret += tree[r--];
            l >>= 1, r >>= 1;
        }
        if (l == r)
            ret += tree[r];
        return ret;
    }
};