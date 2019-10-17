
#specify the oldest version of cmake that your CMakeLists.txt will work for
cmake_minimum_required(VERSION 3.5.1)

#create our project and specify what language it is for
#ours is for C in this case
project(FindDeterminant LANGUAGES C)


#these are the source files that make up your project
set (SOURCES main.c matrix.c matrix.h) #add any other sources you have after matrix.h

#create the executable from the sources
add_executable(FindDeterminant ${SOURCES}) 


#turn on warnings and treat warnings as errors
target_compile_options(FindDeterminant PRIVATE -Wall -Werror)


#name the executable FindDeterminant.out
set_target_properties(FindDeterminant
        PROPERTIES
        OUTPUT_NAME "FindDeterminant"
        SUFFIX ".out")