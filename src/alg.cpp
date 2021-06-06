// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::string str = "";
  std::ifstream file(filename);
  if (!file) {
    std::cout « "Reading file error!" « std::endl;
    return tree;
  }
  char diff = 'a' - 'A';
  while (!file.eof()) {
    char sym = file.get();
    if (((sym >= 'a') && (sym <= 'z')) || ((sym >= 'A') && (sym <= 'Z'))) {
      if ((sym >= 'A') && (sym <= 'Z')) {
        sym += diff;
      }
      str += sym; }
    else if (str != "") {
      tree.add(str);
      str = "";
    }
  }
  file.close();
  return tree;
}
