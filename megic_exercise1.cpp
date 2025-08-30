#include <iostream>
#include <string>
using namespace std;


class Card {
protected:
    string suits;
    string cardNum;

public:
    Card() : suits("none"), cardNum("0"){}
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
        	cout<<"invalide card number";
        	exit(0);

		}
    }
    // to get suits only
    string getSuit() const 
	{ 
		return suits; 
	}
	// to get cardnumber only
    string getCardNum() const 
	{ 
		return cardNum; 
	}

};

class Assistence : public Card {
private:
    int reorderedNums[5];   // member variable
    string reorderedSuits[5];
    int diff;
public:
    Assistence() : Card() {}

    // prints which card index (1..5) should be the hidden card
    void chooseHidenCart(Card c1, Card c2, Card c3, Card c4, Card c5) 
	{
		//seperate suits and number for each card and stor all in new arrays seperatly
        int cardnumarray[5] = {c1.get_card_value(), c2.get_card_value(), c3.get_card_value(),c4.get_card_value(), c5.get_card_value()};
        string suitsarr[5] = { c1.getSuit(), c2.getSuit(), c3.getSuit(), c4.getSuit(), c5.getSuit() };
        
        int hiddenIndex;
        int pairIndex;
        
        //using loop for finding same suits

        for (int i = 0; i < 4; ++i) 
		{
            for (int j = i + 1; j < 5; ++j) 
			{
                if (suitsarr[i] == suitsarr[j]) 
				{
					//after finding same suit's card take card value 
                    int a = cardnumarray[i];
                    int b = cardnumarray[j];
                    if (a < 1 || b < 1) 
					{
                        cout << "Invalid card rank detected (one of the ranks is not recognized)\n";
                        return;
                    }

                    // compute modular difference
                    diff = (a - b + 13) % 13;
                     
                    // rule: if diff <= 6 -> choose position i as hidden, else choose j
                    if (diff <= 6) 
					{
                        hiddenIndex=i;
                        pairIndex=j;
                                    
                    } 
					else 
					{
						
                        hiddenIndex = j;
                        pairIndex   = i;
                              
                    }
                    break; // stop after first same-suit pair found
                }
                 
            }
        }
        
    
	   //take hidden card and assign it to the first in array of reodernum
	    reorderedNums[0] = cardnumarray[hiddenIndex];
	    reorderedSuits[0] = suitsarr[hiddenIndex];
	   //take pair card and assign it to the second in array of reodernum
	    reorderedNums[1] = cardnumarray[pairIndex];
	    reorderedSuits[1] = suitsarr[pairIndex];
	  
	   // add other 3 cards into last 3 arrays
	    int k = 2;
	    for (int i = 0; i < 5; ++i) 
		{
	        if (i != hiddenIndex && i != pairIndex)
	        {
	        	reorderedNums[k] = cardnumarray[i];
		        reorderedSuits[k] = suitsarr[i];
		        k++;
			}
	
	    }
	        
	}
	
