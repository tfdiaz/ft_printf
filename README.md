# Replication of printf
This project as the title denotes is to replicate certain aspects of printf. This was one of the earlier projects in [42 Silicon Valley](42.us.org) I completed in C. The purpose was to understand:
* Varadic Functions
* Organization!
* Conversions and Flag Handling

## Technical Notes
I've recently updated some of the functionally to increase speed. The old implementation had one write call per character. This is wildly unnecessary as I pass around the length of the string to print out in a simple vector structure.
```C
    write(1, vec->str, vec->len);
```
Unfortunately, this change forces the way I was handling null characters. As a result I had to do some shifting around.

All the following are handled:

* *Conversions* **sSpdDioOuxXcC**
* *Flags* **hh, h, l, ll, j, z, \*,**
* *Precision*
* *Minimum field-width*

 As a final note, don't use this printf and just use the standard printf!