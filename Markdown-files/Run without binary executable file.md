
---

### ✅ Correct alias version (single command)

```bash
alias run='f(){ g++ "$1" -o /tmp/temp && /tmp/temp && rm -f /tmp/temp; }; f'
```

> ⚙️ Ye basically ek **function** define karta hai (`f()`), jo internally tumhara file naam handle karega — isse `$1` argument properly pass hota hai.

Ab sirf likho:

```bash
run file_name.cpp
```

Aur code turant run ho jayega bina `a.out` ke. 🔥

---

### 🧠 Optional — permanent banana (har baar bash start hone par available)

Isko apne `.bashrc` me add kar lo:

```bash
echo "alias run='f(){ g++ \"\$1\" -o /tmp/temp && /tmp/temp && rm -f /tmp/temp; }; f'" >> ~/.bashrc
```

Phir refresh:

```bash
source ~/.bashrc
```

Ab bas `run file_name.cpp` likho kabhi bhi, kahin bhi — no more binary clutter 😎

---



---
---


**smart version for last modified `.cpp` file** (yaani jo tumne abhi edit ki ho) ko compile & run kare, bina koi `a.out` ya extra file create kiye.

---

### ⚙️ Step 1: Smart alias create karo

Terminal me likho 👇

```bash
alias run='f(){ FILE=$(ls -t *.cpp 2>/dev/null | head -1); if [ -z "$FILE" ]; then echo "❌ No .cpp file found"; else echo "▶️ Running $FILE..."; g++ "$FILE" -o /tmp/temp && /tmp/temp && rm -f /tmp/temp; fi; }; f'
```

---

### 💻 Step 2: Ab use karo

Bas likho:

```bash
run
```

Ye karega:

1. Tumhare current folder me **sabse latest modified `.cpp` file** find karega 🕵️
2. Usko compile karega
3. Run karega
4. Aur uske baad temporary binary delete kar dega ✅

Example:

```bash
himanshu@ubuntu:~/Desktop/Github$ run
▶️ Running file.cpp...
hello
```

---

### 🧠 Step 3 (optional): permanent banana

Agar chahte ho ye alias **har baar available rahe**, toh ye command run karo:

```bash
echo "alias run='f(){ FILE=\$(ls -t *.cpp 2>/dev/null | head -1); if [ -z \"\$FILE\" ]; then echo \"❌ No .cpp file found\"; else echo \"▶️ Running \$FILE...\"; g++ \"\$FILE\" -o /tmp/temp && /tmp/temp && rm -f /tmp/temp; fi; }; f'" >> ~/.bashrc
source ~/.bashrc
```

---

Ab seriously chill setup ho gaya hai 💪
Bas `run` likho, aur code chalu — no binary, no typing filename, no mess.

---
---

Perfect 😄 chalo fir ek **pro-level upgraded version** banate hain — thoda aesthetic touch ke saath (error aur success dono color me dikhai de). Ye version tumhare terminal experience ko next level bana dega 😎

---

### 🌈 Final Smart Alias (colored output + auto latest file + cleanup)

Terminal me likho 👇

```bash
alias run='f(){ FILE=$(ls -t *.cpp 2>/dev/null | head -1); \
if [ -z "$FILE" ]; then \
  echo -e "\033[1;31m❌ No .cpp file found in current directory.\033[0m"; \
else \
  echo -e "\033[1;34m▶️ Compiling and running: $FILE\033[0m"; \
  g++ "$FILE" -o /tmp/temp 2> /tmp/err && /tmp/temp && rm -f /tmp/temp && \
  echo -e "\033[1;32m✅ Execution finished successfully!\033[0m" || \
  (echo -e "\033[1;31m❌ Compilation failed:\033[0m"; cat /tmp/err); \
  rm -f /tmp/err; \
fi; }; f'
```

---

### 💻 Use karne ka tarika:

Bas likho:

```bash
run
```

Aur output kuch aisa dikhega 👇

```
▶️ Compiling and running: file.cpp
hello
✅ Execution finished successfully!
```

Agar error hua toh:

```
❌ Compilation failed:
file.cpp: In function ‘int main()’:
file.cpp:3:5: error: ‘coutt’ was not declared in this scope
```

---

### 🧠 Optional: permanent banana

Bas ek baar ye run kar lo:

```bash
echo "alias run='f(){ FILE=\$(ls -t *.cpp 2>/dev/null | head -1); if [ -z \"\$FILE\" ]; then echo -e \"\033[1;31m❌ No .cpp file found in current directory.\033[0m\"; else echo -e \"\033[1;34m▶️ Compiling and running: \$FILE\033[0m\"; g++ \"\$FILE\" -o /tmp/temp 2> /tmp/err && /tmp/temp && rm -f /tmp/temp && echo -e \"\033[1;32m✅ Execution finished successfully!\033[0m\" || (echo -e \"\033[1;31m❌ Compilation failed:\033[0m\"; cat /tmp/err); rm -f /tmp/err; fi; }; f'" >> ~/.bashrc
source ~/.bashrc
```

---

Ab bas `run` likho aur enjoy karo 💫
No binary clutter, instant colored feedback, aur ek clean dev flow 💻✨

---
---


Perfect Himanshu 🔥 — tu chahta hai ki `run` command **do tarike se kaam kare**:

