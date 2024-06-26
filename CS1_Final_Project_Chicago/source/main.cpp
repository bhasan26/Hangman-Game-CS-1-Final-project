#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <algorithm>
using namespace std;

// Function to choose a random word and its hint from files
pair<string, string> chooseRandomWordAndHint(const string &wordFilePath, const string &hintFilePath)
{
    // Read words and hints simultaneously
    ifstream wordFile(wordFilePath);
    ifstream hintFile(hintFilePath);

    if (!wordFile.is_open() || !hintFile.is_open())
    {
        cerr << "Error: Could not open one of the files. " << strerror(errno) << endl;
        return make_pair("", "");
    }

    vector<pair<string, string>> wordHintPairs;
    string word, hint;

    while (getline(wordFile, word) && getline(hintFile, hint))
    {
        wordHintPairs.push_back(make_pair(word, hint));
    }

    wordFile.close();
    hintFile.close();

    if (wordHintPairs.empty())
    {
        cerr << "Error: The files are empty or do not have matching word-hint pairs.\n";
        return make_pair("", "");
    }

    // Seed for random number generation
    srand(static_cast<unsigned int>(time(nullptr)));

    // Choose a random index from the vector
    int randomIndex = rand() % wordHintPairs.size();

    // Return the randomly chosen word and its hint
    return wordHintPairs[randomIndex];
}

void hints(string hintTwo)
{
    char ask;
    int num = rand() % 2;
    cout << "Seem like your having a bit of trouble." << endl;
    cout << "Would you like a hint? :) " << endl;
    cout << "   y/n" << endl;
    cin >> ask;
    string game[2] = {"heads", "tails"};
    if (ask == 'y')
    {
        cout << "Is that so?" << endl;
        cout << endl;
        cout << "You're going to have to earn that hint" << endl;
        cout << "heads or tails" << endl;
        string player;
        cin >> player;
        if (player == game[num])
        {
            cout << "Correct it was: " << game[num] << endl;
            cout << endl;
            cout << "Hint: " << hintTwo << endl;
        }
        if (player != game[num])
        {
            cout << "Wrong it was: " << game[num] << endl;
            cout << "However I'm nice here it is." << endl;
            cout << endl;
            cout << "Hint: " << hintTwo << endl;
        }
    }
    if (ask == 'n')
    {
        cout << "Understood." << endl;
    }
}

char userInput() // Players Input goes inside here.
{
    char letter;
    cout << "__________________________________________________________" << endl;
    cout << "Please enter letter: " << endl;
    cin >> letter;
    return letter;
}

void displayHangman(int error)
{
    cout << "          +----+" << endl;
    cout << "          |    |" << endl;
    if (error == -1) // if user wins the game
    {
        cout << "              |" << endl;  // prints an empty line to separate the head from the body.
        cout << "        \\0/   |" << endl; // displays the smiley face of the winning hangman
        cout << "          |    |" << endl; // to seprate the face from body thats why we use this at this point
        cout << "        / \\   |" << endl; // displays the arms of the hangman,
    }
    /// if user made mistake than hanging body of Hangman will start to print
    else
    {
        if (error > 0)
            cout << "          |    0" << endl; // if error is greater than 1 , it will print Head
        else
            cout << "          |" << endl; // else just a | slash of hanger
        if (error > 1)
            cout << "          |    |" << endl; // if user made 2 errors than the neck of hangman will print
        else                                    // it will seprate head from the body
            cout << "          |" << endl;
        if (error > 2)
        {
            cout << "          |   /|"; // if greater than 2 left arms of hangman
        }
        if (error > 3)
        {
            cout << "\\" << endl; // if greater than 3 right arms of hangman
        }
        if (error > 4)
        {
            cout << "          |   /"; // if error greater than 4 prints the left leg
        }
        if (error > 5) /// if greater than 5 it will print both right anf left legs of hangman body
        {
            cout << " \\   " << endl;
        }
    }
}

