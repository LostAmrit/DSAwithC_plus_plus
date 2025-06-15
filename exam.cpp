#include<iostream>
#include<string.h>
using namespace std;
#define ARRAY_NOT_CREATED 1;
#define ARRAY_ELEMENT_NOT_FIND 2;
struct product
{
    char ProductName[20];
    int Quantity;
    int CurrentStock;
};
class ManageShop
{
    private:
        int capacity;
        int lastIndex;
        product *Arr;
    public:
        ManageShop();
        void createArray(int);
        void EnterProduct();
        bool islessStock(char[]);
        int search(char[]); //return index if find
        void updateStock(char[],int);
        void showShop();
        ~ManageShop();
};
ManageShop::ManageShop()
{
    capacity=0;
    lastIndex=0;
}
void ManageShop::createArray(int size)
{
    capacity=size;
    lastIndex=0;
    Arr=new product[capacity];
}
void ManageShop::EnterProduct()
{
    if(capacity==0)
        throw ARRAY_NOT_CREATED;
    for(int i=0;i<capacity;i++)
    {
        product p;
        cout<<"Enter Product Name:";
        //fgets(p.ProductName,20,stdin);
        cin.ignore();
        cin.getline(p.ProductName,20);
        cout<<"Enter Quantity, CurrentStock:";
        cin>>p.Quantity;
        cin>>p.CurrentStock;
        Arr[i]=p;
        lastIndex++;
    }
}
bool ManageShop::islessStock(char Name[])
{
    if(capacity==0)
        throw ARRAY_NOT_CREATED;
    int index=search(Name);
    
    if(Arr[index].CurrentStock<Arr[index].Quantity)
        return true;
    return false;
    
}
int ManageShop::search(char Name[])
{
    if(capacity==0)
        throw ARRAY_NOT_CREATED;
    for(int i=0;i<capacity;i++)
        if(strcmp(Name,Arr[i].ProductName)==0)
            return i;           
    throw ARRAY_ELEMENT_NOT_FIND;
}
void ManageShop::updateStock(char Name[],int currentStock)
{
    if(capacity==0)
        throw ARRAY_NOT_CREATED;
    int index=search(Name);
    Arr[index].CurrentStock=currentStock;
}
void ManageShop::showShop()
{
    cout<<"Product Name  Quantity  Current stock"<<endl;
    for(int i=0;i<capacity;i++)
        cout<<Arr[i].ProductName<<"    "<<Arr[i].Quantity<<"    "<<Arr[i].CurrentStock<<endl;
}
ManageShop::~ManageShop()
{
    delete Arr;
}
