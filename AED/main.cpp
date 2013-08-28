#include <iostream>
#include "list.h"

using namespace std;

template<typename T>
void showList(list<T> A)
{
    sizet A_size=A.size();
    for(size_t i=0; i<A_size; i++)
        cout<<A.at(i)<<endl;
}

int main()
{


    list<int> A;
    int a=2, b=3, c=4;
    A.push_back(a);
    A.push_back(b);
    A.push_front(c);
    A.push_back(c);

    showList(A);
    cout<<"size: "<<A.size()<<endl;
}

