#include <math.h>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <array>
#include <cstring>
#include <ctime>
#include <cassert>
#include <string_view>
#include <functional>
#include <sstream>
#include <numeric>
#include <cmath>
#include <deque>
#include <list>
#include <algorithm>
#include <iomanip>
 
using namespace std;
 
using i64 = long long;
using ui32 = unsigned int;
using ui64 = unsigned long long;
 
#define all(a) (a).begin(), (a).end()
 
 
struct Tree;
 
Tree* NewNode();
 
struct Count {
    int left = 0;
    int right = 0;
    void Add(int delta) {
        left += delta;
        if (delta < 0) {
            right -= delta;
        }
    }
    void operator += (const Count& c) {
        left += c.left;
        right += c.right;
    }
 
    int GetMin() {
        return min(left, right);
    }
};
 
struct Tree {
        Count count;
        Tree* left = nullptr;
        Tree* right = nullptr;
 
        void Add(int l, int r, int p, int delta = 1) {
            count.Add(delta);
            if (r - l == 1) {
                return;
            }
            int mid = (l + r) / 2;
            if (p < mid) {
                if (left == nullptr) {
                    left = NewNode();
                }
                left->Add(l, mid, p, delta);
            } else {
                if (right == nullptr) {
                    right = NewNode();
                }
                right->Add(mid, r, p, delta);
            }
        } 
 
        Count LeftCount() {
            if (left) {
                return left->count;
            }
            return {};
        }
        Count RightCount() {
            if (right) {
                return right->count;
            }
            return {};
        }
 
        void Remove(int l, int r, int p) {
            Add(l, r, p, -1);
        }
};
 
Tree nodes[7000000];
 
Tree* NewNode() {
    static Tree* nextNode = nodes;
    return nextNode++;
}
 
 
struct Solver {
    struct Point {
        int x, y;
        bool operator < (const Point& p) const {
            return x < p.x;
        }
    };
 
    int max = 0;
    int bx = 0;
    int by = 0;
 
    bool FindBest(int l, int r, Tree* node, const Count& left = {}, const Count& right = {}) {
        if (node == nullptr) {
            return false;
        }
        int mid = (l + r) / 2;
        Count newLeft = node->LeftCount();
        Count newRight = node->RightCount();
        newLeft += left;
        newRight += right;
        int mn = min(newLeft.GetMin(), newRight.GetMin());
        bool updated = false;
        if (mn > max) {
            max = mn;
            by = mid;
            updated = true;
        }
        if (mn == newLeft.GetMin()) {
            if (FindBest(mid, r, node->right, newLeft, right)) {
                return true;
            }
        } else {
            if (FindBest(l, mid, node->left, left, newRight)) {
                return true;
            }
        }
        return updated;
    }
 
    void Solve(istream& cin, ostream& cout) {
        int n;
        cin >> n;
        vector<Point> a(n);
        int t9 = 1000000001;
        #ifdef pperm
            t9 = 100;
        #endif
        Tree* tree = NewNode();
        for (Point& p : a) {
            cin >> p.x >> p.y;
            tree->Add(-t9, t9, p.y);
        }
        sort(all(a));
        for (int i = 0; i < n;) {
            int j = i + 1;
            while (j < n && a[j].x == a[i].x) {
                ++j;
            }
            if (FindBest(-t9, t9, tree)) {
                bx = a[i].x;
            }
            for (;i < j; ++i) {
                tree->Remove(-t9, t9, a[i].y);
 
            }
        }
        cout << max << '\n' << bx << ' ' << by << endl;
    }
};
 
int main(int argc, char* args[]) {
#ifdef pperm
    ifstream cin("/home/pperm86/My/Codeforces/input.txt");
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef pperm
    srand(time(0));
#endif
    int T = 1;
    cin >> T;
    for (int iTest = 1; iTest <= T; ++iTest) {
		Solver solver{};
        solver.Solve(cin, cout);
    }
#ifdef pperm
    cout << clock() / static_cast<double>(CLOCKS_PER_SEC) << endl;
#endif
    return 0;
}