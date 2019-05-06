#include <Iostream>
using namespace std;
void isPrime(int n) {
	int i, flag = 0;
	for (i = 2; i <= n / 2; ++i) {
		if (n % i == 0) {
			flag = 1;
			break;
		}
	}
	if (flag == 0 && n!= 1 && n!=0)
		cout << n << " is a prime number" << endl;
	else
		cout << n << " is not a prime number" << endl;
}
int main() {
	int a = 0;
	while (a <= 10000)
	{
		int x = 0;
		std::cin >> x;
		isPrime(x);
		return 0;
		

	}
	

}
	
	
