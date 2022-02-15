#include <algorithm>
#include <iostream>
#include <vector>
#include <random>

int main()
{
	const int CardsNumber = 36;
	std::vector<size_t> Deck(CardsNumber);

	int i;
	for (i = 0; i < CardsNumber; i++)
	{
		Deck[i] = i + 1;
	}

	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist6(0, CardsNumber - 1); 

	for (i = 0; i < CardsNumber; i++)
	{
		std::swap(Deck[i], Deck[dist6(rng)]);
	}

	copy(Deck.begin(), Deck.end(), std::ostream_iterator<size_t>(std::cout, " "));
	std::cout << std::endl;
}

