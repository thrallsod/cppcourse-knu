#include "PrintHelper.h"

/* *************************************
 * * Fundamental types and expressions *
 * *************************************
 *
 * Tasks:
 * ------
 * - Compile the program and analyse the output of the different expressions
 * - Discuss with other students or your tutor in case the result of an expression is a surprise
 * - Fix the marked expressions by changing types such that they produce meaningful results
 * - Answer the questions in the code
 */

int main() {
  std::cout << "Using literals of different number types:\n";
  print(5);
  print(5./2);
  print(100/2ull);
  print(2 + 4ull);
  print(2.f + 4ull);
  print(0 - 1);
  print(1.0000000001); // Точність більша ніж в float
  print(1.L + 1.E-18L);

  std::cout << "\nUsing increment and decrement operators:\n";
  int a = 1;
  int b;
  int c;
  print(b = a++);       // Q: What is the difference between a++ and ++a?
    // b = a, a = a+1
  print(c = ++a); // c = a+1, a = a+1
  print(a);
  print(b);
  print(c);

  std::cout << "\nCompound assignment operators:\n";
  int n = 1;
  print(n *= 2);        // Q: Is there a difference between this and the next line?
  // в 40 округлиться до цілого числа через те, що n int, в 41 не округлиться.
  print(n *= 2.9);
  print(n -= 1.1f);
  print(n /= 4);        // Q: Based on the results of these expressions, is there a better type to be used for n?
  // Виведе 0 замість 0.25 (треба замінити на  double)

  std::cout << "\nLogic expressions:\n";
  const bool alwaysTrue = true;
  bool condition1 = false;
  bool condition2 = true;
  print( alwaysTrue && condition1 && condition2 );
  print( alwaysTrue || condition1 && condition2 );  // Q: Why does operator precedence render this expression useless?
  // Оператор && має вищий пріоритет за ||
  print( alwaysTrue && condition1 || condition2 );
  print(condition1 != condition1);                  // Q: What is the difference between this and the following expression?
  print(condition2 = !condition2); // != - порівняння не дорівнює, !condition2 - інвертує condition2
  print( alwaysTrue && condition1 && condition2 );
  print( alwaysTrue || condition1 && condition2 );
  print( alwaysTrue && condition1 || condition2 );

  std::cout << '\n';
  print( false || 0b10 );     // Q: What is the difference between || and | ?
  print( false | 0b10 ); // || and | логічне і бітове
  printBinary( 0b1 & 0b10 );
  printBinary( 0b1 | 0b10 );
  printBinary( 0b1 && 0b10 ); // Q: Are the operators && and || appropriate for integer types?
  // так 0 - false, інші - true
  printBinary( 0b1 || 0b10 );

  std::cout << "\nPlay with characters and strings:\n";
  print("a");                 // Q: Why is this expression two bytes at run time, the next only one?
  // "a" — це 2 байти ('a' + '\0'), 'a' — 1 байт
  print('a');

  char charArray[20];
  char* charPtr = charArray;
  charArray[19] = 0; // Make sure that our string is terminated with the null byte

  print(charArray);
  print(charArray[0] = 'a');
  print(charArray);
  print(charArray[1] = 98);
  print(charArray);
  print(charPtr);
  // FIXME: Ensure that no unexpected garbage is printed above
}
