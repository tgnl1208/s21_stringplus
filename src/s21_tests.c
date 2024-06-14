#include <check.h>
#include <stdio.h>
#include <string.h>

#include "s21_string.h"

char str1[] = "";
char str2[] = "b";
char str3[] = "Hello World!";
char str4[] = "Hel\0lo World!";

START_TEST(s21_memchr_test) {
  ck_assert_ptr_eq(s21_memchr(str1, 'b', 5), memchr(str1, 'b', 5));
  ck_assert_ptr_eq(s21_memchr(str2, 'b', 1), memchr(str2, 'b', 1));
  ck_assert_ptr_eq(s21_memchr(str3, 'e', 10), memchr(str3, 'e', 10));
  ck_assert_ptr_eq(s21_memchr(str3, 'W', 20), memchr(str3, 'W', 20));
}
END_TEST

START_TEST(s21_memcmp_test) {
  ck_assert_int_eq(s21_memcmp(str1, str2, 5), memcmp(str1, str2, 5));
  ck_assert_int_eq(s21_memcmp(str2, str3, 10), memcmp(str2, str3, 10));
  ck_assert_int_eq(s21_memcmp(str3, str4, 20), memcmp(str3, str4, 20));
  ck_assert_int_eq(s21_memcmp(str3, "Hello World!", 12),
                   memcmp(str3, "Hello World!", 12));
}
END_TEST

START_TEST(s21_memcpy_test) {
  ck_assert_str_eq(s21_memcpy(str1, str2, 5), memcpy(str1, str2, 5));
  ck_assert_str_eq(s21_memcpy(str2, str3, 10), memcpy(str2, str3, 10));
  ck_assert_str_eq(s21_memcpy(str3, str4, 6), memcpy(str3, str4, 6));
  ck_assert_str_eq(s21_memcpy(str3, str4, 0), memcpy(str3, str4, 0));
  ck_assert_str_eq(s21_memcpy(str1, str4, 1), memcpy(str1, str4, 1));
}
END_TEST

START_TEST(s21_memset_test) {
  ck_assert_str_eq(s21_memset(str1, 'a', 5), memset(str1, 'a', 5));
  ck_assert_str_eq(s21_memset(str2, 'b', 10), memset(str2, 'b', 10));
  ck_assert_str_eq(s21_memset(str2, 'b', 1), memset(str2, 'b', 1));
  ck_assert_str_eq(s21_memset(str3, 's', 6), memset(str3, 's', 6));
  ck_assert_str_eq(s21_memset(str4, 'M', 8), memset(str4, 'M', 8));
}
END_TEST

START_TEST(s21_strncat_test) {
  ck_assert_str_eq(s21_strncat(str1, str2, 5), strncat(str1, str2, 5));
  ck_assert_str_eq(s21_strncat(str2, str3, 1), strncat(str2, str3, 1));
}
END_TEST

START_TEST(s21_strchr_test) {
  ck_assert_ptr_eq(s21_strchr(str1, 's'), strchr(str1, 's'));
  ck_assert_ptr_eq(s21_strchr(str2, 'b'), strchr(str2, 'b'));
  ck_assert_ptr_eq(s21_strchr(str3, '.'), strchr(str3, '.'));
  ck_assert_ptr_eq(s21_strchr(str3, 'H'), strchr(str3, 'H'));
  ck_assert_ptr_eq(s21_strchr(str4, 'e'), strchr(str4, 'e'));
}
END_TEST

START_TEST(s21_strncmp_test) {
  ck_assert_int_eq(s21_strncmp(str1, str2, 5), strncmp(str1, str2, 5));
  ck_assert_int_eq(s21_strncmp(str2, str3, 4), strncmp(str2, str3, 4));
  ck_assert_int_eq(s21_strncmp(str3, str4, 8), strncmp(str3, str4, 8));
  ck_assert_int_eq(s21_strncmp(str1, str4, 2), strncmp(str1, str4, 2));
}
END_TEST

START_TEST(s21_strncpy_test) {
  char deststr1[5] = "";
  char deststr2[20] = "";
  ck_assert_str_eq(s21_strncpy(str1, str2, 5), strncpy(str1, str2, 5));
  ck_assert_str_eq(s21_strncpy(str2, str3, 1), strncpy(str2, str3, 1));
  ck_assert_str_eq(s21_strncpy(str3, str4, 5), strncpy(str3, str4, 5));
  ck_assert_str_eq(s21_strncpy(deststr1, str4, 5), strncpy(deststr1, str4, 5));
  ck_assert_str_eq(s21_strncpy(deststr2, str4, 20),
                   strncpy(deststr2, str4, 20));
}
END_TEST

