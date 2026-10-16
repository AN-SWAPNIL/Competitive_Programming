// Main Template
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
// Single-order tree (like a set, but with ordering operations)
template <class T>
using ordertree =
    tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// Multi-order tree (like a multiset, but with ordering operations)
template <class T>
using multiordertree =
    tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

bool display = false;
typedef long long int ll;
typedef vector<ll> vll;
typedef vector<bool> vbl;
typedef pair<ll, ll> pll;
typedef vector<pll> vpll;
typedef map<ll, ll> mll;
#define MAX (ll)1e18
#define MOD (ll)1e9+7
#define pb push_back
#define print(x) cout << x << endl
#define lp(start, i, end) for (ll i = start; i < end; i++)
#define rlp(start, i, end) for (ll i = start; i >= end; i--)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define End cout << "\n"
#define allin(a, n)           \
    for (int i = 0; i < n; i++) \
        cin >> a[i];
#define allout(a, n)          \
    for (int i = 0; i < n; i++) \
        cout << a[i] << ' ';      \
    End;
#define yesno(a) print((a ? "YES" : "NO"))
#define bug(...) \
    if (display)   \
    __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char *name, Arg1 &&arg1)
{
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char *names, Arg1 &&arg1, Args &&...args)
{
    const char *comma = strchr(names + 1, ',');
    cerr.write(names, comma - names) << " : " << arg1 << " | ";
    __f(comma + 1, args...);
}

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count()); // rng() % n

ll getRand(ll low, ll high) { // getRand(0, n-1)
    static std::random_device rd;
    static std::mt19937_64 gen(rd());
    std::uniform_int_distribution<ll> dist(low, high);
    return dist(gen);
}

void init() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
    display = true;
#endif
}

int main()
{
    init();
	    ordertree<int> o_set;
	    o_set.insert(3);
	    o_set.insert(1);
    cout << *o_set.find_by_order(0) << " " << o_set.order_of_key(3) << endl; // 1 1
    // multiordertree is same but multiset
    return 0;
}

// Python Template
/*
import sys
input = sys.stdin.read  # Fast input using sys.stdin
data = input().split()  # Read all input as a list of strings split by whitespace

# Parse inputs
n = int(data[0])  # Number of elements
arr = list(map(int, data[1:]))  # List of integers

# List comprehension: create a list of squares
squares = [x**2 for x in arr]

# Sorting with lambda: sort by squares in descending order
sorted_squares = sorted(squares, reverse=True, key=lambda x: x)

# Using map and filter
even_squares = list(filter(lambda x: x % 2 == 0, sorted_squares))  # Filter only even squares

# Output the sorted even squares
print("Sorted Even Squares:", even_squares)

accumulated_sum = 0  # Define a global variable

def recursive_sum(n):
    global accumulated_sum  # Access the global variable
    # Base case
    if n == 0:
        result = accumulated_sum
        accumulated_sum = 0  # Reset for next use
        return result
    
    # Add n to the global accumulated_sum and make the recursive call
    accumulated_sum += n
    return recursive_sum(n - 1)

# Example usage
n = 5
result = recursive_sum(n)
print("Sum:", result)  # Output should be the sum of numbers from 1 to n
*/

// JAVA Template
/*
import java.io.*;
import java.util.*;
import java.math.*;

public class Main {
	public static void main(String[] args) throws IOException {
		FastReader fr = new FastReader();
		PrintWriter pw = new PrintWriter(System.out);

		int t = fr.nextInt(); // Number of test cases
		while (t-- > 0) {
			// Example input and output with BigInteger
			BigInteger a = new BigInteger(fr.next());
			BigInteger b = new BigInteger(fr.next());
			BigInteger sum = a.add(b);
			pw.println(sum);
		}

		pw.flush();
		pw.close();
	}

	// Utility class for fast input
	static class FastReader {
		BufferedReader br;
		StringTokenizer st;

		public FastReader() {
			br = new BufferedReader(new InputStreamReader(System.in));
		}

		String next() {
			while (st == null || !st.hasMoreElements()) {
				try {
					st = new StringTokenizer(br.readLine());
				} catch (IOException e) {
					e.printStackTrace();
				}
			}
			return st.nextToken();
		}

		int nextInt() { return Integer.parseInt(next()); }
		long nextLong() { return Long.parseLong(next()); }
		double nextDouble() { return Double.parseDouble(next()); }
		String nextLine() {
			String str = "";
			try {
				str = br.readLine();
			} catch (IOException e) {
				e.printStackTrace();
			}
			return str;
		}
	}

	// Example BigInteger operations
	static BigInteger bigAdd(BigInteger a, BigInteger b) {
		return a.add(b);
	}

	static BigInteger bigMultiply(BigInteger a, BigInteger b) {
		return a.multiply(b);
	}

	static BigInteger bigGCD(BigInteger a, BigInteger b) {
		return a.gcd(b);
	}

	static BigInteger bigModExp(BigInteger base, BigInteger exp, BigInteger mod) {
		return base.modPow(exp, mod);
	}

	static BigInteger bigMod(BigInteger a, BigInteger mod) {
		return a.mod(mod);
	}

	// Sieve of Eratosthenes for prime numbers
	static boolean[] sieveOfEratosthenes(int n) {
		boolean[] primes = new boolean[n + 1];
		Arrays.fill(primes, true);
		primes[0] = primes[1] = false;
		for (int i = 2; i * i <= n; i++) {
			if (primes[i]) {
				for (int j = i * i; j <= n; j += i) {
					primes[j] = false;
				}
			}
		}
		return primes;
	}

	// Custom comparator for sorting pairs
	static class Pair implements Comparable<Pair> {
		int first, second;

		public Pair(int first, int second) {
			this.first = first;
			this.second = second;
		}

		@Override
		public int compareTo(Pair o) {
			return this.first == o.first ? Integer.compare(this.second, o.second) : Integer.compare(this.first, o.first);
		}
	}
}
*/

// Trie
struct Trie
{
    struct node
    {
        node *next[26][2];
        int words = 0;
        node()
        {
            for (int i = 0; i < 26; i++)
                next[i][0] = next[i][1] = nullptr;
        }
    };
    node *root = nullptr;
    Trie()
    {
        root = new node();
    }
    pair<int, int> get(char x)
    {
        if ('a' <= x && x <= 'z')
            return {x - 'a', 0};
        return {x - 'A', 1};
    }
    void insert(string x)
    {
        int n = x.size();
        node *now = root;
        for (int i = 0; i < n; i++)
        {
            pair<int, int> id = get(x[i]);
            if (now->next[id.first][id.second] == nullptr)
                now->next[id.first][id.second] = new node();
            now = now->next[id.first][id.second];
        }
        now->words++;
    }
    int search(string x)
    {
        int n = x.size();
        node *now = root;
        for (int i = 0; i < n; i++)
        {
            pair<int, int> id = get(x[i]);
            if (now->next[id.first][id.second] == nullptr)
                return 0;
            else
                now = now->next[id.first][id.second];
        }
        return now->words;
    }
    void del(node *x)
    {
        for (int i = 0; i < 26; i++)
        {
            if (x->next[i][0])
                del(x->next[i][0]);
            if (x->next[i][1])
                del(x->next[i][1]);
        }
        delete (x);
    }
    void del()
    {
        del(root);
    }
};

//Or Simple
const ll N = 30;
ll Trie[200005 * N][2], ct;

void insert(ll x)
{
    ll node = 0;
    rlp(N, i, 0)
    {
        ll y = x >> i & 1;
        if (!Trie[node][y])
            Trie[node][y] = ++ct;
        node = Trie[node][y];
    }
}

ll search(ll x)
{
    ll ans = 0, node = 0;
    rlp(N, i, 0)
    {
        ll y = x >> i & 1;
        if (Trie[node][y ^ 1])
        {
            node = Trie[node][y ^ 1];
            ans += (1 << i);
        }
        else
            node = Trie[node][y];
    }
    return ans;
}

//max subarray xor
int main()
{
    init();
    ll n;
    ll xr=0, x, mx=0;
    while(n--){
        cin >> x;
        xr^=x;
        insert(x);
        mx=max(mx,search(xr));
    }
    print(mx);
    return 0;
}

