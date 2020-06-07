#include <fstream>
#include <iostream>
#include <string>

extern "C" {
#include <glob.h>
#include <unistd.h>
}

using namespace std;

int count_files(string pth) {
  fstream f{pth.c_str()};
  if (!f.is_open()) {
    return 0;
  }
  return 5;
}

int glob_test(const char *p) {
  glob_t gres;

  if (0 == glob(p, GLOB_ERR | GLOB_NOSORT, nullptr, &gres)) {
    // if(0 == glob(p, GLOB_ERR, nullptr, &gres)) {
    cout << "Number of files: " << to_string(gres.gl_pathc) << '\n';
    for (size_t fn = 0; fn < gres.gl_pathc; fn++) {
      cout << "File name: " << *gres.gl_pathv << '\n';
      gres.gl_pathv++;
    }
  } else {
    cerr << "Error reading: " << p << '\n';
  }
  if (gres.gl_pathc > 0) {
    // On RPi this call throws SIGSEGV 
    // Check https://sourceware.org/bugzilla/show_bug.cgi?id=22332
    // The function globfree seems to not be located in libc or the address is 
    // weird:
    // => 0x004012ce <+214>:   add.w   r3, r7, #8
    // 0x004012d2 <+218>:   mov     r0, r3
    // 0x004012d4 <+220>:   blx     0x401010 <globfree@plt>
    // 0x004012d8 <+224>:   movs    r3, #0 
    // Then inside globfree@plt
    // (gdb) disass
    // Dump of assembler code for function globfree@plt:
    // => 0x00401010 <+0>:     add     r12, pc, #0, 12
    // 0x00401014 <+4>:     add     r12, r12, #69632        ; 0x11000
    // 0x00401018 <+8>:     ldr     pc, [r12, #88]! ; 0x58
    // End of assembler dump.
    globfree(&gres);
  }
  return 0;
}

int main(int c, char **v, char **e) {
  if (c < 2) {
    cerr << "Pass the glob expression sorrounded by 's to avoid expansion \n";
    return 1;
  }

  // count_files("/root/workspace/");
  cout << v[0] << '\n';
  cout << v[1] << '\n';
  glob_test(v[1]);
}