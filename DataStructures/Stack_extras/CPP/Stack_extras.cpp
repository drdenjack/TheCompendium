#include <iostream>
#include <climits>

using namespace std;

class STK
{
public:
    STK();
    STK(int size);
    STK(const STK &S);
    ~STK();

    int size();
    int min();
    int max();
    int max_size();
    bool is_empty();

    void push(int);
    void pop();
    int top();

    void print();
    
private:
    int * _data;
    int _max_size;
    int _size;
    int _min;
    int _max;

    void resize(void);
    
};

STK::STK(): _max_size(32), _size(0), _min(INT_MAX), _max(INT_MIN)
{
    _data = new int[_max_size];
}

STK::STK(int max_size): _size(0), _min(INT_MAX), _max(INT_MIN)
{
    _max_size=max_size;
    _data = new int[_max_size];
}

STK::STK(const STK &S)
{
    _max_size=S._max_size;
    _size=S._size;
    _min=S._min;
    _max=S._max;
    _data = new int[_max_size];
    for(int i=0;i<_max_size;++i)
        _data[i]=S._data[i];
}

STK::~STK()
{
    delete _data;
}

int STK::size()
{
    return _size;
}

int STK::min()
{
    if(is_empty())
        throw "STK is empty.  No min available";
    return _min;
}

int STK::max()
{
    if(is_empty())
        throw "STK is empty.  No max available";
    return _max;
}

int STK::max_size()
{
    return _max_size;
}

bool STK::is_empty()
{
    return (size()==0);
}

void STK::push(int a)
{
    if(size()==max_size())
        resize();
    
    _data[_size++]=a;

    if(a<_min)
        _min=a;
    if(a>_max)
        _max=a;
}

void STK::resize()
{
    int prev_size=max_size();
    _max_size*=2;
    int * prev_data = _data;
    int * new_data = new int[_max_size];
    for(int i=0;i<prev_size;i++)
    {
        new_data[i]=_data[i];
    }
    _data=new_data;
    delete prev_data;
}

void STK::pop()
{
    int pop_val=_data[_size-1];
    if(!is_empty())
        _size--;

    if(is_empty())
    {
        _min=INT_MAX;
        _max=INT_MIN;
    }
    else if(_size>0)
    {
        // without storing a second array/map/etc this needs to be
        // calculated again
        if(pop_val==_min || pop_val==_max)
        {
            int new_min=_data[0];
            int new_max=_data[0];
            if(_size>1)
            {
                for(int i=1;i<_size;i++)
                {
                    if(_data[i]<new_min)
                        new_min=_data[i];
                    if(_data[i]>new_max)
                        new_max=_data[i];
                }
            }
            _min=new_min;
            _max=new_max;
        }
    }
}

int STK::top()
{
    if(is_empty())
        throw "STK is empty";
    return _data[size()-1];
    // NOTE: the STL stack just has a segmentation fault when accessing top() of an empty stack.
}

void STK::print()
{
    cout << " -- printing --\n";
    cout << "size: " << size() << endl;
    try {
        cout << "min: " << min() << endl;
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
        
    try {
        cout << "max: " << max() << endl;
    }
    catch (const char* msg) {
        cout << msg << endl;
    }
    
    cout << "max_size: " << max_size() << endl;

    for(int i=size()-1;i>=0;i--)
    {
        cout << " data[" << i << "]" << _data[i] << endl;
    }
    
}

int main() {
	cout << "Enhanced Stack" << endl;

        STK S(2);
        S.print();

        int top;
        try {
            top=S.top();
            cout << "top: " << top << endl;
        } catch (const char* msg) {
            cout << msg << endl;
        }
        
        S.pop();
        S.print();
        
        S.push(5);
        S.print();
        
        S.push(8);
        S.print();

        top=S.top();
        cout << "top: " << top << endl;
        
        S.push(13);
        S.print();

        S.push(21);
        S.print();

        S.push(13);
        S.print();

        S.pop(); 
        S.print();
        
        S.pop(); 
        S.print();

        
	return 0;

}
