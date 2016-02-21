#include <iostream>     
#include <algorithm>    
#include <vector> 

using namespace std;

class kkk
{
public:
	kkk(int i)
	{
		z = i;
	}
	bool operator<(const kkk& right)const
	{
		return(z < right.z);
	}

	int z;

};

bool cmpa(const kkk & i, const  kkk & z)
{
	return (i<z);
}


/*
template <class RandomAccessIterator> void sortk(RandomAccessIterator first, RandomAccessIterator last)
{
	auto next = first;
	bool out = true;
	while (out)
	{
		out = false;
		next = first;
		while (next + 1 != last)
		{
			if (*next > *(next + 1))
			{
				int a = *next;
				*next = *(next + 1);
				*(next + 1) = a;
				out = true;
			}
			++next;
		}
	}
}
//*/


template <class RandomAccessIterator, class compare> void sortk(RandomAccessIterator first, RandomAccessIterator last, compare cmp)
{
	auto next = first;
	bool out = true;
	while (out)
	{
		out = false;
		next = first;
		while (next + 1 != last)
		{
			if (cmp(*(next + 1), *(next)))
			{
				auto a = *next;
				*next = *(next + 1);
				*(next + 1) = a;
				out = true;
			}
			++next;
		}
	}
}



int main()
{
	kkk z = 10;
	vector<kkk>_vect;
	_vect.push_back(z);
	z = 24;
	_vect.push_back(z);
	z = 5;
	_vect.push_back(z);
	z = 7;
	_vect.push_back(z);

	//*
	for (auto&elem : _vect)
	{
		cout << elem.z << endl;
	}
	//*/
	cout << endl;

	sortk(_vect.begin(), _vect.end(), cmpa);
	//*
	for (auto&elem : _vect)
	{
		cout << elem.z << endl;
	}
	//*/
	cin.get();
}
