
#include <iostream>
#include <string>
#include <ctime>
#include <random>
using namespace std;

// 16 8  4  2 1
// 64 32 16 8 4 2 1 
//    0  1  2 3 4 5 6     
//Total number of rounds (iterations)
const int NUM_ROUNDS = 7; 
//total number of teams
const int NUM_TEAMS = 64;

// Historic Seed / Win data
// Really only need half of this, teams are either the same, or first team is higher seeded
// entries represent the probability of first team beating second team
const float GAME_STATS[16][16] = {
//1      2      3      4      5      6      7      8      9      10     11     12     13     14     15     16
{ 0.500, 0.556, 0.600, 0.714, 0.837, 0.700, 0.800, 0.800, 0.930, 0.850, 0.850, 0.900, 0.940, 0.900, 0.950, 0.993}, //Seed one playing X
{ 0.000, 0.500, 0.611, 0.600, 0.650, 0.767, 0.683, 0.750, 0.750, 0.660, 0.833, 0.780, 0.850, 0.890, 0.938, 0.920}, //Seed two playing X
{ 0.000, 0.000, 0.500, 0.550, 0.600, 0.600, 0.625, 0.700, 0.700, 0.714, 0.640, 0.750, 0.800, 0.847, 0.850, 0.880}, // 3
{ 0.000, 0.000, 0.000, 0.500, 0.560, 0.580, 0.600, 0.600, 0.630, 0.680, 0.700, 0.667, 0.785, 0.850, 0.850, 0.900}, // 4
{ 0.000, 0.000, 0.000, 0.000, 0.500, 0.520, 0.570, 0.650, 0.600, 0.650, 0.650, 0.645, 0.842, 0.800, 0.850, 0.900}, // 5
{ 0.000, 0.000, 0.000, 0.000, 0.000, 0.500, 0.600, 0.550, 0.600, 0.667, 0.625, 0.680, 0.730, 0.875, 0.800, 0.800}, // 6
{ 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.500, 0.530, 0.550, 0.604, 0.600, 0.650, 0.700, 0.800, 0.800, 0.750}, // 7
{ 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.500, 0.500, 0.550, 0.550, 0.600, 0.660, 0.650, 0.700, 0.900}, // 8
{ 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.500, 0.550, 0.550, 0.550, 0.600, 0.650, 0.700, 0.900}, // 9
{ 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.500, 0.520, 0.600, 0.650, 0.700, 0.800, 0.680}, // 10
{ 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.500, 0.550, 0.600, 0.800, 0.650, 0.650}, // 11
{ 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.500, 0.750, 0.600, 0.650, 0.800}, // 12
{ 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.500, 0.520, 0.600, 0.750}, // 13
{ 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.500, 0.550, 0.580}, // 14
{ 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.500, 0.550}, // 15
{ 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.000, 0.500}, // 16
};

class Team{
    public:
    //Attributes
        // For now we are going to pretend it is not an issue to have these be public, and in this file
        string team_name; //name of the team in the tournament
        int seed_num; //seed digit of the team
        //Running 'position' in the rounds
        // index 0: starting 64
        //       1: 32
        //       2: 16
        //       3: 8
        //       4: 4
        //       5: 2
        int round_position[NUM_ROUNDS]; 

    //Behaviors
        //default constructor
        Team(){
            team_name = "No Team";
            seed_num = 0;

            for(int i = 0; i < NUM_ROUNDS; i++ ){
                round_position[i] = 0;
            }
        }

        //variable constructor
        Team(string name, int digit){
        //has a team name and a seed number that is determined in the main function
            team_name = name;
            seed_num = digit; 

            //Clear position
            for(int i = 0; i < NUM_ROUNDS; i++ ){
                round_position[i] = 0;
            }
        }

        //variable constructor, with position
        Team(string name, int digit, int pos64){
        //has a team name and a seed number that is determined in the main function
            team_name = name;
            seed_num = digit; 

            //Clear position
            for(int i = 0; i < NUM_ROUNDS; i++ ){
                round_position[i] = 0;
            }
            round_position[0] = pos64;
        }

