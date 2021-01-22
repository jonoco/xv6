#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"
#include "pstat.h"


void
getpinfo_test(void)
{
  struct pstat proc_stats;

  printf(1, "getpinfo test\n");

  getpinfo(&proc_stats);

  for (int i = 0; i < NPROC; i++)
  {
    printf(1, "pid: [%d] in-use: [%d] h-ticks: [%d] l-ticks: [%d]\n",
      proc_stats.pid[i],
      proc_stats.inuse[i],
      proc_stats.hticks[i],
      proc_stats.lticks[i]
    );
  }

  printf(1, "getpinfo test OK\n");
}

int
main(void)
{
  getpinfo_test();
  exit();
}
