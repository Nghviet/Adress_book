#pragma once

#ifndef ACTION_H_INCLUDED
#define ACTION_H_INCLUDED

#include"Storage.h"
#include"Person.h"
#include"Constant.h"
#include<vector>
#include<string>

void add();

Person findId(const std::string &Id);

/** Find */

void find();

std::vector<Person>findByName   (const std::string &name);
std::vector<Person>findByNumber (const std::string &number);
std::vector<Person>findByGroup  (const std::string &name);

/** Remove */

void remove();

void removeByName();
void removeByNumber();
void removeFromGroup();

/** Update */

void update();

void updateByName();
void updateByNumber();
void updateByGroup();
void updatePerson(const std::string &ID);
#endif // ACTION_H_INCLUDED
