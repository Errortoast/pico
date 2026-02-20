#include <iostream>
#include <ncurses.h>
#include <vector>

using namespace std;

int main(){
    string file = "";

    system("clear");

    vector<string> text = {""};
    int currentLine = 0;
    int cursorPos = 0;

    initscr();
    noecho();
    cbreak();
    keypad(stdscr, TRUE);
    idlok(stdscr, TRUE);
    scrollok(stdscr, TRUE);

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
                text[currentLine].insert(cursorPos, "   ");
                cursorPos+=4;
                break;
            
            default:
                if (ch >= 32 && ch < 127) {
                    text[currentLine].insert(cursorPos, 1, static_cast<char>(ch));
                    cursorPos++;
                }
                break;
        }
        clear();
        for (int i = 0; i < text.size(); i++) {
            mvprintw(i, 0, "%s", text[i].c_str());
        }
        move(currentLine, cursorPos);
        refresh();
    }
    /*TODO:
        Scrolling
        Writing file
        Reading file
    */
    return 0;
}