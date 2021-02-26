class Solution {
public:
    
    static bool validation(pair<string,int> p1, pair<string,int> p2){
        if( p1.first.size() == p2.first.size()) return p1.second < p2.second;
        return p1.first.size() < p2.first.size();
    }
    
    string arrangeWords(string text) {
        
        vector<pair<string,int>> array;
        
        text[0] = text[0] + 32;
        
        istringstream ss(text);
        int i = 0;
        do { 
            string word; 
            ss >> word;
            if(!word.empty()){
                array.push_back(make_pair(word,i));    
            }
            i++;
        } while (ss);
        
        
        sort(array.begin(), array.end(), validation);
        
        string result = "";
        
        if(array[0].first[0]>=97 && array[0].first[0]<=122){
		    array[0].first[0] = array[0].first[0] - 32;
	    }
        result += array[0].first;
        
        for(int i = 1 ; i < array.size() ; i++){
            result += " " + array[i].first;
        }
        
        return result;
        
    }
};