// SegTree
// segment tree
template <class T>
class segment_tree
{
private:
    ll N = 0;
    T *t;
    ll root = 1;
    ll tla = 0, tra = 0;
    T combine(T a, T b)
    {
        return a + b;
        // return min(a, b);
        // return max(a, b);
        // return __gcd(a, b);
        // return a ^ b;
    }
    void build(vector<T> &a, ll v, ll tl, ll tr)
    {
        if (tl == tr)
            t[v] = a[tl];
        else
        {
            ll tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }
    T query(ll v, ll tl, ll tr, ll l, ll r)
    {
        if (l > r)
            return 0;
        // for min--> return INT32_MAX;
        // for max--> return INT32_MIN;
        // for gcd--> retyrn 0;
        // for xor--> return 0;
        if (l == tl && r == tr)
            return t[v];
        ll tm = (tl + tr) / 2;
        T a = query(v * 2, tl, tm, l, min(r, tm));
        T b = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return combine(a, b);
    }
    void update(ll v, ll tl, ll tr, ll pos, T new_val)
    {
        if (tl == tr)
            t[v] = new_val;
        else
        {
            ll tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }

public:
    segment_tree() {}
    segment_tree(vector<T> &a)
    {
        build(a);
    }
    void build(vector<T> &a)
    {
        if (N)
            clear();
        N = a.size() + 1;
        tla = 0, tra = a.size() - 1;
        t = new T[4 * N];
        build(a, 1, tla, tra);
    }
    T query(ll l, ll r)
    {
        return query(root, tla, tra, l, r);
    }
    void update(ll pos, T new_val)
    {
        update(root, tla, tra, pos, new_val);
    }
    void clear()
    {
        if (N)
            delete[] t;
        N = 0, tra = 0, tla = 0;
    }
    ~segment_tree()
    {
        if (N)
            clear();
    }
};

// segment tree lazy propagation
template <class T>
class lazy_segment_tree
{
private:
    ll N = 0;
    T *t;
    T *lazy;
    ll root = 1;
    ll tla = 0, tra = 0;
    void push(ll v, ll tl, ll tm, ll tr)
    {
        t[v * 2] += (tm - tl + 1) * lazy[v];
        lazy[v * 2] += lazy[v];
        t[v * 2 + 1] += (tr - tm) * lazy[v];
        lazy[v * 2 + 1] += lazy[v];
        lazy[v] = 0;
    }
    void build(vector<T> &a, ll v, ll tl, ll tr)
    {
        if (tl == tr)
            t[v] = a[tl];
        else
        {
            ll tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }
    T query(ll v, ll tl, ll tr, ll l, ll r)
    {
        if (l > r)
            return 0;
        // for min--> return INT32_MAX;
        // for max--> return INT32_MIN;
        if (l == tl && r == tr)
            return t[v];
        ll tm = (tl + tr) / 2;
        push(v, tl, tm, tr);
        T a = query(v * 2, tl, tm, l, min(r, tm));
        T b = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
        return a + b;
    }
    void update(ll v, ll tl, ll tr, ll l, ll r, T add_val)
    {
        if (l > r)
            return;
        if (l == tl && r == tr)
        {
            t[v] += (r - l + 1) * add_val;
            lazy[v] += add_val;
        }
        else
        {
            ll tm = (tl + tr) / 2;
            push(v, tl, tm, tr);
            update(v * 2, tl, tm, l, min(r, tm), add_val);
            update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, add_val);
            t[v] = t[v * 2] + t[v * 2 + 1];
        }
    }

public:
    lazy_segment_tree(){ }
    lazy_segment_tree(vector<T> &a)
    {
        build(a);
    }
    void build(vector<T> &a)
    {
        if (N)
            clear();
        N = a.size() + 1;
        tla = 0, tra = a.size() - 1;
        t = new T[4 * N];
        lazy = new T[4 * N];
        for (int i = 0; i < 4 * N; i++)
            lazy[i] = 0;
        build(a, 1, tla, tra);
    }
    T query(ll l, ll r)
    {
        return query(root, tla, tra, l, r);
    }
    void update(ll l, ll r, T add_val)
    {
        update(root, tla, tra, l, r, add_val);
    }
    void clear()
    {
        if (N)
        {
            delete[] t;
            delete[] lazy;
        }
        N = 0, tra = 0, tla = 0;
    }
    ~lazy_segment_tree()
    {
        if (N)
            clear();
    }
};

// Or Mine
struct SegTree
{
    typedef ll type;

    struct Data
    {
        type sum, min, in;
    };

    Data make_data(type val, ll i)
    {
        Data res;
        res.sum = 0;
        res.min = val;
        res.in = i;
        return res;
    }

    bool is_Equal(Data a, Data b)
    {
        return a.sum == b.sum;
    }

    Data merge(Data l, Data r)
    {
        Data res;
        res.sum = 0;
        res.min = min(min(l.min + l.sum, (ll)1e18), min(r.min + r.sum, (ll)1e18));
        res.in = l.min + l.sum < r.min + r.sum ? l.in : r.in;
        return res;
    }

    ll n;
    vector<type> a;
    vector<Data> tree;
    Data defalt_val = make_data(0, -1);
    Data null_val = make_data(-1, -1);

    SegTree(vector<type> &a)
    {
        this->a = a;
        n = a.size();
        tree.resize(4 * n);
        built(1, 0, n - 1);
    }

    SegTree(ll n)
    {
        this->n = n;
        tree.assign(4 * n, defalt_val);
    }

    void built(ll node, ll l, ll r)
    {
        if (l == r)
        {
            tree[node] = make_data(a[l], l);
            return;
        }
        built(2 * node, l, (l + r) / 2);
        built(2 * node + 1, (l + r) / 2 + 1, r);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    Data query(ll node, ll l, ll r, ll query_l, ll query_r)
    {
        if (l > query_r || r < query_l)
        {
            return make_data(1e18, -1);
        }
        if (l >= query_l && r <= query_r)
        {
            return tree[node];
        }
        return merge(query(2 * node, l, (l + r) / 2, query_l, query_r), query(2 * node + 1, (l + r) / 2 + 1, r, query_l, query_r));
    }

    Data query(ll query_l, ll query_r)
    {
        return query(1, 0, n - 1, query_l, query_r);
    }

    void point_update(ll node, ll l, ll r, ll idx, type val)
    {
        if (l == r)
        {
            a[l] = val;
            tree[node] = make_data(a[l], l);
            return;
        }
        if (!is_Equal(tree[node], null_val))
        {
            tree[2 * node].sum += tree[node].sum;
            tree[2 * node + 1].sum += tree[node].sum;
        }
        tree[node] = null_val;
        ll mid = (l + r) / 2;
        if (idx > mid)
        {
            point_update(2 * node + 1, mid + 1, r, idx, val);
        }
        else
        {
            point_update(2 * node, l, mid, idx, val);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void point_update(ll idx, type val)
    {
        point_update(1, 0, n - 1, idx, val);
    }

    void range_update(ll node, ll l, ll r, ll query_l, ll query_r, type val)
    {
        if (l > query_r || r < query_l)
        {
            return;
        }
        if (l >= query_l && r <= query_r)
        {
            tree[node].sum += val;
            return;
        }
        if (!is_Equal(tree[node], null_val))
        {
            tree[2 * node].sum += tree[node].sum;
            tree[2 * node + 1].sum += tree[node].sum;
        }
        tree[node] = null_val;
        range_update(2 * node, l, (l + r) / 2, query_l, query_r, val);
        range_update(2 * node + 1, (l + r) / 2 + 1, r, query_l, query_r, val);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void range_update(ll query_l, ll query_r, type val)
    {
        range_update(1, 0, n - 1, query_l, query_r, val);
    }
};

// 2D Segtree
struct Node
{
    ll value;
    Node() : value(0) {}
    // for min--> value(INT32_MAX);
    // for max--> value(INT32_MIN);
    // for gcd--> value(0);
    // for xor--> value(0);
};

class segment_tree_2D
{
private:
    ll rows, cols;
    vector<vector<Node>> tree;
    ll combine(ll a, ll b)
    {
        return a + b;
        // return min(a, b);
        // return max(a, b);
        // return __gcd(a, b);
        // return a ^ b;
    }
    void buildY(ll vx, ll lx, ll rx, ll vy, ll ly, ll ry, const vector<vector<ll>> &arr)
    {
        if (ly == ry)
        {
            if (lx == rx)
                tree[vx][vy].value = arr[lx][ly];
            else
                tree[vx][vy].value = combine(tree[vx * 2][vy].value, tree[vx * 2 + 1][vy].value);
        }
        else
        {
            ll my = (ly + ry) / 2;
            buildY(vx, lx, rx, vy * 2, ly, my, arr);
            buildY(vx, lx, rx, vy * 2 + 1, my + 1, ry, arr);
            tree[vx][vy].value = combine(tree[vx][vy * 2].value, tree[vx][vy * 2 + 1].value);
        }
    }
    void buildX(ll vx, ll lx, ll rx, const vector<vector<ll>> &arr)
    {
        if (lx != rx)
        {
            ll mx = (lx + rx) / 2;
            buildX(vx * 2, lx, mx, arr);
            buildX(vx * 2 + 1, mx + 1, rx, arr);
        }
        buildY(vx, lx, rx, 1, 0, cols - 1, arr);
    }
    ll queryY(ll vx, ll vy, ll tly, ll try_, ll ly, ll ry)
    {
        if (ly > ry)
            return 0;
        // for min--> return INT32_MAX;
        // for max--> return INT32_MIN;
        // for gcd--> retyrn 0;
        // for xor--> return 0;
        if (ly == tly && try_ == ry)
            return tree[vx][vy].value;
        ll tmy = (tly + try_) / 2;
        return combine(queryY(vx, vy * 2, tly, tmy, ly, min(ry, tmy)), queryY(vx, vy * 2 + 1, tmy + 1, try_, max(ly, tmy + 1), ry));
    }
    ll queryX(ll vx, ll tlx, ll trx, ll lx, ll rx, ll ly, ll ry)
    {
        if (lx > rx)
            return 0;
        // for min--> return INT32_MAX;
        // for max--> return INT32_MIN;
        // for gcd--> retyrn 0;
        // for xor--> return 0;
        if (lx == tlx && trx == rx)
            return queryY(vx, 1, 0, cols - 1, ly, ry);
        ll tmx = (tlx + trx) / 2;
        return combine(queryX(vx * 2, tlx, tmx, lx, min(rx, tmx), ly, ry), queryX(vx * 2 + 1, tmx + 1, trx, max(lx, tmx + 1), rx, ly, ry));
    }
    void updateY(ll vx, ll lx, ll rx, ll vy, ll ly, ll ry, ll x, ll y, ll new_val)
    {
        if (ly == ry)
        {
            if (lx == rx)
                tree[vx][vy].value = new_val;
            else
                tree[vx][vy].value = combine(tree[vx * 2][vy].value, tree[vx * 2 + 1][vy].value);
        }
        else
        {
            ll my = (ly + ry) / 2;
            if (y <= my)
                updateY(vx, lx, rx, vy * 2, ly, my, x, y, new_val);
            else
                updateY(vx, lx, rx, vy * 2 + 1, my + 1, ry, x, y, new_val);
            tree[vx][vy].value = combine(tree[vx][vy * 2].value, tree[vx][vy * 2 + 1].value);
        }
    }
    void updateX(ll vx, ll lx, ll rx, ll x, ll y, ll new_val)
    {
        if (lx != rx)
        {
            ll mx = (lx + rx) / 2;
            if (x <= mx)
                updateX(vx * 2, lx, mx, x, y, new_val);
            else
                updateX(vx * 2 + 1, mx + 1, rx, x, y, new_val);
        }
        updateY(vx, lx, rx, 1, 0, cols - 1, x, y, new_val);
    }

public:
    segment_tree_2D(const vector<vector<ll>> &arr)
    {
        rows = arr.size();
        cols = arr[0].size();
        tree.resize(4 * rows);
        for (ll i = 0; i < 4 * rows; ++i)
            tree[i].resize(4 * cols);
        buildX(1, 0, rows - 1, arr);
    }
    ll query(ll lx, ll rx, ll ly, ll ry)
    {
        return queryX(1, 0, rows - 1, lx, rx, ly, ry);
    }
    void update(ll x, ll y, ll new_val)
    {
        updateX(1, 0, rows - 1, x, y, new_val);
    }
};

// SparseTree
// lookup[i][j] is going to store minimum
// value in arr[i..j]. Ideally lookup table
// size should not be fixed and should be
// determined using n Log n. It is kept
// constant to keep code simple.
ll lookup[200005][20];

// Fills lookup array lookup[][] in bottom up manner.
void buildSparseTable(ll arr[], ll n)
{
    // Initialize M for the llervals with length 1
    for (ll i = 0; i < n; i++)
        lookup[i][0] = arr[i];

    // Compute values from smaller to bigger llervals
    for (ll j = 1; (1 << j) <= n; j++) {

        // Compute minimum value for all llervals with
        // size 2^j
        for (ll i = 0; (i + (1 << j) - 1) < n; i++) {

            // For arr[2][10], we compare arr[lookup[0][7]] 
            // and arr[lookup[3][10]]
            if (lookup[i][j - 1] < 
                        lookup[i + (1 << (j - 1))][j - 1])
                lookup[i][j] = lookup[i][j - 1];
            else
                lookup[i][j] = 
                        lookup[i + (1 << (j - 1))][j - 1];
        }
    }
}

// Returns minimum of arr[L..R]
ll query(ll L, ll R)
{
    // Find highest power of 2 that is smaller
    // than or equal to count of elements in given
    // range. For [2, 10], j = 3
    ll j = (ll)log2(R - L + 1);

    // Compute minimum of last 2^j elements with first
    // 2^j elements in range.
    // For [2, 10], we compare arr[lookup[0][3]] and
    // arr[lookup[3][3]],
    if (lookup[L][j] <= lookup[R - (1 << j) + 1][j])
        return lookup[L][j];

    else
        return lookup[R - (1 << j) + 1][j];
}

// Driver program
int main()
{
    ll a[] = { 7, 2, 3, 0, 5, 10, 3, 12, 18 };
    ll n = sizeof(a) / sizeof(a[0]);
    buildSparseTable(a, n);
    cout << query(0, 1) << endl;
    cout << query(4, 7) << endl;
    cout << query(7, 8) << endl;
    return 0;
}

// Binary Search
ll binarySearch(ll low, ll high, ll x)
{
    ll ans = -1;
    while (low <= high) {
        ll mid = low + (high - low) / 2;
        // If x greater, ignore left half
        if (solve(mid) >= x)
            high = mid - 1;

        // If x is smaller, ignore right half
        else {
            low = mid+1;
            // if(ans==mid) return ans;
            ans = mid;
        }
    }

    // If we reach here, then element was not present
    return ans;
}

// Ternery Search
void ternery_search() {
    ll lo, hi;
    while (hi - lo > 1e-7) // finding minimum
    {
        ll mid1 = lo + (hi - lo) / 3, mid2 = hi - (hi - lo) / 3;
        ll ans1 = fun(mid1), ans2 = fun(mid2);
        if (ans1 < ans2)
            hi = mid2;
        else if (ans1 > ans2)
            lo = mid1;
        else
        {
            hi = mid2;
            lo = mid1;
        }
    }
    while (hi - lo > 1e-7) // finding maximum
    {
        ll mid1 = lo + (hi - lo) / 3, mid2 = hi - (hi - lo) / 3;
        ll ans1 = fun(mid1), ans2 = fun(mid2);
        if (ans1 < ans2)
            lo = mid1;
        else if (ans1 > ans2)
            hi = mid2;
        else
        {
            hi = mid2;
            lo = mid1;
        }
    }
}

// Merge Sort
void mergeSort(long int arr[], long int array_size)
{ 
    long int temp[array_size]; 
    cout<< _mergeSort(arr, temp, 0, array_size - 1) <<endl;
}

/* An auxiliary recursive function that sorts the input array and
returns the number of inversions in the array. */
long int _mergeSort(long int arr[], long int temp[], long int left, long int right)
{ 
    long int mid, inv_count = 0;
    if (right > left) {
        /* Divide the array long into two parts and  
        call _mergeSortAndCountInv()
        for each of the parts */
        mid = (right + left) / 2; 

        /* Inversion count will be sum of  
        inversions in left-part, right-part  
        and number of inversions in merging */
        inv_count += _mergeSort(arr, temp, left, mid); 
        inv_count += _mergeSort(arr, temp, mid + 1, right);

        /*Merge the two parts*/
        inv_count += merge(arr, temp, left, mid + 1, right); 
    } 
    return inv_count; 
} 
  
/* This funt merges two sorted arrays  
and returns inversion count in the arrays.*/
long int merge(long int arr[], long int temp[], long int left, 
          long int mid, long int right) 
{ 
    long int i, j, k; 
    long int inv_count = 0; 
  
    i = left; /* i is index for left subarray*/
    j = mid; /* j is index for right subarray*/
    k = left; /* k is index for resultant merged subarray*/
    while ((i <= mid - 1) && (j <= right)) { 
        if (arr[i] <= arr[j]) { 
            temp[k++] = arr[i++]; 
        } 
        else {
            temp[k++] = arr[j++]; 
  
            /* this is tricky -- see above  
            explanation/diagram for merge()*/
            inv_count = inv_count + (mid - i);
        } 
    } 
  
    /* Copy the remaining elements of left subarray  
(if there are any) to temp*/
    while (i <= mid - 1) 
        temp[k++] = arr[i++]; 
  
    /* Copy the remaining elements of right subarray  
(if there are any) to temp*/
    while (j <= right) 
        temp[k++] = arr[j++]; 
  
    /*Copy back the merged elements to original array*/
    for (i = left; i <= right; i++) 
        arr[i] = temp[i]; 
  
    return inv_count;
}

// Hashing
namespace Hashing {
    #define ff first
    #define ss second

    const pll M = {1e9+7, 1e9+9};        ///Should be large primes
    const ll base = 1259;                ///Should be larger than alphabet size
    const int N = 1e6+7;                 ///Highest length of string

    pll operator+ (const pll& a, ll x)     {return {a.ff + x, a.ss + x};}
    pll operator- (const pll& a, ll x)     {return {a.ff - x, a.ss - x};}
    pll operator* (const pll& a, ll x)     {return {a.ff * x, a.ss * x};}
    pll operator+ (const pll& a, pll x)    {return {a.ff + x.ff, a.ss + x.ss};}
    pll operator- (const pll& a, pll x)    {return {a.ff - x.ff, a.ss - x.ss};}
    pll operator* (const pll& a, pll x)    {return {a.ff * x.ff, a.ss * x.ss};}
    pll operator% (const pll& a, pll m)    {return {a.ff % m.ff, a.ss % m.ss};}
    ostream& operator<<(ostream& os, pll hash) {
        return os<<"("<<hash.ff<<", "<<hash.ss<<")";
    }
    pll pb[N];      ///powers of base mod M

    ///Call pre before everything
    void hashPre() {
        pb[0] = {1,1};
        for (int i=1; i<N; i++)     pb[i] = (pb[i-1] * base)%M;
    }

    ///Calculates hashes of all prefixes of s including empty prefix
    vector<pll> hashList(string s) {
        int n = s.size();
        vector<pll> ans(n+1);
        ans[0] = {0,0};
        for (int i=1; i<=n; i++)    ans[i] = (ans[i-1] * base + s[i-1])%M;
        return ans;
    }

    ///Calculates hash of substring s[l..r] (1 indexed)
    pll substringHash(const vector<pll> &hashlist, int l, int r) {
        return (hashlist[r]+(M-hashlist[l-1])*pb[r-l+1])%M;
    }

    ///Calculates Hash of a string
    pll Hash (string s) {
        pll ans = {0,0};
        for (int i=0; i<s.size(); i++)  ans=(ans*base + s[i])%M;
        return ans;
    }

    ///Tested on https://toph.co/p/palindromist
    ///appends c to string
    pll append(pll cur, char c) {
        return (cur*base + c)%M;
    }

    ///Tested on https://toph.co/p/palindromist
    ///prepends c to string with size k
    pll prepend(pll cur, int k, char c) {
        return (pb[k]*c + cur)%M;
    }

    ///Tested on https://toph.co/p/chikongunia
    ///replaces the i-th (0-indexed) character from right from a to b;
    pll replace(pll cur, int i, char a, char b) {
        return cur + pb[i] * (M+b-a)%M;
    }

    ///Erases c from front of the string with size len
    pll pop_front(pll hash, int len, char c) {
        return (hash + pb[len-1]*(M-c))%M;
    }

    ///Tested on https://toph.co/p/palindromist
    ///concatenates two strings where length of the right is k
    pll concat(pll left, pll right, int k) {
        return (left*pb[k] + right)%M;
    }

    pll power (const pll& a, ll p) {
        if (p==0)   return {1,1};
        pll ans = power(a, p/2);
        ans = (ans * ans)%M;
        if (p%2)    ans = (ans*a)%M;
        return ans;
    }

    pll inverse(pll a)  {
        if (M.ss == 1)  return power(a, M.ff-2);
        return power(a, (M.ff-1)*(M.ss-1)-1);
    }

    ///Erases c from the back of the string
    pll invb = inverse({base, base});
    pll pop_back(pll hash, char c) {
        return ((hash-c+M)*invb)%M;
    }

    ///Tested on https://toph.co/p/palindromist
    ///Calculates hash of string with size len repeated cnt times
    ///This is O(log n). For O(1), pre-calculate inverses
    pll repeat(pll hash, int len, ll cnt) {
        pll mul = ((pb[len*cnt]-1+M) * inverse(pb[len]-1+M))%M;
        pll ans = (hash*mul);
        if (pb[len].ff == 1)    ans.ff = hash.ff*cnt;
        if (pb[len].ss == 1)    ans.ss = hash.ss*cnt;
        return ans%M;
    }
}

/// Solves https://judge.yosupo.jp/problem/enumerate_palindromes
using namespace Hashing;
vector<pll> forwardHash, backwardHash;
int n;
bool check(int l, int r) {
    return substringHash(forwardHash, l, r) == substringHash(backwardHash, n+1-r, n+1-l);
}

int main() {
    hashPre();

    string s;
    cin>>s;
    n = s.size();
    forwardHash = hashList(s);

    reverse(s.begin(), s.end());
    backwardHash = hashList(s);

    for (int i=0; i<2*n-1; i++) {
        int a = (i+1)/2, b = i/2+2;
        int lo = 0, hi = min(a, n+1-b);
        while (lo < hi) {
            int m = (lo + hi + 1)/2;
            if (check(a-m+1, b+m-1))    lo = m;
            else                        hi = m-1;
        }

        cout<<2*lo+(i%2==0)<<" ";
    }
}

// Simple hashing
int hashing(string s)
{
    // To store the hash value.
    int ans = 0;

    // To store 'P'.
    int p = 1;

    // For taking modulo.
    int m = 1000000007;
    for (int i = 0; i < s.size(); i++)
    {
        ans += (s[i] - 'a') * p;
        ans = ans % m;
        p *= 31;
    }
    return ans;
}

// Mod Pow nCr nPr gcd lcm

ll modPow(ll n, ll p, ll m) {
    if(n==0) return 0%m;
    if(p==0) return 1%m;
    if(p&1) return (n*modPow(n,p-1,m))%m;
    ll x=modPow(n,p/2,m);
    return (x*x)%m;
}

ll egcd(ll a, ll b, ll &x, ll &y) {
    // ax+by = gcd(a,b)
    // lcm(a,b) = a*b/gcd(a,b)
    if(b%a == 0) {
        x=1, y=0;
        return b;

    }
    ll x1, y1;
    ll d=egcd(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return d;
}

ll modInv(ll n, ll m) {
    ll x, y;
    egcd(n,m,x,y);
    return (m+x)%m;
}

vll f;
void modFact(vll &f, ll n, ll m) {
    f.resize(n+1);
    f[0]=1;
    lp(1,i,n+1) {
        f[i]=(f[i-1]*i)%m;
    }
}

ll modnCr(ll n, ll r, ll m) {
    // nPr = nCr * r!
    return (((f[n]*modInv(f[r],m))%m)*modInv(f[n-r],m))%m;
}

// log

vector<double> log_fact;
void fact_log(int n) {
    log_fact.assign(n + 1, 0.0);
    log_fact[0] = 0.0; 
    for (int i = 1; i <= n; i++) log_fact[i] = log_fact[i - 1] + log(i); 
}

ll log_nCk(int n, int k) { 
    if (k < 0 || k > n) return 0;
    return exp(log_fact[n] - log_fact[n - k] - log_fact[k]); 
}

// Factorials
vector<int>fact;
vector<int>invfac;

void factorials(int N){
    N = N+1;

    fact.resize(N+1);
    invfac.resize(N+1);

    invfac[0]=1;
    invfac[1] = 1;
    fact[0]=1;
    fact[1] = 1;
    for(int i=2; i<N; i++) invfac[i] = (mod - (mod/i)*invfac[mod%i]%mod)%mod;
    for(int i=1; i<N; i++){
        fact[i]=i*fact[i-1];
        invfac[i]*=invfac[i-1];
        fact[i]%=mod;
        invfac[i]%=mod;
    }
}


// Prime

class Prime
{
    vector<int> mark, prime;

public:
    Prime(int n)
    {
        mark.resize(n + 5, 0);
        int limit = sqrt(n + 1);
        mark[1] = -1;
        prime.push_back(2);
        mark[2] = 2;
        for (int i = 4; i <= n; i += 2)
            mark[i] = 2;
        for (int i = 3; i <= n; i += 2)
        {
            if (!mark[i])
            {
                mark[i] = i;
                prime.push_back(i);
                // cout << i << endl;
                if (i > limit)
                    continue;
                for (int j = i * i; j <= n; j += i * 2)
                    mark[j] = i;
            }
        }
    }
    int nextPrime(int n)
    {
        // cout << n << ' '<<prime.back() << endl;
        if (n > prime.back())
            return n;
        return *lower_bound(prime.begin(), prime.end(), n);
    }
    int prevPrime(int n)
    {
        // cout << n << ' '<<prime.back() << endl;
        if (n <= 2)
            return n;
        return *prev(lower_bound(prime.begin(), prime.end(), n));
    }
};

Prime primes(1e7);

vll lpf;
vll prime;
void sieve(ll n)
{
    lpf.assign(n+1, 0);
    ll limit = sqrt(n + 1);
    lpf[1] = -1;
    prime.pb(2);
    lpf[2] = 2; // incase we need divllsor or NOD(Number of div) or SOD(Sum of div)...
    for (ll i = 4; i <= n; i += 2)
        lpf[i] = 2;
    for (ll i = 3; i <= n; i += 2)
    {
        if (!lpf[i])
        {
            lpf[i] = i; // if lpf[k]!=k so it is not prime...
            prime.pb(i);
            if (i > limit)
                continue; // j=prime1*prime2 if prime1>limit, so prime2<limit. So already has been checked...
            // {
            // No need to check <i*i becouse it surely has prime num <i...
            // No need incrementation j+=i, becouse there will be even number(not prime)...
            for (ll j = i * i; j <= n; j += i * 2)
                lpf[j] = i;
            // }
        }
    }
}

vpll prime_factorization(ll n)
{
    vpll factors;
    while (n > 1)
    {
        ll p = lpf[n];
        ll cnt = 0;
        while (n % p == 0)
        {
            n /= p;
            cnt++;
        }
        factors.pb(mp(p, cnt));
    }
    return factors;
}

bool isPrime(int n) {
    if (n < 2 || n % 6 % 4 != 1) return (n | 1) == 3;
    int A[] = {2, 325, 9375, 28178, 450775, 9780504, 1795265022},
    s = __builtin_ctzll(n-1), d = n >> s;
    for (int a : A) { // ^ count t ra i l in g zeroes
        int p = modpow(a%n, d, n), i = s;
        while (p != 1 && p != n - 1 && a % n && i--)
            p = modmul(p, p, n);
        if (p != n-1 && i != s) return 0;
    }
    return 1;
}

// BigMod BigSum BigMul
long bigmod(long a, long b, long m) {
    if(b==0) return 1%m;
    long x = bigmod(a,b/2,m);
    x = (x*x)%m;
    if(b&1) x = (a*x)%m;
    return x;
}

long bigsum(long a, long n, long m) {
    if(n==1) return 1%m;
    if(!(n&1)) return (bigsum(a,n/2,m)*(1 + bigmod(a,n/2,m)))%m;
    else return (bigsum(a,n-1,m) + bigmod(a,n-1,m))%m;
}

int main()
{
    long a, n, m; // [1+a+a^2+a^3.....+a^(n-1)]%m
    cin >> a >> n >> m;
    cout << bigsum(a,n,m) << endl;
    return 0;
}

void bigmul()
{
    string s1, s2; cin >> s1 >> s2;
    bool minus = false;
    if(s1[0]=='-'&&s2[0]=='-') {
        s1 = s1.substr(1, s1.size());
        s2 = s2.substr(1, s2.size());
    } else if(s1[0]=='-') {
        s1 = s1.substr(1, s1.size());
        minus = true;
    } else if(s2[0]=='-') {
        s2 = s2.substr(1, s2.size());
        minus = true;
    }
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    //cout << s1 << ' ' << s2 << ' ' << minus << '=';
    vector<int> result(s1.size()+s2.size()+1);
    int carry = 0;
    for(int i=0; i<s1.size(); i++) {
        int a = s1[i] - '0'; 
        for(int j=0; j<s2.size(); j++) {
            int b = s2[j] - '0';
            result[j+i] += a*b + carry;
            result[j+i] = result[j+i]%10;
            carry = result[j+i]/10;
        }
        if(carry!=0) {
            result[s2.size()+i] += carry;
            carry = 0;
        }
    }
    reverse(result.begin(), result.end());
    bool start = false; 
    if(minus) cout << '-';
    for(int i = 0; i<s1.size()+s2.size()+1; i++) {
        if(result[i]!=0&&!start) start = true;
        if(start) cout << result[i];
    }
    cout << endl;
    return;
}

// Permutations Combinations
int c = 0;
int numbers[MAX]; // vector is slow, this is better for now thanpassing para
bool used[MAX];

void permutation(int at, ll n)
{
    c++;
    if (at > n)
    {
        for (int i = 1; i <= n; i++)
            cout << numbers[i] << ' ';
        cout << endl;
        return;
    }
    for (int i = 1; i <= n; i++)
        if (!used[i])
        {
            used[i] = true;
            numbers[at] = i;
            permutation(at + 1, n);
            used[i] = false;
        }
}

int n, k;
int numbers[MAX] = {0};

void Combination(int at, int last)
{
    if (at == k + 1)
    {
        for (int i = 1; i <= k; i++)
            cout << numbers[i] << ' ';
        cout << endl;
        return;
    }
    for (int i = last + 1; i <= n - k + at; i++)
    {
        numbers[at] = i;
        Combination(at + 1, i);
    }
}

// All subset generation
vector<vector<ll>> subsetgen(vector<ll> &nums)
{
    ll n = nums.size();
    ll subsetCount = 1 << n;
    vector<vector<ll>> subsets;
    for (ll mask = 0; mask < subsetCount; ++mask)
    {
        vector<ll> subset;
        for (ll i = 0; i < n; ++i)
        {
            if (mask & (1 << i))
            {
                subset.push_back(nums[i]);
            }
        }
        subsets.push_back(subset);
    }
    return subsets;
}

// dfs
void dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            dfs(x, graph, isVisited);
        }
    }
}

// bfs
void bfs(ll source, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    queue<ll> q;
    isVisited[source] = true;
    q.push(source);
    while (q.size())
    {
        ll vertex = q.front();
        q.pop();
        for (auto x : graph[vertex])
        {
            if (!isVisited[x])
            {
                q.push(x);
                isVisited[x] = true;
            }
        }
    }
}

// Shortest path using bfs
vector<ll> Parents;
vector<ll> Distance;
ll Source;
void bfs(ll source, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    Parents.clear();
    Distance.clear();
    Parents.assign(isVisited.size(), 0);
    Distance.assign(isVisited.size(), 0);
    Source = source;
    queue<ll> q;
    isVisited[source] = true;
    q.push(source);
    while (q.size())
    {
        ll vertex = q.front();
        q.pop();
        for (auto x : graph[vertex])
        {
            if (!isVisited[x])
            {
                q.push(x);
                isVisited[x] = true;
                Parents[x] = vertex;
                Distance[x] = Distance[vertex] + 1;
            }
        }
    }
}

vector<ll> shortest_path(ll destination)
{
    ll source = Source;
    vector<ll> path;
    ll node = destination;
    while (node != source)
    {
        path.push_back(node);
        node = Parents[node];
    }
    path.push_back(source);
    reverse(path.begin(), path.end());
    return path;
}

// Grid dfs
void grid_dfs(ll i, ll j, ll row, ll column)
{
    if (i < 1 || i > row || j < 1 || j > column || isVisited[i][j] == true)
        return;
    isVisited[i][j] = true;
    // adjacent cell
    grid_dfs(i + 1, j, row, column);
    grid_dfs(i - 1, j, row, column);
    grid_dfs(i, j + 1, row, column);
    grid_dfs(i, j - 1, row, column);
    // diagonal cell
    grid_dfs(i + 1, j + 1, row, column);
    grid_dfs(i - 1, j + 1, row, column);
    grid_dfs(i - 1, j - 1, row, column);
    grid_dfs(i + 1, j - 1, row, column);
}

// DSU
class DSU
{
    vector<ll> par, size;

public:
    DSU(ll n) : par(n), size(n)
    {
        fill(size.begin(), size.end(), 1);
        for (ll i = 0; i < n; i++)
            par[i] = i;
    }
    ll Anc(ll node)
    {
        if (par[node] == node)
            return node;
        return par[node] = Anc(par[node]);
    }
    bool same(ll x, ll y)
    {
        return Anc(x) == Anc(y);
    }
    void Union(ll x, ll y)
    {
        x = Anc(x), y = Anc(y);
        if (x == y)
            return;
        if (size[x] < size[y])
            swap(x, y);
        size[x] += size[y], par[y] = x;
    }
    ll Size(ll node)
    {
        return size[Anc(node)];
    }
};

// SSSP
vector<int> parrents_dijkstra;
vector<int> distance_dijkstra;
void dijkstra(vector<vector<pair<int, int>>> &graph, int source)
{
    int n = graph.size();
    parrents_dijkstra.assign(n, -1);
    distance_dijkstra.assign(n, 99999999);
    distance_dijkstra[source] = 0;
    parrents_dijkstra[source] = source;
    vector<bool> isDone(n, false);
    int cost;
    set<pair<int, int>> pq;
    pq.insert({distance_dijkstra[source], source});
    while (pq.size())
    {
        pair<int, int> p = *pq.begin();
        pq.erase(pq.begin());
        cost = p.first;
        if (isDone[p.second])
            continue;
        isDone[p.second] = true;
        for (auto x : graph[p.second])
        {
            if (cost + x.second < distance_dijkstra[x.first])
            {
                distance_dijkstra[x.first] = cost + x.second;
                parrents_dijkstra[x.first] = p.second;
                pq.insert({distance_dijkstra[x.first], x.first});
            }
        }
    }
}
vector<int> shortest_path_dijkstra(int source, int destination)
{
    vector<int> path;
    int node = destination;
    while (node != source)
    {
        path.push_back(node);
        node = parrents_dijkstra[node];
    }
    path.push_back(source);
    reverse(path.begin(), path.end());
    return path;
}

// kth shortest dest

struct node
{
    ll dis, v, u;
};

ll N, M, k;
vector<ll> ans, cnt;
vector<vector<ll>> adj;
vector<node> E;

void sssp_dijkstra(ll src, ll dest)
{
    cnt.assign(N + 5, 0);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> Q;
    Q.push({0, src});
    while (!Q.empty() && cnt[dest] < k)
    {
        pair<ll, ll> u = Q.top();
        Q.pop();
        cnt[u.second]++;
        if (u.second == dest)
            ans.push_back(u.first);
        if (cnt[u.second] > k)
            continue;
        for (ll a : adj[u.second])
        {
            node x = E[a];
            Q.push({u.first + x.dis, x.v});
        }
    }
}

// APSP
vector<vector<int>> shortest_distance;
vector<vector<int>> graph;
void floydwarshall(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int u = 1; u <= n; u++)
        {
            for (int v = 1; v <= n; v++)
            {
                shortest_distance[u][v] = min(shortest_distance[u][v], shortest_distance[u][i] + shortest_distance[i][v]);
            }
        }
    }
}

// Max Flow
const int MAX_N = 1e5 + 5;
const ll MOD = 1e9 + 7;
const ll INF = 1e18;

struct max_flow_graph {
    struct edge {
        int u, v, cap, flow;
    };
    int n; 
    vector<edge> el; 
    vector<vector<int>> adj;
    vector<int> dist, par;
    max_flow_graph(int n) : n(n), adj(n) {}
    void add_edge(int u, int v, int w) {
        adj[u].push_back(el.size());
        el.push_back({u, v, w, 0});
        adj[v].push_back(el.size());
        el.push_back({v, u, 0, 0}); 
    }
    int send_one_flow(int s, int e) {
        int nf = INF;
        for (int u = e; u != s; u = el[par[u]].u) {
            nf = min(nf, el[par[u]].cap - el[par[u]].flow);
        }
        for (int u = e; u != s; u = el[par[u]].u) {
            el[par[u]].flow += nf;
            el[par[u]^1].flow -= nf;
        }
        return nf;
    }
    bool bfs(int s, int e) {
        dist.assign(n, INF);
        par.assign(n, 0);
        queue<int> q;
        q.push(s); dist[s] = 0;
        while (q.size()) {
            int u = q.front(); q.pop();
            if (u == e) break;
            for (int idx : adj[u]) {
                if (el[idx].cap > el[idx].flow && dist[el[idx].v] > dist[el[idx].u] + 1) {
                    dist[el[idx].v] = dist[el[idx].u] + 1;
                    par[el[idx].v] = idx;
                    q.push(el[idx].v);
                }
            }
        }
        return dist[e] < INF;
    }
    ll edmonds_karp(int s, int e) {
        ll mf = 0;
        while (bfs(s, e)) mf += send_one_flow(s, e);
        return mf;
    }
};

void solve() {
    int n, m; cin >> n >> m;
    max_flow_graph adj(n);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        adj.add_edge(u, v, w);
    }
    cout << adj.edmonds_karp(0, n - 1) << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++) {
        // cout << "Case #" << t << ": ";
        solve();
    }
}

