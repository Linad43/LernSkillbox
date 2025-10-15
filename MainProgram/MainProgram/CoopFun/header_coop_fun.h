#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include <windows.h>
#include <vector>
#include <chrono>

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
