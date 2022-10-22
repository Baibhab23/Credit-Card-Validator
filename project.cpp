#include<iostream>
using namespace std;
#include<string>

bool isNumberstring(const string& s)
{
    int len =s.length();
    for(int i=0;i<len;i++)
    {
        if(s[i]<'0'||s[i]>'9')
            return false;
    }
    return true;
}
int main()
{
    string ccnumber;
    cout<<"You can enter 'exit' anytime to to quit."<<endl;
    while(true)
    {
        cout<<"Please enter a CC number to validate: ";
        cin>>ccnumber;
        if(ccnumber =="exit")
            break;
        else if(!isNumberstring(ccnumber))
        {
            cout<<"Bad Input!";
            continue;
        }
        int len =ccnumber.length();
        int doubleevensum=0;
        for(int i=len-2;i>=0;i=i-2)
        {
            int dbl=((ccnumber[i]-48)*2);
            if(dbl>9)
            {
                dbl=(dbl/10)+(dbl%10);
            }
            doubleevensum+=dbl;
        }
        for(int i=len-1;i>=0;i=i-2)
        {
            doubleevensum+=(ccnumber[i]-48);
        }
        cout<<(doubleevensum%10==0?"Valid!":"Invalid!")<<endl;
        continue;
    }
    return 0;
}
