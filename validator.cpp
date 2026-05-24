#include "testlib.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    registerValidation(argc, argv);

    int t = inf.readInt(1, 10'000, "T");
    inf.readEoln();

    long long sum_nk = 0;

    for (int test = 1; test <= t; test++) {
        int n = inf.readInt(1, 100'000, "N");
        inf.readSpace();
        int k = inf.readInt(1, 100, "K");
        inf.readSpace();
        int l = inf.readInt(1, n, "L");
        inf.readSpace();
        int m = inf.readInt(0, n, "M"); 
        inf.readEoln();

        ensuref(1LL * k * l <= n, 
                "Test %d: K*L (%d) exceeds N (%d). M was %d", 
                test, (int)(k * l), n, m);

        sum_nk += 1LL * n * k;

        for (int i = 0; i < n; i++) {
            inf.readInt(1, 100'000'000, "A_i");
            if (i < n - 1) inf.readSpace();
            else inf.readEoln();
        }
    }

    ensuref(sum_nk <= 1'000'000LL, "Global sum of N*K (%d) exceeds 1'000'000", (int)sum_nk);
    inf.readEof();

    return 0;
}