#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

struct Transition
{
    string current_state;
    string read_symbol;
    string next_state;
    string write_symbol;
    string direction;
};

vector<Transition> loadTransitions()
{
    return {
        {"q0", "a", "q0", "a", "R"},
        {"q0", "_", "q1", "#", "L"},
        {"q1", "0", "q4", "7", "L"},
        {"q1", "a", "q2", "a-1", "R"},
        {"q2", "#", "q2", "#", "R"},
        {"q2", "_", "q3", "1", "L"},
        {"q2", "a", "q9", "a", "R"},
        {"q3", "#", "q1", "#", "L"},
        {"q3", "a", "q3", "a", "L"},
        {"q4", "0", "q4", "7", "L"},
        {"q4", "a", "q5", "a-1", "R"},
        {"q4", "_", "qf", "_", "R"},
        {"q5", "a", "q5", "a", "R"},
        {"q5", "#", "q2", "#", "R"},
        {"q6", "2", "q6", "0", "L"},
        {"q6", "a", "q3", "a+1", "L"},
        {"q6", "#", "q7", "#", "R"},
        {"q7", "0", "q8", "1", "R"},
        {"q8", "0", "q8", "0", "R"},
        {"q8", "_", "q3", "0", "L"},
        {"q9", "a", "q9", "a", "R"},
        {"q9", "_", "q10", "_", "L"},
        {"q10", "2", "q6", "0", "L"},
        {"q10", "a", "q3", "a+1", "L"}};
}