// Bridges of a graph
void bridgedfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, vector<ll> &start, vector<ll> &low, vector<ll> &parrents, ll &timer, vector<pair<ll, ll>> &ret)
{
    isVisited[vertex] = true;
    start[vertex] = timer++;
    low[vertex] = start[vertex];
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            parrents[x] = vertex;
            bridgedfs(x, graph, isVisited, start, low, parrents, timer, ret);
        }
        if (parrents[vertex] != x)
            low[vertex] = min(low[vertex], low[x]);
    }
    if (low[vertex] > start[parrents[vertex]] && vertex > 1)
    {
        ret.push_back({min(vertex, parrents[vertex]), max(vertex, parrents[vertex])});
    }
}
vector<pair<ll, ll>> bridges(vector<vector<ll>> &graph)
{
    ll n = graph.size() - 1, timer = 1;
    vector<ll> start(n + 1, 0), low(n + 1);
    vector<ll> parrents(n + 1, 0);
    vector<bool> isVisited(n + 1, false);
    vector<pair<ll, ll>> ret;
    bridgedfs(1, graph, isVisited, start, low, parrents, timer, ret);
    return ret;
}

// least common ancestor
pair<ll, ll> func(ll n)
{
    pair<ll, ll> ret;
    for (int i = 31; i >= 0; i--)
    {
        if (n & (1 << i))
        {
            ret.first = i;
            ret.second = n & (1 << i);
            break;
        }
    }
    return ret;
}

