/*
 * names.c -- example of group name callback.
 */
#include <stdio.h>
#include "oniguruma.h"

static int
name_callback(UChar* name, UChar* name_end, int ngroup_num, int* group_nums,
	      regex_t* reg, void* arg)
{
  int i, gn, ref;
  char* s;
  OnigRegion *region = (OnigRegion* )arg;

  for (i = 0; i < ngroup_num; i++) {
    gn = group_nums[i];
    ref = onig_name_to_backref_number(reg, name, name_end, region);
    s = (ref == gn ? "*" : "");
    fprintf(stderr, "%s (%d): ", name, gn);
    fprintf(stderr, "(%d-%d) %s\n", region->beg[gn], region->end[gn], s);
  }
  return 0;  /* 0: continue */
}

extern int main(int argc, char* argv[])
{
  int r;
  unsigned char *start, *range, *end;
  regex_t* reg;
  OnigErrorInfo einfo;
  OnigRegion *region;

  static unsigned char* pattern = "(?<foo>a*)(?<bar>b*)(?<foo>c*)";
  static unsigned char* str = "aaabbbbcc";

  r = onig_new(&reg, pattern, pattern + strlen(pattern),
	ONIG_OPTION_DEFAULT, ONIG_ENCODING_ASCII, ONIG_SYNTAX_DEFAULT, &einfo);
  if (r != ONIG_NORMAL) {
    char s[ONIG_MAX_ERROR_MESSAGE_LEN];
    onig_error_code_to_str(s, r, &einfo);
    fprintf(stderr, "ERROR: %s\n", s);
    return -1;
  }

  fprintf(stderr, "number of names: %d\n", onig_number_of_names(reg));

  region = onig_region_new();

  end   = str + strlen(str);
  start = str;
  range = end;
  r = onig_search(reg, str, end, start, range, region, ONIG_OPTION_NONE);
  if (r >= 0) {
    fprintf(stderr, "match at %d\n\n", r);
    r = onig_foreach_name(reg, name_callback, (void* )region);
  }
  else if (r == ONIG_MISMATCH) {
    fprintf(stderr, "search fail\n");
  }
  else { /* error */
    char s[ONIG_MAX_ERROR_MESSAGE_LEN];
    onig_error_code_to_str(s, r);
    return -1;
  }

  onig_region_free(region, 1 /* 1:free self, 0:free contents only */);
  onig_free(reg);
  onig_end();
  return 0;
}
