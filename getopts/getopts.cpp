#include <bits/stdc++.h>
#include <unistd.h>

/* bazel run with arguments: use the -- after all the bazel arguments are given */
/* compile with debug symbols -c dbg (fordebug not gdb) */
/* run gdb with in arguments --args <bin> <arg1> <arg2> */
int main(int argc, char const *argv[])
{
  int status{0};
  //int _argc = sizeof(argv)/sizeof(argv[0]);
  while ((status = getopt(argc, (char**)argv, "n:i:")) != EOF){
    switch (status)
    {
    case 'i':
      std::cout << "Option I: " << optarg << '\n';
      break;

    case 'n':
      std::cout << "Option N: " << optarg << '\n';
      break;

    default:
      break;
    }
  }

  return 0;
}
