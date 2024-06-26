/////////////////////////////////////////////////////////
//
// CS1: Final Project: 64-Team Bracket Simulation
//
/////////////////////////////////////////////////////////

#include <iostream> // print out to the screen (cout)
#include <ctime>
using namespace std;

class Team{
    public:
    //Attributes
        string team_name; //name of the team in the tournament
        int seed_num; //seed digit of the team

    //Behaviors
        //default constructor
        Team(){
            team_name = "No Team        ";
            seed_num = 0;
        }

        //variable constructor
        Team(string name, int digit){
        //has a team name and a seed number that is determined in the main function
            team_name = name;
            seed_num = digit; 
        }

        //Print function
        string print(){
            return team_name;
        }

};

//FUNCTIONS FOR ROUND 1 GAMES:

    //Decides winner of each 1 vs 16 matchup
    //Input : the 1 seed and the 16 seed who are matching up
    //Output: whichever team wins (generated from probability)
    Team one_vs_16(Team one, Team sixteen);

    //Decides winner of each 8 vs 9 matchup
    //Input : the 8 seed and the 9 seed who are matching up
    //Output: whichever team wins (generated from probability)
    Team eight_vs_9(Team eight, Team nine);

    //Decides winner of each 5 vs 12 matchup
    //Input : the 5 seed and the 12 seed who are matching up
    //Output: whichever team wins (generated from probability)
    Team five_vs_12(Team five, Team twelve);

    //Decides winner of each 4 vs 13 matchup
    //Input : the 4 seed and the 13 seed who are matching up
    //Output: whichever team wins (generated from probability)
    Team four_vs_13(Team four, Team thirteen);

    //Decides winner of each 6 vs 11 matchup
    //Input : the 6 seed and the 11 seed who are matching up
    //Output: whichever team wins (generated from probability)
    Team six_vs_11(Team six, Team eleven);

    //Decides winner of each 3 vs 14 matchup
    //Input : the 3 seed and the 14 seed who are matching up
    //Output: whichever team wins (generated from probability)
    Team three_vs_14(Team three, Team fourteen);

    //Decides winner of each 7 vs 10 matchup
    //Input : the 7 seed and the 10 seed who are matching up
    //Output: whichever team wins (generated from probability)
    Team seven_vs_10(Team seven, Team ten);

    //Decides winner of each 2 vs 15 matchup
    //Input : the 2 seed and the 15 seed who are matching up
    //Output: whichever team wins (generated from probability)
    Team two_vs_15(Team two, Team fifteen);


//FUNCTIONS FOR ROUND 2 GAMES:

    //Decides the winner of the game between the winners of the 1/16 and 8/9 games
    //Input: winners of the 1/16 and 8/9 game
    //Output: whichever team wins (generated from probability)
    Team quadrant1(Team winner1, Team winner2);

    //Decides the winner of the game between the winners of the 5/12 and 4/13 games
    //Input: winners of the 5/12 and 4/13 game
    //Output: whichever team wins (generated from probability)
    Team quadrant2(Team winner1, Team winner2);

    //Decides the winner of the game between the winners of the 6/11 and 3/14 games
    //Input: winners of the 6/11 and 3/14 games
    //Output: whichever team wins (generated from probability)
    Team quadrant3(Team winner1, Team winner2);

    //Decides the winner of the game between the winners of the 7/10 and 2/15 games
    //Input: winners of the 7/10 and 2/15 games
    //Output: whichever team wins (generated from probability)
    Team quadrant4(Team winner1, Team winner2);


//FUNCTIONS FOR ROUND 3 GAMES

    //Decides the winner of the game between the winners of the 1/16 vs 8/9 and 5/12 vs 4/13 games (upper half of one quadrant of the bracket)
    //Input: winners of the 1/16 vs 8/9 and 5/12 vs 4/13 games
    //Output: whichever team wins (generated from probability)
    Team upper_half(Team winner1, Team winner2);

    //Decides the winner of the game between the winners of the 6/11 vs 3/14 and 7/10 vs 2/15 games (lower half of one quadrant of the bracket)
    //Input: winners of the 6/11 vs 3/14 and 7/10 vs 2/15 games
    //Output: whichever team wins (generated from probability)
    Team lower_half(Team winner1, Team winner2);


//FUNCTION FOR ROUND 4 GAMES

    //Decides the winner of the game between the regional finalists in each region
    //Input: winners of the regional semifinals
    //Output: whichever team wins (generated from probability)
    Team whole_region(Team winner1, Team winner2);


//FUNCTION FOR ROUNDS 5 AND 6 GAMES

    //Decides the winner of the game between the regional champions from each region
    //Input: winners of the regionals
    //Output: whichever team wins (generated from probability)
    Team whole_bracket(Team winner1, Team winner2);


int main(){

    srand(time(NULL)); //seed random library with current time

    //Naming 64 teams for the bracket (teams seeded 1-16, 4 teams on each seed line)
        //initializing each team to be in the bracket
        //organized into 4 regions
        //format for variable name is the seed number_underscore_region(i.e. 4_3, 5_2, 12_1, etc.)
        //15 spaces are allotted for each slot in the bracket; whatever spaces are left after the team's name are typed out for formatting efficiency
        //A seed digit is assigned to each team along with a name
        Team t1_1("1 Gonzaga      ", 1);
        Team t1_2("1 Baylor       ", 1);
        Team t1_3("1 Illinois     ", 1);
        Team t1_4("1 Michigan     ", 1);
        Team t2_4("2 Alabama      ", 2);
        Team t2_3("2 Houston      ", 2);
        Team t2_2("2 Ohio St      ", 2);
        Team t2_1("2 Iowa         ", 2);
        Team t3_1("3 Kansas       ", 3);
        Team t3_2("3 Arkansas     ", 3);
        Team t3_3("3 West Virginia", 3);
        Team t3_4("3 Texas        ", 3);
        Team t4_4("4 Florida St   ", 4);
        Team t4_3("4 Oklahoma St  ", 4);
        Team t4_2("4 Purdue       ", 4);
        Team t4_1("4 Virginia     ", 4);
        Team t5_1("5 Creighton    ", 5);
        Team t5_2("5 Villanova    ", 5);
        Team t5_3("5 Tennessee    ", 5);
        Team t5_4("5 Colorado     ", 5);
        Team t6_4("6 BYU          ", 6);
        Team t6_3("6 San Diego St ", 6);
        Team t6_2("6 Texas Tech   ", 6);
        Team t6_1("6 USC          ", 6);
        Team t7_1("7 Oregon       ", 7);
        Team t7_2("7 Florida      ", 7);
        Team t7_3("7 Clemson      ", 7);
        Team t7_4("7 UConn        ", 7);
        Team t8_4("8 LSU          ", 8);
        Team t8_3("8 Loyola-Chi.  ", 8);
        Team t8_2("8 N. Carolina  ", 8);
        Team t8_1("8 Oklahoma     ", 8);
        Team t9_1("9 Missouri     ", 9);
        Team t9_2("9 Wisconsin    ", 9);
        Team t9_3("9 Georgia Tech ", 9);
        Team t9_4("9 St Bona.     ", 9);
        Team t10_4("10 Maryland    ",10);
        Team t10_3("10 Rutgers     ",10);
        Team t10_2("10 Va. Tech    ",10);
        Team t10_1("10 VCU         ",10);
        Team t11_1("11 Drake       ",11);
        Team t11_2("11 Utah St     ",11);
        Team t11_3("11 Syracuse    ",11);
        Team t11_4("11 UCLA        ",11);
        Team t12_4("12 Georgetown  ",12);
        Team t12_3("12 Oregon St   ",12);
        Team t12_2("12 Winthrop    ",12);
        Team t12_1("12 UCSB        ",12);
        Team t13_1("13 Ohio        ",13);
        Team t13_2("13 North Texas ",13);
        Team t13_3("13 Liberty     ",13);
        Team t13_4("13 UNCG        ",13);
        Team t14_4("14 Abilene Chr.",14);
        Team t14_3("14 Morehead St ",14);
        Team t14_2("14 Colgate     ",14);
        Team t14_1("14 Eastern Wash",14);
        Team t15_1("15 Grand Canyon",15);
        Team t15_2("15 Oral Roberts",15);
        Team t15_3("15 Cleveland St",15);
        Team t15_4("15 Iona        ",15);
        Team t16_4("16 Texas So.   ",16);
        Team t16_3("16 Drexel      ",16);
        Team t16_2("16 Hartford    ",16);
        Team t16_1("16 Norfolk St  ",16);


    //Displaying initial bracket
    cout << "Welcome to the March Madness simulator!" << endl;
    cout << "Press 1 then hit enter to see the bracket: ";
    bool n;
    cin >> n;
    cout << endl << endl << endl;
    
    //Region 1
    if(n){ //display this only once the user has entered "1"
    cout <<  t1_1.print() << endl;
    cout << "---------------|" << endl;
    cout << t16_1.print()<<"|---------------|" << endl;
    cout << "---------------|               |" << endl;
    cout << t8_1.print()<< "                |---------------|" << endl;
    cout << "---------------|               |               |" << endl;
    cout << t9_1.print()<< "|---------------|               |" << endl;
    cout << "---------------|                               |" << endl;
    cout <<  t5_1.print()<<"                                |---------------|" << endl;
    cout << "---------------|                               |               |" << endl;
    cout << t12_1.print()<<"|---------------|               |               |" << endl;
    cout << "---------------|               |               |               |" << endl;
    cout << t4_1.print()<< "                |---------------|               |" << endl;
    cout << "---------------|               |                               |" << endl;
    cout << t13_1.print()<<"|---------------|                               |" << endl;
    cout << "---------------|                                               |" << endl;
    cout << t6_1.print()<< "                                                |---------------|" << endl;
    cout << "---------------|                                               |               |" << endl;
    cout << t11_1.print()<<"|---------------|                               |               |" << endl;
    cout << "---------------|               |                               |               |" << endl;
    cout << t3_1.print()<< "                |---------------|               |               |" << endl;
    cout << "---------------|               |               |               |               |" << endl;
    cout << t14_1.print()<<"|---------------|               |               |               |" << endl;
    cout << "---------------|                               |               |               |" << endl;
    cout <<  t7_1.print()<<"                                |---------------|               |" << endl;
    cout << "---------------|                               |                               |" << endl;
    cout << t10_1.print()<<"|---------------|               |                               |" << endl;
    cout << "---------------|               |               |                               |" << endl;
    cout << t2_1.print()<< "                |---------------|                               |" << endl;
    cout << "---------------|               |                                               |" << endl;
    cout << t15_1.print()<<"|---------------|                                               |" << endl;
    cout << "---------------|                                                               |" << endl;
    //Region 4
    cout << t1_4.print()<< "                                                                |---------------|" << endl;
    cout << "---------------|                                                               |               |" << endl;
    cout << t16_4.print()<<"|---------------|                                               |               |" << endl;
    cout << "---------------|               |                                               |               |" << endl;
    cout <<  t8_4.print()<<"                |---------------|                               |               |" << endl;
    cout << "---------------|               |               |                               |               |" << endl;
    cout <<  t9_4.print()<<"|---------------|               |                               |               |" << endl;
    cout << "---------------|                               |                               |               |" << endl;
    cout <<  t5_4.print()<<"                                |---------------|               |               |" << endl;
    cout << "---------------|                               |               |               |               |" << endl;
    cout << t12_4.print()<<"|---------------|               |               |               |               |" << endl;
    cout << "---------------|               |               |               |               |               |" << endl;
    cout <<  t4_4.print()<<"                |---------------|               |               |               |" << endl;
    cout << "---------------|               |                               |               |               |" << endl;
    cout << t13_4.print()<<"|---------------|                               |               |               |" << endl;
    cout << "---------------|                                               |               |               |" << endl;
    cout <<  t6_4.print()<<"                                                |---------------|               |" << endl;
    cout << "---------------|                                               |                               |" << endl;
    cout << t11_4.print()<<"|---------------|                               |                               |" << endl;
    cout << "---------------|               |                               |                               |" << endl;
    cout <<  t3_4.print()<<"                |---------------|               |                               |" << endl;
    cout << "---------------|               |               |               |                               |" << endl;
    cout << t14_4.print()<<"|---------------|               |               |                               |" << endl;
    cout << "---------------|                               |               |                               |" << endl;
    cout <<  t7_4.print()<<"                                |---------------|                               |" << endl;
    cout << "---------------|                               |                                               |" << endl;
    cout << t10_4.print()<<"|---------------|               |                                               |" << endl;
    cout << "---------------|               |               |                                               |" << endl;
    cout <<  t2_4.print()<<"                |---------------|                                               |" << endl;
    cout << "---------------|               |                                                               |" << endl;
    cout << t15_4.print()<<"|---------------|                                                               |" << endl;
    cout << "---------------|                                                                               |" << endl;
    //Region 2
    cout <<  t1_2.print()<<"                                                                                |---------------" << endl;
    cout << "---------------|                                                                               |" << endl;
    cout << t16_2.print()<<"|---------------|                                                               |" << endl;
    cout << "---------------|               |                                                               |" << endl;
    cout <<  t8_2.print()<<"                |---------------|                                               |" << endl;
    cout << "---------------|               |               |                                               |" << endl;
    cout <<  t9_2.print()<<"|---------------|               |                                               |" << endl;
    cout << "---------------|                               |                                               |" << endl;
    cout <<  t5_2.print()<<"                                |---------------|                               |" << endl;
    cout << "---------------|                               |               |                               |" << endl;
    cout << t12_2.print()<<"|---------------|               |               |                               |" << endl;
    cout << "---------------|               |               |               |                               |" << endl;
    cout <<  t4_2.print()<<"                |---------------|               |                               |" << endl;
    cout << "---------------|               |                               |                               |" << endl;
    cout << t13_2.print()<<"|---------------|                               |                               |" << endl;
    cout << "---------------|                                               |                               |" << endl;
    cout <<  t6_2.print()<<"                                                |---------------|               |" << endl;
    cout << "---------------|                                               |               |               |" << endl;
    cout << t11_2.print()<<"|---------------|                               |               |               |" << endl;
    cout << "---------------|               |                               |               |               |" << endl;
    cout <<  t3_2.print()<<"                |---------------|               |               |               |" << endl;
    cout << "---------------|               |               |               |               |               |" << endl;
    cout << t14_2.print()<<"|---------------|               |               |               |               |" << endl;
    cout << "---------------|                               |               |               |               |" << endl;
    cout <<  t7_2.print()<<"                                |---------------|               |               |" << endl;
    cout << "---------------|                               |                               |               |" << endl;
    cout << t10_2.print()<<"|---------------|               |                               |               |" << endl;
    cout << "---------------|               |               |                               |               |" << endl;
    cout <<  t2_2.print()<<"                |---------------|                               |               |" << endl;
    cout << "---------------|               |                                               |               |" << endl;
    cout << t15_2.print()<<"|---------------|                                               |               |" << endl;
    cout << "---------------|                                                               |               |" << endl;
    //Region 3
    cout <<  t1_3.print()<<"                                                                |---------------|" << endl;
    cout << "---------------|                                                               |" << endl;
    cout << t16_3.print()<<"|---------------|                                               |" << endl;
    cout << "---------------|               |                                               |" << endl;
    cout <<  t8_3.print()<<"                |---------------|                               |" << endl;
    cout << "---------------|               |               |                               |" << endl;
    cout <<  t9_3.print()<<"|---------------|               |                               |" << endl;
    cout << "---------------|                               |                               |" << endl;
    cout <<  t5_3.print()<<"                                |---------------|               |" << endl;
    cout << "---------------|                               |               |               |" << endl;
    cout << t12_3.print()<<"|---------------|               |               |               |" << endl;
    cout << "---------------|               |               |               |               |" << endl;
    cout <<  t4_3.print()<<"                |---------------|               |               |" << endl;
    cout << "---------------|               |                               |               |" << endl;
    cout << t13_3.print()<<"|---------------|                               |               |" << endl;
    cout << "---------------|                                               |               |" << endl;
    cout <<  t6_3.print()<<"                                                |---------------|" << endl;
    cout << "---------------|                                               |" << endl;
    cout << t11_3.print()<<"|---------------|                               |" << endl;
    cout << "---------------|               |                               |" << endl;
    cout <<  t3_3.print()<<"                |---------------|               |" << endl;
    cout << "---------------|               |               |               |" << endl;
    cout << t14_3.print()<<"|---------------|               |               |" << endl;
    cout << "---------------|                               |               |" << endl;
    cout <<  t7_3.print()<<"                                |---------------|" << endl;
    cout << "---------------|                               |" << endl;
    cout << t10_3.print()<<"|---------------|               |" << endl;
    cout << "---------------|               |               |" << endl;
    cout <<  t2_3.print()<<"                |---------------|" << endl;
    cout << "---------------|               |" << endl;
    cout << t15_3.print()<<"|---------------|" << endl;
    cout << "---------------|" << endl;
    }


    //Set up 2nd round
        //assigning the winners to their own new variables (wG1 = "winner game 1", etc.)
            //Region 1
            Team wG1 = one_vs_16(t1_1,t16_1);
            Team wG2 = eight_vs_9(t8_1,t9_1);
            Team wG3 = five_vs_12(t5_1,t12_1);
            Team wG4 = four_vs_13(t4_1,t13_1);
            Team wG5 = six_vs_11(t6_1,t11_1);
            Team wG6 = three_vs_14(t3_1,t14_1);
            Team wG7 = seven_vs_10(t7_1,t10_1);
            Team wG8 = two_vs_15(t2_1,t15_1);    
            //Region 4
            Team wG9  = one_vs_16(t1_4,t16_4);
            Team wG10 = eight_vs_9(t8_4,t9_4);
            Team wG11 = five_vs_12(t5_4,t12_4);
            Team wG12 = four_vs_13(t4_4,t13_4);
            Team wG13 = six_vs_11(t6_4,t11_4);
            Team wG14 = three_vs_14(t3_4,t14_4);
            Team wG15 = seven_vs_10(t7_4,t10_4);
            Team wG16 = two_vs_15(t2_4,t15_4);
            //Region 2
            Team wG17 = one_vs_16(t1_2,t16_2);
            Team wG18 = eight_vs_9(t8_2,t9_2);
            Team wG19 = five_vs_12(t5_2,t12_2);
            Team wG20 = four_vs_13(t4_2,t13_2);
            Team wG21 = six_vs_11(t6_2,t11_2);
            Team wG22 = three_vs_14(t3_2,t14_2);
            Team wG23 = seven_vs_10(t7_2,t10_2);
            Team wG24 = two_vs_15(t2_2,t15_2);
            //Region 3
            Team wG25 = one_vs_16(t1_3,t16_3);
            Team wG26 = eight_vs_9(t8_3,t9_3);
            Team wG27 = five_vs_12(t5_3,t12_3);
            Team wG28 = four_vs_13(t4_3,t13_3);
            Team wG29 = six_vs_11(t6_3,t11_3);
            Team wG30 = three_vs_14(t3_3,t14_3);
            Team wG31 = seven_vs_10(t7_3,t10_3);
            Team wG32 = two_vs_15(t2_3,t15_3);

    //Printing winners of round 1 onto the bracket
    cout << endl << endl << endl;
    cout << "Press 1 then hit enter to simulate the first round of the bracket: ";
    bool k;
    cin >> k;
    cout << endl << endl << endl;

    if(k){//display this only once the user has entered "1"
    cout <<  t1_1.print() << endl;
    cout << "---------------|" << wG1.print()  << endl;
    cout << t16_1.print()<<"|---------------|" << endl;
    cout << "---------------|               |" << endl;
    cout << t8_1.print()<< "                |---------------|" << endl;
    cout << "---------------|" << wG2.print() << "|               |" << endl;
    cout << t9_1.print()<< "|---------------|               |" << endl;
    cout << "---------------|                               |" << endl;
    cout <<  t5_1.print()<<"                                |---------------|" << endl;
    cout << "---------------|" << wG3.print() << "                |               |" << endl;
    cout << t12_1.print()<<"|---------------|               |               |" << endl;
    cout << "---------------|               |               |               |" << endl;
    cout << t4_1.print()<< "                |---------------|               |" << endl;
    cout << "---------------|" << wG4.print() << "|                               |" << endl;
    cout << t13_1.print()<<"|---------------|                               |" << endl;
    cout << "---------------|                                               |" << endl;
    cout << t6_1.print()<< "                                                |---------------|" << endl;
    cout << "---------------|" << wG5.print() << "                                |               |" << endl;
    cout << t11_1.print()<<"|---------------|                               |               |" << endl;
    cout << "---------------|               |                               |               |" << endl;
    cout << t3_1.print()<< "                |---------------|               |               |" << endl;
    cout << "---------------|" << wG6.print() << "|               |               |               |" << endl;
    cout << t14_1.print()<<"|---------------|               |               |               |" << endl;
    cout << "---------------|                               |               |               |" << endl;
    cout <<  t7_1.print()<<"                                |---------------|               |" << endl;
    cout << "---------------|" << wG7.print() << "                |                               |" << endl;
    cout << t10_1.print()<<"|---------------|               |                               |" << endl;
    cout << "---------------|               |               |                               |" << endl;
    cout << t2_1.print()<< "                |---------------|                               |" << endl;
    cout << "---------------|" << wG8.print() << "|                                               |" << endl;
    cout << t15_1.print()<<"|---------------|                                               |" << endl;
    cout << "---------------|                                                               |" << endl;
    //Region 4
    cout << t1_4.print()<< "                                                                |---------------|" << endl;
    cout << "---------------|" << wG9.print() << "                                                |               |" << endl;
    cout << t16_4.print()<<"|---------------|                                               |               |" << endl;
    cout << "---------------|               |                                               |               |" << endl;
    cout <<  t8_4.print()<<"                |---------------|                               |               |" << endl;
    cout << "---------------|" << wG10.print() << "|               |                               |               |" << endl;
    cout <<  t9_4.print()<<"|---------------|               |                               |               |" << endl;
    cout << "---------------|                               |                               |               |" << endl;
    cout <<  t5_4.print()<<"                                |---------------|               |               |" << endl;
    cout << "---------------|" << wG11.print() << "                |               |               |               |" << endl;
    cout << t12_4.print()<<"|---------------|               |               |               |               |" << endl;
    cout << "---------------|               |               |               |               |               |" << endl;
    cout <<  t4_4.print()<<"                |---------------|               |               |               |" << endl;
    cout << "---------------|" << wG12.print() << "|                               |               |               |" << endl;
    cout << t13_4.print()<<"|---------------|                               |               |               |" << endl;
    cout << "---------------|                                               |               |               |" << endl;
    cout <<  t6_4.print()<<"                                                |---------------|               |" << endl;
    cout << "---------------|" << wG13.print() << "                                |                               |" << endl;
    cout << t11_4.print()<<"|---------------|                               |                               |" << endl;
    cout << "---------------|               |                               |                               |" << endl;
    cout <<  t3_4.print()<<"                |---------------|               |                               |" << endl;
    cout << "---------------|" << wG14.print() << "|               |               |                               |" << endl;
    cout << t14_4.print()<<"|---------------|               |               |                               |" << endl;
    cout << "---------------|                               |               |                               |" << endl;
    cout <<  t7_4.print()<<"                                |---------------|                               |" << endl;
    cout << "---------------|" << wG15.print() << "                |                                               |" << endl;
    cout << t10_4.print()<<"|---------------|               |                                               |" << endl;
    cout << "---------------|               |               |                                               |" << endl;
    cout <<  t2_4.print()<<"                |---------------|                                               |" << endl;
    cout << "---------------|" << wG16.print() << "|                                                               |" << endl;
    cout << t15_4.print()<<"|---------------|                                                               |" << endl;
    cout << "---------------|                                                                               |" << endl;
    //Region 2
    cout <<  t1_2.print()<<"                                                                                |---------------" << endl;
    cout << "---------------|" << wG17.print() << "                                                                |" << endl;
    cout << t16_2.print()<<"|---------------|                                                               |" << endl;
    cout << "---------------|               |                                                               |" << endl;
    cout <<  t8_2.print()<<"                |---------------|                                               |" << endl;
    cout << "---------------|" << wG18.print() << "|               |                                               |" << endl;
    cout <<  t9_2.print()<<"|---------------|               |                                               |" << endl;
    cout << "---------------|                               |                                               |" << endl;
    cout <<  t5_2.print()<<"                                |---------------|                               |" << endl;
    cout << "---------------|" << wG19.print() << "                |               |                               |" << endl;
    cout << t12_2.print()<<"|---------------|               |               |                               |" << endl;
    cout << "---------------|               |               |               |                               |" << endl;
    cout <<  t4_2.print()<<"                |---------------|               |                               |" << endl;
    cout << "---------------|" << wG20.print() << "|                               |                               |" << endl;
    cout << t13_2.print()<<"|---------------|                               |                               |" << endl;
    cout << "---------------|                                               |                               |" << endl;
    cout <<  t6_2.print()<<"                                                |---------------|               |" << endl;
    cout << "---------------|" << wG21.print() << "                                |               |               |" << endl;
    cout << t11_2.print()<<"|---------------|                               |               |               |" << endl;
    cout << "---------------|               |                               |               |               |" << endl;
    cout <<  t3_2.print()<<"                |---------------|               |               |               |" << endl;
    cout << "---------------|" << wG22.print() << "|               |               |               |               |" << endl;
    cout << t14_2.print()<<"|---------------|               |               |               |               |" << endl;
    cout << "---------------|                               |               |               |               |" << endl;
    cout <<  t7_2.print()<<"                                |---------------|               |               |" << endl;
    cout << "---------------|" << wG23.print() << "                |                               |               |" << endl;
    cout << t10_2.print()<<"|---------------|               |                               |               |" << endl;
    cout << "---------------|               |               |                               |               |" << endl;
    cout <<  t2_2.print()<<"                |---------------|                               |               |" << endl;
    cout << "---------------|" << wG24.print() << "|                                               |               |" << endl;
    cout << t15_2.print()<<"|---------------|                                               |               |" << endl;
    cout << "---------------|                                                               |               |" << endl;
    //Region 3
    cout <<  t1_3.print()<<"                                                                |---------------|" << endl;
    cout << "---------------|" << wG25.print() << "                                                |" << endl;
    cout << t16_3.print()<<"|---------------|                                               |" << endl;
    cout << "---------------|               |                                               |" << endl;
    cout <<  t8_3.print()<<"                |---------------|                               |" << endl;
    cout << "---------------|" << wG26.print() << "|               |                               |" << endl;
    cout <<  t9_3.print()<<"|---------------|               |                               |" << endl;
    cout << "---------------|                               |                               |" << endl;
    cout <<  t5_3.print()<<"                                |---------------|               |" << endl;
    cout << "---------------|" << wG27.print() << "                |               |               |" << endl;
    cout << t12_3.print()<<"|---------------|               |               |               |" << endl;
    cout << "---------------|               |               |               |               |" << endl;
    cout <<  t4_3.print()<<"                |---------------|               |               |" << endl;
    cout << "---------------|" << wG28.print() << "|                               |               |" << endl;
    cout << t13_3.print()<<"|---------------|                               |               |" << endl;
    cout << "---------------|                                               |               |" << endl;
    cout <<  t6_3.print()<<"                                                |---------------|" << endl;
    cout << "---------------|" << wG29.print() << "                                |" << endl;
    cout << t11_3.print()<<"|---------------|                               |" << endl;
    cout << "---------------|               |                               |" << endl;
    cout <<  t3_3.print()<<"                |---------------|               |" << endl;
    cout << "---------------|" << wG30.print() << "|               |               |" << endl;
    cout << t14_3.print()<<"|---------------|               |               |" << endl;
    cout << "---------------|                               |               |" << endl;
    cout <<  t7_3.print()<<"                                |---------------|" << endl;
    cout << "---------------|" << wG31.print() << "                |" << endl;
    cout << t10_3.print()<<"|---------------|               |" << endl;
    cout << "---------------|               |               |" << endl;
    cout <<  t2_3.print()<<"                |---------------|" << endl;
    cout << "---------------|" << wG32.print() << "|" << endl;
    cout << t15_3.print()<<"|---------------|" << endl;
    cout << "---------------|" << endl;
    }


    //Set up 3rd round
        //assigning the winners to their own new variables (wG1 = "winner game 1", etc.)
            //Region 1
            Team wG33 = quadrant1(wG1,wG2);
            Team wG34 = quadrant2(wG3,wG4);
            Team wG35 = quadrant3(wG5,wG6);
            Team wG36 = quadrant4(wG7,wG8);
            //Region 4
            Team wG37 = quadrant1(wG9,wG10);
            Team wG38 = quadrant2(wG11,wG12);
            Team wG39 = quadrant3(wG13,wG14);
            Team wG40 = quadrant4(wG15,wG16);
            //Region 2
            Team wG41 = quadrant1(wG17,wG18);
            Team wG42 = quadrant2(wG19,wG20);
            Team wG43 = quadrant3(wG21,wG22);
            Team wG44 = quadrant4(wG23,wG24);
            //Region 3
            Team wG45 = quadrant1(wG25,wG26);
            Team wG46 = quadrant2(wG27,wG28);
            Team wG47 = quadrant3(wG29,wG30);
            Team wG48 = quadrant4(wG31,wG32);
    
    //Printing winners of round 2 onto the bracket
    cout << endl << endl << endl;
    cout << "Press 1 then hit enter to simulate the next round of the bracket: ";
    bool p;
    cin >> p;
    cout << endl << endl << endl;

    if(p){//display this only once the user has entered "1"
    cout <<  t1_1.print() << endl;
    cout << "---------------|" << wG1.print()  << endl;
    cout << t16_1.print()<<"|---------------|" << endl;
    cout << "---------------|               |" << wG33.print() << endl;
    cout << t8_1.print()<< "                |---------------|" << endl;
    cout << "---------------|" << wG2.print() << "|               |" << endl;
    cout << t9_1.print()<< "|---------------|               |" << endl;
    cout << "---------------|                               |" << endl;
    cout <<  t5_1.print()<<"                                |---------------|" << endl;
    cout << "---------------|" << wG3.print() << "                |               |" << endl;
    cout << t12_1.print()<<"|---------------|               |               |" << endl;
    cout << "---------------|               |" << wG34.print() << "|               |" << endl;
    cout << t4_1.print()<< "                |---------------|               |" << endl;
    cout << "---------------|" << wG4.print() << "|                               |" << endl;
    cout << t13_1.print()<<"|---------------|                               |" << endl;
    cout << "---------------|                                               |" << endl;
    cout << t6_1.print()<< "                                                |---------------|" << endl;
    cout << "---------------|" << wG5.print() << "                                |               |" << endl;
    cout << t11_1.print()<<"|---------------|                               |               |" << endl;
    cout << "---------------|               |" << wG35.print() << "                |               |" << endl;
    cout << t3_1.print()<< "                |---------------|               |               |" << endl;
    cout << "---------------|" << wG6.print() << "|               |               |               |" << endl;
    cout << t14_1.print()<<"|---------------|               |               |               |" << endl;
    cout << "---------------|                               |               |               |" << endl;
    cout <<  t7_1.print()<<"                                |---------------|               |" << endl;
    cout << "---------------|" << wG7.print() << "                |                               |" << endl;
    cout << t10_1.print()<<"|---------------|               |                               |" << endl;
    cout << "---------------|               |" << wG36.print() << "|                               |" << endl;
    cout << t2_1.print()<< "                |---------------|                               |" << endl;
    cout << "---------------|" << wG8.print() << "|                                               |" << endl;
    cout << t15_1.print()<<"|---------------|                                               |" << endl;
    cout << "---------------|                                                               |" << endl;
    //Region 4
    cout << t1_4.print()<< "                                                                |---------------|" << endl;
    cout << "---------------|" << wG9.print() << "                                                |               |" << endl;
    cout << t16_4.print()<<"|---------------|                                               |               |" << endl;
    cout << "---------------|               |" << wG37.print() << "                                |               |" << endl;
    cout <<  t8_4.print()<<"                |---------------|                               |               |" << endl;
    cout << "---------------|" << wG10.print() << "|               |                               |               |" << endl;
    cout <<  t9_4.print()<<"|---------------|               |                               |               |" << endl;
    cout << "---------------|                               |                               |               |" << endl;
    cout <<  t5_4.print()<<"                                |---------------|               |               |" << endl;
    cout << "---------------|" << wG11.print() << "                |               |               |               |" << endl;
    cout << t12_4.print()<<"|---------------|               |               |               |               |" << endl;
    cout << "---------------|               |" << wG38.print() << "|               |               |               |" << endl;
    cout <<  t4_4.print()<<"                |---------------|               |               |               |" << endl;
    cout << "---------------|" << wG12.print() << "|                               |               |               |" << endl;
    cout << t13_4.print()<<"|---------------|                               |               |               |" << endl;
    cout << "---------------|                                               |               |               |" << endl;
    cout <<  t6_4.print()<<"                                                |---------------|               |" << endl;
    cout << "---------------|" << wG13.print() << "                                |                               |" << endl;
    cout << t11_4.print()<<"|---------------|                               |                               |" << endl;
    cout << "---------------|               |" << wG39.print() << "                |                               |" << endl;
    cout <<  t3_4.print()<<"                |---------------|               |                               |" << endl;
    cout << "---------------|" << wG14.print() << "|               |               |                               |" << endl;
    cout << t14_4.print()<<"|---------------|               |               |                               |" << endl;
    cout << "---------------|                               |               |                               |" << endl;
    cout <<  t7_4.print()<<"                                |---------------|                               |" << endl;
    cout << "---------------|" << wG15.print() << "                |                                               |" << endl;
    cout << t10_4.print()<<"|---------------|               |                                               |" << endl;
    cout << "---------------|               |" << wG40.print() << "|                                               |" << endl;
    cout <<  t2_4.print()<<"                |---------------|                                               |" << endl;
    cout << "---------------|" << wG16.print() << "|                                                               |" << endl;
    cout << t15_4.print()<<"|---------------|                                                               |" << endl;
    cout << "---------------|                                                                               |" << endl;
    //Region 2
    cout <<  t1_2.print()<<"                                                                                |---------------" << endl;
    cout << "---------------|" << wG17.print() << "                                                                |" << endl;
    cout << t16_2.print()<<"|---------------|                                                               |" << endl;
    cout << "---------------|               |" << wG41.print() << "                                                |" << endl;
    cout <<  t8_2.print()<<"                |---------------|                                               |" << endl;
    cout << "---------------|" << wG18.print() << "|               |                                               |" << endl;
    cout <<  t9_2.print()<<"|---------------|               |                                               |" << endl;
    cout << "---------------|                               |                                               |" << endl;
    cout <<  t5_2.print()<<"                                |---------------|                               |" << endl;
    cout << "---------------|" << wG19.print() << "                |               |                               |" << endl;
    cout << t12_2.print()<<"|---------------|               |               |                               |" << endl;
    cout << "---------------|               |" << wG42.print() << "|               |                               |" << endl;
    cout <<  t4_2.print()<<"                |---------------|               |                               |" << endl;
    cout << "---------------|" << wG20.print() << "|                               |                               |" << endl;
    cout << t13_2.print()<<"|---------------|                               |                               |" << endl;
    cout << "---------------|                                               |                               |" << endl;
    cout <<  t6_2.print()<<"                                                |---------------|               |" << endl;
    cout << "---------------|" << wG21.print() << "                                |               |               |" << endl;
    cout << t11_2.print()<<"|---------------|                               |               |               |" << endl;
    cout << "---------------|               |" << wG43.print() << "                |               |               |" << endl;
    cout <<  t3_2.print()<<"                |---------------|               |               |               |" << endl;
    cout << "---------------|" << wG22.print() << "|               |               |               |               |" << endl;
    cout << t14_2.print()<<"|---------------|               |               |               |               |" << endl;
    cout << "---------------|                               |               |               |               |" << endl;
    cout <<  t7_2.print()<<"                                |---------------|               |               |" << endl;
    cout << "---------------|" << wG23.print() << "                |                               |               |" << endl;
    cout << t10_2.print()<<"|---------------|               |                               |               |" << endl;
    cout << "---------------|               |" << wG44.print() << "|                               |               |" << endl;
    cout <<  t2_2.print()<<"                |---------------|                               |               |" << endl;
    cout << "---------------|" << wG24.print() << "|                                               |               |" << endl;
    cout << t15_2.print()<<"|---------------|                                               |               |" << endl;
    cout << "---------------|                                                               |               |" << endl;
    //Region 3
    cout <<  t1_3.print()<<"                                                                |---------------|" << endl;
    cout << "---------------|" << wG25.print() << "                                                |" << endl;
    cout << t16_3.print()<<"|---------------|                                               |" << endl;
    cout << "---------------|               |" << wG45.print() << "                                |" << endl;
    cout <<  t8_3.print()<<"                |---------------|                               |" << endl;
    cout << "---------------|" << wG26.print() << "|               |                               |" << endl;
    cout <<  t9_3.print()<<"|---------------|               |                               |" << endl;
    cout << "---------------|                               |                               |" << endl;
    cout <<  t5_3.print()<<"                                |---------------|               |" << endl;
    cout << "---------------|" << wG27.print() << "                |               |               |" << endl;
    cout << t12_3.print()<<"|---------------|               |               |               |" << endl;
    cout << "---------------|               |" << wG46.print() << "|               |               |" << endl;
    cout <<  t4_3.print()<<"                |---------------|               |               |" << endl;
    cout << "---------------|" << wG28.print() << "|                               |               |" << endl;
    cout << t13_3.print()<<"|---------------|                               |               |" << endl;
    cout << "---------------|                                               |               |" << endl;
    cout <<  t6_3.print()<<"                                                |---------------|" << endl;
    cout << "---------------|" << wG29.print() << "                                |" << endl;
    cout << t11_3.print()<<"|---------------|                               |" << endl;
    cout << "---------------|               |" << wG47.print() << "                |" << endl;
    cout <<  t3_3.print()<<"                |---------------|               |" << endl;
    cout << "---------------|" << wG30.print() << "|               |               |" << endl;
    cout << t14_3.print()<<"|---------------|               |               |" << endl;
    cout << "---------------|                               |               |" << endl;
    cout <<  t7_3.print()<<"                                |---------------|" << endl;
    cout << "---------------|" << wG31.print() << "                |" << endl;
    cout << t10_3.print()<<"|---------------|               |" << endl;
    cout << "---------------|               |" << wG48.print() << "|" << endl;
    cout <<  t2_3.print()<<"                |---------------|" << endl;
    cout << "---------------|" << wG32.print() << "|" << endl;
    cout << t15_3.print()<<"|---------------|" << endl;
    cout << "---------------|" << endl;
    }


    //Setting up 4th round
        //assigning the winners to their own new variables (wG1 = "winner game 1", etc.)
            //Region 1
            Team wG49 = upper_half(wG33,wG34);
            Team wG50 = lower_half(wG35,wG36);
            //Region 4
            Team wG51 = upper_half(wG37,wG38);
            Team wG52 = lower_half(wG39,wG40);
            //Region 2
            Team wG53 = upper_half(wG41,wG42);
            Team wG54 = lower_half(wG43,wG44);
            //Region 3
            Team wG55 = upper_half(wG45,wG46);
            Team wG56 = lower_half(wG47,wG48);

    //Printing winners of round 3 onto the bracket
    cout << endl << endl << endl;
    cout << "Press 1 then hit enter to simulate the next round of the bracket: ";
    bool y;
    cin >> y;
    cout << endl << endl << endl;

    if(y){//display this only once the user has entered "1"
    cout <<  t1_1.print() << endl;
    cout << "---------------|" << wG1.print()  << endl;
    cout << t16_1.print()<<"|---------------|" << endl;
    cout << "---------------|               |" << wG33.print() << endl;
    cout << t8_1.print()<< "                |---------------|" << endl;
    cout << "---------------|" << wG2.print() << "|               |" << endl;
    cout << t9_1.print()<< "|---------------|               |" << endl;
    cout << "---------------|                               |" << wG49.print() << endl;
    cout <<  t5_1.print()<<"                                |---------------|" << endl;
    cout << "---------------|" << wG3.print() << "                |               |" << endl;
    cout << t12_1.print()<<"|---------------|               |               |" << endl;
    cout << "---------------|               |" << wG34.print() << "|               |" << endl;
    cout << t4_1.print()<< "                |---------------|               |" << endl;
    cout << "---------------|" << wG4.print() << "|                               |" << endl;
    cout << t13_1.print()<<"|---------------|                               |" << endl;
    cout << "---------------|                                               |" << endl;
    cout << t6_1.print()<< "                                                |---------------|" << endl;
    cout << "---------------|" << wG5.print() << "                                |               |" << endl;
    cout << t11_1.print()<<"|---------------|                               |               |" << endl;
    cout << "---------------|               |" << wG35.print() << "                |               |" << endl;
    cout << t3_1.print()<< "                |---------------|               |               |" << endl;
    cout << "---------------|" << wG6.print() << "|               |               |               |" << endl;
    cout << t14_1.print()<<"|---------------|               |               |               |" << endl;
    cout << "---------------|                               |" << wG50.print() << "|               |" << endl;
    cout <<  t7_1.print()<<"                                |---------------|               |" << endl;
    cout << "---------------|" << wG7.print() << "                |                               |" << endl;
    cout << t10_1.print()<<"|---------------|               |                               |" << endl;
    cout << "---------------|               |" << wG36.print() << "|                               |" << endl;
    cout << t2_1.print()<< "                |---------------|                               |" << endl;
    cout << "---------------|" << wG8.print() << "|                                               |" << endl;
    cout << t15_1.print()<<"|---------------|                                               |" << endl;
    cout << "---------------|                                                               |" << endl;
    //Region 4
    cout << t1_4.print()<< "                                                                |---------------|" << endl;
    cout << "---------------|" << wG9.print() << "                                                |               |" << endl;
    cout << t16_4.print()<<"|---------------|                                               |               |" << endl;
    cout << "---------------|               |" << wG37.print() << "                                |               |" << endl;
    cout <<  t8_4.print()<<"                |---------------|                               |               |" << endl;
    cout << "---------------|" << wG10.print() << "|               |                               |               |" << endl;
    cout <<  t9_4.print()<<"|---------------|               |                               |               |" << endl;
    cout << "---------------|                               |" << wG51.print() << "                |               |" << endl;
    cout <<  t5_4.print()<<"                                |---------------|               |               |" << endl;
    cout << "---------------|" << wG11.print() << "                |               |               |               |" << endl;
    cout << t12_4.print()<<"|---------------|               |               |               |               |" << endl;
    cout << "---------------|               |" << wG38.print() << "|               |               |               |" << endl;
    cout <<  t4_4.print()<<"                |---------------|               |               |               |" << endl;
    cout << "---------------|" << wG12.print() << "|                               |               |               |" << endl;
    cout << t13_4.print()<<"|---------------|                               |               |               |" << endl;
    cout << "---------------|                                               |               |               |" << endl;
    cout <<  t6_4.print()<<"                                                |---------------|               |" << endl;
    cout << "---------------|" << wG13.print() << "                                |                               |" << endl;
    cout << t11_4.print()<<"|---------------|                               |                               |" << endl;
    cout << "---------------|               |" << wG39.print() << "                |                               |" << endl;
    cout <<  t3_4.print()<<"                |---------------|               |                               |" << endl;
    cout << "---------------|" << wG14.print() << "|               |               |                               |" << endl;
    cout << t14_4.print()<<"|---------------|               |               |                               |" << endl;
    cout << "---------------|                               |" << wG52.print() << "|                               |" << endl;
    cout <<  t7_4.print()<<"                                |---------------|                               |" << endl;
    cout << "---------------|" << wG15.print() << "                |                                               |" << endl;
    cout << t10_4.print()<<"|---------------|               |                                               |" << endl;
    cout << "---------------|               |" << wG40.print() << "|                                               |" << endl;
    cout <<  t2_4.print()<<"                |---------------|                                               |" << endl;
    cout << "---------------|" << wG16.print() << "|                                                               |" << endl;
    cout << t15_4.print()<<"|---------------|                                                               |" << endl;
    cout << "---------------|                                                                               |" << endl;
    //Region 2
    cout <<  t1_2.print()<<"                                                                                |---------------" << endl;
    cout << "---------------|" << wG17.print() << "                                                                |" << endl;
    cout << t16_2.print()<<"|---------------|                                                               |" << endl;
    cout << "---------------|               |" << wG41.print() << "                                                |" << endl;
    cout <<  t8_2.print()<<"                |---------------|                                               |" << endl;
    cout << "---------------|" << wG18.print() << "|               |                                               |" << endl;
    cout <<  t9_2.print()<<"|---------------|               |                                               |" << endl;
    cout << "---------------|                               |" << wG53.print() << "                                |" << endl;
    cout <<  t5_2.print()<<"                                |---------------|                               |" << endl;
    cout << "---------------|" << wG19.print() << "                |               |                               |" << endl;
    cout << t12_2.print()<<"|---------------|               |               |                               |" << endl;
    cout << "---------------|               |" << wG42.print() << "|               |                               |" << endl;
    cout <<  t4_2.print()<<"                |---------------|               |                               |" << endl;
    cout << "---------------|" << wG20.print() << "|                               |                               |" << endl;
    cout << t13_2.print()<<"|---------------|                               |                               |" << endl;
    cout << "---------------|                                               |                               |" << endl;
    cout <<  t6_2.print()<<"                                                |---------------|               |" << endl;
    cout << "---------------|" << wG21.print() << "                                |               |               |" << endl;
    cout << t11_2.print()<<"|---------------|                               |               |               |" << endl;
    cout << "---------------|               |" << wG43.print() << "                |               |               |" << endl;
    cout <<  t3_2.print()<<"                |---------------|               |               |               |" << endl;
    cout << "---------------|" << wG22.print() << "|               |               |               |               |" << endl;
    cout << t14_2.print()<<"|---------------|               |               |               |               |" << endl;
    cout << "---------------|                               |" << wG54.print() << "|               |               |" << endl;
    cout <<  t7_2.print()<<"                                |---------------|               |               |" << endl;
    cout << "---------------|" << wG23.print() << "                |                               |               |" << endl;
    cout << t10_2.print()<<"|---------------|               |                               |               |" << endl;
    cout << "---------------|               |" << wG44.print() << "|                               |               |" << endl;
    cout <<  t2_2.print()<<"                |---------------|                               |               |" << endl;
    cout << "---------------|" << wG24.print() << "|                                               |               |" << endl;
    cout << t15_2.print()<<"|---------------|                                               |               |" << endl;
    cout << "---------------|                                                               |               |" << endl;
    //Region 3
    cout <<  t1_3.print()<<"                                                                |---------------|" << endl;
    cout << "---------------|" << wG25.print() << "                                                |" << endl;
    cout << t16_3.print()<<"|---------------|                                               |" << endl;
    cout << "---------------|               |" << wG45.print() << "                                |" << endl;
    cout <<  t8_3.print()<<"                |---------------|                               |" << endl;
    cout << "---------------|" << wG26.print() << "|               |                               |" << endl;
    cout <<  t9_3.print()<<"|---------------|               |                               |" << endl;
    cout << "---------------|                               |" << wG55.print() << "                |" << endl;
    cout <<  t5_3.print()<<"                                |---------------|               |" << endl;
    cout << "---------------|" << wG27.print() << "                |               |               |" << endl;
    cout << t12_3.print()<<"|---------------|               |               |               |" << endl;
    cout << "---------------|               |" << wG46.print() << "|               |               |" << endl;
    cout <<  t4_3.print()<<"                |---------------|               |               |" << endl;
    cout << "---------------|" << wG28.print() << "|                               |               |" << endl;
    cout << t13_3.print()<<"|---------------|                               |               |" << endl;
    cout << "---------------|                                               |               |" << endl;
    cout <<  t6_3.print()<<"                                                |---------------|" << endl;
    cout << "---------------|" << wG29.print() << "                                |" << endl;
    cout << t11_3.print()<<"|---------------|                               |" << endl;
    cout << "---------------|               |" << wG47.print() << "                |" << endl;
    cout <<  t3_3.print()<<"                |---------------|               |" << endl;
    cout << "---------------|" << wG30.print() << "|               |               |" << endl;
    cout << t14_3.print()<<"|---------------|               |               |" << endl;
    cout << "---------------|                               |" << wG56.print() << "|" << endl;
    cout <<  t7_3.print()<<"                                |---------------|" << endl;
    cout << "---------------|" << wG31.print() << "                |" << endl;
    cout << t10_3.print()<<"|---------------|               |" << endl;
    cout << "---------------|               |" << wG48.print() << "|" << endl;
    cout <<  t2_3.print()<<"                |---------------|" << endl;
    cout << "---------------|" << wG32.print() << "|" << endl;
    cout << t15_3.print()<<"|---------------|" << endl;
    cout << "---------------|" << endl;
    }

   //Setting up 5th round
        //assigning the winners to their own new variables (wG1 = "winner game 1", etc.)
            //Region 1
            Team wG57 = whole_region(wG49,wG50);
            //Region 4
            Team wG58 = whole_region(wG51,wG52);
            //Region 2
            Team wG59 = whole_region(wG53,wG54);
            //Region 3
            Team wG60 = whole_region(wG55,wG56);

    //Printing winners of round 4 onto the bracket
    cout << endl << endl << endl;
    cout << "Press 1 then hit enter to simulate the next round of the bracket: ";
    bool w;
    cin >> w;
    cout << endl << endl << endl;

    if(w){//display this only once the user has entered "1"
    cout <<  t1_1.print() << endl;
    cout << "---------------|" << wG1.print()  << endl;
    cout << t16_1.print()<<"|---------------|" << endl;
    cout << "---------------|               |" << wG33.print() << endl;
    cout << t8_1.print()<< "                |---------------|" << endl;
    cout << "---------------|" << wG2.print() << "|               |" << endl;
    cout << t9_1.print()<< "|---------------|               |" << endl;
    cout << "---------------|                               |" << wG49.print() << endl;
    cout <<  t5_1.print()<<"                                |---------------|" << endl;
    cout << "---------------|" << wG3.print() << "                |               |" << endl;
    cout << t12_1.print()<<"|---------------|               |               |" << endl;
    cout << "---------------|               |" << wG34.print() << "|               |" << endl;
    cout << t4_1.print()<< "                |---------------|               |" << endl;
    cout << "---------------|" << wG4.print() << "|                               |" << endl;
    cout << t13_1.print()<<"|---------------|                               |" << endl;
    cout << "---------------|                                               |" << wG57.print() << endl;
    cout << t6_1.print()<< "                                                |---------------|" << endl;
    cout << "---------------|" << wG5.print() << "                                |               |" << endl;
    cout << t11_1.print()<<"|---------------|                               |               |" << endl;
    cout << "---------------|               |" << wG35.print() << "                |               |" << endl;
    cout << t3_1.print()<< "                |---------------|               |               |" << endl;
    cout << "---------------|" << wG6.print() << "|               |               |               |" << endl;
    cout << t14_1.print()<<"|---------------|               |               |               |" << endl;
    cout << "---------------|                               |" << wG50.print() << "|               |" << endl;
    cout <<  t7_1.print()<<"                                |---------------|               |" << endl;
    cout << "---------------|" << wG7.print() << "                |                               |" << endl;
    cout << t10_1.print()<<"|---------------|               |                               |" << endl;
    cout << "---------------|               |" << wG36.print() << "|                               |" << endl;
    cout << t2_1.print()<< "                |---------------|                               |" << endl;
    cout << "---------------|" << wG8.print() << "|                                               |" << endl;
    cout << t15_1.print()<<"|---------------|                                               |" << endl;
    cout << "---------------|                                                               |" << endl;
    //Region 4
    cout << t1_4.print()<< "                                                                |---------------|" << endl;
    cout << "---------------|" << wG9.print() << "                                                |               |" << endl;
    cout << t16_4.print()<<"|---------------|                                               |               |" << endl;
    cout << "---------------|               |" << wG37.print() << "                                |               |" << endl;
    cout <<  t8_4.print()<<"                |---------------|                               |               |" << endl;
    cout << "---------------|" << wG10.print() << "|               |                               |               |" << endl;
    cout <<  t9_4.print()<<"|---------------|               |                               |               |" << endl;
    cout << "---------------|                               |" << wG51.print() << "                |               |" << endl;
    cout <<  t5_4.print()<<"                                |---------------|               |               |" << endl;
    cout << "---------------|" << wG11.print() << "                |               |               |               |" << endl;
    cout << t12_4.print()<<"|---------------|               |               |               |               |" << endl;
    cout << "---------------|               |" << wG38.print() << "|               |               |               |" << endl;
    cout <<  t4_4.print()<<"                |---------------|               |               |               |" << endl;
    cout << "---------------|" << wG12.print() << "|                               |               |               |" << endl;
    cout << t13_4.print()<<"|---------------|                               |               |               |" << endl;
    cout << "---------------|                                               |" << wG58.print() << "|               |" << endl;
    cout <<  t6_4.print()<<"                                                |---------------|               |" << endl;
    cout << "---------------|" << wG13.print() << "                                |                               |" << endl;
    cout << t11_4.print()<<"|---------------|                               |                               |" << endl;
    cout << "---------------|               |" << wG39.print() << "                |                               |" << endl;
    cout <<  t3_4.print()<<"                |---------------|               |                               |" << endl;
    cout << "---------------|" << wG14.print() << "|               |               |                               |" << endl;
    cout << t14_4.print()<<"|---------------|               |               |                               |" << endl;
    cout << "---------------|                               |" << wG52.print() << "|                               |" << endl;
    cout <<  t7_4.print()<<"                                |---------------|                               |" << endl;
    cout << "---------------|" << wG15.print() << "                |                                               |" << endl;
    cout << t10_4.print()<<"|---------------|               |                                               |" << endl;
    cout << "---------------|               |" << wG40.print() << "|                                               |" << endl;
    cout <<  t2_4.print()<<"                |---------------|                                               |" << endl;
    cout << "---------------|" << wG16.print() << "|                                                               |" << endl;
    cout << t15_4.print()<<"|---------------|                                                               |" << endl;
    cout << "---------------|                                                                               |" << endl;
    //Region 2
    cout <<  t1_2.print()<<"                                                                                |---------------" << endl;
    cout << "---------------|" << wG17.print() << "                                                                |" << endl;
    cout << t16_2.print()<<"|---------------|                                                               |" << endl;
    cout << "---------------|               |" << wG41.print() << "                                                |" << endl;
    cout <<  t8_2.print()<<"                |---------------|                                               |" << endl;
    cout << "---------------|" << wG18.print() << "|               |                                               |" << endl;
    cout <<  t9_2.print()<<"|---------------|               |                                               |" << endl;
    cout << "---------------|                               |" << wG53.print() << "                                |" << endl;
    cout <<  t5_2.print()<<"                                |---------------|                               |" << endl;
    cout << "---------------|" << wG19.print() << "                |               |                               |" << endl;
    cout << t12_2.print()<<"|---------------|               |               |                               |" << endl;
    cout << "---------------|               |" << wG42.print() << "|               |                               |" << endl;
    cout <<  t4_2.print()<<"                |---------------|               |                               |" << endl;
    cout << "---------------|" << wG20.print() << "|                               |                               |" << endl;
    cout << t13_2.print()<<"|---------------|                               |                               |" << endl;
    cout << "---------------|                                               |" << wG59.print() << "                |" << endl;
    cout <<  t6_2.print()<<"                                                |---------------|               |" << endl;
    cout << "---------------|" << wG21.print() << "                                |               |               |" << endl;
    cout << t11_2.print()<<"|---------------|                               |               |               |" << endl;
    cout << "---------------|               |" << wG43.print() << "                |               |               |" << endl;
    cout <<  t3_2.print()<<"                |---------------|               |               |               |" << endl;
    cout << "---------------|" << wG22.print() << "|               |               |               |               |" << endl;
    cout << t14_2.print()<<"|---------------|               |               |               |               |" << endl;
    cout << "---------------|                               |" << wG54.print() << "|               |               |" << endl;
    cout <<  t7_2.print()<<"                                |---------------|               |               |" << endl;
    cout << "---------------|" << wG23.print() << "                |                               |               |" << endl;
    cout << t10_2.print()<<"|---------------|               |                               |               |" << endl;
    cout << "---------------|               |" << wG44.print() << "|                               |               |" << endl;
    cout <<  t2_2.print()<<"                |---------------|                               |               |" << endl;
    cout << "---------------|" << wG24.print() << "|                                               |               |" << endl;
    cout << t15_2.print()<<"|---------------|                                               |               |" << endl;
    cout << "---------------|                                                               |               |" << endl;
    //Region 3
    cout <<  t1_3.print()<<"                                                                |---------------|" << endl;
    cout << "---------------|" << wG25.print() << "                                                |" << endl;
    cout << t16_3.print()<<"|---------------|                                               |" << endl;
    cout << "---------------|               |" << wG45.print() << "                                |" << endl;
    cout <<  t8_3.print()<<"                |---------------|                               |" << endl;
    cout << "---------------|" << wG26.print() << "|               |                               |" << endl;
    cout <<  t9_3.print()<<"|---------------|               |                               |" << endl;
    cout << "---------------|                               |" << wG55.print() << "                |" << endl;
    cout <<  t5_3.print()<<"                                |---------------|               |" << endl;
    cout << "---------------|" << wG27.print() << "                |               |               |" << endl;
    cout << t12_3.print()<<"|---------------|               |               |               |" << endl;
    cout << "---------------|               |" << wG46.print() << "|               |               |" << endl;
    cout <<  t4_3.print()<<"                |---------------|               |               |" << endl;
    cout << "---------------|" << wG28.print() << "|                               |               |" << endl;
    cout << t13_3.print()<<"|---------------|                               |               |" << endl;
    cout << "---------------|                                               |" << wG60.print() << "|" << endl;
    cout <<  t6_3.print()<<"                                                |---------------|" << endl;
    cout << "---------------|" << wG29.print() << "                                |" << endl;
    cout << t11_3.print()<<"|---------------|                               |" << endl;
    cout << "---------------|               |" << wG47.print() << "                |" << endl;
    cout <<  t3_3.print()<<"                |---------------|               |" << endl;
    cout << "---------------|" << wG30.print() << "|               |               |" << endl;
    cout << t14_3.print()<<"|---------------|               |               |" << endl;
    cout << "---------------|                               |" << wG56.print() << "|" << endl;
    cout <<  t7_3.print()<<"                                |---------------|" << endl;
    cout << "---------------|" << wG31.print() << "                |" << endl;
    cout << t10_3.print()<<"|---------------|               |" << endl;
    cout << "---------------|               |" << wG48.print() << "|" << endl;
    cout <<  t2_3.print()<<"                |---------------|" << endl;
    cout << "---------------|" << wG32.print() << "|" << endl;
    cout << t15_3.print()<<"|---------------|" << endl;
    cout << "---------------|" << endl;
    }


    //Setting up 6th round
        //assigning the winners to their own new variables (wG1 = "winner game 1", etc.)
            //Winner of Regions 1 and 4
            Team wG61 = whole_bracket(wG57,wG58);
            //Winner of Regions 2 and 3
            Team wG62 = whole_bracket(wG59,wG60);
    
    //Printing winners of round 5 onto the bracket
    cout << endl << endl << endl;
    cout << "Press 1 then hit enter to simulate the next round of the bracket: ";
    bool q;
    cin >> q;
    cout << endl << endl << endl;

    if(q){//display this only once the user has entered "1"
    cout <<  t1_1.print() << endl;
    cout << "---------------|" << wG1.print()  << endl;
    cout << t16_1.print()<<"|---------------|" << endl;
    cout << "---------------|               |" << wG33.print() << endl;
    cout << t8_1.print()<< "                |---------------|" << endl;
    cout << "---------------|" << wG2.print() << "|               |" << endl;
    cout << t9_1.print()<< "|---------------|               |" << endl;
    cout << "---------------|                               |" << wG49.print() << endl;
    cout <<  t5_1.print()<<"                                |---------------|" << endl;
    cout << "---------------|" << wG3.print() << "                |               |" << endl;
    cout << t12_1.print()<<"|---------------|               |               |" << endl;
    cout << "---------------|               |" << wG34.print() << "|               |" << endl;
    cout << t4_1.print()<< "                |---------------|               |" << endl;
    cout << "---------------|" << wG4.print() << "|                               |" << endl;
    cout << t13_1.print()<<"|---------------|                               |" << endl;
    cout << "---------------|                                               |" << wG57.print() << endl;
    cout << t6_1.print()<< "                                                |---------------|" << endl;
    cout << "---------------|" << wG5.print() << "                                |               |" << endl;
    cout << t11_1.print()<<"|---------------|                               |               |" << endl;
    cout << "---------------|               |" << wG35.print() << "                |               |" << endl;
    cout << t3_1.print()<< "                |---------------|               |               |" << endl;
    cout << "---------------|" << wG6.print() << "|               |               |               |" << endl;
    cout << t14_1.print()<<"|---------------|               |               |               |" << endl;
    cout << "---------------|                               |" << wG50.print() << "|               |" << endl;
    cout <<  t7_1.print()<<"                                |---------------|               |" << endl;
    cout << "---------------|" << wG7.print() << "                |                               |" << endl;
    cout << t10_1.print()<<"|---------------|               |                               |" << endl;
    cout << "---------------|               |" << wG36.print() << "|                               |" << endl;
    cout << t2_1.print()<< "                |---------------|                               |" << endl;
    cout << "---------------|" << wG8.print() << "|                                               |" << endl;
    cout << t15_1.print()<<"|---------------|                                               |" << endl;
    cout << "---------------|                                                               |" << wG61.print() << endl;
    //Region 4
    cout << t1_4.print()<< "                                                                |---------------|" << endl;
    cout << "---------------|" << wG9.print() << "                                                |               |" << endl;
    cout << t16_4.print()<<"|---------------|                                               |               |" << endl;
    cout << "---------------|               |" << wG37.print() << "                                |               |" << endl;
    cout <<  t8_4.print()<<"                |---------------|                               |               |" << endl;
    cout << "---------------|" << wG10.print() << "|               |                               |               |" << endl;
    cout <<  t9_4.print()<<"|---------------|               |                               |               |" << endl;
    cout << "---------------|                               |" << wG51.print() << "                |               |" << endl;
    cout <<  t5_4.print()<<"                                |---------------|               |               |" << endl;
    cout << "---------------|" << wG11.print() << "                |               |               |               |" << endl;
    cout << t12_4.print()<<"|---------------|               |               |               |               |" << endl;
    cout << "---------------|               |" << wG38.print() << "|               |               |               |" << endl;
    cout <<  t4_4.print()<<"                |---------------|               |               |               |" << endl;
    cout << "---------------|" << wG12.print() << "|                               |               |               |" << endl;
    cout << t13_4.print()<<"|---------------|                               |               |               |" << endl;
    cout << "---------------|                                               |" << wG58.print() << "|               |" << endl;
    cout <<  t6_4.print()<<"                                                |---------------|               |" << endl;
    cout << "---------------|" << wG13.print() << "                                |                               |" << endl;
    cout << t11_4.print()<<"|---------------|                               |                               |" << endl;
    cout << "---------------|               |" << wG39.print() << "                |                               |" << endl;
    cout <<  t3_4.print()<<"                |---------------|               |                               |" << endl;
    cout << "---------------|" << wG14.print() << "|               |               |                               |" << endl;
    cout << t14_4.print()<<"|---------------|               |               |                               |" << endl;
    cout << "---------------|                               |" << wG52.print() << "|                               |" << endl;
    cout <<  t7_4.print()<<"                                |---------------|                               |" << endl;
    cout << "---------------|" << wG15.print() << "                |                                               |" << endl;
    cout << t10_4.print()<<"|---------------|               |                                               |" << endl;
    cout << "---------------|               |" << wG40.print() << "|                                               |" << endl;
    cout <<  t2_4.print()<<"                |---------------|                                               |" << endl;
    cout << "---------------|" << wG16.print() << "|                                                               |" << endl;
    cout << t15_4.print()<<"|---------------|                                                               |" << endl;
    cout << "---------------|                                                                               |" << endl;
    //Region 2
    cout <<  t1_2.print()<<"                                                                                |---------------" << endl;
    cout << "---------------|" << wG17.print() << "                                                                |" << endl;
    cout << t16_2.print()<<"|---------------|                                                               |" << endl;
    cout << "---------------|               |" << wG41.print() << "                                                |" << endl;
    cout <<  t8_2.print()<<"                |---------------|                                               |" << endl;
    cout << "---------------|" << wG18.print() << "|               |                                               |" << endl;
    cout <<  t9_2.print()<<"|---------------|               |                                               |" << endl;
    cout << "---------------|                               |" << wG53.print() << "                                |" << endl;
    cout <<  t5_2.print()<<"                                |---------------|                               |" << endl;
    cout << "---------------|" << wG19.print() << "                |               |                               |" << endl;
    cout << t12_2.print()<<"|---------------|               |               |                               |" << endl;
    cout << "---------------|               |" << wG42.print() << "|               |                               |" << endl;
    cout <<  t4_2.print()<<"                |---------------|               |                               |" << endl;
    cout << "---------------|" << wG20.print() << "|                               |                               |" << endl;
    cout << t13_2.print()<<"|---------------|                               |                               |" << endl;
    cout << "---------------|                                               |" << wG59.print() << "                |" << endl;
    cout <<  t6_2.print()<<"                                                |---------------|               |" << endl;
    cout << "---------------|" << wG21.print() << "                                |               |               |" << endl;
    cout << t11_2.print()<<"|---------------|                               |               |               |" << endl;
    cout << "---------------|               |" << wG43.print() << "                |               |               |" << endl;
    cout <<  t3_2.print()<<"                |---------------|               |               |               |" << endl;
    cout << "---------------|" << wG22.print() << "|               |               |               |               |" << endl;
    cout << t14_2.print()<<"|---------------|               |               |               |               |" << endl;
    cout << "---------------|                               |" << wG54.print() << "|               |               |" << endl;
    cout <<  t7_2.print()<<"                                |---------------|               |               |" << endl;
    cout << "---------------|" << wG23.print() << "                |                               |               |" << endl;
    cout << t10_2.print()<<"|---------------|               |                               |               |" << endl;
    cout << "---------------|               |" << wG44.print() << "|                               |               |" << endl;
    cout <<  t2_2.print()<<"                |---------------|                               |               |" << endl;
    cout << "---------------|" << wG24.print() << "|                                               |               |" << endl;
    cout << t15_2.print()<<"|---------------|                                               |               |" << endl;
    cout << "---------------|                                                               |" << wG62.print() << "|" << endl;
    //Region 3
    cout <<  t1_3.print()<<"                                                                |---------------|" << endl;
    cout << "---------------|" << wG25.print() << "                                                |" << endl;
    cout << t16_3.print()<<"|---------------|                                               |" << endl;
    cout << "---------------|               |" << wG45.print() << "                                |" << endl;
    cout <<  t8_3.print()<<"                |---------------|                               |" << endl;
    cout << "---------------|" << wG26.print() << "|               |                               |" << endl;
    cout <<  t9_3.print()<<"|---------------|               |                               |" << endl;
    cout << "---------------|                               |" << wG55.print() << "                |" << endl;
    cout <<  t5_3.print()<<"                                |---------------|               |" << endl;
    cout << "---------------|" << wG27.print() << "                |               |               |" << endl;
    cout << t12_3.print()<<"|---------------|               |               |               |" << endl;
    cout << "---------------|               |" << wG46.print() << "|               |               |" << endl;
    cout <<  t4_3.print()<<"                |---------------|               |               |" << endl;
    cout << "---------------|" << wG28.print() << "|                               |               |" << endl;
    cout << t13_3.print()<<"|---------------|                               |               |" << endl;
    cout << "---------------|                                               |" << wG60.print() << "|" << endl;
    cout <<  t6_3.print()<<"                                                |---------------|" << endl;
    cout << "---------------|" << wG29.print() << "                                |" << endl;
    cout << t11_3.print()<<"|---------------|                               |" << endl;
    cout << "---------------|               |" << wG47.print() << "                |" << endl;
    cout <<  t3_3.print()<<"                |---------------|               |" << endl;
    cout << "---------------|" << wG30.print() << "|               |               |" << endl;
    cout << t14_3.print()<<"|---------------|               |               |" << endl;
    cout << "---------------|                               |" << wG56.print() << "|" << endl;
    cout <<  t7_3.print()<<"                                |---------------|" << endl;
    cout << "---------------|" << wG31.print() << "                |" << endl;
    cout << t10_3.print()<<"|---------------|               |" << endl;
    cout << "---------------|               |" << wG48.print() << "|" << endl;
    cout <<  t2_3.print()<<"                |---------------|" << endl;
    cout << "---------------|" << wG32.print() << "|" << endl;
    cout << t15_3.print()<<"|---------------|" << endl;
    cout << "---------------|" << endl;
    }


   //Finalizing bracket
        //assigning the winner to its own new variable (wG1 = "winner game 1", etc.)
            //Champion
            Team wG63 = whole_bracket(wG61,wG62);

    
    //Printing champion onto the bracket
    cout << endl << endl << endl;
    cout << "Press 1 then hit enter to simulate the next round of the bracket: ";
    bool x;
    cin >> x;
    cout << endl << endl << endl;
    
    if(x){//display this only once the user has entered "1"
    cout <<  t1_1.print() << endl;
    cout << "---------------|" << wG1.print()  << endl;
    cout << t16_1.print()<<"|---------------|" << endl;
    cout << "---------------|               |" << wG33.print() << endl;
    cout << t8_1.print()<< "                |---------------|" << endl;
    cout << "---------------|" << wG2.print() << "|               |" << endl;
    cout << t9_1.print()<< "|---------------|               |" << endl;
    cout << "---------------|                               |" << wG49.print() << endl;
    cout <<  t5_1.print()<<"                                |---------------|" << endl;
    cout << "---------------|" << wG3.print() << "                |               |" << endl;
    cout << t12_1.print()<<"|---------------|               |               |" << endl;
    cout << "---------------|               |" << wG34.print() << "|               |" << endl;
    cout << t4_1.print()<< "                |---------------|               |" << endl;
    cout << "---------------|" << wG4.print() << "|                               |" << endl;
    cout << t13_1.print()<<"|---------------|                               |" << endl;
    cout << "---------------|                                               |" << wG57.print() << endl;
    cout << t6_1.print()<< "                                                |---------------|" << endl;
    cout << "---------------|" << wG5.print() << "                                |               |" << endl;
    cout << t11_1.print()<<"|---------------|                               |               |" << endl;
    cout << "---------------|               |" << wG35.print() << "                |               |" << endl;
    cout << t3_1.print()<< "                |---------------|               |               |" << endl;
    cout << "---------------|" << wG6.print() << "|               |               |               |" << endl;
    cout << t14_1.print()<<"|---------------|               |               |               |" << endl;
    cout << "---------------|                               |" << wG50.print() << "|               |" << endl;
    cout <<  t7_1.print()<<"                                |---------------|               |" << endl;
    cout << "---------------|" << wG7.print() << "                |                               |" << endl;
    cout << t10_1.print()<<"|---------------|               |                               |" << endl;
    cout << "---------------|               |" << wG36.print() << "|                               |" << endl;
    cout << t2_1.print()<< "                |---------------|                               |" << endl;
    cout << "---------------|" << wG8.print() << "|                                               |" << endl;
    cout << t15_1.print()<<"|---------------|                                               |" << endl;
    cout << "---------------|                                                               |" << wG61.print() << endl;
    //Region 4
    cout << t1_4.print()<< "                                                                |---------------|" << endl;
    cout << "---------------|" << wG9.print() << "                                                |               |" << endl;
    cout << t16_4.print()<<"|---------------|                                               |               |" << endl;
    cout << "---------------|               |" << wG37.print() << "                                |               |" << endl;
    cout <<  t8_4.print()<<"                |---------------|                               |               |" << endl;
    cout << "---------------|" << wG10.print() << "|               |                               |               |" << endl;
    cout <<  t9_4.print()<<"|---------------|               |                               |               |" << endl;
    cout << "---------------|                               |" << wG51.print() << "                |               |" << endl;
    cout <<  t5_4.print()<<"                                |---------------|               |               |" << endl;
    cout << "---------------|" << wG11.print() << "                |               |               |               |" << endl;
    cout << t12_4.print()<<"|---------------|               |               |               |               |" << endl;
    cout << "---------------|               |" << wG38.print() << "|               |               |               |" << endl;
    cout <<  t4_4.print()<<"                |---------------|               |               |               |" << endl;
    cout << "---------------|" << wG12.print() << "|                               |               |               |" << endl;
    cout << t13_4.print()<<"|---------------|                               |               |               |" << endl;
    cout << "---------------|                                               |" << wG58.print() << "|               |" << endl;
    cout <<  t6_4.print()<<"                                                |---------------|               |" << endl;
    cout << "---------------|" << wG13.print() << "                                |                               |" << endl;
    cout << t11_4.print()<<"|---------------|                               |                               |" << endl;
    cout << "---------------|               |" << wG39.print() << "                |                               |" << endl;
    cout <<  t3_4.print()<<"                |---------------|               |                               |" << endl;
    cout << "---------------|" << wG14.print() << "|               |               |                               |" << endl;
    cout << t14_4.print()<<"|---------------|               |               |                               |" << endl;
    cout << "---------------|                               |" << wG52.print() << "|                               |" << endl;
    cout <<  t7_4.print()<<"                                |---------------|                               |" << endl;
    cout << "---------------|" << wG15.print() << "                |                                               |" << endl;
    cout << t10_4.print()<<"|---------------|               |                                               |" << endl;
    cout << "---------------|               |" << wG40.print() << "|                                               |" << endl;
    cout <<  t2_4.print()<<"                |---------------|                                               |" << endl;
    cout << "---------------|" << wG16.print() << "|                                                               |" << endl;
    cout << t15_4.print()<<"|---------------|                                                               |" << endl;
    cout << "---------------|                                                                               |" << wG63.print() << endl;
    //Region 2
    cout <<  t1_2.print()<<"                                                                                |---------------" << endl;
    cout << "---------------|" << wG17.print() << "                                                                |   CHAMPION" << endl;
    cout << t16_2.print()<<"|---------------|                                                               |" << endl;
    cout << "---------------|               |" << wG41.print() << "                                                |" << endl;
    cout <<  t8_2.print()<<"                |---------------|                                               |" << endl;
    cout << "---------------|" << wG18.print() << "|               |                                               |" << endl;
    cout <<  t9_2.print()<<"|---------------|               |                                               |" << endl;
    cout << "---------------|                               |" << wG53.print() << "                                |" << endl;
    cout <<  t5_2.print()<<"                                |---------------|                               |" << endl;
    cout << "---------------|" << wG19.print() << "                |               |                               |" << endl;
    cout << t12_2.print()<<"|---------------|               |               |                               |" << endl;
    cout << "---------------|               |" << wG42.print() << "|               |                               |" << endl;
    cout <<  t4_2.print()<<"                |---------------|               |                               |" << endl;
    cout << "---------------|" << wG20.print() << "|                               |                               |" << endl;
    cout << t13_2.print()<<"|---------------|                               |                               |" << endl;
    cout << "---------------|                                               |" << wG59.print() << "                |" << endl;
    cout <<  t6_2.print()<<"                                                |---------------|               |" << endl;
    cout << "---------------|" << wG21.print() << "                                |               |               |" << endl;
    cout << t11_2.print()<<"|---------------|                               |               |               |" << endl;
    cout << "---------------|               |" << wG43.print() << "                |               |               |" << endl;
    cout <<  t3_2.print()<<"                |---------------|               |               |               |" << endl;
    cout << "---------------|" << wG22.print() << "|               |               |               |               |" << endl;
    cout << t14_2.print()<<"|---------------|               |               |               |               |" << endl;
    cout << "---------------|                               |" << wG54.print() << "|               |               |" << endl;
    cout <<  t7_2.print()<<"                                |---------------|               |               |" << endl;
    cout << "---------------|" << wG23.print() << "                |                               |               |" << endl;
    cout << t10_2.print()<<"|---------------|               |                               |               |" << endl;
    cout << "---------------|               |" << wG44.print() << "|                               |               |" << endl;
    cout <<  t2_2.print()<<"                |---------------|                               |               |" << endl;
    cout << "---------------|" << wG24.print() << "|                                               |               |" << endl;
    cout << t15_2.print()<<"|---------------|                                               |               |" << endl;
    cout << "---------------|                                                               |" << wG62.print() << "|" << endl;
    //Region 3
    cout <<  t1_3.print()<<"                                                                |---------------|" << endl;
    cout << "---------------|" << wG25.print() << "                                                |" << endl;
    cout << t16_3.print()<<"|---------------|                                               |" << endl;
    cout << "---------------|               |" << wG45.print() << "                                |" << endl;
    cout <<  t8_3.print()<<"                |---------------|                               |" << endl;
    cout << "---------------|" << wG26.print() << "|               |                               |" << endl;
    cout <<  t9_3.print()<<"|---------------|               |                               |" << endl;
    cout << "---------------|                               |" << wG55.print() << "                |" << endl;
    cout <<  t5_3.print()<<"                                |---------------|               |" << endl;
    cout << "---------------|" << wG27.print() << "                |               |               |" << endl;
    cout << t12_3.print()<<"|---------------|               |               |               |" << endl;
    cout << "---------------|               |" << wG46.print() << "|               |               |" << endl;
    cout <<  t4_3.print()<<"                |---------------|               |               |" << endl;
    cout << "---------------|" << wG28.print() << "|                               |               |" << endl;
    cout << t13_3.print()<<"|---------------|                               |               |" << endl;
    cout << "---------------|                                               |" << wG60.print() << "|" << endl;
    cout <<  t6_3.print()<<"                                                |---------------|" << endl;
    cout << "---------------|" << wG29.print() << "                                |" << endl;
    cout << t11_3.print()<<"|---------------|                               |" << endl;
    cout << "---------------|               |" << wG47.print() << "                |" << endl;
    cout <<  t3_3.print()<<"                |---------------|               |" << endl;
    cout << "---------------|" << wG30.print() << "|               |               |" << endl;
    cout << t14_3.print()<<"|---------------|               |               |" << endl;
    cout << "---------------|                               |" << wG56.print() << "|" << endl;
    cout <<  t7_3.print()<<"                                |---------------|" << endl;
    cout << "---------------|" << wG31.print() << "                |" << endl;
    cout << t10_3.print()<<"|---------------|               |" << endl;
    cout << "---------------|               |" << wG48.print() << "|" << endl;
    cout <<  t2_3.print()<<"                |---------------|" << endl;
    cout << "---------------|" << wG32.print() << "|" << endl;
    cout << t15_3.print()<<"|---------------|" << endl;
    cout << "---------------|" << endl;
    }
    
}


//FUNCTIONS FOR ROUND 1 GAMES

    Team one_vs_16(Team one, Team sixteen){
        //Probability data is taken from the overall historical record of 1 seeds vs 16 seeds in the first round
        //The record of 1 seeds vs 16 seeds is 143-1
        int rand_num = (rand() % 144) + 1; //random number chosen from 1 to 144
        if(rand_num >= 1 && rand_num <= 143){
            return one;
        } else{
            return sixteen;
        }
    }


    Team eight_vs_9(Team eight, Team nine){
        //Probability data is taken from the overall historical record of 8 seeds vs 9 seeds in the first round
        //The record of 8 seeds vs 9 seeds is 72-72
        int rand_num = (rand() % 144) + 1; //random number chosen from 1 to 144
        if(rand_num >= 1 && rand_num <= 72){
            return eight;
        } else{
            return nine;
        }
    }

    Team five_vs_12(Team five, Team twelve){
        //Probability data is taken from the overall historical record of 5 seeds vs 12 seeds in the first round
        //The record of 5 seeds vs 12 seeds is 93-51
        int rand_num = (rand() % 144) + 1; //random number chosen from 1 to 144
        if(rand_num >= 1 && rand_num <= 93){
            return five;
        } else{
            return twelve;
        }
    }

    Team four_vs_13(Team four, Team thirteen){
        //Probability data is taken from the overall historical record of 4 seeds vs 13 seeds in the first round
        //The record of 4 seeds vs 13 seeds is 113-31
        int rand_num = (rand() % 144) + 1; //random number chosen from 1 to 144
        if(rand_num >= 1 && rand_num <= 113){
            return four;
        } else{
            return thirteen;
        }
    }


    Team six_vs_11(Team six, Team eleven){
        //Probability data is taken from the overall historical record of 6 seeds vs 11 seeds in the first round
        //The record of 6 seeds vs 11 seeds is 90-54
        int rand_num = (rand() % 144) + 1; //random number chosen from 1 to 144
        if(rand_num >= 1 && rand_num <= 90){
            return six;
        } else {
            return eleven;
        }
    }


    Team three_vs_14(Team three, Team fourteen){
        //Probability data is taken from the overall historical record of 3 seeds vs 14 seeds in the first round
        //The record of 3 seeds vs 14 seeds is 122-22
        int rand_num = (rand() % 144) + 1; //random number chosen from 1 to 144
        if(rand_num >= 1 && rand_num <= 122){
            return three;
        } else{
            return fourteen;
        }
    }


    Team seven_vs_10(Team seven, Team ten){
        //Probability data is taken from the overall historical record of 7 seeds vs 10 seeds in the first round
        //The record of 7 seeds vs 10 seeds is 87-57
        int rand_num = (rand() % 144) + 1; //random number chosen from 1 to 144
        if(rand_num >= 1 && rand_num <= 87){
            return seven;
        } else{
            return ten;
        }
    }


    Team two_vs_15(Team two, Team fifteen){
        //Probability data is taken from the overall historical record of 2 seeds vs 15 seeds in the first round
        //The record of 2 seeds vs 15 seeds is 135-9
        int rand_num = (rand() % 144) + 1; //random number chosen from 1 to 144
        if(rand_num >= 1 && rand_num <= 135){ 
            return two;
        } else {
            return fifteen;
        }
    }


