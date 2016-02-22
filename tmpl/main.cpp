#include <iostream>     
#include <algorithm>    
#include <vector> 
#include "gtest\gtest.h"

using namespace std;

class kkk;
bool cmpa(const kkk & i, const  kkk & z);
template <class RandomAccessIterator, class compare> void sortk(const RandomAccessIterator & first, const RandomAccessIterator & last, compare cmp);

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


/*
Тестируем компаратор объектами класса ккк. Создается 2 объекта со значением 1 и 2.
При подаче компаратора (1,2) -ожидаем истину
При подаче компаратора (2,1) -ожидаем лож
*/

TEST(cmpr, kkk)  
{
	kkk k1(1), k2(2);
	ASSERT_TRUE(cmpa(k1, k2) ); 
	ASSERT_FALSE(cmpa(k2, k1)); 
}

/*
Тестируется функция сортировки. Создается вектор, заполняется значениями, в сорт подается начальный и конечный итераторы, в результате ожидается отсортированный вектор.
*/

TEST(sotr)
{
	vector<int> vec;
	vec.push_back(30);
	vec.push_back(90);
	vec.push_back(1);
	vec.push_back(35);
	sortk(vec.begin(), vec.end(), cmpa);
	ASSERT_TRUE(vec[0] == 1);
	ASSERT_TRUE(vec[1] == 30);
	ASSERT_TRUE(vec[2] == 35);
	ASSERT_TRUE(vec[3] == 90);
}


bool cmpa(const kkk & i, const  kkk & z)
{
	return (i<z);
}


/*
template <class RandomAccessIterator> void sort(RandomAccessIterator first, RandomAccessIterator last)
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


template <class RandomAccessIterator, class compare> void sortk(const RandomAccessIterator & first, const RandomAccessIterator & last, compare cmp)
{
	auto next = first+1;
	auto current = first;
	bool out = true;
	while (out)
	{
		out = false;
		next = first+1;
		current = first;
		while (next != last)
		{
			if (cmp(*(next), *(current)))
			{
				auto a = *current;
				*current = *(next);
				*(next) = a;
				out = true;
			}
			++next;
			++current;
		}
	}
}



int main(int argc, char ** argv)
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

	for (auto&elem : _vect)
	{
		cout << elem.z << endl;
	}
	cout << endl;
	sortk(_vect.begin(), _vect.end(), cmpa);
	for (auto&elem : _vect)
	{
		cout << elem.z << endl;
	}
	cin.get();

	::testing::InitGoogleTest(&argc, argv);
	RUN_ALL_TESTS();

	cin.get();
}
