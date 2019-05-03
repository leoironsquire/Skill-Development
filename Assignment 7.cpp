/*Rajas Mateti
    17u187
    222010
    B1*/

#include <iostream>
using namespace std;
int hashing(int a[],int value,int n)
{
   int i=1;
    int  key = value%n;
    if (a[key]==-1)
         a[key]=value;
    else
        {
      while(a[key]!=-1)
      {
          key=i*(1+value%(n-1));
          i+=1;
      }
        if (a[key]==-1 )
        a[key]=value;
        else
         cout<<" no index to store value "<<endl;
        }



    return 0;
}

void print(int a[],int n)
{
    cout<<"Index "<<"          "<<" Value "<<endl;
    for (int i=0;i<n;i++)
    {
        if (a[i]!=-1)
         cout<<i<<"         "<<a[i]<<endl;
    }
}
int sizeofset(int a[],int n)
{
  int  cnt=0;
    for(int i=0;i<n;i++)
    {
        if (a[i]!=-1)
            cnt+=1;
    }
    return  cnt;
}
int searchs(int a[],int svalue,int n)
{
    int i=1;
 int key=svalue%n;
 if (a[key]==svalue)
    return key;
    else
     {
      while(a[key]!=svalue)
      {
          key=i*(1+svalue%(n-1));
          i+=1;
      }
        if (a[key]== svalue)
            return key;
        else
         return -1;
        }
}
int main()
{ int value,s,n;
  char choice='y';
  cout<<" enter the size of hashtable "<<endl;
        cin>>n;
        int a[n];
        for (int i=0;i<n;i++)
            a[i]=-1;
while (choice=='y')
{
     cout<<endl<<".............................. MENU ........................................."<<endl;
     cout<<" enter 1 for read number of element and factor present in hashtable "<<endl;
     cout<<" enter 2 for to add value into the hashtable "<<endl;
     cout<<" enter 3 to print the hashtable "<<endl;
     cout<<" enter 4 to search the element "<<endl;
     cout<<"  enter 5 to exit "<<endl;

     cin>>s;
     switch(s)
     {

 case 1:
        cout<<" total element in the set are  "<<sizeofset(a,n)<<endl;
        cout<<" Load factor of hashtable is "<<sizeofset(a,n)/n<<endl;
        break;
 case 2:

       cout<<endl<<" enter the value to store in hashtable "<<endl;
       cin>>value;
       hashing(a,value,n);

       break;
 case 3 :
        print(a,n);
        break;
 case 4:
     int svalue;
     cout<<" enter the value to search "<<endl;
     cin>>svalue;
       if (searchs(a,svalue,n)!=-1)
        cout<<" value "<<svalue<<"  is present at the key "<<searchs(a,svalue,n)<<endl;
       else
        cout<<" element not present in the hashtable "<<endl;
        break;

 case 5:
       choice= 'n';
       break;
     }
    }
    cout << "Hello world!" << endl;
    return 0;
}
