#include <iostream>
#include <fstream>
#include <map>
#include "nlohmann/json.hpp"
#include <string>
#include <vector>

//#include "csvread.h"
//#include "libjson.h"
#include "SqlDataBase.h"
#include "GenerateDB.h"


typedef std::map<int,std::string> map_is;

int main()
{
  srand( (unsigned)time(NULL) );
  
  std::cout<<" **************  CSV *********************   "  << '\n';  

  logger::ClearLog(" -------- write ---------");
  // begin loggirovanie  
  logger::ReadEndMsgNumber();
  logger::WriteMsg(" **************  CSV *********************   ");

  try
  {  
       for(int i=0;i<10;i++)
       {
           //std::cout<< Str::RandomName(15,"Qi","___transmit")<<"\n";
           //std::cout<<"("<<(i+40)<<") - "<< (char)(i+40)<<" | ";
       }
       std::cout<<"\n";
        
      //FD::DeleteFiles("vartab");
      //FD::CreateDir("tables4");

        
      GenerateDB::CreateFolderDB();    
      libjson::CreateJsonVarTab();
      SqlDataBase::DropTables();     
      SqlDataBase::CreateDataBase();     
      SqlDataBase::AllTablesInsert();           
      SqlDataBase::DropTables();           
      /**/
      FD::DeleteFiles("vartab");
      FD::DeleteFiles("tables");

      //GenerateDB::CreateFolder();      
      //GenerateDB::CreateFolderDB();
      
      
  }      

  catch (std::exception& e)
  {
    std::cout<<"ERROR *********************   " << e.what() << '\n';
    logger::WriteMsgError("ERROR  main(): " + std::string(e.what()));

  }
  logger::SaveEndMsgNumber();

  return 0;
}