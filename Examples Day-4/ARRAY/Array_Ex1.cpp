#include <iostream>
#include <array>

int main()
{
	std::array<int, 4> playerScores{}; // initialize with zeros

	for (int score : playerScores)
		std::cout << score << ", ";

	playerScores.fill(100);
	playerScores.front()=40;
    playerScores.back() = 30;

	std::cout << '\n';
	for (int score : playerScores)
		std::cout << score << ", ";
    
    return 0;
}