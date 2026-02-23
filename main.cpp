#include <iostream>
#include <ncurses.h>
#include <vector>

using namespace std;

int main(){
    system("clear");

    /*
    ----------------
    Define variables
    ----------------
    */
    vector<string> text = {""};
    int currentLine = 0, cursorPos = 0;
    int lnOffset = 0, posOffset = 0;
    int screenLns, screenCols;

    /*
    -----
    Setup
    -----
    */
    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    idlok(stdscr, TRUE);

    /*
    ---------------------
    Handle keyboard input
    ---------------------
    */
    int ch;
    while ((ch = getch()) != EOF) {
        switch(ch){
            case KEY_LEFT:
                if(cursorPos > 0){
                    cursorPos -= 1;
                }
                else if (cursorPos == 0 && currentLine > 0){
                    currentLine -= 1;
                    cursorPos = text[currentLine].length();
                }
                break;
            case KEY_RIGHT:
                if (cursorPos < text[currentLine].length()){
                    cursorPos += 1;
                }
                else if (cursorPos == text[currentLine].length() && currentLine < text.size()-1){
                    currentLine += 1;
                    cursorPos = 0;
                }
                break;
            case KEY_UP:
                if(currentLine > 0){
                    currentLine -= 1;
                    if(cursorPos > text[currentLine].length()){
                        cursorPos = text[currentLine].length();
                    }
                }
                break;
            case KEY_DOWN:
                if(currentLine < text.size()-1){
                    currentLine += 1;
                    if(cursorPos > text[currentLine].length()){
                        cursorPos = text[currentLine].length();
                    }
                }
                break;
            
            case KEY_BACKSPACE:{
                if(cursorPos>0){
                    text[currentLine] = text[currentLine].substr(0, cursorPos-1) + text[currentLine].substr(cursorPos);
                    cursorPos -= 1;
                }else if (cursorPos == 0 && currentLine > 0){
                    currentLine--;
                    cursorPos = text[currentLine].length();
                    text[currentLine] += text[currentLine+1];
                    text.erase(text.begin() + currentLine + 1);
                }
                break;
            }

            case '\n': {
                string remainder = text[currentLine].substr(cursorPos);
                text[currentLine] = text[currentLine].substr(0, cursorPos);
                text.insert(text.begin() + currentLine + 1, remainder);
                currentLine++;
                cursorPos = 0;
                break;
            }

            case '\t':
                text[currentLine].insert(cursorPos, "    ");
                cursorPos+=4;
                break;
            
            default:
                if (ch >= 32 && ch < 127) {
                    text[currentLine].insert(cursorPos, 1, static_cast<char>(ch));
                    cursorPos++;
                }
                break;
        }
        /*
        ----------------
        Handle scrolling
        ----------------
        */
        getmaxyx(stdscr, screenLns, screenCols);
        if (currentLine >= lnOffset + screenLns) {
            lnOffset = currentLine - screenLns + 1;
        }
        if (currentLine < lnOffset) {
            lnOffset = currentLine;
        }
        if (cursorPos >= posOffset + screenCols) {
            posOffset = cursorPos - screenCols + 1;
        }
        if (cursorPos < posOffset) {
            posOffset = cursorPos;
        }

        /*
        ---------------
        Print to screen
        ---------------
        */
        clear();
        for (int i = 0; i < screenLns; i++) {
            int fileLine = i + lnOffset;
            if (fileLine >= text.size())
                break;

            string line = text[fileLine];

            if (posOffset < line.length()) {
                string visible = line.substr(posOffset, screenCols);
                mvprintw(i, 0, "%s", visible.c_str());
            }
        }
        move(currentLine-lnOffset, cursorPos-posOffset);
        refresh();
    }
    /*TODO:
        Reading file
        Writing file
    */
    return 0;
}