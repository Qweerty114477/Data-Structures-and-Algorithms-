#include<bits/stdc++.h>
using namespace std;
class Heap{
    public:
    int arr[100];
    int size;
    Heap(){
        arr[0]=-1;
        size=0;
    }
    void insert(int val){
        size++;
        int idx=size;
        arr[idx]=val;
        while(idx>1){
            int parent=idx/2;
            if(arr[idx]>arr[parent]){
                swap(arr[idx],arr[parent]);
                idx=parent;
            }
            else {
                return;
            }
        }
    }
    void deletefromHeap(){
        if(size==0){
            cout<<"Invalid Transaction!!"<<endl;
            return;
        }
        arr[1]=arr[size];
        size--;
        int idx=1;
        while(true){
            int left=2*idx;
            int right=2*idx+1;
            int largest=idx;
            if(left<=size&&arr[left]>arr[largest]){
                largest=left;
            }
            if(right<=size&&arr[right]>arr[largest]){
                largest=right;
            }
            if(largest==idx){
                return;
            }
            swap(arr[idx],arr[largest]);
            idx=largest;
            
        }
    }
    void print (){
        for(int i=1;i<=size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }
    void heapify(vector<int>&arr,int i,int n){
        int largest=i;
        int left=2*i;
        int right=2*i+1;
        if(left<=n&&arr[largest]<arr[left]){
            largest=left;
        }
        if(right<=n&&arr[largest]<arr[right]){
            largest=right;
        }
        if(largest!=i){
            swap(arr[largest],arr[i]);
            heapify(arr,largest,n);
        }
    }
};
int main(){
    Heap h;
    h.insert(34);
    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);
    h.print();
    h.deletefromHeap();
    h.print();
    vector<int>arr={-1,54,53,55,52,50};
    int n=5;
    for(int i=n/2;i>0;i--){
        h.heapify(arr,i,n);
    }
    cout<<"The max heap arry is: "<<endl;
    for(int i=1;i<=5;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    return 0;
}