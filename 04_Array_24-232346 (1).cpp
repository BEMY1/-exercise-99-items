#include<iostream>
#include<algorithm>

using namespace std;
int main() {
    //Input 
    int r; cin >> r;
    int n[50], N[50];
    for (int i = 0; i < r; i++) {
        cin >> n[i];
        N[i] = n[i];
    }
    //##############################################
    //Output first line 
    for (int i = 0; i < r; i++) {
        cout << n[i];
        if (i != r - 1) { cout << " "; }
    }
    cout << endl;
    //##############################################
    // check if it order already by checked with N[i] (sorted Array)
    sort(N, N + r);
    for (int i = r - 1; i >= 0; i--) {
        int Max = 0, pos = 0, count = 0;
        for (int j = 0; j < r; j++) {
            if (N[j] == n[j]) {
                count++;
            }
        }
        if (count == r) { // that mean every array was sorted already, so that's not anything to do anymore.
            break;
        }
    //##############################################
    // if max neither base nor top
        for (int j = 0; j <= i; j++) {
            if (n[j] > Max) {
                Max = max(Max, n[j]);
                pos = j;
            }
        }
        if (pos != 0 && pos != i) {
            for (int j = 0; j < pos; j++) {
                swap(n[j], n[pos]);
                pos--;
            }
            for (int j = 0; j < r; j++) {
                cout << n[j];
                if (j != r - 1) { cout << " "; }
            }
            cout << endl;
        }
    //##############################################
    //if max is top 
        Max = 0;
        for (int j = 0; j <= i; j++) {
            if (n[j] > Max) {
                Max = max(Max, n[j]);
                pos = j;
            }
        }
        if (pos == 0) {
            for (int j = i; pos < j; j--) {
                swap(n[pos], n[j]);
                pos++;
            }
            for (int j = 0; j < r; j++) {
                cout << n[j];
                if (j != r - 1) { cout << " "; }
            }
            cout << endl;
        }
    //##############################################
    // if max is base, no need to do anything.
    }
}