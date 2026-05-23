#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF INT_MAX

void solve() {
    int N, K, L, M;
    cin >> N >> K >> L >> M;

    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int low = 1;
    int high = 1e8;
    int ans;

    vector<vector<int>> best_dp(N + 1, vector<int>(K + 1, INF));
    vector<int> best_cost(N+1);

    while (low <= high) {
        int mid = low + (high - low) / 2;

        vector<int> b(N);

        for (int i = 0; i < N; i++) {
            if (A[i] >= mid)
                b[i] = +1;
            else
                b[i] = -1;

            if (i != 0)
                b[i] = b[i - 1] + b[i];
        }

        vector<int> cost(N + 1);

        for (int i = L - 1; i < N; i++) {
            int sum;

            if (i != L - 1)
                sum = b[i] - b[i - L];
            else
                sum = b[i];

            if (L % 2 == 0) {
                if (sum <= 0)
                    cost[i + 1] = (2 - sum) / 2;
                else
                    cost[i + 1] = 0;
            } 
            else {
                if (sum < 0)
                    cost[i + 1] = (1 - sum) / 2;
                else
                    cost[i + 1] = 0;
            }
        }

        vector<vector<int>> dp(N+1,vector<int>(K+1,INF));

        for (int i = 0; i <= N; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= N; i++) {
            for (int j = 1; j <= K; j++) {
                dp[i][j] = dp[i - 1][j];

                if (i >= L && dp[i - L][j - 1] != INF) {
                    dp[i][j] = min( dp[i][j] ,
                        dp[i - L][j - 1] + cost[i]);
                }
            }
        }

        if (dp[N][K] <= M) {
            low = mid + 1;
            ans = mid;
            best_dp=dp;
            best_cost=cost;
        } 
        else {
            high = mid - 1;
        }
    }

    int curr_i=N;
    int curr_k=K;
    vector<int> schedule;
    while(curr_i>=L && curr_k>0)
    {
        if(best_dp[curr_i-L][curr_k-1]+best_cost[curr_i]==best_dp[curr_i][curr_k])
        {
            schedule.push_back(curr_i-L+1);
            curr_i-=L;
            curr_k--;
        }
        else
        {
            curr_i--;
        }
    }
    reverse(schedule.begin(),schedule.end());
    for(int x:schedule)
    cout<<x<<" ";
    cout<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t--) {
        solve();
    }

    return 0;
}