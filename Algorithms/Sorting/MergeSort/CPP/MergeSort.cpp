#include <iostream>
#include <vector>
using namespace std;

vector<int> sel_sort(vector<int> v)
{
	int size=v.size();
	vector<int> sv;

	for(int foo=0;foo<size;foo++)
	{
		int idx=0;
		for(int i=1;i<v.size();i++)
		{
			if(v[i]<v[idx])
				idx=i;

		}
		sv.push_back(v[idx]);
		v.erase(v.begin() + idx);
	}

	return sv;
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
	cout << "Selection Sort" << endl;

	vector<int> vec;
	vec.push_back(1);
	vec.push_back(5);
	vec.push_back(2);
	vec.push_back(0);
	vec.push_back(88);
	vec.push_back(12);
	vec.push_back(3);

	print_vec(vec);
	vector<int> sv=sel_sort(vec);
	print_vec(sv);

	return 0;
}
