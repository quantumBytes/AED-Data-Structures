#include "list.h"

using namespace std;

template<typename T>
void showList(list<T>& A)
{
    sizet A_size=A.size();
    for(size_t i=0; i<A_size; i++)
        cout<<A[i]<<"\t";
    cout<<"size: "<<A_size<<endl;
}

int main()
{
    list<int> A;
    int a=2, b=3, c=4;
    A.add_rec(a);
    A.add_rec(b);
    A.add_rec(c);
    showList(A);
    A.invert();
    showList(A);

}