vector<vector<ll>> bin_lift;
vector<ll> next_child;
void bin_lift_func(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, vector<ll> parv, ll level)
{
    isVisited[vertex] = true;
    if (level > 0)
    {
        for (auto x : parv)
            bin_lift[vertex].push_back(next_child[x]);
        pair<ll, ll> pr = func(level);
        if (pr.second == level)
            bin_lift[vertex].push_back(1);
    }
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            next_child[vertex] = x;
            bin_lift_func(x, graph, isVisited, bin_lift[vertex], level + 1);
        }
    }
}

ll get_kth_parrent(ll node, ll kth_parrent)
{
    pair<ll, ll> pr = func(kth_parrent);
    ll pow_2 = pr.first;
    ll powl_ = pr.second;
    if (powl_ == kth_parrent && pow_2 < bin_lift[node].size())
        return bin_lift[node][pow_2];
    else if (pow_2 < bin_lift[node].size())
        return get_kth_parrent(bin_lift[node][pow_2], kth_parrent - powl_);
    else
        return -1;
}
vector<ll> start_time, end_time, level_of;
ll time_ = 0;
void calc_time(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited, ll level)
{
    isVisited[vertex] = true;
    level_of[vertex] = level;
    time_++;
    start_time[vertex] = time_;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            calc_time(x, graph, isVisited, level + 1);
        }
    }
    time_++;
    end_time[vertex] = time_;
}
ll least_common_ancestor(ll u, ll v)
{
    if (start_time[u] <= start_time[v] && end_time[u] >= end_time[v])
        return u;
    else if (start_time[v] <= start_time[u] && end_time[v] >= end_time[u])
        return v;
    ll lca;
    lca = u;
    while (1)
    {
        ll dum;
        for (int i = 0; i < bin_lift[lca].size(); i++)
        {
            ll k = bin_lift[lca][i];
            if (start_time[k] < start_time[v] && end_time[k] > end_time[v])
            {
                if (i == 0)
                {
                    return k;
                }
                else
                {
                    break;
                }
            }
            else
                dum = k;
        }
        lca = dum;
    }
    return lca;
}
void init(ll n)
{
    vector<ll> v;
    bin_lift.assign(n + 1, v);
    next_child.assign(n + 1, 0);
    start_time.assign(n + 1, 0);
    end_time.assign(n + 1, 0);
    level_of.assign(n + 1, 0);
}
void pre_processing(ll number_of_nodes, vector<vector<ll>> &graph, ll root)
{
    init(number_of_nodes);
    vector<bool> isVIsited(number_of_nodes + 1, false);
    vector<ll> v;
    bin_lift_func(root, graph, isVIsited, v, 0);
    isVIsited.assign(number_of_nodes + 1, false);
    calc_time(root, graph, isVIsited, 0);
}

