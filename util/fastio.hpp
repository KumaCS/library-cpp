#pragma once

namespace FastIO {
static constexpr unsigned int BUF_SIZE = 1 << 20;

struct InStream {
 private:
  using IS = InStream;
  inline static unsigned int l = 0, r = 0;
  inline static char buf[BUF_SIZE];
  inline void load() {
    memmove(buf, buf + l, r - l);
    r = r - l + fread(buf + r - l, 1, BUF_SIZE - r + l, stdin);
    l = 0;
    if (r < BUF_SIZE) buf[r++] = '\n';
  }
  static bool isSpace(char c) { return c == ' ' || ('\t' <= c && c <= '\r'); }

 public:
  char seekChar() {
    if (l >= r) load();
    return buf[l];
  }
  void skipSpace() {
    while (isSpace(seekChar())) l++;
  }
  template <class T>
  T readUInteger() {
    T x = 0;
    skipSpace();
    if (r - l < 100) load();
    while (true) {
      char c = buf[l];
      if ('9' < c || c < '0') break;
      x = x * 10 + (c - '0');
      l++;
    }
    return x;
  }
  template <class T>
  T readInteger() {
    T x = 0;
    skipSpace();
    if (r - l < 100) load();
    bool is_negative = seekChar() == '-';
    if (is_negative) {
      l++;
      while (true) {
        char c = buf[l];
        if ('9' < c || c < '0') break;
        x = x * 10 - (c - '0');
        l++;
      }
    } else {
      while (true) {
        char c = buf[l];
        if ('9' < c || c < '0') break;
        x = x * 10 + (c - '0');
        l++;
      }
    }
    return x;
  }
  char readChar() {
    skipSpace();
    char c = seekChar();
    l++;
    return c;
  }
  std::string readString() {
    std::string s;
    skipSpace();
    while (true) {
      char c = seekChar();
      if (isSpace(c) || c == '\0') break;
      s.push_back(c);
      l++;
    }
    return s;
  }
  IS& operator>>(unsigned int& x) { x = readUInteger<unsigned int>(); return *this; }
  IS& operator>>(int& x) { x = readInteger<int>(); return *this; }
  IS& operator>>(unsigned long long& x) { x = readUInteger<unsigned long long>(); return *this; }
  IS& operator>>(long long& x) { x = readInteger<long long>(); return *this; }
  IS& operator>>(char& c) { c = readChar(); return *this; }
  IS& operator>>(std::string& s) { s = readString(); return *this; }
};

struct OutputTable {
  char num[10000][4];
  constexpr OutputTable() : num() {
    for (int i = 0; i < 10000; i++) {
      num[i][0] = '0' + i / 1000 % 10;
      num[i][1] = '0' + i / 100 % 10;
      num[i][2] = '0' + i / 10 % 10;
      num[i][3] = '0' + i / 1 % 10;
    }
  }
} constexpr table;

struct OutStream {
 private:
  using OS = OutStream;
  inline static unsigned int p = 0;
  inline static char buf[BUF_SIZE];
  static constexpr uint32_t P10(unsigned int d) { return d ? P10(d - 1) * 10 : 1; }
  static constexpr uint64_t P10L(unsigned int d) { return d ? P10L(d - 1) * 10 : 1; }
  template <class T, class U> static void Split(T& x, U& y, U z) noexcept { x = y / z; y -= x * z; }
  void ensureOutput(unsigned int d) { if (p + d > BUF_SIZE) flush(); }
  void writeNum(uint32_t x) {
    memcpy(buf + p, table.num[x], 4);
    p += 4;
  }
  void writeNumHead(uint32_t x) {
    const char* s = table.num[x];
    if (x >= 1000) buf[p++] = s[0];
    if (x >= 100) buf[p++] = s[1];
    if (x >= 10) buf[p++] = s[2];
    buf[p++] = s[3];
  }
  void writeU32Unchecked(uint32_t x) {
    unsigned int y = 0;
    if (x >= P10(8)) {
      Split(y, x, P10(8)); writeNumHead(y);
      Split(y, x, P10(4)); writeNum(y);
      writeNum(x);
    } else if (x >= P10(4)) {
      Split(y, x, P10(4)); writeNumHead(y);
      writeNum(x);
    } else if (x > 0) {
      writeNumHead(x);
    } else {
      write('0');
    }
  }
  void writeU64Unchecked(uint64_t x) {
    unsigned int y = 0;
    if (x >= P10L(16)) {
      Split(y, x, P10L(16)); writeNumHead(y);
      Split(y, x, P10L(12)); writeNum(y);
      Split(y, x, P10L(8)); writeNum(y);
      Split(y, x, P10L(4)); writeNum(y);
      writeNum(x);
    } else if (x >= P10L(12)) {
      Split(y, x, P10L(12)); writeNumHead(y);
      Split(y, x, P10L(8)); writeNum(y);
      Split(y, x, P10L(4)); writeNum(y);
      writeNum(x);
    } else if (x >= P10L(8)) {
      Split(y, x, P10L(8)); writeNumHead(y);
      Split(y, x, P10L(4)); writeNum(y);
      writeNum(x);
    } else if (x >= P10L(4)) {
      Split(y, x, P10L(4)); writeNumHead(y);
      writeNum(x);
    } else if (x > 0) {
      writeNumHead(x);
    } else {
      write('0');
    }
  }

 public:
  ~OutStream(){ flush(); }
  void flush() {
    fwrite(buf, 1, p, stdout);
    p = 0;
  }
  void write(const char c) {
    if (p == BUF_SIZE) flush();
    buf[p++] = c;
  }
  void write(const char* s) { while (*s) write(*(s++)); }
  void write(const std::string& s) { for (char c : s) write(c); }
  void writeU32(uint32_t x) {
    ensureOutput(10);
    writeU32Unchecked(x);
  }
  void writeI32(int32_t x) {
    ensureOutput(11);
    if (x < 0) { write('-'); writeU32Unchecked(uint32_t(0) - static_cast<uint32_t>(x)); }
    else writeU32Unchecked((uint32_t)x);
  }
  void writeU64(uint64_t x) {
    ensureOutput(20);
    writeU64Unchecked(x);
  }
  void writeI64(int64_t x) {
    ensureOutput(21);
    if (x < 0) { write('-'); writeU64Unchecked(uint64_t(0) - static_cast<uint64_t>(x)); }
    else writeU64Unchecked((uint64_t)x);
  }
  OS& operator<<(unsigned int x) { writeU32(x); return *this; }
  OS& operator<<(int x) { writeI32(x); return *this; }
  OS& operator<<(unsigned long long x) { writeU64(x); return *this; }
  OS& operator<<(long long x) { writeI64(x); return *this; }
  OS& operator<<(const std::string& s) { write(s); return *this; }
  OS& operator<<(const char* s) { write(s); return *this; }
  OS& operator<<(char c) { write(c); return *this; }
};
};  // namespace FastIO
