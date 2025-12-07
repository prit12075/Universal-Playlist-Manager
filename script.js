// --- The Data Structures ---

class Node {
    constructor(data) {
        this.data = data;
        this.next = null;
        this.prev = null;
        // Generate a fake memory address for visuals (e.g., 0x4A1)
        this.address = "0x" + Math.floor(Math.random() * 4096).toString(16).toUpperCase();
    }
}

class DoublyLinkedList {
    constructor() {
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    insertTail(data) {
        const newNode = new Node(data);
        if (!this.head) {
            this.head = this.tail = newNode;
        } else {
            this.tail.next = newNode;
            newNode.prev = this.tail;
            this.tail = newNode;
        }
        this.size++;
        render();
        log(`Inserted "${data}" at Tail`);
    }

    insertHead(data) {
        const newNode = new Node(data);
        if (!this.head) {
            this.head = this.tail = newNode;
        } else {
            newNode.next = this.head;
            this.head.prev = newNode;
            this.head = newNode;
        }
        this.size++;
        render();
        log(`Inserted "${data}" at Head`);
    }

    removeHead() {
        if (!this.head) {
            log("Error: Playlist is empty!");
            return;
        }
        const val = this.head.data;
        if (this.head === this.tail) {
            this.head = this.tail = null;
        } else {
            this.head = this.head.next;
            this.head.prev = null;
        }
        this.size--;
        render();
        log(`Removed "${val}"`);
    }

    reverse() {
        if (!this.head || !this.head.next) return;

        let current = this.head;
        let temp = null;

        // Swap next and prev for all nodes
        while (current) {
            temp = current.prev;
            current.prev = current.next;
            current.next = temp;
            current = current.prev; // Move to next node (which is at prev)
        }

        // Swap head and tail
        temp = this.head;
        this.head = this.tail;
        this.tail = temp;

        render();
        log("Playlist Reversed!");
    }
}

// --- Interaction Logic ---

const playlist = new DoublyLinkedList();
const container = document.getElementById('list-container');
const statusLog = document.getElementById('statusLog');
const input = document.getElementById('songInput');

// Helper to log messages
function log(msg) {
    statusLog.innerText = "> " + msg;
    statusLog.style.animation = 'none';
    statusLog.offsetHeight; /* trigger reflow */
    statusLog.style.animation = 'popIn 0.3s';
}

// The Render Function (Draws the visual list)
function render() {
    container.innerHTML = ''; // Clear current view
    
    let current = playlist.head;
    
    while(current) {
        // 1. Create Node Div
        const nodeDiv = document.createElement('div');
        nodeDiv.className = 'node';
        nodeDiv.innerHTML = `
            <span><i class="fa-solid fa-music"></i> ${current.data}</span>
            <div class="address">${current.address}</div>
        `;
        
        container.appendChild(nodeDiv);

        // 2. Create Arrow (if not last node)
        if (current.next) {
            const arrow = document.createElement('div');
            arrow.className = 'arrow';
            arrow.innerHTML = '<i class="fa-solid fa-arrow-right-arrow-left"></i>'; // Double arrow icon
            container.appendChild(arrow);
        }

        current = current.next;
    }
}

// --- Button Functions ---

function addHead() {
    const val = input.value.trim();
    if(val) {
        playlist.insertHead(val);
        input.value = '';
    }
}

function addTail() {
    const val = input.value.trim();
    if(val) {
        playlist.insertTail(val);
        input.value = '';
    }
}

function removeHead() {
    playlist.removeHead();
}

function reverseList() {
    playlist.reverse();
}

// Initial Data
playlist.insertTail("Blinding Lights");
playlist.insertTail("Levitating");