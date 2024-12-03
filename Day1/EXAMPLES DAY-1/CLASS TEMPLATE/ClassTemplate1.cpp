#include<iostream>
using namespace std;

template<typename T=double> class CA
{
private:
    T a,b;
public:
    CA(T);
    CA(T,T);
    ~CA();
    void Sum();
};

template<typename T> CA<T>::CA(T x):a(x), b(x)
{ 
    cout <<"CA<" <<typeid(T).name()<<"> one arg. constructor called" << endl;
}

template<typename T> CA<T>::CA(T x, T y):a(x), b(y)
{ 
    cout <<"CA<" <<typeid(T).name()<<"> two arg. constructor called" << endl;
}

template<typename T> CA<T>::~CA()
{ 
    cout <<"~CA<" <<typeid(T).name()<<"> destructor called" << endl;
}

template<typename T> void CA<T>::Sum()
{ 
    cout <<"CA<" <<typeid(T).name()<<">::Sum()" << endl;
}
//---------------------------------------------+

int main()
{
    CA<int> ob1(10,20);
    ob1.Sum();
    cout <<"---------------" << endl;
    CA<float> ob2(45.12f, 67.34f);
    ob2.Sum();
    cout <<"---------------" << endl;
    CA<> ob3(980.21, 798.34);
    ob3.Sum();
    return 0;
}
