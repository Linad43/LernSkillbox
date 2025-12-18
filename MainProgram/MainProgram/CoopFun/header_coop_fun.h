#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
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

int random(int min, int max);
float random(float min, float max);
void rusText();
int nod(int a, int b);
int nok(int a, int b);
int createInt(bool flag, const char* text);
int createInt(bool flag);
float createFloat(bool flag, const char* text);
float createFloat(bool flag);
int fibonacci(int num);
std::vector<std::string> splitString(const std::string& str, const std::string& del);
void printVector(const std::vector<int>& numbers);
void printVector(const std::vector<float>& numbers);
void printVector(const std::vector<std::string>& numbers);
std::vector<float> vectorStrToFloat(const std::vector<std::string>& vectorString);
std::vector<int> vectorStrToInt(const std::vector<std::string>& vectorString);
void swap(int* a, int* b);
int factorial(int a);
int selectOrderNotRepit(int n, int m);
int selectOrderRepit(int n, int m);
int selectNotOrderNotRepit(int n, int m);
int selectNotOrderRepit(int n, int m); 
int lenghtStr(const char* str);
int getCurrentYear();
struct stateElement;
bool lackNum(std::string text);
std::string checkName(std::string input);
std::string checkDate(std::string input);
int checkPayment(std::string input);
std::string strToLow(std::string input);
std::string delSpace(std::string text);

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
