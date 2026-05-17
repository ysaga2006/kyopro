#include <bits/stdc++.h>
using ll = long long;
using namespace std;
// 座標管理
struct point {
    int x, y;
};

// 外積
ll cross (const point &a, const point &b) {
    return (ll) a.x * b.y - a.y * b.x;
}

// まずa, bが半平面のどちらにあるかをそれぞれ上半分[0, 180)が0, 下半分が1で持つ
// それらが一致しているならcross、一致していないなら半平面の時点で順序がつけられる
// cmp(a, b)はaがbよりも前にあるなら1, 後ろにあるなら0を返す。
// つまり、ah = 0, bh = 1なら、1を返し、逆なら0を返す。
// a×bの外積が正になる時、aの方が偏角が小さい。
bool cmp (const point &a, const point &b) {
    int ah = (a.y < 0 or (a.y == 0 and a.x < 0));
    int bh = (b.y < 0 or (b.y == 0 and b.x < 0));
    if (ah != bh) {
        return (ah < bh);
    } else {
        return cross(a, b) > 0;
    }
}

// 偏角ソート
void argument_sort(vector<point> &points) {
    sort(points.begin(), points.end(), cmp);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q; cin >> n >> q;
    return 0;
}