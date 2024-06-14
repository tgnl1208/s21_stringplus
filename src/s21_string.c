#include "s21_string.h"

// part 1
void *s21_memchr(const void *str, int c, s21_size_t n) {
  unsigned char *pointer = (unsigned char *)str;
  void *result = s21_NULL;
  for (s21_size_t i = 0; i < n; i++) {
    if (*pointer == (unsigned char)c) {
      result = pointer;
      break;
    }
    pointer++;
  }
  return result;
}

int s21_memcmp(const void *str1, const void *str2, s21_size_t n) {
  const unsigned char *string1 = str1;
  const unsigned char *string2 = str2;
  for (s21_size_t i = 0; i < n; i++) {
    if (string1[i] != string2[i]) {
      return (string1[i] - string2[i]);
    }
  }
  return 0;
}

void *s21_memcpy(void *dest, const void *src, s21_size_t n) {
  unsigned char *dest_bytes = (unsigned char *)dest;
  const unsigned char *src_bytes = (const unsigned char *)src;
  for (s21_size_t i = 0; i < n; i++) {
    dest_bytes[i] = src_bytes[i];
  }
  return dest;
}

void *s21_memset(void *str, int c, s21_size_t n) {
  char *temp = (char *)str;
  for (s21_size_t i = 0; i < n; i++) {
    temp[i] = c;
  }
  return str;
}

char *s21_strncat(char *dest, const char *src, s21_size_t n) {
  s21_size_t dest_len = s21_strlen(dest);
  s21_size_t i;
  for (i = 0; src[i] != '\0' && i < n; i++) {
    dest[dest_len + i] = src[i];
  }
  dest[dest_len + i] = '\0';
  return dest;
}

char *s21_strchr(const char *str, int c) {
  const char *result = s21_NULL;
  for (s21_size_t i = 0; i < s21_strlen(str) + 1; i++) {
    if (str[i] == c) {
      result = &str[i];
      break;
    }
  }
  return (char *)result;
}  // поменял

int s21_strncmp(const char *str1, const char *str2, s21_size_t n) {
  while (n && *str1 && (*str1 == *str2)) {
    str1++;
    str2++;
    n--;
  }
  if (n == 0) {
    return 0;
  } else {
    return (*(unsigned char *)str1 - *(unsigned char *)str2);
  }
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n) {
  s21_size_t i = 0;
  while (i < n && src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }
  if (src[i] == '\0' && n > 0 && n > s21_strlen(src)) {
    dest[i] = '\0';
  }
  return dest;
}

s21_size_t s21_strcspn(const char *str1, const char *str2) {
  s21_size_t size = 0;
  while (*str1) {
    if (s21_strchr(str2, *str1)) {
      break;
    } else {
      str1++;
      size++;
    }
  }
  return size;
}

#if defined(__APPLE__)
#define MAX_ERRLIST 107
#define MIN_ERRLIST -1
#define ERROR "Unknown error: "

