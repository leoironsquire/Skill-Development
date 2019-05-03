/*Rajas Mateti
    17u187
    222010
    B1*/

#include <iostream>
#include <fstream>
#include <string> 
using namespace std;
int main()
{     int k=0; 
string line;     
string find;     
char name[25];    
 int roll=0;     
char d; 
string adres;
ofstream myfile,f2;     
myfile.open("data.txt",ios::app);     
while(k!=4){
cout<<"press 1 for adding data"<<endl;         
cout<<"press 2 for update "<<endl; 
cout<<"press 3 for searching"<<endl;
cin>>k;
if(k==1)
{
cout<<"enter roll no. "<<endl;             
cin>>roll;
cout<<"enter Name"<<endl;           
  cin>>name;
cout<<"enter division "<<endl;             
cin>>d; cout<<"enter adre."<<endl;
cin>>adres; myfile<<roll<<" ";
myfile<<name<<" ";

myfile<<d<<" ";
myfile<<adres<<endl;
}
if(k==2)
{
cout<<"Enter roll no, you want to update "<<endl;             
cin>>find;             
ifstream file,f1;
file.open("data.txt",ios::in); 
file>>line;
while (!file.eof() && line!=find)
{
getline(file,line);
}
if(find!=line)
{
cout<<"deaTAILS NOT FOUND";
} 
else{
cout<<"enter Name"<<endl;            
 cin>>name;
cout<<"enter dividion "<<endl;             
cin>>d;
cout<<"enter address"<<endl; 
cin>>adres; myfile<<find;
myfile<<name;
myfile<<d;
myfile<<adres<<endl;
}}         
if(k==3)
{
cout<<"Enter roll no, you want to update "<<endl;
cin>>find;             
ifstream file;
file.open("data.txt",ios::in);
 file>>line;
while (!file.eof() && line!=find)
{
getline(file,line); file>>line;
}
if(find!=line)
{
cout<<"deaTAILS NOT FOUND";
}
else { 
cout<<"roll.no"<<endl; 
cout<<line<<endl; 
file>>line; 
cout<<line<<endl; 
file>>line; 
cout<<line<<endl; 
file>>line; 
cout<<line<<endl; }

}
}
return 0; }
