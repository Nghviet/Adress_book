#pragma once

#ifndef STORAGE_H_INCLUDED
#define STORAGE_H_INCLUDED

#include"Person.h"
#include<string>
#include<vector>

extern std::vector<Person> data;
extern long current;

bool load();

std::string genId();

bool add();

bool record();

void update(const std::string &name);

bool sortId();

bool sortFName();

bool sortLName();

Person findId(const std::string &Id);

std::vector<Person> findByName(const std::string &name);

std::vector<Person> findByNumber(const std::string &number);

void remove();

#endif // STORAGE_H_INCLUDED
