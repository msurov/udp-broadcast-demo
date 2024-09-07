#include <cppmisc/traces.h>
#include <cppmisc/timing.h>
#include <networking/udp_broadcast.h>


int main(int argc, char **argv)
{
  if (argc != 3)
  {
    printf("format: subscriber boradcast_ip local_port\n"
           "example:\n"
           "    subscriber 127.255.255.255 9597\n"
    );
    return -1;
  }

  UDPBCSubscriber sub(argv[1], std::atoi(argv[2]));
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
