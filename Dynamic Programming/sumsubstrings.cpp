#include <iostream>
#include <vector>
#include <string>
using namespace std;

unsigned long long substrings(string n) { // 123
    long long dp[100001];
    dp[0] = stoi(n.substr(0, 1));
    if (n.size() < 2) return dp[n.size()];

    unsigned long long subsum = 0;
    for (int j = 1; j < n.size(); j++) {
        subsum = 0;
        for (int i = 1; i < j+1; i++) {
            subsum += stoll(n.substr(i, j -i +1));
        }
        dp[j - 1];
        stoll(n.substr(0, j + 1));
        dp[j] = dp[j - 1] + subsum + stoll(n.substr(0, j + 1));
    }
    return dp[n.size() - 1];
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        string n;
    	cin >> n;
    	cout << substrings(n) << endl;
    }

	return 0;
}