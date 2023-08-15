# Shellcode Wrapper POC
**This is an incomplete and still in development Proof of Concept**

### Overview
This project is meant to check wether it is possible to dynamically decode and execute shellcode using shellcode.

### How does it work?
This project is made of 3 main parts:
- An encoding algorithm.
- A decoder & encoder.
- An assembly implementation.

As of now the first two parts are complete, I only have to write this and implement it in ASM properly.

### How does the encoding process work?
The encoding process is pretty cool, and is best explained by explaining the deocding process, it is also easier to understand visually, so that's how I will choose to show it.

This will be a simple exmaple showing the steps of decoding a simple message, using an 8 byte long piece of text encoded in this algorithm, comprised of four blocks that have a length of 2 bytes each.

In the code, you have the ability to choose a block length and input your own text.

This is the input string: `48:45:04:09:03:6d:6e:21`, I will refer to it as S from now on.


|  step # | step result | explanation |
| :------:|:-----------:|:------------|
|    0    |`00:00:00:00:00:00:00:00`| We start by creating a blank block with the same length of the secret|
|    1    |`48:45:48:45:48:45:48:45`| Xor the first 2 bytes of S with our blank block|
|    2    |`48:45:4c:4c:4c:4c:4c:4c`| Xor the second block of S, so the 3rd and 4th bytes with our result, but we start xoring on at the 3rd byte of our previous result|
|    3    |`48:45:4c:4c:4f:21:4f:21`| We now xor from the 5th byte of our previous result, using the 5th and 6th byte of S|
|    4    |`48:45:4c:4c:4f:21:21:00`| For the last step, we xor the last chunk of bytes from S with the last chunk of bytes from our previous result!|

And that's it!

There are some improvements that can be made upon this process, however, my main focus is not on it, but on the idea of creating a piece of shellcode that can decode "itself" and run it.

### Todo
- [ ] Implement in assembly.

