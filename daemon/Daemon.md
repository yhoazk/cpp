# Dämon


## Process Groups

### `setsid()`

The `unistd.h/setsid()` function creates a session and sets the process group ID.
If the calling process is not the leader it creates a new session.


#### Process Group

In POSIX conformant OSs a process group is a set of processes which, among other
other things, are used to control the distribution of a signal. When a signal is
delivered to a group, every process in that group received the signal.

A session is a group of one or more process groups. Process groups are not 
allowed to change sessions nor a process grp is allowed to create a process grp
which is part of another session. 

## 