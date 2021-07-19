

	#include<iostream>
	using namespace std;

	int AR[100];
	int bsearch(int VAL,int left, int right);
	void sort(int n);
	void accept(int n);
	int main()
	{
		int n,val;
		int found;
	
		cout<<"Enter number of elements you want to insert ";
		cin>>n;
		accept(n);

		sort(n);

		cout<<"\nEnter the number you want to search ";
		cin>>val;

		found=bsearch(val,0,n-1);

		if(found!=0)
			cout<<"\nItem found at: "<<found+1<<" position\n";
		else
			cout<<"\nItem not found";
	
		return 0;
	}

	void accept(int n)
	{

		cout<<"Enter elements\n";
		for(int i=0;i<n;i++)
		{
			cout<<"Enter element: "<<i+1<<":";
			cin>>AR[i];
		}
	}

	int bsearch(int VAL,int left, int right)
	{
		int Mid;
		if(left<=right)
		{
			Mid=(left+right)/2;
			if(VAL>AR[Mid])
				return bsearch(VAL,Mid+1,right);
			else if(VAL<AR[Mid])
				return bsearch(VAL,left,Mid-1);
			else
				return Mid;
		}
		return 0;
	}


	void sort(int n)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n-i-1;j++)
			{		
				if(AR[j]>AR[j+1])
				{
					int temp=AR[j];
					AR[j]=AR[j+1];
					AR[j+1]=temp;
				}
			}
		}

		cout<<"Sorted array is:";
		for(int i=0;i<n;i++)
		{
			cout<<AR[i]<<"  ";
		}
	}

	/*
	[ccoew@localhost ~]$ g++ recursivesearch.cpp
	[ccoew@localhost ~]$ ./a.out
	Enter number of elements you want to insert 7
	Enter elements
	Enter element: 1:3
	Enter element: 2:5
	Enter element: 3:4
	Enter element: 4:1
	Enter element: 5:2
	Enter element: 6:6
	Enter element: 7:7
	Sorted array is:1  2  3  4  5  6  7  
	Enter the number you want to search 9

	Item not found[ccoew@localhost ~]$ ./a.out
	Enter number of elements you want to insert 6
	Enter elements
	Enter element: 1:23
	Enter element: 2:11
	Enter element: 3:14
	Enter element: 4:32
	Enter element: 5:56
	Enter element: 6:7
	Sorted array is:7  11  14  23  32  56  
	Enter the number you want to search 23

	Item found at: 4 position


	Item not found[ccoew@localhost ~]$ ^C
	*/
