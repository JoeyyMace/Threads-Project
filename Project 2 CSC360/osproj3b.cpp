#include <thread>
#include <iostream>
#include <vector>
using namespace std;

#define MAX_THREADS 512

void fib_seq(vector<int>& fib , int seq_len) {
    for (int i = 2; i < seq_len; i++) {
        fib.push_back(fib[i - 1] + fib[i - 2]);
    }
}

void print_fib(vector<int>& fib) {
    for (int i = 0; i < fib.size(); i++) {
        cout << fib[i] << " ";
    }
    cout << endl;
}

void generate_fibonacci(int num) {
    vector<int> fib;
    
    // Special cases for 1 or 2 Fibonacci numbers
    if (num == 1) {
        cout << "0" << endl;
        return;
    } else if (num == 2) {
        cout << "0 1" << endl;
        return;
    } else {
        // Initialize the first two Fibonacci numbers
        fib.push_back(0);
        fib.push_back(1);

        // Generate Fibonacci sequence in a separate thread
        fib_seq(fib, num);

        // Print the Fibonacci sequence
        print_fib(fib);
    }
}

int main() {
    int num;

    // Ask the user how many Fibonacci numbers to generate
    cout << "How many numbers of the Fibonacci sequence would you like to generate: ";
    cin >> num;

    //Create main thread
    thread fib_thread(generate_fibonacci, num);

    //wait for thread to complete before continuing
    fib_thread.join();

    return 0;
}