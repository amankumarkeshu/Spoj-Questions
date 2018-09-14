#include<iostream>
#include<string>
#include<list>

using namespace std;

void print( list<int> l){
    for(list<int>::iterator it=l.begin(); it!=l.end() ; ++it)
            cout << " " << *it;
    cout<<endl;
}

void subset(int arr[], int size, int left, int index, list<int> &l){
    if(left==0){
        print(l);
        return;
    }
    for(int i=index; i<size;i++){
        l.push_back(arr[i]);
        subset(arr,size,left-1,i+1,l);
        l.pop_back();
    }

}

int main(){
    int array[5]={1,2,3,4,5};
    list<int> lt;
    subset(array,5,3,0,lt);


    return 0;
}
