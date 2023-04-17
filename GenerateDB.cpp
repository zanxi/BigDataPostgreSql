#include <unistd.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <dirent.h>
#include <sys/stat.h>

#include "GenerateDB.h"
#include "logger.h"
#include "Utils.h"


struct stat sb;

//namespace fs = std::filesystem; // Для краткости

long GenerateDB::numColumns=50;

void GenerateDB::CreateFileCsv(std::string pathFolderDB)
{
    //setlocale(LC_TYPE, "rus");
    srand( (unsigned)time(NULL) );
            
    char username[1024] = {0};
    //fs::create_directory(pathFolderDB);
    //mkdir(pathFolderDB);    
    //do_mkdir(pathFolderDB.c_str());

    
    if (stat(pathFolderDB.c_str(), &sb) == 0 && S_ISDIR(sb.st_mode))
    {
       logger::WriteMsgError("Folder <<<"+pathFolderDB+">>> exists !!!!!!!!!!!!"); 
       return;
    }

    //const int dir_err = mkdir("foo", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    //if (-1 == dir_err)
    {
        //logger::WriteMsgError("Folder <<<"+pathFolderDB+">>> NOT Created"); 
        //printf("Error creating directory!n");
        //exit(1);
    }

    std::string mkdir_create = "mkdir -p "+pathFolderDB;
    const int dir_err = system(pathFolderDB.c_str());
    if (-1 == dir_err)
    {
        logger::WriteMsgError("Folder <<<"+pathFolderDB+">>> NOT Created"); 
       //printf("Error creating directory!n");
       //exit(1);
    }

    //logger::WriteMsgError("Folder <<<"+pathFolderDB+">>> exists");     
}

void GenerateDB::CreateFolder(std::string pathFolderDB)
{      
    logger::WriteMsg("Operation - Create Folder !!!!!!");   
    if (stat(pathFolderDB.c_str(), &sb) == 0 && S_ISDIR(sb.st_mode))
    {
       logger::WriteMsgError("Folder <<<"+pathFolderDB+">>> exists !!!!!!!!!!!!"); 
       return;
    }

    //const int dir_err = mkdir("foo", S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
    //if (-1 == dir_err)
    {
        //logger::WriteMsgError("Folder <<<"+pathFolderDB+">>> NOT Created"); 
        //printf("Error creating directory!n");
        //exit(1);
    }

    //std::string mkdir_create = "mkdir -p "+pathFolderDB+"/";
    std::string str_cmd = "mkdir -p "+pathFolderDB+"/";
    const int dir_err = system(str_cmd.c_str());
    if (-1 == dir_err)
    {
        logger::WriteMsgError("Folder <<<"+pathFolderDB+">>> NOT Created"); 
       //printf("Error creating directory!n");
       //exit(1);
    }
    else{
            logger::WriteMsgError("Folder Created!!!!!!!!!!!!!!!!"); 
    }

    //logger::WriteMsgError("Folder <<<"+pathFolderDB+">>> exists");     
}

std::vector<std::string> GenerateDB::GenerateVariablesData(
    int numColumns, 
    std::string pref1, 
    std::string pref2)
{
    std::vector<std::string> temp;
    for(int i=0;i<numColumns;i++)
       {
           std::string r_ = Str::RandomName(3,pref1,pref2);
           if(rand()%20==0)r_+="Time";
           temp.push_back(r_);
           //logger::WriteMsg("("+std::to_string(numColumns)+") : "+r_);
           //std::cout<<"("<<(i+40)<<") - "<< (char)(i+40)<<" | ";
       }
       return temp;
}

void GenerateDB::CsvGenerateData(std::string tabF, std::vector<std::string> column)
{    
    std::ofstream out;        
    out.open(tabF,std::ios::app);
    //ou+t.open(fn);
    if(out.is_open())
    {       
        std::string cols = ""; 
        for(int i=0; i<column.size();i++)
        {
            cols += column[i]+";";
        }
        //cols += column[column.size()-1]+";";        
        //out<< cols <<std::endl;//<<"\r\n";        
        out<< cols <<"\r\n";        

        int nRows = 1+(rand()%150);
        std::string dataRow = ""; 
        for(int j=0;j<nRows;j++)
        {
        std::string dataRow = ""; 
        for(int i=0; i<column.size();i++)
        {
            dataRow += std::to_string(rand()%20000)+";";
        }
        //cols += column[column.size()-1]+";";
        //out<< dataRow<<std::endl;//<<"\r\n"; 
        out<< dataRow<<"\r\n"; 
        //dataRow += "\n";
        }
        //out<< dataRow<<"\n";        
        
        
    }
    out.close();
}

void GenerateDB::CreateFolderDB()
{
      std::string folder = "./vartab/";
        CsvGenerateData(folder+"SvodkaData",GenerateVariablesData(10,"Data_","_Experiment"));
        CsvGenerateData(folder+"Remission",GenerateVariablesData(100,"Mi","_Remission"));
        CsvGenerateData(folder+"Annigilation",GenerateVariablesData(200,"Sub","_Pion"));
        CsvGenerateData(folder+"ActionTime",GenerateVariablesData(130,"Sub","_Recom"));
        CsvGenerateData(folder+"DevPart",GenerateVariablesData(50,"NML","_Particles"));
        CsvGenerateData(folder+"Material",GenerateVariablesData(10,"End_","_Work"));
        //CsvGenerateData("./vartab2/Material",GenerateVariablesData(80,"","_"));
}