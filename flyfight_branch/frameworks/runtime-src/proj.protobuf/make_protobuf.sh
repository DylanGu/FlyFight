#!/bin/sh

echo "### Prepare env ..."
filepath=${PWD}
cpp_out_path=${filepath}/pro_out/cpp
java_out_path=${filepath}/pro_out/java

echo "### Begin run protoc ..."
protoc --cpp_out=${cpp_out_path} *.proto
#protoc --java_out=${java_out_path} *.proto
echo "### End run protoc ..."

proj_cpp_path=${filepath}/../Classes/game/data_table/pb

echo "### Begin copy files"
#echo ${proj_cpp_path}

cp ${cpp_out_path}/* ${proj_cpp_path}

echo "### Script end ..."