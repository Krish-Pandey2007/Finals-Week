#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, 50, "t");
    inf.readEoln(); 

    long long sum_n = 0;

    for (int test = 1; test <= t; test++) {
        int n = inf.readInt(1, 200000, "n");
        inf.readSpace();
        
        int k = inf.readInt(1, n, "k");
        inf.readSpace();
        
        int l = inf.readInt(1, n, "l");
        inf.readSpace();
        
        int m = inf.readInt(0, n, "m");
        inf.readEoln(); 

        ensuref(1LL * k * l <= n, "Test %d violated K * L <= N (K=%d, L=%d, N=%d)", test, k, l, n);

        sum_n += n;

        for (int i = 0; i < n; i++) {
            inf.readInt(1, 100000000, "a_i");
            
            if (i < n - 1) {
                inf.readSpace();
            } else {
                inf.readEoln();
            }
        }
    }
    ensuref(sum_n <= 5000000LL, "Sum of N exceeded \"5,000,000\"! (Actual: %lld)", sum_n);

    inf.readEof();

    return 0;
}
