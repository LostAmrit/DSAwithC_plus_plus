#include<iostream>
#define ARRAY_NOT_CREATED 1
#define ARRAY_OVERFLOW 2
#define ARRAY_UNDERFLOW 3
#define INVAILID_INDEX 4
using namespace std;
//1. Define a class Array to implement array data structure with member variables to store capacity of array, last index at the filled block of the array and the pointer to hold the address of the first block of the dynamically created array.
class Array
{
    private:
        int capacity, lastIndex;
        int *p; 
    public:
        Array(int);
        Array(Array &);
        int getcapacity(){return capacity;}
        int getLastIndex(){return lastIndex;}
        void creatArray();
        bool IsEmpty();
        void Append(int);
        void insert(int,int);
        void edit(int,int);
        void Delete(int);
        int getElement(int);
        int count();
        virtual ~Array();
        int find(int);
        void getArray();
};
Array::Array(int size)
{
    p=nullptr;
    if(size<1)
        throw ARRAY_NOT_CREATED;
    capacity=size;
    lastIndex=-1;         
}
Array::Array(Array &C)
{
    //capacity=size;
    capacity=C.capacity;
    lastIndex=C.lastIndex;
    p=C.p;
    p=new int [capacity];
}
void Array::creatArray()
{
    if(capacity<0)
        throw ARRAY_NOT_CREATED;
    p=new int[capacity];
}
void Array::getArray()
{
    if(p==nullptr)
        throw ARRAY_NOT_CREATED;
    for(int i=0;i<=lastIndex;i++)
        cout<<p[i]<<" ";
}
bool Array::IsEmpty()
{
    if(p==nullptr)
        throw ARRAY_NOT_CREATED;
    if(lastIndex+1==capacity)
        return true;
    return false; 
}
void Array::Append(int NewElement)
{
    if(p==nullptr)
        throw ARRAY_NOT_CREATED;
    if(IsEmpty())
        throw ARRAY_OVERFLOW;
    p[lastIndex+1]=NewElement;
    lastIndex++;
}
void Array::insert(int index,int NewElement)
{
    if(p==nullptr)
        throw ARRAY_NOT_CREATED;
    if(IsEmpty())
        throw ARRAY_OVERFLOW;
    if(index<0 || index>lastIndex+1)
        throw ARRAY_UNDERFLOW;
    for(int i=lastIndex;i>=index;i--)
        p[i-1]=p[i];
    p[index]=NewElement;
    lastIndex++;
}
void Array::edit(int index,int newelement)
{
    if(p==nullptr)
        throw ARRAY_NOT_CREATED;
    if(index<0 || index>lastIndex)
        throw INVAILID_INDEX;
    p[index]=newelement;
}
void Array::Delete(int index)
{
    if(p==nullptr)
        throw ARRAY_NOT_CREATED;
    if(index<0 || index>lastIndex)
        throw INVAILID_INDEX;
    for(int i=index;i<=lastIndex;i++)
        p[i+1]=p[i];
    lastIndex--;
}
int Array::getElement(int index)
{
    if(p==nullptr)
        throw ARRAY_NOT_CREATED;
    if(index<0 || index>lastIndex)
        throw INVAILID_INDEX;
    return p[index];
}
int Array::count()
{
    if(p==nullptr)
        throw ARRAY_NOT_CREATED;
    return lastIndex;
}
Array::~Array()
{
    if(p!=nullptr)
        delete []p;
}
int Array::find(int search)
{
    if(p==nullptr)
        throw ARRAY_NOT_CREATED;
    for(int i=0;i<=lastIndex;i++)
        if(p[i]==search)
            return i;
    return -1;
}
int main()
{
    try
    {
        Array A(10);
        int a;
        A.creatArray();
        cout<<"Enter 5 elements:";
        for(int i=0;i<5;i++)
        {
            cin>>a;
            if(A.IsEmpty())
                throw 2;
            A.Append(a);
            
        }
        if(4>A.getLastIndex())
            return 1;
        cout<<A.find(5)<<endl;
        if(3>A.getLastIndex())
            return 3;
        //A.Delete(4);
        A.getArray();

    }
    catch(int e){
        switch(e)
        {
            case 1:
                cout<<"ARRAY NOT CREATED";
                break;
            case 2:
                cout<<"ARRAY_OVERFLOW";
                break;
            case 3:
                cout<<"INVALID INDEX";
        }
    }
    
}
//2. In Question 1, define a parameterise constructor to creat an array of specific size.
//3. In question 1, add a method to check whether an array is empty of not by return true and false.
//4. In question 1,define a method to append a new elements in the array
//5. In question 1, define a method to insert a new element in specific index
//6. In question 1, define a methode to edit an element at specific index
//7. In question 1, define a method to delete a element at specific index.
//8. In question 1, define a method to check if the aray is full by returning true and false.
//9. In question 1, define a method to get element at specific index.
//10. In question 1, define a method to count number of elements present in array.
//11. In question 1, define a distructor to deallocate the memory of array.
//12. In question 1, define a method to find an element in array. return index if the element found, otherwise return -1.