# Interface Segregation

No client should be forced to depend on methods that it does not use.

Example:

We could implement a multifunctional device, so we create it's interfaces:

```cpp
struct Document;
struct IMultifunctional{
    virtual void print(std::vector<Document&> docs) = 0;
    virtual void scan(std::vector<Document&> docs) = 0;
    virtual void fax(std::vector<Document&> docs) = 0;
};
```

This implementation has the problem that any one that needs only a printer
will need to add the functionality for all the other method, even a dummy one.

The solution is to use the decorator pattern:


```cpp
struct IPrinter{
    virtual void print(vector<Document&> docs)
};

struct IScanner{
    virtual void scan(vector<Document&> docs) = 0;
}

struct IMultifunctional : IPrinter, IScanner {
    IPrinter printer;
    IScanner scanner;
    void print(vector<Document&> doc) override{};
    void scan(vector<Document&> doc) override{};
}
```