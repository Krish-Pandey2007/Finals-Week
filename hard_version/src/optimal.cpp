#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF INT_MAX
#define ll long long

#define int ll


bool check(int N,int K,int L,int M,vector<int>& a,ll X)
{
    vector<int> b(N);
    vector<int> cost(N+1,0);
    for(int i=0;i<N;i++)
    {
        if(a[i]>=X)
        b[i]=+1;
        else
        b[i]=-1;

        if(i!=0)
        b[i]=b[i]+b[i-1];
    }
    for(int i=L-1;i<N;i++)
    {
        int sum;
        if(i!=L-1)
        sum=b[i]-b[i-L];
        else
        sum=b[i];

        if(L%2==0)
        cost[i+1]=max((int)0,(2-sum)/2);
        else
        cost[i+1]=max((int)0,(1-sum)/2);
    }

    ll low=0;
    ll high=1e9;
    ll best;
    ll best_lambda;
    while(low<=high)
    {
        ll mid=low+(high-low)/2;
        vector<ll> dp(N+1);
        vector<ll> cnt(N+1);
        dp[0]=0;
        for(int i=1;i<=N;i++)
        {
            dp[i]=dp[i-1];
            cnt[i]=cnt[i-1];
            if(i>=L)
            {
                if(dp[i-L]-mid+cost[i]<=dp[i-1])
                {
                    dp[i]=dp[i-L]-mid+cost[i];
                    cnt[i]=cnt[i-L]+1;
                }
            }
        }
        if(cnt[N]>=K)
        {
            high=mid-1;
            best_lambda=mid;
            best=dp[N]+1LL*K*best_lambda;
        }
        else
        low=mid+1;
    }
    return best<=M;
}

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

    while (low <= high) {
        int X = low + (high - low) / 2;
        bool cond=check(N,K,L,M,A,X);
        if(cond)
        {
            low=X+1;
            ans=X;
        }
        else high=X-1;
    }
    cout<<ans<<endl;
}

int32_t main() {
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
