#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include "Node.h"

using namespace std;

template <typename T>
class Playlist {
private:
    Node<T>* head;
    Node<T>* tail;

public:
    Playlist() {
        head = nullptr;
        tail = nullptr;
    }

    // --- TOPIC 1: INSERTION ---

    void insertAtTail(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    void insertAtHead(T val) {
        Node<T>* newNode = new Node<T>(val);
        if (head == nullptr) {
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }

    // --- TOPIC 2: DELETION ---

    void deleteSong(T val) {
        if (head == nullptr) return;

        Node<T>* temp = head;
        while (temp != nullptr && temp->data != val) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Song not found!" << endl;
            return;
        }

        // If node to be deleted is head
        if (temp == head) {
            head = head->next;
            if (head) head->prev = nullptr;
            else tail = nullptr; // List became empty
        }
        // If node to be deleted is tail
        else if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
        }
        // If node is in the middle
        else {
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;
        }

        delete temp;
        cout << "Song removed: " << val << endl;
    }

    // --- TOPIC 3: TRAVERSAL ---

    void displayForward() {
        if (!head) { cout << "Playlist is empty." << endl; return; }
        Node<T>* temp = head;
        cout << "Playlist (Start -> End): ";
        while (temp != nullptr) {
            cout << "[" << temp->data << "] <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void displayBackward() {
        if (!tail) { cout << "Playlist is empty." << endl; return; }
        Node<T>* temp = tail;
        cout << "Playlist (End -> Start): ";
        while (temp != nullptr) {
            cout << "[" << temp->data << "] <-> ";
            temp = temp->prev;
        }
        cout << "NULL" << endl;
    }

    // --- TOPIC 4: REVERSAL (Iterative) ---

    void reversePlaylist() {
        if (!head || !head->next) return;

        Node<T>* current = head;
        Node<T>* temp = nullptr;

        // Swap next and prev for all nodes
        while (current != nullptr) {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev; // Move to next node (which is now at prev)
        }

        // Swap head and tail pointers
        temp = head;
        head = tail;
        tail = temp;

        cout << "Playlist reversed successfully!" << endl;
    }

    // --- TOPIC 5: CYCLE DETECTION (Floyd's Algorithm) ---
    // Useful for interview prep: Checks if the playlist is stuck in a loop
    bool hasCycle() {
        if (!head) return false;
        Node<T>* slow = head;
        Node<T>* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;       // Move 1 step
            fast = fast->next->next; // Move 2 steps
            if (slow == fast) return true; // Cycle detected
        }
        return false;
    }
};

#endif