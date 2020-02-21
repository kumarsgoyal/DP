/*
    Given a set of non-negative integers, and a value sum, determine if there 
    is a subset of the given set with sum equal to given sum.
    
    Input:-
    4. -> Array Size
    1 5 11 5. ->Last element is Sum 
*/


#include <iostream>
using namespace std;

string cal_yes_not(int *arr, int size, int num) {
    bool **cal = new bool*[size+1];
    
    for(int i = 0; i < size+1; i++) {
        cal[i] = new bool[num+1];
    }
    
    cal[0][0] = true;
    for(int i =1; i < num+1; i++) {
        cal[0][i] = false;
    }
    
    for(int i = 1; i < size+1; i++) {
        for(int j = 0; j < num+1; j++) {
            if(j < arr[i-1]) {
                cal[i][j] = cal[i-1][j];
            }
            else {
                cal[i][j] = cal[i-1][j] || cal[i-1][j-arr[i-1]];
            }
        }
    }
    
    return cal[size][num] ? "YES" : "NO";
}

int main() {
	int t = 0;
	cin>>t;
	while(t--) {
	    int size = 0;
	    cin>>size;
	    int *arr = new int[size-1];
	    int num;
	    for(int i = 0; i < size-1; i++) {
	        cin>>arr[i];
	    }
	    cin>>num;
	    
	    cout<<cal_yes_not(arr, size-1, num)<<"\n";
	}
	return 0;
}
