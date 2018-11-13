/*********************************************
* Names: Dixant Patel, Jade Legare, Ali Afzal, Kathleen McCulloch-Cop
* GROUP: team 3 seaction 1 (Tuesday lab)
* Course: Software design 3 (cis*3250)
* Date: October 15 2018
*********************************************/
#include "connect.h"

//Author: unknown
//Reviewed By: Ali Afzal 1005257
//Functionality: initiliaze the board array given height and width
void arrInitialization(int height, int width){
    int counter1, counter2;
    for (counter1 = 0; counter1 < height; counter1++){
        for(counter2 = 0; counter2 < width; counter2++){
            arr[counter1][counter2] = '-';
        }
    }
}
//Author: unknown
//Reviewed By: Ali Afzal 1005257
//Functionality: Save the state of the current game
void saveGame(){
    int counter, counter2;
    char chose, chose2, chose3;
    printf("\nIf you save the file you will delete the previously saved file.");
    printf("\nIf you want to continue >> Enter Y << else >> Enter N << ");
    scanf("%s", &chose);
    if (chose =='Y'){
        FILE * file = fopen( "saveGame.txt" , "w");
        fprintf(file,"%d %d %d %d", width, height, highScores, numberOfPlay);
        fprintf(file,"\n%d %d", scoreOne, scoreTwo);
        fprintf(file,"\n%s\n", &whichPlayer);
        for(counter = 0; counter < height; counter++){
            for(counter2 = 0; counter2 < width; counter2++){
                fprintf(file, "%c ", arr[counter][counter2]);
            }
            fprintf(file, "\n");
        }
        fclose(file);
        printf("\n\x1b[96m The game has been saved. \n If you want to continue playing in the same game, \n"
               ">> Enter Y << else >> Enter N <<\x1b[0m ");
        scanf("%s", &chose2);
        if (chose2 == 'Y'){

        }
        else
        {
            gameOut = 1;
        }
    }
    /*continues playing the game if you dont save*/
    /*FIXME if user doesnt save then option to quit game before straight into playing */
    printf("\x1b[96mThe game is not saved. If you want to continue playing in the same game,\n >> Enter Y << else >> Enter N <<\x1b[0m" );
    scanf("%s", &chose3);

    if(chose == 'N' || chose2 == 'Y'){
        system("cls");
        printArrayValue(height, width);
        if (numberOfPlay % 2 == 0){
            printf("\n ,---.\n/ o o \\ \n\\ \\_/ /\n `---`");
            printf("\t\x1b[96m Player 2 >> Enter your play << = \x1b[0m");
            scanf("%s", playerInput);
            player(*playerInput, numberOfPlay);
        }
        else{
            printf("\n  |||||\n 0 . . 0\n0   ^   0\n0  \\_/  0\n 0     0\n  00000\n   888\n    8");
            printf("\t\x1b[92m Player 1 >> Enter your play << = \x1b[0m");
            scanf("%s", playerInput);
            player(*playerInput, numberOfPlay);
        }
    }
}

/* Author:
 Reviewed by: Jade Legare
 Functionality: Opens HighScores textfile to increment length of list
 Prints out highscores from the file
 */

