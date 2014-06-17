#ifndef ABILITY_DATA_TABLE_H
#define ABILITY_DATA_TABLE_H

#include <string>
#include <vector>
#include <list>
#include <map>
using namespace std;

class AbilityData
{
public:
  /*;被动技能ID*/
  int GetId()
  {
    return id;
  }
  /*被动技能名称*/
  string& GetName()
  {
    return name;
  }
  /*被动技能类型*/
  int GetType()
  {
    return type;
  }
  /*技能描述*/
  string& GetText()
  {
    return text;
  }
  /*技能作用对象
0.自己
1.敌人
2.本方全体
3.本方全体(不包括自己)
4.血量最少队友*/
  int GetTarget()
  {
    return target;
  }
  /*参数0*/
  float GetParam0()
  {
    return param0;
  }
  /*参数1*/
  float GetParam1()
  {
    return param1;
  }
  /*参数2*/
  float GetParam2()
  {
    return param2;
  }
  /*参数3*/
  float GetParam3()
  {
    return param3;
  }
  /*参数4*/
  float GetParam4()
  {
    return param4;
  }
  /*附加状态*/
  int GetFlag()
  {
    return flag;
  }
  /*作用对象职业
0.无
1.战士
2.弓使
4.法师
8.僧侣
16.骑士*/
  int GetIParam0()
  {
    return iParam0;
  }
private:
  int		id;
  string		name;
  int		type;
  string		text;
  int		target;
  float		param0;
  float		param1;
  float		param2;
  float		param3;
  float		param4;
  int		flag;
  int		iParam0;

  friend class AbilityDataTable;
};

class AbilityDataTable
{
public:
  AbilityDataTable();
  ~AbilityDataTable();
  bool InitWithFileName(const char *file_name);
  AbilityData* GetAbility(int id);

protected:
  void parseRow(vector<string> &row);

private:
  vector<AbilityData*> *ability_data_table_;

  map<int, int> index_map_;
};
#endif
