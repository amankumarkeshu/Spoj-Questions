#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct node{
	int val;
	node* next;
	node* prev;

	node()
	{
		next = NULL;
		prev = NULL;
	}

	node(int n){
		val = n;
		next = NULL;
		prev = NULL;
	}
};

struct adalist
{
	int isReverse;

	node* start;
	node* end;

	adalist(){
		isReverse = false;
		start = NULL;
		end = NULL;
	}

	void _push_front(int n){
		if(end == NULL || start == NULL){
			start = new node(n);
			end = start;
		}else{
			node* temp = new node(n);
			start->prev = temp;
			temp->next = start;
			start = temp;
		}
	}

	void _push_back(int n){
		if(end == NULL || start == NULL){
			start = new node(n);
			end = start;
		}else{
			node* temp = new node(n);
			end->next = temp;
			temp->prev = end;
			end = temp;
		}
	}

	int _back(){
		if(end == NULL)
			return -1;
		int val = end->val;
		end = end->prev;

		if(end == NULL)
			start = NULL;
		else
			end->next = NULL;

		return val;
	}

	int _front(){
		if(start == NULL)
			return -1;
		int val = start->val;
		start = start->next;

		if(start == NULL)
			end = NULL;
		else
			start->prev = NULL;

		return val;
	}


	void toFront(int n){
		if(isReverse)
			_push_back(n);
		else
			_push_front(n);
	}

	void push_back(int n){
		if(!isReverse)
			_push_back(n);
		else
			_push_front(n);
	}

	void reverse(){
		isReverse = !isReverse;
	}

	int front(){
		if(isReverse)
			return _back();
		else
			return _front();
	}

	int back(){
		if(!isReverse)
			return _back();
		else
			return _front();
	}

	int print(){
		node* temp = start;
		while(temp!=NULL){
			cout<<temp->val<<" ";
			temp= temp->next;
		}
		cout<<" $$$$ "<<isReverse<<endl;

	}

};

int main()
{	
	int n;
	cin>>n;

	string s;
	adalist list;
	int k;
	while(n--){
		cin>>s;
		//cout<<s<<"  * \n";
		
			if(s=="back")
			{
				k=list.back();
				if(k>=0)
					cout<<k<<endl;
				else
					cout<<"No job for Ada?\n";
			}
			else if( s == "front" ){
				k=list.front();
				if(k>=0)
					cout<<k<<endl;
				else
					cout<<"No job for Ada?\n";
			}
			else if( s == "reverse" ){
				list.reverse();
			}
			else if( s == "toFront" ){
				cin>>k;
				//cout<<k<<" * \n";
				list.toFront(k);
			}
			else if( s == "push_back" ){
				cin>>k;
				//cout<<k<<" * \n";
				list.push_back(k);
			}

			//list.print();
	}
	return 0;
}