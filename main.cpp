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

#include <vector>
#include <string>
using namespace std;

vector<Transition> loadTransitions(int x, int y)
{
    // Convert x-1 and y+1 to strings once
    string xMinusOne = to_string(x - 1);
    string yPlusOne = to_string(y + 1);

    vector<Transition> transitions = {
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

    for (auto &t : transitions)
    {
        if (t.read_symbol == "7")
            t.read_symbol = xMinusOne;
        if (t.write_symbol == "7")
            t.write_symbol = xMinusOne;
        if (t.read_symbol == "2")
            t.read_symbol = yPlusOne;
        if (t.write_symbol == "2")
            t.write_symbol = yPlusOne;
    }

    return transitions;
}

bool applyTransition(string &tape, int &head, string &state, const vector<Transition> &transitions)
{
    for (const auto &t : transitions)
    {
        char current_symbol = tape[head];

        bool match = (state == t.current_state) &&
                     (t.read_symbol == string(1, current_symbol) || (t.read_symbol == "a" && isdigit(current_symbol)));

        if (match)
        {
            state = t.next_state;

            // Write symbol
            if (t.write_symbol == "a-1")
                tape[head] = current_symbol - 1;
            else if (t.write_symbol == "a+1")
                tape[head] = current_symbol + 1;
            else
                tape[head] = t.write_symbol[0];

            // Move head
            head += (t.direction == "R") ? 1 : -1;

            return true;
        }
    }
    return false;
}

string runTuringMachine(string input, const vector<Transition> &transitions)
{
    string tape = "_" + input + "_____________________________________";
    int head = 1;
    string state = "q0";
    const string end_state = "qf";

    while (state != end_state)
    {
        if (!applyTransition(tape, head, state, transitions))
            break; // Stop if no transition matches
    }

    return tape;
}

string extractOutput(const string &tape)
{
    string output;
    bool started = false;
    for (char ch : tape)
    {
        if (started && ch == '_')
            break;
        if (started)
            output += ch;
        if (ch == '#')
            started = true;
    }
    return output;
}

int main()
{
    string input;
    cout << "Please enter a number: ";
    cin >> input;

    auto transitions = loadTransitions();
    string final_tape = runTuringMachine(input, transitions);
    string output = extractOutput(final_tape);

    cout << "Output: " << output << endl;
    return 0;
}
