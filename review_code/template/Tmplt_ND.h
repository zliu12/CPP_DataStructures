/**
 * Template - Node Header File
 *
 * Copyright (c) [2021], Zhao Liu.
 */

#ifndef TMPLT_ND_H_
#define TMPLT_ND_H_

template <class T>
struct Node {
  T data;
  Node *next = nullptr;
};

#endif    // TMPLT_ND_H_