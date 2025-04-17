//  1) Write a C++ code for implementation of stack push and pop operation
#include <iostream>
using namespace std;

#define SIZE 100  // You can change the size as needed

class Stack {
    int top;
    int arr[SIZE];

public:
    Stack() {
        top = -1;
    }

    // Push operation
    void push(int value) {
        if (top >= SIZE - 1) {
            cout << "Stack Overflow! Cannot push " << value << endl;
        } else {
            arr[++top] = value;
            cout << value << " pushed to stack." << endl;
        }
    }

    // Pop operation
    void pop() {
        if (top < 0) {
            cout << "Stack Underflow! Nothing to pop." << endl;
        } else {
            cout << arr[top--] << " popped from stack." << endl;
        }
    }

    // Peek operation (just for checking top element)
    int peek() {
        if (top < 0) {
            cout << "Stack is empty." << endl;
            return -1;
        } else {
            return arr[top];
        }
    }

    // Check if the stack is empty
    bool isEmpty() {
        return (top < 0);
    }
};

int main() {
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "Top element is: " << s.peek() << endl;

    s.pop();
    s.pop();
    s.pop();
    s.pop();  // This will show underflow

    return 0;
}

//2) Write a C++ code for Balance()
#include <iostream>
#include <stack>
using namespace std;

bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}

bool Balance(string expr) {
    stack<char> s;

    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (s.empty() || !isMatchingPair(s.top(), ch)) {
                return false;  // Unbalanced or mismatched
            }
            s.pop();
        }
    }

    return s.empty(); // True if all brackets are balanced
}

int main() {
    string expression;
    cout << "Enter an expression: ";
    cin >> expression;

    if (Balance(expression))
        cout << "Balanced expression." << endl;
    else
        cout << "Not balanced." << endl;

    return 0;
}

//3) Write a C++ code for implementing Q using two stacks.
#include <iostream>
#include <stack>
using namespace std;

class Queue {
    stack<int> s1, s2;

public:
    // Enqueue operation (costly)
    void enqueue(int x) {
        // Move all elements from s1 to s2
        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        // Push the new element to s1
        s1.push(x);

        // Move everything back to s1 from s2
        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }

        cout << x << " enqueued to queue." << endl;
    }

    // Dequeue operation (efficient)
    void dequeue() {
        if (s1.empty()) {
            cout << "Queue is empty! Nothing to dequeue." << endl;
            return;
        }
        int front = s1.top();
        s1.pop();
        cout << front << " dequeued from queue." << endl;
    }

    // Peek front element
    int front() {
        if (s1.empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return s1.top();
    }

    // Check if queue is empty
    bool isEmpty() {
        return s1.empty();
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.front() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();  // This should say "Queue is empty"

    return 0;
}

//4) Write a C++ code for implementation of queue, front, and rear operations
#include <iostream>
using namespace std;

#define SIZE 100

class Queue {
    int arr[SIZE];
    int front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    // Enqueue operation
    void enqueue(int x) {
        if (rear == SIZE - 1) {
            cout << "Queue Overflow!" << endl;
            return;
        }
        if (front == -1) front = 0; // First element
        arr[++rear] = x;
        cout << x << " enqueued to queue." << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow!" << endl;
            return;
        }
        cout << arr[front] << " dequeued from queue." << endl;
        front++;
        if (front > rear) {
            front = rear = -1; // Reset queue
        }
    }

    // Get front element
    int getFront() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Get rear element
    int getRear() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return arr[rear];
    }

    // Check if queue is empty
    bool isEmpty() {
        return (front == -1 || front > rear);
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    cout << "Front element: " << q.getFront() << endl;
    cout << "Rear element: " << q.getRear() << endl;

    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue(); // Will show underflow

    return 0;
}

//5) Write a C++ code for counting total number of nodes in linked list.
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
};

// Function to insert node at end
void insert(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
    }
}

// Function to count nodes
int countNodes(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

// Function to display list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);

    cout << "Linked List: ";
    display(head);

    int total = countNodes(head);
    cout << "Total number of nodes: " << total << endl;

    return 0;
}


//6) Write a C++ code for finding cycle in linked list.
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Function to insert at end
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// Floyd’s Cycle Detection Algorithm
bool hasCycle(Node* head) {
    Node *slow = head, *fast = head;

    while (fast && fast->next) {
        slow = slow->next;          // move one step
        fast = fast->next->next;    // move two steps

        if (slow == fast)
            return true;  // Cycle found
    }
    return false;  // No cycle
}

