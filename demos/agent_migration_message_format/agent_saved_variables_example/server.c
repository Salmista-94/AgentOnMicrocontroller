/* File: agent_saved_variables_example/server.c */

#include <stdio.h>
#include <libmc.h>

#ifdef _WIN32
#include <windows.h>
#endif

int main() 
{
  MCAgency_t agency;
  int local_port = 5051;
  
  agency = MC_Initialize(local_port, NULL);

  MC_MainLoop(agency);

  MC_End(agency);
  return 0;
}
