#include <iostream>
#include <random>
#include <string>


namespace rnd
{
	std::random_device rd;
	std::mt19937 rng(rd());
	const int gen_int(const int& mn, const int& mx)
	{
		std::uniform_int_distribution<int> uni(mn, mx);
		return uni(rng);
	}
}


int main()
{
	std::cout << "Hi hi there\n";

	const int mn = 100;
	const int mx = 1000;
	
	int secret = rnd::gen_int(mn, mx);
	std::string str_secret = std::to_string(secret);
	std::cout << "Secret: " << secret << std::endl;

	std::string guess;

	while (true)
	{
		std::cout << "Guess: ";
		std::cin >> guess;
		if (guess == "q")
			break;
		std::cout << "Got: " << guess << std::endl;

			
	}
	return 0;
}
