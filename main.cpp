#include <bits/stdc++.h>

#include "Person.h"
#include "Constant.h"
#include "Storage.h"
using namespace std;

int main()
{
    if(!load())
    {
        return 0;
    }

    char input;
    bool quit = false;

    time_t timer = chrono::system_clock::to_time_t(chrono::system_clock::now());

    while(!quit)
    {
        cin>>input;
        switch(input)
        {
            case ADD:{
                if(add()) cout<<"Add completed"<<endl;
                break;
            }
            case REMOVE:{
                remove();
                break;
            }
            case FIND:{
                vector<Person> memory;
                cout<<"Find by name   : 1"<<std::endl;
                cout<<"Find by number : 2"<<std::endl;
                while(true)
                {
                    cin>>input;
                    if(input == FIND_BY_NAME)
                    {
                        string name;
                        cout<<"Name:";
                        cin.ignore();
                        getline(cin,name);
                        memory = findByName(name);
                        break;
                    }
                    else
                    if(input == FIND_BY_NUMBER)
                    {
                        string number;
                        cout<<"Number:";
                        cin.ignore();
                        getline(cin,number);
                        memory = findByNumber(number);
                        break;
                    }
                    else cout<<"Unsupport input"<<endl;
                }

                cout<<"Found "<<memory.size()<<" matched"<<endl;
                for(auto i:memory) cout<<i<<endl;

                break;
            }
            case PRINTALL:{
                sort(data.begin(),data.end(),cmpId);
                cout<<data.size()<<endl;
                for(auto i:data) cout<<i<<endl;
                break;
            }
            case UPDATE:{
                cout<<"Update:"<<endl;
                cout<<"Update by name: 1"<<endl;
                cout<<
                break;
            }
            case QUIT:{
                quit = true;
                break;
            }

            case FINDID:
            {
                string t;
                cout<<"Find id:";
                cin>>t;
                cout<<findId(t)<<endl;
            }
        }
    }

    if(!record()) cout<<"Cant record data";
    return 0;
}

