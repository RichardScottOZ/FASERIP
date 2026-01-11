#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

// Function to validate numeric input
int getValidInput(int maxValue) {
    string input;
    int value;
    
    while (true) {
        getline(cin, input);
        
        // Check if input is numeric
        bool isNumeric = true;
        if (input.empty()) {
            isNumeric = false;
        } else {
            for (char c : input) {
                if (!isdigit(c)) {
                    isNumeric = false;
                    break;
                }
            }
        }
        
        if (isNumeric) {
            value = stoi(input);
            if (value >= 0 && value <= maxValue) {
                return value;
            }
        }
        
        cout << "Invalid input. Please try again." << endl;
    }
}

int main() {
    // Seed random number generator
    srand(time(0));
    
    // Script rank and effects to STDIN
    vector<string> effects = {
        "None", "Blunt Attack", "Edged Attack", "Shooting Attack",
        "Throwing Edged", "Throwing Blunt", "Energy", "Force",
        "Grappling", "Grabbing", "Escaping", "Charging", "Dodging",
        "Evading", "Blocking", "Catching", "Stun?", "Slam?", "Kill?"
    };
    
    vector<string> rank = {
        "", "SH0", "FB", "PR", "TY", "GD", "EX", "RM", "IN", "AM", "MN",
        "UN", "SHX", "SHY", "SHZ", "CL1000", "CL3000", "CL5000", "Beyond"
    };
    
    vector<string> whiteEffects = {
        "WHITE", "MISS", "MISS", "MISS", "MISS", "MISS", "MISS",
        "MISS", "MISS", "MISS", "MISS", "MISS", "NONE", "AUTOHIT",
        "-6 CS", "AUTOHIT", "1-10", "GRAND SLAM", "ENDURANCE LOSS"
    };
    
    vector<string> greenEffects = {
        "GREEN", "HIT", "HIT", "HIT", "HIT", "HIT", "HIT", "HIT",
        "MISS", "TAKE", "MISS", "HIT", "-2 CS", "EVASION", "-4 CS",
        "MISS", "1", "1 AREA", "E/S (EDGED/SHOOTING)"
    };
    
    vector<string> yellowEffects = {
        "YELLOW", "SLAM", "STUN", "BULLSEYE", "STUN", "HIT",
        "BULLSEYE", "BULLSEYE", "Partial", "GRAB", "ESCAPE", "SLAM",
        "-4 CS", "+1 CS", "-2 CS", "DAMAGE", "NO", "STAGGER", "NO"
    };
    
    vector<string> redEffects = {
        "RED", "STUN", "KILL", "KILL", "KILL", "STUN", "KILL", "STUN",
        "HOLD", "BREAK", "REVERSE", "STUN", "-6 CS", "+2 CS", "+1 CS",
        "CATCH", "NO", "NO", "NO"
    };
    
    // Advanced Universal Table (rank, white, green, yellow, red)
    struct TableEntry {
        string rankName;
        int white;
        int green;
        int yellow;
        int red;
    };
    
    vector<TableEntry> universalTable = {
        {"SH0", -1, 66, 95, 100},
        {"FB", -1, 61, 91, 100},
        {"PR", -1, 56, 86, 100},
        {"TY", -1, 51, 81, 98},
        {"GD", -1, 46, 76, 98},
        {"EX", -1, 41, 71, 95},
        {"RM", -1, 36, 66, 95},
        {"IN", -1, 31, 61, 91},
        {"AM", -1, 26, 56, 91},
        {"MN", -1, 21, 51, 86},
        {"UN", -1, 16, 46, 86},
        {"SHX", -1, 11, 41, 81},
        {"SHY", -1, 7, 41, 81},
        {"SHZ", -1, 4, 36, 76},
        {"CL1000", -1, 2, 36, 76},
        {"CL3000", -1, 2, 31, 71},
        {"CL5000", -1, 2, 26, 66},
        {"Beyond", -1, 2, 21, 61}
    };
    
    // Generate d100 roll
    int d100 = (rand() % 100) + 1;
    
    cout << endl;
    cout << "CHOOSE EFFECT" << endl;
    
    int countEffect = 0;
    for (const string& effect : effects) {
        cout << countEffect << ": " << effect << "  ";
        countEffect++;
    }
    cout << endl;
    
    int chosenEffect = getValidInput(18);
    
    cout << "Effect = " << effects[chosenEffect] << endl << endl;
    
    cout << "CHOOSE RANK" << endl;
    int countRank = 0;
    for (const string& r : rank) {
        cout << countRank << ": " << r << "  ";
        countRank++;
    }
    cout << endl;
    
    int chosenRank = getValidInput(18);
    
    cout << "Rank = " << rank[chosenRank] << " - " << effects[chosenEffect] << " - ";
    
    string d100Result = "WHITE";
    string colorResult = whiteEffects[chosenEffect];
    
    for (const TableEntry& column : universalTable) {
        if (column.rankName == rank[chosenRank]) {
            // found rank column
            if (d100 >= column.green) {
                d100Result = "GREEN";
                colorResult = greenEffects[chosenEffect];
            }
            if (d100 >= column.yellow) {
                d100Result = "YELLOW";
                colorResult = yellowEffects[chosenEffect];
            }
            if (d100 >= column.red) {
                d100Result = "RED";
                colorResult = redEffects[chosenEffect];
            }
            cout << "Roll : " << d100 << " - " << d100Result << " - " << colorResult << endl;
            break;
        }
    }
    
    return 0;
}
