#include <iostream>

typedef struct card Card;

// Array of the different suits, Clubs, Diamonds, Hearts and Spades
const char suits[] = {'C', 'D', 'H', 'S'};
char ranks[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

// Foundations
Card *foundations[4];

//Columns
Card *columns[7];

struct card {
    Card *prev;
    Card *next;
    char rank;
    char suit;
};

Card *new_card(char rank, char suit){
    Card *card = (Card *)malloc(sizeof(Card));
    card->prev = NULL;
    card->next = NULL;
    card->rank = rank;
    card->suit = suit;
    return card;
}
Card *default_deck(){
    //Initialize deck, with a dummy bottom card
    Card *deck = new_card('B', 'B');
    Card *prev = deck;
    for (int suit = 0; suit < 4; suit++) {
        for (int rank = 0; rank < 13; rank++) {
            Card *card = new_card(ranks[rank], suits[suit]);
            prev->next = card;
            card->prev = prev;
            prev = card;
        }
    }
    return deck;
}

//Still needs work - currently only takes input file and prints content to terminal
Card *load_deck(char* filename){
    FILE* ptr;
    char ch;

    ptr = fopen(filename, "r");

    if (NULL == ptr) {
        printf("File doesn't exist");
    }

    // Add dummy card to bottom
    Card *deck = new_card('B', 'B');
    Card *prev = deck;

    char input[3]; // char array to hold line characters for input

    // Do-while that reads an entire line, creates a new card and adds it to the deck
    do {
        for (int i = 0; i < 3; ++i) {
            ch = fgetc(ptr);
            input[i] = ch;
        }
        Card *card = new_card(input[0], input[1]);
        prev->next = card;
        card->prev = prev;
        prev = card;

    // Checking if character is not EOF.
    // If it is EOF stop reading.
    } while (ch != EOF);

    // Closing the file
    fclose(ptr);
    return deck;
}
void *save_cards(Card *deck, char* filename){
    FILE* ptr;

    ptr = fopen(filename, "w");
    do {
        deck = deck->next;
        fprintf(ptr,"%c%c\n", deck->rank, deck->suit);
    }while(deck->next != NULL);


    // Closing the file
    fclose(ptr);
}

void show(){

    printf("\tC1\tC2\tC3\tC4\tC5\tC6\tC7\n\n");
    for (int i = 0; i < 52; ++i) {

    }
}

const char* get_input() {
    char input[127];
    printf("Enter command: ");
    scanf("%s", &input);
    return input;
}

void setup_columns_foundations(){
    for (int i = 0; i < 4; ++i) {
        foundations[i] = new_card('d', 'd'); //dummy card
    }
    for (int i = 0; i < 7; ++i) {
        columns[i] = new_card('d', 'd'); //dummy card
    }
}


int main() {
    int a = 4;
    setup_columns_foundations();
    Card *first_card = columns[0];
    Card *card  = new_card('A', 'C');
    first_card->next = card;
    //Test to show how it could be made in conole
    printf("\tC1\tC2\tC3\tC4\tC5\tC6\tC7\n\n");
    printf("\t%c%c\t[]\t[]\t[]\t[]\t[]\t[]\t\tF1\n", first_card->next->rank, first_card->next->suit);
    printf("\t  \t7H\t[]\t[]\t[]\t[]\t[]\t\t\n");
    printf("\t  \t  \t5H\t[]\t[]\t[]\t[]\t\tF2\n");
    printf("\t  \t  \t  \t6C\t[]\t[]\t[]\t\t\n");
    printf("\t  \t  \t  \t  \t6S\t[]\t[]\t\tF3\n");
    printf("\t  \t  \t  \t  \t  \tQC\t[]\t\t\n");
    printf("\t  \t  \t  \t  \t  \t  \tKH\t\tF4\n");
    printf("\t  \t  \t  \t  \t  \t  \t  \t\t\n");

    // Test to print all cards, if no input file is provided
    Card * deck = load_deck(R"(C:\DTU\2-semester\MaskinarProgrammering\Yukon\YukonS-G50\Test_input.txt)");
//    do {
//        deck = deck->next;
//        printf("%c%c\n",deck->rank, deck->suit);
//    }  while (deck->next != NULL);
//
//
//    do {
//        printf("%c%c\n",first_card->rank, first_card->suit);
//        first_card = first_card->next;
//        printf("%c%c\n",first_card->rank, first_card->suit);
//    }  while (first_card->next != NULL);

    //clear screen
    //system("cls");

    //save_cards(deck, "C:\\DTU\\2-semester\\MaskinarProgrammering\\Yukon\\YukonS-G50\\Test1_input.txt");



    return 0;
}
