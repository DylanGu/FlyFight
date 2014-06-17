#ifndef TEST_DATA_TABLE_H
#define TEST_DATA_TABLE_H

#include <string>
#include <vector>
#include <list>
#include <map>
#include "engine/base/basictypes.h"
using namespace std;

class TestData
{
public:
  /*2*/
  int GetId()
  {
    return id;
  }
  /*1002*/
  float GetValue()
  {
    return value;
  }
  /*a*/
  string& GetName()
  {
    return name;
  }
  /*a*/
  string& GetTitle()
  {
    return title;
  }
private:
  int		id;
  float		value;
  string		name;
  string		title;

  friend class TestDataTable;
};

class TestDataTable
{
public:
  TestDataTable();
  ~TestDataTable();
  bool InitWithFileName(const char *file_name);
  TestData* GetTest(int id);

protected:
  void parseRow(vector<string> &row);

private:
  vector<TestData*> *test_data_table_;

  map<int, int> index_map_;
};
#endif
