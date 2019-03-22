#include"Person.h"
#include"Storage.h"
#include"Constant.h"
#include<algorithm>
#include<math.h>
Person::Person()
{
    priority = 2;
}

Person::Person(const std::string& name,const std::string & _number,const std::string & _id,const std::vector<std::string> _group)
{
    fullName = name;
    splitedName = split(name);
    number = _number;
    group = _group;
    id = _id;
    priority = 2;

    std::sort(group.begin(),group.end());
    auto last = std::unique(group.begin(),group.end());
    group.erase(last,group.end());
}

bool Person::remove()
{
    sort(data.begin(),data.end(),cmpId);
    int l = 0,r = data.size()-1;
    while(l<r)
    {
        int mid = (l+r)>>1;
//        std::cout<<l<<" "<<r<<" "<<mid<<std::endl;
        if(data[mid].id<id) l = mid + 1 ;else r = mid;
    }
//    std::cout<<l<<std::endl;
//    std::cout<<id<<std::endl;
//    std::cout<<data[l]<<std::endl;
    data.erase(data.begin()+l);
    return true;
}

std::string HEX(long n)
{
    std::string t;
    while(n!=0)
    {
        int tmp = n%16;
        n/=16;
        if(tmp>=0&&tmp<=9) t.push_back(tmp+'0'); else t.push_back(tmp-10+'A');
    }
//    reverse(t.begin(),t.end());
    while(t.length()<IDLENGTH) t.push_back('0');
    reverse(t.begin(),t.end());
    return t;
}

bool cmpId(const Person &a,const Person &b)
{
    return (a.id<b.id);
}

bool cmpName(const Person &a,const Person &b)
{
    int tmp = std::min(a.splitedName.size(),b.splitedName.size());
    for(int i=0;i<tmp;i++)
    {
        if(a.splitedName[a.splitedName.size()-1-i] > b.splitedName[b.splitedName.size()-1-i]) return false;
        if(a.splitedName[a.splitedName.size()-1-i] < b.splitedName[b.splitedName.size()-1-i]) return true;
    }
    if(a.splitedName.size()>b.splitedName.size()) return false;
    if(a.splitedName.size()<b.splitedName.size()) return true;
    return true;
}

std::ostream& operator<<(std::ostream& out, const Person &p)
{
    out<<"{"<<std::endl;
    out<<"  Name   : "<<p.fullName<<std::endl;
    out<<"  Number : "<<p.number<<std::endl;
    out<<"  Group  : "<<std::endl;
    for(auto i:p.group)
        out<<"    "<<i<<std::endl;
    out<<"}"<<std::endl;
    return out;
}

std::vector<std::string> split(const std::string &in)
{
    std::string tmp;
    std::vector<std::string> ans;

    for(auto i:in)
    if(i==' ')
    {
        if(!tmp.empty()) ans.pb(tmp);
        tmp.clear();
    }
    else tmp.pb(i);
    if(!tmp.empty()) ans.pb(tmp);
    return ans;
}

