#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
string to_string(pair<A, B> p);
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p);
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p);
string to_string(const string& s) {
    return '"' + s + '"';
}
string to_string(const char* s) {
    return to_string((string)s);
}
string to_string(bool b) {
    return (b ? "true" : "false");
}
string to_string(vector<bool> v) {
    bool first = true;
    string res = "{";
    for (int i = 0; i < static_cast<int>(v.size()); i++) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(v[i]);
    }
    res += "}";
    return res;
}
template <size_t N>
string to_string(bitset<N> v) {
    string res = "";
    for (size_t i = 0; i < N; i++) {
        res += static_cast<char>('0' + v[i]);
    }
    return res;
}
template <typename A>
string to_string(A v) {
    bool first = true;
    string res = "{";
    for (const auto& x : v) {
        if (!first) {
            res += ", ";
        }
        first = false;
        res += to_string(x);
    }
    res += "}";
    return res;
}
template <typename A, typename B>
string to_string(pair<A, B> p) {
    return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";
}
template <typename A, typename B, typename C>
string to_string(tuple<A, B, C> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ")";
}
template <typename A, typename B, typename C, typename D>
string to_string(tuple<A, B, C, D> p) {
    return "(" + to_string(get<0>(p)) + ", " + to_string(get<1>(p)) + ", " + to_string(get<2>(p)) + ", " + to_string(get<3>(p)) + ")";
}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    cerr << " " << to_string(H);
    debug_out(T...);
}
template <typename T>
void read(T& val) {
    cin >> val;
}
template <typename T>
void read(vector<T>& a) {
    for (int i = 0; i < (int)a.size(); ++i) {
        read(a[i]);
    }
}
template <typename Head, typename... Tail>
void read(Head& H, Tail&... T) {
    read(H);
    read(T...);
}
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...) 42
#endif
#define vec vector
#define i64 long long
#define endl '\n'
#define sz(x) (int)(x).size()
#define times(n) for (int i = 0; i < (n); ++i)
#define bits(x) __builtin_popcount(x)

int query_number = 1;
void print_query() {
#ifdef LOCAL
    cout << "Query #" << query_number++ << ": ";
#endif
}
int test_case_number = 1;
void print_case() {
#ifdef LOCAL
    cout << "Case #" << test_case_number++ << ": ";
#endif
}

class Cell {
   public:
    int x;
    int y;
    int val;
    Cell(){};
    Cell(int nx, int ny, int nval) {
        this->x = nx;
        this->y = ny;
        this->val = nval;
    }
};

vector<vector<Cell>> mat;
// vector<string> ans;
string res;
int lines = 0;
void flip(Cell& c) {
    c.val = c.val == 1 ? 0 : 1;
    mat[c.x][c.y].val = mat[c.x][c.y].val == 1 ? 0 : 1;
}
void pc(Cell& c) {
    // cout << c.x << ' ' << c.y << ' ';
    res += to_string(c.x + 1) + " " + to_string(c.y + 1) + " ";
    flip(c);
}
int count(vector<vector<Cell>>& at) {
    int c = 0;
    for (auto u : at)
        for (Cell v : u)
            c += v.val;
    return c;
}

bool has2AdjacentOnes(vector<vector<Cell>>& at) {
    assert(count(at) == 2);
    return (at[0][0].val == at[0][1].val) || (at[0][1].val == at[1][1].val) || (at[1][1].val == at[1][0].val) || (at[1][0].val == at[0][0].val);
}

