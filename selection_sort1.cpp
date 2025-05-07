// Selection sort

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the total number of elements => ";
    cin>>n;
    
    vector<int> arr(n);
    
    cout<<"Enter "<<n<<" numbers:- \n";
    for(auto &i:arr){
        cin>>i;
    }
    
    for(int i=0;i<n-1;i++){
        int min = arr[i];
        int minPos = i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<min){
                min = arr[j];
                minPos = j;
            }
        }
        
        int temp = arr[i];
        arr[i] = arr[minPos];
        arr[minPos] = temp;
    }
    
    cout<<"------ Sorted Array is ------ \n";
    for(auto &i:arr){
        cout<<i<<" ";
    }
    
    return 0;
}