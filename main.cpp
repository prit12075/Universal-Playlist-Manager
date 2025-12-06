#include <iostream>
#include <string>
#include "Playlist.h"

using namespace std;

int main() {
    // Instantiate Playlist for Strings (Song names)
    Playlist<string> myMusic;
    int choice;
    string songName;

    do {
        cout << "\n--- 🎵 LINKED LIST MUSIC PLAYER 🎵 ---\n";
        cout << "1. Add Song (to End)\n";
        cout << "2. Add Priority Song (to Start)\n";
        cout << "3. Remove Song\n";
        cout << "4. Show Playlist (Forward)\n";
        cout << "5. Show Playlist (Backward)\n";
        cout << "6. Reverse Playlist\n";
        cout << "7. Check for Infinite Loop (Cycle)\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore(); // Clear buffer

        switch (choice) {
        case 1:
            cout << "Enter song name: ";
            getline(cin, songName);
            myMusic.insertAtTail(songName);
            break;
        case 2:
            cout << "Enter song name: ";
            getline(cin, songName);
            myMusic.insertAtHead(songName);
            break;
        case 3:
            cout << "Enter song name to remove: ";
            getline(cin, songName);
            myMusic.deleteSong(songName);
            break;
        case 4:
            myMusic.displayForward();
            break;
        case 5:
            myMusic.displayBackward();
            break;
        case 6:
            myMusic.reversePlaylist();
            break;
        case 7:
            if (myMusic.hasCycle()) cout << "Cycle Detected! Infinite loop." << endl;
            else cout << "No Cycle. Linear Playlist." << endl;
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != 0);

    return 0;
}