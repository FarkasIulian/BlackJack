#include <iostream>
using namespace std;
//creating a deck of cards, assuming cards are placed on 4 rows of 13 columns each

enum class Suits{
    CLUBS,
    SPADES,
    HEARTS,
    DIAMONDS,
};

enum class Names{
    ACE=1,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE,
    TEN,
    JACK,
    QUEEN,
    KING,
};

struct Card{
    int value;
    Suits suit;
    Names name;

    void PrintSuit(){
        if(suit==Suits::CLUBS)
            cout<<"CLUBS";
        if(suit==Suits::SPADES)
            cout<<"SPADES";
        if(suit==Suits::HEARTS)
            cout<<"HEARTS";
        if(suit==Suits::DIAMONDS)
            cout<<"DIAMONDS";
    }
    void PrintName(){
        if(name==Names::ACE)
            cout<<"ACE";
        else if(name==Names::JACK)
            cout<<"JACK";
        else if(name==Names::QUEEN)
            cout<<"QUEEN";
        else if(name==Names::KING)
            cout<<"KING";
        else
            cout<<value;
    }
    void Draw(){
        cout<<" _____ "<<endl;
     for(int i=0;i<=3;i++){
        if(i==1){
            if(name==Names::ACE)
                cout<<"|  A  |"<<endl;
            else if(name==Names::JACK)
                cout<<"|  J  |"<<endl;
            else if(name==Names::QUEEN)
                cout<<"|  Q  |"<<endl;
            else if(name==Names::KING)
                cout<<"|  K  |"<<endl;
            else if(value==10)
                 cout<<"|  10 |"<<endl;
            else
                 cout<<"|  "<<value<<"  |"<<endl;
        }
        else if(i==2){
            if(suit==Suits::CLUBS)
                cout<<"|  C  |"<<endl;
            else if(suit==Suits::SPADES)
                cout<<"|  S  |"<<endl;
            else if(suit==Suits::HEARTS)
                cout<<"|  H  |"<<endl;
            else if(suit==Suits::DIAMONDS)
                cout<<"|  D  |"<<endl;
        }
        else if(i==3)
            cout<<"|_____|"<<endl;
        else 
            cout<<"|     |"<<endl;

     }
    }


};

struct CardDeck{
    Card arrCards[52];
    
    void createDeck(){
        for(int i=(int)Suits::CLUBS;i<=(int)Suits::DIAMONDS;i++){
            for(int j=(int)Names::ACE;j<=(int)Names::KING;j++){
                Card c;
                c.suit=(Suits)i;
                c.name=(Names)j;
                if(c.name == Names::JACK)
                    c.value=10;
                else if(c.name==Names::QUEEN)
                    c.value=10;
                else if(c.name==Names::KING)
                    c.value=10;
                else 
                    c.value=j;
                int index=(13*i)+j-1; 
                // the position of the card is 13 * the row that we want and to that we add the column of the selected card,
                // we subtract one because the ACE starts at 1 not at 0 in the enum.
                arrCards[index]=c;
                //cout<<(int)c.name<<" of "<<(int)c.suit<<endl;
            }
        }
    }

    void PrintAll(){
        for(int index=0;index<52;index++){
                arrCards[index].PrintName();
                cout<< " of ";
                arrCards[index].PrintSuit();
                cout<<endl;
        }
    }
    void DrawAll(){
         for(int i=(int)Suits::CLUBS;i<=(int)Suits::DIAMONDS;i++){
            for(int j=(int)Names::ACE;j<=(int)Names::KING;j++){
                int index=(13*i)+j-1;
                arrCards[index].Draw();
                cout<<endl;
            }
            cout<<endl;
        }
    }
};


int main(){
    CardDeck deck;
    deck.createDeck();
    //deck.PrintAll();
    deck.DrawAll();
    return 0;
}