void solve3Ones(vector<vector<Cell>>& at) {
    // cout << "solving 3Ones" << endl;
    // cout << "{{" << at[0][0].val << ", " << at[0][1].val << "}, {" << at[1][0].val << ", " << at[1][1].val << "}}" << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            int c = 0;
            if (at[i][j].val == 1) {
                if (i + 1 < 2 && at[i + 1][j].val == 1) c++;
                if (j + 1 < 2 && at[i][j + 1].val == 1) c++;
                if (i - 1 >= 0 && at[i - 1][j].val == 1) c++;
                if (j - 1 >= 0 && at[i][j - 1].val == 1) c++;
                if (c == 2) {
                    pc(at[i][j]);
                    if (i + 1 < 2 && at[i + 1][j].val == 1) pc(at[i + 1][j]);
                    if (j + 1 < 2 && at[i][j + 1].val == 1) pc(at[i][j + 1]);
                    if (i - 1 >= 0 && at[i - 1][j].val == 1) pc(at[i - 1][j]);
                    if (j - 1 >= 0 && at[i][j - 1].val == 1) pc(at[i][j - 1]);
                    // cout << endl;
                    res += '\n';
                    lines++;
                    return;
                }
            }
        }
    }
}
void solve2AdjacentOnes(vector<vector<Cell>>& at) {
    // cout << "solving 2AdjacentOnes " << endl;
    // cout << "{{" << at[0][0].val << ", " << at[0][1].val << "}, {" << at[1][0].val << ", " << at[1][1].val << "}}" << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (at[i][j].val == 0) {
                // debug(i, j);
                pc(at[i][j]);
                if (i + 1 < 2) pc(at[i + 1][j]);
                if (j + 1 < 2) pc(at[i][j + 1]);
                if (i - 1 >= 0) pc(at[i - 1][j]);
                if (j - 1 >= 0) pc(at[i][j - 1]);
                // cout << endl;
                res += '\n';
                lines++;
                solve3Ones(at);
                return;
            }
        }
    }
}
void solve2NonAdjacent(vector<vector<Cell>>& at) {
    // cout << "solve2NonAdjacent" << endl;
    pc(at[0][0]);
    pc(at[1][0]);
    pc(at[0][1]);
    // cout << endl;
    res += '\n';
    lines++;
    solve3Ones(at);
}

void solve1(vector<vector<Cell>>& at) {
    // cout << "solving 1" << endl;
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            if (at[i][j].val == 1) {
                int c = 1;
                pc(at[i][j]);
                if (i + 1 < 2 && at[i + 1][j].val == 0) {
                    pc(at[i + 1][j]);
                    c++;
                    if (c == 3) {
                        res += '\n';
                        lines++;
                        // // cout << endl;
                        solve2NonAdjacent(at);
                        return;
                    }
                }
                if (j + 1 < 2 && at[i][j + 1].val == 0) {
                    pc(at[i][j + 1]);
                    c++;
                    if (c == 3) {
                        res += '\n';
                        lines++;
                        // cout << endl;
                        solve2NonAdjacent(at);
                        return;
                    }
                }
                if (i - 1 >= 0 && at[i - 1][j].val == 0) {
                    pc(at[i - 1][j]);
                    c++;
                    if (c == 3) {
                        res += '\n';
                        lines++;
                        // cout << endl;
                        solve2NonAdjacent(at);
                        return;
                    }
                }
                if (j - 1 >= 0 && at[i][j - 1].val == 0) {
                    pc(at[i][j - 1]);
                    c++;
                    if (c == 3) {
                        res += '\n';
                        lines++;
                        // cout << endl;
                        solve2NonAdjacent(at);
                        return;
                    }
                }
            }
        }
    }
}

void solve4(vector<vector<Cell>>& at) {
    // cout << "solving 4" << endl;
    pc(at[0][0]);
    pc(at[1][0]);
    pc(at[0][1]);
    // cout << endl;
    res += '\n';
    lines++;
    solve1(at);
}

void solve() {
    int n, m;
    cin >> n >> m;
    mat = vector<vector<Cell>>(n, vector<Cell>(m));
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        // debug(s);
        for (int j = 0; j < m; ++j) {
            mat[i][j].x = i;
            mat[i][j].y = j;
            // debug((s[i] - '0'));
            mat[i][j].val = (s[j] - '0');
        }
    }
    // for (int i = 0; i < n; ++i) {
    //     for (int j = 0; j < m; ++j) {
    //         cout << mat[i][j].val << ' ';
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < m - 1; ++j) {
            Cell a = mat[i][j];
            Cell b = mat[i][j + 1];
            Cell c = mat[i + 1][j];
            Cell d = mat[i + 1][j + 1];
            vector<vector<Cell>> at = {{a, b}, {c, d}};
            // cout << "{{" << at[0][0].val << ", " << at[0][1].val << "}, {" << at[1][0].val << ", " << at[1][1].val << "}}" << endl;
            int zeros = count(at);
            if (zeros == 0) {
                continue;
            } else if (zeros == 1) {
                solve1(at);
            } else if (zeros == 2) {
                if (has2AdjacentOnes(at)) {
                    solve2AdjacentOnes(at);
                } else {
                    solve2NonAdjacent(at);
                }
            } else if (zeros == 3) {
                solve3Ones(at);
            } else {
                assert(zeros == 4);
                solve4(at);
            }
        }
    }
    cout << lines << endl;
    cout << res << endl;
    lines = 0;
    res = "";
}

int32_t main() {

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while (t--) {
        // print_case();
        solve();
    }
}