        //Print function
        string print(){
            string seed_string = to_string(seed_num);
            if(seed_string.length() == 1){ // Check for length (i.e. "1" is different than "11")
                seed_string = " " + seed_string; //add a space in front (to line up)
            }
            //                 Might as well print the see info with the name
            //                 that won't change during the program
            return team_name + "(" + seed_string + ")";
        }
};

//Fill in data for the array tSet
void initializeTeams(Team tSet[]);

// Pull a specific team out of the team set
// This is used by the printRegion function
// input: tSet full of team info
//        regionOffest: 0/1/2/3 (internal offset for each region)
//        roundIndex: which round are we dealing with (0 for 64, 1 for 32, 2 for 16...)
//        position: which position are we trying to pull from, based off of valid index of round and region
string findTeam(Team tSet[], int region, int roundIndex, int position);

// Pull a specific team out of team set
// This is used by runRound
// input tSet - collection of teams
//       roundIndex - which round of the tournament are we one
//       position - which team position do we want
// return: index in tSet for correct team
int findTeam(Team tSet[], int roundIndex, int position);

//Display to the screen all the info in tSet
// input: assumes tSet is full of valid Team data (importantly the position numbers)
//        region: 1-4
//                1: 1-16
//                2: 17-32 ...
// output: print well formatted bracket to terminal
void printRegion(Team tSet[], int region);

//Simple utility to call print Region for all four regions
void printAllRegions(Team tSet[]);

//Just print the final 4 and on
void printFinal(Team tSet[]);

//Simple user input to continue
int pause(){
    int val;
    cout << "Enter number to continue..." << endl;
    cin >> val;
    return val;
}

// Primary looping function to evaluate and advance tournament
// input: tSet - collection of teams, should have value round information up until this point
//        round - current round being evaluated, will fill in positions for the next round
// post: round_position for each team is updated
void runRound(Team tSet[], int round);

// Pit two teams up against each other!
// Input t1 and t2 are playing eachother
// Returns the winner of the two teams (0 for T1, 1 for T2)
// probability is based on historic data
int playGame(Team t1, Team t2);

int main(){
    srand(time(NULL));

    //Collection of teams
    Team teams[NUM_TEAMS];

    //Set up teams
    initializeTeams(teams);
    //Print Start of tournament
    printAllRegions(teams);

    cout << "Tournament seeded! Ready to start playing games." << endl;
    pause();

    //Loop over number of rounds
    //TODO:: This could be more easily expandable to just run until all games are done
    for(int i = 0; i < NUM_ROUNDS-1; i++ ){
        // Run games
        runRound(teams,i);
        // Print new bracket
        printAllRegions(teams);

        if(i > 2) { //After the final four are determined, print final bracket
            //Final Bracket
            printFinal(teams);
        }

        if(i < NUM_ROUNDS-2){ //Don't wait the last loop
            // Wait for user input
            pause();
        }
    }    

    cout << "Tournament over! Congrats to " << findTeam(teams,1,NUM_ROUNDS-1,1) << endl;

}

string findTeam(Team tSet[], int region, int roundIndex, int position){
    //Figure out region offset for region and round
    // For round 0:
    // region 1: 1
    // region 2: 17
    // region 3: 33
    // region 4: 49
    // round 0
    // region offset: 16
    // round 1
    // region offset: 8
   
    //                   0/1/2/3
    //                               round 0:       7 - 2 - 0 = 2^4 = 16
    int regionOffset = (region-1) * pow(2, ( ( NUM_ROUNDS - 3 ) - roundIndex ));

    //Loop through all teams, searching for the right position
    for(int i = 0 ; i < NUM_TEAMS; i++ ){
        //                         VV make sure we are in the right round
        //                                        VV Check position
        if( tSet[i].round_position[roundIndex] == regionOffset + position){
            return tSet[i].print(); // if we find the right one, return it's name and seed
        }
    }
    
    //We didn't find anything! As in the game has not been seeded yet. Default 'fill'
    //return "XXXXXXXXXXXXXXXXXXX"; //Testing
    return "                   ";
}

int findTeam(Team tSet[], int roundIndex, int position){
    //Loop through all teams, searching for the right position
    for(int i = 0 ; i < NUM_TEAMS; i++ ){
        //                         VV make sure we are in the right round
        //                                        VV Check position
        if( tSet[i].round_position[roundIndex] == position){
            return i; // if we find the right one, return it's index
        }
    }
    
    //We didn't find anything! This should not happen
    cout << "Error! Didn't find a team in findTeam!" << endl;
    return -1;
}

