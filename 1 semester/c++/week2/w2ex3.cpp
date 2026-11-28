#include<iostream>
using namespace std;

int main()
{
    int choice;
    do
    {
        cout<<"Choose conversion:\n";
        cout<<"1.Decimal to Binary\n";
        cout<<"2.Binary to Decimal\n";
        cout<<"3.Exit\n";
        cout<<"Enter choice:";
        cin>>choice;
        switch(choice)
        {
            case 1:
            {
                int n,binary[32],i=0;
                cout<<"Enter decimal number:";
                cin>>n;
                if(n==0)
                {
                    cout<<"Binary:0\n";
                }
                else
                {
                    while(n>0)
                    {
                        binary[i]=n%2;
                        n=n/2;
                        i++;
                    }
                    cout<<"Binary:";
                    for(int j=i-1;j>=0;j--)
                        cout<<binary[j];
                    cout<<endl;
                }
                break;
            }
            case 2:
            {
                int n,decimal=0,base=1;
                bool valid=true;
                cout<<"Enter binary number:";
                cin>>n;
                while(n>0)
                {
                    int last=n%10;
                    if(last!=0&&last!=1)
                    {
                        valid=false;
                        break;
                    }
                    n=n/10;
                    decimal=decimal+last*base;
                    base=base*2;
                }
                if(valid)
                    cout<<"Decimal:"<<decimal<<endl;
                else
                    cout<<"Invalid binary number.\n";
                break;
            }
            case 3:
                cout<<"Exiting...\n";
                break;
            default:
                cout<<"Invalid choice.\n";
        }
    }while(choice!=3);
    return 0;
}

