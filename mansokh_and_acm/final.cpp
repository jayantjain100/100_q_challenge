//https://codeforces.com/problemset/status

//just noticed that they have given more memory than needed, could have also strored the full 2d dp matrix
#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	long modulo = 1000000000 + 7;
	int i,j,l;
	long old[n+1]; // dp with using just one row at a time, saving memory
	long naya[n+1];
	// cout<<naya[2]<<endl;
	for(i=1;i<=n;i++){
		old[i]=1;
		naya[i]=1; //because if they give us the corner case with k=1, this will handle this , otherwise in the last loop
		// 0 ban jayega jabki 1 hoina chahiye tha
		//vaise 1<=n,k<=2000
	}
	//cout<<naya[2]<<endl;
	//first layer
	// cout<<"hi"<<endl;
	for(j=2;j<=k;j++){

		for(i=1;i<=n;i++){
			naya[i]= 0;
			for(l=1;l<=(n/i);l++){
				naya[i]+= old[i*l]; //the main LOGIC
				naya[i]=naya[i] %modulo;
			}
			//now we have formed the next layer
		}
		//copy the layer forward
		for(l=1;l<=n;l++){
			old[l]=naya[l];
		}
	}
	// cout<<"hi"<<endl;
	//calc answer
	long answer=0;
	for(int i=1; i<=n;i++){
		answer= (answer+ naya[i])%modulo;
	}
	answer= answer%modulo;
	cout<<answer<<endl;
}