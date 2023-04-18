#ifndef SQLDATABASE_H
#define SQLDATABASE_H
#include <iostream>
#include <map>
#include <vector>

#include "libjson.h"

const std::string create_table = "CREATE TABLE IF NOT EXISTS ";
const std::string create_table_end = "WITH (OIDS=FALSE,MACS=FALSE);";
//const std::string create_table ="INSERT INTO products " + " VALUES"; 

class SqlDataBase
{
public:     
    static std::string sql_script_f;
    
    static void CreateDataBase();
    static std::string InsertStrokaFieldsNames(std::vector<std::string> columns_);
    static std::string InsertStrokaValues(
    std::vector<std::string> columns_Name, std::vector<std::string> columns_);
    static std::string InsertStrokaValuesRandom(
          std::vector<std::string> columns_Name, std::vector<std::string> columns_);

    static void TableInsert(std::string tab_fn = "RMilkSettings");
    static void AllTablesInsert();
     // delete tables
    static void DropTables();
};

#endif