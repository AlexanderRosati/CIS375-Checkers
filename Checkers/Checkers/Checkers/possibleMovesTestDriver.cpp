#include "Board.h";
#include <iostream>

void possibleMovesTestDriver()
{
	Board board;
	std::vector<int> adjSpaces;
	
	for (int i = 0; i < 32; ++i)
	{
		board.content[i] = "K1";
	}

	for (int i = 0; i < 32; ++i)
	{
		std::cout << "Space Num: " << i + 1 << " Adj Spaces: ";
		adjSpaces = board.adjSpaces('K', '1', i / 4, i);
		for (int i = 0; i < adjSpaces.size(); ++i) adjSpaces.at(i) += 1;
		
		for (int i = 0; i < adjSpaces.size(); ++i)
		{
			std::cout << adjSpaces.at(i) << " ";
		}

		std::cout << std::endl;
		system("pause");
	}
}