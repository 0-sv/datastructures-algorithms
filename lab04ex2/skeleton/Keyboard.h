//=====================================================================
// FILE: Keyboard.h
//=====================================================================

//=====================================================================
// STUDENT NAME: <Sebastiaan Verbeek>
// MATRIC NO.  : <A0174730H>
// NUS EMAIL   : <e0215432@u.nus.edu>
// COMMENTS TO GRADER:
// <comments to grader, if any>
//
//=====================================================================

#ifndef keyboard_h
#define keyboard_h

class Keyboard {
private:
    struct Node {
        char letter;
        Node *prev;
        Node *next;
    };

    Node *_head;
    Node *_tail;
    Node *_cursor;

public:
    Keyboard();
    void moveCursorLeft(int k);
    void moveCursorRight(int k);
    void insertChar(char newLetter);
    void deleteChar();
    void printLine();

    // Add more if necessary.
};

#endif