const char *s21_error[] = {"Undefined error: 0",
                           "Operation not permitted",
                           "No such file or directory",
                           "No such process",
                           "Interrupted system call",
                           "Input/output error",
                           "Device not configured",
                           "Argument list too long",
                           "Exec format error",
                           "Bad file descriptor",
                           "No child processes",
                           "Resource deadlock avoided",
                           "Cannot allocate memory",
                           "Permission denied",
                           "Bad address",
                           "Block device required",
                           "Resource busy",
                           "File exists",
                           "Cross-device link",
                           "Operation not supported by device",
                           "Not a directory",
                           "Is a directory",
                           "Invalid argument",
                           "Too many open files in system",
                           "Too many open files",
                           "Inappropriate ioctl for device",
                           "Text file busy",
                           "File too large",
                           "No space left on device",
                           "Illegal seek",
                           "Read-only file system",
                           "Too many links",
                           "Broken pipe",
                           "Numerical argument out of domain",
                           "Result too large",
                           "Resource temporarily unavailable",
                           "Operation now in progress",
                           "Operation already in progress",
                           "Socket operation on non-socket",
                           "Destination address required",
                           "Message too long",
                           "Protocol wrong type for socket",
                           "Protocol not available",
                           "Protocol not supported",
                           "Socket type not supported",
                           "Operation not supported",
                           "Protocol family not supported",
                           "Address family not supported by protocol family",
                           "Address already in use",
                           "Can't assign requested address",
                           "Network is down",
                           "Network is unreachable",
                           "Network dropped connection on reset",
                           "Software caused connection abort",
                           "Connection reset by peer",
                           "No buffer space available",
                           "Socket is already connected",
                           "Socket is not connected",
                           "Can't send after socket shutdown",
                           "Too many references: can't splice",
                           "Operation timed out",
                           "Connection refused",
                           "Too many levels of symbolic links",
                           "File name too long",
                           "Host is down",
                           "No route to host",
                           "Directory not empty",
                           "Too many processes",
                           "Too many users",
                           "Disc quota exceeded",
                           "Stale NFS file handle",
                           "Too many levels of remote in path",
                           "RPC struct is bad",
                           "RPC version wrong",
                           "RPC prog. not avail",
                           "Program version wrong",
                           "Bad procedure for program",
                           "No locks available",
                           "Function not implemented",
                           "Inappropriate file type or format",
                           "Authentication error",
                           "Need authenticator",
                           "Device power is off",
                           "Device error",
                           "Value too large to be stored in data type",
                           "Bad executable (or shared library)",
                           "Bad CPU type in executable",
                           "Shared library version mismatch",
                           "Malformed Mach-o file",
                           "Operation canceled",
                           "Identifier removed",
                           "No message of desired type",
                           "Illegal byte sequence",
                           "Attribute not found",
                           "Bad message",
                           "EMULTIHOP (Reserved)",
                           "No message available on STREAM",
                           "ENOLINK (Reserved)",
                           "No STREAM resources",
                           "Not a STREAM",
                           "Protocol error",
                           "STREAM ioctl timeout",
                           "Operation not supported on socket",
                           "Policy not found",
                           "State not recoverable",
                           "Previous owner died",
                           "Interface output queue is full"};

#elif defined(__linux__)
#define MAX_ERRLIST 134
#define MIN_ERRLIST -1
#define ERROR "Unknown error "

