# WASM version of PMachine

Compiles to WASM, thus enabling Node.js and browser to run it.

## Before

This PMachine is for course project of Compilation Principles.

Based on [http:
Modifications:

+ fix compatibility problems
+ add instruction: pop (SP:=SP-1)
+ add instruction: mod (STORE[SP-1]:=STORE[SP-1]%STORE[SP], SP:=SP-1)
