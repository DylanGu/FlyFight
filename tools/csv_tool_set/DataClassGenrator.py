import csv
import os
import sys
import codecs

gNameList = []
gTypeList = []
gDescriptList = []
gDelimiter = ','
gQuoter = '\"'
gFileName = ''
gFilePath = 'D:\\Workspace\\iwar\\trunk\\res\\data\\obstacles.csv'
gHeadFileName = ''
gCppFileName = ''
gDataClassName = ''
gDataTableClassName = ''
gDataTableContainerVarName = ''

def getPadding(n):
	return ("  " * n)

def getFileName(file_path):
	file_name = os.path.basename(file_path)
	return file_name.split('.')[0]

def getCSVStructure(file_path):
	row_no = 0
	global gFileName
	global gFilePath
	gFileName = getFileName(file_path)
	gFilePath = file_path

	with open(gFilePath, newline='', encoding="utf-8") as csvfile:
		rowList = csv.reader(csvfile, delimiter=gDelimiter, quotechar='\"')
		for row in rowList:
			global gNameList
			global gTypeList
			global gDescriptList
			if row_no == 0:
				gNameList = row
			elif row_no == 1:
				gTypeList = row
			elif row_no == 2:
				gDescriptList = row
			row_no = row_no + 1
	no = 0
	for type in gTypeList:
	 	if type.lower() == "boolean" or type.lower() == "bool":
	 		gTypeList[no] = "bool"
	 	elif type.lower() == "int32_t" or type.lower() == "int32" or type.lower() == "int_32":
	 		gTypeList[no] = "int_32"
	 	elif type.lower() == "int16_t" or type.lower() == "int16" or type.lower() == "int_16":
	 		gTypeList[no] = "int_16"
	 	elif type.lower() == "int8_t" or type.lower() == "int8" or type.lower() == "int_8":
	 		gTypeList[no] = "int_8"
	 	elif type.lower() == "uint32_t" or type.lower() == "uint32" or type.lower() == "uint_32":
	 		gTypeList[no] = "uint_32"	
	 	elif type.lower() == "uint16_t" or type.lower() == "uint16" or type.lower() == "uint_16":
	 		gTypeList[no] = "uint_16"	
	 	elif type.lower() == "uint8_t" or type.lower() == "uint8" or type.lower() == "uint_8":
	 		gTypeList[no] = "uint_8"		
	 	elif type.lower() == "array_int":
	 		gTypeList[no] = "std::list<int>"
	 	else:
	 		gTypeList[no] = gTypeList[no].lower() 		
	 	no = no + 1
	#remove BOM '\ufeff'
	gTypeList = [item.lower() for item in gTypeList]
	if gNameList[0][0] == '\ufeff':
		gNameList[0] = gNameList[0][1:]
		if gNameList[0][0] == '"' and gNameList[0][-1] == '"':
			gNameList[0] = gNameList[0][1:-1]
	#print(gNameList[0])
	return

#code for data class
def GeneratorDataClassCode():
	print(gFilePath)
	print("Var Type:")
	print(gTypeList)
	print("Var Name:")
	print(gNameList)
	print("Var Descript:")
	print(gDescriptList)
	global gHeadFileName
	global gCppFileName
	global gDataClassName
	global gDataTableClassName
	global gDataTableContainerVarName
	gHeadFileName = gFileName.lower() + "_data_table.h"
	gCppFileName = gFileName.lower() + "_data_table.cpp"
	gDataClassName = gFileName.title() + "Data"
	gDataTableClassName = gFileName.title() + "DataTable"
	gDataTableContainerVarName = gFileName.lower() + "_data_table_"

	file = open("./" + gHeadFileName, mode = 'w', encoding="utf")

	#code for precompiler
	file.write("#ifndef " + gFileName.upper() + "_DATA_TABLE_H\n")
	file.write("#define " + gFileName.upper() + "_DATA_TABLE_H\n\n")
	file.write("#include <string>\n")
	file.write("#include <vector>\n")
	file.write("#include <list>\n")
	file.write("#include <map>\n")
	file.write("#include \"engine/base/basictypes.h\"\n")
	file.write("using namespace std;\n")
	file.write("\n")
	file.write("class " + gDataClassName + "\n")
	file.write("{\n")
	file.write("public:\n")

	#code for geter seter
	var_num = 0;
	for var_name in gNameList:
		var_type = gTypeList[var_num]
		var_des = gDescriptList[var_num]
		var_num = var_num + 1
		file.write(getPadding(1) + "/*" + var_des + "*/\n")
		print(var_type.lower() + ":::" + var_name)
		if var_type == "string" or var_type == "std::list<int>":
			file.write(getPadding(1) + var_type.lower() + "& Get" + var_name[0].upper() + var_name[1:] + "()\n")
		else:
			file.write(getPadding(1) + var_type.lower() + " Get" + var_name[0].upper() + var_name[1:] + "()\n")
		file.write(getPadding(1) + "{\n")
		file.write(getPadding(2) + "return " + var_name + ";\n")
		file.write(getPadding(1) + "}\n")

	file.write("private:\n")
	#code for var
	var_num = 0;
	for var_name in gNameList:
		var_type = gTypeList[var_num]
		var_des = gDescriptList[var_num]
		var_num = var_num + 1
		file.write(getPadding(1) + var_type.lower() + "\t\t" + var_name + ";\n")

	file.write("\n" + getPadding(1) + "friend class " + gDataTableClassName + ";\n")
	file.write("};\n")
	#file.write("#endif")
	file.close()
	return

