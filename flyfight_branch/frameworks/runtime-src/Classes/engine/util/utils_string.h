//
//  utils_string.h
//  flyfight_branch
//
//  Created by snowcold on 14-6-17.
//
//

#ifndef __flyfight_branch__utils_string__
#define __flyfight_branch__utils_string__

#include <iostream>
#include <stdlib.h>

static int String2Int(const char* msg)
{
    return atoi(msg);
}

static int String2Int(std::string& msg)
{
    return atoi(msg.c_str());
}

static float String2Float(const char* msg)
{
    return atof(msg);
}

static float String2Float(std::string& msg)
{
    return atof(msg.c_str());
}


#endif /* defined(__flyfight_branch__utils_string__) */
