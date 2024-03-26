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
#include <algorithm>
#include <iterator>
#include <unordered_map>

using namespace std;

class Actions {
        public:
        unordered_map<string, int> valid_actions;
        string action;
        int direction = 0;

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
            valid_actions["down"] = 9;
            valid_actions["up"] = 10;

        }

        bool check_valid(){
            bool valid = false;
            
            if (valid_actions.find(action) == valid_actions.end()){
                return valid;
            }
            return valid = true;
        }

        int find_direction(){
    
            if (valid_actions[action] > 8){
                return 0;
            }
            int action_no = valid_actions[action];
            switch (action_no){
                case 1:
                direction= 100;
                break;
                case 2:
                direction= 100;
                break;
                case 3:
                direction= 300;
                break;
                case 4:
                direction= 300;
                break;
                case 5:
                direction= 400;
                break;
                case 6:
                direction= 400;
                break;
                case 7:
                direction= 200;
                break;
                case 8:
                direction= 200;
                break;
                case 9:
                direction= 500;
                break;
                case 10:
                direction= 600;
                break;
                default:
                direction = 0;
            }

        }

    };
class Location {
        public:
        int number;
        string locationTitle;
        string locationMessage;
        
        unordered_map<int, int> exits;
        
        
        Location(int n, string title, string m, unordered_map<int,int> e){
            locationTitle = title;
            number = n;
            locationMessage = m;
            exits = e;
        }
        
        void add_exits(unordered_map<int, int> e){
            exits = e;
        }

        bool present(string item){
            /* check if an item in present in the room the user is in*/

        }

        int valid_direction(Actions a){
            return this->exits[a.direction];
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


    


class Game {
    public:
        bool game_running;
    
    void Entry_message(){
        cout << "\n----------------- Welcome to the Alice in Wonderland Game! -----------------\n" << endl;
        cout << "Your goal is to find out how to embrace your true self." << "\nYou will learn how to do this as you are challenged throughout your journey" << endl;
        cout << "\n\n" << endl;
 
    }


    vector<Location> Create_locations(string file){
        vector<Location> locations;
        ifstream myfile; 
        myfile.open(file);
        string line;
        
        if (!myfile) {                        
            cout<<"File doesnt exist.";          
        }

        while (getline(myfile, line))
        {
            stringstream ss(line);
            int number;
            string title, message;
            int key1, value1, key2, value2, key3, value3, key4, value4, key5, value5, key6, value6;

            ss >> number;
            ss >> __quoted(title);
            ss >> __quoted(message);
            ss >> key1;
            ss >> value1;
            ss >> key2;
            ss >> value2;
            ss >> key3;
            ss >> value3;
            ss >> key4;
            ss >> value4;
            ss >> key5;
            ss >> value5;
            ss >> key6;
            ss >> value6;
            
            unordered_map<int,int> exits;
            exits[key1] = value1;
            exits[key2] = value2;
            exits[key3] = value3;
            exits[key4] = value4;
            exits[key5] = value5;
            exits[key6] = value6;
            Location location(number, title, message,exits);
        
            locations.push_back(location);
        }
        return locations;
    }

    void play(){
        game_running = true;
        int score = 0;
        int location = 0;
        Control controller;
        Entry_message();
        vector<Location> locations;
        
        locations = Create_locations("Locations.txt");

        while (game_running){
            cout << locations[location].locationMessage << endl;
            controller.get_action();
            Actions action1;
            action1.action = controller.action;
            while (action1.check_valid() == false){
                cout << "invalid action, please try again" << endl;
                controller.get_action();
                action1.action = controller.action;
                action1.check_valid();
            }
            int move;
            action1.find_direction();
            move = locations[location].valid_direction(action1);
            location += move;
            
        }
    }

};

int main(void){
    Game adventure;
    adventure.play();
    

}