	void odercard()
	{
		int position;
		if(diff<=6)
		{
			position=diff;
		}
		else
		{
			position=13-diff;
		}
		
		int original[3] = {2, 3, 4}; // the original positions
		int before[3] = {reorderedNums[2], reorderedNums[3], reorderedNums[4]};// help to finding the 2,3,4 indexes after oder
		
		int last3[3]={reorderedNums[2], reorderedNums[3], reorderedNums[4]};
		int small, medium, large;
		// finding a small value

		if (last3[0] < last3[1] && last3[0] < last3[2])
		{
			small = last3[0];
		} 
		else if (last3[1] < last3[0] && last3[1] < last3[2])
		{
		 	small = last3[1];
		}
		else
		{
			small = last3[2];
		} 
		// finding large value
		if (last3[0] > last3[1] && last3[0] > last3[2])
		{
			large = last3[0];
		 } 
		else if (last3[1] > last3[0] && last3[1] > last3[2])
		{
			large = last3[1];
		 }
		else 
		{
			large = last3[2];
		}
		// finding medium value
		medium = last3[0] + last3[1] + last3[2] - small - large;
		
		// finding the position
		
		if(position==1)
		{
			last3[0] = small;
			last3[1] = medium;
			last3[2] = large;
		}
		if(position==2)
		{
			last3[0] = small;
			last3[1] = large; 
			last3[2] = medium;
		}
		if(position==3)
		{
			last3[0] = medium;
			last3[1] = small;
			last3[2] = large;
		}
		if(position==4)
		{
			last3[0] = medium;
			last3[1] = large;
			last3[2] = small;
		}
		if(position==5)
		{
			last3[0] = large;
			last3[1] = small;
			last3[2] = medium;
		}
		if(position==6)
		{
			last3[0] = large;
			last3[1] = medium;
			last3[2] = small;
		}
		//save the last3 arry into after array
		int after[3];
		for(int i=0;i<3;i++)
		{
			after[i]=last3[i];
		}
		
		int newOrder[3];  // this will hold {3,4,2}

		// find originel indexes oder after oder the array
		for(int i = 0; i < 3; i++) 
		{
		    for(int j = 0; j < 3; j++) 
			{
		        if (after[i] == before[j]) 
				{
		            newOrder[i] = original[j];  // store the original index
		        }
		    }
		}
		// take indexes assign it in i1,i2,i3
		int i1=newOrder[0];
		int i2=newOrder[1];
		int i3=newOrder[2];
		
		//after oder last three and add all in to last 3 elemnts in reodernum
		reorderedNums[2] = after[0];
		reorderedNums[3] = after[1];
		reorderedNums[4] = after[2];
		
		string newsuits[3];
		newsuits[0]=reorderedSuits[i1];
		newsuits[1]=reorderedSuits[i2];
		newsuits[2]=reorderedSuits[i3];
		
		reorderedSuits[2]=newsuits[0];
		reorderedSuits[3]=newsuits[1];
		reorderedSuits[4]=newsuits[2];
			
		 
	}
	
	void showcard()
	{
		cout<<"\n 1st card is the hidden card of the belov oder"<<endl;
		for(int i=0;i<5;i++)
		{
			
			cout<<"card "<<i+1<<" = "<<reorderedSuits[i]<<" ";
			if(reorderedNums[i]==11)
			{
				cout<<"J"<<endl;
	
			}
			else if(reorderedNums[i]==12)
			{
				cout<<"Q"<<endl;
	
			}
			else if(reorderedNums[i]==13)
			{
				cout<<"K"<<endl;
	
			}
			else if(reorderedNums[i]==1)
			{
				cout<<"A"<<endl;
	
			}
			else
			{
				cout<<reorderedNums[i]<<endl;
			}
			cout<<endl;
			
		}
	}
    
};

 
int main() {
    string s1, s2, s3, s4, s5;
    string n1, n2, n3, n4, n5;
     // taking inputs 
    cout << "select 5 random cards \n put heart = HA , diamond = DI, club = CL, spade = SP \nexample: HA 3\n";
    cout << "card 1: ";
    cin >> s1 >> n1;
    cout << "\ncard 2: ";
    cin >> s2 >> n2;
    cout << "\ncard 3: ";
    cin >> s3 >> n3;
    cout << "\ncard 4: ";
    cin >> s4 >> n4;
    cout << "\ncard 5: ";
    cin >> s5 >> n5;
    
    // assign inputs in to card objects
    Card c1(s1, n1), c2(s2, n2), c3(s3, n3), c4(s4, n4), c5(s5, n5);

 
    
    // check if there invalide suits there
    string suit[5]={s1,s2,s3,s4,s5};
    for(int i=0;i<5;i++)
    {
    	if(suit[i]!="HA" && suit[i]!="DI" && suit[i]!="CL" && suit[i]!="SP" )
    	{
    		cout<<"invalide suits";
		   	exit(0);
		}
		
	}
	// equalent card check
	Card carr[5]={c1,c2,c3,c4,c5};
	for(int i=0;i<5;i++)
    {
    	for(int j=i+1;j<5;j++)
    	{
    		if(carr[i]==carr[j])
    		{
    			cout<<"here two cards are same, card should be different";
    			exit(0);
			}
		}
	}
	
	//creat assistant object and all function
	Assistence a;
	a.chooseHidenCart(c1, c2, c3, c4, c5);
	a.odercard();
	a.showcard();
	

    return 0;
}
