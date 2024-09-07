#include <cppmisc/traces.h>
#include <cppmisc/timing.h>
#include <networking/udp_broadcast.h>


int main(int argc, char **argv)
{
  UDPBCSubscriber sub("127.255.255.255", 9597);
  while (true)
  {
    char buf[1024] = "";
    int n = sub.get_last(buf, sizeof(buf));
    if (n == 0)
    {
      printf("nothing to read\n");
    }
    else
    {
      printf("read: %d, %s\n", n, buf);
    }
    sleep_sec(0.1);
  }
  return 0;
}
