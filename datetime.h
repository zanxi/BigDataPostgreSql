#ifndef DATETIME_H
#define DATETIME_H

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <stdexcept>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <chrono>

#include <bits/stdc++.h>

using namespace std;

class datetime{
public:
static std::string DataZ;
static long int cntTime;

static std::string utcExample();
static long int string2timestamp(const string &str);
static string unixTimeToHumanReadable(long int seconds);
static std::string GenerateTime();

};

#endif