#data for data_table class
def GeneratorDataTableClassCode():
	file = open("./" + gHeadFileName, mode = 'a', encoding="utf-8")

#data table class header
	file.write("\n")
	file.write("class " + gDataTableClassName + "\n")
	file.write("{\n")

	#code for constructor and deconstructor
	file.write("public:\n")
	file.write(getPadding(1) + gDataTableClassName + "();\n")
	file.write(getPadding(1) + "~" + gDataTableClassName + "();\n")

	#code for init method
	file.write(getPadding(1) + "bool InitWithFileName(const char *file_name);\n")

	#code for Get by id method
	file.write(getPadding(1) + gDataClassName + "* Get" + gFileName.title() + "(" + gTypeList[0].lower() + " " + gNameList[0].lower() + ");\n\n")

	#code for protected(parse row) method
	file.write("protected:\n")
	file.write(getPadding(1) + "void parseRow(vector<string> &row);\n\n")

	#code for membervirable
	file.write("private:\n")
	file.write(getPadding(1) + "vector<" + gDataClassName + "*> *" + gDataTableContainerVarName + ";\n\n");
	file.write(getPadding(1) + "map<" + gTypeList[0].lower() + ", int> index_map_;\n")
	file.write("};\n")
	file.write("#endif\n")
	file.close()
#end of .h file
	return

