#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	string a;
	bool isAnswer = true;

	cin >> a;

	int n = a.length();

	vector<int> dp(n + 1, 0);
	vector<int> s(n + 1, 0);

	s[0] = 0;
	for (int i = 0; i < n; i++) {
		s[i + 1] = a[i] - '0';
	}
	
	dp[0] = 1;

	for (int i = 1; i <= n; i++) {
		// �ѹ��ڸ� �������� �� ���� �ڸ��� 0�� �ƴ϶��, ���� ���� �Ȱ���.
		if (s[i] != 0) {
			dp[i] = dp[i - 1] % 1000000;
		}

		// �չ��ڸ� �����ؼ� ���ڸ� ������� ��
		int x = s[i] + s[i - 1] * 10;

		// 10~26���̶��  dp[i-2] + dp[i]�� ���ش�.
		if (10 <= x && x <= 26) {
			dp[i] = (dp[i] + dp[i - 2]) % 1000000;
		}
	}

	cout << dp[n] % 1000000;


	return 0;

}