START_TEST(s21_strcspn_test) {
  char test1[] = "abcd efgh";
  char test2[] = "abcd";
  char test3[] = "efgh";
  char test4[] = "sadd";
  ck_assert_uint_eq(s21_strcspn(test1, test2), strcspn(test1, test2));
  ck_assert_uint_eq(s21_strcspn(test2, test3), strcspn(test2, test3));
  ck_assert_uint_eq(s21_strcspn(test3, test4), strcspn(test3, test4));
}
END_TEST

START_TEST(s21_strerror_test) {
  for (int i = -1; i < 322; i++) {
    char *case1 = s21_strerror(i);
    char *case2 = strerror(i);
    ck_assert_uint_eq((unsigned long)*case1, (unsigned long)*case2);
  }
}
END_TEST

START_TEST(s21_strlen_test) {
  ck_assert_int_eq(s21_strlen(str1), strlen(str1));
  ck_assert_int_eq(s21_strlen(str2), strlen(str2));
  ck_assert_int_eq(s21_strlen(str3), strlen(str3));
  ck_assert_int_eq(s21_strlen(str4), strlen(str4));
}
END_TEST

START_TEST(s21_strpbrk_test) {
  ck_assert_ptr_eq(s21_strpbrk(str1, str2), strpbrk(str1, str2));
  ck_assert_ptr_eq(s21_strpbrk(str2, str3), strpbrk(str2, str3));
  ck_assert_ptr_eq(s21_strpbrk(str3, str4), strpbrk(str3, str4));
}
END_TEST

START_TEST(s21_strrchr_test) {
  ck_assert_ptr_eq(s21_strrchr(str1, 's'), strrchr(str1, 's'));
  ck_assert_ptr_eq(s21_strrchr(str2, 'b'), strrchr(str2, 'b'));
  ck_assert_ptr_eq(s21_strrchr(str3, '.'), strrchr(str3, '.'));
  ck_assert_ptr_eq(s21_strrchr(str3, 'H'), strrchr(str3, 'H'));
  ck_assert_ptr_eq(s21_strrchr(str4, 'e'), strrchr(str4, 'e'));
}
END_TEST

START_TEST(s21_strstr_test) {
  ck_assert_ptr_eq(s21_strstr(str1, str2), strstr(str1, str2));
  ck_assert_ptr_eq(s21_strstr(str2, str3), strstr(str2, str3));
  ck_assert_ptr_eq(s21_strstr(str3, str4), strstr(str3, str4));
}
END_TEST

START_TEST(s21_strtok_test) {
  char str_strtok1[] = "Hello/World/How/are/you?";
  char delim1[] = "/";

  char str_strtok2[] = "Hello/World/How/are/you?";
  char delim2[] = "/";

  char *s21_token = s21_strtok(str_strtok1, delim1);
  char *token = strtok(str_strtok2, delim2);

  while (s21_token != s21_NULL) {
    ck_assert_str_eq(s21_token, token);
    s21_token = s21_strtok(s21_NULL, delim1);
    token = strtok(NULL, delim2);
  }
}
END_TEST

START_TEST(s21_to_upper_test) {
  char s1[] = "hello world!";
  char s2[] = "HELLO WORLD!";
  char *s1_res = s21_to_upper(s1);
  char *s2_res = s21_to_upper(s2);
  ck_assert_str_eq(s1_res, "HELLO WORLD!");
  ck_assert_str_eq(s2_res, "HELLO WORLD!");
  free(s1_res);
  free(s2_res);
}
END_TEST

START_TEST(s21_to_lower_test) {
  char s1[] = "hello world!";
  char s2[] = "HELLO WORLD!";
  char *s1_res = s21_to_lower(s1);
  char *s2_res = s21_to_lower(s2);
  ck_assert_str_eq(s1_res, "hello world!");
  ck_assert_str_eq(s2_res, "hello world!");
  free(s1_res);
  free(s2_res);
}
END_TEST

START_TEST(s21_insert_test) {
  char s1[] = "hello world!";
  char s2[] = "HELLO WORLD!";
  char *res1 = s21_insert(s1, s2, 5);
  char *res2 = s21_insert(s1, s2, 0);
  ck_assert_str_eq(res1, "helloHELLO WORLD! world!");
  ck_assert_str_eq(res2, "HELLO WORLD!hello world!");
  free(res1);
  free(res2);
}
END_TEST

