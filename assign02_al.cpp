#include <iostream>

using namespace std;

#define MAX 1000;

int main() {
	int data[1000];
	int N, K;
	int i = 0;

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> data[i];

	int start = 0, end = N - 1;
	int count = 0;

	while (start < end) {
		int sum = data[start] + data[end];
		if (sum > K)
			end--;
		else if (sum < K)
			start++;
		else {
			count++;
			start++;
			end--;
		}
	}

	cout << "count:" << count << endl;


}