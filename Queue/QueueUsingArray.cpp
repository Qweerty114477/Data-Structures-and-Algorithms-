#include<bits/stdc++.h>
using namespace std;
class Queue{
    private:
    int size1=10;
    int arr[10];
    int cursize=0;
    int start,end;
    public:
    Queue(){
        start=-1;
        end=-1;
    }
    void push(int x){
        if(cursize==size1){
            cout<<"Queue Overflow"<<endl;
            return;
        }
        if(cursize==0){
            start=0,end=0;
        }
        else {
            end=(end+1)%size1;
        }
        arr[end]=x;
        cursize++;
    }
    int pop (){
        if(cursize==0){
            cout<<"Queue underflow"<<endl;
            return-1;
        }
        int ele=arr[start];
        if(cursize==1){
            start=-1,end=-1;

        }
        else {
            start=(start+1)%size1;
        }
        cursize--;
        return ele;
    }
    int top(){
        if(cursize==0){
            cout<<"Queue is empty"<<endl;
            return-1;
        }
        return arr[start];
    }
    int size(){
        return cursize;
    }
    void display(){
        if(cursize==0){
            cout<<"Queue is empty"<<endl;
            return;
        }
        int count = 0;
            int i = start;
            while(count < cursize) {
                cout << arr[i] << " ";
                i = (i + 1) % size1;
                count++;
            }
            cout << endl;
    }
    bool empty(){
        return cursize==0;
    }
};
int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.display(); // Output: 10 20 30
    
    q.pop();
    q.display(); // Output: 20 30
    return 0;
}