void printRegion(Team tSet[], int region){
    //This is a little complicated. I am going to break this up in to region

    cout << findTeam(tSet,region       ,0,1) << endl;
    cout << "-------------------|"           << findTeam(tSet,region       ,1,1)  << endl;
    cout << findTeam(tSet,region       ,0,2) << "|-------------------|"           << endl;
    cout << "-------------------|"           << "                   |"            << findTeam(tSet,region       ,2,1) << endl;
    cout << findTeam(tSet,region       ,0,3) << "                    |"           << "-------------------|"           << endl;
    cout << "-------------------|"           << findTeam(tSet,region       ,1,2)  << "|                   |"          << endl;
    cout << findTeam(tSet,region       ,0,4) << "|-------------------|"           << "                   |"           << endl;
    cout << "-------------------|"           << "                     "           << "                  |"            << findTeam(tSet,region       ,3,1) << endl;
    cout << findTeam(tSet,region       ,0,5) << "                     "           << "                   |"           << "-------------------|"           << endl;
    cout << "-------------------|"           << findTeam(tSet,region       ,1,3)  << "                    |"          << "                   |" << endl;
    cout << findTeam(tSet,region       ,0,6) << "|-------------------|"           << "                   |"           << "                   |" << endl;
    cout << "-------------------|"           << "                   |"            << findTeam(tSet,region       ,2,2) << "|                   |"<< endl;
    cout << findTeam(tSet,region       ,0,7) << "                    |"           << "-------------------|"           << "                   |" << endl;
    cout << "-------------------|"           << findTeam(tSet,region       ,1,4)  << "|                   "           << "                    |"<< endl;
    cout << findTeam(tSet,region       ,0,8) << "|-------------------|"           << "                    "           << "                   |" << endl;
    cout << "-------------------|"           << "                     "           << "                    "           << "                  |"  << findTeam(tSet,region       ,4,1) << endl;
    cout << findTeam(tSet,region       ,0,9) << "                     "           << "                    "           << "                   |-------------------|" << endl;
    cout << "-------------------|"           << findTeam(tSet,region       ,1,5)  << "                    "           << "                    |"<< endl;
    cout << findTeam(tSet,region       ,0,10)<< "|-------------------|"           << "                    "           << "                   |" << endl;
    cout << "-------------------|"           << "                   |"            << findTeam(tSet,region       ,2,3) << "                    |"<< endl;
    cout << findTeam(tSet,region       ,0,11)<< "                    |"           << "-------------------|"           << "                   |" << endl;
    cout << "-------------------|"           << findTeam(tSet,region       ,1,6)  << "|                   |"          << "                   |" << endl;
    cout << findTeam(tSet,region       ,0,12)<< "|-------------------|"           << "                   |"           << "                   |" << endl;
    cout << "-------------------|"           << "                     "           << "                  |"            << findTeam(tSet,region       ,3,2) << "|" << endl;
    cout << findTeam(tSet,region       ,0,13)<< "                     "           << "                   |"           << "-------------------|" << endl;
    cout << "-------------------|"           << findTeam(tSet,region       ,1,7)  << "                    |"          << endl;
    cout << findTeam(tSet,region       ,0,14)<< "|-------------------|"           << "                   |"           << endl;
    cout << "-------------------|"           << "                   |"            << findTeam(tSet,region       ,2,4) << "|" << endl;
    cout << findTeam(tSet,region       ,0,15)<< "                    |"           << "-------------------|"           << endl;
    cout << "-------------------|"           << findTeam(tSet,region       ,1,8)  << "|" << endl;
    cout << findTeam(tSet,region       ,0,16)<<"|-------------------|"            << endl;
    cout << "-------------------|" << endl;
}

void printAllRegions(Team tSet[]){
    for(int i = 1; i < 5; i++){
    cout << "################" << endl;
    cout << "### Region " << i << " ###" << endl;
    cout << "################" << endl;
    
    printRegion(tSet,i);

    cout << endl << endl;
    }
}

