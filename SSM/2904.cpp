#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>
#define max 1000000
using namespace std;

vector<int> primesOfNum[101];
bool isPrime[max + 1];
vector<int> primes;
int maxsqr = sqrt(max);

void setPrime() { // 에라토스테네스의 체
	isPrime[1] = false;
	for (int i = 2; i <= max; i++) {
		isPrime[i] = true;
	}

	for (int i = 2; i <= max; i++) {
		if (isPrime[i] == true) {
			primes.push_back(i);
			for (int j = 2;; j++) {
				int mul = i * j;
				if (mul > max) break;
				else isPrime[mul] = false;
			}
		}
	}
}

void devideToPrime(int num, int idx) {
	int howMany = 0, prime, i;
	for (i = 0; (i < primes.size()) && (num != 0); i++) {
		howMany = 0;
		prime = primes[i];
		while (num % prime == 0) {
			num = num / prime;
			howMany++;
		}
		primesOfNum[idx].push_back(howMany);
	}
}

int main() {

	int n, num, cnt = 0, score = 1;

	// 체를 이용해 소수 분별 : prime 이라는 vector에 저장
	setPrime();

	//입력과 소수로 분해
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> num;
		devideToPrime(num, i);
	}

	//계산
	int needs, total, tmp;
	for (int i = 0; i < primes.size(); i++) { // 최대공약수 구하기 primesOfNum[0]에 저장
		total = 0;
		for (int j = 1; j <= n; j++) {
			total += primesOfNum[j][i];
		}
		tmp = total / n;
		primesOfNum[0].push_back(tmp);
		if (tmp != 0)
			score = score * (int)pow(primes[i], tmp);
		//cout << primes[i] << " : "<< tmp <<'\n';
	}

	for (int i = 0; i < primes.size(); i++) { // 필요 이동 수 구하기
		if (primesOfNum[0][i] != 0) {
			for (int j = 1; j <= n; j++) {
				needs = primesOfNum[0][i] - primesOfNum[j][i];
				//cout << primes[i] << " : " << needs << '\n';
				if (needs > 0) cnt += needs;
			}
		}
	}

	//출력

	cout << score << " " << cnt;
	return 0;
}