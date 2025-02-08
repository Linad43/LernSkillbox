#pragma once

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <iostream>
#include <windows.h>

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