#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <queue>
#include <stack>
#include <climits>
#include <cstring>

using namespace std;

// int solve(vector<int> &arr, int i, int sum)
// {
//     if (i >= arr.size())
//     {
//         if (sum == 0)
//             return 1;
//         return 0;
//     }
//     if (sum == 0)
//     {
//         return 1;
//     }
//     int nottake = solve(arr, i + 1, sum);
//     int take = 0;
//     if (sum >= arr[i])
//     {
//         take = solve(arr, i, sum - arr[i]);
//     }
//     return take + nottake;
// }

int main()
{
    int n;
    cin >> n;
    int mod = pow(10, 9) + 7;
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        for (int dice = 1; dice <= 6; dice++)
        {
            if(i - dice >= 0){
                dp[i] = (dp[i] + dp[i - dice] )% mod;
            }
        }
    }
    cout << dp[n];
}