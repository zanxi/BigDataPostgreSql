#include "SqlDataBase.h"

    std::string SqlDataBase::sql_script_f="";

    void  SqlDataBase::CreateDataBase()
    {         
         std::vector<std::string> tabFiles = csvfile::ReadFiles();
         

         for(auto fn:tabFiles)  {
             std::cout<< "sql: " << fn << "\n";
             map_json_prop tab_ = libjson::Read_Tab(fn);         
             std::cout<< "size: " << tab_.size() << "\n";
             
             std::string sql_script = create_table+ " "+ fn + "(";

             for (int i=0; i< tab_[0].size()-1;i++ ) 
             {
                 if(Str::contains(Str::tolower(tab_[0][i].key),"time")!=-1)
                 {
                    sql_script += tab_[0][i].key+" "+"TIMESTAMP"+",\n";                   
                 }
                 else 
                 {
                    sql_script += tab_[0][i].key+" "+tab_[0][i].value+",\n";                 
                 }
             }            
             sql_script += tab_[0][tab_[0].size()-1].key+" "+tab_[0][tab_[0].size()-1].value+",\n";                 
             //std::map<std::string,std::string>::iterator it = tab_.begin();             
             sql_script += " CONSTRAINT "+ fn +"_pkey PRIMARY KEY ("+(tab_[0][0].key)+"))";
             sql_script += " " + create_table_end;

             //std::cout << sql_script << "\n\n";
             logger::WriteMsg("   ");
             //logger::WriteMsg(sql_script);
             sql_script_f="sql_script_"+datetime::utcExample()+".sql";
             logger::WriteSqlScript(sql_script,sql_script_f);
         }
    }

    std::string SqlDataBase::InsertStrokaFieldsNames(std::vector<std::string> columns_)
    {
        int sz = columns_.size()-1;
        std::string sql_script="(";                            
        for(int i=0; i<sz-1;i++)
        {     
            sql_script += columns_[i]+",\n";                 
        }      
        sql_script += columns_[sz-1];                 
        sql_script += ")\n";       

        return sql_script;                   
    }


    std::string SqlDataBase::InsertStrokaValues(
    std::vector<std::string> columns_Name, std::vector<std::string> columns_)
    {
        int sz = columns_.size()-1;
        std::string sql_script="(";                            
        sql_script += columns_[0]+",";                 
        for(int i=1; i<sz-1;i++)
        {   
            if(Str::contains(Str::tolower(columns_Name[i]),"time")!=-1)
                 {
                    //sql_script += "to_timestamp('"+columns_[i]+ "', 'dd-mm-yyyy hh24:mi:ss'),";
                    sql_script += datetime::GenerateTime() + ","; 
                 }
                 else 
                 {
                    sql_script += "'"+columns_[i]+ "', ";                 
                 }
        }      

         
        if(Str::contains(Str::tolower(columns_Name[sz-1]),"time")!=-1)
                 {
                    //sql_script += "to_timestamp('"+columns_[i]+ "', 'dd-mm-yyyy hh24:mi:ss'),";
                    sql_script += datetime::GenerateTime();
                 }
                 else 
                 {
                    sql_script += "'"+columns_[sz-1]+ "'";                 
                 } 

                    
                  

        

        sql_script += ")\n";       

        return sql_script;                   
    }

    std::string SqlDataBase::InsertStrokaValuesRandom(
    std::vector<std::string> columns_Name, std::vector<std::string> columns_)
    {
        //srand( (unsigned)time(NULL) );      

        int sz = columns_.size()-1;
        std::string sql_script="(";                            
        sql_script += std::to_string(rand()%10000)+",";                 
        for(int i=1; i<sz-1;i++)
        {   
            if(Str::contains(Str::tolower(columns_Name[i]),"time")!=-1)
                 {
                    //sql_script += "to_timestamp('"+columns_[i]+ "', 'dd-mm-yyyy hh24:mi:ss'),";
                    sql_script += datetime::GenerateTime() + ","; 
                 }
                 else 
                 {
                    sql_script += "'"+std::to_string(rand()%10000)+ "', ";                 
                 }
        }      

         
        if(Str::contains(Str::tolower(columns_Name[sz-1]),"time")!=-1)
                 {
                    //sql_script += "to_timestamp('"+columns_[i]+ "', 'dd-mm-yyyy hh24:mi:ss'),";
                    sql_script += datetime::GenerateTime();
                 }
                 else 
                 {
                    sql_script += "'"+std::to_string(rand()%10000)+ "'";                 
                 } 

        sql_script += ")\n";       

        return sql_script;                   
    }

    void SqlDataBase::TableInsert(std::string tab_fn)
    {         
        std::map<int, std::vector<std::string>> rows_ = csvfile::Read_TabMap(tab_fn);         
        //std::cout << "TableInsert - Size column: "<< rows_.size() << "\n\n";
        std::cout << "TableInsert <<<"+tab_fn+">>> - Size Rows: "<< rows_.size() << "\n\n";
        logger::WriteMsg("TableInsert <<<"+tab_fn+">>> - Size Rows: "+ std::to_string(rows_.size()));
        std::string sql_script = "INSERT INTO " + tab_fn + InsertStrokaFieldsNames(rows_[0]);
        
        if(rows_.size()<2)
        {
            //sql_script += ";";
            //std::cout << ("    ");
            //std::cout << ("<<<<No DATA>>>> <<< RANDOMIZE DATA>>>:" + sql_script);

            logger::WriteMsg("    ");
            logger::WriteMsg("<<<<No DATA>>>> <<< RANDOMIZE DATA>>>:" + sql_script);

            sql_script += " VALUES ";
            for(int n=1;n<50;n++){           
              sql_script += InsertStrokaValuesRandom(rows_[0], rows_[0])+ ",";       
            }
            sql_script +=  InsertStrokaValuesRandom(rows_[0], rows_[0])+";";
            logger::WriteMsg(" <<<<<<Random sql Insert>>>>>  ");
            logger::WriteMsg(sql_script);

            return;
        }
        sql_script += " VALUES ";
        for(int n=1;n<rows_.size()-1;n++){           
           sql_script += InsertStrokaValues(rows_[0], rows_[n])+ ",";       
        }
        sql_script +=  InsertStrokaValues(rows_[0], rows_[rows_.size()-1])+";";
        

        //std::cout<< sql_script << "\n";

        //INSERT INTO products (product_no, name) VALUES (1, 'Cheese'); 
        //INSERT INTO products VALUES (1, 'Cheese');\
        //INSERT INTO products (product_no, name, price) VALUES (1, 'Cheese', 9.99), (2, 'Bread', 1.99), (3, 'Milk', 2.99);
                
        //std::map<std::string,std::string>::iterator it = tab_.begin();             
        //sql_script += "CONSTRAINT "+ fn +"_pkey PRIMARY KEY ("+(tab_[n][0].key)+"))";

        logger::WriteMsg("   ");
        //logger::WriteMsg(sql_script);
        logger::WriteSqlScript(sql_script,sql_script_f);
        
    }

    void SqlDataBase::AllTablesInsert()
    {         
        std::vector<std::string> tabFiles = csvfile::ReadFiles();

         for(auto fn:tabFiles)  
         {
            TableInsert(fn); 
         }
        
        //logger::WriteMsg("   ");
        //logger::WriteMsg(sql_script);
        
    }

     // delete tables
    void SqlDataBase::DropTables()
    {         
        std::vector<std::string> tabFiles = csvfile::ReadFiles();
        std::string sql_script="";

         for(auto fn:tabFiles)  
         {
            sql_script += "DROP TABLE "+fn+";"+"\n"; 
         }
        
        //logger::WriteMsg("   ");
        
        std::string sql_script_del_all_tables = 
        "sql_script_del__"+
        datetime::utcExample()+
        ".sql";
        logger::WriteSqlScript(sql_script,sql_script_del_all_tables);
        
    }
