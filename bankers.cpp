
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

/*
    Banker's Algorithm Implementation
    - Reads allocation, max, and available resources from an input file
    - Calculates need matrix
    - Determines if the system is in a safe state
    - Prints safe sequence if one exists
*/

const int MAX_P = 10;
const int MAX_R = 10;

int P, R;
int allocation[MAX_P][MAX_R];
int maxNeed[MAX_P][MAX_R];
int need[MAX_P][MAX_R];
int available[MAX_R];

void calculateNeed() {
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            need[i][j] = maxNeed[i][j] - allocation[i][j];
        }
    }
}

bool canAllocate(int process, int work[]) {
    for (int i = 0; i < R; i++) {
        if (need[process][i] > work[i])
            return false;
    }
    return true;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cout << "Usage: ./bankers inputfile.txt" << endl;
        return 1;
    }

    ifstream inputFile(argv[1]);
    if (!inputFile) {
        cout << "Error opening input file." << endl;
        return 1;
    }

    inputFile >> P >> R;
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            inputFile >> allocation[i][j];
        }
    }
    for (int i = 0; i < P; i++) {
        for (int j = 0; j < R; j++) {
            inputFile >> maxNeed[i][j];
        }
    }
    for (int i = 0; i < R; i++) {
        inputFile >> available[i];
    }
    inputFile.close();

    calculateNeed();

    int work[MAX_R];
    bool finish[MAX_P] = {false};
    vector<int> safeSequence;

    for (int i = 0; i < R; i++) {
        work[i] = available[i];
    }

    bool foundProcess;
    for (int count = 0; count < P; count++) {
        foundProcess = false;
        for (int p = 0; p < P; p++) {
            if (!finish[p] && canAllocate(p, work)) {
                for (int k = 0; k < R; k++) {
                    work[k] += allocation[p][k];
                }
                safeSequence.push_back(p);
                finish[p] = true;
                foundProcess = true;
                break;
            }
        }
        if (!foundProcess) {
            break;
        }
    }

    bool isSafe = true;
    for (int i = 0; i < P; i++) {
        if (!finish[i]) {
            isSafe = false;
            break;
        }
    }

    if (isSafe) {
        cout << "System is in a safe state." << endl;
        cout << "Safe sequence: ";
        for (size_t i = 0; i < safeSequence.size(); i++) {
            cout << "P" << safeSequence[i];
            if (i != safeSequence.size() - 1)
                cout << " -> ";
        }
        cout << endl;
    } else {
        cout << "System is NOT in a safe state." << endl;
    }

    return 0;
}
