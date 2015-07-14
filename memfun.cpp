#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

using namespace std;

class Rectangle {
	double w;
	double h;
public:
	Rectangle(double w, double h) : w(w), h(h) {}
	Rectangle(double s = 1.0) : w(s), h(s) {}
	bool IsSquare(){ return w == h; }
};

struct P2 {
	double x;
	double y;

	P2(double x, double y) : x(x), y(y) {}
	P2() : x(0.0), y(0.0) {}
};

int main(){
	Rectangle rects[] = {
		Rectangle(10), Rectangle(10, 20), Rectangle(20), Rectangle(20, 40), Rectangle(40)
	};
	
	vector<Rectangle> vrects(&rects[0], &rects[0] + sizeof(rects) / sizeof(rects[0]));
	cout << count_if(vrects.begin(), vrects.end(), mem_fn(&Rectangle::IsSquare)) << endl;
	
//	P2 pts[] = {
//		P2(), P2(10.0, 10.0), P2(60.0, 10.0), P2(50.0, 0.0)
//	};


	static const int arr[] = { 16, 2, 77, 29 };
	vector<int> vec(arr, arr + sizeof(arr) / sizeof(arr[0]));

	return 0;
}

