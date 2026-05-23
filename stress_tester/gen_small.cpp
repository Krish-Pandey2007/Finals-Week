#include <bits/stdc++.h>
using namespace std;
#include "testlib.h"

#define endl '\n'

int main(int argc,char* argv[])
{
    registerGen(argc, argv, 1);
    int T=1;
    cout<<T<<endl;

    int N=rnd.next(1,12);
    int K,L,M;
    if(rnd.next(0,1))
    {
        K=rnd.next(1,N);
        L=rnd.next(1,N/K);
    }
    else
    {
        L=rnd.next(1,N);
        K=rnd.next(1,N/L);
    }
    M=rnd.next(0,N);
    cout << N << " " << K << " " << L << " " << M << endl;

    int max_A = 20;
    for(int i=0;i<N-1;i++)
    {
        cout<<rnd.next(1,max_A)<<" ";
    }
    cout<<rnd.next(1,max_A)<<endl;
}


