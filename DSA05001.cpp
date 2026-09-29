#include <bits/stdc++.h>
using namespace std;
int main()
{

    string s1, s2;
    cin >> s1 >> s2;
    int dp[s1.size()][s2.size()];
    int s1_length = s1.size();
    int s2_length = s2.size();

    int best = 0;
    for (int i = 0; i < s2_length; i++)
    {
        dp[0][i] = 0;
    }
    for (int i = 0; i < s1_length; i++)
    {
        dp[1][i] = {0};
    }
    for (int i = 0; i < s1_length; i++)
    {

        for (int j = 0; j < s2_length; j++)
        {

            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
            {

                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout << dp[s1_length][s2_length]<<endl;
}