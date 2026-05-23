#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define INF INT_MAX

int N, K, L, M;
vector<int> B;
vector<int> B_medians;
vector<int> bestStart;
int bestShots;
int bestEfficiency;

bool betterLex(vector<int> a, vector<int> b) {

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());

    return a > b;
}


bool betterSchedule(vector<int>& a,vector<int>& b,int a_efficiency,int b_efficiency,int a_shots,int b_shots)
{
    if(a_efficiency!=b_efficiency) return a_efficiency>b_efficiency;
    else if(a_shots!=b_shots) return a_shots<b_shots;
    else return betterLex(a,b);
} //returns 1 if a is a better schedule than b


void dfs(int idx,int taken,vector<int>& starts,int shots,int efficiency)
{
    if(taken==K)
    {
        if(bestStart.size()==0 || betterSchedule(starts,bestStart,efficiency,bestEfficiency,shots,bestShots))
        {
            bestStart=starts;
            bestEfficiency=efficiency;
            bestShots=shots;
        }
        return;
    }

    if(idx+1<N)
    dfs(idx+1,taken,starts,shots,efficiency);

    if(idx+L-1<N)
    {
        starts.push_back(idx);
        int newEfficiency=min(efficiency,B_medians[idx]);
        dfs(idx+L,taken+1,starts,shots,newEfficiency);
        starts.pop_back();
    }
}

void solve() {
    cin >> N >> K >> L >> M;
    bestShots=0;
    bestEfficiency=0;
    bestStart.clear();

    vector<int> A(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }

    for(int mask=0;mask<(1<<N);mask++)
    {
        int shots=__builtin_popcount(mask);
        if(shots>M)
        continue;

        B=A;
        B_medians.clear();
        B_medians.resize(N);

        for(int i=0;i<N;i++)
        {
            if(mask & (1<<i))
            B[i]=1e9;
        }

        for(int i=0;i+L-1<N;i++)
        {
           vector<int> v;
           for(int j=0;j<L;j++)
           v.push_back(B[i+j]);

           sort(v.begin(),v.end());
           B_medians[i]=v[(L+1)/2-1];
        }

        vector<int> starts;
        dfs(0,0,starts,shots,INT_MAX);
    }
    for(int x:bestStart)
    cout<<x+1<<" ";
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