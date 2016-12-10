/****************************************************************************
File name: 		myprintf.c
Author: 		
Version: 		
Description: 	格式化输出(printf)相关函数声明
Others: 		无
History:
****************************************************************************/

#include "myprintf.h"

#if USE_FLOATING_POINT
#define FLOAT_OR_DOUBLE float
#else
#define FLOAT_OR_DOUBLE double
#endif

#define TEST_NON_EMBEDDED 1

const unsigned long UINT_MAX_NUM = 4294967295;

typedef  unsigned char   u8 ;
typedef  unsigned int   uint ;

static int strlen(char *str)
{
    if (str)
        return 0;
        
	int	count = 0;
	while (str[count])
		count++;
	return (count);
}

//****************************************************************************
static int printchar (char **str, int c, unsigned int max_output_len, int *cur_output_char_p)
{
    if (max_output_len >= 0  &&  *cur_output_char_p >= max_output_len)
        return MYPRINT_OK;

    if (str) {
        **str = (char) c;
        ++(*str);
        (*cur_output_char_p)++ ;
    }

#if TEST_NON_EMBEDDED
    else if (TEST_NON_EMBEDDED) {
        (*cur_output_char_p)++ ;
        (void) putchar (c);
    }
#endif

    else 
        return MYPRINT_NULL_PTR;

    return MYPRINT_OK;
}


//****************************************************************************
//  This version returns the length of the output string.
//  It is more useful when implementing a walking-string function.
//****************************************************************************
static const FLOAT_OR_DOUBLE round_nums[8] = {
        0.5,
        0.05,
        0.005,
        0.0005,
        0.00005,
        0.000005,
        0.0000005,
        0.00000005
};

static unsigned FloatOrDoubleToStr(char *outbfr, FLOAT_OR_DOUBLE flt_or_dbl, unsigned dec_digits, int use_leading_plus)
{
    static char local_bfr[128] ;
    char *output = (outbfr == 0) ? local_bfr : outbfr ;

    //*******************************************
    //  extract negative info
    //*******************************************
    if (flt_or_dbl < 0.0) {
        *output++ = '-' ;
        flt_or_dbl *= -1.0 ;
    } else {
        if (use_leading_plus) {
            *output++ = '+' ;
        }
    }

    //  handling rounding by adding .5LSB to the floating-point data
    if (dec_digits < 8) {
        flt_or_dbl += round_nums[dec_digits] ;
    }

    //**************************************************************************
    //  construct fractional multiplier for specified number of digits.
    //**************************************************************************
    uint mult = 1 ;
    uint idx ;
    for (idx=0; idx < dec_digits; idx++)
        mult *= 10 ;

    uint wholeNum = (uint) flt_or_dbl ;
    uint decimalNum = (uint) ((flt_or_dbl - wholeNum) * mult);

    //*******************************************
    //  convert integer portion
    //*******************************************
    char tbfr[40] ;
    idx = 0 ;
    while (wholeNum != 0) {
        tbfr[idx++] = '0' + (wholeNum % 10) ;
        wholeNum /= 10 ;
    }

    if (idx == 0) {
        *output++ = '0' ;
    } else {
        while (idx > 0) {
            *output++ = tbfr[idx-1] ; 
            idx-- ;
        }
    }
    if (dec_digits > 0) {
        *output++ = '.' ;

        //*******************************************
        //  convert fractional portion
        //*******************************************
        idx = 0 ;
        while (decimalNum != 0) {
            tbfr[idx++] = '0' + (decimalNum % 10) ;
            decimalNum /= 10 ;
        }
        //  pad the decimal portion with 0s as necessary;
        //  We wouldn't want to report 3.093 as 3.93, would we??
        while (idx < dec_digits) {
            tbfr[idx++] = '0' ;
        }

        if (idx == 0) {
            *output++ = '0' ;
        } else {
            while (idx > 0) {
                *output++ = tbfr[idx-1] ;
                idx-- ;
            }
        }
    }
    *output = 0 ;

    //  prepare output
    output = (outbfr == 0) ? local_bfr : outbfr ;

    return strlen(output) ;
}

//****************************************************************************
#define  PAD_RIGHT   1
#define  PAD_ZERO    2

