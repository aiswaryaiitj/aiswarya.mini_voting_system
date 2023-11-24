#include <stdio.h>
#include <string.h>

#define MAX_CANDIDATES 20

// Structure to represent a candidate
struct Candidate {
    char name[50];
    int votes;
};

struct Candidate candidates[MAX_CANDIDATES];
int candidateCount;

//Function to get candidates list and store it
void initializeCandidates(struct Candidate candidates[]) {
    printf("Enter the no of candidates are participating: ");
    scanf("%d", &candidateCount);
    if(candidateCount > MAX_CANDIDATES) {
        printf("Number of candidates count should not be more than %d\n", MAX_CANDIDATES);
    } else {
        for (int i = 0; i < candidateCount; i++) {
            printf("Enter the name of Candidate %d: ", i + 1);
            scanf("%s", candidates[i].name);
            candidates[i].votes = 0;
        }   
    }
}

//Function to show all candidates
void showAllCandidates(struct Candidate candidates[]) {
    printf("\n----- Candidates -----\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%d. %s\n", i + 1, candidates[i].name);
    }
    printf("-----------------------\n");
}

//Function to vote
void utilizeVote(struct Candidate candidates[]) {
    int choice;
    showAllCandidates(candidates);
    printf("Enter the number of the candidate you want to vote for: ");
    scanf("%d", &choice);

    // Validate the choice
    if (choice >= 1 && choice <= candidateCount) {
        candidates[choice - 1].votes++;
        printf("Vote for %s recorded!\n", candidates[choice - 1].name);
    } else {
        printf("Invalid choice!\n");
    }
}

//function to show results
void showResults(struct Candidate candidates[]) {
    printf("\n----- Voting Results -----\n");
    for (int i = 0; i < candidateCount; i++) {
        printf("%s: %d votes\n", candidates[i].name, candidates[i].votes);
    }
    printf("---------------------------\n");
}

// function to announce winner 
void announceWinner(struct Candidate candidates[]) 
{ 
    int maxVotes = 0; 
    int winnerIndex = -1; 
    int winnerFrequency = 0; 
    for (int i = 0; i < candidateCount; i++) { 
        if (candidates[i].votes > maxVotes) { 
            maxVotes = candidates[i].votes; 
            winnerIndex = i; 
        } 
    } 
  
    for (int i = 0; i < candidateCount; i++) { 
        if (candidates[i].votes == maxVotes) { 
            winnerFrequency++; 
        } 
    } 
  
    printf("\n-----RESULT-----\n"); 
  
    if (winnerFrequency > 1) { 
        printf("No candidate has majority votes\n"); 
    } 
    else if (winnerIndex != -1) { 
        printf("The winner is: %s\n"
               "%d votes!\n", 
               candidates[winnerIndex].name, maxVotes); 
    } 
    else { 
        printf("No winner\n"); 
    } 
    printf("\n-----RESULT END -----\n"); 
}


// Function to display the menu
void displayAvailableOptions() {
    printf("\n----- Mini Voting System -----\n");
    printf("1. Add Candidates\n");
    printf("2. View Candidates\n");
    printf("3. Vote for a Candidate\n");
    printf("4. View Results\n");
    printf("5. Announce Winner\n");
    printf("6. Exit\n");
    printf("-------------------------------\n");
}

//main function
int main() {
    struct Candidate candidates[MAX_CANDIDATES];
    int option;
    do {
        displayAvailableOptions();
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                initializeCandidates(candidates);
                break;
            case 2:
                showAllCandidates(candidates);
                break;
            case 3:
                utilizeVote(candidates);
                break;
            case 4:
                showResults(candidates);
                break;
            case 5:
                announceWinner(candidates);
                break;
            case 6:
                printf("Exiting the program. Thank you!\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (option != 6);
    
    return 0;
}

