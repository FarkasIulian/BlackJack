#include <iostream>
#include <time.h>
#include <vector>
#include <stdlib.h>
#include <conio.h>

using namespace std;
//creating a deck of cards, assuming cards are placed on 4 rows of 13 columns each

#define BUST 21
int win=0,loss=0;


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

    vector <int> HitMe();
    void showHand(Player p);
};

vector <int> CardDeck::HitMe(){
    vector <int> value;
    srand(time(NULL));
    int index=rand()%n;
    if(index > n || index < 0 ){
        cout<<"Error.";
        exit(0);
    }
    if(n==52)
        cout<<"You start with: ";
    else
        cout<<"You drew: ";
    printOne(index);
    value.push_back(arrCards[index].value);
    value.push_back(index);
    removeCard(index);
    return value;
}

void CardDeck::showHand(Player p){
    CardDeck aux;
    aux.createDeck();
    for(int i=0;i<p.cards.size();i++){
        aux.drawOne(p.cards[i]);
        cout<<endl;
        aux.printOne(p.cards[i]);
        aux.removeCard(p.cards[i]);
    }
}

void Game(){
    Player player,dealer;
    CardDeck Deck;
    int opt,first=0;
    vector <int> aux;
    Deck.createDeck();
    aux=Deck.HitMe();  
    player.cards.push_back(aux[1]); 
    player.sum+=aux[0];
    while(1){
        cout<<"Would you like to draw a card or to stand? "<<endl<<"1 - draw , 2 - show hand, 3 - stand"<<endl;
        cin>>opt;
        if(opt==1){
            aux=Deck.HitMe();  
            player.cards.push_back(aux[1]); 
            if(aux[0]==11 && player.sum+aux[0]>21)
                player.sum+=1;
            else
                player.sum+=aux[0];
            cout<<"Your current total is: "<<player.sum<<endl;
        }
        else if(opt==2){
            system("CLS");
            cout<<"Your cards are: "<<endl;
            Deck.showHand(player);
            cout<<"The sum of your cards is: "<<player.sum<<endl;
            cout<<"Press any key to get back to the game! "<<endl;
            getch();
        }
        else{
            system("CLS");
            cout<<"Your turn is over!"<<endl<<"DEALEARS TURN: "<<endl;
            while(1){
                if(dealer.sum+6 < BUST){
                    aux=Deck.HitMe();
                    dealer.cards.push_back(aux[1]); 
                    if(aux[0]==11 && dealer.sum+aux[0]>21)
                        dealer.sum+=1;
                    else
                        dealer.sum+=aux[0];
                    cout<<"Dealer current total is: "<<dealer.sum<<endl;
                    if(dealer.sum>BUST){
                        cout<<"DEALER BUSTED! "<<endl<<"Dealer total was: "<<dealer.sum;
                        win++;
                        break;
                    }
                }
                else
                    break;
            }
            if(player.sum>dealer.sum){
                cout<<"YOU WON!"<<endl;
                win++;
            }
            else{
                cout<<"YOU LOST!"<<endl;
                loss++;
            }
            break;
        } 
        if(player.sum>BUST){
          cout<<"YOU BUSTED! "<<endl<<"Your total was: "<<player.sum<<endl;
          loss++;
          break;
        }
    }
    cout<<"YOU HAVE "<<win<<" WINS AND "<<loss<<" LOSSES"<<endl;  
    cout<<"Do you want to play again?"<<endl;
    cout<<"1 - yes , 0 - no"<<endl;
    cin>>opt;
    if(opt){
        system("CLS");
        Game();
    }
    else return;
}

int main(){
    Game();
    system("CLS");
    return 0;
}