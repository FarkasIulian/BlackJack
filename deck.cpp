#include <iostream>
#include <time.h>
#include <vector>
using namespace std;
//creating a deck of cards, assuming cards are placed on 4 rows of 13 columns each

#define BUST 21

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

struct Player{
    int sum=0;
    int wins;
    int losses;
    vector <int> cards;
};

struct CardDeck{
    Card arrCards[52];
    int n=52;
    void createDeck(){
        for(int i=(int)Suits::CLUBS;i<=(int)Suits::DIAMONDS;i++){
            for(int j=(int)Names::ACE;j<=(int)Names::KING;j++){
                Card c;
                c.suit=(Suits)i;
                c.name=(Names)j;
                if(c.name == Names::ACE)
                    c.value=11;
                else if(c.name == Names::JACK)
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

    void printOne(int index){
        arrCards[index].PrintName();
        cout<<" of ";
        arrCards[index].PrintSuit();
        cout<<endl;
    }

    void drawOne(int index){
        arrCards[index].Draw();
    }

    void removeCard(int index){
        for(int i=index;i<n-1;i++)
            arrCards[i]=arrCards[i+1];
        n--;
    }

    int HitMe();
    void showHand(Player p);
};

int CardDeck::HitMe(){
    srand(time(NULL));
    int index=rand()%n;
    if(index > n || index < 0 ){
        cout<<"Error.";
        exit(0);
    }
    cout<<"You drew: ";
    printOne(index);
    removeCard(index);
    cout<<arrCards[index].value<<endl<<endl;
    return arrCards[index].value;    
}

//1void CardDeck::showHand(Player p){
  //  for(int i=0;i<cards.size();i++)
//}

void Game(){
    Player player,dealer;
    CardDeck Deck;
    int opt;
    Deck.createDeck();
    while(1){
        cout<<"Would you like to draw a card or to stand? "<<endl<<"1 - draw , 2 - show hand, 3 - stand"<<endl;
        cin>>opt;
        if(opt==1){
            player.sum+=Deck.HitMe();
            cout<<player.sum<<endl;
        }
        else if(opt==2)
            break;
        else
            break; 
        if(player.sum>BUST){
          cout<<"YOU BUSTED! "<<endl<<"Your total was: "<<player.sum;
          player.losses++;
          break;
        }
    }
    
}


int main(){
    Game();
    return 0;
}