// Matrix
vector<vll> matrix_multiplication(vector<vll> &a, vector<vll> &b, ll n)
{
    vector<vll> ans(n, vll(n, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                ans[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    return ans;
}
vector<vll> binExp(vector<vll> &a, ll b, ll n)
{
    if (b == 1)
        return a;
    vector<vll> ans = binExp(a, b / 2, n);
    if (b % 2 != 0)
    {
        vector<vll> v = matrix_multiplication(ans, ans, n);
        return matrix_multiplication(v, a, n);
    }
    else
    {
        return matrix_multiplication(ans, ans, n);
    }
}

// matrix chain multi
ll matrixChain(ll di[], ll n)
{
    lp(0, l, n + 1) mi[l][l] = 0;
    lp(0, l, n)
    {
        ll i = 1, j = l + 2;
        while (j <= n && i <= (n - l))
        {
            mi[i][j] = MAX;
            lp(i, k, j)
            {
                ll ans = mi[i][k] + mi[k + 1][j] + di[i - 1] * di[k] * di[j];
                if (ans < mi[i][j])
                    mi[i][j] = ans, s[i][j] = k;
            }
            i++, j++;
        }
    }
    return mi[1][n];
}

// Strongly connected components
ll time_ = 0;
vector<ll> start_t, end_t;
void scc_dfs(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    time_++;
    start_t[vertex] = time_;
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            scc_dfs(x, graph, isVisited);
        }
    }
    time_++;
    end_t[vertex] = time_;
}
vector<ll> nodes;
void scc_dfs_2(ll vertex, vector<vector<ll>> &graph, vector<bool> &isVisited)
{
    isVisited[vertex] = true;
    nodes.push_back(vertex);
    for (auto x : graph[vertex])
    {
        if (!isVisited[x])
        {
            scc_dfs_2(x, graph, isVisited);
        }
    }
}
vector<vector<ll>> all_scc;
vector<ll> map_scc_index;
void strongly_connnected_components(ll n, vector<pair<ll, ll>> &edge_list)
{
    ll i;
    start_t.assign(n + 1, 0);
    end_t.assign(n + 1, 0);
    map_scc_index.assign(n + 1, 0);
    vector<vector<ll>> graph(n + 1), graph_t(n + 1);
    for (auto x : edge_list)
    {
        graph[x.first].push_back(x.second);
        graph_t[x.second].push_back(x.first);
    }
    vector<bool> isVisited(n + 1, false);
    for (i = 1; i <= n; i++)
    {
        if (!isVisited[i])
        {
            scc_dfs(i, graph, isVisited);
        }
    }
    isVisited.assign(n + 1, false);
    vector<pair<ll, ll>> vp;
    for (i = 1; i <= n; i++)
    {
        vp.push_back({end_t[i], i});
    }
    sort(vp.begin(), vp.end());
    reverse(vp.begin(), vp.end());
    all_scc.push_back(vector<ll>(0));
    i = 1;
    for (auto x : vp)
    {
        if (!isVisited[x.second])
        {
            nodes.clear();
            scc_dfs_2(x.second, graph_t, isVisited);
            all_scc.push_back(nodes);
            for (auto y : nodes)
            {
                map_scc_index[y] = i;
            }
            i++;
        }
    }
}

// 2D presum
ll presum[1008][1008];
void grid_presum(ll row, ll column)
{
    for (ll i = 2; i <= row; i++)
    {
        presum[i][1] = presum[i][1] + presum[i - 1][1];
    }
    for (ll i = 2; i <= column; i++)
    {
        presum[1][i] = presum[1][i] + presum[1][i - 1];
    }
    for (ll i = 2; i <= row; i++)
    {
        for (ll j = 2; j <= column; j++)
        {
            presum[i][j] = presum[i][j] + presum[i - 1][j] + presum[i][j - 1] - presum[i - 1][j - 1];
        }
    }
}
ll query(pair<ll, ll> p1, pair<ll, ll> p2)
{
    return presum[p2.first][p2.second] + presum[p1.first - 1][p1.second - 1] - presum[p2.first][p1.second - 1] - presum[p1.first - 1][p2.second];
}

// DP 01 knapsack
ll n, W;
ll p[100][100] = {0};
// vector<vll> p((int)1001,vll((int)1001,0));

ll dp_type1(vll w, vll v, ll i, ll wt)
{
    if (i == 0 || wt == 0)
        return 0;
    if (p[i][wt])
        return p[i][wt];
    if (w[i - 1] > wt)
        return p[i][wt] = dp_type1(w, v, i - 1, wt);
    return p[i][wt] = max(dp_type1(w, v, i - 1, wt), dp_type1(w, v, i - 1, wt - w[i - 1]) + v[i - 1]);
}

ll dp_type2(vll w, vll v, ll i, ll wt)
{
    if (i == n)
        return 0;
    if (p[i][wt])
        return p[i][wt];
    if (w[i] + wt > W)
        return p[i][wt] = dp_type2(w, v, i + 1, wt);
    return p[i][wt] = max(dp_type2(w, v, i + 1, wt), dp_type2(w, v, i + 1, wt + w[i]) + v[i]);
}

ll dp_type3(vll w, vll v)
{
    lp(1, i, n + 1)
    {
        lp(1, wj, W + 1)
        {
            if (w[i - 1] > wj)
                p[i][wj] = p[i - 1][wj];
            else
                p[i][wj] = max(p[i - 1][wj], p[i - 1][wj - w[i - 1]] + v[i - 1]);
        }
    }
    return p[n][W];
}

ll d[2][100] = {0};
ll dp_type4(vll w, vll v)
{
    lp(1, i, n + 1)
    {
        lp(1, wj, W + 1)
        {
            if (w[i - 1] > wj)
                d[i%2][wj] = d[(i - 1)%2][wj];
            else
                d[i%2][wj] = max(d[(i - 1)%2][wj], d[(i - 1)%2][wj - w[i - 1]] + v[i - 1]);
        }
    }
    return d[n%2][W];
}

// Traveling Salesman bitmask DP
const int MAX_N = 11;
int n, x[MAX_N], y[MAX_N], adj[MAX_N][MAX_N], dp[1 << MAX_N][MAX_N];

int tsp(int mask, int u) {
    if (mask == (1 << n) - 1) return adj[u][0]; // finish all nodes (bitmask == 11...11)
    if (dp[mask][u] != -1) return dp[mask][u];

    int ans = INT_MAX;
    // Visit all the unvisited nodes and take the best route
    for (int v = 0; v < n; v++) {
        if (!(mask & (1 << v))) { // this node is unvisited
            int cur = adj[u][v] + tsp(mask | (1 << v), v);
            ans = min(ans, cur);
        }
    }
    return dp[mask][u] = ans;
}

// Longest common substr
int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        int ans=0;
        vector<vector<int>> dp(2, vector<int>(m+1,0));
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++)
            {
                if(S1[i-1]==S2[j-1]) dp[i%2][j]=dp[(i-1)%2][j-1]+1;//Just using diagonal
                else dp[i%2][j]=0;
                ans=max(ans,dp[i%2][j]);
            }
        }
        return ans;
    }