const char *s21_error[] = {"Success",
                           "Operation not permitted",
                           "No such file or directory",
                           "No such process",
                           "Interrupted system call",
                           "Input/output error",
                           "No such device or address",
                           "Argument list too long",
                           "Exec format error",
                           "Bad file descriptor",
                           "No child processes",
                           "Resource temporarily unavailable",
                           "Cannot allocate memory",
                           "Permission denied",
                           "Bad address",
                           "Block device required",
                           "Device or resource busy",
                           "File exists",
                           "Invalid cross-device link",
                           "No such device",
                           "Not a directory",
                           "Is a directory",
                           "Invalid argument",
                           "Too many open files in system",
                           "Too many open files",
                           "Inappropriate ioctl for device",
                           "Text file busy",
                           "File too large",
                           "No space left on device",
                           "Illegal seek",
                           "Read-only file system",
                           "Too many links",
                           "Broken pipe",
                           "Numerical argument out of domain",
                           "Numerical result out of range",
                           "Resource deadlock avoided",
                           "File name too long",
                           "No locks available",
                           "Function not implemented",
                           "Directory not empty",
                           "Too many levels of symbolic links",
                           "Unknown error 41",
                           "No message of desired type",
                           "Identifier removed",
                           "Channel number out of range",
                           "Level 2 not synchronized",
                           "Level 3 halted",
                           "Level 3 reset",
                           "Link number out of range",
                           "Protocol driver not attached",
                           "No CSI structure available",
                           "Level 2 halted",
                           "Invalid exchange",
                           "Invalid request descriptor",
                           "Exchange full",
                           "No anode",
                           "Invalid request code",
                           "Invalid slot",
                           "Unknown error 58",
                           "Bad font file format",
                           "Device not a stream",
                           "No data available",
                           "Timer expired",
                           "Out of streams resources",
                           "Machine is not on the network",
                           "Package not installed",
                           "Object is remote",
                           "Link has been severed",
                           "Advertise error",
                           "Srmount error",
                           "Communication error on send",
                           "Protocol error",
                           "Multihop attempted",
                           "RFS specific error",
                           "Bad message",
                           "Value too large for defined data type",
                           "Name not unique on network",
                           "File descriptor in bad state",
                           "Remote address changed",
                           "Can not access a needed shared library",
                           "Accessing a corrupted shared library",
                           ".lib section in a.out corrupted",
                           "Attempting to link in too many shared libraries",
                           "Cannot exec a shared library directly",
                           "Invalid or incomplete multibyte or wide character",
                           "Interrupted system call should be restarted",
                           "Streams pipe error",
                           "Too many users",
                           "Socket operation on non-socket",
                           "Destination address required",
                           "Message too long",
                           "Protocol wrong type for socket",
                           "Protocol not available",
                           "Protocol not supported",
                           "Socket type not supported",
                           "Operation not supported",
                           "Protocol family not supported",
                           "Address family not supported by protocol",
                           "Address already in use",
                           "Cannot assign requested address",
                           "Network is down",
                           "Network is unreachable",
                           "Network dropped connection on reset",
                           "Software caused connection abort",
                           "Connection reset by peer",
                           "No buffer space available",
                           "Transport endpoint is already connected",
                           "Transport endpoint is not connected",
                           "Cannot send after transport endpoint shutdown",
                           "Too many references: cannot splice",
                           "Connection timed out",
                           "Connection refused",
                           "Host is down",
                           "No route to host",
                           "Operation already in progress",
                           "Operation now in progress",
                           "Stale file handle",
                           "Structure needs cleaning",
                           "Not a XENIX named type file",
                           "No XENIX semaphores available",
                           "Is a named type file",
                           "Remote I/O error",
                           "Disk quota exceeded",
                           "No medium found",
                           "Wrong medium type",
                           "Operation canceled",
                           "Required key not available",
                           "Key has expired",
                           "Key has been revoked",
                           "Key was rejected by service",
                           "Owner died",
                           "State not recoverable",
                           "Operation not possible due to RF-kill",
                           "Memory page has hardware error"};
#endif

char *s21_strerror(int errnum) {
  char *result = s21_NULL;
  static char arr[128] = {'\0'};
  if (errnum <= MIN_ERRLIST || errnum >= MAX_ERRLIST) {
    s21_sprintf(arr, "Unknown error: %d", errnum);
    result = arr;
  } else {
    result = (char *)s21_error[errnum];
  }
  return result;
}

s21_size_t s21_strlen(const char *str) {
  s21_size_t len = 0;
  if (str) {
    for (unsigned char *p = (unsigned char *)str; *p != '\0'; p++) {
      len++;
    }
  }
  return len;
}

char *s21_strpbrk(const char *str1, const char *str2) {
  char *result = s21_NULL;
  for (char *a = (char *)str1; *a; a++) {
    for (char *b = (char *)str2; *b; b++) {
      if (*a == *b) {
        result = a;
        break;
      }
    }
    if (result != s21_NULL) break;
  }
  return result;
}

char *s21_strrchr(const char *str, int c) {
  const char *result = s21_NULL;
  do {
    if (*str == c) {
      result = str;
    }
  } while (*str++);
  return (char *)result;
}
// поменял

char *s21_strstr(const char *haystack, const char *needle) {
  if (!*needle) return (char *)haystack;
  while (*haystack) {
    if (*haystack == *needle) {
      const char *h = haystack, *n = needle;
      while (*n && *h == *n) {
        h++;
        n++;
      }
      if (!*n) return (char *)haystack;
    }
    haystack++;
  }
  return s21_NULL;
}

