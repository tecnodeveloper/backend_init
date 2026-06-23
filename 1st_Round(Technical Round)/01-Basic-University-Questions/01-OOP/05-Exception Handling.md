# Exception Handling 

**Exception handling** in C++ is a mechanism to handle **runtime errors** (unexpected situations) in a controlled way, preventing program crashes.

---
## Mental Model

Think of exception handling like a **safety net**:

- Code runs normally
- If something goes wrong → control jumps to handler
- Program recovers instead of crashing
- It allows you to separate **error-handling code** from normal logic.

---

## Core Syntax 

```javascript
try {
  // risky code thow error to catch block
} catch (error) {
  // handle error
} finally {
  // always runs (optional)
}
```

---

## C++ Equivalent Keywords

- `try` → block of code to monitor
- `throw` → signal an error
- `catch` → handle the error

---

## Step-by-Step Execution

1. Code enters `try` block    
2. Error condition detected
3. `throw` is executed
4. Control jumps to `catch`
5. Error is handled


---

## Key Points

- `try` → risky code
- `throw` → generate error
- `catch` → handle error

---

## Comparison: Exceptions vs Error Codes

|Feature|Exceptions|Error Codes|
|---|---|---|
|Readability|High|Low|
|Flow control|Automatic|Manual|
|Error handling|Centralized|Scattered|

---

### Common Questions:

- What is exception handling?
- What happens when exception is thrown?
- What is stack unwinding?
- Can constructors throw exceptions?

---

## Interview Summary

- Exception handling manages runtime errors
- Uses `try`, `throw`, `catch`
- Prevents crashes and improves reliability
- Works with RAII for automatic cleanup

---

## Final Mental Model

- `try` → “attempt this”
- `throw` → “something went wrong”
- `catch` → “handle the problem”