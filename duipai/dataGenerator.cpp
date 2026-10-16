// data.cpp - 随机数据生成器
#include <algorithm>
#include <cstdio>
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <vector>
#include <assert.h>
#include <memory.h>
#include <cmath>
#include <random>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int randInt(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}

int main() {
    freopen("0_input.txt", "w", stdout);
    // 设置随机种子
    srand(time(0));
    
    // 生成测试数据示例：n个数和m个询问
    int T = 1;
    int n = randInt(1, 10);
    int h = randInt(1, 10);
    
    cout << T << '\n' << n << " " << h << endl;
    
    // 生成数组
    for (int i = 0; i < n; i++) {
        cout << randInt(1, h) << " \n"[i == n-1];
    }
    
    return 0;
}