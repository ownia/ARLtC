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
20. Prefer pass-by-reference-to-const to pass-by-value.
21. Don't try to return a reference when you must return an object.
22. Declare data members private.
23. Prefer non-member non-friend functions to member functions.
24. Declare non-member functions when type conversions should apply to all parameters.
25. Consider support for a non-throwing swap.
	(pimpl: pointer to implementation)

- **Implementations**
26. Postpone variable definitions as long as possible.
27. Minimize casting.
	(avoid cascading dynamic_casts)
28. Avoid returning "handles" to object internals.
	(dangling handles)
29. Strive for exception-safe code.
30. Understand the ins and outs of inlining.
31. Minimize compilation dependencies between files.
	(cascading compilation dependencies)
	(full and declaration-only forms)

- **Inheritance and Object-Oriented Design**

32. Make sure public inheritance models "is-a".
33. Avoid hiding inherited names.
	(name-hiding rules)
	(forwarding function)
34. Differentiate between inheritance of interface and inheritance of implementation.
	(invariant vs. specialization)
35. Consider alternatives to virtual functions.
	(use Non-Virtual Interface to achieve Template Method)
	(NVI: non-virtual interface)
	(use Function Pointers to achieve Strategy Method)
36. Never redefine an inherited non-virtual function.
37. Never redefine a function's inherited default parameter value.
38. Model "has-a" or "is-implemented-in-terms-of" through composition.
39. Use private inheritance judiciously.
	(EBO: empty base optimization)
40. Use multiple inheritance judiciously.
	(MI: multiple inheritance)

- **Templates and Generic Programming**

41. Understand implicit interfaces and compile-time polymorphism.
42. Understand the two meanings of typename.
43. Know how to access names in templatized base classes.
44. Factor parameter-independent code out of templates.
	(commonality and variability analysis)
45. Use member function templates to accept "all compatible types."
46. Define non-member functions inside templates when type conversions are desired.
47. Use traits classes for information about types.
48. Be aware of template metaprogramming.
	(fractional dimensional exponents)
	(expression templates)
	(custom design pattern)
	(generative programming)

- **Customizing new and delete**

49. Understand the behavior of the new-handler
50. Understand when it makes sense to replace new and delete.
51. 