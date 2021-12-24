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


const int GUESS_LENGTH = 3;
const int mn = 100;
const int mx = 1000;


int main()
{
	int secret = rnd::gen_int(mn, mx);
	std::string str_secret = std::to_string(secret);
	std::cout << "Secret: " << secret << std::endl;

	std::string guess;

	while (true)
	{
		std::cout << "Guess: ";
		std::cin >> guess;
		// std::cout << "Got: " << guess << std::endl;
		

		if (guess == "q")
			break;
		if (guess.length() != GUESS_LENGTH)
		{
			std::cout << "Guess must be length of 3.";
			continue;
		}

		if (guess == str_secret)
		{
			std::cout << "Win!\n";
			break;
		}

		int founded_chars_count = 0;
		for (int i = 0; i <= GUESS_LENGTH; i++)
		{
			auto pos = str_secret.find(guess[i]);

			if (pos == std::string::npos)
			{
				continue;
			}
			else
			{
				founded_chars_count++;
				if (pos == i)
				{
					std::cout << "Fermi ";
				}
				else
				{
					std::cout << "Pico ";
				}
			}
		}
		if (founded_chars_count == 0)
		{
			std::cout << "Bagels\n";
		}
		else
		{
			std::cout << "\n";
		}
	}
	return 0;
}
