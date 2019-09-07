#include <bitset>
#include <limits>
#include <iostream>
#include <queue>
#include <math.h>
using namespace std;

void ToTwo(int a)
{
	cout << bitset<32>(a) << endl;
	bitset<32> dvo;
	bool minus_flag = a < 0, flag = false ;
	
	queue <int> st;
	int b = abs(a);
	
	while (b > 1) {
		st.push(b % 2);
		b = b / 2;
	}
	st.push(b);
	for (int i = 0; i < 32; i++) {
		if (st.empty())
			dvo[i] = flag ? 1 : 0;
		else {
			if (flag) {
				dvo[i] = st.front() == 1 ? 0 : 1;
				st.pop();
			}
			else {

				dvo[i] = st.front();
				st.pop();
				if (minus_flag && dvo[i] == 1) flag = true;
			}
		}
	}
	cout << dvo;
	/*for (int i = 0; i < 32; i++) {
		if (st.empty())
			dvo[i] =  0;
		else {
			

				dvo[i] = st.front();
				st.pop();
				
			
		}
	}
	if (a >= 0)
		cout << dvo;
	else
		cout << ~dvo + 1;*/
}

void ToTwo(float a)
{
	cout << bitset<32>(a) << endl;
	bitset<32> dvo;
	bool minus_flag = a < 0, flag = false;

	queue <int> st;
	int b = abs(a);
	float c = a - b;
	while (b > 1) {
		st.push(b % 2);
		b = b / 2;
	}
	st.push(b);
	int n = st.size();
	for (int i = n; i <= 24; i++) {
		float k;
		c = modff(c * 2, &k);
		st.push(k);
	}

	for (int i = 0; i < 32; i++) {
		if (st.empty())
			dvo[i] = flag ? 1 : 0;
		else {
			if (flag) {
				dvo[i] = st.front() == 1 ? 0 : 1;
				st.pop();
			}
			else {

				dvo[i] = st.front();
				st.pop();
				if (minus_flag && dvo[i] == 1) flag = true;
			}
		}
	}
	cout << dvo;
	/*for (int i = 0; i < 32; i++) {
		if (st.empty())
			dvo[i] =  0;
		else {


				dvo[i] = st.front();
				st.pop();


		}
	}
	if (a >= 0)
		cout << dvo;
	else
		cout << ~dvo + 1;*/
}

int main()
{
	/*int a = 25, b = -25;
	short int s = 78, ns = -78;	cout << bitset<32>(a) << endl;
	cout << bitset<32>(b) << endl;
	cout << bitset<16>(s) << endl;
	cout << bitset<16>(ns) << endl;
	
	cout << bitset<32>(~a + 1) << endl;
	cout << bitset<16>(~s + 1) << endl;

	cout << bitset<sizeof(a) * CHAR_BIT>(a) << endl;
	cout << bitset<sizeof(b) * CHAR_BIT>(b) << endl;
	cout << bitset<sizeof(s) * CHAR_BIT>(s) << endl;
	cout << bitset<sizeof(ns) * CHAR_BIT>(ns) << endl;
	float g = 0.99;
	
		float f = 0.01, nf = -0.01;
	float sum = f + g;
	float ff = numeric_limits<float>::quiet_NaN();
	float fff = numeric_limits<float>::infinity();	int* rf = reinterpret_cast<int *>(&f);
	cout << bitset<32>(*rf) << endl;
	rf = reinterpret_cast<int *>(&nf);
	cout << bitset<32>(*rf) << endl;
	rf = reinterpret_cast<int *>(&ff);
	cout << bitset<32>(*rf) << endl;
	rf = reinterpret_cast<int *>(&fff);
	cout << bitset<32>(*rf) << endl;
	rf = reinterpret_cast<int *>(&f);
	cout << bitset<32>(*rf) << endl;
	rf = reinterpret_cast<int *>(&g);
	cout << bitset<32>(*rf) << endl;
	rf = reinterpret_cast<int *>(&sum);
	cout << bitset<32>(*rf) << endl;*/

	int a, b;
	float c, d;
	cin >> a;
	cin >> b;
	cin >> c;
	cin >> d;
	ToTwo(a);
	return 0;
}