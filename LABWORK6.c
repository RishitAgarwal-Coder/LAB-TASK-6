#include <stdio.h>

/* NAME: Rishit Agarwal
   REG NO: AP25110070245
   COURSE: CSE 102 - Data Structures Lab
   LAB TASK 6
*/

int q[5], cq[5];
int f = -1, r = -1;
int cf = -1, cr = -1;
int size = 5;

// --- LINEAR QUEUE FUNCTIONS ---
void enqueueLinear(int val) {
    if (r == size - 1) {
        printf("Linear Queue Overflow\n");
    } else {
        if (f == -1) f = 0;
        q[++r] = val;
        printf("Enqueued %d to Linear Queue\n", val);
    }
}

int dequeueLinear() {
    if (f == -1 || f > r) {
        printf("Linear Queue Underflow\n");
        return -1;
    } else {
        int val = q[f++];
        if (f > r) f = r = -1;
        return val;
    }
}

void searchLinear(int key) {
    int found = 0;
    if (f == -1) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = f; i <= r; i++) {
        if (q[i] == key) {
            printf("Element %d found at index %d in Linear Queue\n", key, i);
            found = 1;
            break;
        }
    }
    if (!found) printf("Element %d not found in Linear Queue\n", key);
}

// --- CIRCULAR QUEUE FUNCTIONS ---
void enqueueCircular(int val) {
    if ((cr + 1) % size == cf) {
        printf("Circular Queue Overflow\n");
    } else {
        if (cf == -1) cf = 0;
        cr = (cr + 1) % size;
        cq[cr] = val;
        printf("Enqueued %d to Circular Queue\n", val);
    }
}

int dequeueCircular() {
    if (cf == -1) {
        printf("Circular Queue Underflow\n");
        return -1;
    } else {
        int val = cq[cf];
        if (cf == cr) cf = cr = -1;
        else cf = (cf + 1) % size;
        return val;
    }
}

void searchCircular(int key) {
    if (cf == -1) {
        printf("Queue is empty\n");
        return;
    }
    int i = cf, found = 0;
    while (1) {
        if (cq[i] == key) {
            printf("Element %d found at index %d in Circular Queue\n", key, i);
            found = 1;
            break;
        }
        if (i == cr) break;
        i = (i + 1) % size;
    }
    if (!found) printf("Element %d not found in Circular Queue\n", key);
}

void question1() {
    printf("\n--- Question 1: Linear Queue ---\n");
    enqueueLinear(10);
    enqueueLinear(20);
    enqueueLinear(30);
    searchLinear(20);
    printf("Dequeued: %d\n", dequeueLinear());
    searchLinear(10);
}

void question2() {
    printf("\n--- Question 2: Circular Queue ---\n");
    enqueueCircular(40);
    enqueueCircular(50);
    enqueueCircular(60);
    searchCircular(50);
    printf("Dequeued: %d\n", dequeueCircular());
    searchCircular(40);
}

int main() {
    question1();
    question2();
    return 0;
}