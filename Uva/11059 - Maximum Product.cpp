#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
using namespace std;

int main(){

	int N;
	vector<long long> S;
	int numCase=1;
	while(scanf("%d",&N)!=EOF){
		long long temp;
		while(N--){
			scanf("%lld",&temp);
			S.push_back(temp);
		}
		int l=S.size();
		long long maxProduct = 0;
		long long sum;
		for (int i = 0; i < l; ++i){
			sum=1;
			for (int j = i; j < l; ++j){
				if(!S[j])break;
				sum*=S[j];
				if(maxProduct<sum)
					maxProduct = sum;
			}
		}
		S.clear();
		printf("Case #%d: The maximum product is %lld.\n\n",numCase,maxProduct);
		numCase++;
	}
	return 0;
}