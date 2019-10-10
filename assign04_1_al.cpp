#include <iostream>
#include <ctime>

using namespace std;

#define N1 1000
#define N2 10000
#define N3 100000

void show_arr(int* arr, int N);
void bubble(int* arr, int N);
void selection(int* arr, int N);
void insertion(int* arr, int N);
void mergeSort(int* arr, int s, int N);
void merge(int* arr, int s, int m, int e);
void quickSort(int* arr, int s, int e);
int partition(int* arr, int s, int e);

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
	
	for (int i = 0; i < N2; i++)
		arr2[i] = rand() % N2;
	
	for (int i = 0; i < N3; i++)
		arr3[i] = rand() % N3;

	// examine if array1 is well created

	show_arr(arr1, N1);
	
	
	// do sort Algorithm

	//bubble(arr1, N1);
	//selection(arr1, N1);
	//insertion(arr1, N1);
	//mergeSort(arr1, 0, N1-1);
	quickSort(arr1, 0, N1 - 1);

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

void insertion(int* arr, int N) {
	for (int i = 1; i < N; i++) {
		int pivot = arr[i];
		for (int j = i-1; j >= 0; j--) {
			if (pivot < arr[j]) {
				arr[j + 1] = arr[j];
				arr[j] = pivot;
			}
			//cout << j << endl;
			//show_arr(arr, N);
		}
	}
}

void mergeSort(int* arr,int s ,int e) {

	if (s < e) {
		int m = (s + e) / 2;
		mergeSort(arr, s, m);
		mergeSort(arr, m + 1, e);
		merge(arr, s, m, e);
		
	}

}

void merge(int* arr, int s, int m, int e) {
	int i = s, j = m + 1, k = s;
	int* tmp = new int[e];

	//show_arr(arr, m);
	//show_arr(arr, e);
	//cout << "i :" << i << " j :" << j << " k :" << k << endl;

	while (i <= m && j <= e) {
		if (arr[i] <= arr[j])
			tmp[k++] = arr[i++];
		else
			tmp[k++] = arr[j++];
	}

	while (i <= m)
		tmp[k++] = arr[i++];
	while (j <= e)
		tmp[k++] = arr[j++];

	

	for (int i = s; i <= e; i++)
		arr[i] = tmp[i];
}

void quickSort(int* arr, int s, int e) {

	if (s < e) {
		int m=partition(arr, s, e);
		quickSort(arr, s, m-1);
		quickSort(arr, m + 1, e);
		

	}

}

int partition(int* arr, int s , int e) {
	int pivot = arr[e];
	int i = s - 1;
	for (int j = s; j < e; j++) 
		if (arr[j] < pivot) {
			i = i + 1;
			int temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	int temp = pivot;
	arr[e] = arr[i + 1];
	arr[i + 1] = temp;

	return i + 1;
}