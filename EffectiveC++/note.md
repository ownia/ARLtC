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