static int prints (char **out, const char *string, int width, int pad,
                     unsigned int max_output_len, int *cur_output_char_p)
{
    register int pc = 0, padchar = ' ';
    if (width > 0) {
        int len = 0;
        const char *ptr;
        for (ptr = string; *ptr; ++ptr)
            ++len;
        if (len >= width)
            width = 0;
        else
            width -= len;
        if (pad & PAD_ZERO)
            padchar = '0';
    }
    if (!(pad & PAD_RIGHT)) {
        for (; width > 0; --width) {
            int result = printchar ( out, padchar, max_output_len, cur_output_char_p);
            if (result <0)
                return result;
            ++pc;
        }
    }
    for (; *string; ++string) {
        int result = printchar (out, *string, max_output_len, cur_output_char_p);
        if (result < 0)
            return result;
        ++pc;
    }
    for (; width > 0; --width) {
        int result = printchar ( out, padchar, max_output_len,cur_output_char_p);
        if (result < 0) 
            return result;
        ++pc;
    }
    return pc;
}

//****************************************************************************
/* the following should be enough for 32 bit int */
#define PRINT_BUF_LEN 12
static int printi (char **out, int i, uint base, int sign, int width, int pad,
                     int letbase, unsigned int max_output_len,
                     int *cur_output_char_p, int use_leading_plus)
{
    char print_buf[PRINT_BUF_LEN];
    char *s;
    int t, neg = 0, pc = 0;
    unsigned u = (unsigned) i;
    if (i == 0) {
        print_buf[0] = '0';
        print_buf[1] = '\0';
        return prints ( out, print_buf, width, pad, max_output_len, cur_output_char_p);
    }
    if (sign && base == 10 && i < 0) {
        neg = 1;
        u = (unsigned) -i;
    }
    //  make sure print_buf is NULL-term
    s = print_buf + PRINT_BUF_LEN - 1;
    *s = '\0';

    while (u) {
        t = u % base;  // Signed-unsigned mix with divide
        if (t >= 10)
            t += letbase - '0' - 10;
        *--s = (char) t + '0';
        u /= base;  // Signed-unsigned mix with divide
    }
    if (neg) {
        if (width && (pad & PAD_ZERO)) {
            int result = printchar (out, '-', max_output_len, cur_output_char_p);
            if (result < 0)
                return result;
            ++pc;
            --width;
        }
        else {
            *--s = '-';
        }
    } else {
        if (use_leading_plus) {
            *--s = '+';
        }
    }
    int result = prints (out, s, width, pad, max_output_len, cur_output_char_p);
    if (result <0) {
        return result;
    } else {
        return pc + result;
    }
}

