#include <iostream>
#include <vector>

#include <boost/multiprecision/cpp_int.hpp> // Use Boost Library to store big ints
using boost::multiprecision::cpp_int; 
using namespace std;

cpp_int catalan(int n) {
    vector<cpp_int> dp(1000, 0);
    dp[0] = 1;
	dp[1] = 1;
	if (n == 0 || n == 1) return 1;
	cpp_int sum = 0;
	for (int j = 2; j <= n; j++) {
		sum = 0;
		for (int i = 0; i < j; i++) {
			sum += dp[i] * dp[j - i - 1];
		}
		dp[j] = sum;
	}

	return dp[n];
}
int main() {
	
	int t;
	cin >> t;
	int n;
	for (int i = 0; i < t; i++) {
		cin >> n;
		cout << catalan(n) << endl;
	}
	return 0;
}