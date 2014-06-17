#include "test_data_table.h"

#include "engine/csvparser/csv_file_parser.h"
#include "engine/base/utils_string.h"
#include <cocos2d.h>

TestDataTable::TestDataTable()
{
  test_data_table_ = new vector<TestData*>();
}

TestDataTable::~TestDataTable()
{
  for (vector<TestData*>::iterator itr = test_data_table_->begin();
  itr != test_data_table_->end(); ++itr)
  {
    delete *itr;
  }
  delete test_data_table_;
}

bool TestDataTable::InitWithFileName(const char *file_name)
{
  CSVFileParser csv_file;
  CSVFileRow csv_row;
  CCLog("Loading csv file %s", file_name);

  if(!csv_file.InitWithFileName(file_name))
    return false;

  while(csv_file.IsHasMoreLine())
  {
    csv_file.GetNextRow(csv_row);
    parseRow(csv_row);
  }

  return true;
}

TestData* TestDataTable::GetTest(int id)
{
  map<int, int>::iterator index = index_map_.find(id);
  if(index == index_map_.end())
  {
    CCLog("TestDataTable TypeId not found! Id: %d", id);
    assert(false);
    return NULL;
  }
  return test_data_table_->at(index->second);
}

void TestDataTable::parseRow(vector<string> &row)
{
  int i = 0;
  TestData *data = new TestData();
  data->id = String2Int(row[i++]);
  data->value = String2Float(row[i++]);
  data->name = row[i++];
  data->title = row[i++];
  index_map_.insert(pair<int, int>(data->id, test_data_table_->size()));
  test_data_table_->push_back(data);
}

