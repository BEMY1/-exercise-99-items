#include <iostream>
#include <string>
#include <algorithm>
using namespace std;



int main(){
    int n ; cin >> n;
    int N[100];
    int number[100];
    for(int i=0 ; i<n ; i++){
        cin >> number[i];
        N[i] = number[i];
    }
    sort(N, N + n);
    int count = 0;
    for(int i=0 ; i<n ; i++){
        if(N[i] == number[i]) count++;
    }
    if(count == n) cout << "Sorted" <<endl;

    // 3 1 2 5 4
    // มี n=5 ตัว แต่ทำ n-1=4 รอบ
    for(int i=0 ; i<n-1 ; i++){


        //ไม่เรียง ไม่ base max และไม่ top max
        int max = 0, pos=0; 
            //หาตำแหน่ง max โดยตำแหน่งสุดท้ายของแต่ละรอบ = n-1 
        for(int j=0 ; j<n-1 ; j++){
            if(number[j] > max){
                max = number[j];
                pos = j; 
            } 
        }

        if( pos != 0 && pos != string::npos){
            for(int j=0 ; j<pos ; j++){
                swap(n[i], n[pos]);
                pos--;
            }
        }
        else break;
        max=0;
        for(int j=0 ; j<n-1 ; j++){
            if(number[j] > max){
                max = number[j];
                pos = j; 
            } 
        }

        if(pos == 0){
            for(int j=i ; pos<j ; j--){
                swap(n[pos],n[j]);
                pos++;
            }
        }
    }
   for(int i=0; i<n ; i++) {
    cout << number[i] <<endl;
   }
}