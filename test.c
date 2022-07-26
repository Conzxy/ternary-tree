#include "ternary_tree.h"

#include <stdio.h>
#include <stddef.h>
#include <string.h>

void print_str(char const *str) {
  printf("%s\n", str);
}

#define CHECK_SEARCH(root, str) do {\
  char *res = ternary_search(root, str); \
  if (res == NULL || strcmp(res, str)) \
    printf("Not expect\n"); \
} while (0) 

void test_mini() {
  TernaryNode* root = NULL;
  puts(__func__); 
  ternary_add(&root, "stradd", false);
  ternary_add(&root, "strget", false);
  ternary_add(&root, "strdel", false);
  ternary_add(&root, "strset", false);
  ternary_add(&root, "help", false); 
  ternary_add(&root, "exit", false);
  ternary_add(&root, "setadd", false);
  ternary_add(&root, "str", false);
  ternary_add(&root, "stradd", false);
  ternary_add(&root, "s", false);
  CHECK_SEARCH(root, "stradd");
  CHECK_SEARCH(root, "strget");
  CHECK_SEARCH(root, "strdel");
  CHECK_SEARCH(root, "strset");
  CHECK_SEARCH(root, "help");
  CHECK_SEARCH(root, "exit");
  CHECK_SEARCH(root, "setadd");
  puts("search prefix: str");
  ternary_search_prefix(root, "str", &print_str);
  puts("search prefix: stradd");
  ternary_search_prefix(root, "stradd", &print_str);
  
  puts("search prefix: empty");
  ternary_search_prefix(root, "", &print_str);
  
  puts("search prefix: strx");
  ternary_search_prefix(root, "strx", &print_str);
  
  puts("remove: stradd");
  ternary_remove(&root, "stradd");
  ternary_search_prefix(root, "str", &print_str);

  ternary_free(&root);
}

int main() {
  printf("TernaryNode size = %zu\n", sizeof(TernaryNode));
  test_mini();
}
