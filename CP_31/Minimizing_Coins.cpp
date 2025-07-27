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

vector<vector<int>> dp;

int solve(vector<int> &arr, int i, int sum){
    if(i == arr.size()){
        if(sum == 0) return 0;
        return 1e9;
    }
    if(dp[i][sum]!=-1) return dp[i][sum];
    int nottake = solve(arr, i + 1, sum);
    int take = 1e9;
    if(sum >= arr[i]){
        take = 1 + solve(arr, i, sum - arr[i]);
    }
    return dp[i][sum] = min(take, nottake);
}

int main(){
    int n, req;
    cin>>n>>req;
    vector<int> arr;
    for(int i = 0;i<n;i++){
        int val;
        cin>>val;
        arr.push_back(val);
    }
    sort(arr.begin(), arr.end());
    dp = vector<vector<int>>(n + 1, vector<int>(req + 1, -1));
    int val = solve(arr, 0, req);
    if(val == 1e9){
        cout<<-1;
    } else {
        cout<<val;
    }
}