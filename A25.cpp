#include <iostream>
#include <cmath>
using namespace std;
#include <limits>
// cmath and limits needed for CodeBlocks compilation
int read_number(){
    int x;
    while (true){
        cin >> x;
        if (!cin){
            cout << "Please enter a round number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }
        else break;
    }
    return x;
}
// When used as a function return type, the void keyword
// specifies that the function does not return a value.
void geoprog(){
    int a;
    int q;
    int n = 0;
    while (true){
        cout<<"Enter a:";
        a = read_number();
        cout<<"Enter q:";
        q = read_number();
        while(n<1){
            cout<<"Enter n:";
            n = read_number();
        }
        break;
    }
    for(int i = 0; i<n; i++){
        int num = a * pow(q, i);
        cout<<"Number a"<<i+1<<" is "<<num<<endl;
    }
}

int main() {
    while(true){
        geoprog();
        while(true){
            char c;
            cout<<"Would you like to calculate again? (y/n)\n";
            cin>>c;
            if (c == 'y') break;
            else if (c == char('n')) exit(0);
            else {
                cout<<"Enter \"y\" to continue or \"n\" to end.\n";
                cin.clear();
                    // cin.ignore() function is used which is used
                // to ignore or clear one or more characters from the input buffer.
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }
        }
    }
    return 0;
}

