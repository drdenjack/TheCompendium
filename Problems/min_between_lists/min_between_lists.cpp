#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

void print_vec(vector<int> a)
{
    int a_size=a.size();
    for(auto i=0;i<a_size;i++)
        cout << a[i] << " ";
    cout << endl;

}

int main() {
	cout << "Minimum distance between two pages" << endl;

        vector<int> a = { 1, 2, 3, 4, 9, 7, 13 };
        vector<int> b = { 1, 10, 23, 14 ,5};

        cout << "unsorted: " << endl;
        print_vec(a);
        print_vec(b);

        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        cout << "sorted: " << endl;
        print_vec(a);
        print_vec(b);

        int a_size=a.size();
        int b_size=b.size();

        int i=0;
        int j=0;
        int prev_diff=a[0]-b[0];
        int diff=prev_diff;
        bool inc_a=true;
        int min_diff=diff;
        while(i<a_size && j<b_size)
        {
            cout << " i,j: " << i << ", " << j << endl;
            
            diff = abs(a[i] - b[j]);
                
            cout << "abs(" << a[i] << " - " << b[j] << ")" << endl; 
            cout << " diff: " << diff << endl;
            cout << " -- prev_diff: " << prev_diff << endl;
            if(diff==0)
                break;

            if(diff>prev_diff)
                inc_a=!inc_a;

            
            if(inc_a)
                i++;
            else
                j++;

            if(diff<min_diff)
                min_diff=diff;
            
            prev_diff=diff;
        }
        
        cout << "MIN_DIFF: " << min_diff << endl;
        
        

        
	return 0;

}
