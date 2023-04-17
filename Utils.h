#ifndef UTILS_H
#define UTILS_H


#include <iostream>
#include <map>
#include <string>

#include "logger.h"

struct db_propeties{
    std::string field_name;
    std::string field_type;

};

struct key_value_t
{
  std::string key;
  std::string value;
};

class Str{
  public:
  static std::string tolower(std::string str);
  static std::string RandomName(int numSymbols, std::string type1, std::string type2);
  static int contains(std::string str, std::string substr);    
      
};

typedef std::vector<db_propeties> vec_db_prop;
typedef std::map<int,vec_db_prop> map_db_prop;

typedef std::vector<key_value_t> vec_json_prop;
typedef std::map<int,vec_json_prop> map_json_prop;


#endif