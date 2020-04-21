# note

- **Accustoming Yourself to C++**

01. View C++ as a federation of languages.
02. Prefer consts, enums, and inlines to #defines.
03. Use const wherever possible.
04. Make sure that objects are initialized before they're used.
	(Use member initialization list instead of assignments)

- **Constructors, Destructors, and Assignment Operators**

05. Know what functions C++ silently writes and calls.
06. Explicitly disallow the use of complier-generated functions you do not want.
07. Declare destructors virtual in polymorphic base classes.
08. Prevent exceptions from leaving destructors.
09. Never call virtual functions during construction or destruction.
10. Have assignment operators return a reference to \*this.
11. Handle assignment to self in operator=.
12. Copy all parts of an object.

- **Resource Management**

13. Use objects to manage resources.
	(C++11 use unique_str replace auto_ptr)
	(Rvalue reference)
14. Think carefully about copying behaviors in resource-managing classes.
	(RAII: Resource Acquisition Is Initialization)
15. Provide access to raw resource in resource-managing classes.
16. Use the same form in corresponding uses of new and delete.
17. Store newed objects in smart pointers in standalone statements.

- **Designs and Declarations**

18. Make interfaces easy to use correctly and hard to use incorrectly.
	(cross-DLL problem)
19. Treat class design as type design.
	(type conversion operators)
	(non-explicit-one-argument)
20. Prefer pass-by-reference-to-const to pass-by-value
21. Don't try to return a reference when you must return an object.
22. 