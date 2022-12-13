
#include <iostream>
using namespace std;

class Vector3D
{
private:
	double d[3];
	int state;
	static int count;
public:
	
	Vector3D() : state(0) { d[0] = d[1] = d[2] = 0; count++;}
	Vector3D(double n);
	Vector3D(double*);
	~Vector3D() {
		cout << " State = " << state << endl;
		count--;
	}
	static int getCount() {
		if (count <= 0) cout << " There are no objects Vector3D " << endl;
		return count;
	}
	void Output();
	void SetD(double a);
	double GetDi(int i);
	Vector3D Add(Vector3D& b);
	Vector3D Sub(Vector3D& b);
	Vector3D VecMul(Vector3D& b);
	Vector3D Div(short b);
	bool CompLessAll(Vector3D& b);
	bool CompMoreAll(Vector3D& b);
	bool EqualAll(Vector3D& b);
};
int Vector3D::count = 0;
Vector3D::Vector3D(double n) {
	state = 0;
	count++;
	for (int i = 0; i < 3; i++) {
		d[i] = n;
	}
}
Vector3D::Vector3D(double* p) {
	count++;
	if (p == NULL) { state = -1; cout << " Vec --> 0 "; }
	else { state = 0; }
	for (int i = 0; i < 3; i++) {
		d[i] = p[i];
	}
}
void Vector3D::SetD(double a = 1) {
	for (int i = 0; i < 3; i++) {
		d[i] = a;
	}
}
void Vector3D::Output() {
	for (int i = 0; i < 3; i++) {
		cout << " D[" << i << "] " << d[i] << '\t';
		cout << endl;
	}
}
double Vector3D::GetDi(int i) {
	return d[i];
}
Vector3D Vector3D::Add(Vector3D& b) {
	Vector3D tmp;
	for (int i = 0; i < 3; i++) {
		tmp.d[i] = d[i] + b.d[i];
	}
	return tmp;
}

Vector3D Vector3D::Sub(Vector3D& b) {
	Vector3D tmp;
	for (int i = 0; i < 3; i++) {
		tmp.d[i] = d[i] - b.d[i];
	}
	return tmp;
}

Vector3D Vector3D::VecMul(Vector3D& b) {
	Vector3D tmp;
	tmp.d[0] = d[1] * b.d[2] - d[2] * b.d[1];
	tmp.d[1] = -(d[0] * b.d[2] - d[2] * b.d[0]);
	tmp.d[2] = d[1] * b.d[0] - d[0] * b.d[1];
	return tmp;

}
Vector3D Vector3D::Div(short b) {
	if (b != 0) {
		Vector3D tmp;
		for (int i = 0; i < 3; i++) {
			tmp.d[i] = d[i] /b;
		}
		return tmp;
	}
	state = -1;
	return *this;
}
bool Vector3D::CompLessAll(Vector3D& b) {
	bool result;
	for (int i = 0; i < 3; i++) {
		result = d[i] < b.d[i];
		if (result == false) {
			return false;
		}
	}
	return true;
}

bool Vector3D::CompMoreAll(Vector3D& b) {
	bool result;
	for (int i = 0; i < 3; i++) {
		result = d[i] > b.d[i];
		if (result == false) {
			return false;
		}
	}
	return true;
}

bool Vector3D::EqualAll(Vector3D& b) {
	bool result;
	for (int i = 0; i < 3; i++) {
		result = d[i] == b.d[i];
		if (result == false) {
			return false;
		}
	}
	return true;
}

int main()
{
	double a;
	double A[3] = { 1, 2, 3 };
	cout << " Test " << endl;
	Vector3D VecObj, VecObj1(10), VecObj2(A);
	cout << "VecObj \n";
	VecObj.Output();
	cout << "VecObj1 \n";
	VecObj1.Output();
	cout << "VecObj2 \n";
	VecObj2.Output();
	cout << " Count of objects Vector3D " << Vector3D::getCount() << endl;
	cout << " Input a " << endl;
	cin >> a;
	cout << a << endl;
	VecObj.SetD(a);
	cout << "VecObj \n";
	VecObj.Output();
	cout << VecObj2.GetDi(1) << endl;
	VecObj1 = VecObj.Add(VecObj1);
	cout << "VecObj1 \n";
	VecObj1.Output();
	VecObj1 = VecObj1.Sub(VecObj2);
	cout << "VecObj1 \n";
	VecObj1.Output();
	VecObj1 = VecObj1.VecMul(VecObj2);
	cout << "VecObj1 \n";
	VecObj1.Output();
	VecObj = VecObj1.Div(3);
	cout << "VecObj \n";
	VecObj.Output();
	cout << VecObj.CompLessAll(VecObj2) << endl;
	cout << VecObj2.CompMoreAll(VecObj) << endl;
	cout << VecObj.EqualAll(VecObj) << endl;
	return 0;
}