int main() {
    Node* head = nullptr;

    // Creating list: 10 -> 20 -> 30 -> 40 -> 50
    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);

    // Creating a cycle manually: 50 -> points back to 20
    head->next->next->next->next->next = head->next;

    if (hasCycle(head))
        cout << "Cycle detected in the linked list!" << endl;
    else
        cout << "No cycle in the linked list." << endl;

    return 0;
}

// 7) Write a c++ code for reversing linked list
#include <iostream>
using namespace std;

// Node structure
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// Insert at end
void insert(Node*& head, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

// Display the list
void display(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL" << endl;
}

// Reverse the list
Node* reverse(Node* head) {
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr) {
        next = curr->next;   // store next node
        curr->next = prev;   // reverse current node's pointer
        prev = curr;         // move prev one step
        curr = next;         // move curr one step
    }

    return prev; // new head
}

int main() {
    Node* head = nullptr;

    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);

    cout << "Original Linked List: ";
    display(head);

    head = reverse(head);

    cout << "Reversed Linked List: ";
    display(head);

    return 0;
}

// 8)Write a C++ code for implementing BubbleSort.
#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;

        for (int j = 0; j < n - i - 1; j++) {
            // Swap if elements are in wrong order
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Optimization: If no swaps, the array is already sorted
        if (!swapped)
            break;
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

// 9) Write a C++ code for implementation of SelectionSort.
#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;

        // Find the minimum in the unsorted part
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }

        // Swap the found minimum with the first element of unsorted part
        if (minIndex != i)
            swap(arr[i], arr[minIndex]);
    }
}

// Function to print array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {29, 10, 14, 37, 13};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    selectionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

//10) Write a C++ code for implementation of Insertion Salt.
#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i]; // Current element
        int j = i - 1;

        // Move elements greater than key to one position ahead
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }

        // Insert key at correct position
        arr[j + 1] = key;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {9, 5, 1, 4, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    insertionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}


//11)Write a C++ code for implementation of QuickSort.
#include <iostream>
using namespace std;

// Partition function to place pivot at correct position
int partition(int arr[], int low, int high) {
    int pivot = arr[high];  // Choosing the last element as pivot
    int i = low - 1;  // Index of smaller element

    for (int j = low; j <= high - 1; j++) {
        // If current element is smaller than pivot, swap it
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);  // Place pivot at correct position
    return (i + 1);
}

// QuickSort function
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // Partition index

        // Recursively sort the two halves
        quickSort(arr, low, pi - 1);  // Left part
        quickSort(arr, pi + 1, high); // Right part
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    quickSort(arr, 0, n - 1);  // Call QuickSort

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

//12) Write a C++ code for merge sort.
#include <iostream>
using namespace std;

// Merge two subarrays into a sorted array
void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temporary arrays to hold the subarrays
    int L[n1], R[n2];

    // Copy data to temporary arrays L[] and R[]
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    // Merge the temporary arrays back into arr[left..right]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of L[], if any
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copy remaining elements of R[], if any
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;  // Find the middle point

        // Recursively sort the two halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    mergeSort(arr, 0, n - 1);  // Call MergeSort

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}


//13) Write a C++ code for implementation of linear search.
#include <iostream>
using namespace std;

// Linear search function
int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;  // Return the index where the target is found
        }
    }
    return -1;  // Return -1 if the target is not found
}

int main() {
    int arr[] = {34, 23, 11, 56, 90, 27, 43};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 56;

    int result = linearSearch(arr, n, target);

    if (result != -1) {
        cout << "Element " << target << " is present at index " << result << endl;
    } else {
        cout << "Element " << target << " is not present in the array" << endl;
    }

    return 0;
}


//14) Write a C++ code for implementation of binary search.
#include <iostream>
using namespace std;

// Binary search function
int binarySearch(int arr[], int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;  // To avoid overflow

        // Check if target is at the middle
        if (arr[mid] == target)
            return mid;

        // If target is smaller, search in the left half
        else if (arr[mid] > target)
            right = mid - 1;

        // If target is larger, search in the right half
        else
            left = mid + 1;
    }

    // If target is not found
    return -1;
}