void printFinal(Team tSet[]){
    cout << "###############" << endl;
    cout << "# Final Four! #" << endl;
    cout << "###############" << endl << endl;
    cout << findTeam(tSet,1,4,1) << endl;
    cout << "-------------------|" << findTeam(tSet,1,5,1)    << endl;
    cout << findTeam(tSet,1,4,2)   << "|-------------------|" << endl;
    cout << "-------------------|" << "                   |"  << findTeam(tSet,1,6,1) << endl;
    cout << findTeam(tSet,1,4,3)   << "                    |" << "-------------------|"           << endl;
    cout << "-------------------|" << findTeam(tSet,1,5,2)    << "|" << endl;
    cout << findTeam(tSet,1,4,4)   << "|-------------------|" << endl << endl;
}

void runRound(Team tSet[], int round){
    //Figure out games for the given round
    // round 0 = 32 games 2^5
    // round 1 = 16 games 2^4
    // round 2 = 8 games  2^3
    // round 3 = 4 games  2^2
    // round 4 = 2 games  2^1 
    // round 5 = 1 game   2^0 
    //                        VV   7  VV
    int num_games = pow(2,( ( NUM_ROUNDS - 2 ) - round ));

    //Loop over all games (/2 of total teams)
    for(int i = 0; i < num_games; i++){
        //cout << "Playing game: round " << round << " game " << i << endl; // testing

        // Game 0 is teams 1 and 2
        // Game 1 is teams 3 and 4
        int team1 = findTeam(tSet,round,(i*2)+1); 
        int team2 = findTeam(tSet,round,((i*2)+1)+1); //One offset is to go from team1 to team2, and other other is to increase the index from 0 to 1

        // figure out winner for each game
        // update round_position for next round
        if(playGame(tSet[team1], tSet[team2]) == 0){
            //Team 1 won!
            //Next Round position == current game number
            tSet[team1].round_position[round+1] = i+1;
        } else {
            //Team 2 won!
            tSet[team2].round_position[round+1] = i+1;
        }        
    }
}

int playGame(Team t1, Team t2){
    float probability = 0.0;
    //It might be simpler to just have a swap, but then things get harder to debug
    //It could have been two functions, one to figure out which is 'higher' and the other to do the roll
    if(t1.seed_num <= t2.seed_num){
        //Team 1 is 'higher' seeded
        //Grab the appropriate probability (team1 needs to be 'first')
        probability = GAME_STATS[t1.seed_num-1][t2.seed_num-1];

        //   int 0-999    < 
        //                              int 999 = 0.999 * 1000
        if( (rand()%1000) < static_cast<int>( probability * 1000 ) ) {
            return 0; //Team 1 wins!
        } else {
            cout << "Upset! " << t2.print() << " beat " << t1.print() << endl;
            return 1;
        }
    } else {
        //Team 2 is the 'higher' seed
        //Grab the appropriate probability (team2 needs to be 'first')
        probability = GAME_STATS[t2.seed_num-1][t1.seed_num-1];

        //   int 0-999    < 
        //                              int 999 = 0.999 * 1000
        if( (rand()%1000) < static_cast<int>( probability * 1000 ) ) {
            return 1; //Team 2 wins!
        } else {
            cout << "Upset! " << t1.print() << " beat " << t2.print() << endl;
            return 0;
        }
    }
}

