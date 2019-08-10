#include <iostream>
#include <string>

#include "GReturn.h"
#include "SwipeBehavior.h"
#include "Board.h"

	int main() {

		GReturn ret;
		//if (100 < 1) {
		//	ret = GReturn::FailedReturn();
		//}
		//else
		//{
		//	ret = GReturn::SuccessReturn();
		//}

		//SwipeBehavior* sb = new SwipeBehavior();

		//string b = ret.IsSuccess() == true ? "success" : "failed";
		//string v = "Test ret.IsSucces: " + b;
		//
		//cout << v <<"\n";

		//b = ret.IsFailed() == true ? "success" : "failed";
		//v = "Test ret.IsFailed: " + b;
		//
		//cout << v;

		//ret = sb->Swipe(North);
		//cout << ret.IsFailed();

		//cin >> v;

		Board* board = new Board();
		board->GenerateBoard();

		string v = "";
		//cin >> v;
		char* a = new char('a');
		cin.read(a, 1);
		return 0;

	}

