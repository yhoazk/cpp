# Futures and promises

The intention of futures and promises is to help to manage the langecy and unpredictability of IO operations. Concurrency is both decomposing and composing the program from the parts that work well
individially and together. It is in the composition of connected and multicore componentes where
todays c++ libraries are still lacking.

The functionality of `std::future` offers a partial solution by allowing the separation of the initiation
of an opoeration and the act of waiting for its result; however the act of waiting is synchronous.

Possible use of sync wait using futures:

```cpp
#include <future>
using namespace std;

int main() {
    future<int> f = async([]() {return 42;});

    int result = f.get(); // migth block
}
```

Futures and promises are high level concurrency constructs in the std lib to support async
programming. 
- A future can be viewed as a placeholder for a computation that will eventually
  become available.  
- A promise is a form of future where the result can be explicitly provided by 
  the programmer.


By default C++ futures are not shareable and therefore cannot be copied, hence a move is needed.
C++17 does not provide any executors like thread pools. By default is upto the implementation
if `std::async()` spawns a new thread or not. The programmer migth pass the lauch policy manually
to `std::async()` to specify whether it should always spawn a new thread or let the result be
evaluated lazily by a requesting thread. This call migth be expensive since each thread has its
own stack and are slower that for lightweight tasks which are also missing in c++17.

Additionally C++17 lacks operations to compose futures. The user is required to write lots 
of boilder plate code. This is error prone and obfuscate the program logic.


### Boost.Thread futures

Boost provies executors such as a basic thread pool, which improves the performance compared
to cüü17 futures. Another improvement is the presence of the `then` method via which we can
feed the result of one future to another future. Thus avoid a second `async` call.

### Folly futures

Folly is another C++ library supporting futures and promises. Folly also implements executors
which are provided via the Wrangle library. The `via` function corresponds to `async`. Folly
has two further improvements compared to boost. First folly's `then` takes the result of the
future whereas Boost `then` expects the future itself. Thus the call to get can be avoided
leading to better readeability in the program text. A second improbement is the `filter` method
which acts like a guard and takes an argument a predicate. If the predicate holds, the future
will be passed through. Otherwise ther resulting `future` fails
