# operator overloading

Any of the next operators can be overloaded:
 - `+`
 - `-`
 - `*`
 - `/`
 - `%`
 - `ˆ`
 - `&`
 - `|`
 - `~`
 - `!`
 - `=`
 - `<`
 - `>`
 - `+=`
 - `-= `
 - `*=`
 - `/=`
 - `%=`
 - `ˆ=`
 - `&=`
 - `|=`
 - `<<`
 - `>>`
 - `>>=`
 - `<<=`
 - `==`
 - `!=`
 - `<=`
 - `>=`
 - `&&`
 - `||`
 - `++`
 - `--`
 - `,`
 - `->*`
 - `->`
 - `( )`
 - `[ ]`


* The operators `::`, `.`(member access), `.*`(member access through pointer to member), and `:?` (ternary conditional) cannot be overloaded.
* The operators `&&` and `||` loose short-circuit evaluation.
* The overload of `->` must either return a raw pointer or return an object
(by reference or by value), for which the operator `->` is in turn overloaded.
