#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
using namespace std;



enum class Choice { rock, paper, scissors };



Choice player_choice;     // Holds user's move
Choice computer_choice;   // Holds computer move 

int player_wins = 0;      // Track player victories.
int computer_wins = 0;    // Track computer wins.

string words[3] = { "rock", "paper", "scissors" };

Choice get_computer_choice();
void decide_winner();
string get_msg(Choice winner);
int rand0toN1(int n);

int main(int argc, char *argv[])
{
	srand(time(NULL));  // Set seed for randomization.
	string input_str;
	int c;
	while (true) {
		cout << "Enter Rock, Paper, Scissors, or Exit: ";
		getline(cin, input_str);
		if (input_str.size() < 1) {
			cout << "Invalid input." << endl;
			continue;
		}
		c = input_str[0];
		if (c == 'R' || c == 'r')
			player_choice = Choice::rock;
		else if (c == 'P' || c == 'p')
			player_choice = Choice::paper;
		else if (c == 'S' || c == 's')
			player_choice = Choice::scissors;
		else if (c == 'E' || c == 'e')
			break;
		else {
			cout << "Invalid input." << endl;
			continue;
		}
		computer_choice = get_computer_choice();
		int p = (int)player_choice;
		int c = (int)computer_choice;
		cout << "You chose " << words[p];
		cout << "," << endl;
		cout << "I chose " << words[c];
		cout << "," << endl;
		decide_winner();
	}
	cout << "player wins:   " << player_wins << endl;
	cout << "computer wins: " << computer_wins << endl;
	
	return EXIT_SUCCESS;
}

Choice get_computer_choice() {
	int n = rand0toN1(3);
	if (n == 0) return Choice::rock;
	if (n == 1) return Choice::paper;
	return  Choice::scissors;
}

void decide_winner() {
	if (player_choice == computer_choice) {
		cout << "Result is a tie." << endl << endl;
		return;
	}
	int p = (int)player_choice;
	int c = (int)computer_choice;
	if (p - c == 1 || p - c == -2) {
		cout << get_msg(player_choice);
		cout << "YOU WIN!" << endl;
		player_wins+1;
	}
	else {
		cout << get_msg(computer_choice);
		cout << "I WIN!" << endl;
		computer_wins+1;
		cout << "computer_wins" << 
	}
	cout << endl;
}

string get_msg(Choice winner) {
	if (winner == Choice::rock)
		return string("Rock smashes scissors...  ");
	else if (winner == Choice::paper)
		return string("Paper covers rock...  ");
	else
		return string("Scissors cuts paper...  ");
}

int rand0toN1(int n) {
	return rand() % n;
}p
