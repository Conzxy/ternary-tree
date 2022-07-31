#include "ternary_tree.h"

#include <stdio.h>
#include <stddef.h>
#include <string.h>

void print_str(char const *str, void *args) {
  printf("%s\n", str);
}

#define CHECK_SEARCH(root, str) do {\
  char *res = ternary_search(root, str); \
  if (res == NULL || strcmp(res, str)) \
    printf("Not expect\n"); \
} while (0) 

#define CHECK_REMOVE(root, str) do {\
  bool res = ternary_remove(&root, str); \
  if (res) \
    printf("Remove successful\n"); \
  else \
    printf("Remove failure\n"); \
} while (0)

#define PRINT_FUNCTION\
  printf("===== %s =====\n", __func__)

void test_mini() {
  TernaryNode* root = NULL;
  PRINT_FUNCTION;
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
  ternary_search_prefix(root, "str", &print_str, NULL);
  puts("search prefix: stradd");
  ternary_search_prefix(root, "stradd", &print_str, NULL);
  
  puts("search prefix: empty");
  ternary_search_prefix(root, "", &print_str, NULL);
  puts("search prefix: s");
  ternary_search_prefix(root, "s", &print_str, NULL);
  
  puts("search prefix: strx");
  ternary_search_prefix(root, "strx", &print_str, NULL);
  
  puts("remove: stradd");
  ternary_remove(&root, "stradd");
  ternary_search_prefix(root, "str", &print_str, NULL);
  
  puts("remove: strset");
  ternary_remove(&root, "strset");
  ternary_search_prefix(root, "str", &print_str, NULL);
  
  puts("remove: xxx");
  CHECK_REMOVE(root, "xxx"); 

  ternary_free(&root);
}

void test_large() {
  PRINT_FUNCTION;
  char *arr[] = {
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "a",
    "b",
    "c",
    "d",
    "e",
    "f",
    "g",
    "00",
    "10",
    "20",
    "30",
    "40",
    "50",
    "60",
    "70",
    "80",
    "90",
    "a0",
    "b0",
    "c0",
    "d0",
    "e0",
    "f0",
    "g0",
    "01",
    "11",
    "21",
    "31",
    "41",
    "51",
    "61",
    "71",
    "81",
    "91",
    "a1",
    "b1",
    "c1",
    "d1",
    "e1",
    "f1",
    "g1",
    "02",
    "12",
    "22",
    "32",
    "42",
    "52",
    "62",
    "72",
    "82",
    "92",
    "a2",
    "b2",
    "c2",
    "d2",
    "e2",
    "f2",
    "g2",
    "03",
    "13",
    "23",
    "33",
    "43",
    "53",
    "63",
    "73",
    "83",
    "93",
    "a3",
    "b3",
    "c3",
    "d3",
    "e3",
    "f3",
    "g3",
    "04",
    "14",
    "24",
    "34",
    "44",
    "54",
    "64",
    "74",
    "84",
    "94",
    "a4",
    "b4",
    "c4",
    "d4",
    "e4",
    "f4",
    "g4",
    "05",
    "15",
    "25",
    "35",
    "45",
    "55",
    "65",
    "75",
    "85",
    "95",
    "a5",
    "b5",
    "c5",
    "d5",
    "e5",
    "f5",
    "g5",
    "06",
    "16",
    "26",
    "36",
    "46",
    "56",
    "66",
    "76",
    "86",
    "96",
    "a6",
    "b6",
    "c6",
    "d6",
    "e6",
    "f6",
    "g6",
    "07",
    "17",
    "27",
    "37",
    "47",
    "57",
    "67",
    "77",
    "87",
    "97",
    "a7",
    "b7",
    "c7",
    "d7",
    "e7",
    "f7",
    "g7",
  };

  const size_t n = sizeof(arr) / sizeof(arr[0]);
  TernaryNode *root = NULL;
  for (size_t i = 0; i < n; ++i)
    ternary_add(&root, arr[i], false);

  puts("search prefix: a");
  ternary_search_prefix(root, "a", &print_str, NULL);
  
  ternary_free(&root);
}

void test_remove() {
  PRINT_FUNCTION;
  TernaryNode *root = NULL;
  ternary_add(&root, "a", false);
  ternary_add(&root, "b", false);
  CHECK_REMOVE(root, "a");
  CHECK_REMOVE(root, "b");
  
  ternary_free(&root);
}

int main() {
  printf("TernaryNode size = %zu\n", sizeof(TernaryNode));
  test_mini();
  test_large();
  test_remove(); 
}
