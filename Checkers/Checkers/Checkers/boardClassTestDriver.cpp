#include "Board.h"
#include <assert.h>
#include <iostream>

std::string turnPossibleMovesToString(PossibleMoves pm)
{
	std::string str = "<";
	std::pair<int, std::vector<int>> pair;
	int removePos = NULL;

	while (!pm.empty())
	{
		pair = pm.at(0);
		str += "(" + std::to_string(pair.first) + ", <";

		while (!pair.second.empty())
		{
			if (pair.second.size() == 1)
			{
				removePos = pair.second.at(0);
				pair.second.erase(pair.second.begin());
				str += std::to_string(removePos);
			}

			else
			{
				removePos = pair.second.at(0);
				pair.second.erase(pair.second.begin());
				str += std::to_string(removePos) + ", ";
			}
		}

		str += ">)";
		pm.erase(pm.begin());
	}


	str += ">";
	return str;
}

std::string doTest(std::vector<int> playerOne, std::vector<int> playerTwo, int movingPiece)
{
	Board testBoard(NULL, NULL);

	//make every space empty
	for (int i = 0; i < 32; ++i) testBoard.content[i] = "E";

	//put player one pieces on board
	for (int i = 0; i < playerOne.size(); ++i)
	{
		if (playerOne.at(i) < 0)
		{
			testBoard.content[abs(playerOne.at(i)) - 1] = "K1";
		}

		else
		{
			testBoard.content[playerOne.at(i) - 1] = "P1";
		}
	}

	//put player two pieces on board
	for (int i = 0; i < playerTwo.size(); ++i)
	{
		if (playerTwo.at(i) < 0)
		{
			testBoard.content[abs(playerTwo.at(i)) - 1] = "K2";
		}

		else
		{
			testBoard.content[playerTwo.at(i) - 1] = "P2";
		}
	}

	//calculate possible moves for checker at movingPiece
	PossibleMoves possibleMoves = testBoard.possibleMoves(movingPiece);


	//sort moves
	int minIndx = 0;

	//order pairs by space to be moved to
	for (int i = 0; i < (int) (possibleMoves.size() - 1); ++i)
	{
		minIndx = i;

		for (int j = i + 1; j < possibleMoves.size(); ++j)
		{
			if (possibleMoves.at(minIndx).first > possibleMoves.at(j).first)
			{
				minIndx = j;
			}
		}

		std::swap(possibleMoves.at(minIndx), possibleMoves.at(i));
	}

	//reset minIndx
	minIndx = 0;

	//order spaces to remove for each pair
	for (int i = 0; i < possibleMoves.size(); ++i)
	{
		for (int j = 0; j < (int) (possibleMoves.at(i).second.size() - 1); ++j)
		{
			minIndx = j;

			for (int k = j + 1; k < possibleMoves.at(i).second.size(); ++k)
			{
				if (possibleMoves.at(i).second.at(minIndx) > possibleMoves.at(i).second.at(k))
				{
					minIndx = k;
				}
			}

			std::swap(possibleMoves.at(i).second.at(minIndx), possibleMoves.at(i).second.at(j));
		}
	}

	//convert result to string
	std::string possibleMovesStr = turnPossibleMovesToString(possibleMoves);

	//return string
	return possibleMovesStr;
}

