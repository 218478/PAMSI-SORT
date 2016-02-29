#include<iostream>
#include<cstdio>
#include<ctime>
using namespace std;

class Tab
{
	int size;
	int * tab;
	int * wsk;

	public : Tab()
	{
		size = 10;
		tab = new int[10];
		wsk = tab;
	}

	public : Tab(int newSize)
	{
		size = newSize;
		tab = new int[size];
		wsk = tab;
	}

	public : void Add(int number)
	{
		if(wsk != NULL)
		{
			*wsk = number;
			wsk++;
		}
		else
		{
			size++;
			int * t = new int[size];
			for(int i =0; i < (size-1); i++)
			{
				t[i] = tab[i];
			}
			t[size-1] = number;

			delete [] tab;
			tab = new int[size];
			wsk = tab;
			for(int i = 0; i < size; i++)
			{
				*wsk = t[i];
				wsk++;
			}
			delete [] t;
		}
	}

	public : int Display(int i)
	{
		return tab[i];
	}
};

int main()
{
	clock_t startTime;
	clock_t endTime;
	double difference;
	int n;

	cout << "Podaj ilosc elementow: " << endl;
	cin >> n;


	Tab tab1(10);

	startTime = clock();
	for(int i=0; i < n; i++)
	{
		tab1.Add(i);
		cout << "Tab" << i << " : " << tab1.Display(i) << endl;
	}
	endTime = clock();
	difference = (double)(endTime-startTime) / (double)CLOCKS_PER_SEC;
	cout << "Czas wykonania: " << difference << endl;

	return 0;
}





