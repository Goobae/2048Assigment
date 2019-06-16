#pragma once

#include "GReturn.h"

GReturn::GReturn() {
	_result = false;	
	Message = "";
}

GReturn::GReturn(bool result) {
	_result = result;
	Message = "";
}

GReturn::GReturn(bool result, string message) {
	_result = result;
	Message = message;
}

GReturn::GReturn(string error = ""){
	_result = false;
	Message = error;
}

GReturn::~GReturn()
{
	_result = NULL;
	Message = "";
}

bool GReturn::IsFailed()
{
	return _result == false;
}

bool GReturn::IsSuccess()
{
	return _result == true;
}