int main() {
    int arr[] = {2, 5, 10, 15, 20, 25, 30, 35, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 25;

    int result = binarySearch(arr, n, target);

    if (result != -1) {
        cout << "Element " << target << " is present at index " << result << endl;
    } else {
        cout << "Element " << target << " is not present in the array" << endl;
    }

    return 0;
}


//15)Write a C++ code for finding height of BST Binary Search Tree
#include <iostream>
using namespace std;

// Structure for a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to find the height of the BST
int height(Node* root) {
    // Base case: If the tree is empty, height is 0
    if (root == nullptr)
        return 0;
    
    // Recursively find the height of the left and right subtrees
    int leftHeight = height(root->left);
    int rightHeight = height(root->right);
    
    // The height of the current node is the maximum of the left and right subtree heights plus 1
    return max(leftHeight, rightHeight) + 1;
}

// Function to insert a new node into the BST
Node* insert(Node* root, int val) {
    // If the tree is empty, create a new node
    if (root == nullptr)
        return new Node(val);
    
    // Otherwise, recur down the tree
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    
    // Return the (unchanged) node pointer
    return root;
}

int main() {
    Node* root = nullptr;
    
    // Insert elements into the BST
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 15);
    
    cout << "Height of the BST: " << height(root) << endl;
    
    return 0;
}


//16) Write a C++ code for counting total number of nodes in BST.
#include <iostream>
using namespace std;

// Structure for a tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to count the total number of nodes in the BST
int countNodes(Node* root) {
    // Base case: If the tree is empty, return 0
    if (root == nullptr)
        return 0;
    
    // Recursively count the nodes in the left and right subtrees, then add 1 for the current node
    return countNodes(root->left) + countNodes(root->right) + 1;
}

// Function to insert a new node into the BST
Node* insert(Node* root, int val) {
    // If the tree is empty, create a new node
    if (root == nullptr)
        return new Node(val);
    
    // Otherwise, recur down the tree
    if (val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
        root->right = insert(root->right, val);
    
    // Return the (unchanged) node pointer
    return root;
}

int main() {
    Node* root = nullptr;
    
    // Insert elements into the BST
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 1);
    root = insert(root, 15);
    
    cout << "Total number of nodes in the BST: " << countNodes(root) << endl;
    
    return 0;
}


//17)Write a C++ code for implementing BFS.
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph {
    int V;  // Number of vertices
    vector<vector<int>> adj;  // Adjacency list

public:
    // Constructor to initialize the graph with a given number of vertices
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    // Function to add an edge to the graph (undirected)
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);  // As it's an undirected graph
    }

    // BFS traversal starting from the source node
    void BFS(int start) {
        vector<bool> visited(V, false);  // To keep track of visited nodes
        queue<int> q;

        visited[start] = true;  // Mark the starting node as visited
        q.push(start);  // Enqueue the starting node

        while (!q.empty()) {
            int node = q.front();  // Get the node at the front of the queue
            q.pop();
            cout << node << " ";  // Print the current node

            // Explore all unvisited neighbors of the current node
            for (int neighbor : adj[node]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);  // Enqueue the neighbor
                }
            }
        }
        cout << endl;
    }
};

int main() {
    // Create a graph with 6 vertices (0 to 5)
    Graph g(6);
    
    // Adding edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << "BFS Traversal starting from node 0: ";
    g.BFS(0);

    return 0;
}


//18) Write the C++ code for implementing DFS.
#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;  // Number of vertices
    vector<vector<int>> adj;  // Adjacency list

public:
    // Constructor to initialize the graph with a given number of vertices
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    // Function to add an edge to the graph (undirected)
    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);  // As it's an undirected graph
    }

    // DFS traversal starting from the source node
    void DFS(int start) {
        vector<bool> visited(V, false);  // To keep track of visited nodes
        DFSUtil(start, visited);
        cout << endl;
    }

private:
    // Utility function for DFS traversal using recursion
    void DFSUtil(int node, vector<bool>& visited) {
        visited[node] = true;  // Mark the node as visited
        cout << node << " ";   // Print the current node
        
        // Recur for all unvisited neighbors of the current node
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                DFSUtil(neighbor, visited);
            }
        }
    }
};

int main() {
    // Create a graph with 6 vertices (0 to 5)
    Graph g(6);
    
    // Adding edges to the graph
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);

    cout << "DFS Traversal starting from node 0: ";
    g.DFS(0);

    return 0;
}


