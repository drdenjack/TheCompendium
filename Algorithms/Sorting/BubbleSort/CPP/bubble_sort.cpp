//============================================================================
// Name        : bubble_sort.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

vector<int> bsort(vector<int> v)
{
	int size=v.size();
	for(int foo=0;foo<size;foo++)
	{
		for(int i=0;i<size-1;i++)
		{
			if(v[i+1]<v[i])
			{
				int tmp = v[i];
				v[i]=v[i+1];
				v[i+1]=tmp;
			}
		}

	}
	return v;
}

void print_vec(vector<int> v)
{
	int size=v.size();
	for(int i=0;i<size;i++)
	{
		cout << v[i];
		if(i<size-1)
			cout << ", ";
	}
	cout << endl;

}

int main() {
	cout << "Bubble Sort" << endl; // prints !!!Hello World!!!

	vector<int> vec;
	vec.push_back(1);
	vec.push_back(5);
	vec.push_back(2);
	vec.push_back(0);
	vec.push_back(88);
	vec.push_back(12);
	vec.push_back(3);

	print_vec(vec);
	vector<int> sv=bsort(vec);
	print_vec(sv);

	return 0;
}
