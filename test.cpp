#include<iostream>
using namespace std;
#include "exam.cpp"
int main()
{
    try 
    {
        ManageShop M;
        char pro[10];
        int quantity;
        int capacity,check;
        cout<<"Enter capacity:";
        cin>>capacity;
        M.createArray(capacity);
        M.EnterProduct();
        M.showShop();
        cout<<"Do you want to cheke any product understock Yes->1 No->0:";
        cin>>check;
        if(check)
        {
            cout<<"Enter Product Name:";
            cin.ignore();
            cin.getline(pro,10);
            if(M.islessStock(pro))
                cout<<"INSUFFICIENT STOCK !"<<endl;
            cout<<"Do you want to update Yes->1 No->0:";
            cin>>check;
            if(check)
            {
                cout<<"Enter updated current stock:";
                cin>>quantity;
                M.updateStock(pro,quantity);
            }
        
        }
        M.showShop();
    }
    catch(int e)
    {
        switch (e)
        {
        case 1:
            cout<<"ARRAY NOT CREATED !";
            break;
        case 2:
            cout<<"ARRAY ELEMENT NOT FOUND !";
        }

    }
    return 0;
}