#include <limits.h> // min value
#include <iostream>

using namespace std;

int counter,maxRev = INT_MIN,rodlenUsed;
int cutRod(int *prices, int *rods, int size){
	int *values = new int[size + 1], *lastSize = new int[size + 1];
	if(size == 0)
		return 0;
    for (int i = 1; i <= size; i++){
		for (int j = 0; j < i; j++){
			if(maxRev < prices[j] + values[i-j-1]){
				maxRev = max(maxRev, prices[j] + values[i-j-1]);
				rodlenUsed = j + 1;
			}
		}
        values[i] = maxRev;
        lastSize[i] = rodlenUsed;
    }
    for (int i = size; i > 0; i -= lastSize[i])
        rods[counter++] = lastSize[i];
	delete[] values;
	delete[] lastSize;
    return maxRev;
}
int main(){
    int size;
	cin >> size;
	int	*prices = new int[size], *rods = new int[size];
	for(int i = 0; i < size; i++)
		cin >> prices[i];
    cout << cutRod(prices, rods, size) << "\n";
    for(int j = 0; j < counter; j++)
        cout << rods[j] << " ";
	cout << "-1" << "\n";
	delete[] rods;
	delete[] prices;
    return 0;
}