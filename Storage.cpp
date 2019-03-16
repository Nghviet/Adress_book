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

std::map<std::string,std::string> groupId;
std::vector<ss> groupData;
long current = 0;
long curGroupId = 0;

void load()
{
    std::ifstream in;
    in.open("collection",std::fstream::in);
    if(in.good())
    {
        in>>current;
        char c;
        while(in>>c)
        {
            std::string id,name,number;
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

            in>>e1>>e2;
            std::vector<std::string> group;
            std::string tmp;
            in.ignore();
            while(getline(in,tmp))
            {
                if(tmp.length()==1&&tmp[0]=='}') break;
                while(!tmp.empty()&&tmp[0]==' ') tmp.erase(tmp.begin());
                if(!tmp.empty()) group.pb(tmp);
            }
            data.pb(Person(name,number,id,group));
        }
    }
    in.close();

    in.open("groupCollection",std::fstream::in);
    if(in.good())
    {
        int n;
        in>>n;
        curGroupId = n;
        while(n--)
        {
            std::string id , name;
            in>>id;
            in.ignore();
            std::getline(in,name);
            groupData.pb(ss(name,id));
            groupId[name] = id;
        }

    }
    in.close();
}

void record()
{
    std::ofstream out;
    out.open("collection",std::fstream::out);
    if(out.good())
    {
        out<<current<<std::endl;
        for(auto i:data)
        {
            out<<"{"<<std::endl;
            out<<"  ID     : "<<i.id<<std::endl;
            out<<"  Name   : ";
            out<<i.splitedName[0];
            for(int t = 1;t<i.splitedName.size();t++) out<<SEPERATE<<i.splitedName[t];
            out<<std::endl;
            out<<"  Number : "<<i.number<<std::endl;
            out<<"  Group  :";
            for(auto j:i.group) out<<std::endl<<"      "<<j;
            out<<std::endl<<"}"<<std::endl;
        }
    }
    out.close();

    out.open("groupCollection",std::fstream::out);
    if(out.good())
    {
        out<<curGroupId<<std::endl;
        for(auto i:groupData)
        {
            out<<i.second<<" "<<i.first<<std::endl;
        }
    }
    out.close();

}

