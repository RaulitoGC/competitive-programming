class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string,int> M1;
        unordered_map<string,int> M2;
        
        int n1 = list1.size();
        int n2 = list2.size();
        int i, sum = INT_MAX;
        string word;
        vector<string> result;
        if(n1 < n2){
            for(i = 0 ; i < n1 ; i++){
                M1[list1[i]] = M2[list2[i]] = i;
            }
            for(i = n1 ; i < n2 ; i++){
                M2[list2[i]] = i;
            }
            
            for(i = 0 ; i < n1 ; i++){
                word = list1[i];
                if(M2.count(word) > 0){
                    if(M1[word] + M2[word] < sum){
                        sum = M1[word] + M2[word];
                    }
                }
            }
            
            for(i = 0 ; i < n1 ; i++){
                word = list1[i];
                if(M2.count(word) > 0){
                    if(M1[word] + M2[word] == sum){
                        result.push_back(word);
                    }
                }
            }
            
        }else{
            for(i = 0 ; i < n2 ; i++){
                M1[list1[i]] = M2[list2[i]] = i;
            }
            
            for(i = n2 ; i < n1 ; i++){
                M1[list1[i]] = i;
            }
            
            for(i = 0 ; i < n2 ; i++){
                word = list2[i];
                if(M1.count(word) > 0){
                    if(M1[word] + M2[word] < sum){
                        sum = M1[word] + M2[word];
                    }
                }
            }
            
            for(i = 0 ; i < n2 ; i++){
                word = list2[i];
                if(M1.count(word) > 0){
                    if(M1[word] + M2[word] == sum){
                        result.push_back(word);
                    }
                }
            }
        }
        
        return result;
    }
};