void highScoresList(int flag){
    int counter, counter1, temp;
    
    /*scans file and increments listLength*/
    if (flag == 0){
        FILE *file = fopen("highScores.txt" , "r");
        while(fscanf(file, "%d",&highScoreList[listLength]) != EOF){
            listLength++;
        }
        fclose(file);
    }
    highScoreList[listLength] = scoreOne;
    highScoreList[listLength+1] = scoreTwo;
    printf("The High Score List\n");
    /*for length of the list, sets highScoreCounter to 
    previous counter and decreases that counter*/
    for (counter = 1; counter <= listLength + 1; counter++){
        counter1 = counter;
        while ( counter1 > 0 && highScoreList[counter1] > highScoreList[counter1 - 1]){
            temp = highScoreList[counter1];
            highScoreList[counter1] = highScoreList[counter1 - 1];
            highScoreList[counter1 - 1] = temp;
            counter1--;
        }
    }
    /*opens file and prints the high scores*/
    if (flag == 1){
        FILE *file = fopen("highScores.txt" , "w");
        for(counter = 0; counter < highScores; counter++){
            fprintf(file, "%d\n", highScoreList[counter]);
            printf("\n%d", highScoreList[counter]);
        }
        fclose(file);
    }
    else{
        for(counter = 0; counter < listLength; counter++){
            printf("%d\n", highScoreList[counter]);
        }
    }
}
/* Author:
 Reviewed by: Jade Legare
 Functionality: Sets up the game board by loading X's and O's from file
 Prints out user prompts to select who they want to play against
 */
void loadGame(){
    int counter, counter1, flag = 0, counterX = 0, counterO = 0;
    FILE *file = fopen("saveGame.txt", "r");
    if (file == NULL){
        flag = 1;
    }
    /*scans text file and sets values*/
    else{
        fscanf(file, "%d %d %d %d", &width, &height, &highScores, &numberOfPlay);
        fscanf(file, "%d %d", &scoreOne, &scoreTwo);
        fscanf(file, "%s", &whichPlayer);
        
	/*scans file and sets up the X's and O's in the board*/
        for(counter = 0; counter < height; counter++){
            for(counter1 = 0; counter1 < width; counter1++){
                fscanf(file, " %c ", &arr[counter][counter1]);
                if (arr[counter][counter1] == 'X'){
                    counterX++;
                }
                else if (arr[counter][counter1] == 'O'){
                    counterO++;
                }
            }
        }
    }
    /*sets flag to 1 in all statements except is score is out of 0 - 50 range*/
    fclose(file);
    if (width < 3 || width > 12 || height < 3 || height > 12){
        flag = 1;
    }
    if (numberOfPlay % 2 == 0 && (counterX - 1 != counterO || counterX * 2 != numberOfPlay)){
        flag = 1;
    }
    if (numberOfPlay % 2 != 0 && (counterX != counterO || counterX * 2 + 1 != numberOfPlay)){
        flag = 1;
    }
    if ((scoreOne >= 0  && scoreOne <= 50) && (scoreTwo >= 0 && scoreTwo <= 50)){
    }
    else{
        flag = 1;
    }
    if (flag == 1){
        printf("\n\t\x1b[96m >> Human vs. Human << \n OR \n\t >> Human vs. Computer \x1b[0m<<\n");
        printf("\n\x1b[92m>> Enter (H) if two player or (C) if one player\x1b[0m\n");
        scanf("%s", &whichPlayer);
        while (whichPlayer != 'H' && whichPlayer != 'C'){
            printf("\n\x1b[91m Invalid Input: Please try again\n >> Enter (H) if two player or (C) if one player \n\x1b[0m\n");
            scanf("%s", &whichPlayer);
        }
        numberOfPlay = 1;
        savePlace = 0, restorePlace = 0, scoreOne = 0, scoreTwo = 0;
        readXml();
        arrInitialization(height, width);
    }
}
/*
*Author:
*Reviewed by: Kathleen
*Functionality: uses for loops to go through pieces array, and print game board
* appropriately. Using ansicolor library to change colour of text and board
* From Ansicolor library:
* \xb1[0m = all attributes off (colour at startup
* \x1b[96m = light cyan
* \x1b[92m = light green
* \x1b[91m = light red
*
*/
void printArrayValue(int height, int width){

    int counter1, counter2;
    int flag = 0;

    printf("\n\n\t\x1b[96m>> Connect 4 \"Have fun\" <<\x1b[0m");
    printf("\n\n\t\x1b[92mScore One = %d\x1b[0m", scoreOne);
    printf("\t\t\t\x1b[96mScore Two = %d\x1b[0m", scoreTwo);
    printf("\n\n");

    for (counter1 = 0; counter1 < height; counter1++){
        for(counter2 = 0; counter2 < width && flag == 0; counter2++){
            printf("\x1b[96m[ %d ] \x1b[0m", counter2 + 1);
        }
        printf("\n");

        for(counter2 = 0; counter2 < width; counter2++){
            printf("\x1b[91m***** \x1b[0m");
        }

        printf("\n");
        for(counter2 = 0; counter2 < width; counter2++){
            printf("\x1b[91m*   * \x1b[0m");
        }

        printf("\n");
        for(counter2 = 0; counter2 < width; counter2++){
            printf("\x1b[91m* \x1b[0m");
            if (arr[counter1][counter2] == 'X'){
                printf("\x1b[92m%c \x1b[0m", arr[counter1][counter2]);
            }
            else if (arr[counter1][counter2] == 'O'){
                printf("\x1b[96m%c \x1b[0m", arr[counter1][counter2]);
            }
            else{
                printf("%c ", arr[counter1][counter2]);
            }
            printf("\x1b[91m* \x1b[0m");
        }
        printf("\n");
        for(counter2 = 0; counter2 < width; counter2++){
            printf("\x1b[91m*   * \x1b[0m");
        }
        printf("\n");
        for(counter2 = 0; counter2 < width; counter2++){
            printf("\x1b[91m***** \x1b[0m");
        }
        flag = 1;
    }
    printf("\n\n(U) to make undo");
    printf("\n\x1b[92m(R) to make redo \x1b[0m");
    printf("\n\x1b[96m(S) to save\n\x1b[0m");
}

