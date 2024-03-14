/*
Title: Assignment 4
Description: Alice in wonderland game
Date: March 1, 2024
Author: Hannah Rydlo
Version: 1.0
Copyright: 2024 Hannah Rydlo
*/

/*
DOCUMENTATION
Program Purpose: 
    
    Compile (compiled on bash): g++ -std=c++11 -o AliceInWonderland AliceInWonderland.cpp
    Execution (compiled on bash): ./AliceInWonderland 
Classes: none
Variables:

*/

/*
TEST PLAN
the test plan is simply; does the output match the required format?

Discussion:

*/

#include <iostream>
#include <ctype.h>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;


class Location {
        public:
        int number;
        string locationTitle;
        string locationMessage;
        
        vector<string> exits;
        
        Location(int n, string title, string m, vector<string> e){
            locationTitle = title;
            number = n;
            locationMessage = m;
            exits = e;
        }

        bool present(string item){
            /* check if an item in present in the room the user is in*/

        }

    };

class Inventory {
        public:
        vector<string> inventory;

        void add(string item){

        }

        void drop(string item){

        }

        void check_inventory(){
            
            if (inventory.size() == 0){
                cout << "You don't have anything in your inventory.\n";
            }

            if (inventory.size() >= 8){
                "You don't have any more space in your inventory.\n";
            }

            for(int i=0; i < inventory.size(); i++){
                cout << inventory.at(i) << ' ';
            }
        }

    };

class Control {
        
        public:
        string action;
        
        Control(){
            string action = "";
        }

        void get_action(){
            cin >> this->action;
            cin.ignore();
        }

    };
     
class Items {

    };

class Characters {

    };

class Actions {
        public:
        unordered_map<string, int> valid_actions;
        string action;

        Actions(){
            string action = "";
            valid_actions["n"] = 1;
            valid_actions["north"] = 2;
            valid_actions["s"] = 3;
            valid_actions["south"] = 4;
            valid_actions["w"] = 5;
            valid_actions["west"] = 6;
            valid_actions["e"] = 7;
            valid_actions["east"] = 8;
        }

        bool check_valid(){
            bool valid = false;
            
            auto f = find(valid_actions.begin(), valid_actions.end(), action);
            if (f == valid_actions.end()){
                valid = false;
            }
            else{
                valid = true;
            }
            return valid;

        }

    };
    


class Game {
    public:
        bool game_running;
    
    void Entry_message(){
        cout << "\n----------------- Welcome to the Alice in Wonderland Game! -----------------\n" << endl;
        cout << "Your goal is to find out how to embrace your true self." << "\nYou will learn how to do this as you are challenged throughout your journey" << endl;
        cout << "\n\n" << endl;
 
    }

    void play(){
        game_running = true;
        int score = 0;
        int location = 0;
        Control controller;
        Entry_message();
        vector <string> exits_0 = {"north", "west"};
        vector <string> exits_1 = {"north", "west", "south", "east"};
        Location Garden_0(0, "Garden", "You are in a beautiful garden. To your west, a group of fancy looking people seem to be waiting for you.\nSuddenly, out of the corner of your eye, you see a white rabbit in some sort of suit dart off to your north.\n", exits_0 );
        Location Garden_1(1, "Garden", "You are in a beautiful garden. The shrubs are higher here and the noise from the party has grown quieter. You look around and notice the rabbit dissapear to the east.", exits_1);
        vector<Location> locations;
        locations.push_back(Garden_0);
        locations.push_back(Garden_1);
        while (game_running){
            cout << locations[location].locationMessage << endl;
            controller.get_action();
            Actions action1;
            action1.action = controller.action;
            while (action1.check_valid() == false){
                cout << "invalid action, please try again" << endl;
                controller.get_action();
                action1.action = controller.action;
            }


        }
    }

};

int main(void){
    Game adventure;
    adventure.play();
    

}