using namespace std;

// Do not edit the class below except for
// the insert method. Feel free to add new
// properties and methods to the class.
class ContinuousMedianHandler {
public:
  double median;
	vector<int> numbers;

  void insert(int number) {
    numbers.push_back(number);
		sort(numbers.begin(), numbers.end());
		int n = numbers.size();
		if(n % 2 != 0){
			median = numbers[n/2];
		}else{
			median = (numbers[n/2] + numbers[(n/2) - 1]) / 2.0;
		}
  }

  double getMedian() { return median; }
};