/*
*Author:
*Reviewed by: Kathleen
*Functionality:function checks several different conditions to ensure game is not
*over, score is not violated, and piece placements will not violate if game continues
*/
void updateScore(int row, int col){
    int score = 0;

    if(col + 3 <= width && arr[row][col] == arr[row][col+1]){
        if (arr[row][col] == arr[row][col+2] && arr[row][col] == arr[row][col+3]){
            score++;
        }
    }
    if (col - 3 >= 0 && arr[row][col] == arr[row][col-1]){
        if (arr[row][col] == arr[row][col-2] && arr[row][col] == arr[row][col-3] ){
            score++;
        }
    }
    if (col - 1 >= 0 && col + 2 <= width && arr[row][col] == arr[row][col-1]){
        if(arr[row][col] == arr[row][col+1] && arr[row][col] == arr[row][col+2] ){
            score++;
        }
    }
    if (col - 2 >= 0 && col + 1 <= width && arr[row][col] == arr[row][col-1]){
        if (arr[row][col] == arr[row][col-2] && arr[row][col] == arr[row][col+1] ){
            score++;
        }
    }
    if(row - 3 >= 0 && arr[row][col] == arr[row-1][col] && arr[row][col] ==
            arr[row-2][col]&& arr[row][col] == arr[row-3][col] ){
        score++;
    }
    if (row + 3 <= height && arr[row][col] == arr[row+1][col]){
        if (arr[row][col] == arr[row+2][col] && arr[row][col] == arr[row+3][col] ){
            score++;
        }
    }
    if (row - 3 >= 0 && col+3 <= width && arr[row][col] == arr[row-1][col+1]){
        if (arr[row][col] == arr[row-2][col+2] && arr[row][col] == arr[row-3][col+3] ){
            score++;
        }
    }
    if (row + 3 <= height && col+3 <= width && arr[row][col] == arr[row+1][col+1]){
        if(arr[row][col] == arr[row+2][col+2] && arr[row][col] == arr[row+3][col+3]){
            score++;
        }
    }
    if (col + 1 <= width && row - 1 >= 0 && col - 2 >=0 && row + 2 <= height){
        if (arr[row][col] == arr[row-1][col+1] && arr[row][col] == arr[row+1][col-1]){
            if(arr[row][col] == arr[row+2][col-2]){
                score++;
            }
        }
    }
    if(col + 2 <= width && row - 2 >= 0 && col - 1 >= 0 && row + 1 <= height){
        if (arr[row][col] == arr[row-1][col+1] && arr[row][col] == arr[row-2][col+2]){
            if(arr[row][col] == arr[row+1][col-1]){
                score++;
            }
        }
    }
    if (col - 3 >= 0 && row - 3 >= 0 && arr[row][col] == arr[row-1][col-1]){
        if(arr[row][col] == arr[row-2][col-2] && arr[row][col] == arr[row-3][col-3] ){
            score++;
        }
    }
    if (col - 3 >= 0 && row + 3 <= height && arr[row][col] == arr[row+1][col-1]){
        if(arr[row][col] == arr[row+2][col-2] && arr[row][col] == arr[row+3][col-3]){
            score++;
        }
    }
    if (col + 1 <= width && row + 1 <= height && col - 2 >=0 && row - 2 >= 0){
        if(arr[row][col] == arr[row-1][col-1] && arr[row][col] == arr[row-2][col-2]){
            if(arr[row][col] == arr[row+1][col+1]){
                score++;
            }
        }
    }
    if (col + 2 <= width && row + 2 <= height && col - 1 >= 0 && row - 1 >= 0){
        if(arr[row][col] == arr[row-1][col-1] && arr[row][col] == arr[row+1][col+1]){
            if(arr[row][col] == arr[row+2][col+2]){
                score++;
            }
        }
    }
    if (numberOfPlay % 2 != 0){
        if (playerInput[0] == 'U'){
            scoreOne -= score;
        }
        else{
            scoreOne += score;
        }
    }
    else{
        if (playerInput[0] == 'U'){
            scoreTwo -= score;
        }
        else{
            scoreTwo += score;
        }
    }
}

