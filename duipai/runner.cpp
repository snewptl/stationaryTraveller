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
using namespace std;

int main() {
    int testCase = 1;
    // 生成测试数据
    system("g++ --std=c++17 std.cpp -o std");
    system("g++ --std=c++17 myCode.cpp -o myCode");
    system("g++ --std=c++17 dataGenerater.cpp -o dataGenerater");
    while (true) {
        system("./dataGenerater");
        system("./std");
        system("./myCode");
        
        // 对比结果
        if (system("diff stdOut.txt 0_output.txt")) {
            cout << "Wrong Answer on test " << testCase << endl;
            break;
        }
        cout << "Accepted on test " << testCase << endl;
        testCase++;
    }
    return 0;
}