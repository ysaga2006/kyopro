#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

constexpr std::array<int, 4> di4 = {-1, 0, 1, 0};
constexpr std::array<int, 4> dj4 = {0, 1, 0, -1};

struct dsu {
  public:
    dsu() : _n(0) {}
    explicit dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        return _leader(a);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                          [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;

    int _leader(int a) {
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = _leader(parent_or_size[a]);
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  ll h, w, q; cin >> h >> w >> q;

  auto ttoo = [&](ll x, ll y) {
  return x * w + y;
  };

  vector mp(h, vector<bool>(w, false));

  dsu g(h * w);


  while (q--) {
    ll op; cin >> op;
    if (op == 1) {
      ll r, c; cin >> r >> c; --r; --c;
      mp[r][c] = true;
      rep(i, 4) {
        ll nr = r + di4[i], nc = c + dj4[i];
        if (nr < 0 || nc < 0 || nr >= h || nc >= w) continue;
        if (mp[nr][nc] == true) {
          g.merge(ttoo(r, c), ttoo(nr, nc));
        }
      }
    } else {
      ll ra, ca, rb, cb; cin >> ra >> ca >> rb >> cb; --ra; --ca; --rb; --cb;
      bool ok = true;
      if (mp[ra][ca] == false || mp[rb][cb] == false) ok = false;
      if (!g.same(ttoo(ra, ca), ttoo(rb, cb))) ok = false;
      cout << (ok ? "Yes" : "No") << '\n';
    }
  }
  return 0;
}