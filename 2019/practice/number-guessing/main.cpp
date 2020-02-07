#include <iostream>
#include <cassert>

using namespace std;

struct Problem {
    int lower_bond;
    int upper_bond;
    int max_num_guesses;
};

bool solve(Problem problem) {
    int num_guesses = 0;

    int head = problem.lower_bond+1;
    int tail = problem.upper_bond;
    int solved = false;

    string answer;

    for(int num_guess=0; num_guess<problem.max_num_guesses; ++num_guess) {
        ++num_guesses;
        int guess = (head+tail)/2; 

        assert(problem.lower_bond<guess);
        assert(guess<=problem.upper_bond);

        cout << guess << endl;
        cin >> answer;
        if (answer == "CORRECT") {
            solved = true;
            break;
        }
        else if (answer == "TOO_SMALL") {
            head = guess+1;
        }
        else if (answer == "TOO_BIG") {
            tail = guess-1;
        }
        else if (answer == "WRONG_ANSWER") {
            cout << "error" << endl;
            exit(1);
        }
    }

    return solved;
}

int main() {
    int test_cases;
    cin >> test_cases;

    for(int test_case=0; test_case<test_cases; ++test_case) {
        Problem problem;
        cin >> problem.lower_bond >> problem.upper_bond;
        cin >> problem.max_num_guesses;
        
        assert(solve(problem));
    }

    return 0;       
}