/* Author:
 Reviewed by: Jade Legare
 Functionality: Sends user error and promps them to enter a new choice
 */
void playAgain(){
    printf("\n\t\x1b[91m This move isn't valid. \n \n Please try another move: \x1b[0m");
    scanf("%s",playerInput);
    player(*playerInput, numberOfPlay);
}
/*
* changed from upercase to lower case
*/
void undo(){
    int counter = 0, flag = 0, noOfCol;
    if (savePlace == 0){

    }
    else{
        savePlace--;
        noOfCol = arrSaveAction[savePlace];
        arrRestorePlace[restorePlace] = noOfCol;
        restorePlace++;

        for (counter = 0; (counter < height) && (flag == 0) ; counter++){
            if (arr[counter][noOfCol] == 'X' ||  arr[counter][noOfCol] == 'O'){
                numberOfPlay--;
                updateScore(counter, noOfCol);
                arr[counter][noOfCol] = '-';
                flag = 1;
            }
        }
    }

    system("cls");
    printArrayValue(height, width);

    if (numberOfPlay % 2 == 0){
        if (whichPlayer == 'H'){
            printf("\n ,---.\n/ o o \\ \n\\ \\_/ /\n `---`");
            printf("\t\x1b[96mPlayer 2 >> Enter your play << = \x1b[0m");
            scanf("%s",playerInput);
            player(*playerInput, numberOfPlay);
        }
        else{
            computerPlayer();
        }
    }
    else{
        printf("\n  |||||\n 0 . . 0\n0   ^   0\n0  \\_/  0\n 0     0\n  00000\n   888\n    8");
        printf("\t\x1b[92m Player 1 >> Enter your play << = \x1b[0m");
        scanf("%s", playerInput);
        player(*playerInput, numberOfPlay);
    }
}

