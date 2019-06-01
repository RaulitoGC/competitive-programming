class Solution {
public:
    
    string units1[10] = {"One","Two","Three","Four","Five","Six","Seven","Eight","Nine","Ten"};
    string units2[9] = {"Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};    
    string tens[9] = {"Ten","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety"};
    
    string hundreds(int num){
        int u,t,h;
        
        if(num == 0) return "";
        
        if(num <= 10){
            return units1[num-1];
        }
        
        if(num < 20){
            return units2[(num%10) - 1];
        }
    
        if(num < 100){
            u = num%10;
            t = num/10;
            if(u == 0){
                return tens[t-1];    
            }else{
                return tens[t - 1] + " " + units1[u-1];
            }
        }
        
        return "";
    }
    
    string getSpace(string ss){
        return (ss !="")? " " + ss : "";
    }
    
    string numberToWords(int num) {
        
        if(num == 0) return "Zero";
        
        string partialResult,result;
        
        string names[4] = {"Hundred","Thousand","Million","Billion"};
        
        if(num < 100) return hundreds(num);
        
        int tempNum;
        for(int i = 0; i < 4  && num > 0; i++){
            tempNum = num%1000;
            cout << "Temp Num -> "<< tempNum << endl;
            partialResult = hundreds(tempNum%100);
            cout << "Partial Result ->"<< partialResult <<"|"<< endl;
            tempNum = (tempNum%1000)/100;
            cout << "Temp Num -> "<< tempNum << endl;
            if(tempNum != 0){
                if(i == 0){
                    result = units1[tempNum-1] + " " + names[i] + getSpace(partialResult) +getSpace(result); 
                }else{
                    result = units1[tempNum-1] + " " + names[0] + getSpace(partialResult) + " "+ names[i]+getSpace(result); 
                }
            }else if(partialResult != ""){
                if(i == 0){
                    result = partialResult + getSpace(result);     
                }else{
                    result = partialResult + " " + names[i] + getSpace(result);     
                }
            }
            num /=1000;
            cout << "result -> "<< result << endl;
            cout << "=====================" << endl;
        }
        
        return result;
    }
};