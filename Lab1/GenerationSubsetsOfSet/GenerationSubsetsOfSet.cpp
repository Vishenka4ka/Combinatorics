#include <algorithm>
#include <iostream>
#include <vector>
#include <boost/timer.hpp>

using namespace std;

int main()
{
	int n = 10;
	vector<size_t> b(n);
	boost::timer t;
	t.restart();

	for (int i = 0; i <=  n; i++)
	{
		b[i] = 0;
	}

	int i;
	while (b[n] != 1)
	{
		copy(b.end(), b.begin(), ostream_iterator<size_t>(cout, " "));
		cout << "\n";
		
		i = 0;
		while (b[i] == 1)
		{
			b[i] = 0;
			i = i + 1;
		}

		b[i] = 1;
	}

	double duration = t.elapsed();
	cout << duration << endl;
}
