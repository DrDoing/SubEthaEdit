/**********************************************************************

  iso8859_1.c -  Oniguruma (regular expression library)

  Copyright (C) 2003-2004  K.Kosako (kosako@sofnec.co.jp)

**********************************************************************/
#include "regenc.h"

#define ENC_ISO_8859_1_TO_LOWER_CASE(c) EncISO_8859_1_ToLowerCaseTable[c]
#define ENC_IS_ISO_8859_1_CTYPE(code,ctype) \
  ((EncISO_8859_1_CtypeTable[code] & ctype) != 0)

static UChar EncISO_8859_1_ToLowerCaseTable[256] = {
  '\000', '\001', '\002', '\003', '\004', '\005', '\006', '\007',
  '\010', '\011', '\012', '\013', '\014', '\015', '\016', '\017',
  '\020', '\021', '\022', '\023', '\024', '\025', '\026', '\027',
  '\030', '\031', '\032', '\033', '\034', '\035', '\036', '\037',
  '\040', '\041', '\042', '\043', '\044', '\045', '\046', '\047',
  '\050', '\051', '\052', '\053', '\054', '\055', '\056', '\057',
  '\060', '\061', '\062', '\063', '\064', '\065', '\066', '\067',
  '\070', '\071', '\072', '\073', '\074', '\075', '\076', '\077',
  '\100', '\141', '\142', '\143', '\144', '\145', '\146', '\147',
  '\150', '\151', '\152', '\153', '\154', '\155', '\156', '\157',
  '\160', '\161', '\162', '\163', '\164', '\165', '\166', '\167',
  '\170', '\171', '\172', '\133', '\134', '\135', '\136', '\137',
  '\140', '\141', '\142', '\143', '\144', '\145', '\146', '\147',
  '\150', '\151', '\152', '\153', '\154', '\155', '\156', '\157',
  '\160', '\161', '\162', '\163', '\164', '\165', '\166', '\167',
  '\170', '\171', '\172', '\173', '\174', '\175', '\176', '\177',
  '\200', '\201', '\202', '\203', '\204', '\205', '\206', '\207',
  '\210', '\211', '\212', '\213', '\214', '\215', '\216', '\217',
  '\220', '\221', '\222', '\223', '\224', '\225', '\226', '\227',
  '\230', '\231', '\232', '\233', '\234', '\235', '\236', '\237',
  '\240', '\241', '\242', '\243', '\244', '\245', '\246', '\247',
  '\250', '\251', '\252', '\253', '\254', '\255', '\256', '\257',
  '\260', '\261', '\262', '\263', '\264', '\265', '\266', '\267',
  '\270', '\271', '\272', '\273', '\274', '\275', '\276', '\277',
  '\340', '\341', '\342', '\343', '\344', '\345', '\346', '\347',
  '\350', '\351', '\352', '\353', '\354', '\355', '\356', '\357',
  '\360', '\361', '\362', '\363', '\364', '\365', '\366', '\327',
  '\370', '\371', '\372', '\373', '\374', '\375', '\376', '\337',
  '\340', '\341', '\342', '\343', '\344', '\345', '\346', '\347',
  '\350', '\351', '\352', '\353', '\354', '\355', '\356', '\357',
  '\360', '\361', '\362', '\363', '\364', '\365', '\366', '\367',
  '\370', '\371', '\372', '\373', '\374', '\375', '\376', '\377'
};

