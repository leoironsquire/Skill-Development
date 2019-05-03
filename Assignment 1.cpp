/*Rajas Mateti
    17u187
    222010
    B1*/

#include<iostream>
using namespace std;

class Set
{
	int set[20];
	int size;
public:
	Set(int s)
	{
		size=s;
	}

	void create()
	{
		for(int i=0;i<size;i++)
		{
			cin>>set[i];
		}
	}

	int insert(int element)
	{
		set[size]=element;
		return ++size;
	}

	int contains(int element)
	{
		int i=0;
		while(i<size)
		{
			if(set[i]==element)
				return i+1;
			i++;
		}
		return 0;
	}

	int set_size()
	{
		return size;
	}

	void remove(int element)
	{
		int i=0;
		while(i<size)
		{
			if(set[i]==element)
			{
				for(int j=i;j<size;j++)
				{
					set[j]=set[j+1];
				}
				cout<<"\nElement deleted...";
				size=size-1;
				return;
			}
			i++;
		}
		cout<<"\nSorry, element not found...";
	}

	void display()
	{
		cout<<"{ ";
		for(int i=0;i<size;i++)
		{
			cout<<set[i]<<" ";
		}
		cout<<"}";
	}

	void set_intesection(Set &set1,Set &set2)
	{
		int i=0,j=0;
		while(i<set2.size)
		{
			if(compare(set2.set[i],set1))
			{
				this->set[j]=set2.set[i];
				j++;
			}
			i++;
		}
		size=j;
	}

	void set_union(Set &set1,Set &set2)
	{
		int j;
		for(j=0;j<set1.size;j++)
			set[j]=set1.set[j];

		int i=0;
		while(i<set2.size)
		{
			if(!compare(set2.set[i],set1))
			{
				this->set[j]=set2.set[i];
				j++;
			}
			i++;
		}
		size=j;
	}

	void set_diff(Set &set1,Set &set2)
	{
		int i=0,j=0;
		while(i<set1.size)
		{
			if(!compare(set1.set[i],set2))
			{
				this->set[j]=set1.set[i];
				j++;
			}
			i++;
		}
		size=j;
	}

	int subset(Set &s)
	{
		int i=0,status=1;
		while(i<s.size)
		{
			if(!compare(s.set[i],*this))
			{
				status=0;
				break;
			}
			else
				status=1;

			i++;
		}
		return status;
	}

	int compare(int e,Set &s)
	{
		for(int i=0;i<s.size;i++)
		{
			if(e==s.set[i])
				return 1;
		}
		return 0;
	}

};
int main()
{
	Set inter(20),BmA(20),AmB(20),un(30);
	int size1,size2,ch,status,e;
	char set_ch;
	char tryAgain;
	cout<<"Enter the size of set A: ";
	cin>>size1;
	Set s1(size1);
	cout<<"Enter the elements of set A: ";
	s1.create();
	cout<<"Enter the size of set B: ";
	cin>>size2;
	Set s2(size2);
	cout<<"Enter the elements of set B: ";
	s2.create();
	cout<<"Set A: ";
	s1.display();
	cout<<"\nSet B: ";
	s2.display();
	do{
		cout<<"\n|===============Menu==============|";
		cout<<"\n1.Insert";
		cout<<"\n2.Remove";
		cout<<"\n3.Contains";
		cout<<"\n4.Size";
		cout<<"\n5.Intersection";
		cout<<"\n6.Union";
		cout<<"\n7.A-B";
		cout<<"\n8.B-A";
		cout<<"\n9.Check subset";
		cout<<"\n10.Display Sets.";
		cout<<"\n11.Exit.";
		cout<<"\nEnter your choice: ";
		cin>>ch;

		switch(ch)
		{
		case 1:
			cout<<"Which set you want to enter the element in?(A/B): ";
			cin>>set_ch;
			cout<<"Enter element to be inserted: ";
			cin>>e;
			if(set_ch=='A'||set_ch=='a')
			{
				s1.insert(e);
				cout<<"\nSet A: ";
				s1.display();
			}
			else
			{
				s2.insert(e);
				cout<<"\nSet B: ";
				s2.display();
			}
		break;

		case 2:
			cout<<"Which set you want to delete the element from?(A/B): ";
			cin>>set_ch;
			cout<<"Enter element to be deleted: ";
			cin>>e;
			if(set_ch=='A'||set_ch=='a')
			{
				s1.remove(e);
				cout<<"\nSet A: ";
				s1.display();
			}
			else
			{
				s2.remove(e);
				cout<<"\nSet B: ";
				s2.display();
			}
		break;

		case 3:
			int pos;
			cout<<"In which set you want check?(A/B): ";
			cin>>set_ch;
			cout<<"Enter element to be checked: ";
			cin>>e;
			if(set_ch=='A'||set_ch=='a')
			{
				pos=s1.contains(e);
				if(pos!=0)
				{
					cout<<"\nElement found at position: "<<pos;
					cout<<"\nSet A: ";
					s1.display();
					break;
				}
			}
			else
			{
				pos=s2.contains(e);
				if(pos!=0)
				{
					cout<<"\nElement found at position: "<<pos;
					cout<<"\nSet B: ";
					s2.display();
					break;
				}
			}
			cout<<"\nSorry,element not found...";
		break;

		case 4:
			cout<<"\nSet A: ";
			s1.display();
			size1=s1.set_size();
			cout<<" with Size: "<<size1;
			cout<<"\nSet B: ";
			s2.display();
			size2=s2.set_size();
			cout<<" with Size: "<<size2;
		break;

		case 5:
			inter.set_intesection(s1,s2);
			cout<<"\nIntersection: ";
			inter.display();
		break;

		case 6:
			un.set_union(s1,s2);
			cout<<"\nUnion: ";
			un.display();
		break;

		case 7:
			AmB.set_diff(s1,s2);
			cout<<"\nA-B: ";
			AmB.display();
		break;

		case 8:
			BmA.set_diff(s2,s1);
			cout<<"\nB-A: ";
			BmA.display();
		break;

		case 9:
			status=s1.subset(s2);
			(status==0)?cout<<"\nB Subset of A: false" :cout<<"\nB Subset of A: true";
		break;
		case 10:
				cout<<"Set A: ";
				s1.display();
				cout<<"\nSet B: ";
				s2.display();
		break;
		case 11:
			exit(1);

		default: cout<<"\nInvalid Entry...";
		}
	cout<<"\n\nDo you want to try again? (Y/N)";
	cin>>tryAgain;
	}while(tryAgain=='Y'||tryAgain=='y');
}