void initializeTeams(Team tSet[]){
    //Fill in the team list
    //This would be much easier if read in from a file (that is a CS2 thing)

    //64 position based on who plays who (1 plays 2, 3 plays 4...)
    //First 'region'  1-16
    //Second 'region' 17-32
    //Third           33-48
    //Fourth          49-64
    //                                   VV This only needs to be set in the first 'region', then we will automate the rest (0s)
    tSet[0] = Team("1 Gonzaga      ", 1, 1);
    tSet[1] = Team("1 Baylor       ", 1, 0);
    tSet[2] = Team("1 Illinois     ", 1, 0);
    tSet[3] = Team("1 Michigan     ", 1, 0);
    tSet[4] = Team("2 Alabama      ", 2, 15);
    tSet[5] = Team("2 Houston      ", 2, 0);
    tSet[6] = Team("2 Ohio St      ", 2, 0);
    tSet[7] = Team("2 Iowa         ", 2, 0);
    tSet[8] = Team("3 Kansas       ", 3, 11);
    tSet[9] = Team("3 Arkansas     ", 3, 0);
    tSet[10] = Team("3 West Virginia", 3, 0);
    tSet[11] = Team("3 Texas        ", 3, 0);
    tSet[12] = Team("4 Florida St   ", 4, 7);
    tSet[13] = Team("4 Oklahoma St  ", 4, 0);
    tSet[14] = Team("4 Purdue       ", 4, 0);
    tSet[15] = Team("4 Virginia     ", 4, 0);
    tSet[16] = Team("5 Creighton    ", 5, 5);
    tSet[17] = Team("5 Villanova    ", 5, 0);
    tSet[18] = Team("5 Tennessee    ", 5, 0);
    tSet[19] = Team("5 Colorado     ", 5, 0);
    tSet[20] = Team("6 BYU          ", 6, 9);
    tSet[21] = Team("6 San Diego St ", 6, 0);
    tSet[22] = Team("6 Texas Tech   ", 6, 0);
    tSet[23] = Team("6 USC          ", 6, 0);
    tSet[24] = Team("7 Oregon       ", 7, 13);
    tSet[25] = Team("7 Florida      ", 7, 0);
    tSet[26] = Team("7 Clemson      ", 7, 0);
    tSet[27] = Team("7 UConn        ", 7, 0);
    tSet[28] = Team("8 LSU          ", 8, 3);
    tSet[29] = Team("8 Loyola-Chi.  ", 8, 0);
    tSet[30] = Team("8 N. Carolina  ", 8, 0);
    tSet[31] = Team("8 Oklahoma     ", 8, 0);
    tSet[32] = Team("9 Missouri     ", 9, 4);
    tSet[33] = Team("9 Wisconsin    ", 9, 0);
    tSet[34] = Team("9 Georgia Tech ", 9, 0);
    tSet[35] = Team("9 St Bona.     ", 9, 0);
    tSet[36] = Team("10 Maryland    ",10, 14);
    tSet[37] = Team("10 Rutgers     ",10, 0);
    tSet[38] = Team("10 Va. Tech    ",10, 0);
    tSet[39] = Team("10 VCU         ",10, 0);
    tSet[40] = Team("11 Drake       ",11, 10);
    tSet[41] = Team("11 Utah St     ",11, 0);
    tSet[42] = Team("11 Syracuse    ",11, 0);
    tSet[43] = Team("11 UCLA        ",11, 0);
    tSet[44] = Team("12 Georgetown  ",12, 6);
    tSet[45] = Team("12 Oregon St   ",12, 0);
    tSet[46] = Team("12 Winthrop    ",12, 0);
    tSet[47] = Team("12 UCSB        ",12, 0);
    tSet[48] = Team("13 Ohio        ",13, 8);
    tSet[49] = Team("13 North Texas ",13, 0);
    tSet[50] = Team("13 Liberty     ",13, 0);
    tSet[51] = Team("13 UNCG        ",13, 0);
    tSet[52] = Team("14 Abilene Chr.",14, 12);
    tSet[53] = Team("14 Morehead St ",14, 0);
    tSet[54] = Team("14 Colgate     ",14, 0);
    tSet[55] = Team("14 Eastern Wash",14, 0);
    tSet[56] = Team("15 Grand Canyon",15, 16);
    tSet[57] = Team("15 Oral Roberts",15, 0);
    tSet[58] = Team("15 Cleveland St",15, 0);
    tSet[59] = Team("15 Iona        ",15, 0);
    tSet[60] = Team("16 Texas So.   ",16, 2);
    tSet[61] = Team("16 Drexel      ",16, 0);
    tSet[62] = Team("16 Hartford    ",16, 0);
    tSet[63] = Team("16 Norfolk St  ",16, 0);

    //Step forward every 4 teams to get the correct 'number', then move forward
    for(int i = 0; i < NUM_TEAMS; i += 4){
        int topNum = tSet[i].round_position[0]; //Base number from the 'first' region
        tSet[i+1].round_position[0] = topNum + 16; //Other regions are just offsets of 16 from the first
        tSet[i+2].round_position[0] = topNum + 32;
        tSet[i+3].round_position[0] = topNum + 48;
    }
}