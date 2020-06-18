class Solution {
public:
    
    bool isNumberDecimal(string str){
        if( str == "") return false;
        for(int i=0 ; i < str.size() ; i++){
            if( str[i] < '0' || str[i] > '9') return false;
        }
        return true;
    }
    
    bool isHexDecimal(string str){
        if( str == "") return false;
        for(int i=0 ; i < str.size() ; i++){
            if((str[i] < '0' || str[i] > '9') && (str[i] < 'A' || str[i] > 'F') && (str[i] < 'a' || str[i] > 'f')) return false;
        }
        return true;
    }
    
    bool isIPV4(vector<int> v, string str){
        string nums[4];
        nums[0] = str.substr(0, v[0]);
        for(int i = 1; i <= 2 ; i++){
            nums[i] = str.substr(v[i-1] + 1, v[i] - v[i-1] - 1);    
        }
        nums[3] = str.substr(v[2] + 1, str.size() - v[2] - 1);
        
        int current = 0;
        for(int i = 0 ; i < 4 ; i++){
            if(nums[i].size() > 3 || !isNumberDecimal(nums[i])) return false;
            
            current = stoi(nums[i]);
            if(to_string(current) != nums[i]) return false;
            if(current < 0 || current > 255) return false;
            
        }
        
        return true;
    }
    
    bool isIPV6(vector<int> v, string str){
        string nums[8];
        nums[0] = str.substr(0, v[0]);
        for(int i = 1; i <=6 ; i++){
            nums[i] = str.substr(v[i-1] + 1, v[i] - v[i-1] - 1);    
        }
        nums[7] = str.substr(v[6] + 1, str.size() - v[6] - 1);
        
        for(int i = 0 ; i < 8 ; i++){
            if(!isHexDecimal(nums[i]) || nums[i].size() > 4) return false;
        }
        
        return true;
    }
    
    vector<int> countPattern(string str, char c){
        vector<int> v;
        for(int i = 0 ; i < str.size() ; i++){
            if(str[i] == c) v.push_back(i);
        }
        
        return v;
    }

        
    
    string validIPAddress(string IP) {

        if(IP == "") return "Neither";
        vector<int> points = countPattern(IP, '.');
        vector<int> colons = countPattern(IP, ':');
        
        if(points.size() == 3 && colons.size() != 7){
            if(isIPV4(points,IP)) return "IPv4";
            else "Neither";
        }else if( points.size() != 3 && colons.size() == 7){
            if(isIPV6(colons,IP)) return "IPv6";
            else "Neither";
        }
        
        return "Neither";
    }
};
