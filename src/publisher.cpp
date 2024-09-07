#include <cppmisc/traces.h>
#include <cppmisc/timing.h>
#include <networking/udp_broadcast.h>


int main(int argc, char **argv)
{
  if (argc != 4)
  {
    printf("format: publisher local_ip boradcast_ip destination_port\n"
           "example:\n"
           "    publisher 127.0.0.1 127.255.255.255 9597\n"
    );
    return -1;
  }
  UDPBCPublusher pub(argv[1], argv[2], std::atoi(argv[3]));
  for (int i = 1; i < 1000; ++ i)
  {
    char buf[64];
    int n = sprintf(buf, "msg %06d", i);
    bool ok = pub.send(buf, n, true);
    printf("status: %d\n", ok);
    sleep_sec(1.);
  }
  return 0;
}