void boardClassTestDriver()
{
	std::string result;

	//Test 1
	result = doTest(std::vector<int> {22}, std::vector<int>(), 22);
	std::cout << "Test 1: " << result << std::endl;
	assert(result == "<(17, <>)(18, <>)>");

	//Test 2
	result = doTest(std::vector<int> {20}, std::vector<int>(), 20);
	std::cout << "Test 2: " << result << std::endl;
	assert(result == "<(16, <>)>");

	//Test 3
	result = doTest(std::vector<int> {22}, std::vector<int> {18, 15}, 22);
	std::cout << "Test 3: " << result << std::endl;
	assert(result == "<(17, <>)>");

	//Test 4
	result = doTest(std::vector<int> {30}, std::vector<int> {26, 19}, 30);
	std::cout << "Test 4: " << result << std::endl;
	assert(result == "<(16, <19, 26>)(25, <>)>");

	//Test 5
	result = doTest(std::vector<int> {22}, std::vector<int> {18, 10, 11}, 22);
	std::cout << "Test 5: " << result << std::endl;
	assert(result == "<(6, <10, 18>)(8, <11, 18>)(17, <>)>");

	//Test 6
	result = doTest(std::vector<int> {29}, std::vector<int> {25, 18, 11}, 29);
	std::cout << "Test 6: " << result << std::endl;
	assert(result == "<(8, <11, 18, 25>)>");

	//Test 7
	result = doTest(std::vector<int> {29}, std::vector<int> {25, 18, 10, 11}, 29);
	std::cout << "Test 7: " << result << std::endl;
	assert(result == "<(6, <10, 18, 25>)(8, <11, 18, 25>)>");

	//Test 8
	result = doTest(std::vector<int> {26, 22, 23}, std::vector<int>(), 26);
	std::cout << "Test 8: " << result << std::endl;
	assert(result == "<>");

	//Test 9
	result = doTest(std::vector<int> {26, 23}, std::vector<int>(), 26);
	std::cout << "Test 9: " << result << std::endl;
	assert(result == "<(22, <>)>");

	//Test 10
	result = doTest(std::vector<int> {22}, std::vector<int> {18, 11, 8}, 22);
	std::cout << "Test 10: " << result << std::endl;
	assert(result == "<(15, <18>)(17, <>)>");

	//Test 11
	result = doTest(std::vector<int> {29}, std::vector<int> {25, 18, 11, 8}, 29);
	std::cout << "Test 11: " << result << std::endl;
	assert(result == "<(15, <18, 25>)>");

	//Test 12
	result = doTest(std::vector<int> {6}, std::vector<int> {1, 2}, 6);
	std::cout << "Test 12: " << result << std::endl;
	assert(result == "<>");

	//Test 13
	result = doTest(std::vector<int> {22}, std::vector<int> {17, 18}, 22);
	std::cout << "Test 13: " << result << std::endl;
	assert(result == "<(13, <17>)(15, <18>)>");

	//Test 14
	result = doTest(std::vector<int> {23}, std::vector<int> {18, 19, 9}, 23);
	std::cout << "Test 14: " << result << std::endl;
	assert(result == "<(5, <9, 18>)(16, <19>)>");

	//Test 15
	result = doTest(std::vector<int> {10}, std::vector<int> {6, 7}, 10);
	std::cout << "Test 15: " << result << std::endl;
	assert(result == "<(1, <6>)(3, <7>)>");

	//Test 16
	result = doTest(std::vector<int> {26}, std::vector<int> {22, 23, 15, 16}, 26);
	std::cout << "Test 16: " << result << std::endl;
	assert(result == "<(10, <15, 23>)(12, <16, 23>)(17, <22>)>");

	//Test 17
	result = doTest(std::vector<int>(), std::vector<int> {6}, 6);
	std::cout << "Test 17: " << result << std::endl;
	assert(result == "<(9, <>)(10, <>)>");

	//Test 18
	result = doTest(std::vector<int>(), std::vector<int> {13}, 13);
	std::cout << "Test 18: " << result << std::endl;
	assert(result == "<(17, <>)>");

	//Test 19
	result = doTest(std::vector<int> {18, 15}, std::vector<int> {11}, 11);
	std::cout << "Test 19: " << result << std::endl;
	assert(result == "<(16, <>)>");

	//Test 20
	result = doTest(std::vector<int> {10, 17}, std::vector<int> {7}, 7);
	std::cout << "Test 20: " << result << std::endl;
	assert(result == "<(11, <>)(21, <10, 17>)>");

	//Test 21
	result = doTest(std::vector<int> {17}, std::vector<int> {13}, 17);
	std::cout << "Test 21: " << result << std::endl;
	assert(result == "<(14, <>)>");

	//Test 22
	result = doTest(std::vector<int> {10, 17, 18}, std::vector<int> {7}, 7);
	std::cout << "Test 22: " << result << std::endl;
	assert(result == "<(11, <>)(21, <10, 17>)(23, <10, 18>)>");

	//Test 23
	result = doTest(std::vector<int> {8, 15, 22}, std::vector<int> {4}, 4);
	std::cout << "Test 23: " << result << std::endl;
	assert(result == "<(25, <8, 15, 22>)>");

	//Test 24
	result = doTest(std::vector<int> {}, std::vector<int> {10, 14, 15}, 10);
	std::cout << "Test 24: " << result << std::endl;
	assert(result == "<>");

	//Test 25
	result = doTest(std::vector<int> {}, std::vector<int> {7, 10}, 7);
	std::cout << "Test 25: " << result << std::endl;
	assert(result == "<(11, <>)>");

	//Test 26
	result = doTest(std::vector<int> {7, 14, 17}, std::vector<int> {3}, 3);
	std::cout << "Test 26: " << result << std::endl;
	assert(result == "<(8, <>)(10, <7>)>");

	//Test 27
	result = doTest(std::vector<int> {30, 31}, std::vector<int> {26}, 26);
	std::cout << "Test 27: " << result << std::endl;
	assert(result == "<>");

	//Test 28
	result = doTest(std::vector<int> {10, 11}, std::vector<int> {7}, 7);
	std::cout << "Test 28: " << result << std::endl;
	assert(result == "<(14, <10>)(16, <11>)>");

	//Test 29
	result = doTest(std::vector<int> {25, 26}, std::vector<int> {22}, 22);
	std::cout << "Test 29: " << result << std::endl;
	assert(result == "<(29, <25>)(31, <26>)>");

	//Test 30
	result = doTest(std::vector<int> {13}, std::vector<int> {9}, 9);
	std::cout << "Test 30: " << result << std::endl;
	assert(result == "<(14, <>)>");

	//Test 31
	result = doTest(std::vector<int> {-14}, std::vector<int> {}, 14);
	std::cout << "Test 31: " << result << std::endl;
	assert(result == "<(9, <>)(10, <>)(17, <>)(18, <>)>");

	//Test 32
	result = doTest(std::vector<int> {}, std::vector<int> {-14}, 14);
	std::cout << "Test 32: " << result << std::endl;
	assert(result == "<(9, <>)(10, <>)(17, <>)(18, <>)>");

	//Test 33
	result = doTest(std::vector<int> {-29}, std::vector<int> {}, 29);
	std::cout << "Test 33: " << result << std::endl;
	assert(result == "<(25, <>)>");

	//Test 34
	result = doTest(std::vector<int> {}, std::vector<int> {-4}, 4);
	std::cout << "Test 34: " << result << std::endl;
	assert(result == "<(8, <>)>");

	//Test 35
	result = doTest(std::vector<int> {6, -10}, std::vector<int> {}, 10);
	std::cout << "Test 35: " << result << std::endl;
	assert(result == "<(7, <>)(14, <>)(15, <>)>");

	//Test 36
	result = doTest(std::vector<int> {6, 7, -10}, std::vector<int> {}, 10);
	std::cout << "Test 36: " << result << std::endl;
	assert(result == "<(14, <>)(15, <>)>");

	//Test 37
	result = doTest(std::vector<int> {6, 7, 14, -10}, std::vector<int> {}, 10);
	std::cout << "Test 37: " << result << std::endl;
	assert(result == "<(15, <>)>");

	//Test 38
	result = doTest(std::vector<int> {-18}, std::vector<int> {14, 15, 22, 23}, 18);
	std::cout << "Test 38: " << result << std::endl;
	assert(result == "<(9, <14>)(11, <15>)(25, <22>)(27, <23>)>");

	//Test 39
	result = doTest(std::vector<int> {14, 15, 22, 23}, std::vector<int> {-18}, 18);
	std::cout << "Test 39: " << result << std::endl;
	assert(result == "<(9, <14>)(11, <15>)(25, <22>)(27, <23>)>");

	//Test 40
	result = doTest(std::vector<int> {-17}, std::vector<int> {14, 15}, 17);
	std::cout << "Test 40: " << result << std::endl;
	assert(result == "<(13, <>)(19, <14, 15>)(21, <>)(22, <>)>");

	//Test 41
	result = doTest(std::vector<int> {8, 15, 18}, std::vector<int> {-4}, 4);
	std::cout << "Test 41: " << result << std::endl;
	assert(result == "<(11, <8>)>");

	//Test 42
	result = doTest(std::vector<int> {-7}, std::vector<int> {10, 17}, 7);
	std::cout << "Test 42: " << result << std::endl;
	assert(result == "<(2, <>)(3, <>)(11, <>)(21, <10, 17>)>");

	//Test 43
	result = doTest(std::vector<int> {15, 16, 23}, std::vector<int> {-26}, 26);
	std::cout << "Test 43: " << result << std::endl;
	assert(result == "<(10, <15, 23>)(12, <16, 23>)(22, <>)(30, <>)(31, <>)>");

	//Test 44
	result = doTest(std::vector<int> {-29}, std::vector<int> {25, 18, 11}, 29);
	std::cout << "Test 44: " << result << std::endl;
	assert(result == "<(8, <11, 18, 25>)>");

	//Test 45
	result = doTest(std::vector<int> {-4}, std::vector<int> {8, 15, 22}, 4);
	std::cout << "Test 45: " << result << std::endl;
	assert(result == "<(25, <8, 15, 22>)>");

	//Test 46
	result = doTest(std::vector<int> {-13}, std::vector<int> {}, 13);
	std::cout << "Test 46: " << result << std::endl;
	assert(result == "<(9, <>)(17, <>)>");

	//Test 47
	result = doTest(std::vector<int> {}, std::vector<int> {-13}, 13);
	std::cout << "Test 47: " << result << std::endl;
	assert(result == "<(9, <>)(17, <>)>");

	//Test 48
	result = doTest(std::vector<int> {-4}, std::vector<int> {8, 15, 22, 25}, 4);
	std::cout << "Test 48: " << result << std::endl;
	assert(result == "<(18, <8, 15>)>");

	//Test 49
	result = doTest(std::vector<int> {26}, std::vector<int> {23, 15}, 26);
	std::cout << "Test 49: " << result << std::endl;
	assert(result == "<(10, <15, 23>)(22, <>)>");

	//Test 50
	result = doTest(std::vector<int> {10, 18}, std::vector<int> {7}, 7);
	std::cout << "Test 50: " << result << std::endl;
	assert(result == "<(11, <>)(23, <10, 18>)>");

	//Test 52
	result = doTest(std::vector<int> {-15}, std::vector<int> {10}, 10);
	std::cout << "Test 52: " << result << std::endl;
	assert(result == "<(14, <>)(19, <15>)>");

	//Test 53
	result = doTest(std::vector<int> {18}, std::vector<int> {22}, 18);
	std::cout << "Test 53: " << result << std::endl;
	assert(result == "<(14, <>)(15, <>)>");

	//Test 54
	result = doTest(std::vector<int> {10}, std::vector<int> {15}, 15);
	std::cout << "Test 54: " << result << std::endl;
	assert(result == "<(18, <>)(19, <>)>");

	//Test 55
	result = doTest(std::vector<int> {-22}, std::vector<int> {-26, -27}, 22);
	std::cout << "Test 55: " << result << std::endl;
	assert(result == "<(17, <>)(18, <>)(24, <26, 27>)(25, <>)>");

	//Test 56
	result = doTest(std::vector<int> {-2}, std::vector<int> {-6, -7, -14, -15}, 2);
	std::cout << "Test 56: " << result << std::endl;
	assert(result == "<(2, <6, 7, 14, 15>)>");

	//Test 57
	result = doTest(std::vector<int> {-2}, std::vector<int> {}, 2);
	std::cout << "Test 57: " << result << std::endl;
	assert(result == "<(6, <>)(7, <>)>");

	//Test 58
	result = doTest(std::vector<int> {}, std::vector<int> {-30}, 30);
	std::cout << "Test 58: " << result << std::endl;
	assert(result == "<(25, <>)(26, <>)>");

	//Test 59
	Board myBoard1(NULL, NULL);
	std::cout << "Test 59:" << std::endl;

	for (int i = 1; i < 33; ++i)
	{
		std::cout << "Remove checker at " << i << std::endl;
		myBoard1.removeChecker(i);
		assert(myBoard1.content[i - 1] == "E");
	}

	//Test 60
	Board myBoard2(NULL, NULL);
	myBoard2.emptyBoard();
	myBoard2.content[31] = "P1";
	myBoard2.content[26] = "P2";
	myBoard2.content[27] = "P2";
	assert(myBoard2.canPlayerMove(1), false);
	std::cout << "Test 60: Player one cannot move" << std::endl;
	
	//Test 61
	Board myBoard3(NULL, NULL);
	myBoard3.emptyBoard();
	myBoard3.content[0] = "P2";
	myBoard3.content[4] = "P1";
	myBoard3.content[5] = "P1";
	assert(myBoard3.canPlayerMove(2), false);
	std::cout << "Test 61: Player two cannot move" << std::endl;

	//Test 62
	Board myBoard4(NULL, NULL);
	myBoard4.emptyBoard();
	myBoard4.content[31] = "P1";
	assert(myBoard4.canPlayerMove(1), true);
	std::cout << "Test 62: Player one can move" << std::endl;

	//Test 63
	Board myBoard5(NULL, NULL);
	myBoard5.emptyBoard();
	myBoard5.content[0] = "P2";
	assert(myBoard5.canPlayerMove(2), true);
	std::cout << "Test 63: Player two can move." << std::endl;
}