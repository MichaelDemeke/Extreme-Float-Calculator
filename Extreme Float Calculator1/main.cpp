#include <iostream>
#include <stack>
#include <bits/stdc++.h>
#include <ctype.h>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;
//Michael Demeke
//Tsion Fitsum
//Natneal Tsegaye


struct Node{ // Node decleration
    int data;
    struct Node * next;
    struct Node * prev;
};

struct Node * head; // head
struct Node * tail; // tail


// creating a new node
struct Node* xnewnode(char x){
    struct Node * xn = (struct Node*)malloc(sizeof(struct Node)); // create new node
    int ConvertedValue = x - '0'; // converting the char data type into int
    xn->data=ConvertedValue; // inserting the data in the node
    xn->next = NULL; // initallizing next
    xn->prev = NULL; // initallizing prev
    return xn; // return the node back
};


// initalizing the new node that ha been created
void InsertDigit(char x){

        struct Node* n = xnewnode(x); // new node inherating the node structer from node
// assigning the next and prev value of a node
    // if the node is empty
        if (tail==NULL){
            head = tail = n; // the new node would be both the
            return;
        }
		tail->next = n; // the new node would be after the
		n->prev = tail; // the new node's prevous value will be the last node
		tail = n; // now the new node i the last node
}



//gets a number from the keyboard
void getExtreme(){
	string num1,num2;
	char separator='$';


    cout<<"Enter num1 : ";
    cin>>num1;
    cout<< separator;
     cout<<"Enter num2:";
      cin>>num2;
    for (int i = 0; i < num1.length(); i++)
        {
            InsertDigit(num1[i] );
        }


        InsertDigit(separator);

    for (int i = 0; i < num2.length(); i++)
    {
         InsertDigit(num2[i] );
    }

}


// Display the Two Numbers
void Display(){
    Node * temp = head; // assigning a a temp node to head
     cout<< "Number 1 -> " ;
    while (temp != NULL){ // along as there is data in the linked list
       if(temp->data == -12 ){ // -12 is the int value of '$' that separate the 2 numbers
            cout<<endl;  // to end the first number
            cout<<"Number 2 -> " ; // the start of the second number
            temp=temp->next; // go to the next node skip this node don't print out
       }
       else{
        cout<< temp->data << " "; // write the data in the node
        temp=temp->next; // go to next node
       }
      }
     cout<<endl; // end of the second number

}

void trimZeros()
	{
int x=0;
int y=0;
        Node * temp = head; // assigning a a temp node to head
     cout<< "Number 1 -> " ;
    while (temp != NULL){ // along as there is data in the linked list
       if(temp->data == -12 ){ // -12 is the int value of '$' that separate the 2 numbers
            cout<<endl;  // to end the first number
            cout<<"Number 2 -> " ; // the start of the second number
            temp=temp->next; // go to the next node skip this node don't print out
            x=0;
            y=0;
       }
       else{
        if (x==0){
            if(temp->data == 0 && y==0)
                 temp=temp->next; // go to next node
            else{
                cout<< temp->data ; // write the data in the node
                temp=temp->next; // go to next node
                y++;
            }

      }

	}

    }
     cout<<endl; // end of the second number
}

