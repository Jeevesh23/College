#include<iostream>

using namespace std;

class election{

    public : int count[6];

    public: void vote();
            //void total(count[]);
            void display();
}o;

void election :: vote() {
    int n,i,choice;
    cout<<"Enter the number of votes casted: ";
    cin>>n;

    for(i=0;i<6;i++) {
        o.count[i]=0;
    }
    
    for(i=0;i<n;i++) {
        cout<<"Enter your vote: ";
        cin>>choice;
        switch(choice) {
            case 1: {
                o.count[1]++;
                break;
            }
            case 2: {
                o.count[2]++;
                break;
            }
            case 3: {
                o.count[3]++;
                break;
            }
            case 4: {
                count[4]++;
                break;
            }
            case 5: {
                o.count[5]++;
                break;
            }
            default:
                o.count[0]++;
            }
        }
}

void display() {
	printf("The results are as follows:\n");
	int i;
    for(i=1;i<6;i++) {
        printf("Candidate %d --> %d Votes\n",i, o.count[i]);

    }
    printf("Spoilt Ballot --> %d", o.count[0]);
}

int main() {
	o.vote();
	o.display();
	return 0;
}
/*
int main() {
    int count[6];
    int n,i,choice;
    cout<<"Enter the number of votes casted: ";
    cin>>n;

    for(i=0;i<6;i++) {
        count[i]=0;
    }
    
    for(i=0;i<n;i++) {
        cout<<"Enter your vote: ";
        cin>>choice;
        switch(choice) {
            case 1: {
                count[1]++;
                break;
            }
            case 2: {
                count[2]++;
                break;
            }
            case 3: {
                count[3]++;
                break;
            }
            case 4: {
                count[4]++;
                break;
            }
            case 5: {
                count[5]++;
                break;
            }
            default:
                count[0]++;
            }
        }
    
    printf("The results are as follows:\n");
    for(i=1;i<6;i++) {
        printf("Candidate %d --> %d Votes\n",i, count[i]);

    }
    printf("Spoilt Ballot --> %d", count[0]);
    }
    
    */
    
    
    
    /*
#include <iostream>

using namespace std;

int const size=50;

class ballot {
	int candidate;        //candidate you want to create for voting
	int vote[size];
	int ballot[6];

//static int spballot;            //spoil ballot

	public : void getdisplay(void);
};

int ballot :: spballot;

void ballot :: getdisplay(void)

{

cout<<\"\\n\\n\\nEnter how many candidate you want to make:-\";

cin>>candidate;

static int a,b,c,d,e;

a=0;

a=b=c=d=e;

cout<<\"\\nEnter 1-5 Integers\\n\";

for(int i=0;i< candidate;i++)

{

   cin>>vote[i];

  switch(vote[i])

  {

   case 1:ballot[a];

           a++;

          break;

     case 2:ballot[b];

           b++;

          break;

     case 3:ballot[c];

           c++;

          break;

     case 4:ballot[d];

           d++;

          break;

     case 5:ballot[e];

           e++;

          break;

  default    : ++spballot;

  }

}

//for displaying

   int choice;

  do

  {

   cout<<\"\\n\\n\\n\\nChoices Available\\n\";

     cout<<\"\\n1)  Scored By Ballot A\\n\";

     cout<<\"2)  Scored By Ballot B\\n\";

     cout<<\"3)  Scored By Ballot C\\n\";

     cout<<\"4)  Scored By Ballot D\\n\";

     cout<<\"5)  Scored By Ballot E\\n\";

     cout<<\"6)  Spoilt Ballot\\n\";

     cout<<\"7)  EXIT\\n\";

     cout<<\"Enter Your Choice :- \";

     cin>>choice;

     switch(choice)

     {

     case 1:    cout<<\"Scored By Ballot A is \"<<a;

                 break;

     case 2:    cout<<\"Scored By Ballot B is \"<<b;

                 break;

     case 3:    cout<<\"Scored By Ballot C is \"<<c;

                 break;

     case 4:    cout<<\"Scored By Ballot D is \"<<d;

           break;

     case 5:    cout<<\"Scored By Ballot E is \"<<e;

                 break;

     case 6:    cout<<\"Spoil Ballot were \"<<spballot;

                 break;

     case 7:    goto end;

     }

  }while(1);

end:

}

void main()

{

clrscr();

ballot o1;

o1.getdisplay();

}*/
