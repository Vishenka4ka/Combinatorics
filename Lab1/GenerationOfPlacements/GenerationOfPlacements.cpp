#include <algorithm>
#include <iostream>
#include <vector>
#include <boost/timer.hpp>

using namespace std;

int main()
{
	int n = 20;
	vector<size_t> v(n);
	boost::timer t;
	t.restart();

	int k = 5;
	v[0] = -1;
	for (int i = 1; i <= k; i++)
	{
		v[i] = i;
	}

	int m = 1;
	while (m != 0)
	{
		do
		{
			copy(v.begin() + 1, v.begin() + k + 1, ostream_iterator<int>(cout, " "));
			cout << "\n";

		} while (std::next_permutation(v.begin() + 1, v.begin() + k + 1));

		m = k;
		while (v[m] == n - k + m)
		{
			m = m - 1;
		}

		v[m]++;
		for (int i = m + 1; i <= k; i++)
		{
			v[i] = v[i - 1] + 1;
		}
	}

	double duration = t.elapsed();
	std::cout << duration << std::endl;
}
