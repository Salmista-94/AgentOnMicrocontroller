/* File: multi_task_example/client.c */

#include <stdio.h>
#include <libmc.h>

int main() 
{
  MCAgency_t agency;
  MCAgencyOptions_t options;
  MCAgent_t agent;
  int dim;
  double *data;
  int i, j, size;
  int local_port=5050;

  MC_InitializeAgencyOptions(&options);
  MC_SetThreadOff(&options, MC_THREAD_CP); /* Turn off command prompt */
  agency = MC_Initialize(local_port, &options);

  /* Note: The third argument of the following function may also be a
     valid IP address in the form of a string. i.e. 192.168.0.1 */
  MC_SendAgentFile(agency, "test.xml");

  /* Wait for return-agent arrival signal */
  MC_WaitSignal(agency, MC_RECV_RETURN);

  /* Make sure we caught the correct agent */
  agent = MC_FindAgentByName(agency, "mobagent3");
  if (agent == NULL) {
    fprintf(stderr, "Did not receive correct agent. \n");
    exit(1);
  }

  /* Print relevant information */
  printf("%d tasks.\n", MC_GetAgentNumTasks(agent) );
  for (i = 0; i < MC_GetAgentNumTasks(agent); i++) {
    dim = MC_AgentReturnArrayDim(agent, i);
    data = (double*)MC_AgentReturnDataGetSymbolAddr(agent, i);
    size = MC_AgentReturnArrayNum(agent, i);
    printf("Task: %d\n", i);
    printf("dim is %d\n", dim);
    printf("Size: %d\n", size);
    printf("Data elements: ");
    for (j = 0; j < size; j++) {
      printf("%f ", data[j]);
    }
    printf("\n\n");
  }

  /* We must reset the signal that we previously caught with the 
   * MC_WaitSignal() function with MC_ResetSignal() */
  MC_ResetSignal(agency);

  MC_End(agency);
  return 0;
}
