#pragma once
#include "stdafx.h"
#include "Exercise.h"
#include <string>

//EXERCISE 18
//
//Write a program that asks the user to type the value of N and writes this picture :
//
//N = 1
//*
//N = 2
//* *
//*
//N = 3
//* **
//**
//*

class Exercise18 : Exercise
{
public:
	void mySolution();
	std::string createTriangleString(const int i_num);

private:
	int askUserForNumber();
	void outputString(const std::string &i_string);
};
