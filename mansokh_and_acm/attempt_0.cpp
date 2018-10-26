//https://codeforces.com/problemset/problem/414/B
#include <stdio.h>
#include <iostream>

using namespace std;


int main(){
	int dummy =-10;
	int n,k;
	cin>> n>>k;

	//dplagega
	long cache[n][k];
	//report answer modulo

	for(int i=0; i< n;i++){
		for(int j=0;j<k;j++){
			cache[i][j]=dummy;
		}
	} 
	for(int i=0; i<n;i++){
		cache[i][0]=1;
	}
	for(int j=0;j<k;j++){
		cache[0][j]=0;
	}

	//recursion?

	for(int i=0;i<n;i++){
		for(int j=1;j<k;j++){
			if(cache[i][j]!=dummy){
				cache[i][j]=cache[i][j-1]; //shifted initialisation
				for(int k=1;k<=i;k++){
					for(int l=1; l<= i/k;l++){
						cache[i][j]+= cache[i- l*k+1][j-1]
					}
 				}
			}
		}
	}

	//dhang se nhi socha 
	//
	//LINEAR SHIFTING OF VALUES DOESN"T PRESERVE DIVISIBILITY

	return 0;
}