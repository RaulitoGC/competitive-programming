/* Template from Tourist */
 
string to_string(const string& s) {
  return '"' + s + '"';
}
 
string to_string(const char* s) {
  return to_string((string) s);
}
 
string to_string(bool b) {
  return (b ? "T" : "F");
}

template<typename A, typename B>
string to_string(unordered_map<A, B> umap){
  bool first = true;
  string res = "{";
  typename unordered_map<A, B>::iterator it;
  for (it = umap.begin(); it != umap.end(); it++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += "\n";
    res += "[" + to_string(it->first) + ":" + to_string(it->second) + "]";
  }
  res += "\n";
  res += "}";
  return res;
}

template<typename A, typename B>
string to_string(map<A, B> m){
  bool first = true;
  string res = "{";
  typename map<A, B>::iterator it;
  for (it = m.begin(); it != m.end(); it++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += "\n";
    res += "[" + to_string(it->first) + ":" + to_string(it->second) + "]";
  }
  res += "\n";
  res += "}";
  return res;
}

template<typename A>
string to_string(set<A> s){
  bool first = true;
  string res = "{";
  typename set<A>::iterator it;
  for (it = s.begin(); it != s.end(); it++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(*it);
  }
  res += "}";
  return res;
}

template<typename A>
string to_string(unordered_set<A> s){
  bool first = true;
  string res = "{";
  typename unordered_set<A>::iterator it;
  for (it = s.begin(); it != s.end(); it++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(*it);
  }
  res += "}";
  return res;
}
 
string to_string(vector<bool> v) {
  bool first = true;
  string res = "{";
  for (int i = 0; i < static_cast<int>(v.size()); i++) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(v[i]);
  }
  res += "}";
  return res;
}
 
template <typename A>
string to_string(A v) {
  bool first = true;
  string res = "{";
  for(const auto &x : v) {
    if (!first) {
      res += ", ";
    }
    first = false;
    res += to_string(x);
  }
  res += "}";
  return res;
}
 
template <typename A, typename B>
string to_string(pair<A, B> p) {
  return "<" + to_string(p.first) + ", " + to_string(p.second) + ">";
}

void debug_out() { cerr << endl; }
 
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}