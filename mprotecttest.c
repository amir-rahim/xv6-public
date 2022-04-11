#include "types.h"
#include "stat.h"
#include "user.h"
#include "mmu.h"

void
mprotectTest() 
{
  printf(1, "\nStart of mprotect(void* addr, int len) test!\n");

  int *value = (int*) sbrk(sizeof(int));

  printf(1, "\nCreated Value Address!\n");

  *value = 100;

  printf(1, "\nInitial Value: %d\n", *value);

  mprotect((void*) value, 1);

  printf(1, "\nWrite protected the value and about to attempt to change value!\nExpect a Page Fault below this!\n");

  *value = 5;

  printf(1, "\nShould not hit this part of the code. If we do, there is an error.\n");
}

int
main(int argc, char *argv[])
{
  mprotectTest();
  exit();
}