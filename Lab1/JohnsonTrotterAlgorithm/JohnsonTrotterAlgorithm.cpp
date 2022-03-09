#include <algorithm>
#include <iostream>
#include <vector>
#include <boost/timer.hpp>

int main()
{
	int n = 10;
	std::vector<size_t> v(n + 2);
	std::vector<size_t> p(n + 1);
	std::vector<int> d(n + 1);
	boost::timer t;
	t.restart();

	// Заполнение вектора перестановки, обратной перестановки и направления 
	int i;
	for (i = 1; i <= n; ++i)
	{
		v[i] = i;
		p[i] = i;
		d[i] = -1;
	}
	
	v[0] = n + 1;
	v[n + 1] = n + 1;
	d[1] = 0;
	int m = n + 1;

	// Цикл алгоритма Джонсона-Троттера без вывода каждой из перестановок 
	while (m != 1)
	{
		m = n;
		while (v[p[m] + d[m]] > m)
		{
			d[m] = -d[m];
			--m;
		}

		std::swap(v[p[m]], v[p[m] + d[m]]);
		std::swap(p[v[p[m]]], p[m]);
	}

	double duration = t.elapsed();
	std::cout << duration << std::endl;
}