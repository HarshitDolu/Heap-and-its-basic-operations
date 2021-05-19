#include<bits/stdc++.h>
using namespace std;

class heap{
	public:
	
	int *arr;
	int size;
	
// constructor

	heap(int n){
	
		size=n;
		arr=new int[n];
		
		// input array
		cout<<"input array"<<endl;
		
		for(int i=0;i<n;i++)
		cin>>arr[i];
		
	}
	
/* utility functions */
	
// leftchild

	int leftchild(int i,int n){
		
		int lc=2*i+1;
		if(lc>=n)
			return -1;
			
			return arr[lc];
	}
	
// right child

	int rightchild(int i,int n){
		
		int rc=2*i+2;
		if(rc>=n)
			return -1;
			
			return arr[rc];
	}
	
// parent
	
	int parent(int i){
		int p=(i-1)/2;
		
		return p;
	}
	
	/* utility function ends */
	
	
// insertion in heap

void insert(int val){
		
		size=size+1;
		arr[size-1]=val;
		
		for(int i=size-1;i!=0 && arr[parent(i)]>arr[i];){
			swap(arr[i],arr[parent(i)]);
			i=parent(i);
	}
		
		
		for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";
	}
	
/* min heapify */
	
void min_heapify(int i,int n){
		
		int smallest=i;
		int lc=2*i+1;
		int rc=2*i+2;
		
		if(lc<n && arr[smallest]>arr[lc])
		smallest=lc;
		
		if(rc<n && arr[smallest]>arr[rc])
		smallest=rc;
		
		if(i!=smallest){
			swap(arr[i],arr[smallest]);
			min_heapify(smallest,n);
		}
		
	}

/* build heap */
	
void build_heap(){
		int n=size;
		
		for(int i=n/2-1;i>=0;i--){
			
			min_heapify(i,n);
		}
		
		// min heap
		cout<<"Min heap"<<endl;
		for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";
		cout<<endl;
		
	}
/* extract min */
	
void extract_min(){
		
		swap(arr[0],arr[size-1]);
		size=size-1;
		
		min_heapify(0,size);
		
		// heap_after extract_min
		cout<<"Extract min"<<endl;
		for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";
		cout<<endl;
	}
	
	
	
/* Decrease key */

void decrease_key(int index,int value){
	arr[index]=value;
	
	for(int i=index;i!=0 && arr[parent(i)]>arr[i];){
		
		swap(arr[i],arr[parent(i)]);
		i=parent(i);
		
	}
	// heap_after decrease key
	cout<<"Decrease Key"<<endl;
		for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";
		cout<<endl;
	
	
}

/* delete in heap */

void delete_heap(int index){
	
	decrease_key(index,INT_MIN);
	extract_min();
	
	// heap_after delete key
		cout<<"Delete Key"<<endl;
		for(int i=0;i<size;i++)
		cout<<arr[i]<<" ";
		cout<<endl;
	
}

	
};




int main(){
	
	heap h1(5);
	h1.build_heap();
	cout<<endl;
	
	h1.extract_min();
	cout<<endl;
	
	h1.decrease_key(3,1);
	cout<<endl;
	
	
	h1.delete_heap(3);

	
	
	return 0;
	
}
