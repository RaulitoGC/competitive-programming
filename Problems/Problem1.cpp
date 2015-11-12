/*
Se requiere postular a un trabajo y el correo para que te acepten en el trabajo es el siguiente #####@gmail.com
En donde ###### es la sumatoria de los 12 numeros primos capicúas de
5 cifras que solo usen 2 digitos, uno par y el otro impar (ejemplos de estos numeros: 11411, 72727, 78887)
Se le pide buscar cual es esa sumatorio para que te acepten en el trabajo.
*/

//Solucion:

#include <iostream>
#include <bitset>
#include <vector>

using namespace std;

bitset<10000010> bs;
vector<int> primes;
long long _sieve_size;

void sieve(long long uppebound){

	_sieve_size =  uppebound +1;
	bs.set();
	bs[0] = bs[1] = 0;
	for (long long i = 2; i <= _sieve_size; ++i){
		if(bs[i]){
			for (long long j = i*i; j <= _sieve_size; j+=i)
				bs[j] = 0;

			primes.push_back((int)i);
		}
	}
}

bool isCapicua(int n){
    int t1 =  n%10;
    int t2 =  (n/10)%10;

    int t3 = (n/1000)%10;
    int t4 = (n/10000)%10;
    return ((t1==t4)&&(t2==t3));
}
bool is2Digits(int n){
    int t1 =  n%10;
    int t2 =  (n/10)%10;
    int t3 = (n/100)%10;
    if(t1==t2){
        if(t3!=t1){
            return true;
        }
    }
    else{
        if(t1==t3 || t2==t3){
        return true;
        }
    }
    return false;
}
bool evenOdd(int n){
    int t1 =  n%10;
    int t2 =  (n/10)%10;
    int t3 = (n/100)%10;
    if(t1==t2){
        if((t3%2==0 && t1%2==1) || (t1%2==0 && t3%2==1)){
            return true;
        }
    }
    else{
        if((t2%2==0 && t1%2==1) || (t1%2==0 && t2%2==1)){
            return true;
        }
    }
    return false;
}

int main (){

	sieve(100000);
	int sum=0;
	if(bs[10001]){
        cout<<"HOPÑ";
	}
	 for(int i =10000;i<100000;i++){
        if(bs[i]){
            if(isCapicua(i)){
                if(is2Digits(i)){
                    if(evenOdd(i)){
                        cout<<"number :"<<i<<endl;
                        sum=sum+i;
                    }
                }
            }
        }
	 }
	 cout<<sum;

 return 0;
 }

