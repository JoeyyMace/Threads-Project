#include <thread>
#include <iostream>
#include <string>
#include <vector>
#include <sched.h>
#include <mutex>
using namespace std;

bool is_vow(const string& word) {
    // Check if the first character is a vowel (lowercase)
    char first_char = tolower(word[0]);
    return (first_char == 'a' || first_char == 'e' || first_char == 'i' || first_char == 'o' || first_char == 'u');
}

mutex mtx; // Variable to sync threads
int ind = 0; // Shared index so that the threads can keep track of the current word together

void print_vow(vector<string>& yoshi) {
    while (ind < yoshi.size()) {
        lock_guard<mutex> lock(mtx); // Mutex locks data to prevent simultaneous access
        if (is_vow(yoshi[ind])) {
            cout << "vow: " << yoshi[ind] << endl;
            ind++;  // Move to the next word
        }
        sched_yield(); // Yield to other thread to allow it to proceed
    }
}

void print_cons(vector<string>& yoshi) {
    while (ind < yoshi.size()) {
        lock_guard<mutex> lock(mtx); // Mutex locks data to prevent simultaneous access
        if (!is_vow(yoshi[ind])) {
            cout << "cons: " << yoshi[ind] << endl;
            ind++;  // Move to the next word
        }
        sched_yield(); // Yield to other thread to allow it to proceed
    }
}

int main() {
    string phrase;
    vector<string> yoshi;

    // Ask the user for a phrase
    cout << "Prompt% ";
    getline(cin, phrase);

    // Split the phrase into words
    string word;
    for (char c : phrase) {
        if (c == ' ') {
            if (!word.empty()) {
                yoshi.push_back(word);
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        yoshi.push_back(word);  // Add the last word
    }

    // Create and run threads
    thread t1(print_vow, ref(yoshi));  // Thread to print vowels
    thread t2(print_cons, ref(yoshi)); // Thread to print consonants

    t1.join();
    t2.join();

    cout << endl;
}
