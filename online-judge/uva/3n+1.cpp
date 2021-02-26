#include <bits/stdc++.h>

using namespace std;

int numberPrinted(int n) {
    int count = 0;
    while (n != 1) {
        count++;
        if (n & 1) n = 3 * n + 1;
        else n /= 2;
    }
    return count;
}

int main() {

    int i, j, maxLength, value, start,end;
    while (cin >> i >> j) {
        start = i;
        end = j;
        maxLength = 0;
        if( j < i) swap(i,j);
        while (i <= j) {
            value = numberPrinted(i);
            if (value > maxLength) {
                maxLength = value;
            }
            i++;
        }

        cout << start << " " << end << " " << maxLength + 1 << endl;
    }
    return 0;
}