//19) Write a C++ code for implementing graph, adjacency list, and adjacency matrix.
#include <iostream>
#include <vector>
using namespace std;

class Graph {
public:
    // Adjacency List Representation
    vector<vector<int>> adjList;
    int V;  // Number of vertices

    // Constructor to initialize the graph with a given number of vertices
    Graph(int vertices) {
        V = vertices;
        adjList.resize(V);
    }

    // Function to add an edge to the graph (undirected graph)
    void addEdgeAdjList(int u, int v) {
        adjList[u].push_back(v);
        adjList[v].push_back(u);  // As it's an undirected graph
    }

    // Function to print the adjacency list
    void printAdjList() {
        for (int i = 0; i < V; i++) {
            cout << "Node " << i << ": ";
            for (int j : adjList[i]) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    // Adjacency Matrix Representation
    vector<vector<int>> adjMatrix;

    // Function to initialize the adjacency matrix
    void initializeAdjMatrix() {
        adjMatrix.resize(V, vector<int>(V, 0));  // Initialize a V x V matrix with 0s
    }

    // Function to add an edge to the graph (undirected graph)
    void addEdgeAdjMatrix(int u, int v) {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1;  // As it's an undirected graph
    }

    // Function to print the adjacency matrix
    void printAdjMatrix() {
        cout << "Adjacency Matrix:" << endl;
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    // Create a graph with 5 vertices (0 to 4)
    Graph g(5);

    // Add edges to the graph
    g.addEdgeAdjList(0, 1);
    g.addEdgeAdjList(0, 4);
    g.addEdgeAdjList(1, 2);
    g.addEdgeAdjList(1, 3);
    g.addEdgeAdjList(3, 4);

    // Print the adjacency list representation
    cout << "Adjacency List Representation:" << endl;
    g.printAdjList();
    
    // Initialize adjacency matrix
    g.initializeAdjMatrix();

    // Add edges to the adjacency matrix
    g.addEdgeAdjMatrix(0, 1);
    g.addEdgeAdjMatrix(0, 4);
    g.addEdgeAdjMatrix(1, 2);
    g.addEdgeAdjMatrix(1, 3);
    g.addEdgeAdjMatrix(3, 4);


    g.printAdjMatrix();

    return 0;
}


//20) Write a C++ code for implementing hashing table.
#include <iostream>
#include <list>
#include <vector>
#include <string>
using namespace std;

class HashTable {
    int size;  
    vector<list<pair<int, string>>> table;  

public:

    HashTable(int size) {
        this->size = size;
        table.resize(size);
    }


    int hash(int key) {
        return key % size;  
    }


    void insert(int key, const string& value) {
        int index = hash(key);

        for (auto& pair : table[index]) {
            if (pair.first == key) {
                pair.second = value;  
                return;
            }
        }

        table[index].push_back(make_pair(key, value));
    }


    string search(int key) {
        int index = hash(key);

        for (auto& pair : table[index]) {
            if (pair.first == key) {
                return pair.second;  
            }
        }
        return "Not Found";  
    }


    void deleteKey(int key) {
        int index = hash(key);
        auto& list_at_index = table[index];


        for (auto it = list_at_index.begin(); it != list_at_index.end(); ++it) {
            if (it->first == key) {
                list_at_index.erase(it);  
                return;
            }
        }
        cout << "Key not found." << endl;  
    }


    void display() {
        for (int i = 0; i < size; i++) {
            if (!table[i].empty()) {
                cout << "Index " << i << ": ";
                for (auto& pair : table[i]) {
                    cout << "{" << pair.first << ": " << pair.second << "} ";
                }
                cout << endl;
            }
        }
    }
};

int main() {

    HashTable ht(10);


    ht.insert(12, "Apple");
    ht.insert(22, "Banana");
    ht.insert(32, "Cherry");
    ht.insert(42, "Date");
    ht.insert(52, "Elderberry");


    cout << "Hash Table after insertions:" << endl;
    ht.display();


    cout << "Search for key 22: " << ht.search(22) << endl;
    cout << "Search for key 99: " << ht.search(99) << endl;


    ht.deleteKey(22);
    cout << "Hash Table after deleting key 22:" << endl;
    ht.display();

    return 0;
}

