/*
 * inline function is a function that is expanded in line when it is called.
 * This substitution is performed by the C++ compiler at compile time. Inline function may increase efficiency if it is small.
 *
 * inline return-type function-name(parameters){
   }
 *
 * Remember, inlining is only a request to the compiler, not a command. Compiler can ignore the request for inlining. Compiler
 * may not perform inlining in such circumstances like:
 * -> If a function contains a loop. (for, while, do-while)
 * -> If a function contains static variables.
 * -> If a function is recursive.
 * -> If a function return type is other than void, and the return statement doesn’t exist in function body.
 * -> If a function contains switch or goto statement.
 */

/*
 *
 * Inline functions provide following advantages:
 * -> Function call overhead doesn’t occur.
 * -> It also saves the overhead of push/pop variables on the stack when function is called.
 * -> It also saves overhead of a return call from a function.
 * -> When you inline a function, you may enable compiler to perform context specific optimization on the body of function. Such
 *    optimizations are not possible for normal function calls. Other optimizations can be obtained by considering the flows of
 *    calling context and the called context.
 * -> Inline function may be useful (if it is small) for embedded systems because inline can yield less code than the function
 *    call preamble and return.
 */

/*
 * Inline function disadvantages:
 * -> The added variables from the inlined function consumes additional registers, After in-lining function if variables number
 *    which are going to use register increases than they may create overhead on register variable resource utilization. This
 *    means that when inline function body is substituted at the point of function call, total number of variables used by the
 *    function also gets inserted. So the number of register going to be used for the variables will also get increased. So if
 *    after function inlining variable numbers increase drastically then it would surely cause an overhead on register
 *    utilization.

 * -> If you use too many inline functions then the size of the binary executable file will be large, because of the duplication
 *    of same code.

 * -> Too much inlining can also reduce your instruction cache hit rate, thus reducing the speed of instruction fetch from that
 *    of cache memory to that of primary memory.

 * -> Inline function may increase compile time overhead if someone changes the code inside the inline function then all the
 *    calling location has to be recompiled because compiler would require to replace all the code once again to reflect the
 *    changes, otherwise it will continue with old functionality.

 * -> Inline functions may not be useful for many embedded systems. Because in embedded systems code size is more important
 *    than speed.

 * -> Inline functions might cause thrashing because inlining might increase size of the binary executable file. Thrashing in
 *    memory causes performance of computer to degrade.
 *
 */

/*
 * It is also possible to define the inline function inside the class. In fact, all the functions defined inside the class are
 * implicitly inline.
 *
 * If you need to explicitly declare inline function in the class then just declare the function inside the class and define it
 * outside the class using inline keyword.
 */

/*
 * The preprocessor replace all macro calls directly within the macro code. It is recommended to always use inline function
 * instead of macro. According to Dr. Bjarne Stroustrup the creator of C++ that macros are almost never necessary in C++ and
 * they are error prone. There are some problems with the use of macros in C++. Macro cannot access private members of class.
 * Macros looks like function call but they are actually not.
 *
 */