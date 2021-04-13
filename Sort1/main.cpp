#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;
void quickSort(int* data, int const len);
int main() {
    int const len = 20;
    int arr[len];
    for (int i = 0; i < len; i++) {
        arr[i] = 1 + rand() % 10;
    }

    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    quickSort(arr, len);
    for (int i = 0; i < len; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    system("pause");
	return 0;
}

void quickSort(int* data, int const len)
{
    int pivot = 0;
    int const DL = len;
    int ind = DL / 2;
    int j = 0, k = 0;
    if (DL > 1) {
        int* L = new int[DL];
        int* R = new int[DL];
        pivot = data[ind];
        for (int i = 0; i < DL; i++) {
            if (i != ind) {
                if (data[i] < pivot) {
                    L[j] = data[i];
                    j++;
                }
                else {
                    R[k] = data[i];
                    k++;
                }
            }
        }
        quickSort(L, j);
        quickSort(R, k);
        for (int cnt = 0; cnt < DL; cnt++) {
            if (cnt < j) {
                data[cnt] = L[cnt];;
            }
            else if (cnt == j) {
                data[cnt] = pivot;
            }
            else {
                data[cnt] = R[cnt - (j + 1)];
            }
        }
    }
}