#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
//#include <stdio.h>
#include <string>
#include <iostream>
#include <windows.h>
#include <vector>
#include <chrono>
#include <fstream>
#include <map>
#include <ctime>
#include <iomanip>
#include <thread>
#include <mutex>
#include <algorithm>
#include <cmath>
//#include <cpr/cpr.h>

const double PI = std::acos(-1);

int randomInt(int min, int max);
float randomFloat(int min, int max);
void rusText();
int nod(int a, int b);
int nok(int a, int b);
int createInt(bool flag, const char* text);
int createInt(bool flag);
float createFloat(bool flag, const char* text);
float createFloat(bool flag);
int fibonacci(int n);
std::vector<std::string> splitString(const std::string& str, const std::string& del);
void printVector(const std::vector<int>& vec);
void printVector(const std::vector<float>& vec);
void printVector(const std::vector<std::string>& vec);
std::vector<float> vectorStrToFloat(const std::vector<std::string>& vectorString);
std::vector<int> vectorStrToInt(const std::vector<std::string>& vectorString);
void swap(int* a, int* b);
int factorial(int a);
int selectOrderNotRepetition(int n, int m);
int selectOrderRepetition(int n, int m);
int selectNotOrderNotRepetition(int n, int m);
int selectNotOrderRepetition(int n, int m);
int lengthString(const char* str);
int getCurrentYear();
struct stateElement;
bool isLackNum(std::string text);
std::string checkName(std::string input);
std::string checkDate(std::string input);
int checkPayment(std::string input);
std::string stringToLower(std::string input);
std::string delSpace(std::string text);
bool isDigit(std::string input, bool checkNumPhone = false);
class Point {
	double x;
	double y;
	Point() = default;
public:
	void setX(double pointX);
	void setY(double pointY);
	double getX();
	double getY();
	std::string toString();
	Point(double x, double y);

	
};

struct point { 
	double x; 
	double y;
	void constructor(double inputX, double inputY) {
		x = inputX;
		y = inputY;
	}
	std::string toString() {
		return "(" + std::to_string(x) + ";" + std::to_string(y) + ")";
	}
	double equals(point inputPoint) {
		if (x == inputPoint.x && y == inputPoint.y)
			return true;
		return false;
	}
};
