#include <iostream>
#include <string>
using namespace std;


class Card {
protected:
    string suits;
    string cardNum;

public:
    Card() : suits("none"), cardNum("0") {}
    Card(string x, string y) : suits(x), cardNum(y) {}
    
    // operator over load function to check same card is there
    bool operator == (const Card c) const
    {
    	return (c.suits==suits && c.cardNum==cardNum);
    	 
	}
    
	// change card value string into integers
    int get_card_value() {
        if (cardNum == "A") return 1;
        else if (cardNum == "2") return 2;
        else if (cardNum == "3") return 3;
        else if (cardNum == "4") return 4;
        else if (cardNum == "5") return 5;
        else if (cardNum == "6") return 6;
        else if (cardNum == "7") return 7;
        else if (cardNum == "8") return 8;
        else if (cardNum == "9") return 9;
        else if (cardNum == "10") return 10;
        else if (cardNum == "J") return 11;
        else if (cardNum == "Q") return 12;
        else if (cardNum == "K") return 13;
        else
        {
        	cout<<"invalide cardnumber";
        	exit(0);
		}
 
    }

    string getSuit() const 
	{ 
		return suits; 
	}
    string getCardNum() const 
	{ 
		return cardNum; 
	}
     
};
class megician : public Card
{
public:
    void findHidenCart(Card c1, Card c2, Card c3, Card c4) 
	{
		int cardnumarray[4] = {c1.get_card_value(), c2.get_card_value(), c3.get_card_value(),c4.get_card_value()};
        string suitsarr[4] = { c1.getSuit(), c2.getSuit(), c3.getSuit(), c4.getSuit()};
        
		//first card suit equal to hidden card suit
		cout<<"hidden card is = "<<suitsarr[0]<<" ";
		
		int getoder[3]={c2.get_card_value(), c3.get_card_value(),c4.get_card_value()};
		int small, medium, large;
		// finding a small value

		if (getoder[0] < getoder[1] && getoder[0] < getoder[2])
		{
			small = getoder[0];
		} 
		else if (getoder[1] < getoder[0] && getoder[1] < getoder[2])
		{
		 	small = getoder[1];
		}
		else
		{
			small = getoder[2];
		} 
		// finding large value
		if (getoder[0] > getoder[1] && getoder[0] >getoder[2])
		{
			large = getoder[0];
		 } 
		else if (getoder[1] > getoder[0] && getoder[1] > getoder[2])
		{
			large = getoder[1];
		 }
		else 
		{
			large = getoder[2];
		}
		// finding medium value
		medium = getoder[0] + getoder[1] + getoder[2] - small - large;
		
		//frome the oder get hop
		int code;
		if (getoder[0] == small && getoder[1] == medium && getoder[2] == large) 
		{
			code = 1;
		}
		else if (getoder[0] == small && getoder[1] == large && getoder[2] == medium)
		{
			code = 2;
		}
		else if (getoder[0] == medium && getoder[1] == small && getoder[2] == large)
		{
			code = 3;
		}
		else if (getoder[0] == medium && getoder[1] == large && getoder[2] == small)
		{
			code = 4;
		}
		else if (getoder[0] == large && getoder[1] == small && getoder[2] == medium)
		{
			code = 5;
		}
	
		else if (getoder[0] == large && getoder[1] == medium && getoder[2] == small)
		{
			code = 6;
		}
		
		int x=c1.get_card_value();
		
		//found the value from the pair card value
		int y=x+code;
		
		if(y<=13)
		{
			if(y==11)
			{
				cout<<"J";
	
			}
			else if(y==12)
			{
				cout<<"Q";
	
			}
			else if(y==13)
			{
				cout<<"K";
	
			}
			else if(y==1)
			{
				cout<<"A";
	
			}
			else
			{
				cout<<y;
			}
		}
		else
		{
			cout<<y-13;
		}		
    }

};
int main() {
    string s1, s2, s3, s4;
    string n1, n2, n3, n4;

    cout << "put 4 oder cards \nput heart = HA , diamond = DI, club = CL, spade = SP \nexample: heart 3\n";
    cout << "\ncard 1: ";
    cin >> s1 >> n1;
    cout << "\ncard 2: ";
    cin >> s2 >> n2;
    cout << "\ncard 3: ";
    cin >> s3 >> n3;
    cout << "\ncard 4: ";
    cin >> s4 >> n4;
   
    
    Card c1(s1, n1), c2(s2, n2), c3(s3, n3), c4(s4, n4);
    // check if there invalide suits there
    string suit[4]={s1,s2,s3,s4};
    for(int i=0;i<4;i++)
    {
    	if(suit[i]!="HA" && suit[i]!="DI" && suit[i]!="CL" && suit[i]!="SP" )
    	{
    		cout<<"invalide suits";
		   	exit(0);
		}
		
	}
	
	// equalent card check
	Card carr[4]={c1,c2,c3,c4};
	for(int i=0;i<4;i++)
    {
    	for(int j=i+1;j<4;j++)
    	{
    		if(carr[i]==carr[j])
    		{
    			cout<<"here two cards are same, card should be different";
    			exit(0);
			}
		}
	}
//creat megician class object
    megician m;
    m.findHidenCart(c1, c2, c3, c4);
     

    return 0;
}