//Author
//Reviewed By: Jeongyeon
//Functionality: Redo the action and update the grid
void redo(){
    int noOfCol;
    int counter = 0, flag = 0;

    if (restorePlace == 0){

    }
    else{
        restorePlace--;
        noOfCol = arrRestorePlace[restorePlace];
        savePlace++;
        for (counter = 0; counter < height && flag == 0; counter++){
            if (arr[height - counter - 1][noOfCol] == '-'){
                if (numberOfPlay % 2 != 0){
                    arr[height - counter - 1][noOfCol] = 'X';
                }
                else{
                    arr[height - counter - 1][noOfCol] = 'O';
                }
                flag = 1;
            }
        }
        updateScore(height - counter, noOfCol);
        numberOfPlay++;
    }
    system("cls");
    printArrayValue(height, width);
    if (numberOfPlay % 2 == 0){
        printf("\n ,---.\n/ o o \\ \n\\ \\_/ /\n `---`");
        printf("\t\x1b[96mPlayer 2 >> Enter your play << = \x1b[0m");
        scanf("%s", playerInput);
        player(*playerInput, numberOfPlay);
    }
    else{
        printf("\n  |||||\n 0 . . 0\n0   ^   0\n0  \\_/  0\n 0     0\n  00000\n   888\n    8");
        printf("\t\x1b[92mPlayer 1 >> Enter your play << =\x1b[0m");
        scanf("%s", playerInput);
        player(*playerInput, numberOfPlay);
    }
}

//Author
//Reviewed By: Jeongyeon
//Functionality: Compute action for computer player and update score
void computerPlayer(){
    int row, randomPlay;
    int flag = 0;

    while (flag == 0){
        randomPlay = rand() % width;
        for(row = 0; row < height && flag == 0; row++){
            if(arr[height - row - 1][randomPlay]== 'X' || arr[height - row - 1][randomPlay] == 'O'){

            }
            else{
                if (row < height){
                    restorePlace = 0;
                    arr[height - row - 1][randomPlay] = 'O';
                    arrSaveAction[savePlace] = randomPlay;
                    savePlace++;
                    updateScore(height - row - 1, randomPlay);
                    system("cls");
                    printArrayValue(height, width);
                    flag = 1;
                }
            }
        }
    }
}

//Author
//Reviewed By: Jeongyeon
//Functionality: Get input from user to undo, redo or save game.
//		 Update move from user and computer
void player(char numberOfCol, int numberOfPlay){
    int row, convert;
    int flag = 0;

    convert = atoi(playerInput);

    if (convert == 0){
        numberOfCol = 0;
    }
    else{
        numberOfCol = convert;
    }
    if(numberOfCol > 0 && numberOfCol <= width){

    }
    else if (playerInput[0] == 'U'){
        undo();
        flag = 1;
    }
    else if (playerInput[0] == 'R'){
        redo();
        flag = 1;
    }
    else if(playerInput[0] == 'S'){
        saveGame();
        flag = 1;
    }
    else{
        flag = 2;
    }
    for(row = 0; row < height && flag == 0; row++){
        if(arr[height - row - 1][numberOfCol - 1] == 'X' || arr[height - row - 1][numberOfCol - 1] == 'O'){

        }
        else{
            if (row < height){
                restorePlace = 0;
                if (numberOfPlay % 2 != 0){
                    arr[height - row - 1][numberOfCol - 1] = 'X';
                    arrSaveAction[savePlace] = (numberOfCol - 1);
                    savePlace++;
                    updateScore(height - row - 1 , numberOfCol - 1);
                }
                else{
                    if (whichPlayer == 'H'){
                        arr[height - row - 1][numberOfCol - 1] = 'O';
                        arrSaveAction[savePlace] = (numberOfCol - 1);
                        savePlace++;
                        updateScore(height - row - 1 , numberOfCol - 1);
                    }
                    else{
                        computerPlayer();
                    }
                }
                system("cls");
                printArrayValue(height, width);
                flag = 1;
            }
        }
    }
    if (flag == 0 || flag == 2){ //if flag = this mean row "counter" is bigger than height <<all the row is fulled
        playAgain();
    }
}