void removeDigit(){
    int x;
    int y;
    cout<<"Insert the digit that you want to remove " << endl;
    cin>>x;
a:  cout<<"From which number do you want to delete the digit " << endl;
    cout<<" "<< endl;
    cout<<"1,Number one " << endl;
    cout<<"2,Number two " << endl;
    cin>>y;

  Node* num1;
  Node* num2;

 num1=head;
 num2=head;

while(num2->data!= -12){ // until the separate is found
             num2=num2->next; // go to the last value of the first number
        }
    num2=num2->next; // the last value of the first number has found

if (y==1){
        while(num1->data != -12){

        if(num1->data==x){
                 num1->prev->next=num1->next;
                 num1->next->prev= num1->prev;
              //   delete num1;

               /*  temp=tail;
                 tail->prev->next=NULL;
                 tail=tail->prev;
                 delete temp;
             */
            }

        num1=num1->next;
        }
    }
else if (y==2){
        while(num2->next!=NULL){
          /*
            if(tail==NULL){

                cout<<"list is empty"<<endl;
                }
            */

        if(num2->data==x){
                 num2->prev->next=num2->next;
                 num2->next->prev= num2->prev;
             //   delete num2;

               /*  temp=tail;
                 tail->prev->next=NULL;
                 tail=tail->prev;
                 delete temp;
             */
            }

        num2=num2->next;
        }
    }
 else{
    cout<<" you have put the wrong input"<<endl;
    goto a;
 }



  Display();

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// addition of the 2 numbers
void Add(){
    Node * num1 = head; // refer to the first number starting from the head
    Node * num2 = tail;// refers to the second number starting from tail
    stack<int> s; // stack decleration with int type
    int y=0; // y refers to the sum of the 2 numbers
    int m=0;// m refers to the additonal value added to the next numbers
    int z=0;// z refers to the value pushed on the stack
    int done=0; // it shows if the first number is on head and it has ended
    while(num1->data!= -12){ // until the separate is found
             num1=num1->next; // go to the last value of the first number
        }
    num1=num1->prev; // the last value of the first number has found

// lets go to the additon
while(done!=1 || num2->data!= -12 ){ //making sure that both numbers are not done
    // if the first number ended but the second didn't end
    if (done==1 && num2->data!= -12){
            y = num2->data + m;  // only add the second number and the additonal value (if there is any)

                if(y > 9){
                    string x = to_string (y) ; // converting y to int type to separate the 2 number if the sum is a 2 digte
                    z = x[1] - '0'; // the first digte is z
                    m = x[0] - '0';// the second digte is x
                    s.push(z); // get the first digte into stack
                }

                else{
                s.push(y); // if it only have one diget just add it into stack
                m=0; // no additional value back to 0
                z=0;// back to 0
                }
        num2=num2->prev; // go to the next number in number 2
    }
    // if the second number ended but the first didn't end
    else if (done!=1 && num2->data== -12){
            y = num1->data + m; // only add the first number and the additonal value (if there is any)
            string x = to_string (y) ;
                if(y > 9){
                    string x = to_string (y) ; // converting y to int type to separate the 2 number if the sum is a 2 digte
                    z = x[1] - '0'; // the first digte is z
                    m = x[0] - '0';// the second digte is x
                    s.push(z); // get the first digte into stack
                }

                else{
                s.push(y); // if it only have one diget just add it into stack
                m=0; // no additional value back to 0
                z=0;// back to 0
                }
        // go to the next first number
        if(num1!= head)
            num1=num1->prev; // if it is not a head node then go to the prev node
        else{
            num1=head; // but if it is a head node it got no where else to go
            done=1; // so make done 1 to show it has ended
      }
    }
// if both didn't end
    else {
            y = num1->data + num2->data + m;

                if(y > 9){
                    string x = to_string (y) ; // converting y to int type to separate the 2 number if the sum is a 2 digte
                    z = x[1] - '0'; // the first digte is z
                    m = x[0] - '0';// the second digte is x
                    s.push(z); // get the first digte into stack
                }

                else{
                s.push(y); // if it only have one diget just add it into stack
                m=0; // no additional value back to 0
                z=0;// back to 0
                }
    // go to the next first number
        if(num1!= head)
            num1=num1->prev; // if it is not a head node then go to the prev node
        else{
            num1=head; // but if it is a head node it got no where else to go
            done=1; // so make done 1 to show it has ended
      }
 num2=num2->prev; // go to the next number in number 2
}
}

// after they are both done there could be additonal value left
    if(m > 0){
        s.push(m); // add that on the stack
    }

// viewing the elements in the stack
cout<<"Additon:- " ;
while (!s.empty()){
        cout << s.top() ;
        s.pop();
 }
cout<< endl;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Sub(){
    Node * num1 = head; // refer to the first number starting from the head
    Node * num2 = tail;// refers to the second number starting from tail
    stack<int> s; // stack deceleration with int type
    int y=0; // y refers to the sum of the 2 numbers
    int m=0;// m refers to the additional value added to the next numbers
    int done=0; // it shows if the first number is on head and it has ended

    while(num1->data!= -12){ // until the separate is found
             num1=num1->next; // go to the last value of the first number
        }
    num1=num1->prev; // the last value of the first number has found

// lets go to the additon
while(done!=1 || num2->data!= -12 ){ //making sure that both numbers are not done
    // if the second number ended but the first didn't end
     if (done!=1 && num2->data== -12){
            y = num1->data + m; // only add the first number and the additonal value (if there is any)
             s.push(y);
        // go to the next first number
        if(num1!= head)
            num1=num1->prev; // if it is not a head node then go to the prev node
        else{
            num1=head; // but if it is a head node it got no where else to go
            done=1; // so make done 1 to show it has ended
      }
    }
// if both didn't end
    else {

        if(num1->data > num2->data || num1->data == num2->data){
            y=num1->data + m - num2->data;
            s.push(y);
            m=0;
        }
        else if(num1->data < num2->data){
            y=num1->data + 10 + m - num2->data;
            s.push(y);
            m=-1;
        }


    // go to the next first number
        if(num1!= head)
            num1=num1->prev; // if it is not a head node then go to the prev node
        else{
            num1=head; // but if it is a head node it got no where else to go
            done=1; // so make done 1 to show it has ended
      }
    num2=num2->prev; // go to the next number in number 2
}
}


// after they are both done there could be additonal value left


// viewing the elements in the stack
cout<<"Substraction:- " ;
while (!s.empty()){
        cout << s.top() ;
        s.pop();
 }
cout<< endl;
}

void Mul(){
    Node * num1 = head; // refer to the first number starting from the head
    Node * num2 = tail;// refers to the second number starting from tail // the last value of the first number has found
  stack <int> a; //stack number 1
  stack <int> b;// stack number 2
  stack <int> c;// stack number 3
  stack <int> d;// stack number 4
    int done=0; // checks if the frist number is done or not
    int y=0; // y refers to the sum of the 2 numbers
    int m=0;// m refers to the additonal value added to the next numbers
    int z=0;// z refers to the value pushed on the stack
    int w=0;
    int check=0;
while(num1->data!= -12){ // until the separate is found
             num1=num1->next; // go to the last value of the first number
        }
num1=num1->prev; // found the last digt of num one

Node * temp = head; // assign temp to head



while (num2->data!= -12){ // first while loop start
    done=0; // restss the
    num1=temp;
    while(num1->data!= -12){ // until the separate is found
             num1=num1->next; // go to the last value of the first number
        }
    num1=num1->prev;
    while (done!=1){
            y=num1->data * num2->data + m;

                if(y > 9){
                    string x = to_string (y) ; // converting y to int type to separate the 2 number if the sum is a 2 digte
                    z = x[1] - '0'; // the first digte is z
                    m = x[0] - '0';// the second digte is x
                    a.push(z); // get the first digte into stack
                }

                else{
                a.push(y); // if it only have one diget just add it into stack
                m=0; // no additional value back to 0
                z=0;// back to 0
                }

                        if(num1!= head)
                        num1=num1->prev; // if it is not a head node then go to the prev node
                    else{
                        num1=head; // but if it is a head node it got no where else to go
                        done=1; // so make done 1 to show it has ended
                        }
            }
    if(m > 0){
             a.push(m);
             m=0;
    }
             w++;

    while (!a.empty()){
            d.push(a.top());
            a.pop();
     }



    if(w==1){
            while (!d.empty()){
                b.push(d.top());
                d.pop();

            }

            while (!b.empty()){
                c.push(b.top());
                b.pop();
            }

    }



    else{
         int check2=0;
        while(!d.empty() || !c.empty()){
        // if the first number ended but the second didn't end
            if(d.empty() && !c.empty()){
                    y = c.top() + m;
                    m=0;
                    b.push(y);
                    c.pop();

            }
            else if(!d.empty() && c.empty()){
                    y = d.top() + m;
                    m=0;
                    b.push(y);
                    d.pop();

            }
            else{

               if(check2==0){
                for(int i=1;i<=check;i++){
                    b.push(c.top());
                    c.pop();
                    }
                }
                else{
                    y = c.top() + d.top() + m;

                            if(y > 9){
                                    string x = to_string (y) ; // converting y to int type to separate the 2 number if the sum is a 2 digte
                                    z = x[1] - '0'; // the first digte is z
                                    m = x[0] - '0';// the second digte is x
                                    b.push(z); // get the first digte into stack

                                }

                            else{
                                b.push(y); // if it only have one diget just add it into stack
                                m=0; // no additional value back to 0
                                z=0;// back to 0

                                }
                    c.pop();
                    d.pop();
                    }
                check2++;
                }

        }

   while (!b.empty()){
            c.push(b.top());
            b.pop();
     }


    }
    check++;
    num2=num2->prev;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


    while (!c.empty()){
              b.push(c.top());
                c.pop();
         }
         cout<<"Multiplication -> " ;
    while(!b.empty()){
            cout << b.top();
            b.pop();
         }
        cout<< endl;

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void substact(stack<int> &a,stack<int> &b, string x, int n){

                string h;
                string g;
    stack<int> c; // stack decleration with int type
    int y=0; // y refers to the sum of the 2 numbers
    int m=0;// m refers to the additonal value added to the next numbers
    int z=0;// z refers to the value pushed on the stack
               // int n=0;
    while(!b.empty()|| !a.empty()){ //making sure that both numbers are not done
            // if the second number ended but the first didn't end
             if (!b.empty() && a.empty()){
                    y = b.top() + m; // only add the first number and the additonal value (if there is any)
                     c.push(y);
                    g = to_string (y);
                     h.append(g); // copy it into a string so that it can be transfered into an array
                    n++;
                    b.pop();
            }
        // if both didn't end
            else {

                if(b.top() > a.top() || b.top() == a.top()){
                    y=b.top() + m - a.top();
                    c.push(y);
                    if(n==0)
                        h=to_string (y);
                    else
                        g = to_string (y);

                    h.append(g); // copy it into a string so that it can be transfered into an array
                    n++;
                    m=0;
                }
                else if(b.top() < a.top()){
                    y=b.top() + 10 + m - a.top();
                    c.push(y);
                    if(n==0)
                        h=to_string (y);
                    else
                        g=to_string (y);

                    h.append(g); // copy it into a string so that it can be transfered into an array
                    n++;
                    m=-1;
                }

            b.pop();
            a.pop(); // go to the next number in number 2
            }
        x=h;

}
}
int compare(stack<int> &a, string h){
                int u=0;
                int w=0;
                int x=0;
                int comp=0;
                bool found2=true;
                while(!a.empty() && u<h.length() ){
                    if(h[u]==a.top() && found2!=false){

                        }
                    else if(h[u]>a.top() && w==0){
                        comp=1;
                        w++;
                        found2=false;
                    }
                    else if(h[u]<a.top() && x==0){
                        comp=2;
                        x++;
                        found2=false;
                    }
                    else
                        found2=false;
                        u++;
                        a.pop();
                }
    if(comp==1)
        return -1;
    else if(comp==2)
        return 1;
    else
        return 0;
}

void Adding(int x, int o, string * quote){
    string num1 = quote[x];
    string num2 = quote[o];
    stack<int> s; // stack decleration with int type
    int y=0; // y refers to the sum of the 2 numbers
    int m=0;// m refers to the additonal value added to the next numbers
    int z=0;// z refers to the value pushed on the stack
    int p=0;
while(p<num1.length() || p<num2.length()){
    // if the first number ended but the second didn't end
    if (p>=num1.length() && p<num2.length()){
            y = num2[p] + m;  // only add the second number and the additonal value (if there is any)

                if(y > 9){
                    string x = to_string (y) ; // converting y to int type to separate the 2 number if the sum is a 2 digte
                    z = x[1] - '0'; // the first digte is z
                    m = x[0] - '0';// the second digte is x
                    s.push(z); // get the first digte into stack
                }

                else{
                s.push(y); // if it only have one diget just add it into stack
                m=0; // no additional value back to 0
                z=0;// back to 0
                }
        p++; // go to the next number in number 2
    }
    // if the second number ended but the first didn't end
    else if (p<num1.length() && p>=num2.length()){
            y = num1[p] + m; // only add the first number and the additonal value (if there is any)
            string x = to_string (y) ;
                if(y > 9){
                    string x = to_string (y) ; // converting y to int type to separate the 2 number if the sum is a 2 digte
                    z = x[1] - '0'; // the first digte is z
                    m = x[0] - '0';// the second digte is x
                    s.push(z); // get the first digte into stack
                }

                else{
                s.push(y); // if it only have one diget just add it into stack
                m=0; // no additional value back to 0
                z=0;// back to 0
                }
        p++;
    }
// if both didn't end
    else {
            y = num1[p] + num2[p] + m;

                if(y > 9){
                    string x = to_string (y) ; // converting y to int type to separate the 2 number if the sum is a 2 digte
                    z = x[1] - '0'; // the first digte is z
                    m = x[0] - '0';// the second digte is x
                    s.push(z); // get the first digte into stack
                }

                else{
                s.push(y); // if it only have one diget just add it into stack
                m=0; // no additional value back to 0
                z=0;// back to 0
                }
            p++;
    }
}

// after they are both done there could be additonal value left
    if(m > 0){
        s.push(m); // add that on the stack
    }

// viewing the elements in the stack
cout<<"Division:- " ;
while (!s.empty()){
        cout << s.top() ;
        s.pop();
 }
cout<< endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
    getExtreme();
    int choice;
    while(1){
        int data;

        cout<<"\n 1. Delete number \n"<<endl;
        cout<<"\n 2. Add the numbers\n"<<endl;
        cout<<"\n 3. Subtract the numbers \n"<<endl;
        cout<<"\n 4. multiply the numbers \n"<<endl;
        cout<<"\n 6. trim the zeros \n"<<endl;
         cout<<"\n 7. Exit \n"<<endl;
        cout<<"Enter the option: ";
        cin>>choice;
        switch(choice){
            case 1:
                removeDigit();
                break;
            case 2:
                Add();
                break;
            case 3:
                Sub();
                break;
             case 4:
                Mul();
                break;
            case 5:
                trimZeros();
                break;
            case 6:
                exit(0);
                break;
        }
    }
  cout<<"***************************************EXTREME FLOAT CALCULATOR********************************************  "<<endl;
  cout<<"**"<<endl;
  cout<<"**"<<endl;
  cout<<"**"<<endl;
  cout<<"**"<<endl;
  cout<<"**"<<endl;
    cout<<"**********************************************************************************************************  "<<endl;



    return 0;
}

