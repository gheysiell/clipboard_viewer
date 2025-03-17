#include <Windows.h>
#include <stdio.h>

int main() {
  if (!OpenClipboard(NULL)) {
    printf("Failed to open clipboard.\n");
    return 1;
  }

  HANDLE data = GetClipboardData(CF_TEXT);
  if (data == NULL) {
    printf("No clipboard data available.\n");
    CloseClipboard();
    return 1;
  }

  char* text = (char*)GlobalLock(data);
  if (text == NULL) {
    printf("Failed to lock global memory.\n");
    CloseClipboard();
    return 1;
  }  

  printf("Contents: %s\n", text);

  GlobalUnlock(data);
  CloseClipboard();
  return 0;
}