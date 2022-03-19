/*how operator overloading works
 clear; g++ -std=c++2a operator.cpp && ./a.exe
 *
 * */
#include<iostream>
#include<vector>
using namespace std;

class DailyTemp {
private:
	int temp;
public:
	class x;

	// todo How to make following explicit?
	explicit DailyTemp(int x): temp{x} {
	};

	void display(){
		cout << this->temp << ", ";
	}

	bool operator<(const DailyTemp &rhs) const {
		if (this->temp < rhs.temp) {
			return true;
		}
		return false;
	}

	bool operator>(const DailyTemp &rhs) const {
		if (this->temp > rhs.temp){
			return true;
		}

		return false;
	}
};

int main(int argc, char *argv[]){
	/* explicit states, call the constructor explicitly. assignment cant call constuctor. */
	// DailyTemp test1 = 3; // Error: constructor is explicit. so
	// 3 will not be converted to DailyTemp type
	DailyTemp test2(3); // correct as in explicit
	DailyTemp test3(3.4); // correct as in explicit
	vector<DailyTemp> v;
	int i;

	for (i = 0; i<10; i++ ){
		v.push_back(DailyTemp(i + 0.4));
	}

	for(i=0; i<v.size();i++){
		v[i].display();
	}
	cout << endl;
	cout << boolalpha << (v[0] < v[1]) << endl;
	cout << boolalpha << (v[0] > v[1]) << endl;
}
