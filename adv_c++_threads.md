# Advanced Concepts of Multithreading in C++


### The humble debugger:

In `gcc` the debug information is controlled with the `-g` flag and a number
describing the level of desired debug information.

* `-g0`: No debug information
* `-g1`: Minimal information on external variables and function description
* `-g2`: All informaion including macro definitions

### Dynamic Analysis tools

##### Valgrind

The dynamic tools are used for analysis of:
* Memory usage
    * Memory Leaks
    * Illegal reads and writes
    * Allocation/Deallocation
* Leaks
* Diagnose threading issues

Valgrind os focused on POSIX threads, and does not work on windows.

###### Memcheck

Memcheck is the default tool in Valgrind, this tool reports the next potential
issues:

- Accessing memory outside of allocated bounds
- Use of undefined values
- improper freeing of heap memory
    - Double `free`
- Mismatched use of `C` and `C++` memory handling
- Overlaping source and destination pointers
- Passing of an invalid value as the size parameter of `malloc` or similar
- Memory leaks

```
$ valgrind --log-file=<logname>.log --track-origins=yes --read-var-info=yes --leak-check=full ./<app>
```

Memcheck reports any potential issues it finds:

* Definitely lost
* Indirectly lost
* Possibly lost

###### Helgrind

The purpose of Helgrind is to detect issues with synchronization implelemtations
within a Multithreaded application. It can detect wrongful use of POSIX threads,
potential deadlock issues due to wrong locking order as well as data races.

```
valgrind --tool=helgrind --read-var-info=yes --log-file=<logname>.log  ./app
```


Are boolean operations atomic? 

###### DRD

Similar to helgrind, also detects issues with threading and synchronization.
Main ways in which DRD differs fron Helgrind:

* Uses ess memory
* DRD doesn't detect locking order violations
* DRD supports detached threads

```
valgrind --tool=drd --log-file=<drd>.log --read-var-info=yes ./<app>
```

In order to use `C++11` std::thread we need to add some code to the common header
or at the start of every src file which uses threads:

```cpp
#include <valgrind/drd.h>

#define _GLIBCXX_SYNCRONIZATION_HAPPENS_BEFORE(addr)
ANNOTATE_HAPPENS_BEFORE(addr)
#define _GLIBCXX_SYNCHRONIZATION_HAPPENS_AFTER(addr)
ANNOTATE_HAPPENS_AFTER(addr)
```

From the src code of gcc `gcc/libstc++-v3/src/c++11/thread.cc` copy the 
implementation of the `execute_native_thread_routine` and the 
`thread::_M_start_thread` in a binary which is linked with the application
and the snippet mentioned before in that binary.



### Testing

#### Proper multithreading

Guides to prevent deadlocks:

- Try to never hold more than one lock at time
- Release any held locks as soon as possible 
- When holding mutliple locks mind their order

Procedure to get data shared and protected by a lock:

1. Lock the mutex
2. Copy relevant data
3. Release the lock

Guidelines to prevent data races:

- Never write to an unlocked, non-atomic, and shared resource
- Never read from and unlocked, non-atomic, and shared resource
- Write or read has to be thread-safe

#### Mutexes, Locks and Threads

General rules:
- Ensure that threads wait for mutexes and similar locks as less as possible
- Use conditional variables or timers for longer waiting periods
    - Differing in the way that they use mutexes
- Regular mutex
- R/W lock
* Remaphore
* Recursive mutex or lock


Threads:

The mina adv - customized behavior
- promise:
    - One send in a task to run and at the end
    - Gets the result out of a future instance

The best approach is to learn threads and synchronizaion mechanisms, consider
using:

* Promise
* Packaged task
* Full-blown thread

Consider that threads use templates heavily and this complicates the debugging.

**Compare and swap**

**Test and set**


**Static members**:

There is no warranty on the initialization order of the static members

```cpp
class Foo{
    static std::map<int, std::string> strings;
    static std::string oneString;

public:
    static void init(int a, std::string b, std::string c){
        strings.insert(std::pair<int, std::string>(a,b));
        oneString = c;
    }
};

std::map<int, std::string Foo:Strings;
std::string Foo::oneString;

class Bar{
    static std::string name;
    static std::string initName();

public:
    void init();
};

std::string Bar::name = Bar::initName();

std::string Bar::initName()·{
    Foo::init(1,"A", "B"); // here lays the problem
    return "Bar";
}

class Foo {
    static std::map<int, std::string>& string();
    static std::string oneString;
    public:
    static void init(int a, std::string b, std::string c){
        static std::map<int, std::string> stringsStatic = Foo::strings();
        stringStatic.insert(std::pair<int, std::string>(a,b));
        oneString = c;
    }
};

std::string Foo::oneString;

std::map<int, std::string>& Foo::strings(){
    static std::map<int, std::strings>* stringStatic = new std::map<int, std::string>();
    return *stringStatic;
}
```

The initializaion order of static varibles is random, leading to non-deterministic
behaviour, the solution is basically kame the initialization explicit