#Code for cpp file
def GeneratorDataTableClassCPPCode():
	file = open("./" + gCppFileName, mode = 'w', encoding="utf-8")
	#file = codecs.open("./" + gCppFileName, 'w', 'utf-8')
	#code for precompiler header
	file.write("#include \"" + gHeadFileName + "\"\n\n")
	file.write("#include \"engine/csvparser/csv_file_parser.h\"\n")
	file.write("#include \"engine/base/utils_string.h\"\n")
	file.write("#include <cocos2d.h>\n\n")

	#code for constructor
	file.write(gDataTableClassName + "::" + gDataTableClassName + "()\n")
	file.write("{\n")
	file.write(getPadding(1) + gDataTableContainerVarName + " = new " + "vector<" + gDataClassName + "*>();\n");
	file.write("}\n\n")

	#code for deconstructor
	file.write(gDataTableClassName + "::~" + gDataTableClassName + "()\n")
	file.write("{\n")
	file.write(getPadding(1) + "for (vector<" + gDataClassName + "*>::iterator itr = " + gDataTableContainerVarName + "->begin();\n")
	file.write(getPadding(1) + "itr != " + gDataTableContainerVarName + "->end(); ++itr)\n")
	file.write(getPadding(1) + "{\n")
	file.write(getPadding(2) + "delete *itr;\n")
	file.write(getPadding(1) + "}\n")
	file.write(getPadding(1) + "delete " + gDataTableContainerVarName + ";\n")
	file.write("}\n\n")	

	#code for init method
	file.write("bool " + gDataTableClassName + "::InitWithFileName(const char *file_name)\n")
	file.write("{\n")
	file.write(getPadding(1) + "CSVFileParser csv_file;\n")
	file.write(getPadding(1) + "CSVFileRow csv_row;\n")
	file.write(getPadding(1) + "CCLog(\"Loading csv file %s\", file_name);\n\n")
	file.write(getPadding(1) + "if(!csv_file.InitWithFileName(file_name))\n")
	file.write(getPadding(2) + "return false;\n\n")
	file.write(getPadding(1) + "while(csv_file.IsHasMoreLine())\n")
	file.write(getPadding(1) + "{\n")
	file.write(getPadding(2) + "csv_file.GetNextRow(csv_row);\n")
	file.write(getPadding(2) + "parseRow(csv_row);\n")
	file.write(getPadding(1) + "}\n\n")
	file.write(getPadding(1) + "return true;\n")
	file.write("}\n\n")

	#code for getObstacles method
	#file.write(getPadding(1) + gDataClassName + "* Get" + gFileName.title() + "(" +  + ");\n\n")
	file.write(gDataClassName + "* " + gDataTableClassName + "::Get" + gFileName.title() + "(" + gTypeList[0].lower() + " " + gNameList[0].lower() + ")\n")
	file.write("{\n")
	file.write(getPadding(1) + "map<" + gTypeList[0].lower() + ", int>::iterator index = index_map_.find(" + gNameList[0].lower() + ");\n")
	file.write(getPadding(1) + "if(index == index_map_.end())\n")
	file.write(getPadding(1) + "{\n")
	file.write(getPadding(2) + "CCLog(\"" + gDataTableClassName + " TypeId not found! Id: %d\", " + gNameList[0].lower() + ");\n")
	file.write(getPadding(2) + "assert(false);\n")
	file.write(getPadding(2) + "return NULL;\n")
	file.write(getPadding(1) + "}\n")
	file.write(getPadding(1) + "return " + gDataTableContainerVarName + "->at(index->second);\n")
	file.write("}\n\n")

	#code for parseRow
	file.write("void " + gDataTableClassName + "::parseRow(vector<string> &row)\n")
	file.write("{\n")
	file.write(getPadding(1) + "int i = 0;\n")
	file.write(getPadding(1) + gDataClassName + " *data = new " + gDataClassName + "();\n")
	
	#assing var
	no = 0;
	for var in gNameList:
		type = gTypeList[no].lower()
		if type == "int":
			file.write(getPadding(1) + "data->" + var + " = ")
			file.write("String2Int(row[i++])")
		elif type == "int_32":
			file.write(getPadding(1) + "data->" + var + " = ")
			file.write("String2Int32(row[i++])")
		elif type == "int_16":
			file.write(getPadding(1) + "data->" + var + " = ")
			file.write("String2Int16(row[i++])")
		elif type == "int_8":
			file.write(getPadding(1) + "data->" + var + " = ")
			file.write("String2Int8(row[i++])")
		elif type == "uint_32":
			file.write(getPadding(1) + "data->" + var + " = ")
			file.write("String2UInt32(row[i++])")
		elif type == "uint_16":
			file.write(getPadding(1) + "data->" + var + " = ")
			file.write("String2UInt16(row[i++])")
		elif type == "uint_8":
			file.write(getPadding(1) + "data->" + var + " = ")
			file.write("String2UInt8(row[i++])")
		elif type == "string":
			file.write(getPadding(1) + "data->" + var + " = ")
			file.write("row[i++]")
		elif type == "bool" or type == "boolean":
			file.write(getPadding(1) + "data->" + var + " = ")
			file.write("String2Bool(row[i++])")
		elif type == "float":
			file.write(getPadding(1) + "data->" + var + " = ")
			file.write("String2Float(row[i++])")
		elif type == "std::list<int>":
			file.write(getPadding(1) + "getIntListFromString(row[i++], " + "data->" + var + ")")
		file.write(";\n")
		no = no + 1
	file.write(getPadding(1) + "index_map_.insert(pair<" + gTypeList[0].lower() + ", int>(data->" + gNameList[0] + ", " + gDataTableContainerVarName + "->size()));\n")
	file.write(getPadding(1) + gDataTableContainerVarName + "->push_back(data);\n")
	file.write("}\n\n")	

	file.close()
	return

def getFileList(file_path):
	file_path = str(file_path)
	if file_path == "":
		return []
	file_path = file_path.replace("\\", "/")
	if file_path[-1] != "/":
		file_path = file_path + "/"
	file_list = os.listdir(file_path)
	result_list = [x for x in file_list if os.path.isfile(file_path + x)]
	return result_list

def getDirList(file_path):
	file_path = str(file_path)
	if file_path == "":
		return []
	file_path = file_path.replace("\\", "/")
	if file_path[-1] != "/":
		file_path = file_path + "/"
	file_list = os.listdir(file_path)
	result_list = [x for x in file_list if os.path.isdir(file_path + x)]
	return result_list

def getFileListWithTypeName(file_path, type_name):
	file_list = getFileList(file_path)
	result_list = [x for x in file_list if x.endswith(type_name)]
	return result_list

def handInput():
	print(sys.argv[1])
	if os.path.isdir(sys.argv[1]):	
		csv_list = getFileListWithTypeName(sys.argv[1], "csv")
		
		for csv_file in csv_list:
			getCSVStructure(sys.argv[1] + "/" + csv_file)
			GeneratorDataClassCode()
			GeneratorDataTableClassCode()
			GeneratorDataTableClassCPPCode()
	else:
		getCSVStructure(sys.argv[1])
		GeneratorDataClassCode()
		GeneratorDataTableClassCode()
		GeneratorDataTableClassCPPCode()
	return

handInput()
#getCSVStructure(gFilePath)
#GeneratorDataClassCode()
#GeneratorDataTableClassCode()
#GeneratorDataTableClassCPPCode()