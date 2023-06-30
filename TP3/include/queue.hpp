#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

// A Tree node
struct Node
{
    char ch;
    int freq;
    Node* left, * right;
};

// Queue Node
struct QueueNode {
    char data;
    QueueNode* next;

    QueueNode(char ch) {
        data = ch;
        next = nullptr;
    }
};

// Queue class
class Queue {
    private:
        QueueNode* front;
        QueueNode* rear;

    public:
        Queue() {
            front = nullptr;
            rear = nullptr;
        }

        bool isEmpty() {
            return front == nullptr;
        }

        void enqueue(char ch) {
            QueueNode* newNode = new QueueNode(ch);

            if (rear == nullptr) {
                front = newNode;
                rear = newNode;
                return;
            }

            rear->next = newNode;
            rear = newNode;
        }

        char dequeue() {
            if (isEmpty()) {
                return '\0';
            }

            QueueNode* temp = front;
            char ch = temp->data;
            front = front->next;

            if (front == nullptr) {
                rear = nullptr;
            }

            delete temp;
            return ch;
        }
};

#endif