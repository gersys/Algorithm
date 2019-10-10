#include <iostream>
#include <ctime>

using namespace std;

#define N1 1000
#define N2 10000
#define N3 100000

void show_arr(int* arr, int N);
void bubble(int* arr, int N);
void selection(int* arr, int N);

int main() {

	// create rand int variable
	srand((unsigned int)time(0));
	cout << rand() << endl;

	int rand_N1 = rand() % N1;
	int rand_N2 = rand() % N2;
	int rand_N3 = rand() % N3;

	cout << rand_N1 << endl;
	cout << rand_N2 << endl;
	cout << rand_N3 << endl;

	//create array to save rand variables

	int arr1[N1];
	int arr2[N2];
	int arr3[N3];

	for (int i = 0; i < N1; i++) 
		arr1[i] = rand() % N1;
	
	for (int i = 0; i < N1; i++)
		arr2[i] = rand() % N2;
	
	for (int i = 0; i < N1; i++)
		arr3[i] = rand() % N3;

	// examine if array1 is well created

	show_arr(arr1, N1);
	
	
	// do sort Algorithm

	//bubble(arr1, N1);
	selection(arr1, N1);

	//examine arr1 is well sorted

	show_arr(arr1, N1);


}

void show_arr(int* arr, int N) {
	for (int i = 0; i < N; i++)
		cout << arr[i] << " ";

	cout << endl;
	cout << "--------------------------------------------------------" << endl;

}

void bubble(int* arr, int N) {
	for (int i = 0; i < N; i++) 
		for (int j = N - 1; j > i; j--) {
			if (arr[j] < arr[j - 1]) {
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
			//show_arr(arr, N);
		}
			
}

void selection(int* arr, int N) {
	for (int i = 0; i < N; i++) {
		int min = arr[N-1];
		int min_id = N - 1;
		for (int j = i; j < N; j++) {
			if (min > arr[j]) {
				min = arr[j];
				min_id = j;
			}
		}
		int temp = arr[min_id];
		arr[min_id] = arr[i];
		arr[i] = temp;
	}
}