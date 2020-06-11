class BrowserHistory {
public:
    
    list<string> pages;
    list<string>::iterator it;
    int current;
    
    BrowserHistory(string homepage) {
        pages.push_back(homepage);
        current = 0;
    }
    
    void visit(string url) { 
        if(current != pages.size() - 1){
            int size = pages.size();
            for(int i = current + 1; i < size; i++){
                pages.pop_back();
            }    
        }
        pages.push_back(url);
        current = pages.size() - 1;
    }
    
    string back(int steps) {
        current -= steps;
        if( current < 0) current = 0;
        it = pages.begin();
        advance(it, current);
        return *it;
    }
    
    string forward(int steps) {
        current += steps;
        if(current >= pages.size()) current = pages.size() - 1;
        it = pages.begin();
        advance(it, current);
        return *it;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

