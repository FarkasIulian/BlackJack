#include <iostream>
using namespace std;


void Draw(){
    cout<<" _____ "<<endl;
    for(int i=0;i<=3;i++){
        if(i==1)
            cout<<"|  "<<i+9<<"  |"<<endl;
        else if(i==2)
            cout<<"|  D  |"<<endl;
        else if(i==3)
            cout<<"|_____|"<<endl;
        else 
            cout<<"|     |"<<endl;

    }
}


int main(){
    Draw();
}