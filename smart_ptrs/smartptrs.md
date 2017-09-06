# Smart pointers

[src](http://www.informit.com/articles/article.aspx?p=25264)


Smart pointers are C++ objects that simulate built-in pointers by implementing
the `operator->` and the unary `operator*`. In addition to supporting syntax and
semantics, smart pointers often perform other tasks as memory management or
locking  tasks in the background, this way freeing the application from
carefully managing the lifetime of pointed-to objects.
