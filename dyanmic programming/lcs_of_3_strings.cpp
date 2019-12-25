#include<bits/stdc++.h>
using namespace std;

int lcs(string x, string y, string z, int a, int b, int c, int*** dp)
{
    if(a == 0 || b==0 || c==0)
    {
        return 0;
    }
    if(dp[a][b][c] > -1)
    {
        return dp[a][b][c];
    }
    int ans;
    if(x[a-1] == y[b-1] && y[b-1] ==  z[c-1])
    {
        ans = 1 + lcs(x,y,z,a-1,b-1,c-1,dp);
    }
    else
    {
        ans = max(lcs(x,y,z,a-1,b,c,dp), max(lcs(x,y,z,a,b-1,c,dp), lcs(x,y,z,a,b,c-1,dp)));
    }
    dp[a][b][c] = ans;
    return ans;
}

int main()
{
    string x,y,z;
    cin >> x >> y >> z;
    int a = x.length();
    int b = y.length();
    int c = z.length();
    int*** dp = new int**[a+1];
    for(int i=0;i<=a;i++)
    {
        dp[i] = new int*[b+1];
        for(int j=0;j<=b;j++)
        {
            dp[i][j] = new int[c+1];
            for(int k=0;k<=c;k++)
            {
                dp[i][j][k] = -1; 
            }
        }
    }
    cout << lcs(x,y,z,a,b,c,dp);
    return 0;
}