#include <bits/stdc++.h>
using namespace std;

int dist(string s1, string s2)
{
    int len1 = s1.length();
    int len2 = s2.length();
    int dp[len1+1][len2+1];
    for(int i=0;i<=len2;i++)
    {
        dp[0][i] = i;
    }
    for(int j=0;j<=len1;j++)
    {
        dp[j][0] = j;
    }
    for(int i=1;i<=len1;i++)
    {
        for(int j=1;j<=len2;j++)
        {
            if(s1[i-1] == s2[j-1])
            {
                dp[i][j] = dp[i-1][j-1];
            }
            else
            {
                dp[i][j] = min(dp[i-1][j], min(dp[i][j-1], dp[i-1][j-1])) + 1;
            }
        }
    }
    /*for(int i=0;i<=len1;i++)
    {
        for(int j=0;j<=len2;j++)
        {
            cout << dp[i][j]  << " ";
        }
        cout << endl;
    }*/
    return dp[len1][len2];
}


int main() {
	int t;
	cin >> t;
	while(t--)
	{
	    string s1, s2;
	    cin >> s1 >> s2;
	    cout << "Minimum changes required are ";
	    cout << dist(s1,s2) << endl;
	}
	return 0;
}