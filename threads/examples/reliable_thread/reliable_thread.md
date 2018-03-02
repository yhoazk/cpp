In this example, the thread finishes safely, this is due to the call of the
join function.

If the join is not incuded, the progra finishes as soon as it reaches the end of
the main function, it doesn]t matter what are the threads doing

This has an important effect, **if you want a thread to be done at certain part
of the code, we must wait for it**
Also, we must be sure that all the threads have finished before leaving the
program, this is also important if the thread has access to local variables
we want the thread to have finished before the local variable goes out of scope.
