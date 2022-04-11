#include "types.h"
#include "stat.h"
#include "user.h"
#include "mmu.h"

void
munprotectTest() 
{
  printf(1, "\nStart of munprotect(void* addr, int len) test!\n");

  int *value = (int*) sbrk(sizeof(int));

  printf(1, "\nCreated Value Address!\n");

  *value = 100;

  printf(1, "\nInitial Value: %d\n", *value);

  mprotect((void*) value, 1);
  munprotect((void*) value, 1);

  printf(1, "\nWrite now allowed for the value and about to attempt to change value!\n");

  *value = 5;

  printf(1, "\nWe should hit this part of the code. Old Value: 100. New Value: %d.\n", *value);
}

int
main(int argc, char *argv[])
{
  munprotectTest();
  exit();
}
