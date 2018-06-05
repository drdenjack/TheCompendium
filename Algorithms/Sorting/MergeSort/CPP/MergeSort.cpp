#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

vector<int> merge(vector<int> a_vec, vector<int> b_vec)
{
    vector<int> ret;

    int size_a = a_vec.size();
    int size_b = b_vec.size();

    int a=0;
    int b=0;
    while(a<size_a && b<size_b)
    {
        if(a_vec[a]<b_vec[b])
        {
            ret.push_back(a_vec[a]);
            a++;
        }
        else
        {
            ret.push_back(b_vec[b]);
            b++;
        }
    }

    while(a<size_a)
    {
        ret.push_back(a_vec[a]);
        a++;
    }

    while(b<size_b)
    {
        ret.push_back(b_vec[b]);
        b++;
    }

    return ret;
}


vector<int> merge_sort(vector<int> v,int l, int r)
{
    if(r-l<=0)
    {
        vector<int> ret;
        ret.push_back(v[r]);
        return ret;
    }
        
    int idx=(r+l)/2;

    vector<int> left = merge_sort(v,l,idx);
    vector<int> right = merge_sort(v,idx+1,r);
    return merge(left,right);
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
    for(int i=0;i<100;i++)
    {
        vec.push_back(rand()%10000-5000);
    }
    
    print_vec(vec);
    vector<int> sv=merge_sort(vec,0,vec.size()-1);
    print_vec(sv);

    return 0;
}
