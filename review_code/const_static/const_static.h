/**
 * Const_Static Header
 *
 * Copyright (c) [2021], Zhao Liu.
 */

/* Static
1. Member function/variable: belong to the object(class)
2. Friend frinend: not belong to the object(class), just a friend
3. Static function/variable: belong to the class itself, can access the function
   straight through the class
 */



class Inventory {
 private:
  static int count;

 public:
  Inventory();
  static int getCount();
};