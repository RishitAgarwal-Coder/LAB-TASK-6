# Data Structures Lab - Task 6

This repository contains C implementations for Queue data structures using arrays, focusing on FIFO (First-In, First-Out) logic and circular memory management.

**Lab Exercises:**

1. **Linear Queue Implementation:** - Standard FIFO management using front and rear pointers.
   - Modular functions for `enqueue`, `dequeue`, and `search`.
   
2. **Circular Queue Implementation:**
   - Memory-efficient design that wraps the rear pointer back to the front.
   - Prevents memory waste using the modulo operator for pointer incrementing.



**Objective:**

The purpose of these exercises is to master basic queue operations and understand how circular indexing solves the "static" limitation of linear queues where space becomes unusable after multiple dequeues.