#include"Storage.h"
#include"Person.h"
#include"Constant.h"
#include"Action.h"
#include<algorithm>
#include<vector>
using namespace std;
void add()
{
    std::string name,number;
    std::cout<<"Name   :";
    std::cin.ignore();
    std::getline(std::cin,name);
    std::cout<<"Number :"<<number;
    std::cin>>number;
    std::cout<<"Number of group:";
    int n;
    std::cin>>n;
    std::vector<std::string> group;
    std::cin.ignore();
    for(int i=0;i<n;i++)
    {
        std::string tmp;
        std::getline(std::cin,tmp);
        if(groupId[tmp].empty())
        {
            curGroupId++;
            groupId[tmp] = HEX(curGroupId);
            groupData.pb(ss(tmp,groupId[tmp]));
        }
        group.pb(tmp);
    }
    data.pb(Person(name,number,HEX(current),group));
    current++;
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

/** Find */
void find()
{
    cout<<"Find by name   : 1"<<std::endl
        <<"Find by number : 2"<<std::endl
        <<"Find by group  : 3"<<std::endl
        <<"Quit           : q"<<std::endl;

    char c;
    while(cin>>c)
    {
        switch(c)
        {
            case FIND_BY_NAME:{
                std::cout<<"Name for searching:";
                std::cin.ignore();
                std::string name;
                std::getline(std::cin,name);
                std::vector<Person> memory = findByName(name);
                std::cout<<"Found "<<memory.size()<<" matched"<<std::endl;
                for(auto i:memory) std::cout<<i<<std::endl;
                break;
            }
            case FIND_BY_NUMBER:{
                std::cout<<"Number for searching:";
                std::cin.ignore();
                std::string number;
                std::getline(std::cin,number);
                std::vector<Person> memory = findByNumber(number);
                std::cout<<"Found "<<memory.size()<<" matched"<<std::endl;
                for(auto i:memory) std::cout<<i<<std::endl;
                break;
            }
            case FIND_BY_GROUP:{
                std::cout<<"Name for searching:";
                std::cin.ignore();
                std::string name;
                std::getline(std::cin,name);
                std::vector<Person> memory = findByGroup(name);
                std::cout<<"Found "<<memory.size()<<" matched"<<std::endl;
                for(auto i:memory) std::cout<<i<<std::endl;
                break;
            }
            case QUIT:{
                return;
            }
            default:{
                std::cout<<"Unsupport input"<<std::endl;
                break;
            }
        }
    }
}
std::vector<Person> findByName(const std::string &name)
{

     std::vector<Person> found;
     for(auto p:data)
     {
         std::size_t pos = p.fullName.find(name);
         if(pos != std::string::npos) found.pb(p);
     }

//    std::cout<<"Found "<<found.size()<<" matched"<<std::endl;
//    for(auto p:found) std::cout<<p<<std::endl;
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
std::vector<Person> findByGroup(const std::string &name)
{
    std::vector<Person> found;
    for(auto p:data)
    {
        sort(p.group.begin(),p.group.end());
        if(binary_search(p.group.begin(),p.group.end(),name)) found.pb(p);
    }
    return found;
}

/** Remove */
void remove()
{
    std::cout<<"Remove by name   :1"<<std::endl
             <<"Remove by number :2"<<std::endl
             <<"Remove from group:3"<<std::endl
             <<"Quit : q"<<std::endl;
    while(1)
    {
        char c;
        std::cout<<"Remove option:";
        std::cin>>c;
        switch(c)
        {
            case REMOVE_BY_NAME:{
                removeByName();
                break;
            }
            case REMOVE_BY_NUMBER:{
                removeByNumber();
                break;
            }
            case QUIT:{
                return;
            }
            default:{
                std::cout<<"Unsupported input"<<std::endl;
            }
        }

    }
}
void removeByName()
{
    std::cout<<"Input name to remove";
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
//    std::cout<<found[n-1]<<std::endl;
    found[n-1].remove();
//    std::cout<<std::endl<<"Remove complete"<<std::endl;
}
void removeByNumber()
{
    std::cout<<"Input number to remove";
    std::string number;
    std::cin.ignore();
    std::getline(std::cin,number);
    std::vector<Person> found = findByNumber(number);
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
}


/** Update */
void update()
{
    std::cout<<"Update by name   :1"<<std::endl
             <<"Update by number :2"<<std::endl
             <<"Update from group:3"<<std::endl;
    char c;
    while(1)
    {
        std::cout<<"Update option:";
        std::cin>>c;
        switch(c)
        {
            case UPDATE_BY_NAME:{
                updateByName();
                break;
            }
            case UPDATE_BY_NUMBER:{
                updateByNumber();
                break;
            }
            case QUIT:{
                return;
            }
        }
    }
}

void updateByName()
{
    std::string name;
    std::cout<<"Name:";
    std::cin.ignore();
    std::getline(std::cin,name);
    std::vector<Person> found = findByName(name);
    std::cout<<"Found "<<found.size()<<" match"<<std::endl;
    if(found.empty()) return;
    for(auto i:found) std::cout<<i<<std::endl;
    while(1)
    {
        int n;
        std::cout<<"Number:";
        std::cin>>n;
        if(n<1||n>found.size()) std::cout<<"Out range"<<std::endl;
        else{
            updatePerson(found[n-1].id);
            return;
        }
    }
}
void updateByNumber()
{
    std::string number;
    std::cout<<"Number:";
    std::cin>>number;
    std::vector<Person> found = findByNumber(number);
    std::cout<<"Found "<<found.size()<<" match"<<std::endl;
    if(found.empty()) return;
    for(auto i:found) std::cout<<i<<std::endl;
    while(1)
    {
        int n;
        std::cout<<"Number:";
        std::cin>>n;
        if(n<1||n>found.size()) std::cout<<"Out range"<<std::endl;
        else{
            updatePerson(found[n-1].id);
            return;
        }
    }
    return;
}
void updatePerson(const std::string &ID)
{
    sort(data.begin(),data.end(),cmpId);
    int l = 0,r = data.size()-1;
    while(l<r)
    {
        int mid = (l + r)/2;
        if(data[mid].id<ID) l = mid + 1;
        else r = mid ;
    }

    std::cout<<"Change name  :1"<<std::endl
             <<"Change number:2"<<std::endl
             <<"Add group    :3"<<std::endl
             <<"Remove group :4"<<std::endl
             <<"Quit         :q"<<std::endl;

    while(1)
    {
        char c;
        std::cout<<"Change option:";
        std::cin>>c;
        switch(c)
        {
            case CHANGE_NAME:{
                std::cout<<"New name:";
                std::string t;
                std::cin.ignore();
                std::getline(std::cin,t);
                data[l].fullName = t;
                data[l].splitedName = split(t);
                break;
            }
            case CHANGE_NUMBER:{
                std::cout<<"New number:";
                std::string t;
                std::cin>>t;
                data[l].number = t;
                break;
            }
            case ADD_GROUP:{
                std::cout<<"New group:";
                std::string t;
                std::cin.ignore();
                std::getline(std::cin,t);
                sort(data[l].group.begin(),data[l].group.end());
                if(binary_search(data[l].group.begin(),data[l].group.end(),t))
                {
                    std::cout<<"Exist group"<<std::endl;
                }
                else
                {
                    data[l].group.pb(t);
                    if(groupId[t].empty())
                    {
                        curGroupId++;
                        groupId[t] = HEX(curGroupId);
                        groupData.pb(ss(t,groupId[t]));
                    }
                }
                break;
            }
            case REMOVE_GROUP:{
                std::cout<<"Group name:";
                std::string t;
                std::cin.ignore();
                std::getline(std::cin,t);
                sort(data[l].group.begin(),data[l].group.end());
                if(binary_search(data[l].group.begin(),data[l].group.end(),t))
                {
                    int left = 0,right = data[l].group.size()-1;
                    while(left<right)
                    {
                        int mid = (left+right)>>1;
                        if(data[l].group[mid]<t) left = mid + 1;else right = mid;
                    }
                    data[l].group.erase(data[l].group.begin()+l);
                }
                break;
            }
            case QUIT:{
                return;
            }
        }
    }
}
