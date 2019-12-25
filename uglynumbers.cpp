#include<bits/stdc++.h>
using namespace std;

int uglynum(int n)
{
    int dp[n];
    dp[0] = 1;
    int next2,next3,next5=0;
    int nextnum2 = dp[next2] * 2;
    int nextnum3 = dp[next3] * 3;
    int nextnum5 = dp[next5] * 5;
    for(int i=1;i<n;i++)
    {
        dp[i] = min(nextnum2, min(nextnum3,nextnum5));
        if(dp[i] == nextnum2)
        {
            next2 += 1;
            nextnum2 = dp[next2] * 2;
        }
        if(dp[i] == nextnum3)
        {
            next3 += 1;
            nextnum3 = dp[next3] * 3;
        }
        if(dp[i] == nextnum5)
        {
            next5 += 1;
            nextnum5 = dp[next5] * 5;
        }
    }
    return dp[n-1];
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout << uglynum(n) << endl;
    }
    return 0;
}