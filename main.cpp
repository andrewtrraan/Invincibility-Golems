#include <iostream>
#include <algorithm>
#include <windows.h>
#include <cstdlib>
#include <string>
#include <time.h>
#include <locale>

/*Andrew Tran
Description: guess the correct spell to fix the golems and R will output for right elements in right spot
and B will output for right elements in the wrong spot. 3 Difficultuies and 10 chances to get right spot.
Elemenets can be F(fire) W(water) A(air) E(earth)
ICS4U
Mr. Trink
Date Submitted: 04/04/2017
*/

using namespace std;

int main()
{
    //opening message
    //make text yellow
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
    cout<<"Oh no! The majestic Golems of Ankh Morpork City are causing trouble far and wide within the city. "<<endl;
    cout<<"Their owner Adora spent the money her Golems were supposed to be paid on Pineapple pizza and the Golems are on a rampage."<<endl;
    cout<<"One Golem has been reported to have lactated on the City Hall stairs, and another took a huge";
    cout<<"bite out of the Krispy Kreme doughnuts sign thinking it was a real doughnut, only to be disappointed."<<endl;
    cout<<"With his disappointment he released his fecal matter all over the roads and caused a flood on 5th Street East"<<endl;
    cout<<"The only way to have the Golems return to their calm state is to cast a spell containing a certain amount of elements."<<endl;


    cout<<"\nThese Elements Inlucde:"<<endl;

    //make text red
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
    cout<<"\nF for Fire"<<endl;

    //make text dark blue
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
    cout<<"W for Water"<<endl;

    //make text grey
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout<<"A for Air"<<endl;

    //make text green
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
    cout<<"E for Earth"<<endl;

    //make text grey
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
    cout<<"\nIt is your job to help save the city and depending on your mastery in Golem taming, you can prevent the Golems"<<endl;
    cout<<" from doing this again for a longer time."<<endl;
    cout<<"If you are a Master you can prevent the Golems from doing this again for 6x10^69 years"<<endl;
    cout<<"If you are Average at the mastery you can prevent the Golems form doing this again for 100 years"<<endl;
    cout<<"If you are a beginner that somehow figures out the spell, you receive a walnut and the Golems will not cause trouble 10 years"<<endl;


    //make text light grey
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
    cout<<"\nBeginner: 4 elements in the spell."<<endl;

    //make text maroon
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
    cout<<"Average: 6 elements in the spell."<<endl;

    //make text purple
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
    cout<<"Master: 8 elements in the spell."<<endl;

    //set the number of guesses to 1
    int numGuess =1;

    //the level the user will choose
    string level;

    //the array with the possible elements
    string possibleLetters = "FWAE";

    //the generated elements from the possible 4 elements
    string generatedLetters;

    //declare how many times to loop or the number of elemnts
    int toLoop=0;

    //to see if the current level is valid
    bool validLevel =false;


    //makes sure each run will have a new set of elements
    srand(time(NULL));

    //to see if user has right answer
    bool isRight = false;

    //varible that will hold what the user enters as their answer
    string userInput;
    do
    {


        //ask the user for their preferred level
        //make text yellow
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
        cout<<"\nWhat Mastery do you possess young padawan?: ";
        cin>>level;

        //converts what the user entrers into capitals
        transform(level.begin(), level.end(),level.begin(), ::toupper);

        //if the user chooses the beginner difficulty
        if(level == "BEGINNER")
        {
            generatedLetters ="    ";

            //number of times to loop in each for loop and number of elements in spell
            toLoop =4;

            //set the valid level choice to true
            validLevel=true;
        }

        //if the user chooses the average difficulty
        else if(level =="AVERAGE")
        {
            //average difficulty will have 6 elements
            generatedLetters ="      ";

            //number of times to loop in each for loop and number of elements in spell
            toLoop =6;

            //set the valid level choice to true
            validLevel=true;
        }

        //if the user chooses the master difficulty
        else if(level =="MASTER")
        {
            //master difficulty will have 8 elements
            generatedLetters ="        ";

            //number of times to loop in each for loop and number of elements in spell
            toLoop =8;

            //set the valid level choice to true
            validLevel=true;
        }
        else
        {

            //make text red
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout<<"The Mastery you have entered seems to be invalid."<<endl;
        }
        //keep looping until the user chooses a valid difficulty
    }
    while(validLevel==false);


    bool isValid =true;

    //generate the random elements from the possible elements bank
    for(int i=0; i<toLoop; i++)
    {
        generatedLetters[i]= possibleLetters[rand()%4];
        cout<<generatedLetters[i];

    }
    //create a temp array for the "B" outputs
    string tempArray = generatedLetters;
    cout<<endl;

    //getline(cin,userInput);
    do
    {

        //the number of guesses left
        int numLeft = 10-numGuess;
        do
        {
            //make text maroon
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);


            //let the user know how many guesses they have left
            cout<<"\nGuess num: "<<numGuess<<endl;

            //make text yellow
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
            //ask the user to input a guess
            cout<<"What spell shall you cast?("<<toLoop<<" Elements in your spell): ";
            cin>>userInput;

            //converts the guess to all capitals
            transform(userInput.begin(), userInput.end(),userInput.begin(), ::toupper);

            //if the user does not enter the correct number of elements
            if(userInput.size() !=toLoop )
            {

                //make text red
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                //tell the user to enter the correct number of elements depdending on difficulty
                cout<<"Please enter "<<toLoop<< " elements"<<endl;

                //set the boolean for the user's guess to false
                isValid =false;
            }


            //if the user enters the correct number of elements
            else
            {
                //set the boolean for the user's guess to true
                isValid =true;
            }

            //if the user enters an invalid element
            for(int i=0; i<toLoop; i++)
            {


                if(userInput[i] != 'F'&&userInput[i] != 'W'&&userInput[i] != 'A'&&userInput[i] != 'E')
                {

                    //adds 1 to the index number since index starts at 0 not 1
                    int q=i+1;

                    //set the boolean for the user's guess to false
                    isValid =false;

                    //make text red
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);

                    //let the user know where the invalid element is
                    cout<<"The "<<q<<" element is not a valid element"<<endl;
                }
            }

            //keep looping until the user's guess is valid
        }
        while(isValid !=true);


        //if the user guesses the correct combonation of elements
        if(userInput == generatedLetters)
        {
            //set the
            isRight =true;
        }
        else
        {

            for(int i=0; i<4; i++)
            {
                //if an element in the user's enter matches the generated element in the same spot
                if(userInput[i]==generatedLetters[i])
                {

                    //make text red
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                    cout<<"R";
                    //mark off the used up characters while checking for matches
                    userInput[i]= '&';
                    tempArray[i]= '#';
                }
            }
            for(int q =0; q<4; q++)
            {
                for(int i=0; i<4; i++)
                {
                    //if the element the user entered is in the array but in the wrong spot
                    if(userInput[q]== tempArray[i])
                    {

                        //make text blue
                        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                        cout<<"B";
                        tempArray[i]=false;
                    }
                    //tempArray[i]=true;

                }



            }
            //resets the temp array varibles so "B"'s will properly output in next guess if needed
            for(int z=0; z<4; z++)
            {
                tempArray[z] =generatedLetters[z];
            }

            //don't output any message when user is about to enter their last guess
            if(numGuess==10)
            {


                cout<<" "<<endl;
            }
            //output a message to motivate the user and let them know how many guesses are left
            else
            {

                //make text purple
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
                cout<<"\nYour spell was incorrect. Hurry up and get the right spell you have "<<numLeft<<" guesses left!"<<endl;

            }

        }
        //count for the number of guess attemps
        numGuess++;

        //keep looping until the user gets the right answer of exceeds 10 guesses
    }
    while((isRight !=true)&&(numGuess!=11));

    //if the user casts the correct spell
    if(isRight==true)
    {

        //make text green
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
        cout<<"\nThe City Of Ankh Morpork thanks you and your "<<level<<" mastery. We will dispose of Adora to prevent this from happening again" <<endl;
    }
    //if the user exceeds 10 guesses
    if(numGuess==11)
    {

        //make text grey
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
        cout<<"\nYou have failed us now the Golems will force feed you pineapple pizza"<<endl;
    }

    //output the correct spell at the end
    for(int i=0; i<toLoop; i++)
    {

        cout<<generatedLetters[i];


    }
    return 0;
}