int is_delim(char c, const char *delim) {  //добавил
  int flag = 0;
  while (*delim != '\0') {
    if (c == *delim) {
      flag = 1;
    }
    delim++;
  }
  return flag;
}

char *s21_strtok(char *str, const char *delim) {  //исправил
  static char *start_point;
  char *result = s21_NULL;
  if (!str) {
    str = start_point;
  }
  if (str) {
    int all_deligms = 0;
    int regular = 0;
    while (regular == 0) {
      if (is_delim(*str, delim)) {
        str++;
      } else if (*str == '\0') {
        all_deligms = 1;
        regular = 1;
      } else {
        regular = 1;
      }
    }
    if (!all_deligms) {
      result = str;
      int flag = 1;
      while (flag == 1) {
        if (*str == '\0') {
          start_point = str;
          flag = 0;
        }
        if (is_delim(*str, delim)) {
          *str = '\0';
          start_point = str + 1;
          flag = 0;
        }
        str++;
      }
    }
  }
  return result;
}

// part 5
void *s21_to_upper(const char *str) {
  if (str == s21_NULL) {
    return s21_NULL;
  }
  int len = s21_strlen(str);
  char *upper_str = malloc(len + 1);
  if (upper_str == s21_NULL) return s21_NULL;
  for (int i = 0; i < len; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      upper_str[i] = str[i] - 32;
    } else {
      upper_str[i] = str[i];
    }
  }
  upper_str[len] = '\0';
  return upper_str;
}

void *s21_to_lower(const char *str) {
  if (str == s21_NULL) {
    return s21_NULL;
  }
  int len = s21_strlen(str);
  char *lower_str = malloc(len + 1);
  if (lower_str == s21_NULL) return s21_NULL;
  for (int i = 0; i < len; i++) {
    if (str[i] >= 'A' && str[i] <= 'Z') {
      lower_str[i] = str[i] + 32;
    } else {
      lower_str[i] = str[i];
    }
  }
  lower_str[len] = '\0';
  return lower_str;
}

void *s21_insert(const char *src, const char *str, size_t start_index) {
  if (src == s21_NULL || str == s21_NULL) return s21_NULL;
  s21_size_t src_len = s21_strlen(src);
  s21_size_t str_len = s21_strlen(str);
  if (start_index > src_len) return s21_NULL;
  s21_size_t ns_len = src_len + str_len;
  char *new_string = malloc(ns_len + 1);
  if (new_string == s21_NULL) return s21_NULL;
  s21_size_t j = 0, k = 0;
  for (s21_size_t i = 0; i < ns_len; i++) {
    if (i >= start_index && i < start_index + str_len) {
      new_string[i] = str[k++];
    } else {
      new_string[i] = src[j++];
    }
  }
  new_string[ns_len] = '\0';
  return new_string;
}

int check_char(char c, const char *chars) {
  while (*chars)
    if (c == *chars++) return 1;
  return 0;
}

void *s21_trim(const char *src, const char *trim_chars) {
  if (src == s21_NULL || trim_chars == s21_NULL) return s21_NULL;
  s21_size_t src_len = s21_strlen(src), start = 0, end = src_len;
  while (start < src_len && check_char(src[start], trim_chars)) start++;
  while (end > start && check_char(src[end - 1], trim_chars)) end--;

  s21_size_t ns_len = end - start;
  char *new_string = (char *)malloc(ns_len + 1);
  if (new_string == s21_NULL) return s21_NULL;
  for (s21_size_t i = 0; i < ns_len; i++) new_string[i] = src[start + i];
  new_string[ns_len] = '\0';
  return new_string;
}

char *s21_strcat(char *str1, const char *str2) {
  s21_strcpy(str1 + s21_strlen(str1), str2);
  return str1;
}

char *s21_strcpy(char *dest, const char *str) {
  unsigned int i = 0;
  while (str[i] != '\0') {
    dest[i] = str[i];
    i++;
  }
  dest[i] = '\0';
  return dest;
}