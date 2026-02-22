# Quick Guide: How to Run Your Parking Lot Project

## **Step 1: Adding New Files**

When you create a new file (`.hpp` or `.cpp`), you need to tell the build system about it.

### Files you might add:
- `mynewclass.hpp` - Class definition
- `mynewclass.cpp` - Class implementation  
- `mynewclass_statics.cpp` - Static member initialization

### Where to save them:
```
src/
├── mynewclass/
│   ├── mynewclass.hpp
│   ├── mynewclass.cpp
│   └── mynewclass_statics.cpp
```

---

## **Step 2: Update the Build Task**

After adding new files, you MUST update the build configuration.

1. Open `.vscode/tasks.json` file (in your VS Code)
2. Find this section:
```json
"args": [
    "-std=gnu++14",
    "-fcolor-diagnostics",
    "-fansi-escape-codes",
    "-g",
    "main.cpp",
    "vehicle/vehicle.cpp",
    "vehicle/vehicle_statics.cpp",
    "parking/parkinglot.cpp",
    "parking/parkinglot_statics.cpp",
    "ticket/ticket_statics.cpp",
    "-o",
    "main"
],
```

3. Add your new `.cpp` files to this list:
```json
    "ticket/ticket_statics.cpp",
    "mynewclass/mynewclass.cpp",           // ADD THIS
    "mynewclass/mynewclass_statics.cpp",   // ADD THIS
    "-o",
```

---

## **Step 3: Click to Compile and Run**

### **Option A: Using the Build Button (Recommended)**

1. Look at the **TOP RIGHT** of VS Code
2. Click the **▶ (Play) button** or dropdown arrow next to it
3. The build will compile and show output in the terminal below

### **Option B: Using Keyboard Shortcut**

1. Press **`Shift + Cmd + B`** on Mac
2. Select **"Build & Run Parking Lot"** from dropdown
3. Wait for compilation to finish

### **Option C: Manual Terminal Command**

If the above doesn't work, open a terminal and run:
```bash
cd /Users/abhishek/projects/url_shortner/src && /usr/bin/clang++ -std=gnu++14 -fcolor-diagnostics -fansi-escape-codes -g main.cpp vehicle/vehicle.cpp vehicle/vehicle_statics.cpp parking/parkinglot.cpp parking/parkinglot_statics.cpp ticket/ticket_statics.cpp mynewclass/mynewclass.cpp mynewclass/mynewclass_statics.cpp -o main && ./main
```

---

## **Step 4: View the Output**

After clicking build/run:

1. Look at the **BOTTOM** of VS Code
2. You should see a **Terminal panel** with output:
```
parking number is 1
Vehicles created successfully!
```

If you don't see it:
- Press **`Cmd + `` (backtick)** to open terminal
- Or go to **View → Terminal**

---

## **Example: Adding a New Class Called `Report`**

### 1. Create files:
- `src/report/report.hpp`
- `src/report/report.cpp`
- `src/report/report_statics.cpp`

### 2. Update `tasks.json`:
Add these lines in the `"args"` array:
```json
"report/report.cpp",
"report/report_statics.cpp",
```

### 3. Click build button or press `Shift+Cmd+B`

### 4. Check output in terminal at bottom

---

## **Quick Checklist**

When adding a new file:
- ✅ Create `.hpp` with `#ifndef` guards
- ✅ Create `.cpp` with implementation
- ✅ Create `_statics.cpp` if you have static members
- ✅ Add all `.cpp` files to `tasks.json` args
- ✅ Build with button or `Shift+Cmd+B`
- ✅ Check terminal for output

---

## **If You Get Errors**

1. **Check the terminal** - it shows what's wrong
2. **Read the error message** - it tells you the file and line
3. **Common errors:**
   - `file not found` → File path in tasks.json is wrong
   - `undefined reference` → Forgot to add `_statics.cpp` file
   - `no matching constructor` → Wrong parameters in function call

---

## **Your Current Build Command in tasks.json**

```json
"args": [
    "-std=gnu++14",
    "-fcolor-diagnostics",
    "-fansi-escape-codes",
    "-g",
    "main.cpp",
    "vehicle/vehicle.cpp",
    "vehicle/vehicle_statics.cpp",
    "parking/parkinglot.cpp",
    "parking/parkinglot_statics.cpp",
    "ticket/ticket_statics.cpp",
    "-o",
    "main"
]
```

This is what gets executed when you click the build button!
