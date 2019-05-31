#include <bits/stdc++.h>

using namespace std;

#define debug(x) cout<<#x<<" : "<<x<<"\n"
#define debug2(x, y) cout << #x << " : " << x << " - " << #y << " : " << y << "\n"
#define debug3(n, array) for(int i = 0; i < n ; i++) cout<<i<<" : "<<array[i]<<"\n"
#define test() cout<<"Hello world"<<"\n"
#define z() Sleep(2000)

#define loop(i, n) for(int i = 0; i < n ; i++)

#define sz(array) (int)array.size()
#define mset(array, value) memset(array,value,sizeof(array))

#define vi vector<int>
#define vll vector<ll>
#define msi map<int,string>
#define mss map<string,string>

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}


void quicksort(vector<int> &arr, int low, int high) {

    if (low < high) {
        int pi = partition(arr, low, high);

        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    int nums1Length = nums1.size();
    int nums2Length = nums2.size();

    vector<int> result;

    if(nums1Length == 0 || nums2Length ==0) return result;

    if( nums1Length == 2){
        if(nums1[0] > nums1[1]){
            swap(nums1[0],nums1[1]);
        }
    }else if(nums1Length > 2){
        quicksort(nums1, 0, nums1Length-1);
    }

    if(nums2Length == 2){
        if(nums2[0] > nums2[1]){
            swap(nums2[0],nums2[1]);
        }
    }else if(nums2Length > 2){
        quicksort(nums2, 0, nums2Length-1);
    }

    int i, j;

    if (nums1Length < nums2Length) {
        i = 0;
        for (j = 0; j < nums2Length; j++) {

            while(i < nums1Length && nums2[j] > nums1[i]){
                i++;
            }

            if( i >= nums1Length) break;

            if(nums1[i] == nums2[j]){
                result.push_back(nums1[i]);
                i++;
            }
        }
    }else{
        i = 0;
        for (j = 0; j < nums1Length; j++) {
            while(i < nums2Length && nums1[j] > nums2[i]){
                i++;
            }

            if( i >= nums2Length) break;

            if(nums2[i] == nums1[j]){
                result.push_back(nums2[i]);
                i++;
            }
        }
    }

    return result;
}

int main() {

    vi v1;
    v1.push_back(-2147483648);
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    vi v2;
    v2.push_back(1);
    v2.push_back(-2147483648);
    v2.push_back(-2147483648);

    vi result = intersect(v1,v2);
    debug3(result.size(),result);

    return 0;
}