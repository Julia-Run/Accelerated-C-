//say hello in a frame
#include<iostream>
#include<string>
using std::cin; using std::cout;
using std::string; using std::endl;

int main(){
    cout<<"Please input your name: ";
    string name;
    cin >> name;
    string greeting = "Hello, " + name + " !";

    int pad = 1;
    int rows = pad*2+3;
    string::size_type cols = greeting.size()+pad*8+2;

    cout << endl;
    for (int r = 0; r!=rows; ++r){
        string::size_type c = 0;
        while (c!=cols){
            if (r == pad+1 && c == pad*4+1){
                cout << greeting;
                c += greeting.size();
            }
            else{
                if (r==0 || r==rows-1 || c==0 || c==cols-1) cout<<'*';
                else cout<<' ';
                ++c;
            }
        }
        cout << endl;
    }
    return 0;
}