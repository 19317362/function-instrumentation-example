#include <stdio.h>
#include <time.h>

static FILE* fpTrace = NULL;

void
__attribute__ ((constructor))
traceBegin
(
  void
)
{
  fpTrace = fopen("trace.out", "w");
}

void
__attribute__ ((destructor))
traceEnd
(
  void
)
{
  if( NULL != fpTrace )
  {
    fclose(fpTrace);
  }
}

void
__cyg_profile_func_enter
(
  void* func,
  void* caller
)
{
  if(NULL != fpTrace)
  {
    fprintf(fpTrace, "e %p %p %lu\n", func, caller, time(NULL));
  }
}

void
__cyg_profile_func_exit
(
  void* func,
  void* caller
)
{
  if(NULL != fpTrace)
  {
    fprintf(fpTrace, "x %p %p %lu\n", func, caller, time(NULL));
  }
}

