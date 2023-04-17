#ifndef LIBJSON_H
#define LIBJSON_H


#include <iostream>
//#include <fmt/ranges.h>
#include <map>
#include <vector>
#include "nlohmann/json.hpp"
#include <fstream>
#include <string>

#include "csvfile.h"
#include "Utils.h"

using json = nlohmann::json;


void from_json(const json& j, key_value_t& kv);
void to_json(json& j, const key_value_t& kv);

class libjson
{
    public:

    static map_json_prop Read_Tab(std::string fn = "RFeedSettings");
    static std::map<std::string, std::string> Read_Tab2(std::string fn = "RFeedSettings");
    static void CreateJsonVarTab();
    static void read();
    static void ReadArray();
    static void ReadArray2();

// *******************************************************************************************************

    static void ReadArray3();


};

#endif