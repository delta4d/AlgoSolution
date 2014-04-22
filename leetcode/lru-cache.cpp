// 280ms
// heap
// node::cnt seems useless = =
struct node {
    int key, val, ts, cnt;
    node() {}
    node(int _k, int _v, int _t, int _c=0):key(_k), val(_v), ts(_t), cnt(_c) {}
    bool operator<(const node &lhs) const {
        if (ts != lhs.ts) return ts < lhs.ts;
        return cnt < lhs.cnt;
    }
};

const int MAXN = (1 << 15) + 1;
struct cache {
    node mem[MAXN];
    unordered_map <int, int> idx;
    int cap, n;
    
    cache() {}
    cache(int _c):cap(_c) {
        n = 0;
        idx.clear();
    }
    void init(int _c) {
        cap = _c, n = 0;
        idx.clear();
    }
    int get(int key, int ts) {
        if (!idx.count(key)) return -1;
        int k = idx[key];
        mem[k].ts = ts, ++mem[k].cnt;
        down(k);
        return mem[idx[key]].val;
    }
    void up(int p) {
        while (p != 1) {
            int r = p >> 1;
            if (!(mem[p] < mem[r])) return;
            idx[mem[p].key] = r, idx[mem[r].key] = p;
            swap(mem[p], mem[r]);
            p = r;
        }
    }
    void down(int p) {
        while ((p << 1) <= n) {
            int l = p << 1, r = l ^ 1, q = l;
            if (r <= n && mem[r] < mem[l]) q = r;
            if (mem[p] < mem[q]) return;
            idx[mem[p].key] = q, idx[mem[q].key] = p;
            swap(mem[p], mem[q]);
            p = q;
        }
    }
    void set(int key, int val, int ts) {
        if (idx.count(key)) {
            int p = idx[key];
            ++mem[p].cnt, mem[p].ts = ts, mem[p].val = val;
            down(p);
        } else {
            node cc(key, val, ts);
            if (n == cap) {
                idx.erase(mem[1].key);
                mem[1] = cc;
                idx[key] = 1;
                down(1);
            } else {
                mem[++n] = cc;
                idx[key] = n;
                up(n);
            }
        }
    }
};

class LRUCache{
public:
    cache ch;
    int ts;
    LRUCache(int capacity) {
        ch.init(capacity);
        ts = 0;
    }
    
    int get(int key) {
        return ch.get(key, ++ts);
    }
    
    void set(int key, int value) {
        ch.set(key, value, ++ts);
    }
};
