#include <iostream>
#include <vector>
using namespace std;
vector<long long int> fibo(91);

long long int count_fibo(int n) {
	if (n == 0) return 0;
	else if (n == 1) return 1;
	else if (fibo[n]) return fibo[n];
	else {
		fibo[n] = count_fibo(n - 1) + count_fibo(n - 2);
		return fibo[n];
	}
}

int main()
{
	fibo[0] = 0;
	fibo[1] = 1;

	int n;
	cin >> n;

	cout << count_fibo(n);

	return 0;
}