// MO's Algo
struct Query {
    int l, r, id;
};
const int MAX_N = 100000;  // Adjust according to your constraints
int n, q;
int arr[MAX_N], ans[MAX_N], cnt[MAX_N], cur;
Query qs[MAX_N];

// Function to add an element
void add(int idx) {
    if (cnt[arr[idx]] == 0) cur++;  // If it's the first occurrence
    cnt[arr[idx]]++;  // Increment count of this element
}

// Function to remove an element
void subtract(int idx) {
    if (cnt[arr[idx]] == 1) cur--;  // If it's the last occurrence
    cnt[arr[idx]]--;  // Decrement count of this element
}

// Function to perform Mo's Algorithm
void mo_algo() {
    sort(qs, qs + q, [](Query a, Query b) {
        // Sort by blocks and then by R values
        return (a.l / sqrt(n) == b.l / sqrt(n)) ? a.r < b.r : a.l < b.l;
    });

    int curL = 0, curR = 0;
    add(0);  // Add the first element (0-indexed)

    for (int i = 0; i < q; i++) {
        int L = qs[i].l, R = qs[i].r;
        // Move the left pointer
        while (curL < L) subtract(curL++);
        while (curL > L) add(--curL);
        // Move the right pointer
        while (curR < R) add(++curR);
        while (curR > R) subtract(curR--);

        // Store the result for this query
        ans[qs[i].id] = cur;
    }
}

