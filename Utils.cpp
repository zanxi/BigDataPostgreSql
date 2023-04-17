#include "Utils.h"

  std::string Str::tolower(std::string str)
    {         
        std::string temp = "";
        for(int i=0;i<str.size();i++)
        {
            temp+=std::tolower(str[i]);
        }
        //std::cout<< " lower register stroka: "<<temp << "\n";
        // logger::WriteMsg(" lower register stroka: "+temp);
        return temp;
    }

    int Str::contains(std::string str, std::string substr)    
    {
       size_t pos = str.find(substr);
       if (pos != std::string::npos) return pos;
       else return -1;
    }
    
    std::string Str::RandomName(int numSymbols, std::string type1, std::string type2)
    {
      // srand( (unsigned)time(NULL) );
      std::string str = "";
      for(int i=0; i<numSymbols;i++)
      {
        //str+=(char)(((rand()%2)==0)?(65+rand()%26):(rand()%2)*(97+rand()%26));
        //str+=(char)(((rand()%2)==0)?(66+rand()%24):(rand()%2)*(98+rand()%24));
        if(((rand()%2)==0))
        {
            str+=(char)(67+rand()%24);            
        }
        else
        {
           str+=(char)(98+rand()%24);            
        }
        //str+=(char)(((rand()%2)==0)?(66+rand()%24):(rand()%2)*(98+rand()%24));
      }
      return type1 + str + type2;

    }


