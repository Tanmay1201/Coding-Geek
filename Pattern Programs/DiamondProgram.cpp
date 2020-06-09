#include <bits/stdc++.h>
using namespace std;

int main() {
	
	int n;
	cin >> n;
	
	for(int i=0;i<=n/2;i++){
	    int leftTemp = n/2-i;
	    int rightTemp = n/2+i;
	    if(i!=n/2){
	    for(int j=0;j<n;j++){
	        if(j==leftTemp || j==rightTemp || j==n/2){
	            cout << "*";
	        }
	        else{
	            cout << " ";
	        }
	    }
	    cout << endl;
	    }
	    else{
	        for(int j=0;j<n;j++){
	            cout << "*"; 
	            
	        }
	        cout << endl;
	    }
	    
	}
	for(int i=n/2+1;i<n;i++){
	    int diff = i-n/2;
	    int rightTemp = n-1-diff;
	    for(int j=0;j<n;j++){
	        if(j==diff || j==n/2 || j==rightTemp){
	            cout << "*";
	        }
	        else{
	            cout << " ";
	        }
	    }
	    cout << endl;
	}
	return 0;
}