int main() {
    cin >> n >> q;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < q; i++) {
        cin >> qs[i].l >> qs[i].r;  // Input the range
        qs[i].id = i;  // Store the original index
    }

    mo_algo();  // Execute Mo's Algorithm

    for (int i = 0; i < q; i++) {
        cout << ans[i] << "\n";  // Output the count of distinct elements
    }
    return 0;
}

// Occurance count Prefix func
// f[i] = length of the longest proper prefix of the substring s[0...i] which is also a suffix of this substring
vector<int> prefix_func(string s) {
    int n = s.size();
    vector<int> f(n); 
    for (int i = 1; i < n; i++) {
        int j = f[i - 1];
        while (j && s[i] != s[j]) j = f[j - 1];
        f[i] = j + (s[i] == s[j]);
    }
    return f;
}
int cnt_occ(string s, string t) {
    string ts = t + "#" + s;
    int n = t.size(), m = s.size(), nm = ts.size();
    auto f = prefix_func(ts);
    int res = 0;
    for (int i = n + 1; i < nm; i++) res += (f[i] == n);
    return res;
}

// Occurance count Z func
// f[i] = length of the longest common prefix between s and the substring s[i...n-1]
vector<int> z_func(string s) {
    int n = s.size();
    vector<int> f(n); // f[0] = 0 by default
    for (int i = 1, l = 0, r = 0; i < n; i++) {
        if (i <= r) f[i] = min(r - i + 1, f[i - l]);
        while (i + f[i] < n && s[f[i]] == s[i + f[i]]) f[i]++;
        if (i + f[i] - 1 > r) l = i, r = i + f[i] - 1;
    }
    return f;
}
int cnt_occ(string s, string t) {
    string ts = t + "#" + s;
    int n = t.size(), m = s.size(), nm = ts.size();
    auto f = z_func(ts);
    int res = 0;
    for (int i = n + 1; i < nm; i++) res += (f[i] == n);
    return res;
}

