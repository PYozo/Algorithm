#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> mul(vector<vector<int>> a, vector<vector<int>> b,int m)
{
	vector<vector<int>> ans(2, vector<int>(2, 0));
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < 2; k++) {
				ans[i][j] = (ans[i][j]+a[i][k] * b[k][j]) % m;
			}
		}
	}
	return ans;
}
//Using matrix to find fibolacci
void Fibonacci(int n,int m)
{
	vector<vector<int>> res(2, vector<int>(2));
	vector<vector<int>> a(2, vector<int>(2));
	a[0][0] = 1;
	a[0][1] = 1;
	a[1][0] = 1;
	a[1][1] = 0;
	res[0][0] = 1;
	res[0][1] = 0;
	res[1][0] = 0;
	res[1][1] = 1;
	while (n) {
		//Using fast exponentiation
		if(n&1) res = mul(res, a,m);
		a = mul(a, a,m);
		n = n / 2;
	}
	cout << res[0][1];
}

int main()
{
	int n, m;
	cin >> n >> m;
	Fibonacci(n, m);
}
