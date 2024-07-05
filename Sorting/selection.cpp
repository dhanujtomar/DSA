#include<iostream>


using namespace std;

int main(){
    int arr[] = {13,46,24,52,20,9};

    int n = sizeof(arr)/sizeof(arr[0]);

    for(int i=0; i<n-1; i++){
        int minIndex = i;

        for(int j=i+1; j<n; j++){       // dont check the i index for min value see only the next set of values
            if(arr[minIndex]>arr[j]){
                minIndex = j;
            }
        }
        swap(arr[i],arr[minIndex]);
    }

    for(int i:arr){
        cout << i << " ";
    }
}