// KMP (string matching)
vll build_failure_function(string pattern, ll m) 
{
    vll failure(m+1);
    failure[0] = 0; 
    failure[1] = 0; //base case

    for(ll i = 2; i <= m; i++) { 
        ll j = failure[i - 1];
        while(true) {
            if(pattern[j] == pattern[i - 1]) { 
                failure[i] = j + 1; 
                break; 
            }
            if(j == 0) { 
                failure[i] = 0; 
                break; 
            }
            j = failure[j];
        }
    }
    return failure;   
}

bool kmp(string text, string pattern)
{
    ll n = text.size();
    ll m = pattern.size();
    vll failure = build_failure_function(pattern, m); 

    ll i = 0; // the initial state of the automaton is
            // the empty string

    ll j = 0; // the first character of the text

    while(true) {
        if(j == n) 
            return false; //reached the end of the text
        if(text[j] == pattern[i]) 
        {
            i++; // change the state of the automaton
            j++; // get the next character from the text
            if(i == m)
                return true;
        } 
        else 
        {
            if (i == 0)
                j++;
            else
                i = failure[i];//we try to "expand" the next best (largest) match
        }
    }
    return false;
}

// Articulation Point
vector<vll> adj;
vll disc, low;
vbl vis;
bitset<10001> isAP;

void find_ap(ll u, ll par, ll &time)
{
    vis[u] = 1;
    disc[u] = low[u] = ++time;
    ll childs = 0;
    for(auto v: adj[u])
    {
        if(v == par)
            continue;
        if(vis[v])
            low[u] = min(low[u], disc[v]);
        else
        {
            childs++;
            find_ap(v, u, time);
            low[u] = min(low[u], low[v]);
            if(low[v] >= disc[u] && par != -1)
                isAP[u] = 1;
        }
    }
    if(par == -1 && childs > 1)
        isAP[u] = 1;
}

void solve() {
ll time=0;
    lp(1, i, n+1)
    {
        if(!vis[i])
            find_ap(i, -1, time);
    }
}

// Bridge
vector<vll> adj;
vll disc, low;
vbl vis;
vpll bridge;

void find_bridge(ll u, ll par, ll &time)
{
    vis[u] = 1;
    disc[u] = low[u] = ++time;
    for(auto v: adj[u])
    {
        if(v == par)
            continue;
        if(vis[v])
            low[u] = min(low[u], disc[v]);
        else
        {
            find_bridge(v, u, time);
            low[u] = min(low[u], low[v]);
            if(low[v] > disc[u])
                bridge.pb({min(u, v), max(u, v)});
        }
    }
}
void solve() {
ll time=0;
    lp(0, i, n)
    {
        if(!vis[i])
            find_bridge(i, -1, time);
    }
}


// Fenwick tree
// Point updates and range queries
class Fenwick{
    public:
    int n, tree[MAX];

    Fenwick(){}

    Fenwick(int m){
        n = m;
        for (int i = 1; i <= n; i++) tree[i] = 0;
    }

    /// Add v to index p
    void update(int p, int v){
        while (p <= n){
            tree[p] += v;
            p += (p & (-p));
        }
    }

    /// Returns sum from index [1:p]
    int query(int p){
        int res = 0;
        while (p){
            res += tree[p];
            p ^= (p & (-p));
        }
        return res;
    }

    /// Returns sum from index [l:r]
    int query(int l, int r){
        if (l > r) return 0;
        return (query(r) - query(--l));
    }
};

// Range updates and point queries
class Fenwick{
    public:
    int n, tree[MAX];

    Fenwick(){}

    Fenwick(int m){
        n = m;
        for (int i = 1; i <= n; i++) tree[i] = 0;
    }

    /// Add v to index [p:n]
    void update(int p, int v){
        while (p <= n){
            tree[p] += v;
            p += (p & (-p));
        }
    }

    /// Add v to index [l:r]
    void update(int l, int r, int v){
        if (l > r) return;
        update(l, v);
        update(r + 1, -v);
    }

    /// Returns value of index p
    int query(int p){
        int res = 0;
        while (p){
            res += tree[p];
            p ^= (p & (-p));
        }
        return res;
    }
};

//Range updates and range queries
class Fenwick{
    public:
    int n;
    long long tree[MAX], temp[MAX];

    Fenwick(){}

    Fenwick(int m){
        n = m;
        for (int i = 1; i <= n; i++) tree[i] = temp[i] = 0;
    }

    void update(long long* tree, int p, long long v){
        while (p <= n){
            tree[p] += v;
            p += (p & (-p));
        }
    }

    /// Add v to index [l:r]
    void update(int l, int r, long long v){
        if (l > r) return;
        update(tree, l, v);
        update(tree, r + 1, -v);
        update(temp, l, v * (l - 1));
        update(temp, r + 1, (-v) * r);
    }

    long long query(long long* tree, int p){
        long long res = 0;
        while (p){
            res += tree[p];
            p ^= (p & (-p));
        }
        return res;
    }

    /// Returns sum from index [1:p]
    long long query(int p){
        return ((query(tree, p) * p) - query(temp, p));
    }

    /// Returns sum from index [l:r]
    long long query(int l, int r){
        if (l > r) return 0;
        return (query(r) - query(--l));
    }
};

