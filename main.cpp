#include <bits/stdc++.h>

#include "Person.h"
#include "Constant.h"
#include "Storage.h"
#include "Action.h"
using namespace std;

int main()
{
    load();

    char input;
    while(cin>>input)
    {

        switch(input)
        {
            case ADD:{
                add();
                cout<<"Add complete"<<endl;
                break;
            }
            case REMOVE:{
                remove();
                cout<<"Remove complete"<<endl;
                break;
            }
            case FIND:{
                find();
                break;
            }
            case PRINTALL:{
                sort(data.begin(),data.end(),cmpId);
                cout<<data.size()<<endl;
                for(auto i:data) cout<<i<<endl;
                break;
            }
            case UPDATE:{
                update();
                break;
            }
            case QUIT:{
                record();
                return 0;
            }


            /** Debug only */
            case FINDID:{
                string t;
                cout<<"Find id:";
                cin>>t;
                cout<<findId(t)<<endl;
            }
        }
    }
}

