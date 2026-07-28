extern "C" const char* __asan_default_options() {
  return "handle_abort=1:dump_registers=0";
}

extern "C" const char* __ubsan_default_options() {
  return "print_stacktrace=1";
}