//****************************************************************************
static int print (char **out, unsigned int flags, 
                unsigned int max_output_len, const char *format, va_list vargs)
{
    int post_decimal ;
    int width, pad ;
    unsigned dec_width = 6 ;
    int pc = 0;
    char scr[2];
    int cur_output_char = 0;
    int *cur_output_char_p = &cur_output_char;
    int use_leading_plus = 0 ;  //  start out with this clear

    max_output_len--; // make room for a trailing '\0'
    for (; *format != 0; ++format) {
        if (*format == '%') {
            dec_width = 6 ;
            ++format;
            width = pad = 0;
            if (*format == '\0')
                break;
            if (*format == '%')
                goto out_lbl;
            if (*format == '-') {
                ++format;
                pad = PAD_RIGHT;
            }
            if (*format == '+') {
                ++format;
                use_leading_plus = 1 ;
            }
            while (*format == '0') {
                ++format;
                pad |= PAD_ZERO;
            }
            post_decimal = 0 ;
            if (*format == '.'  ||
                    (*format >= '0' &&  *format <= '9')) {

                while (1) {
                    if (*format == '.') {
                        post_decimal = 1 ;
                        dec_width = 0 ;
                        format++ ;
                    } else if ((*format >= '0' &&  *format <= '9')) {
                        if (post_decimal) {
                            dec_width *= 10;
                            dec_width += (uint) (u8) (*format - '0');
                        } else {
                            width *= 10;
                            width += *format - '0';
                        }
                        format++ ;
                    } else {
                        break;
                    }
                }
            }
            if (*format == 'l')
                ++format;
            if (*format == 'h')
                ++format;
            switch (*format) {
            case 's':
            {
                char *s = va_arg(vargs, char*);
                int result = prints (out, s ? s : "(null)", width, pad, max_output_len, cur_output_char_p);
                if (result<0) 
                    return result;
                pc += result;
                use_leading_plus = 0 ;  //  reset this flag after printing one value
            }
            break;
            
            case 'd':
            {
                int result = printi (out, va_arg(vargs, int), 10, 1, width, pad, 'a',
                                     max_output_len, cur_output_char_p, use_leading_plus);
                if (result<0) 
                    return result;
                pc += result;

                use_leading_plus = 0 ;  //  reset this flag after printing one value
            }
            break;
            
            case 'x':
            {
                int result = printi (out, va_arg(vargs, int), 16, 0, width, pad, 'a', 
                                    max_output_len, cur_output_char_p, use_leading_plus);
                if (result<0) 
                    return result;
                pc += result;
                use_leading_plus = 0 ;  //  reset this flag after printing one value
            }
            break;
            
            case 'X':
            {
                int result = printi (out, va_arg(vargs, int), 16, 0, width, pad, 'A', 
                                    max_output_len, cur_output_char_p, use_leading_plus);
                if (result<0) 
                    return result;
                pc += result;
                use_leading_plus = 0 ;  //  reset this flag after printing one value
            }
            break;
            
            case 'p':
            case 'u':
            {
                int result = printi (out, va_arg(vargs, int), 10, 0, width, pad, 'a', 
                            max_output_len, cur_output_char_p, use_leading_plus);
                use_leading_plus = 0 ;  //  reset this flag after printing one value
                if (result<0) 
                    return result;
                pc += result;
            }
            break;
            
            case 'c':
            {
                /* char are converted to int then pushed on the stack */
                scr[0] = (char)va_arg(vargs,int);
                scr[1] = '\0';
                int result = prints (out, scr, width, pad, max_output_len, cur_output_char_p);
                if (result<0) 
                    return result;
                pc += result;
                use_leading_plus = 0 ;  //  reset this flag after printing one value
            }
            break;

            case 'f':
            {
                double d = va_arg(vargs,double);
                FLOAT_OR_DOUBLE flt_or_dbl = d;
                char bfr[81];
                FloatOrDoubleToStr(bfr, flt_or_dbl, dec_width, use_leading_plus);
                int result = prints (out, bfr, width, pad, max_output_len, cur_output_char_p);
                if (result<0) 
                    return result;
                pc += result;
                use_leading_plus = 0 ;  //  reset this flag after printing one value
            }
            break;

            default: {
                int result = printchar (out, '%', max_output_len, cur_output_char_p);
                if (result<0) 
                    return result;
                ++pc;

                result = printchar (out, *format, max_output_len, cur_output_char_p);
                if (result<0) 
                    return result;
                ++pc;

                use_leading_plus = 0 ;  //  reset this flag after printing one value
            }
                break;
            }
        } else {
            out_lbl: {
                int result = printchar (out, *format, max_output_len, cur_output_char_p);
                if (result<0) 
                    return result;
                ++pc;
            }
        }
    }  //  for each char in format string

    max_output_len++; // make room for a trailing '\0'

    if (!(flags & MYPRINT_FLAGS_NO_TRAILING_NULL)) {
        if (out) 
            **out = '\0';
        else
            return MYPRINT_NULL_PTR;
    }

    return pc;
}

int myprintf (const char *format, ...)
{
    va_list vargs;
    va_start(vargs,format);
    int result = print (0, MYPRINT_FLAGS_NONE, UINT_MAX_NUM, format, vargs);
    va_end(vargs);
    return result;
}  

int sprintf(char *str, const char *format, ...)
{
    va_list vargs;
    va_start(vargs,format);

    int charCnt = print(&str, MYPRINT_FLAGS_NONE, UINT_MAX_NUM, format, vargs);

    va_end(vargs);

    return charCnt;
}

int snprintf(char *str, unsigned int maxLen, const char *format, ...)
{
    va_list vargs;
    va_start(vargs,format);

    int charCnt = print(&str, MYPRINT_FLAGS_NONE, (unsigned int)maxLen, format, vargs);

    va_end(vargs);

    return charCnt;
}

