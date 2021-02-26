#include <bits/stdc++.h>
using namespace std;

bool leap(int y){
	return y%4==0 && (y%100!=0 || y%400==0);
}

int main(){

	int t,c=1;
	char iniMonth[30],finMonth[30];
	int iniDay,iniYear,finDay,finYear;
	scanf("%d",&t);
	while(t--){
	
		scanf("%s %d, %d",iniMonth,&iniDay,&iniYear);
		scanf("%s %d, %d",finMonth,&finDay,&finYear);

		bool cond=true;
		
		int i,temp,cont;
		cont=0;
		for(i = iniYear; i<=finYear;i++){
			if(leap(i)){
				temp = i;
				cond = false;
				break;
			}
		}
		if(cond){
			cont=0;	
		} 
		else{

			for(i = temp; i<=finYear;i+=4){
				if(leap(i)) cont++;
			}		
			if(leap(iniYear)){
				if(iniMonth!="January" && iniMonth!="February")
					cont--;
			}

			if(leap(finYear)){
				if(finMonth=="January"){
					cont--;	
				}else{
					if(finMonth=="February")
						if(finDay!=29) 
							cont--;
				}
			}

		}
		printf("Case %d: %d\n",c,cont);
		c++;
	}


	return 0;
}