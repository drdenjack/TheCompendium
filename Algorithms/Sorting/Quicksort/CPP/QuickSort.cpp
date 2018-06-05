#include <iostream>
#include <vector>
using namespace std;

vector<int> quick_sort(vector<int> v)
{
    int size=v.size();
    if(size<=1)
        return v;

    vector<int> sv;

    // pick mid point as piv
    int idx=size/2;
    int piv = v[idx];
    vector<int> less;
    vector<int> more;
    for(int i=0;i<size;i++)
    {
        if(i!=idx)
        {
            if(v[i]<piv)
                less.push_back(v[i]);
            else
                more.push_back(v[i]);
        }
    }

    less = quick_sort(less);
    more = quick_sort(more);

    
    vector<int>::iterator it = less.begin();
    vector<int>::iterator end = less.end();
    for(;it!=end;++it)
    {
        sv.push_back(*it);
    }

    sv.push_back(piv);
    
    it = more.begin();
    end = more.end();
    for(;it!=end;++it)
    {
        sv.push_back(*it);
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
    for(int i=0;i<100;i++)
    {
        vec.push_back(rand()%10000-5000);
    }
    
    print_vec(vec);
    vector<int> sv=quick_sort(vec);
    print_vec(sv);

    return 0;
}
