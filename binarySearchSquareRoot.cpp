//https://www.codingninjas.com/studio/problems/square-root_893351?source=youtube&campaign=love_babbar_codestudio2&leftPanelTabValue=SUBMISSION


#include<iostream>
using namespace std;
long long int binarySearchSquareRoot(int n){
    int s =0;
    int e = n;
    long long int mid = s + (e-s)/2;

    long long int ans = -1;

    while(s<=e){
        long long int square = mid * mid;

        if(square == n){
            return mid;
        }

        if(square < n){
            ans = mid;
            s= mid + 1;
        }
        else{
            e= mid -1;
        }
        mid = s+(e-s)/2;
    }
    return ans;
}
int main(){
    cout<<binarySearchSquareRoot(99);

}