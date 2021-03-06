/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {

/* 
  Step 1 : Negate x and y;
  Step 2 : Calculate x&negated y and negated x&y;
  Step 3 : Calculate the OR result of previous two varibles.
  (OR operation is created by combine ~ and &)
*/
  int x_negate = ~x;
  int y_negate = ~y;
  int x_and_negate_y = x & y_negate;
  int x_negate_and_y = x_negate & y;

  return (~ ((~x_and_negate_y) & (~x_negate_and_y)));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  int x = 1;

  return (x << 31);
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
  int crt1 = !(~(x + (x+1)));
  int crt2 = !!(~x);
  int crt3 = x;
    return (crt1 & crt2 & crt3);
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  int m = (0xAA<<8)+0xAA;
  int mask = (m<<16) + m;
  int crt1 = x & mask;
  int crt2 = crt1 | (crt1>>1);  
  return !(~crt2);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return (~x+1);
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {

  int xminus30 = x + (~0x30+1);
  int crt1 = !(xminus30>>31);

  int xminus3a = x + (~0x3a+1);
  int crt2 = !(~(xminus3a>>31));
  return crt1 & crt2;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
  // if x == 0 return 0xffffffff; otherwise return 0x00000000
  int isXzero = (~(!(!x)) << 31) >> 31;
  return ((~isXzero & y) + (isXzero & z));
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
  // Result = x - y
  int result = (x + ~y + 1);

  // See if result < 0
  int crt1 = !!( result >> 31 );

  // x > 0 & y < 0 but result <0; positive overflow
  int crt3 = !(x>>31) & (y>>31) & crt1;

  // x < 0 & y > 0 but result > 0; negative overflow
  int crt4 = (x>>31) & !(y>>31) & !crt1;
  // Result < 0 but not when positive or negative overflow ; or x=y
  return (crt1 ^ (crt3|crt4)) | !result;
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
  int negX = ~x + 1;
  return (((x|negX)>>31) +1);
}
/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {
  /* To convert x to positive number. (Including boundary case)
  x = Tmin -> x = Tmax
  x = Tmax -> x = Tmax

  Tmin < x < 0 -> x = |x|
  x = 0 -> x = 0
  0 < x < Tmax -> x = x

  x = -1 (0xFFFFFFFF) -> x = 0                                */
  x = x ^ (x>>31);
  int isZero=!x;
  int notZeroMask=(!(!x)<<31)>>31;
  int bits = 0;

  /* Those masks are illegal operations, but can be generated 
  by tricks performed in allOddBits. */
  int left_16mask = 0xffff0000;
  int left_16 = x & left_16mask;
  int right_16mask = 0x0000ffff;
  int right_16 = x & right_16mask;
  int bin1 = !!(left_16) << 4;
  x = ((x >> (!!(left_16) * 16)) & right_16mask);

  int left_8mask = 0x0000ff00;
  int left_8 = x & left_8mask;
  int right_8mask = 0x000000ff;
  int right_8 = x & right_8mask;
  int bin2 = !!(left_8) << 3;
  x = (x >> (!!(left_8) * 8)) & right_8mask;

  int left_4mask = 0x000000f0;
  int left_4 = x & left_4mask;
  int right_4mask = 0x0000000f;
  int right_4 = x & right_4mask;
  int bin3 = !!(left_4) << 2;
  x = (x >> (!!(left_4) * 4)) & right_4mask;

  int left_2mask = 0x0000000c;
  int left_2 = x & left_2mask;
  int right_2mask = 0x00000003;
  int right_2 = x & right_2mask;
  int bin4 = !!(left_2) << 1;
  x = (x >> (!!(left_2) * 2)) & right_2mask;

  int left_1mask = 0x00000002;
  int left_1 = x & left_1mask;
  int right_1mask = 0x00000001;
  int right_1 = x & right_1mask;
  int bin5 = !!left_1 + !!right_1;
  bin5 = !!left_1;
    
  bits = bin1 + bin2 + bin3 + bin4 + bin5 + 2;
  return isZero|(bits&notZeroMask);
  
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
  // To make sure uf is not all zero
  if (uf<<1){
    // To make sure uf is normalized number
    if ((uf<<1)>>24 ){
      // If exp is all 1, means uf is either Inf or NaN.
      if ( (uf & 0x7f800000) == 0x7f800000 )
      {
         uf = uf;
      }
      else{
      unsigned int expPlus = 0x00800000;
      uf = uf + expPlus;
      }
      }
    // If uf is a denorm number
    // If uf is the biggest denorm which will casue overflow.
    else if (uf == 0x7fffff) {
          uf = 0xfffffe;
    }
  else{
      uf = (uf<<1) + ((!!(uf>>31))<<31);
    }
  }
  // When uf is plus or minus zero.
  else{
  uf += 0;}
  return uf;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {

    // To make sure uf is not all zero
  if (uf<<1){

    // Case 1: uf is normalized number
    if ((uf<<1)>>24 ){
      // If exp is all 1, means uf is either Inf or NaN.
      if ( (uf & 0x7f800000) == 0x7f800000 )
      {
         uf = 0x80000000u;
      }
      else{
      unsigned int sinMask = 0x80000000;    
      unsigned int expMask = 0x7f800000;
      unsigned int sigMask = 0x007fffff;
      int exp = ((uf & expMask)>>23) - 127;
      int sig = (uf & sigMask);
      int sin = uf & sinMask;

      // If exp is within int range
      if (exp>=0 && exp <= 23 ){
        if (!sin) {
          uf = (sig>>(23-exp)) + (0x1<<exp) ;}
        else{
          uf = (sig>>(23-exp)) + (0x1<<exp) ;
          uf = ~uf + 1;
        }   
      }
      // If exp is too small
      else if (exp < 0){uf = 0x0;}
      else {uf = 0x80000000;}
      }
      }
    // Case 2: If uf is a denorm number
    else  {
          uf = 0x0;
    }
  }
  // When uf is plus or minus zero.
  else{
  uf = 0;}
  return uf;
}  
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {

    unsigned ans;
    if (x<-128) { ans = 0; }
    else if (x>127) {ans = 0x7f800000;}
    else {
      int exp = x + 127;
      ans = (exp<<23);
    }
    return ans;
}
