#include <iostream>
using namespace std;

struct Array {
	int T;
	int P;
};
Array* arr;
int max_score = 0;
int n;

void calc(int cur, int score);

int main() {

	scanf("%d", &n);
	if (n < 1 || n>15) {
		cout << "Exception Occurred" << endl;
		return 0;
	}
	arr = (Array*)malloc(sizeof(Array) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i].T);
		scanf("%d", &arr[i].P);
	}

	calc(0, 0);
	
	cout << max_score;
	free(arr);
}

void calc(int cur, int score) {
	
	for (cur; cur <= n; cur++) {
		if (cur + arr[cur].T > n || cur >= n) {
			
			if (score > max_score) {
				max_score = score;
			}
			return;
		}
		else {
			calc(cur + arr[cur].T, score + arr[cur].P);
		}
	}
}



