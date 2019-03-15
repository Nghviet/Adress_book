#include"Storage.h"
#include"Person.h"
#include"Constant.h"

#include<iostream>
#include<string>
#include<fstream>
#include<istream>
#include<algorithm>
#include<time.h>

std::vector<Person> data;
long current = 0;

bool load()
{
    std::ifstream in;
    in.open("collection",std::fstream::in);
    if(in.good())
    {
        std::string id,name,number;
        in>>current;
        char c;
        while(in>>c)
        {
            std::string e1,e2;
            std::string m;
            in>>e1>>e2>>m;
            id = m;

            in>>e1>>e2>>m;
            for(int i=0;i<m.length();i++) if(m[i]==SEPERATE) m[i] = ' ';
//            std::cout<<m<<std::endl;
            name = m;

            in>>e1>>e2>>m;
            number = m;

            data.pb(Person(name,number,id));
            in>>c;
        }
    }
    else
    {
        in.close();
        return false;
    }
    in.close();
    return true;
}

std::string genId()
{
    time_t curTime;
    time(&curTime);
    return std::string();
}

bool add()
{
    std::string name,number;
    std::cout<<"Name   :";
    std::cin.ignore();
    std::getline(std::cin,name);
    std::cout<<"Number :"<<number;
    std::cout.flush();
    std::cin>>number;
    data.pb(Person(name,number,HEX(current)));
    current++;
    return true;
}

bool record()
{
    freopen("collection","w",stdout);
    std::cout<<current<<std::endl;
    for(auto i:data)
    {
        std::cout<<"{"<<std::endl;
        std::cout<<"  ID     : "<<i.id<<std::endl;
        std::cout<<"  Name   : ";
        std::cout<<i.splitedName[0];
        for(int t = 1;t<i.splitedName.size();t++) std::cout<<SEPERATE<<i.splitedName[t];
        std::cout<<std::endl;
        std::cout<<"  Number : "<<i.number<<std::endl;
        std::cout<<"}"<<std::endl;
    }
    return true;
}

void updateByName()
{
    std::string name;
    std::cout<<"Name:"<<std::endl;
    std::cin.ignore();
    std::getline(std::cin,name);
    std::vector<Person> found = findByName(name);
    std::cout<<"Found "<<found.size()<<" match"<<std::endl;
    for(auto i:found) std::cout<<i<<std::endl;
}

Person findId(const std::string &Id)
{
    sort(data.begin(),data.end(),cmpId);
    int l = 0,r = data.size()-1;
    while(l<r)
    {
        int mid = (l + r)/2;
        if(data[mid].id<Id) l = mid + 1;
        else r = mid ;
    }
    return data[l];
}

std::vector<Person> findByName(const std::string &name)
{
     std::vector<Person> found;
     for(auto p:data)
     {
         std::size_t pos = p.fullName.find(name);
         if(pos != std::string::npos) found.pb(p);
     }

//     std::cout<<"Found "<<found.size()<<" matched"<<std::endl;
//     for(auto p:found) std::cout<<p<<std::endl;
    return found;
}

std::vector<Person> findByNumber(const std::string &number)
{
     std::vector<Person> found;
     for(auto p:data)
     {
         std::size_t pos = p.number.find(number);
         if(pos != std::string::npos) found.pb(p);
     }

//     std::cout<<"Found "<<found.size()<<" matched"<<std::endl;
//     for(auto p:found) std::cout<<p<<std::endl;
    return found;
}

void remove()
{
    std::cout<<"Input name to remove"<<std::endl;
    std::string name;
    std::cin.ignore();
    std::getline(std::cin,name);
    std::vector<Person> found = findByName(name);
    std::cout<<"Found "<<found.size()<<" matched"<<std::endl;
    for(auto p:found) std::cout<<p<<std::endl;
    if(found.size()==0) return;
    std::cout<<"Number of contact to remove:";
    int n;
    while(1)
    {
        std::cin>>n;
        if(n>found.size()||n<1) std::cout<<std::endl<<"Dont exist,type in another number";
        else break;
    }
    std::cout<<found[n-1]<<std::endl;
    found[n-1].remove();
    std::cout<<std::endl<<"Remove complete"<<std::endl;
    return;

}
