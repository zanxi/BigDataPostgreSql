#include "libjson.h"

void from_json(const json& j, key_value_t& kv)
{
  assert(j.is_object());
  assert(j.size() == 1);
  kv.key = j.begin().key();
  kv.value = j.begin().value();
}

void to_json(json& j, const key_value_t& kv)
{
  j = nlohmann::json{
    {kv.key, kv.value}
  };
}

    vec_json_prop SearchIdentVarsAndChange(vec_json_prop vars)    
    {       
        std::string temp;
        for(int i=0; i<vars.size();i++)
        {   
            temp = vars[i].key;        
            for(int j=i; j<vars.size();j++)
            {                            
                if(temp == vars[j].key)
                {
                    vars[j].key+="__"+std::to_string(j);                    
                    logger::WriteMsg("odinary vars: "+ vars[j].key);
                }
            }                        
        }

        return vars;

    }


    map_json_prop libjson::Read_Tab(std::string fn)
    {      
        map_json_prop temp;              
        std::ifstream f("./tables/"+fn+".json", std::ifstream::in);
        json js_in;
        f>>js_in;
        
        vec_json_prop kv_in;    
        js_in.at(fn).get_to(kv_in);        
        //vec_json_prop kv_in_temp = SearchIdentVarsAndChange(kv_in);
        //vec_json_prop kv_in_temp;
        
        //for(auto kv_:kv_in)
        {
          
        }

        temp.insert(std::pair<int,vec_json_prop>(0,kv_in));			    
        return temp;
    }

    std::map<std::string, std::string> libjson::Read_Tab2(std::string fn)
    {      
      std::map<std::string, std::string> temp;
      std::ifstream f("./tables/"+fn+".json", std::ifstream::in);
        json js_in;
        f>>js_in;
        
      std::vector<key_value_t> kv_in;
      //get input object
      js_in.at(fn).get_to(kv_in);
      temp.insert( std::pair<std::string,std::string>(kv_in[0].key,kv_in[0].value) );			    
      //std::cout<<"************ size ="<<kv_in.size()<<"******************************************************"<<"\n";
      for(int i=0; i<kv_in.size();i++)
      {
         //std::cout<<"key = "<<kv_in[i].key<<"; value = "<<kv_in[i].value<<"\n";       
         temp.insert( std::pair<std::string,std::string>(kv_in[i].key,kv_in[i].value) );			    
      }
      return temp;
    }

    void libjson::CreateJsonVarTab()
    {
       std::vector<std::string> tabFiles = csvfile::ReadFiles();
    for(auto fn: tabFiles)
    {
      std::map<int, std::vector<std::string>> tab_ = csvfile::Read_TabMap(fn); 

      nlohmann::json js_out = nlohmann::json::object_t();

      std::vector<key_value_t> kv_;// = tab_[0];
      //kv_.push_back(key_value_t{ tab_[0][0], "integer NOT NULL" });  
      for(int i=0; i<tab_[0].size();i++)
      {     if(tab_[0][i]=="\r")break;     
            if(Str::contains(Str::tolower(tab_[0][i]),"time")!=-1)
                 {                    
                    key_value_t kv{ tab_[0][i], "TIMESTAMP" };  
                    kv_.push_back(kv);
                 }
                 else 
                 {
                    key_value_t kv{ tab_[0][i], "text NOT NULL" };                       
                    kv_.push_back(kv);
                 }
            
            
      }      

      nlohmann::json js_arr = kv_;

      //add to main JSON object
      js_out += {fn, js_arr};

      //save output
      std::ofstream ofs("./tables/"+fn+".json");
      ofs << std::setw(2) << js_out << std::endl;
      ofs.close();

    }

    } 

    void libjson::read()
    {
        std::ifstream f("test.json", std::ifstream::in);
        json j;
        f>>j;
        std::cout<<j<<"\n";
        std::cout<<j.at("cal")<<"\n";
        std::cout<<j.at("months")<<"\n";

        int day = j.at("days");
        std::cout<<day<<"\n";

    }

    void libjson::ReadArray()
    {
        //std::ifstream ifs("test2.json");
        std::string str{R"({ "Main": [ { "obj1": "bar" }, { "obj2": "foo" } ] })"};
        //json js = json::parse(ifs);
        json js = json::parse(str);

        //auto objects{ j.at("Main").get<objects_t>(); }
        //auto objects{ js.at("Main").get<object_t>(); };

        //fmt::printf("{}", objects);

        //return;

       for (json::iterator it = js.begin(); it != js.end(); ++it) 
       {
          //std::cout << it.key() << " : ";
          //std::cout << it.value() << "\n";
       }

       std::map<std::string, std::string> mat;

       if (js.contains("Main"))
       {
          json a = js["Main"];
          for (size_t idx = 0; idx < a.size(); ++idx)
          {
              json o = a.at(idx);
              for (json::iterator it2 = o.begin(); it2 != o.end(); ++it2) 
              {
                 std::cout<<"[1]" << it2.key() << " : ";
                 std::cout<<"[2]" << it2.value() << "\n";
              }
              //std::cout << o << "\n";   
              //map.insert(std::pair<std::string,std::string> (o.key(),std::to_string(o.value()));           
              //map.insert(std::pair<std::string,std::string> (o.key(),std::to_string(o.value())));           
        }
       }      
    }

    void libjson::ReadArray2()
    {
        try
  {
    std::string str{ R"({ "Main": [ { "obj1": "bar" }, { "obj2": "foo" } ] })" };
    json js = json::parse(str);

    std::vector<key_value_t> kv;
    if (js.contains("Main"))
    {
      js.at("Main").get_to(kv);
    }
  }

  catch (std::exception& e)
  {
    std::cout << e.what() << '\n';
  }
    }


// *******************************************************************************************************

    void libjson::ReadArray3()
    {
        try
  {
    std::string str{ R"({ "Main": [ { "obj1": "bar" }, { "obj2": "foo" } ] })" };

    std::ifstream f("test2.json", std::ifstream::in);
        json js_in2;
       f>>js_in2;
      if (js_in2.contains("Main"))
       {
         json js_in = js_in2.at("Main");
    //json js_in = json::parse(str);
    std::cout<<"************ Parser json *****************************************************"<<"\n";

    std::vector<key_value_t> kv_in;

     //get input object
    js_in.at("Main").get_to(kv_in);
    std::cout<<"************ size ="<<kv_in.size()<<"******************************************************"<<"\n";
    for(int i=0; i<kv_in.size();i++)
    {
       std::cout<<"key = "<<kv_in[i].key<<"; value = "<<kv_in[i].value<<"\n";       
    }

    if (js_in.contains("Main"))
    {
      nlohmann::json js_out = nlohmann::json::object_t();

      std::vector<key_value_t> kv_;
      key_value_t kv1{ "obj1", "1" };
      key_value_t kv2{ "obj2", "2" };
      kv_.push_back(kv1);
      kv_.push_back(kv2);

      std::cout<<"******************************************************************"<<"\n";

      nlohmann::json js_arr = kv_;

      //add to main JSON object
      js_out += {"Main", js_arr};

      //save output
      std::ofstream ofs("output.json");
      ofs << std::setw(2) << js_out << std::endl;
      ofs.close();

    }
       }
  }

  catch (std::exception& e)
  {
    std::cout<< "\n ReadJson3\n" << e.what() << '\n';
  }
  

    }

