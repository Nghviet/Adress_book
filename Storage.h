#pragma once

#ifndef STORAGE_H_INCLUDED
#define STORAGE_H_INCLUDED

#include"Person.h"
#include<string>
#include<vector>
#include<utility>
typedef std::pair<std::string,std::string> ss;

extern std::vector<Person> data;
extern std::map<std::string,std::string> groupId;
extern std::vector<ss> groupData;
extern long curGroupId;
extern long current;

void load();

void record();

#endif // STORAGE_H_INCLUDED
