#pragma once
#include <string>


using namespace std;

class GReturn
{
public:

	GReturn();
	GReturn(bool result);
	GReturn(string error);
	GReturn(bool result, string error);

	~GReturn();

	bool IsFailed();
	bool IsSuccess();
	string Message;
	
	static GReturn FailedReturn(string error = "") {
		GReturn ret = GReturn(error);
		ret._result = false;
		return ret;
	}

	static GReturn SuccessReturn(string error = "") {
		GReturn ret = GReturn(error);
		ret._result = true;
		return ret;
	}
	   	  
private:
	bool _result;
};