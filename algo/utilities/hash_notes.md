# Hasing algorithms

## Cryptographic hash function

A cryptographic hash function is something that mecanically takes an arbitrary
amount of input and produces an "unpredictable" output of fixed size. The
unpredictableness isn't in the operation it self. Every time a given input is
used the same output will result. It means that you cannot easily craft an input
to produce a wanted output, or similarly guess what input produced a given
output.

## Non-cryptographic hash functions

This hash functions are used for high-speed hash tables or other data structures
Those are desinged to produce high enough quality statistical randomness to
fullfil their purpose. However they are not designed to defeat a determined
adversary.

## Hash vs Checksum

Some checksums provide error detection/correcting properties.