static unsigned short EncISO_8859_1_CtypeTable[256] = {
  0x1004, 0x1004, 0x1004, 0x1004, 0x1004, 0x1004, 0x1004, 0x1004,
  0x1004, 0x1106, 0x1104, 0x1104, 0x1104, 0x1104, 0x1004, 0x1004,
  0x1004, 0x1004, 0x1004, 0x1004, 0x1004, 0x1004, 0x1004, 0x1004,
  0x1004, 0x1004, 0x1004, 0x1004, 0x1004, 0x1004, 0x1004, 0x1004,
  0x1142, 0x10d0, 0x10d0, 0x10d0, 0x10d0, 0x10d0, 0x10d0, 0x10d0,
  0x10d0, 0x10d0, 0x10d0, 0x10d0, 0x10d0, 0x10d0, 0x10d0, 0x10d0,
  0x1c58, 0x1c58, 0x1c58, 0x1c58, 0x1c58, 0x1c58, 0x1c58, 0x1c58,
  0x1c58, 0x1c58, 0x10d0, 0x10d0, 0x10d0, 0x10d0, 0x10d0, 0x10d0,
  0x10d0, 0x1e51, 0x1e51, 0x1e51, 0x1e51, 0x1e51, 0x1e51, 0x1a51,
  0x1a51, 0x1a51, 0x1a51, 0x1a51, 0x1a51, 0x1a51, 0x1a51, 0x1a51,
  0x1a51, 0x1a51, 0x1a51, 0x1a51, 0x1a51, 0x1a51, 0x1a51, 0x1a51,
  0x1a51, 0x1a51, 0x1a51, 0x10d0, 0x10d0, 0x10d0, 0x10d0, 0x18d0,
  0x10d0, 0x1c71, 0x1c71, 0x1c71, 0x1c71, 0x1c71, 0x1c71, 0x1871,
  0x1871, 0x1871, 0x1871, 0x1871, 0x1871, 0x1871, 0x1871, 0x1871,
  0x1871, 0x1871, 0x1871, 0x1871, 0x1871, 0x1871, 0x1871, 0x1871,
  0x1871, 0x1871, 0x1871, 0x10d0, 0x10d0, 0x10d0, 0x10d0, 0x1004,
  0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004,
  0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004,
  0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004,
  0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004, 0x0004,
  0x0142, 0x00d0, 0x0050, 0x0050, 0x0050, 0x0050, 0x0050, 0x0050,
  0x0050, 0x0050, 0x0871, 0x00d0, 0x0050, 0x00d0, 0x0050, 0x0050,
  0x0050, 0x0050, 0x0850, 0x0850, 0x0050, 0x0871, 0x0050, 0x00d0,
  0x0050, 0x0850, 0x0871, 0x00d0, 0x0850, 0x0850, 0x0850, 0x00d0,
  0x0a51, 0x0a51, 0x0a51, 0x0a51, 0x0a51, 0x0a51, 0x0a51, 0x0a51,
  0x0a51, 0x0a51, 0x0a51, 0x0a51, 0x0a51, 0x0a51, 0x0a51, 0x0a51,
  0x0a51, 0x0a51, 0x0a51, 0x0a51, 0x0a51, 0x0a51, 0x0a51, 0x0050,
  0x0a51, 0x0a51, 0x0a51, 0x0a51, 0x0a51, 0x0a51, 0x0a51, 0x0871,
  0x0871, 0x0871, 0x0871, 0x0871, 0x0871, 0x0871, 0x0871, 0x0871,
  0x0871, 0x0871, 0x0871, 0x0871, 0x0871, 0x0871, 0x0871, 0x0871,
  0x0871, 0x0871, 0x0871, 0x0871, 0x0871, 0x0871, 0x0871, 0x0050,
  0x0871, 0x0871, 0x0871, 0x0871, 0x0871, 0x0871, 0x0871, 0x0871
};

static int
iso_8859_1_mbc_to_lower(UChar* p, UChar* lower)
{
  *lower = ENC_ISO_8859_1_TO_LOWER_CASE(*p);
  return 1; /* return byte length of converted char to lower */
}

static int
iso_8859_1_mbc_is_case_ambig(UChar* p)
{
  int v = (EncISO_8859_1_CtypeTable[*p] &
	   (ONIGENC_CTYPE_UPPER | ONIGENC_CTYPE_LOWER));

  if ((v | ONIGENC_CTYPE_LOWER) != 0) {
    /* 0xdf, 0xaa, 0xb5, 0xba are lower case letter, but can't convert. */
    if (*p == 0xdf || (*p >= 0xaa && *p <= 0xba))
      return FALSE;
    else
      return TRUE;
  }

  return (v != 0 ? TRUE : FALSE);
}

static int
iso_8859_1_code_is_ctype(OnigCodePoint code, unsigned int ctype)
{
  if (code < 256)
    return ENC_IS_ISO_8859_1_CTYPE(code, ctype);
  else
    return FALSE;
}

OnigEncodingType OnigEncodingISO_8859_1 = {
  {
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1
  },
  "ISO-8859-1",  /* name */
  1,             /* max byte length */
  TRUE,          /* is_fold_match */
  ONIGENC_CTYPE_SUPPORT_LEVEL_SB,    /* ctype_support_level */
  TRUE,          /* is continuous sb mb codepoint */
  onigenc_single_byte_mbc_to_code,
  onigenc_single_byte_code_to_mbclen,
  onigenc_single_byte_code_to_mbc,
  iso_8859_1_mbc_to_lower,
  iso_8859_1_mbc_is_case_ambig,
  iso_8859_1_code_is_ctype,
  onigenc_nothing_get_ctype_code_range,
  onigenc_single_byte_left_adjust_char_head,
  onigenc_single_byte_is_allowed_reverse_match,
  onigenc_get_all_fold_match_code_ss_0xdf,
  onigenc_get_fold_match_info_ss_0xdf
};
