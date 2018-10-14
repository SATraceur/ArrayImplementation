#include <iostream>

using namespace std;

// definition

#define MAX_LENGTH 100
#define INIT_VALUE 0

class Array {
public:
	Array(int length);
	Array& operator=(const Array& other);

	int length() const;
	int& operator[](int index);
	
	bool operator==(const Array& other) const;
	bool operator!=(const Array& other) const;


private:
	int length_;
	int elements_[MAX_LENGTH];
};

// implementation

Array::Array(int length) {
	length_ = length;
	if (length_ > MAX_LENGTH) length_ = MAX_LENGTH;
	for (int i = 0; i < length_; ++i) {
		elements_[i] = INIT_VALUE;
	}
}

Array& Array::operator=(const Array& other) {
	// Q2 code goes here
	if (*this != other) // protect against invalid self-assignment
	{
		length_ = other.length_; // assigning length of other array to ?
		for (int i = 0; i < length_; i++)
		{
			elements_[i] = other.elements_[i]; // assigning elements of other to this array's elements
		}
	}
	return *this;
}

int Array::length() const {
	return length_;
}




int& Array::operator[](int index) {
	// Q3 code goes here
	if (index < 0) { index = 0; }
	if (index > MAX_LENGTH) { index = MAX_LENGTH; }
	return elements_[index];
}

bool Array::operator==(const Array& other) const {
	if (length_ != other.length_) return false;
	for (int i = 0; i < other.length_; ++i) {
		if (elements_[i] != other.elements_[i]) return false;
	}
	return true;
}

bool Array::operator!=(const Array& other) const {
	// Q1 code goes here
	if (length_ == other.length_) return true;
	for (int i = 0; i < other.length_; ++i)
	{
		if (elements_[i] == other.elements_[i]) return true;
	}

	return false;
}

// testing

int main() 
{
	Array x(10);
	x[10] = 1;
	
	//cout << "x contains ";
	//for (int i = 0; i < x.length(); ++i) {
	//	cout << x[i] << " ";
	//}
	//cout << endl;

	Array y(10);
	y[0] = 3;
	x = y;
	cout << boolalpha;
	cout << "x equals y? " << (x == y) << endl;
	// cout << y[-1] << " y[-1]";


	system("pause");
	return(0);
}
