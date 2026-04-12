#include <iostream>
using namespace std;
#include <math.h>
class Solution {
public:
    bool isPowerOfThree(int n) {}
};


int main(int argc, char const *argv[]) {
    // 手动找一下最大的数
    int n = 1;
    int border = pow(2, 31);
    while (-border < n && border - 1) {
        n *= 3;
    }
    
    return 0;
}