void readXml(){
    char str[555];
    char str2[20][20];
    char s[4] = "<>";
    char *token;
    int counter, counter1, counter3 ;
    int found = 0, savePlace = 0, colmun = 0, row = 0, list = 0, flag = 0;

    FILE * file = fopen( "data.xml" , "r");

    while (fscanf(file, "%s", str) != EOF && flag == 0){
        counter = 0;
        found = 0;

        if (strlen(str) > 3){
            if  (str[counter] == '<' && ( str[strlen(str) - 1] == '>'
                || str[strlen(str) - 2] == '>'|| str[strlen(str) - 3] == '>' || str[strlen(str) -4] == '>') ){
                counter++;
            }
            else if (str[counter + 1] == '<' && str[strlen(str) - 1] == '>'){
                counter += 2 ;
            }
            else if ( str[counter + 2] == '<' &&  str[strlen(str) - 1] == '>'){
                counter += 3;
            }
            else if ( str[counter + 3] == '<' &&  str[strlen(str) - 1] == '>' ){
                counter += 4;
            }
            else{
                found = 1;
            }
            if (found == 0){
                while(counter < strlen(str) - 2 ){
                    if( (str[counter] >= 'A' && str[counter] <= 'z') || str[counter] == '<'
                            || str[counter] == '>' || str[counter] == '/'){
                        //do nothing
                    }
                    else if (found == 0){
                        if (str[counter + 1] == '\0' || str[counter + 2] =='\0' || str[counter + 3] =='\0' ||str[counter + 4] == '\0'){
                            if(str[counter - 1] != '>'){
                                flag = 1;
                            }
                        }
                        else if(str[counter - 1] == '>' && str[counter + 1] == '<' ){

                        }
                        else if (str[counter - 1] == '>' && str[counter + 2] == '<'){

                        }
                        else if (str[counter - 1] == '>' && str[counter + 3] == '<'){

                        }
                        else{
                            flag = 1;
                        }
                        found = 1;
                    }
                    counter++;
                }
            }
            else{
                flag = 1;
            }
        }
        token = strtok(str, s);
        counter = 0;
        if (str[counter] == '<'){
            counter = 1;
        }
        if (token == NULL){
            flag = 1;
        }
        found = 0;
        while( token != NULL && flag == 0){
            counter3 = 0;
            counter1 = 0;
            if (str[counter] == '<'){
                counter ++;
            }
            while ( strlen(token) > counter1 ){
                if ( (strlen(str) == 1 || strlen(str) == 2 || strlen(str) == 3) && found == 0 ){
                    counter = 0;
                    found = 1;
                }
                if (str[counter] == token[counter1] ){
                    counter3++;
                }
                counter1 ++;
                counter ++;
            }
            if ( str[counter + 1] == '>' || str[counter + 1] == '<'){
                flag = 1;
            }
            if(counter3 == strlen(token)){
                strcpy(str2[savePlace], token);
                savePlace ++;
            }
            else{
                flag = 1;
            }
            counter++;
            token = strtok(NULL, s);
        }
    }
    if (flag == 0){
        counter = 0;
        counter3 = 0;
        while ( str2[counter][counter3] != '\0' && flag == 0){
            if(str2[counter][counter3] == str2[savePlace - 1][counter3 + 1] ){
                counter3 ++;
            }
            else{
                flag = 1;
            }
        }
        if (str2[savePlace - 1][0] != '/' || strcmp(str2[counter] , "Configurations") != 0){
            flag = 1;
        }
        counter++;
        while(counter < savePlace - 2 && flag == 0){
            counter3 = 0;
            while (str2[counter][counter3] != '\0' && flag == 0){
                if (str2[counter][counter3] == str2[counter + 2][counter3 + 1]){
                    counter3 ++;
                }
                else{
                    flag = 1;
                }
            }
            if (flag == 0 && str2[counter + 2][0] =='/'){
                if (strcmp(str2[counter] , "width" ) == 0 ){
                    colmun = atoi(str2[counter+1]);
                }
                else if(strcmp(str2[counter] , "height" ) == 0){
                    row = atoi(str2[counter + 1]);
                }
                else if(strcmp(str2[counter] , "highScores") == 0){
                    list = atoi(str2[counter + 1]);
                }
                else{
                    flag = 1;
                }
            }
            else{
                flag = 1;
            }
            counter += 3;
        }
    }
    if( colmun > 3  && colmun < 13 && row > 3 && row < 13
            && list >= 0 && list < 13){
        width = colmun, height = row, highScores = list;
    }
    else{
        flag = 1;
    }
    if (flag == 1){
        width = 7, height = 6, highScores = 5;
    }
    return;
}