//FUNCTIONS FOR ROUND 2 GAMES

    Team quadrant1(Team winner1, Team winner2){
        //In the case of 1 seed vs 8 seed
        if(winner1.seed_num == 1 && winner2.seed_num == 8){
            //Probability data is taken from the overall historical record of 1 seeds vs 8 seeds
            //The record of 1 seeds vs 8 seeds is 60-15
            int rand_num = (rand() % 75) + 1; //random number chosen from 1 to 75
            if(rand_num >= 1 && rand_num <= 60){ 
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of 1 seed vs 9 seed
        if(winner1.seed_num == 1 && winner2.seed_num == 9){
            //Probability data is taken from the overall historical record of 1 seeds vs 9 seeds
            //The record of 1 seeds vs 9 seeds is 66-5
            int rand_num = (rand() % 71) + 1; //random number chosen from 1 to 71
            if(rand_num >= 1 && rand_num <= 66){ 
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of 16 seed vs 8 seed
        if(winner1.seed_num == 16 && winner2.seed_num == 8){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
            if(rand_num >= 1 && rand_num <= 10){ //estimated 10% chance of 16 seed winning
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of 16 seed vs 9 seed
        if(winner1.seed_num == 16 && winner2.seed_num == 9){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
            if(rand_num >= 1 && rand_num <= 10){ //estimated 10% chance of 16 seed winning
                return winner1;
            } else {
                return winner2;
            }
        }
        else{
            return Team();
        }
    }

    Team quadrant2(Team winner1, Team winner2){
        //In the case of a 5 seed vs a 4 seed
        if(winner1.seed_num == 5 && winner2.seed_num == 4){
            //Probability data is taken from the overall historical record of 5 seeds vs 4 seeds
            //The record of 5 seeds vs 4 seeds is 33-42
            int rand_num = (rand() % 75) + 1; //random number chosen from 1 to 75
            if(rand_num >= 1 && rand_num <= 33){ 
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 5 seed vs a 13 seed
        if(winner1.seed_num == 5 && winner2.seed_num == 13){
            //Probability data is taken from the overall historical record of 5 seeds vs 13 seeds
            //The record of 5 seeds vs 13 seeds is 16-3
            int rand_num = (rand() % 19) + 1; //random number chosen from 1 to 19
            if(rand_num >= 1 && rand_num <= 16){ 
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 12 seed vs a 4 seed
        if(winner1.seed_num == 12 && winner2.seed_num == 4){
            //Probability data is taken from the overall historical record of 12 seeds vs 4 seeds
            //The record of 12 seeds vs 4 seeds is 13-26
            int rand_num = (rand() % 39) + 1; //random number chosen from 1 to 39
            if(rand_num >= 1 && rand_num <= 13){ 
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 12 seed vs a 13 seed
        if(winner1.seed_num == 12 && winner2.seed_num == 13){
            //Probability data is taken from the overall historical record of 12 seeds vs 13 seeds
            //The record of 12 seeds vs 13 seeds is 9-3
            int rand_num = (rand() % 12) + 1; //random number chosen from 1 to 12
            if(rand_num >= 1 && rand_num <= 9){ 
                return winner1;
            } else {
                return winner2;
            }
        }
        else{
            return Team();
        }
    }

    Team quadrant3(Team winner1, Team winner2){
        //In the case of a 6 seed vs a 3 seed
        if(winner1.seed_num == 6 && winner2.seed_num == 3){
            //Probability data is taken from the overall historical record of 6 seeds vs 3 seeds
            //The record of 6 seeds vs 3 seeds is 29-45
            int rand_num = (rand() % 74) + 1; //random number chosen from 1 to 74
            if(rand_num >= 1 && rand_num <= 29){ 
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 6 seed vs a 14 seed
        if(winner1.seed_num == 6 && winner2.seed_num == 14){
            //Probability data is taken from the overall historical record of 6 seeds vs 14 seeds
            //The record of 6 seeds vs 14 seeds is 14-2
            int rand_num = (rand() % 16) + 1; //random number chosen from 1 to 16
            if(rand_num >= 1 && rand_num <= 14){ 
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 11 seed vs a 3 seed
        if(winner1.seed_num == 11 && winner2.seed_num == 3){
            //Probability data is taken from the overall historical record of 11 seeds vs 3 seeds
            //The record of 11 seeds vs 3 seeds is 18-32
            int rand_num = (rand() % 50) + 1; //random number chosen from 1 to 50
            if(rand_num >= 1 && rand_num <= 18){ 
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 11 seed vs a 14 seed
        if(winner1.seed_num == 11 && winner2.seed_num == 14){
            //Probability data is adapted from the overall historical record of 11 seeds vs 14 seeds
            //The record of 11 seeds vs 14 seeds is 5-0
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 8){ 
                return winner1;
            } else {
                return winner2;
            }
        }
        else{
            return Team();
        }
    }

    Team quadrant4(Team winner1, Team winner2){
        //In the case of a 7 seed vs a 2 seed
        if(winner1.seed_num == 7 && winner2.seed_num == 2){
            //Probability data is taken from the overall historical record of 7 seeds vs 2 seeds
            //The record of 7 seeds vs 2 seeds is 26-56
            int rand_num = (rand() % 82) + 1; //random number chosen from 1 to 82
            if(rand_num >= 1 && rand_num <= 26){ 
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 7 seed vs a 15 seed
        if(winner1.seed_num == 7 && winner2.seed_num == 15){
            //Probability data is adapted from the overall historical record of 7 seeds vs 15 seeds
            //The record of 7 seeds vs 15 seeds is 2-2
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 8){ //15 seed given a 20% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 10 seed vs a 2 seed
        if(winner1.seed_num == 10 && winner2.seed_num == 2){
            //Probability data is taken from the overall historical record of 10 seeds vs 2 seeds
            //The record of 10 seeds vs 2 seeds is 18-35
            int rand_num = (rand() % 53) + 1; //random number chosen from 1 to 53
            if(rand_num >= 1 && rand_num <= 18){ 
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 10 seed vs a 15 seed
        if(winner1.seed_num == 10 && winner2.seed_num == 15){
            //Probability data is adapted from the overall historical record of 10 seeds vs 15 seeds
            //The record of 10 seeds vs 15 seeds is 5-0
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 8){ //15 seed given a 20% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        else{
            return Team();
        }
    }


//FUNCTIONS FOR ROUND 3 GAMES

    Team upper_half(Team winner1, Team winner2){
        //In the case of a 1 seed vs a 4 seed
        if(winner1.seed_num == 1 && winner2.seed_num == 4){
            //Probability data is taken from the overall historical record of 1 seeds vs 4 seeds
            //The record of 1 seeds vs 4 seeds is 45-18
            int rand_num = (rand() % 63) + 1; //random number chosen from 1 to 63
            if(rand_num >= 1 && rand_num <= 45){ 
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 1 seed vs a 5 seed
        if(winner1.seed_num == 1 && winner2.seed_num == 5){
            //Probability data is taken from the overall historical record of 1 seeds vs 5 seeds
            //The record of 1 seeds vs 5 seeds is 41-8
            int rand_num = (rand() % 49) + 1; //random number chosen from 1 to 49
            if(rand_num >= 1 && rand_num <= 41){ 
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 1 seed vs a 12 seed
        if(winner1.seed_num == 1 && winner2.seed_num == 12){
            //Probability data is adapted from the overall historical record of 1 seeds vs 12 seeds
            //The record of 1 seeds vs 12 seeds is 19-0
            int rand_num = (rand() % 50) + 1; //random number chosen from 1 to 50
            if(rand_num >= 1 && rand_num <= 45){ //12 seed given a 10% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 1 seed vs a 13 seed
        if(winner1.seed_num == 1 && winner2.seed_num == 13){
            //Probability data is adapted from the overall historical record of 1 seeds vs 13 seeds
            //The record of 1 seeds vs 13 seeds is 3-0
            int rand_num = (rand() % 50) + 1; //random number chosen from 1 to 50
            if(rand_num >= 1 && rand_num <= 47){ //13 seed given a 6% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of an 8 seed vs a 4 seed
        if(winner1.seed_num == 8 && winner2.seed_num == 4){
            //Probability data is adapted from the overall historical record of 8 seeds vs 4 seeds
            //The record of 8 seeds vs 4 seeds is 5-4
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 4){ //8 seed given a 40% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of an 8 seed vs a 5 seed
        if(winner1.seed_num == 8 && winner2.seed_num == 5){
            //Probability data is adapted from the overall historical record of 8 seeds vs 5 seeds
            //The record of 8 seeds vs 5 seeds is 2-1
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 9){ //8 seed given a 45% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of an 8 seed vs a 12 seed
        if(winner1.seed_num == 8 && winner2.seed_num == 12){
            //Probability data is adapted from the overall historical record of 8 seeds vs 12 seeds
            //The record of 8 seeds vs 12 seeds is 0-2
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 4){ //12 seed given a 40% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of an 8 seed vs a 13 seed
        if(winner1.seed_num == 8 && winner2.seed_num == 13){
            //Probability data is adapted from the overall historical record of 8 seeds vs 13 seeds
            //The record of 8 seeds vs 13 seeds is 1-0
            int rand_num = (rand() % 50) + 1; //random number chosen from 1 to 50
            if(rand_num >= 1 && rand_num <= 16){ //13 seed given a 32% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 9 seed vs a 4 seed
        if(winner1.seed_num == 9 && winner2.seed_num == 4){
            //Probability data is adapted from the overall historical record of 9 seeds vs 4 seeds
            //The record of 9 seeds vs 4 seeds is 2-2
            int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
            if(rand_num >= 1 && rand_num <= 37){ //9 seed given a 37% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 9 seed vs a 5 seed
        if(winner1.seed_num == 9 && winner2.seed_num == 5){
            //Probability data is adapted from the overall historical record of 9 seeds vs 5 seeds
            //The record of 9 seeds vs 5 seeds is 1-1
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 4){ //9 seed given a 40% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 9 seed vs a 12 seed
        if(winner1.seed_num == 9 && winner2.seed_num == 12){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 9){ //12 seed given a 45% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 9 seed vs a 13 seed
        if(winner1.seed_num == 9 && winner2.seed_num == 13){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 4){ //13 seed given a 40% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 16 seed vs a 4 seed
        if(winner1.seed_num == 16 && winner2.seed_num == 4){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 1){ //16 seed given a 10% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 16 seed vs a 5 seed
        if(winner1.seed_num == 16 && winner2.seed_num == 5){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 1){ //16 seed given a 10% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 16 seed vs a 12 seed
        if(winner1.seed_num == 16 && winner2.seed_num == 12){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 2){ //16 seed given a 20% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 16 seed vs a 13 seed
        if(winner1.seed_num == 16 && winner2.seed_num == 13){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 5){ //16 seed given a 25% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        else{
            return Team();
        }
    }

    Team lower_half(Team winner1, Team winner2){
        //In the case of a 3 seed vs a 2 seed
        if(winner1.seed_num == 3 && winner2.seed_num == 2){
            //Probability data is taken from the overall historical record of 3 seeds vs 2 seeds
            //The record of 3 seeds vs 2 seeds is 21-33
            int rand_num = (rand() % 54) + 1; //random number chosen from 1 to 54
            if(rand_num >= 1 && rand_num <= 21){ 
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 3 seed vs a 7 seed
        if(winner1.seed_num == 3 && winner2.seed_num == 7){
            //Probability data is taken from the overall historical record of 3 seeds vs 7 seeds
            //The record of 3 seeds vs 7 seeds is 10-6
            int rand_num = (rand() % 16) + 1; //random number chosen from 1 to 16
            if(rand_num >= 1 && rand_num <= 10){ 
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 3 seed vs a 10 seed
        if(winner1.seed_num == 3 && winner2.seed_num == 10){
            //Probability data is taken from the overall historical record of 3 seeds vs 10 seeds
            //The record of 3 seeds vs 10 seeds is 10-4
            int rand_num = (rand() % 14) + 1; //random number chosen from 1 to 14
            if(rand_num >= 1 && rand_num <= 10){ 
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 3 seed vs a 15 seed
        if(winner1.seed_num == 3 && winner2.seed_num == 15){
            //Probability data is adapted from the overall historical record of 3 seeds vs 15 seeds
            //The record of 3 seeds vs 15 seeds is 2-0
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 17){ 
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 6 seed vs a 2 seed
        if(winner1.seed_num == 6 && winner2.seed_num == 2){
            //Probability data is taken from the overall historical record of 6 seeds vs 2 seeds
            //The record of 6 seeds vs 2 seeds is 7-23
            int rand_num = (rand() % 30) + 1; //random number chosen from 1 to 30
            if(rand_num >= 1 && rand_num <= 7){ 
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 6 seed vs a 7 seed
        if(winner1.seed_num == 6 && winner2.seed_num == 7){
            //Probability data is adapted from the overall historical record of 6 seeds vs 7 seeds
            //The record of 6 seeds vs 7 seeds is 5-2
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 6){ //7 seed has 40% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 6 seed vs a 10 seed
        if(winner1.seed_num == 6 && winner2.seed_num == 10){
            //Probability data is taken from the overall historical record of 6 seeds vs 10 seeds
            //The record of 6 seeds vs 10 seeds is 4-2
            int rand_num = (rand() % 6) + 1; //random number chosen from 1 to 6
            if(rand_num >= 1 && rand_num <= 4){ 
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 6 seed vs a 15 seed
        if(winner1.seed_num == 6 && winner2.seed_num == 15){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 8){ //15 seed has a 20% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of an 11 seed vs a 2 seed
        if(winner1.seed_num == 11 && winner2.seed_num == 2){
            //Probability data is taken from the overall historical record of 11 seeds vs 2 seeds
            //The record of 11 seeds vs 2 seeds is 3-15
            int rand_num = (rand() % 18) + 1; //random number chosen from 1 to 18
            if(rand_num >= 1 && rand_num <= 3){ 
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of an 11 seed vs a 7 seed
        if(winner1.seed_num == 11 && winner2.seed_num == 7){
            //Probability data is adapted from the overall historical record of 11 seeds vs 7 seeds
            //The record of 11 seeds vs 7 seeds is 4-0
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 4){ //11 seed has 40% chance to win
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of an 11 seed vs a 10 seed
        if(winner1.seed_num == 11 && winner2.seed_num == 10){
            //Probability data is adapted from the overall historical record of 11 seeds vs 10 seeds
            //The record of 11 seeds vs 10 seeds is 2-1
            int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
            if(rand_num >= 1 && rand_num <= 48){ //11 seed has 48% chance to win
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of an 11 seed vs a 15 seed
        if(winner1.seed_num == 11 && winner2.seed_num == 15){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 13){ //15 seed has a 35% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 14 seed vs a 2 seed
        if(winner1.seed_num == 14 && winner2.seed_num == 2){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
            if(rand_num >= 1 && rand_num <= 11){ //14 seed has an 11% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 14 seed vs a 7 seed
        if(winner1.seed_num == 14 && winner2.seed_num == 7){
            //Probability data is adapted from the overall historical record of 14 seeds vs 7 seeds
            //The record of 14 seeds vs 7 seeds is 0-1
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 2){ //14 seed has a 20% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 14 seed vs a 10 seed
        if(winner1.seed_num == 14 && winner2.seed_num == 10){
            //Probability data is adapted from the overall historical record of 14 seeds vs 10 seeds
            //The record of 14 seeds vs 10 seeds is 0-1
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 3){ //14 seed has a 30% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 14 seed vs a 15 seed
        if(winner1.seed_num == 14 && winner2.seed_num == 15){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 11){ //15 seed has a 45% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        else{
            return Team();
        }
    }


//FUNCTION FOR ROUND 4 GAMES

    Team whole_region(Team winner1, Team winner2){
        //In the case of a 1 seed vs a 2 seed
        if(winner1.seed_num == 1 && winner2.seed_num == 2){
            //Probability data is taken from the overall historical record of 1 seeds vs 2 seeds
            //The record of 1 seeds vs 2 seeds is 35-28
            int rand_num = (rand() % 63) + 1; //random number chosen from 1 to 63
            if(rand_num >= 1 && rand_num <= 35){ 
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 1 seed vs a 3 seed
        if(winner1.seed_num == 1 && winner2.seed_num == 3){
            //Probability data is taken from the overall historical record of 1 seeds vs 3 seeds
            //The record of 1 seeds vs 3 seeds is 21-14
            int rand_num = (rand() % 35) + 1; //random number chosen from 1 to 35
            if(rand_num >= 1 && rand_num <= 21){ 
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 1 seed vs a 6 seed
        if(winner1.seed_num == 1 && winner2.seed_num == 6){
            //Probability data is taken from the overall historical record of 1 seeds vs 6 seeds
            //The record of 1 seeds vs 6 seeds is 7-3
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 7){ 
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 1 seed vs a 7 seed
        if(winner1.seed_num == 1 && winner2.seed_num == 7){
            //Probability data is adjusted from the overall historical record of 1 seeds vs 7 seeds
            //The record of 1 seeds vs 7 seeds is 6-1
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 8){ //7 seed has a 20% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 1 seed vs a 10 seed
        if(winner1.seed_num == 1 && winner2.seed_num == 10){
            //Probability data is adjusted from the overall historical record of 1 seeds vs 10 seeds
            //The record of 1 seeds vs 10 seeds is 5-1
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 17){ //10 seed has a 15% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 1 seed vs an 11 seed
        if(winner1.seed_num == 1 && winner2.seed_num == 11){
            //Probability data is adjusted from the overall historical record of 1 seeds vs 11 seeds
            //The record of 1 seeds vs 11 seeds is 5-4
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 17){ //11 seed has a 15% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 1 seed vs a 14 seed
        if(winner1.seed_num == 1 && winner2.seed_num == 14){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 9){ //14 seed has a 10% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 1 seed vs a 15 seed
        if(winner1.seed_num == 1 && winner2.seed_num == 15){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 19){ //15 seed has a 5% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 4 seed vs a 2 seed
        if(winner1.seed_num == 4 && winner2.seed_num == 2){
            //Probability data is adjusted from the overall historical record of 4 seeds vs 2 seeds
            //The record of 4 seeds vs 2 seeds is 4-3
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 4){ //4 seed has 40% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 4 seed vs a 3 seed
        if(winner1.seed_num == 4 && winner2.seed_num == 3){
            //Probability data is adjusted from the overall historical record of 4 seeds vs 3 seeds
            //The record of 4 seeds vs 3 seeds is 2-4
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 9){ //4 seed has 45% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 4 seed vs a 6 seed
        if(winner1.seed_num == 4 && winner2.seed_num == 6){
            //Probability data is adjusted from the overall historical record of 4 seeds vs 6 seeds
            //The record of 4 seeds vs 6 seeds is 2-2
            int rand_num = (rand() % 50) + 1; //random number chosen from 1 to 50
            if(rand_num >= 1 && rand_num <= 29){ //6 seed has a 42% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 4 seed vs a 7 seed
        if(winner1.seed_num == 4 && winner2.seed_num == 7){
            //Probability data is adjusted from the overall historical record of 4 seeds vs 7 seeds
            //The record of 4 seeds vs 7 seeds is 2-3
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 6){ //7 seed has a 40% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 4 seed vs a 10 seed
        if(winner1.seed_num == 4 && winner2.seed_num == 10){
            //Probability data is adjusted from the overall historical record of 4 seeds vs 10 seeds
            //The record of 4 seeds vs 10 seeds is 2-0
            int rand_num = (rand() % 50) + 1; //random number chosen from 1 to 50
            if(rand_num >= 1 && rand_num <= 34){ //10 seed has a 32% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 4 seed vs an 11 seed
        if(winner1.seed_num == 4 && winner2.seed_num == 11){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 7){ //11 seed has a 30% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 4 seed vs a 14 seed
        if(winner1.seed_num == 4 && winner2.seed_num == 14){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 17){ //14 seed has a 15% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 4 seed vs a 15 seed
        if(winner1.seed_num == 4 && winner2.seed_num == 15){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 17){ //15 seed has a 15% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 5 seed vs a 2 seed
        if(winner1.seed_num == 5 && winner2.seed_num == 2){
            //Probability data is adjusted from the overall historical record of 5 seeds vs 2 seeds
            //The record of 5 seeds vs 2 seeds is 3-0
            int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
            if(rand_num >= 1 && rand_num <= 35){ //5 seed has 35% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 5 seed vs a 3 seed
        if(winner1.seed_num == 5 && winner2.seed_num == 3){
            //Probability data is adjusted from the overall historical record of 5 seeds vs 3 seeds
            //The record of 5 seeds vs 3 seeds is 1-2
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 4){ //5 seed has 40% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 5 seed vs a 6 seed
        if(winner1.seed_num == 5 && winner2.seed_num == 6){
            //Probability data is adjusted from the overall historical record of 5 seeds vs 6 seeds
            //The record of 5 seeds vs 6 seeds is 1-0
            int rand_num = (rand() % 50) + 1; //random number chosen from 1 to 50
            if(rand_num >= 1 && rand_num <= 26){ //6 seed has a 48% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 5 seed vs a 7 seed
        if(winner1.seed_num == 5 && winner2.seed_num == 7){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
            if(rand_num >= 1 && rand_num <= 57){ //7 seed has a 43% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 5 seed vs a 10 seed
        if(winner1.seed_num == 5 && winner2.seed_num == 10){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 13){ //10 seed has a 35% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 5 seed vs an 11 seed
        if(winner1.seed_num == 5 && winner2.seed_num == 11){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 13){ //11 seed has a 35% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 5 seed vs a 14 seed
        if(winner1.seed_num == 5 && winner2.seed_num == 14){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 8){ //14 seed has a 20% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 5 seed vs a 15 seed
        if(winner1.seed_num == 5 && winner2.seed_num == 15){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 17){ //15 seed has a 15% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 8 seed vs a 2 seed
        if(winner1.seed_num == 8 && winner2.seed_num == 2){
            //Probability data is adjusted from the overall historical record of 8 seeds vs 2 seeds
            //The record of 8 seeds vs 2 seeds is 5-2
            int rand_num = (rand() % 4) + 1; //random number chosen from 1 to 4
            if(rand_num >= 1 && rand_num <= 1){ //8 seed has 25% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 8 seed vs a 3 seed
        if(winner1.seed_num == 8 && winner2.seed_num == 3){
            //Probability data is adjusted from the overall historical record of 8 seeds vs 3 seeds
            //The record of 8 seeds vs 3 seeds is 0-2
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 3){ //8 seed has 30% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 8 seed vs a 6 seed
        if(winner1.seed_num == 8 && winner2.seed_num == 6){
            //Probability data is adjusted from the overall historical record of 8 seeds vs 6 seeds
            //The record of 8 seeds vs 6 seeds is 1-0
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 9){ //8 seed has a 45% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 8 seed vs a 7 seed
        if(winner1.seed_num == 5 && winner2.seed_num == 7){
            //Probability data is adjusted from the overall historical record of 8 seeds vs 7 seeds
            //The record of 8 seeds vs 7 seeds is 1-1
            int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
            if(rand_num >= 1 && rand_num <= 48){ //8 seed has a 48% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 8 seed vs a 10 seed
        if(winner1.seed_num == 8 && winner2.seed_num == 10){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 11){ //10 seed has a 45% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 8 seed vs an 11 seed
        if(winner1.seed_num == 8 && winner2.seed_num == 11){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 11){ //11 seed has a 45% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 8 seed vs a 14 seed
        if(winner1.seed_num == 8 && winner2.seed_num == 14){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 13){ //14 seed has a 35% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 8 seed vs a 15 seed
        if(winner1.seed_num == 8 && winner2.seed_num == 15){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 7){ //15 seed has a 30% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 9 seed vs a 2 seed
        if(winner1.seed_num == 9 && winner2.seed_num == 2){
            //Probability data is adjusted from the overall historical record of 9 seeds vs 2 seeds
            //The record of 9 seeds vs 2 seeds is 1-0
            int rand_num = (rand() % 4) + 1; //random number chosen from 1 to 4
            if(rand_num >= 1 && rand_num <= 1){ //9 seed has 25% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 9 seed vs a 3 seed
        if(winner1.seed_num == 9 && winner2.seed_num == 3){
            //Probability data is adjusted from the overall historical record of 9 seeds vs 3 seeds
            //The record of 9 seeds vs 3 seeds is 0-2
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 3){ //9 seed has 30% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 9 seed vs a 6 seed
        if(winner1.seed_num == 9 && winner2.seed_num == 6){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 4){ //9 seed has a 40% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 9 seed vs a 7 seed
        if(winner1.seed_num == 9 && winner2.seed_num == 7){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
            if(rand_num >= 1 && rand_num <= 45){ //9 seed has a 45% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 9 seed vs a 10 seed
        if(winner1.seed_num == 9 && winner2.seed_num == 10){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 11){ //10 seed has a 45% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 9 seed vs an 11 seed
        if(winner1.seed_num == 9 && winner2.seed_num == 11){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 11){ //11 seed has a 45% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 9 seed vs a 14 seed
        if(winner1.seed_num == 9 && winner2.seed_num == 14){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 13){ //14 seed has a 35% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 9 seed vs a 15 seed
        if(winner1.seed_num == 9 && winner2.seed_num == 15){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 7){ //15 seed has a 30% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 12 seed vs a 2 seed
        if(winner1.seed_num == 12 && winner2.seed_num == 2){
            //Probability data is adjusted from the overall historical record of 12 seeds vs 2 seeds
            //The record of 12 seeds vs 2 seeds is 0-2
            int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
            if(rand_num >= 1 && rand_num <= 22){ //12 seed has 22% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 12 seed vs a 3 seed
        if(winner1.seed_num == 12 && winner2.seed_num == 3){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 4) + 1; //random number chosen from 1 to 4
            if(rand_num >= 1 && rand_num <= 1){ //12 seed has 25% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 12 seed vs a 6 seed
        if(winner1.seed_num == 12 && winner2.seed_num == 6){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
            if(rand_num >= 1 && rand_num <= 32){ //12 seed has a 32% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 12 seed vs a 7 seed
        if(winner1.seed_num == 12 && winner2.seed_num == 7){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
            if(rand_num >= 1 && rand_num <= 35){ //12 seed has a 35% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 12 seed vs a 10 seed
        if(winner1.seed_num == 12 && winner2.seed_num == 10){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 4){ //12 seed has a 40% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 12 seed vs an 11 seed
        if(winner1.seed_num == 12 && winner2.seed_num == 11){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 9){ //12 seed has a 45% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 12 seed vs a 14 seed
        if(winner1.seed_num == 12 && winner2.seed_num == 14){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 6){ //14 seed has a 40% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 12 seed vs a 15 seed
        if(winner1.seed_num == 12 && winner2.seed_num == 15){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
            if(rand_num >= 1 && rand_num <= 65){ //15 seed has a 35% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 13 seed vs a 2 seed
        if(winner1.seed_num == 13 && winner2.seed_num == 2){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
            if(rand_num >= 1 && rand_num <= 15){ //13 seed has 15% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 13 seed vs a 3 seed
        if(winner1.seed_num == 13 && winner2.seed_num == 3){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 5) + 1; //random number chosen from 1 to 5
            if(rand_num >= 1 && rand_num <= 1){ //13 seed has 20% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 13 seed vs a 6 seed
        if(winner1.seed_num == 13 && winner2.seed_num == 6){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
            if(rand_num >= 1 && rand_num <= 27){ //13 seed has a 27% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 13 seed vs a 7 seed
        if(winner1.seed_num == 13 && winner2.seed_num == 7){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 3){ //13 seed has a 30% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 13 seed vs a 10 seed
        if(winner1.seed_num == 13 && winner2.seed_num == 10){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 7){ //13 seed has a 35% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 13 seed vs an 11 seed
        if(winner1.seed_num == 13 && winner2.seed_num == 11){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 4){ //13 seed has a 40% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 13 seed vs a 14 seed
        if(winner1.seed_num == 13 && winner2.seed_num == 14){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
            if(rand_num >= 1 && rand_num <= 52){ //14 seed has a 48% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 13 seed vs a 15 seed
        if(winner1.seed_num == 13 && winner2.seed_num == 15){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 6){ //15 seed has a 40% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 16 seed vs a 2 seed
        if(winner1.seed_num == 16 && winner2.seed_num == 2){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
            if(rand_num >= 1 && rand_num <= 8){ //16 seed has 8% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 16 seed vs a 3 seed
        if(winner1.seed_num == 16 && winner2.seed_num == 3){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
            if(rand_num >= 1 && rand_num <= 12){ //16 seed has 12% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 16 seed vs a 6 seed
        if(winner1.seed_num == 16 && winner2.seed_num == 6){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 2){ //16 seed has a 20% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 16 seed vs a 7 seed
        if(winner1.seed_num == 16 && winner2.seed_num == 7){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 4) + 1; //random number chosen from 1 to 4
            if(rand_num >= 1 && rand_num <= 1){ //13 seed has a 25% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 16 seed vs a 10 seed
        if(winner1.seed_num == 16 && winner2.seed_num == 10){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
            if(rand_num >= 1 && rand_num <= 32){ //16 seed has a 32% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 16 seed vs an 11 seed
        if(winner1.seed_num == 16 && winner2.seed_num == 11){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 7){ //16 seed has a 35% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 16 seed vs a 14 seed
        if(winner1.seed_num == 16 && winner2.seed_num == 14){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
            if(rand_num >= 1 && rand_num <= 42){ //16 seed has a 42% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //In the case of a 16 seed vs a 15 seed
        if(winner1.seed_num == 16 && winner2.seed_num == 15){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 9){ //16 seed has a 45% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        else{
            return Team();
        }
    }


//FUNCTION FOR ROUNDS 5 AND 6 GAMES
//NOTE: since the lowest seed ever to make these rounds has been an 11 seed, that is as far as I went with this simulator
       
    Team whole_bracket(Team winner1, Team winner2){
        //1 seed cases
        ///*
            //In the case of a 1 seed vs a 1 seed
            if(winner1.seed_num == 1 && winner2.seed_num == 1){
                //Probability is an even 50/50 since the two are the same seed
                int rand_num = (rand() % 2) + 1; //random number chosen from 1 to 2
                if(rand_num == 1){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 1 seed vs a 2 seed
            if(winner1.seed_num == 1 && winner2.seed_num == 2){
                //Probability data is taken from the overall historical record of 1 seeds vs 2 seeds
                //The record of 1 seeds vs 2 seeds is 35-28
                int rand_num = (rand() % 63) + 1; //random number chosen from 1 to 63
                if(rand_num >= 1 && rand_num <= 35){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 1 seed vs a 3 seed
            if(winner1.seed_num == 1 && winner2.seed_num == 3){
                //Probability data is taken from the overall historical record of 1 seeds vs 3 seeds
                //The record of 1 seeds vs 3 seeds is 21-14
                int rand_num = (rand() % 35) + 1; //random number chosen from 1 to 35
                if(rand_num >= 1 && rand_num <= 21){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 1 seed vs a 4 seed
            if(winner1.seed_num == 1 && winner2.seed_num == 4){
                //Probability data is taken from the overall historical record of 1 seeds vs 4 seeds
                //The record of 1 seeds vs 4 seeds is 45-18
                int rand_num = (rand() % 63) + 1; //random number chosen from 1 to 63
                if(rand_num >= 1 && rand_num <= 45){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 1 seed vs a 5 seed
            if(winner1.seed_num == 1 && winner2.seed_num == 5){
                //Probability data is taken from the overall historical record of 1 seeds vs 5 seeds
                //The record of 1 seeds vs 5 seeds is 41-8
                int rand_num = (rand() % 49) + 1; //random number chosen from 1 to 49
                if(rand_num >= 1 && rand_num <= 41){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 1 seed vs a 6 seed
            if(winner1.seed_num == 1 && winner2.seed_num == 6){
                //Probability data is taken from the overall historical record of 1 seeds vs 6 seeds
                //The record of 1 seeds vs 6 seeds is 7-3
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 7){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 1 seed vs a 7 seed
            if(winner1.seed_num == 1 && winner2.seed_num == 7){
                //Probability data is adjusted from the overall historical record of 1 seeds vs 7 seeds
                //The record of 1 seeds vs 7 seeds is 6-1
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 8){ //7 seed has a 20% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 1 seed vs an 8 seed
            if(winner1.seed_num == 1 && winner2.seed_num == 8){
                //Probability data is taken from the overall historical record of 1 seeds vs 8 seeds
                //The record of 1 seeds vs 8 seeds is 60-15
                int rand_num = (rand() % 75) + 1; //random number chosen from 1 to 75
                if(rand_num >= 1 && rand_num <= 60){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 1 seed vs a 9 seed
            if(winner1.seed_num == 1 && winner2.seed_num == 9){
                //Probability data is taken from the overall historical record of 1 seeds vs 9 seeds
                //The record of 1 seeds vs 9 seeds is 66-5
                int rand_num = (rand() % 71) + 1; //random number chosen from 1 to 71
                if(rand_num >= 1 && rand_num <= 66){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 1 seed vs a 10 seed
            if(winner1.seed_num == 1 && winner2.seed_num == 10){
                //Probability data is adjusted from the overall historical record of 1 seeds vs 10 seeds
                //The record of 1 seeds vs 10 seeds is 5-1
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 17){ //10 seed has a 15% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 1 seed vs an 11 seed
            if(winner1.seed_num == 1 && winner2.seed_num == 11){
                //Probability data is adjusted from the overall historical record of 1 seeds vs 11 seeds
                //The record of 1 seeds vs 11 seeds is 5-4
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 17){ //11 seed has a 15% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 1 seed vs a 12 seed
            if(winner1.seed_num == 1 && winner2.seed_num == 12){
                //Probability data is adapted from the overall historical record of 1 seeds vs 12 seeds
                //The record of 1 seeds vs 12 seeds is 19-0
                int rand_num = (rand() % 50) + 1; //random number chosen from 1 to 50
                if(rand_num >= 1 && rand_num <= 45){ //12 seed given a 10% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 1 seed vs a 13 seed
            if(winner1.seed_num == 1 && winner2.seed_num == 13){
                //Probability data is adapted from the overall historical record of 1 seeds vs 13 seeds
                //The record of 1 seeds vs 13 seeds is 3-0
                int rand_num = (rand() % 50) + 1; //random number chosen from 1 to 50
                if(rand_num >= 1 && rand_num <= 47){ //13 seed given a 6% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 1 seed vs a 14 seed
            if(winner1.seed_num == 1 && winner2.seed_num == 14){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 9){ //14 seed has a 10% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 1 seed vs a 15 seed
            if(winner1.seed_num == 1 && winner2.seed_num == 15){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 19){ //15 seed has a 5% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 1 seed vs a 16 seed
            if(winner1.seed_num == 1 && winner2.seed_num == 16){
                //Probability data is taken from the overall historical record of 1 seeds vs 16 seeds in the first round
                //The record of 1 seeds vs 16 seeds is 143-1
                int rand_num = (rand() % 144) + 1; //random number chosen from 1 to 144
                if(rand_num >= 1 && rand_num <= 143){
                    return winner1;
                } else{
                    return winner2;
                }
            }
            //*/

        //2 seed cases
        ///*
            //In the case of a 2 seed vs a 1 seed
            if(winner1.seed_num == 2 && winner2.seed_num == 1){
                //Probability data is taken from the overall historical record of 2 seeds vs 1 seeds
                //The record of 2 seeds vs 1 seeds is 28-35
                int rand_num = (rand() % 63) + 1; //random number chosen from 1 to 63
                if(rand_num >= 1 && rand_num <= 28){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 2 seed vs a 2 seed
            if(winner1.seed_num == 2 && winner2.seed_num == 2){
                //Probability is an even 50/50 since the two are the same seed
                int rand_num = (rand() % 2) + 1; //random number chosen from 1 to 2
                if(rand_num == 1){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 2 seed vs a 3 seed
            if(winner1.seed_num == 2 && winner2.seed_num == 3){
                //Probability data is taken from the overall historical record of 2 seeds vs 3 seeds
                //The record of 2 seeds vs 3 seeds is 33-21
                int rand_num = (rand() % 54) + 1; //random number chosen from 1 to 54
                if(rand_num >= 1 && rand_num <= 33){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 2 seed vs a 4 seed
            if(winner1.seed_num == 2 && winner2.seed_num == 4){
                //Probability data is adjusted from the overall historical record of 2 seeds vs 4 seeds
                //The record of 2 seeds vs 4 seeds is 3-4
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 6){ //4 seed has 40% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 2 seed vs a 5 seed
            if(winner1.seed_num == 2 && winner2.seed_num == 5){
                //Probability data is adjusted from the overall historical record of 2 seeds vs 5 seeds
                //The record of 2 seeds vs 5 seeds is 0-3
                int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
                if(rand_num >= 1 && rand_num <= 65){ //5 seed has 35% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 2 seed vs a 6 seed
            if(winner1.seed_num == 2 && winner2.seed_num == 6){
                //Probability data is taken from the overall historical record of 2 seeds vs 6 seeds
                //The record of 2 seeds vs 6 seeds is 23-7
                int rand_num = (rand() % 30) + 1; //random number chosen from 1 to 30
                if(rand_num >= 1 && rand_num <= 23){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 2 seed vs a 7 seed
            if(winner1.seed_num == 2 && winner2.seed_num == 7){
                //Probability data is taken from the overall historical record of 2 seeds vs 7 seeds
                //The record of 2 seeds vs 7 seeds is 56-26
                int rand_num = (rand() % 82) + 1; //random number chosen from 1 to 82
                if(rand_num >= 1 && rand_num <= 56){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 2 seed vs an 8 seed
            if(winner1.seed_num == 2 && winner2.seed_num == 8){
                //Probability data is adjusted from the overall historical record of 2 seeds vs 8 seeds
                //The record of 2 seeds vs 8 seeds is 2-5
                int rand_num = (rand() % 4) + 1; //random number chosen from 1 to 4
                if(rand_num >= 1 && rand_num <= 3){ //8 seed has 25% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 2 seed vs a 9 seed
            if(winner1.seed_num == 2 && winner2.seed_num == 9){
                //Probability data is adjusted from the overall historical record of 2 seeds vs 9 seeds
                //The record of 2 seeds vs 9 seeds is 0-1
                int rand_num = (rand() % 4) + 1; //random number chosen from 1 to 4
                if(rand_num >= 1 && rand_num <= 3){ //9 seed has 25% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 2 seed vs a 10 seed
            if(winner1.seed_num == 2 && winner2.seed_num == 10){
                //Probability data is taken from the overall historical record of 2 seeds vs 10 seeds
                //The record of 2 seeds vs 10 seeds is 35-18
                int rand_num = (rand() % 53) + 1; //random number chosen from 1 to 53
                if(rand_num >= 1 && rand_num <= 35){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 2 seed vs an 11 seed
            if(winner1.seed_num == 2 && winner2.seed_num == 11){
                //Probability data is taken from the overall historical record of 2 seeds vs 11 seeds
                //The record of 2 seeds vs 11 seeds is 15-3
                int rand_num = (rand() % 18) + 1; //random number chosen from 1 to 18
                if(rand_num >= 1 && rand_num <= 15){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 2 seed vs a 12 seed
            if(winner1.seed_num == 2 && winner2.seed_num == 12){
                //Probability data is adjusted from the overall historical record of 2 seeds vs 12 seeds
                //The record of 2 seeds vs 12 seeds is 2-0
                int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
                if(rand_num >= 1 && rand_num <= 78){ //12 seed has 22% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 2 seed vs a 13 seed
            if(winner1.seed_num == 2 && winner2.seed_num == 13){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
                if(rand_num >= 1 && rand_num <= 85){ //13 seed has 15% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 2 seed vs a 14 seed
            if(winner1.seed_num == 2 && winner2.seed_num == 14){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
                if(rand_num >= 1 && rand_num <= 89){ //14 seed has an 11% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 2 seed vs a 15 seed
            if(winner1.seed_num == 2 && winner2.seed_num == 15){
                //Probability data is taken from the overall historical record of 2 seeds vs 15 seeds in the first round
                //The record of 2 seeds vs 15 seeds is 135-9
                int rand_num = (rand() % 144) + 1; //random number chosen from 1 to 144
                if(rand_num >= 1 && rand_num <= 135){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 2 seed vs a 16 seed
            if(winner1.seed_num == 2 && winner2.seed_num == 16){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
                if(rand_num >= 1 && rand_num <= 92){ //16 seed has 8% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //*/

        //3 seed cases
        ///*
            //In the case of a 3 seed vs a 1 seed
            if(winner1.seed_num == 3 && winner2.seed_num == 1){
                //Probability data is taken from the overall historical record of 3 seeds vs 1 seeds
                //The record of 3 seeds vs 1 seeds is 14-21
                int rand_num = (rand() % 35) + 1; //random number chosen from 1 to 35
                if(rand_num >= 1 && rand_num <= 14){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 3 seed vs a 2 seed
            if(winner1.seed_num == 3 && winner2.seed_num == 2){
                //Probability data is taken from the overall historical record of 3 seeds vs 2 seeds
                //The record of 3 seeds vs 2 seeds is 21-33
                int rand_num = (rand() % 54) + 1; //random number chosen from 1 to 54
                if(rand_num >= 1 && rand_num <= 21){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 3 seed vs a 3 seed
            if(winner1.seed_num == 3 && winner2.seed_num == 3){
                //Probability is an even 50/50 since the two are the same seed
                int rand_num = (rand() % 2) + 1; //random number chosen from 1 to 2
                if(rand_num == 1){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 3 seed vs a 4 seed
            if(winner1.seed_num == 3 && winner2.seed_num == 4){
                //Probability data is adjusted from the overall historical record of 3 seeds vs 4 seeds
                //The record of 3 seeds vs 4 seeds is 4-2
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 11){ //4 seed has 45% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 3 seed vs a 5 seed
            if(winner1.seed_num == 3 && winner2.seed_num == 5){
                //Probability data is adjusted from the overall historical record of 3 seeds vs 5 seeds
                //The record of 3 seeds vs 5 seeds is 2-1
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 6){ //5 seed has 40% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 3 seed vs a 6 seed
            if(winner1.seed_num == 3 && winner2.seed_num == 6){
                //Probability data is taken from the overall historical record of 3 seeds vs 6 seeds
                //The record of 3 seeds vs 6 seeds is 45-29
                int rand_num = (rand() % 74) + 1; //random number chosen from 1 to 74
                if(rand_num >= 1 && rand_num <= 45){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 3 seed vs a 7 seed
            if(winner1.seed_num == 3 && winner2.seed_num == 7){
                //Probability data is taken from the overall historical record of 3 seeds vs 7 seeds
                //The record of 3 seeds vs 7 seeds is 10-6
                int rand_num = (rand() % 16) + 1; //random number chosen from 1 to 16
                if(rand_num >= 1 && rand_num <= 10){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 3 seed vs an 8 seed
            if(winner1.seed_num == 3 && winner2.seed_num == 8){
                //Probability data is adjusted from the overall historical record of 3 seeds vs 8 seeds
                //The record of 3 seeds vs 8 seeds is 2-0
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 7){ //8 seed has 30% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 3 seed vs a 9 seed
            if(winner1.seed_num == 3 && winner2.seed_num == 9){
                //Probability data is adjusted from the overall historical record of 3 seeds vs 9 seeds
                //The record of 3 seeds vs 9 seeds is 2-0
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 7){ //9 seed has 30% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 3 seed vs a 10 seed
            if(winner1.seed_num == 3 && winner2.seed_num == 10){
                //Probability data is taken from the overall historical record of 3 seeds vs 10 seeds
                //The record of 3 seeds vs 10 seeds is 10-4
                int rand_num = (rand() % 14) + 1; //random number chosen from 1 to 14
                if(rand_num >= 1 && rand_num <= 10){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 3 seed vs an 11 seed
            if(winner1.seed_num == 3 && winner2.seed_num == 11){
                //Probability data is taken from the overall historical record of 3 seeds vs 11 seeds
                //The record of 3 seeds vs 11 seeds is 32-18
                int rand_num = (rand() % 50) + 1; //random number chosen from 1 to 50
                if(rand_num >= 1 && rand_num <= 32){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 3 seed vs a 12 seed
            if(winner1.seed_num == 3 && winner2.seed_num == 12){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 4) + 1; //random number chosen from 1 to 4
                if(rand_num >= 1 && rand_num <= 3){ //12 seed has 25% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 3 seed vs a 13 seed
            if(winner1.seed_num == 3 && winner2.seed_num == 13){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 5) + 1; //random number chosen from 1 to 5
                if(rand_num >= 1 && rand_num <= 4){ //13 seed has 20% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 3 seed vs a 14 seed
            if(winner1.seed_num == 3 && winner2.seed_num == 14){
                //Probability data is taken from the overall historical record of 3 seeds vs 14 seeds in the first round
                //The record of 3 seeds vs 14 seeds is 122-22
                int rand_num = (rand() % 144) + 1; //random number chosen from 1 to 144
                if(rand_num >= 1 && rand_num <= 122){
                    return winner1;
                } else{
                    return winner2;
                }
            }
            //In the case of a 3 seed vs a 15 seed
            if(winner1.seed_num == 3 && winner2.seed_num == 15){
                //Probability data is adapted from the overall historical record of 3 seeds vs 15 seeds
                //The record of 3 seeds vs 15 seeds is 2-0
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 17){ //15 seed has 15% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 3 seed vs a 16 seed
            if(winner1.seed_num == 3 && winner2.seed_num == 16){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
                if(rand_num >= 1 && rand_num <= 88){ //16 seed has 12% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //*/

        //4 seed cases
        ///*
            //In the case of a 4 seed vs a 1 seed
            if(winner1.seed_num == 4 && winner2.seed_num == 1){
                //Probability data is taken from the overall historical record of 4 seeds vs 1 seeds
                //The record of 1 seeds vs 4 seeds is 18-45
                int rand_num = (rand() % 63) + 1; //random number chosen from 1 to 63
                if(rand_num >= 1 && rand_num <= 18){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 4 seed vs a 2 seed
            if(winner1.seed_num == 4 && winner2.seed_num == 2){
                //Probability data is adjusted from the overall historical record of 4 seeds vs 2 seeds
                //The record of 4 seeds vs 2 seeds is 4-3
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 4){ //4 seed has 40% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 4 seed vs a 3 seed
            if(winner1.seed_num == 4 && winner2.seed_num == 3){
                //Probability data is adjusted from the overall historical record of 4 seeds vs 3 seeds
                //The record of 4 seeds vs 3 seeds is 2-4
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 9){ //4 seed has 45% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 4 seed vs a 4 seed
            if(winner1.seed_num == 4 && winner2.seed_num == 4){
                //Probability is an even 50/50 since the two are the same seed
                int rand_num = (rand() % 2) + 1; //random number chosen from 1 to 2
                if(rand_num == 1){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 4 seed vs a 5 seed
            if(winner1.seed_num == 4 && winner2.seed_num == 5){
                //Probability data is taken from the overall historical record of 4 seeds vs 5 seeds
                //The record of 4 seeds vs 5 seeds is 42-33
                int rand_num = (rand() % 75) + 1; //random number chosen from 1 to 75
                if(rand_num >= 1 && rand_num <= 42){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 4 seed vs a 6 seed
            if(winner1.seed_num == 4 && winner2.seed_num == 6){
                //Probability data is adjusted from the overall historical record of 4 seeds vs 6 seeds
                //The record of 4 seeds vs 6 seeds is 2-2
                int rand_num = (rand() % 50) + 1; //random number chosen from 1 to 50
                if(rand_num >= 1 && rand_num <= 29){ //6 seed has a 42% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 4 seed vs a 7 seed
            if(winner1.seed_num == 4 && winner2.seed_num == 7){
                //Probability data is adjusted from the overall historical record of 4 seeds vs 7 seeds
                //The record of 4 seeds vs 7 seeds is 2-3
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 6){ //7 seed has a 40% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 4 seed vs an 8 seed
            if(winner1.seed_num == 4 && winner2.seed_num == 8){
                //Probability data is adapted from the overall historical record of 4 seeds vs 8 seeds
                //The record of 4 seeds vs 8 seeds is 4-5
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 6){ //8 seed given a 40% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 4 seed vs a 9 seed
            if(winner1.seed_num == 4 && winner2.seed_num == 9){
                //Probability data is adapted from the overall historical record of 4 seeds vs 9 seeds
                //The record of 4 seeds vs 9 seeds is 2-2
                int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
                if(rand_num >= 1 && rand_num <= 63){ //9 seed given a 37% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 4 seed vs a 10 seed
            if(winner1.seed_num == 4 && winner2.seed_num == 10){
                //Probability data is adjusted from the overall historical record of 4 seeds vs 10 seeds
                //The record of 4 seeds vs 10 seeds is 2-0
                int rand_num = (rand() % 50) + 1; //random number chosen from 1 to 50
                if(rand_num >= 1 && rand_num <= 34){ //10 seed has a 32% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 4 seed vs an 11 seed
            if(winner1.seed_num == 4 && winner2.seed_num == 11){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 7){ //11 seed has a 30% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 4 seed vs a 12 seed
            if(winner1.seed_num == 4 && winner2.seed_num == 12){
                //Probability data is taken from the overall historical record of 4 seeds vs 12 seeds
                //The record of 4 seeds vs 12 seeds is 26-13
                int rand_num = (rand() % 39) + 1; //random number chosen from 1 to 39
                if(rand_num >= 1 && rand_num <= 26){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 4 seed vs a 13 seed
            if(winner1.seed_num == 4 && winner2.seed_num == 13){
                //Probability data is taken from the overall historical record of 4 seeds vs 13 seeds in the first round
                //The record of 4 seeds vs 13 seeds is 113-31
                int rand_num = (rand() % 144) + 1; //random number chosen from 1 to 144
                if(rand_num >= 1 && rand_num <= 113){
                    return winner1;
                } else{
                    return winner2;
                }
            }
            //In the case of a 4 seed vs a 14 seed
            if(winner1.seed_num == 4 && winner2.seed_num == 14){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 17){ //14 seed has a 15% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 4 seed vs a 15 seed
            if(winner1.seed_num == 4 && winner2.seed_num == 15){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 17){ //15 seed has a 15% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 4 seed vs a 16 seed
        if(winner1.seed_num == 4 && winner2.seed_num == 16){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
            if(rand_num >= 1 && rand_num <= 9){ //16 seed given a 10% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        //*/

        //5 seed cases
        ///*
            //In the case of a 5 seed vs a 1 seed
            if(winner1.seed_num == 5 && winner2.seed_num == 1){
                //Probability data is taken from the overall historical record of 5 seeds vs 1 seeds
                //The record of 5 seeds vs 1 seeds is 8-41
                int rand_num = (rand() % 49) + 1; //random number chosen from 1 to 49
                if(rand_num >= 1 && rand_num <= 8){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 5 seed vs a 2 seed
            if(winner1.seed_num == 5 && winner2.seed_num == 2){
                //Probability data is adjusted from the overall historical record of 5 seeds vs 2 seeds
                //The record of 5 seeds vs 2 seeds is 3-0
                int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
                if(rand_num >= 1 && rand_num <= 35){ //5 seed has 35% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 5 seed vs a 3 seed
            if(winner1.seed_num == 5 && winner2.seed_num == 3){
                //Probability data is adjusted from the overall historical record of 5 seeds vs 3 seeds
                //The record of 5 seeds vs 3 seeds is 1-2
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 4){ //5 seed has 40% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 5 seed vs a 4 seed
            if(winner1.seed_num == 5 && winner2.seed_num == 4){
                //Probability data is taken from the overall historical record of 5 seeds vs 4 seeds
                //The record of 5 seeds vs 4 seeds is 33-42
                int rand_num = (rand() % 75) + 1; //random number chosen from 1 to 75
                if(rand_num >= 1 && rand_num <= 33){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 5 seed vs a 5 seed
            if(winner1.seed_num == 5 && winner2.seed_num == 5){
                //Probability is an even 50/50 since the two are the same seed
                int rand_num = (rand() % 2) + 1; //random number chosen from 1 to 2
                if(rand_num == 1){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 5 seed vs a 6 seed
            if(winner1.seed_num == 5 && winner2.seed_num == 6){
                //Probability data is adjusted from the overall historical record of 5 seeds vs 6 seeds
                //The record of 5 seeds vs 6 seeds is 1-0
                int rand_num = (rand() % 50) + 1; //random number chosen from 1 to 50
                if(rand_num >= 1 && rand_num <= 26){ //6 seed has a 48% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 5 seed vs a 7 seed
            if(winner1.seed_num == 5 && winner2.seed_num == 7){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
                if(rand_num >= 1 && rand_num <= 57){ //7 seed has a 43% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of an 5 seed vs a 8 seed
            if(winner1.seed_num == 5 && winner2.seed_num == 8){
                //Probability data is adapted from the overall historical record of 5 seeds vs 8 seeds
                //The record of 5 seeds vs 8 seeds is 1-2
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 11){ //8 seed given a 45% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 5 seed vs a 9 seed
            if(winner1.seed_num == 5 && winner2.seed_num == 9){
                //Probability data is adapted from the overall historical record of 5 seeds vs 9 seeds
                //The record of 5 seeds vs 9 seeds is 1-1
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 6){ //9 seed given a 40% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 5 seed vs a 10 seed
            if(winner1.seed_num == 5 && winner2.seed_num == 10){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 13){ //10 seed has a 35% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 5 seed vs an 11 seed
            if(winner1.seed_num == 5 && winner2.seed_num == 11){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 13){ //11 seed has a 35% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 5 seed vs an 12 seed
            if(winner1.seed_num == 5 && winner2.seed_num == 12){
                //Probability data is taken from the overall historical record of 5 seeds vs 12 seeds in the first round
                //The record of 5 seeds vs 12 seeds is 93-51
                int rand_num = (rand() % 144) + 1; //random number chosen from 1 to 144
                if(rand_num >= 1 && rand_num <= 93){
                    return winner1;
                } else{
                    return winner2;
                }
            }
            //In the case of a 5 seed vs a 13 seed
            if(winner1.seed_num == 5 && winner2.seed_num == 13){
                //Probability data is taken from the overall historical record of 5 seeds vs 13 seeds
                //The record of 5 seeds vs 13 seeds is 16-3
                int rand_num = (rand() % 19) + 1; //random number chosen from 1 to 19
                if(rand_num >= 1 && rand_num <= 16){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 5 seed vs a 14 seed
            if(winner1.seed_num == 5 && winner2.seed_num == 14){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 8){ //14 seed has a 20% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 5 seed vs a 15 seed
            if(winner1.seed_num == 5 && winner2.seed_num == 15){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 17){ //15 seed has a 15% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 5 seed vs a 16 seed
            if(winner1.seed_num == 5 && winner2.seed_num == 16){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 9){ //16 seed given a 10% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //*/

        //6 seed cases
        ///*
            //In the case of a 6 seed vs a 1 seed
            if(winner1.seed_num == 6 && winner2.seed_num == 1){
                //Probability data is taken from the overall historical record of 6 seeds vs 1 seeds
                //The record of 6 seeds vs 1 seeds is 3-7
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 3){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 6 seed vs a 2 seed
            if(winner1.seed_num == 6 && winner2.seed_num == 2){
                //Probability data is taken from the overall historical record of 6 seeds vs 2 seeds
                //The record of 6 seeds vs 2 seeds is 7-23
                int rand_num = (rand() % 30) + 1; //random number chosen from 1 to 30
                if(rand_num >= 1 && rand_num <= 7){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 6 seed vs a 3 seed
            if(winner1.seed_num == 6 && winner2.seed_num == 3){
                //Probability data is taken from the overall historical record of 6 seeds vs 3 seeds
                //The record of 6 seeds vs 3 seeds is 29-45
                int rand_num = (rand() % 74) + 1; //random number chosen from 1 to 74
                if(rand_num >= 1 && rand_num <= 29){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 6 seed vs a 4 seed
            if(winner1.seed_num == 6 && winner2.seed_num == 4){
                //Probability data is adjusted from the overall historical record of 6 seeds vs 4 seeds
                //The record of 6 seeds vs 4 seeds is 2-2
                int rand_num = (rand() % 50) + 1; //random number chosen from 1 to 50
                if(rand_num >= 1 && rand_num <= 21){ //6 seed has a 42% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 6 seed vs a 5 seed
            if(winner1.seed_num == 6 && winner2.seed_num == 5){
                //Probability data is adjusted from the overall historical record of 6 seeds vs 5 seeds
                //The record of 6 seeds vs 5 seeds is 0-1
                int rand_num = (rand() % 50) + 1; //random number chosen from 1 to 50
                if(rand_num >= 1 && rand_num <= 24){ //6 seed has a 48% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 6 seed vs a 6 seed
            if(winner1.seed_num == 6 && winner2.seed_num == 6){
                //Probability is an even 50/50 since the two are the same seed
                int rand_num = (rand() % 2) + 1; //random number chosen from 1 to 2
                if(rand_num == 1){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 6 seed vs a 7 seed
            if(winner1.seed_num == 6 && winner2.seed_num == 7){
                //Probability data is adapted from the overall historical record of 6 seeds vs 7 seeds
                //The record of 6 seeds vs 7 seeds is 5-2
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 6){ //7 seed has 40% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 6 seed vs a 8 seed
            if(winner1.seed_num == 6 && winner2.seed_num == 8){
                //Probability data is adjusted from the overall historical record of 6 seeds vs 8 seeds
                //The record of 6 seeds vs 8 seeds is 0-1
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 11){ //8 seed has a 45% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 6 seed vs a 9 seed
            if(winner1.seed_num == 6 && winner2.seed_num == 9){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 6){ //9 seed has a 40% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 6 seed vs a 10 seed
            if(winner1.seed_num == 6 && winner2.seed_num == 10){
                //Probability data is taken from the overall historical record of 6 seeds vs 10 seeds
                //The record of 6 seeds vs 10 seeds is 4-2
                int rand_num = (rand() % 6) + 1; //random number chosen from 1 to 6
                if(rand_num >= 1 && rand_num <= 4){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 6 seed vs an 11 seed
            if(winner1.seed_num == 6 && winner2.seed_num == 11){
                //Probability data is taken from the overall historical record of 6 seeds vs 11 seeds in the first round
                //The record of 6 seeds vs 11 seeds is 90-54
                int rand_num = (rand() % 144) + 1; //random number chosen from 1 to 144
                if(rand_num >= 1 && rand_num <= 90){
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 6 seed vs a 12 seed
            if(winner1.seed_num == 6 && winner2.seed_num == 12){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
                if(rand_num >= 1 && rand_num <= 68){ //12 seed has a 32% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 6 seed vs a 13 seed
            if(winner1.seed_num == 6 && winner2.seed_num == 13){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
                if(rand_num >= 1 && rand_num <= 73){ //13 seed has a 27% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 6 seed vs a 14 seed
            if(winner1.seed_num == 6 && winner2.seed_num == 14){
                //Probability data is taken from the overall historical record of 6 seeds vs 14 seeds
                //The record of 6 seeds vs 14 seeds is 14-2
                int rand_num = (rand() % 16) + 1; //random number chosen from 1 to 16
                if(rand_num >= 1 && rand_num <= 14){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 6 seed vs a 15 seed
            if(winner1.seed_num == 6 && winner2.seed_num == 15){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 8){ //15 seed has a 20% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 6 seed vs a 16 seed
            if(winner1.seed_num == 6 && winner2.seed_num == 16){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 8){ //16 seed has a 20% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //*/

        //7 seed cases
        ///*
            //In the case of a 7 seed vs a 1 seed
            if(winner1.seed_num == 7 && winner2.seed_num == 1){
                //Probability data is adjusted from the overall historical record of 7 seeds vs 1 seeds
                //The record of 7 seeds vs 1 seeds is 1-6
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 2){ //7 seed has a 20% chance
                    return winner1;
                } else {
                    return winner2;
                }
            } 
            //In the case of a 7 seed vs a 2 seed
            if(winner1.seed_num == 7 && winner2.seed_num == 2){
                //Probability data is taken from the overall historical record of 7 seeds vs 2 seeds
                //The record of 7 seeds vs 2 seeds is 26-56
                int rand_num = (rand() % 82) + 1; //random number chosen from 1 to 82
                if(rand_num >= 1 && rand_num <= 26){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 7 seed vs a 3 seed
            if(winner1.seed_num == 7 && winner2.seed_num == 2){
                //Probability data is taken from the overall historical record of 7 seeds vs 3 seeds
                //The record of 7 seeds vs 3 seeds is 6-10
                int rand_num = (rand() % 16) + 1; //random number chosen from 1 to 16
                if(rand_num >= 1 && rand_num <= 6){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 7 seed vs a 4 seed
            if(winner1.seed_num == 7 && winner2.seed_num == 4){
                //Probability data is adjusted from the overall historical record of 7 seeds vs 4 seeds
                //The record of 7 seeds vs 4 seeds is 3-2
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 4){ //7 seed has a 40% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 7 seed vs a 5 seed
            if(winner1.seed_num == 7 && winner2.seed_num == 5){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
                if(rand_num >= 1 && rand_num <= 43){ //7 seed has a 43% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 7 seed vs a 6 seed
            if(winner1.seed_num == 7 && winner2.seed_num == 6){
                //Probability data is adapted from the overall historical record of 7 seeds vs 6 seeds
                //The record of 7 seeds vs 6 seeds is 2-5
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 4){ //7 seed has 40% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 7 seed vs a 7 seed
            if(winner1.seed_num == 7 && winner2.seed_num == 7){
                //Probability is an even 50/50 since the two are the same seed
                int rand_num = (rand() % 2) + 1; //random number chosen from 1 to 2
                if(rand_num == 1){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 7 seed vs a 8 seed
            if(winner1.seed_num == 7 && winner2.seed_num == 8){
                //Probability data is adjusted from the overall historical record of 7 seeds vs 8 seeds
                //The record of 7 seeds vs 8 seeds is 1-1
                int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
                if(rand_num >= 1 && rand_num <= 52){ //8 seed has a 48% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 7 seed vs a 9 seed
            if(winner1.seed_num == 7 && winner2.seed_num == 9){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
                if(rand_num >= 1 && rand_num <= 55){ //9 seed has a 45% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 7 seed vs a 10 seed
            if(winner1.seed_num == 7 && winner2.seed_num == 10){
                //Probability data is taken from the overall historical record of 7 seeds vs 10 seeds in the first round
                //The record of 7 seeds vs 10 seeds is 87-57
                int rand_num = (rand() % 144) + 1; //random number chosen from 1 to 144
                if(rand_num >= 1 && rand_num <= 87){
                    return winner1;
                } else{
                    return winner2;
                }
            }
            //In the case of a 7 seed vs an 11 seed
            if(winner1.seed_num == 7 && winner2.seed_num == 11){
                //Probability data is adapted from the overall historical record of 7 seeds vs 11 seeds
                //The record of 7 seeds vs 11 seeds is 0-4
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 6){ //11 seed has 40% chance to win
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 7 seed vs a 12 seed
            if(winner1.seed_num == 7 && winner2.seed_num == 12){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
                if(rand_num >= 1 && rand_num <= 65){ //12 seed has a 35% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 7 seed vs a 13 seed
            if(winner1.seed_num == 7 && winner2.seed_num == 13){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 7){ //13 seed has a 30% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 7 seed vs a 14 seed
            if(winner1.seed_num == 7 && winner2.seed_num == 14){
                //Probability data is adapted from the overall historical record of 7 seeds vs 14 seeds
                //The record of 7 seeds vs 14 seeds is 1-0
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 8){ //14 seed has a 20% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 7 seed vs a 15 seed
            if(winner1.seed_num == 7 && winner2.seed_num == 15){
                //Probability data is adapted from the overall historical record of 7 seeds vs 15 seeds
                //The record of 7 seeds vs 15 seeds is 2-2
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 8){ //15 seed given a 20% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 7 seed vs a 16 seed
            if(winner1.seed_num == 7 && winner2.seed_num == 16){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 4) + 1; //random number chosen from 1 to 4
                if(rand_num >= 1 && rand_num <= 3){ //16 seed has a 25% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //*/

        //8 seed cases
        ///*
            //In the case of an 8 seed vs a 1 seed
            if(winner1.seed_num == 8 && winner2.seed_num == 1){
                //Probability data is taken from the overall historical record of 8 seeds vs 1 seeds
                //The record of 8 seeds vs 1 seeds is 15-60
                int rand_num = (rand() % 75) + 1; //random number chosen from 1 to 75
                if(rand_num >= 1 && rand_num <= 15){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of an 8 seed vs a 2 seed
            if(winner1.seed_num == 8 && winner2.seed_num == 2){
                //Probability data is adjusted from the overall historical record of 8 seeds vs 2 seeds
                //The record of 8 seeds vs 2 seeds is 5-2
                int rand_num = (rand() % 4) + 1; //random number chosen from 1 to 4
                if(rand_num >= 1 && rand_num <= 1){ //8 seed has 25% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 8 seed vs a 3 seed
            if(winner1.seed_num == 8 && winner2.seed_num == 3){
                //Probability data is adjusted from the overall historical record of 8 seeds vs 3 seeds
                //The record of 8 seeds vs 3 seeds is 0-2
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 3){ //8 seed has 30% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of an 8 seed vs a 4 seed
            if(winner1.seed_num == 8 && winner2.seed_num == 4){
                //Probability data is adapted from the overall historical record of 8 seeds vs 4 seeds
                //The record of 8 seeds vs 4 seeds is 5-4
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 4){ //8 seed given a 40% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of an 8 seed vs a 5 seed
            if(winner1.seed_num == 8 && winner2.seed_num == 5){
                //Probability data is adapted from the overall historical record of 8 seeds vs 5 seeds
                //The record of 8 seeds vs 5 seeds is 2-1
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 9){ //8 seed given a 45% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 8 seed vs a 6 seed
            if(winner1.seed_num == 8 && winner2.seed_num == 6){
                //Probability data is adjusted from the overall historical record of 8 seeds vs 6 seeds
                //The record of 8 seeds vs 6 seeds is 1-0
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 9){ //8 seed has a 45% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 8 seed vs a 7 seed
            if(winner1.seed_num == 5 && winner2.seed_num == 7){
                //Probability data is adjusted from the overall historical record of 8 seeds vs 7 seeds
                //The record of 8 seeds vs 7 seeds is 1-1
                int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
                if(rand_num >= 1 && rand_num <= 48){ //8 seed has a 48% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of an 8 seed vs an 8 seed
            if(winner1.seed_num == 8 && winner2.seed_num == 8){
                //Probability is an even 50/50 since the two are the same seed
                int rand_num = (rand() % 2) + 1; //random number chosen from 1 to 2
                if(rand_num == 1){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of an 8 seed vs a 9 seed
            if(winner1.seed_num == 8 && winner2.seed_num == 9){
                //Probability data is taken from the overall historical record of 8 seeds vs 9 seeds in the first round
                //The record of 8 seeds vs 9 seeds is 72-72
                int rand_num = (rand() % 144) + 1; //random number chosen from 1 to 144
                if(rand_num >= 1 && rand_num <= 72){
                    return winner1;
                } else{
                    return winner2;
                }
            }
            //In the case of a 8 seed vs a 10 seed
            if(winner1.seed_num == 8 && winner2.seed_num == 10){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 11){ //10 seed has a 45% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 8 seed vs an 11 seed
            if(winner1.seed_num == 8 && winner2.seed_num == 11){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 11){ //11 seed has a 45% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of an 8 seed vs a 12 seed
            if(winner1.seed_num == 8 && winner2.seed_num == 12){
                //Probability data is adapted from the overall historical record of 8 seeds vs 12 seeds
                //The record of 8 seeds vs 12 seeds is 0-2
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 4){ //12 seed given a 40% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of an 8 seed vs a 13 seed
            if(winner1.seed_num == 8 && winner2.seed_num == 13){
                //Probability data is adapted from the overall historical record of 8 seeds vs 13 seeds
                //The record of 8 seeds vs 13 seeds is 1-0
                int rand_num = (rand() % 50) + 1; //random number chosen from 1 to 50
                if(rand_num >= 1 && rand_num <= 16){ //13 seed given a 32% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 8 seed vs a 14 seed
            if(winner1.seed_num == 8 && winner2.seed_num == 14){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 13){ //14 seed has a 35% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 8 seed vs a 15 seed
            if(winner1.seed_num == 8 && winner2.seed_num == 15){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 7){ //15 seed has a 30% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of an 8 seed vs a 16 seed
            if(winner1.seed_num == 8 && winner2.seed_num == 16){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
                if(rand_num >= 1 && rand_num <= 90){ //estimated 10% chance of 16 seed winning
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //*/

        //9 seed cases
        ///*
            //In the case of a 9 seed vs a 1 seed
            if(winner1.seed_num == 9 && winner2.seed_num == 1){
                //Probability data is taken from the overall historical record of 9 seeds vs 1 seeds
                //The record of 9 seeds vs 1 seeds is 5-66
                int rand_num = (rand() % 71) + 1; //random number chosen from 1 to 71
                if(rand_num >= 1 && rand_num <= 5){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 9 seed vs a 2 seed
            if(winner1.seed_num == 9 && winner2.seed_num == 2){
                //Probability data is adjusted from the overall historical record of 9 seeds vs 2 seeds
                //The record of 9 seeds vs 2 seeds is 1-0
                int rand_num = (rand() % 4) + 1; //random number chosen from 1 to 4
                if(rand_num >= 1 && rand_num <= 1){ //9 seed has 25% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 9 seed vs a 3 seed
            if(winner1.seed_num == 9 && winner2.seed_num == 3){
                //Probability data is adjusted from the overall historical record of 9 seeds vs 3 seeds
                //The record of 9 seeds vs 3 seeds is 0-2
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 3){ //9 seed has 30% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 9 seed vs a 4 seed
            if(winner1.seed_num == 9 && winner2.seed_num == 4){
                //Probability data is adapted from the overall historical record of 9 seeds vs 4 seeds
                //The record of 9 seeds vs 4 seeds is 2-2
                int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
                if(rand_num >= 1 && rand_num <= 37){ //9 seed given a 37% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 9 seed vs a 5 seed
            if(winner1.seed_num == 9 && winner2.seed_num == 5){
                //Probability data is adapted from the overall historical record of 9 seeds vs 5 seeds
                //The record of 9 seeds vs 5 seeds is 1-1
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 4){ //9 seed given a 40% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 9 seed vs a 6 seed
            if(winner1.seed_num == 9 && winner2.seed_num == 6){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 4){ //9 seed has a 40% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 9 seed vs a 7 seed
            if(winner1.seed_num == 9 && winner2.seed_num == 7){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
                if(rand_num >= 1 && rand_num <= 45){ //9 seed has a 45% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 9 seed vs an 8 seed
            if(winner1.seed_num == 9 && winner2.seed_num == 8){
                //Probability data is taken from the overall historical record of 9 seeds vs 8 seeds in the first round
                //The record of 9 seeds vs 8 seeds is 72-72
                int rand_num = (rand() % 144) + 1; //random number chosen from 1 to 144
                if(rand_num >= 1 && rand_num <= 72){
                    return winner1;
                } else{
                    return winner2;
                }
            }
            //In the case of a 9 seed vs a 10 seed
            if(winner1.seed_num == 9 && winner2.seed_num == 10){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 11){ //10 seed has a 45% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 9 seed vs an 11 seed
            if(winner1.seed_num == 9 && winner2.seed_num == 11){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 11){ //11 seed has a 45% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 9 seed vs a 12 seed
            if(winner1.seed_num == 9 && winner2.seed_num == 12){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 9){ //12 seed given a 45% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 9 seed vs a 13 seed
            if(winner1.seed_num == 9 && winner2.seed_num == 13){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 4){ //13 seed given a 40% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 9 seed vs a 14 seed
            if(winner1.seed_num == 9 && winner2.seed_num == 14){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 13){ //14 seed has a 35% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 9 seed vs a 15 seed
            if(winner1.seed_num == 9 && winner2.seed_num == 15){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 7){ //15 seed has a 30% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of 9 seed vs 16 seed
            if(winner1.seed_num == 9 && winner2.seed_num == 16){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
                if(rand_num >= 1 && rand_num <= 90){ //estimated 10% chance of 16 seed winning
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //*/

        //10 seed cases
        ///*
            //In the case of a 10 seed vs a 1 seed
            if(winner1.seed_num == 10 && winner2.seed_num == 1){
                //Probability data is adjusted from the overall historical record of 10 seeds vs 1 seeds
                //The record of 10 seeds vs 1 seeds is 1-5
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 3){ //10 seed has a 15% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 10 seed vs a 2 seed
            if(winner1.seed_num == 10 && winner2.seed_num == 2){
                //Probability data is taken from the overall historical record of 10 seeds vs 2 seeds
                //The record of 10 seeds vs 2 seeds is 18-35
                int rand_num = (rand() % 53) + 1; //random number chosen from 1 to 53
                if(rand_num >= 1 && rand_num <= 18){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 10 seed vs a 3 seed
            if(winner1.seed_num == 10 && winner2.seed_num == 3){
                //Probability data is taken from the overall historical record of 10 seeds vs 3 seeds
                //The record of 10 seeds vs 3 seeds is 4-10
                int rand_num = (rand() % 4) + 1; //random number chosen from 1 to 14
                if(rand_num >= 1 && rand_num <= 10){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 10 seed vs a 4 seed
            if(winner1.seed_num == 10 && winner2.seed_num == 4){
                //Probability data is adjusted from the overall historical record of 10 seeds vs 4 seeds
                //The record of 2 seeds vs 4 seeds is 0-2
                int rand_num = (rand() % 50) + 1; //random number chosen from 1 to 50
                if(rand_num >= 1 && rand_num <= 16){ //10 seed has a 32% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 10 seed vs a 5 seed
            if(winner1.seed_num == 10 && winner2.seed_num == 5){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 7){ //10 seed has a 35% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 10 seed vs a 6 seed
            if(winner1.seed_num == 10 && winner2.seed_num == 6){
                //Probability data is taken from the overall historical record of 10 seeds vs 6 seeds
                //The record of 10 seeds vs 6 seeds is 2-4
                int rand_num = (rand() % 6) + 1; //random number chosen from 1 to 6
                if(rand_num >= 1 && rand_num <= 2){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 10 seed vs a 7 seed
            if(winner1.seed_num == 10 && winner2.seed_num == 7){
                //Probability data is taken from the overall historical record of 7 seeds vs 10 seeds in the first round
                //The record of 7 seeds vs 10 seeds is 87-57
                int rand_num = (rand() % 144) + 1; //random number chosen from 1 to 144
                if(rand_num >= 1 && rand_num <= 87){
                    return winner1;
                } else{
                    return winner2;
                }
            }
            //In the case of an 10 seed vs a 11 seed
            if(winner1.seed_num == 10 && winner2.seed_num == 11){
                //Probability data is adapted from the overall historical record of 10 seeds vs 11 seeds
                //The record of 10 seeds vs 11 seeds is 1-2
                int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
                if(rand_num >= 1 && rand_num <= 52){ //11 seed has 48% chance to win
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 10 seed vs a 12 seed
            if(winner1.seed_num == 10 && winner2.seed_num == 12){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 6){ //12 seed has a 40% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 10 seed vs a 13 seed
            if(winner1.seed_num == 10 && winner2.seed_num == 13){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 13){ //13 seed has a 35% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 10 seed vs a 14 seed
            if(winner1.seed_num == 10 && winner2.seed_num == 14){
                //Probability data is adapted from the overall historical record of 10 seeds vs 14 seeds
                //The record of 10 seeds vs 14 seeds is 1-0
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 7){ //14 seed has a 30% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 10 seed vs a 15 seed
            if(winner1.seed_num == 10 && winner2.seed_num == 15){
                //Probability data is adapted from the overall historical record of 10 seeds vs 15 seeds
                //The record of 10 seeds vs 15 seeds is 5-0
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 8){ //15 seed given a 20% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 10 seed vs a 16 seed
            if(winner1.seed_num == 10 && winner2.seed_num == 16){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
                if(rand_num >= 1 && rand_num <= 68){ //16 seed has a 32% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //*/

        //11 seed cases
        ///*
            //In the case of a 11 seed vs an 1 seed
            if(winner1.seed_num == 1 && winner2.seed_num == 11){
                //Probability data is adjusted from the overall historical record of 11 seeds vs 1 seeds
                //The record of 11 seeds vs 1 seeds is 4-5
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 17){ //11 seed has a 15% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of an 11 seed vs a 2 seed
            if(winner1.seed_num == 11 && winner2.seed_num == 2){
                //Probability data is taken from the overall historical record of 11 seeds vs 2 seeds
                //The record of 11 seeds vs 2 seeds is 3-15
                int rand_num = (rand() % 18) + 1; //random number chosen from 1 to 18
                if(rand_num >= 1 && rand_num <= 3){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 11 seed vs a 3 seed
            if(winner1.seed_num == 11 && winner2.seed_num == 3){
                //Probability data is taken from the overall historical record of 11 seeds vs 3 seeds
                //The record of 11 seeds vs 3 seeds is 18-32
                int rand_num = (rand() % 50) + 1; //random number chosen from 1 to 50
                if(rand_num >= 1 && rand_num <= 18){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 11 seed vs an 4 seed
            if(winner1.seed_num == 11 && winner2.seed_num == 4){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 3){ //11 seed has a 30% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 11 seed vs an 5 seed
            if(winner1.seed_num == 11 && winner2.seed_num == 5){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 7){ //11 seed has a 35% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 11 seed vs an 6 seed
            if(winner1.seed_num == 11 && winner2.seed_num == 6){
                //Probability data is taken from the overall historical record of 11 seeds vs 6 seeds in the first round
                //The record of 11 seeds vs 6 seeds is 54-90
                int rand_num = (rand() % 144) + 1; //random number chosen from 1 to 144
                if(rand_num >= 1 && rand_num <= 54){
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of an 11 seed vs a 7 seed
            if(winner1.seed_num == 11 && winner2.seed_num == 7){
                //Probability data is adapted from the overall historical record of 11 seeds vs 7 seeds
                //The record of 11 seeds vs 7 seeds is 4-0
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 4){ //11 seed has 40% chance to win
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 11 seed vs an 8 seed
            if(winner1.seed_num == 11 && winner2.seed_num == 8){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 9){ //11 seed has a 45% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 11 seed vs an 9 seed
            if(winner1.seed_num == 11 && winner2.seed_num == 9){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 9){ //11 seed has a 45% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of an 11 seed vs a 10 seed
            if(winner1.seed_num == 11 && winner2.seed_num == 10){
                //Probability data is adapted from the overall historical record of 11 seeds vs 10 seeds
                //The record of 11 seeds vs 10 seeds is 2-1
                int rand_num = (rand() % 100) + 1; //random number chosen from 1 to 100
                if(rand_num >= 1 && rand_num <= 48){ //11 seed has 48% chance to win
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 11 seed vs an 12 seed
            if(winner1.seed_num == 11 && winner2.seed_num == 12){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 11){ //12 seed has a 45% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 11 seed vs an 13 seed
            if(winner1.seed_num == 11 && winner2.seed_num == 13){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 6){ //13 seed has a 40% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 11 seed vs a 14 seed
            if(winner1.seed_num == 11 && winner2.seed_num == 14){
                //Probability data is adapted from the overall historical record of 11 seeds vs 14 seeds
                //The record of 11 seeds vs 14 seeds is 5-0
                int rand_num = (rand() % 10) + 1; //random number chosen from 1 to 10
                if(rand_num >= 1 && rand_num <= 8){ 
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of an 11 seed vs a 15 seed
            if(winner1.seed_num == 11 && winner2.seed_num == 15){
                //Insufficient historical data; probability data is an estimation
                int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
                if(rand_num >= 1 && rand_num <= 13){ //15 seed has a 35% chance
                    return winner1;
                } else {
                    return winner2;
                }
            }
            //In the case of a 11 seed vs as 16 seed
        if(winner1.seed_num == 11 && winner2.seed_num == 16){
            //Insufficient historical data; probability data is an estimation
            int rand_num = (rand() % 20) + 1; //random number chosen from 1 to 20
            if(rand_num >= 1 && rand_num <= 13){ //16 seed has a 35% chance
                return winner1;
            } else {
                return winner2;
            }
        }
        

            

        else{
            return Team();
        }
    }

