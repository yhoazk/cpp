This example demostrates how the thread fails if the thread is not finished.
A join is needed.

This example, in linux at least, crashes
```
./reliable_thread.exe
terminate called without an active exception
```

Why is this crashing?

This is beacause at the end of main `t` goes out of scope and the
thread destructor is called. Inside the destructor a check is
performed to see if t is joinable. A joinable thread is a thread
that has not been detached.

There is a way to detach the thread and let it continue after the
execution of main finishes. See Detached thread:
