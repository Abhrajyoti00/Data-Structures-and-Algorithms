#include <iostream>

int main() {
  int j = 5;
  
  // Loop with "~j"
  std::cout << "Loop with ~j:" << std::endl;
  while (~j) {
    std::cout << "j = " << j <<" ~j = "<<~j<< std::endl;
    --j;
  }
    std::cout << "Final ~j = " <<~j;
  j = 5; // Reset j to 5

  // Loop with !j
  std::cout << "\nLoop with !j:" << std::endl;
  while (!j) {
    std::cout << "j = " << j << std::endl;
    --j;
  }
  
  return 0;
}
