# [Export Maps](https://accu.org/index.php/journals/1372)

When exporting symbols froma shared library, the GNU ELF shared library
linker behaves in a significantly different way to the MS linker.
On windows, **nothing** is exported from a DLL unless the programmer
explicitly requests it. The GNU ELF linker, on the other hand, exports
**everything** by default.