START_TEST(s21_trim_test) {
  char s1[] = "//hello world!//";
  char trim_chars1[] = "/";
  char s2[] = "dddd/hello world!/dddd";
  char trim_chars2[] = "d";
  char *res1 = s21_trim(s1, trim_chars1);
  char *res2 = s21_trim(s2, trim_chars2);
  ck_assert_str_eq(res1, "hello world!");
  ck_assert_str_eq(res2, "/hello world!/");
  free(res1);
  free(res2);
}
END_TEST

START_TEST(s21_sprintf_char_test) {
  char buffer[100] = {'\0'};
  char s21_buffer[100] = {'\0'};

  char formats[3][10] = {"%c", "%10c", "%-10c"};

  for (int i = 0; i < 3; ++i) {
    sprintf(buffer, formats[i], '@');
    s21_sprintf(s21_buffer, formats[i], '@');
    ck_assert_str_eq(buffer, s21_buffer);
  }
}
END_TEST

START_TEST(s21_sprintf_int_test) {
  char buffer[100] = {'\0'};
  char s21_buffer[100] = {'\0'};

  char formats[12][10] = {
      "%d", "%10d", "%-10d",  "%u", "%.10d", "%10.5d",
      "%i", "%#x",  "%-#10X", "%x", "%o",    "%+-10.5d",
  };

  for (int i = 0; i < 12; ++i) {
    sprintf(buffer, formats[i], 52);
    s21_sprintf(s21_buffer, formats[i], 52);
    ck_assert_str_eq(buffer, s21_buffer);
    sprintf(buffer, formats[i], -52);
    s21_sprintf(s21_buffer, formats[i], -52);
    ck_assert_str_eq(buffer, s21_buffer);
  }
}

START_TEST(s21_sprintf_float_test) {
  char buffer[100] = {'\0'};
  char s21_buffer[100] = {'\0'};

  char formats[8][10] = {
      "%f",   "%#f",  "%+f", "%-f", "%0f", "% f",

      "%10f", "%.5f",

  };

  for (int i = 0; i < 8; ++i) {
    sprintf(buffer, formats[i], 52.0);
    s21_sprintf(s21_buffer, formats[i], 52.0);
    ck_assert_str_eq(buffer, s21_buffer);
    sprintf(buffer, formats[i], -52.0);
    s21_sprintf(s21_buffer, formats[i], -52.0);
    ck_assert_str_eq(buffer, s21_buffer);
  }
}
START_TEST(s21_sprintf_string_test) {
  char buffer[100] = {'\0'};
  char s21_buffer[100] = {'\0'};

  char formats[3][10] = {
      "%s",
      "%10s",
      "%.10s",
  };

  for (int i = 0; i < 3; ++i) {
    sprintf(buffer, formats[i], "test");
    s21_sprintf(s21_buffer, formats[i], "test");
    ck_assert_str_eq(buffer, s21_buffer);
  }
}

Suite *my_suite(void) {
  Suite *s = suite_create("My Suite");
  TCase *tc_core = tcase_create("Core");
  tcase_add_test(tc_core, s21_memchr_test);
  tcase_add_test(tc_core, s21_memcmp_test);
  tcase_add_test(tc_core, s21_memcpy_test);
  tcase_add_test(tc_core, s21_memset_test);
  tcase_add_test(tc_core, s21_strncat_test);
  tcase_add_test(tc_core, s21_strchr_test);
  tcase_add_test(tc_core, s21_strncmp_test);
  tcase_add_test(tc_core, s21_strncpy_test);
  tcase_add_test(tc_core, s21_strcspn_test);
  tcase_add_test(tc_core, s21_strerror_test);
  tcase_add_test(tc_core, s21_strlen_test);
  tcase_add_test(tc_core, s21_strpbrk_test);
  tcase_add_test(tc_core, s21_strrchr_test);
  tcase_add_test(tc_core, s21_strstr_test);
  tcase_add_test(tc_core, s21_strtok_test);
  tcase_add_test(tc_core, s21_to_upper_test);
  tcase_add_test(tc_core, s21_to_lower_test);
  tcase_add_test(tc_core, s21_insert_test);
  tcase_add_test(tc_core, s21_trim_test);
  tcase_add_test(tc_core, s21_sprintf_char_test);
  tcase_add_test(tc_core, s21_sprintf_int_test);
  tcase_add_test(tc_core, s21_sprintf_float_test);
  tcase_add_test(tc_core, s21_sprintf_string_test);
  suite_add_tcase(s, tc_core);
  return s;
}

// Точка входа для запуска тестов
int main(void) {
  int number_failed;
  Suite *s = my_suite();
  SRunner *sr = srunner_create(s);
  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);
  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
