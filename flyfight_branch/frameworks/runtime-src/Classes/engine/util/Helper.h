//
//  Helper.h
//  flyfight_branch
//
//  Created by snowcold on 22/6/14.
//
//

#ifndef __flyfight_branch__Helper__
#define __flyfight_branch__Helper__

#include <iostream>

static bool isPvr_CCZ_File(std::string& path)
{
    static std::string tail = "pvr.ccz";
    return path.compare(path.size() - tail.size(), tail.size(), tail) == 0;
}

static bool is_CCBI_File(std::string& path)
{
    static std::string tail = ".ccbi";
    return path.compare(path.size() - tail.size(), tail.size(), tail) == 0;
}

template <typename T, typename K>
void release_Std_List(T list)
{
    if (list.size() > 0)
    {
        K it = list.begin();
        for (; it != list.end(); ++it)
        {
            delete (*it);
        }
    }
    list.clear();
}

#endif /* defined(__flyfight_branch__Helper__) */
