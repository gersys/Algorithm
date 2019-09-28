#include <iostream>

using namespace std;

#define MAX 1000;

int recurrsion(int start, int end, int count, int data[1000], int K) {
	int sum=data[start] +data[end];
	if (start >= end)
		return count;
	else {
		if (sum > K) {
			end--;
			recurrsion(start, end, count, data, K);
		}
		else if (sum < K) {
			start++;
			recurrsion(start, end, count, data, K);
		}
		else {
			count++;
			start++;
			end--;
			recurrsion(start, end, count, data, K);
		}
	}

}

int main() {
	int data[1000];
	int N, K;
	int i = 0;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> data[i];
		cout << data[i] << " ";
	}
	cout << endl;
	
	cin >> K;

	int start = 0, end = N - 1;
	int count = 0;

	count = recurrsion(start, end, count, data, K);


	cout << "count:" << count << endl;

	//
//
//while (start < end) {
//	int sum = data[start] + data[end];
//	if (sum > k)
//		end--;
//	else if (sum < k)
//		start++;
//	else {
//		count++;
//		start++;
//		end--;
//	}
//}




}
