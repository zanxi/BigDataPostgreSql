# This is a minimal CMakeLists file which includes the Yoctopuce C++ lib.
cmake_minimum_required (VERSION 3.10.2)
project (gendb)

# Adds the executable called "gendb" that is built from the source files "main.cpp".
add_executable (
    gendb main.cpp 
    GenerateDB.cpp    
    libjson.cpp
    logger.cpp
    csvfile.cpp
    datetime.cpp
    data.cpp
    SqlDataBase.cpp
    Utils.cpp

    GenerateDB.h
    libjson.h 
    logger.h 
    csvfile.h 
    datetime.h 
    data.h 
    SqlDataBase.h 
    Utils.h
    
    )


# Adds the Sources subfolder of the Yoctopuce C++ library.
add_subdirectory (/home/zanxi/lib/json-develop/ compiled_json)

# Links the executable to the Yoctopuce C++ library (YoctoLib).
target_link_libraries (gendb LINK_PUBLIC nlohmann_json)