int printer(int size, string word, string hint, int a)
{
    char correctGuess[size];
    char incorrect[a];

    for (int i = 0; i < size; i++)
    {                          // Is only used once
        correctGuess[i] = '_'; // Fills up that array so that the once the input is placed it will be replaced by the letter
    }

    int strikes = 0; // Track the number of incorrect guesses

    while ((strikes < a) || (strikes != a)) // Defines how many rounds the player has based off the max number of strikes.
    {
        char letter = userInput(); // User's guesses
        bool correct = false;      // Helps with checking the correct

        for (int j = 0; j < size; j++)
        {
            if (letter == word.at(j)) // Helps with placing the letter into one of the two arrays
            {
                correctGuess[j] = letter; // If correct it will be placed inside the correct array
                // body funtion call so they know how many body parts they have left to pick from. (should be based off the strikes)
                displayHangman(strikes);  //
                cout << endl;
                correct = true;
            }
        }

        if (!correct) // The above loop will be skipped if the the letter doesn't match.
        {
            incorrect[strikes] = letter; // Place the letter inside the icorrect array based off the number of the strikes
            strikes++;
            // body function call for how body part you call updated version. (based off strikes)
            displayHangman(strikes);
            cout << endl;
        }

        for (int k = 0; k < size; k++) //
        {
            cout << correctGuess[k] << ' ';
        }

        cout << endl;

        if (string(correctGuess) == word) // If array matches the word then the player wins.
        {
            cout << "You win!" << endl;
            break; // Automatically exits the function
            return strikes = a;
        }

        cout << "Wrong letters: ";        // Will print out the wrong letters
        for (int d = 0; d < strikes; d++) // The amount of letters printed out is based off the number of strikes recieved
        {
            cout << incorrect[d] << " "; // Letters will be printed from here until the are to the same number as strikes
        }

        cout << endl;
        cout << "Max tries left " << (a - strikes) << endl;
        cout<<endl;
        if (strikes == (a / 2))
            {
                hints(hint);
                cout<<endl;
            }
    }

    if (strikes == a) // This automatically print out that you lost.
    {
        cout << "You LOSE!!! :(" << endl;
        displayHangman(a);
    }
    cout << "The word is: " << word << endl;
    return strikes;
}

void welcome(int siZe, int a) // Introduction to the Player
{
    cout << "         Welcome to Hangman!!!    :)" << endl;
    cout << "---------------------------------------" << endl;
    cout << endl;
    cout << "The rules to this game are easy and simple." << endl;
    cout << "* Your goal is to guess the word correctly or else BOB is hanged" << endl;
    // Should call the whole body function to display. HERE
    cout << endl;
    cout << "            BOB" << endl;
    displayHangman(a);
    cout << endl;
    cout << "You wouldn't want that on your record.  ;)" << endl;
    cout << "* You my friend have a total of " << a << " attempts" << endl; // displays the amount of attempts the player has
    cout << "So make sure you don't make it to zero. Or else." << endl;
    cout << endl;
    cout << "* Are you ready?" << endl;
    // Gives player the option for how ready they are.
    char ans;
    cout << "   y/n" << endl;
    cin >> ans;
    cout << endl;
    if (ans == 'n')
    {
        cout << "To late to turn back. Should've thought about that before opening this game" << endl;
    }
    else if (ans == 'y')
    {
        cout << "Good" << endl;
    }
    cout << endl;
    cout << "Now let the game begin" << endl;
    cout << "GOODLUCK!!! :)" << endl;
    cout << endl;

    // Shows the player how long their word is:
    for (int a = 0; a < siZe; a++) // Should only be printed out once so that the player can know how many letter spaces.
    {
        cout << "_ ";
    }
    cout << " <---- This is how long your word is." << endl;
}

int main()
{
    string wordFilePath = "source/your_word_list.txt";
    string hintFilePath = "source/your_hint_list.txt";

    pair<string, string> selectedWordAndHint = chooseRandomWordAndHint(wordFilePath, hintFilePath);

    if (selectedWordAndHint.first.empty())
    {
        return 1;
    }

    string selectedWord = selectedWordAndHint.first;
    string wordHint = selectedWordAndHint.second;
    int size = selectedWord.length();

    int b = 6;        // Amount of attempts given which can be changed. Change can give more of a challenge to player.
    welcome(size, b); // Calls the welcome funtion
    printer(size, selectedWord, wordHint, b);

    cout << endl;
    cout << "Thank You for playing." << endl;
    cout << "We hope this was a memorable expierence for you. For Bob it'll be one he will never forget." << endl;
    cout << "Remember to stay out of trouble." << endl;
    cout << "Farewell :)" << endl;
    cout << endl;
    return 0;
}