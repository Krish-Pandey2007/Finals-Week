#include "testlib.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void gen_testcase(int n, int k, int l, int m, int current_max_a, const string& type) {
    vector<int> a(n);
    
    if (type == "uniform") {
        int val = rnd.next(1, current_max_a);
        for (int i = 0; i < n; i++) a[i] = val;
    } 
    else if (type == "binary") {
        int v1 = rnd.next(1, current_max_a);
        int v2 = rnd.next(1, current_max_a);
        for (int i = 0; i < n; i++) a[i] = rnd.next(0, 1) ? v1 : v2;
    } 
    else {
        for (int i = 0; i < n; i++) {
            a[i] = rnd.next(1, current_max_a);
        }
        
        if (type == "sorted") {
            sort(a.begin(), a.end());
        } 
        else if (type == "reverse") {
            sort(a.rbegin(), a.rend());
        } 
        else if (type == "mountain") {
            sort(a.begin(), a.end());
            vector<int> mnt;
            for(int i = 0; i < n; i += 2) mnt.push_back(a[i]);
            for(int i = (n % 2 == 0 ? n - 1 : n - 2); i >= 0; i -= 2) mnt.push_back(a[i]);
            a = mnt;
        }
    }

    cout << n << " " << k << " " << l << " " << m << "\n";
    for (int i = 0; i < n; i++) {
        cout << a[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
}

int main(int argc, char* argv[]) {
    registerGen(argc, argv, 1);

    int t = opt<int>("t", 1);
    string mode = opt<string>("mode", "exact"); 
    string type = opt<string>("type", "random");
    
    int max_n = opt<int>("n");
    int max_k = opt<int>("k");
    int max_l = opt<int>("l");
    int max_m = opt<int>("m");
    int global_max_a = opt<int>("max_a", 100000000); 

    cout << t << "\n";
    long long sum_nk = 0;

    for (int i = 0; i < t; i++) {
        int n = max_n;
        int k = max_k;
        int l = max_l;
        int m = max_m;
        int current_max_a = global_max_a;
        
        if (mode == "random") {
            n = rnd.next(1, max_n);
            k = rnd.next(1, max_k);
            
            int upper_l = n / k;
            if (upper_l < 1) { 
                k = 1;
                l = rnd.next(1, n);
            } else {
                l = rnd.next(1, min(max_l, upper_l));
            }
            m = rnd.next(0, min(max_m, n));

            if(global_max_a==100000000)
            {
            int roll = rnd.next(1, 100);
            if (roll <= 40) {
                current_max_a = rnd.next(2, 5); 
            } else if (roll <= 70) {
                current_max_a = rnd.next(10, 100);
            } else {
                current_max_a = global_max_a;
            }
            }
        }

        sum_nk += 1LL * n * k;
        ensuref(sum_nk <= 1000000LL, "Fatal: Sum of N*K exceeded 10^6 threshold!");
        ensuref(1LL * k * l <= n, "Fatal: K * L (%lld) exceeds N (%d)", 1LL * k * l, n);

        gen_testcase(n, k, l, m, current_max_a, type);
    }
    
    return 0;
}