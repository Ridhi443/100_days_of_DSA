// Problem Statement: Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.
#include <stdio.h>
#include <string.h>

#define MAX 100

struct Candidate {
    char name[100];
    int votes;
};

int findCandidate(struct Candidate candidates[], int count, char* name) {
    for(int i = 0; i < count; i++) {
        if(strcmp(candidates[i].name, name) == 0) {
            return i;
        }
    }
    return -1;
}

char* findWinner(char votes[][100], int n) {
    struct Candidate candidates[MAX];
    int count = 0;
    for(int i = 0; i < n; i++) {
        int idx = findCandidate(candidates, count, votes[i]);
        if(idx != -1) {
            candidates[idx].votes++;
        } else {
            strcpy(candidates[count].name, votes[i]);
            candidates[count].votes = 1;
            count++;
        }
    }
    int maxVotes = 0;
    char* winner = NULL;
    for(int i = 0; i < count; i++) {
        if(candidates[i].votes > maxVotes || (candidates[i].votes == maxVotes && (winner == NULL || strcmp(candidates[i].name, winner) < 0))) {
            maxVotes = candidates[i].votes;
            winner = candidates[i].name;
        }
    }
    return winner;
}

int main() {
    char votes[][100] = {"Alice", "Bob", "Alice", "Charlie", "Bob", "Alice"};
    int n = 6;
    char* winner = findWinner(votes, n);
    printf("Winner: %s\n", winner);
    return 0;
}
