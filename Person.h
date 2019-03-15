#pragma once

#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

#include<string>
#include<fstream>
#include<iostream>
#include<vector>
#include<map>
#include<fstream>

struct Person
{

        std::string id;
        std::string fullName;
        std::vector<std::string> splitedName;
        std::string number;

        Person();

        Person(const std::string & name,
               const std::string & _number,
               const std::string & _id);

        bool remove();

    private:
        std::string password;
        int priority;

    friend std::ostream& operator<<(std::ostream& out,const Person& p);
};

std::string HEX(long n);

bool cmpId(const Person &a,
           const Person &b);

bool cmpName(const Person &a,
             const Person &b);

std::ofstream& operator<<(const std::ofstream &out,
                          const Person &p);

std::vector<std::string> split(const std::string& in);


#endif // PERSON_H_INCLUDED