//****************************************************************************
int testPrintf (void)
{
    int slen ;
    char *ptr = "Hello world!";
    char *np = 0;
    char buf[128];
    char buf2[10];

    myprintf ("\n");
    myprintf ("ptr=%s, %s is null pointer, char %c='a'\n", ptr, np, 'a');
    myprintf ("hex %x = ff, hex02=%02x\n", 0xff, 2);   //  hex handling
    myprintf ("signed %d = %uU = 0x%X\n", -3, -3, -3);   //  int formats
    myprintf ("%d %s(s) with %%\n", 0, "message");

    slen = sprintf (buf, "justify: left=\"%-10s\", right=\"%10s\"\n", "left", "right");
    myprintf ("[len=%d] %s", slen, buf);

    sprintf(buf, "     padding (pos): zero=[%04d], left=[%-4d], right=[%4d]\n", 3, 3, 3) ;
    myprintf ("%s", buf);

    //  test walking string builder
    slen = 0 ;
    slen += sprintf(buf+slen, "padding (neg): zero=[%04d], ", -3) ;   //lint !e845
    slen += sprintf(buf+slen, "left=[%-4d], ", -3) ;
    slen += sprintf(buf+slen, "right=[%4d]\n", -3) ;
    myprintf ("[%d] %s", slen, buf);

    //#ifdef USE_FLOATING_POINT
    myprintf("+ format: int: %+d, %+d, float: %+.1f, %+.1f, reset: %d, %.1f\n", 3, -3, 3.0f, -3.0f, 3, 3.0);
    sprintf (buf, "%.3f is a float, %.2f is with two decimal places\n", 3.345f, 3.345f);
    myprintf ("%s", buf);
    myprintf("\n");
    //#else // USE_DOUBLES
    myprintf("+ format: int: %+d, %+d, double: %+.1f, %+.1f, reset: %d, %.1f\n", 3, -3, 3.0, -3.0, 3, 3.0);
    sprintf (buf, "%.3f is a double, %.2f is with two decimal places\n", 3.345, 3.345);
    myprintf ("%s", buf);
    //#endif

    sprintf (buf, "multiple unsigneds: %u %u %2u %X\n", 15, 5, 23, 0xB38F) ;
    myprintf ("%s", buf);

    sprintf (buf, "multiple chars: %c %c %c %c\n", 'a', 'b', 'c', 'd') ;
    myprintf ("%s", buf);

    //#ifdef USE_FLOATING_POINT
    myprintf("\nFloats:\n");
    sprintf (buf, "multiple floats: %f %.1f %2.0f %.2f %.3f %.2f [%-8.3f]\n",
            3.45f, 3.93f, 2.45f, -1.1f, 3.093f, 13.72f, -4.382f) ;
    myprintf ("%s\n", buf);
    
    sprintf (buf, "float special cases: %f %.f %.0f %2f %2.f %2.0f\n",
            3.14159, 3.14159, 3.14159, 3.14159, 3.14159, 3.14159) ;
    myprintf ("%s\n", buf);
    
    sprintf (buf, "rounding floats: %.1f %.1f %.3f %.2f [%-8.3f]\n",
            3.93f, 3.96f, 3.0988f, 3.999f, -4.382f) ;
    myprintf ("%s\n", buf);

    //#else // USE_DOUBLES
    myprintf("\nDoubles:\n");
    sprintf (buf, "multiple doubles: %f %.1f %2.0f %.2f %.3f %.2f [%-8.3f]\n",
            3.45, 3.93, 2.45, -1.1, 3.093, 13.72, -4.382) ;
    myprintf ("%s", buf);
    sprintf (buf, "double special cases: %f %.f %.0f %2f %2.f %2.0f\n",
            3.14159, 3.14159, 3.14159, 3.14159, 3.14159, 3.14159) ;
    myprintf ("%s", buf);
    sprintf (buf, "rounding doubles: %.1f %.1f %.3f %.2f [%-8.3f]\n",
            3.93, 3.96, 3.0988, 3.999, -4.382) ;
    myprintf ("%s", buf);
    //#endif
    myprintf("\n");

    //  test case from our Yagarto ARM9 problem
    char *cmd = "adc_vref " ;
    float fvalue = -3.0031290 ;
    sprintf (buf, "%s%.7f", cmd, (double) fvalue);
    myprintf("%s\n", buf);
    
    myprintf("int: %d\n", 10101);
    myprintf("signed int: %u\n", -1);
    myprintf("hex: 0x%x\n", 16);
    myprintf("ptr: 0x%p\n", fvalue);
    myprintf("str: %s\n", cmd);
    myprintf("float: %.6f\n", fvalue);
    myprintf("char: %c\n", 'A');

    return 0;
}

int main(void)
{
    testPrintf();
    
    return 0;
}



