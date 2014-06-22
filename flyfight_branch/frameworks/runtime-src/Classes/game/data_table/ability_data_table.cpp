#include "ability_data_table.h"

#include "engine/csvparser/csv_file_parser.h"
#include "engine/util/utils_string.h"
#include <cocos2d.h>
using namespace cocos2d;

AbilityDataTable::AbilityDataTable()
{
  ability_data_table_ = new vector<AbilityData*>();
}

AbilityDataTable::~AbilityDataTable()
{
  for (vector<AbilityData*>::iterator itr = ability_data_table_->begin();
  itr != ability_data_table_->end(); ++itr)
  {
    delete *itr;
  }
  delete ability_data_table_;
}

bool AbilityDataTable::InitWithFileName(const char *file_name)
{
  CSVFileParser csv_file;
  CSVFileRow csv_row;
  log("Loading csv file %s", file_name);

  if(!csv_file.InitWithFileName(file_name))
    return false;

  while(csv_file.IsHasMoreLine())
  {
    csv_file.GetNextRow(csv_row);
    parseRow(csv_row);
  }

  return true;
}

AbilityData* AbilityDataTable::GetAbility(int id)
{
  map<int, int>::iterator index = index_map_.find(id);
  if(index == index_map_.end())
  {
    log("AbilityDataTable TypeId not found! Id: %d", id);
    assert(false);
    return NULL;
  }
  return ability_data_table_->at(index->second);
}

void AbilityDataTable::parseRow(vector<string> &row)
{
  int i = 0;
  AbilityData *data = new AbilityData();
  data->id = String2Int(row[i++]);
  data->name = row[i++];
  data->type = String2Int(row[i++]);
  data->text = row[i++];
  data->target = String2Int(row[i++]);
  data->param0 = String2Float(row[i++]);
  data->param1 = String2Float(row[i++]);
  data->param2 = String2Float(row[i++]);
  data->param3 = String2Float(row[i++]);
  data->param4 = String2Float(row[i++]);
  data->flag = String2Int(row[i++]);
  data->iParam0 = String2Int(row[i++]);
  index_map_.insert(pair<int, int>(data->id, ability_data_table_->size()));
  ability_data_table_->push_back(data);
}