//Author: unknown
//Reviewed By: Ali Afzal 1005257
//Functionality: runs the entire program utilizing all the functions above this one
int main(){
    int flag = 0;
    char chose = 'C';//changed chose to chose1
    char option;

    while (chose == 'C'|| chose == 'c'){
	// added chose1 and chose2
        system("color 0A");
        printf(" \nIf You Want To Load The Saved Game >> Enter L << Else Enter Any thing ");
        scanf("%s", &option);

    if (option == 'L' || option == 'l'){
		//added option == 'l'
       loadGame();
    }
    else{
        printf(" \n\t\x1b[96m >> Human vs. Human << \n OR \n\t >> Human vs. Computer \x1b[0m<<\n");
		//brightcyan
        printf(" \n\x1b[92m>> Enter (H) if two player or (C) if one player\x1b[0m\n");
		//brightgreen
        scanf("%s", &whichPlayer);

        while (whichPlayer != 'H' && whichPlayer != 'C'){
            printf(" \n\x1b[91msome thing error please enter again\x1b[0m\n");
			//brightred
            scanf("%s", &whichPlayer);
        }
        numberOfPlay = 1;
        savePlace = 0, restorePlace = 0, scoreOne = 0, scoreTwo = 0;
        readXml();
        arrInitialization(height,width);
    }
    system("cls");
    gameOut = 0;

    while ( width*height >= numberOfPlay && gameOut != 1){
        system("cls");
        printArrayValue(height, width);
        if (numberOfPlay % 2 != 0){
            printf(" \n  |||||\n 0 . . 0\n0   ^   0\n0  \\_/  0\n 0     0\n  00000\n   888\n    8");
            printf("\t\x1b[92m player1<<Enter your play>> = \x1b[0m");
			//brightgreen
            scanf("%s",playerInput);
            player(*playerInput,numberOfPlay);
            numberOfPlay++;
        }
        else{
            if (whichPlayer == 'H'){
            printf(" \n ,---.\n/ o o \\ \n\\ \\_/ /\n `---`");
            printf("\t\x1b[96mPlayer 2 >> Enter your play << = \x1b[0m");
			//brightcyan
            scanf("%s",playerInput);
            player(*playerInput,numberOfPlay);
            }
            else{
                computerPlayer();
            }
            numberOfPlay++;
        }
    }
    system("cls");
    printArrayValue(height, width);
	//fixed spacing
    system("color 2A");
    if (numberOfPlay - 1 == width * height){
        if (scoreOne > scoreTwo){
            printf(" \n\n\t*** Congradulations Player One!! You are the winner!! ***");
            printf(" \n\t ** Better luck next time Player Two **\n");
        }
        else if (scoreOne < scoreTwo){
            printf(" \n\n\t*** Congradulations Player Two!! You are the winner!! ***");
            printf(" \n\t ** Better luck next time Player One **\n");
        }
        else{
            printf("\n\n\t*** Congradulations to both players!! You scored the same!! ***\n\n");
        }
        flag = 1;
        highScoresList(flag);
    }
    printf(" \n\nIf you want to continue >> Enter C << , else >> Enter X <<");
	//changed this line
    scanf("\n%s",&chose);
    system("cls");
    system("");
    }
    return 0;
}