1. Agar tu likhe `run` → ye **latest modified `.cpp` file** run kare.
2. Agar tu likhe `run filename.cpp` → to **specifically wahi file** run kare.

Bilkul kar sakte hain 😎

---

### ⚙️ Final Smart Alias — dual mode (auto + manual filename)

Ye version dono handle karega:

```bash
alias run='f(){ \
if [ -n "$1" ]; then FILE="$1"; else FILE=$(ls -t *.cpp 2>/dev/null | head -1); fi; \
if [ -z "$FILE" ]; then \
  echo -e "\033[1;31m❌ No .cpp file found.\033[0m"; \
else \
  echo -e "\033[1;34m▶️ Compiling and running: $FILE\033[0m"; \
  g++ "$FILE" -o /tmp/temp 2> /tmp/err; \
  if [ $? -eq 0 ]; then \
    if [ -f input.txt ]; then \
      /tmp/temp < input.txt; \
    else \
      /tmp/temp; \
    fi; \
    rm -f /tmp/temp; \
    echo -e "\033[1;32m✅ Execution finished successfully!\033[0m"; \
  else \
    echo -e "\033[1;31m❌ Compilation failed:\033[0m"; cat /tmp/err; \
  fi; \
  rm -f /tmp/err; \
fi; }; f'
```

---

### 💻 Usage:

#### ✅ Option 1 — Auto mode

```bash
run
```

→ Ye tumhare folder ki **latest modified `.cpp` file** run karega.

#### ✅ Option 2 — Manual mode

```bash
run file.cpp
```

→ Ye **sirf us file** ko run karega jo tumne specify ki.

---

### 🧠 Optional: permanent setup

Ek baar ye run kar lo:

```bash
echo "alias run='f(){ if [ -n \"\$1\" ]; then FILE=\"\$1\"; else FILE=\$(ls -t *.cpp 2>/dev/null | head -1); fi; if [ -z \"\$FILE\" ]; then echo -e \"\033[1;31m❌ No .cpp file found.\033[0m\"; else echo -e \"\033[1;34m▶️ Compiling and running: \$FILE\033[0m\"; g++ \"\$FILE\" -o /tmp/temp 2> /tmp/err; if [ \$? -eq 0 ]; then if [ -f input.txt ]; then echo -e \"\033[1;33m📥 Using input.txt as input...\033[0m\"; /tmp/temp < input.txt; else /tmp/temp; fi; rm -f /tmp/temp; echo -e \"\033[1;32m✅ Execution finished successfully!\033[0m\"; else echo -e \"\033[1;31m❌ Compilation failed:\033[0m\"; cat /tmp/err; fi; rm -f /tmp/err; fi; }; f'" >> ~/.bashrc
source ~/.bashrc
```

---

Ab tumhara `run` command full flexible hai 🧠✨
👉 `run` = latest file
👉 `run main.cpp` = specific file
👉 Auto input.txt detect + colored output + no binary clutter

Chaaho toh mai ek small variant bana du jisme **output.txt me bhi result auto-save** ho jaye (sirf ek flag ke sath, e.g. `run -o file.cpp`)?


---
---

Nice 😄
Toh chalo ek **“quiet mode”** version bana dete hain — taaki tum full control le sako: normal mode me messages dikhein aur quiet mode me **sirf program ka output**.

---

### ⚙️ Final Pro Version – `run` with Quiet Mode Support

```bash
alias run='f(){ \
QUIET=0; \
if [ "$1" = "-q" ]; then QUIET=1; shift; fi; \
if [ -n "$1" ]; then FILE="$1"; else FILE=$(ls -t *.cpp 2>/dev/null | head -1); fi; \
if [ -z "$FILE" ]; then \
  echo -e "\033[1;31m❌ No .cpp file found.\033[0m"; \
else \
  if [ $QUIET -eq 0 ]; then echo -e "\033[1;34m▶️ Compiling and running: $FILE\033[0m"; fi; \
  g++ "$FILE" -o /tmp/temp 2> /tmp/err; \
  if [ $? -eq 0 ]; then \
    if [ -f input.txt ]; then \
      /tmp/temp < input.txt; \
    else \
      /tmp/temp; \
    fi; \
    rm -f /tmp/temp; \
    if [ $QUIET -eq 0 ]; then echo -e "\033[1;32m✅ Execution finished successfully!\033[0m"; fi; \
  else \
    if [ $QUIET -eq 0 ]; then echo -e "\033[1;31m❌ Compilation failed:\033[0m"; fi; \
    cat /tmp/err; \
  fi; \
  rm -f /tmp/err; \
fi; }; f'
```

---

### 💻 Usage Modes:

#### 🟢 **Normal mode (default)**

```bash
run
```

or

```bash
run file.cpp
```

➡️ Shows compile & success messages with color output

#### 🤫 **Quiet mode**

```bash
run -q
```

or

```bash
run -q file.cpp
```

➡️ Runs silently — no compile or success text, sirf program ka output show karega

---

### 🧠 Optional: Permanent setup

Run this once to save it permanently:

```bash
echo "<above alias>" >> ~/.bashrc
source ~/.bashrc
```

---

Ab tumhare paas ek **smart, minimal aur flexible** setup hai:

* `run` → latest file
* `run file.cpp` → specific file
* `run -q` → quiet mode
* auto input.txt detection
* no binary clutter

---
---