/*
 * File: VLCforADAS_UMP.c
 *
 * Code generated for Simulink model 'VLCforADAS_UMP'.
 *
 * Model version                  : 1.850
 * Simulink Coder version         : 9.2 (R2019b) 18-Jul-2019
 * C/C++ source code generated on : Mon Apr  1 17:55:13 2024
 *
 * Target selection: ert.tlc
 * Embedded hardware selection: Texas Instruments->TMS570 Cortex-R4
 * Code generation objectives:
 *    1. Execution efficiency
 *    2. RAM efficiency
 * Validation result: Not run
 */

#include "VLCforADAS_UMP.h"

/* Named constants for Chart: '<S3>/MainVestaChart' */
#define IN_Drive_off                   ((uint8_T)1U)
#define IN_Init                        ((uint8_T)1U)
#define IN_NO_ACTIVE_CHILD             ((uint8_T)0U)
#define IN_SSM                         ((uint8_T)2U)
#define IN_SSR                         ((uint8_T)3U)
#define IN_Stop                        ((uint8_T)2U)
#define IN_VLC_CDD                     ((uint8_T)4U)
#define IN_in_SSM                      ((uint8_T)3U)

/* Named constants for Chart: '<S6>/Chart' */
#define IN_Dec                         ((uint8_T)1U)
#define IN_Hold                        ((uint8_T)2U)
#define IN_Inc                         ((uint8_T)3U)
#define NumBitsPerChar                 8U
#ifndef UCHAR_MAX
#include <limits.h>
#endif

#if ( UCHAR_MAX != (0xFFU) ) || ( SCHAR_MAX != (0x7F) )
#error Code was generated for compiler with different sized uchar/char. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( USHRT_MAX != (0xFFFFU) ) || ( SHRT_MAX != (0x7FFF) )
#error Code was generated for compiler with different sized ushort/short. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( UINT_MAX != (0xFFFFFFFFU) ) || ( INT_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized uint/int. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

#if ( ULONG_MAX != (0xFFFFFFFFU) ) || ( LONG_MAX != (0x7FFFFFFF) )
#error Code was generated for compiler with different sized ulong/long. \
Consider adjusting Test hardware word size settings on the \
Hardware Implementation pane to match your compiler word sizes as \
defined in limits.h of the compiler. Alternatively, you can \
select the Test hardware is the same as production hardware option and \
select the Enable portable word sizes option on the Code Generation > \
Verification pane for ERT based targets, which will disable the \
preprocessor word size checks.
#endif

/* Skipping ulong_long/long_long check: insufficient preprocessor integer range. */

/* Block signals and states (default storage) */
DW rtDW;

/* Previous zero-crossings (trigger) states */
PrevZCX rtPrevZCX;

/* Real-time model */
RT_MODEL rtM_;
RT_MODEL *rtM = &rtM_;
static real32_T rt_roundf_snf(real32_T u);
static real_T rt_roundd_snf(real_T u);
static int16_T look1_is16lu32n32Ds32_linlcas(int16_T u0, const int16_T bp0[],
  const int16_T table[], uint32_T maxIndex);
static int16_T intrp1d_s16s32s32u32u32n32la_s(uint32_T bpIndex, uint32_T frac,
  const int16_T table[], uint32_T maxIndex);
static real32_T look1_iflf_plinlca(real32_T u0, const real32_T bp0[], const
  real32_T table[], uint32_T prevIndex[], uint32_T maxIndex);
static real32_T look1_iflf_linlca(real32_T u0, const real32_T bp0[], const
  real32_T table[], uint32_T maxIndex);
static int32_T look2_iu16bs32lu32n32t_BzWkcOQY(uint16_T u0, uint16_T u1, const
  int32_T bp0[], const int32_T bp1[], const int32_T table[], const uint32_T
  maxIndex[], uint32_T stride);
static int16_T look1_iu16lu64n48ts16D_7ZfpVqQH(uint16_T u0, const uint16_T bp0[],
  const int16_T table[], uint32_T maxIndex);
static real32_T look1_iflf_binlx(real32_T u0, const real32_T bp0[], const
  real32_T table[], uint32_T maxIndex);
static int16_T look1_iu16bs16lu32n32t_Ji2sqUY0(uint16_T u0, const int16_T bp0[],
  const int16_T table[], uint32_T maxIndex);
static int16_T look1_iu16lu64n48ts16D_Xu1w5Bqg(uint16_T u0, const uint16_T bp0[],
  const int16_T table[], uint32_T maxIndex);
static real32_T look1_iu16lftf_linlca(uint16_T u0, const uint16_T bp0[], const
  real32_T table[], uint32_T maxIndex);
static int16_T look2_is16lu32n32Ds32d_VMYn7zgN(int16_T u0, int16_T u1, const
  int16_T bp0[], const int16_T bp1[], const int16_T table[], const uint32_T
  maxIndex[], uint32_T stride);
static uint16_T look1_iu16lu64n48_plinlcase(uint16_T u0, const uint16_T bp0[],
  const uint16_T table[], uint32_T prevIndex[], uint32_T maxIndex);
static uint32_T plook_u32u8s16u32n32_evenca_gs(uint8_T u, int16_T bp0, uint16_T
  bpSpace, uint32_T *fraction);
static uint32_T plook_u32f_linckpa(real32_T u, const real32_T bp[], uint32_T
  maxIndex, uint32_T *prevIndex);
static uint32_T linsearch_u32f(real32_T u, const real32_T bp[], uint32_T
  startIndex);
static int64_T div_nzp_s64_round(int64_T numerator, int64_T denominator);
static int32_T div_nzp_s32_round(int32_T numerator, int32_T denominator);
static uint32_T div_nzp_us32_sat_round(int32_T numerator, int32_T denominator);
static uint32_T div_nzp_u32_round(uint32_T numerator, uint32_T denominator);
static int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator);
static void mul_wide_su64(int64_T in0, uint64_T in1, uint64_T *ptrOutBitsHi,
  uint64_T *ptrOutBitsLo);
static int64_T mul_ssu64_loSR_round(int64_T a, uint64_T b, uint64_T aShift);
static uint64_T div_nzp_u64_round(uint64_T numerator, uint64_T denominator);
static int16_T Subsystem1(int16_T rtu_Reqtrqmax);
static real_T rtGetNaN(void);
static real32_T rtGetNaNF(void);
extern real_T rtInf;
extern real_T rtMinusInf;
extern real_T rtNaN;
extern real32_T rtInfF;
extern real32_T rtMinusInfF;
extern real32_T rtNaNF;
static void rt_InitInfAndNaN(size_t realSize);
static boolean_T rtIsInf(real_T value);
static boolean_T rtIsInfF(real32_T value);
static boolean_T rtIsNaN(real_T value);
static boolean_T rtIsNaNF(real32_T value);
typedef struct {
  struct {
    uint32_T wordH;
    uint32_T wordL;
  } words;
} BigEndianIEEEDouble;

typedef struct {
  struct {
    uint32_T wordL;
    uint32_T wordH;
  } words;
} LittleEndianIEEEDouble;

typedef struct {
  union {
    real32_T wordLreal;
    uint32_T wordLuint;
  } wordL;
} IEEESingle;

real_T rtInf;
real_T rtMinusInf;
real_T rtNaN;
real32_T rtInfF;
real32_T rtMinusInfF;
real32_T rtNaNF;
static real_T rtGetInf(void);
static real32_T rtGetInfF(void);
static real_T rtGetMinusInf(void);
static real32_T rtGetMinusInfF(void);

/*
 * Initialize rtNaN needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetNaN(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T nan = 0.0;
  if (bitsPerReal == 32U) {
    nan = rtGetNaNF();
  } else {
    union {
      BigEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FFFFFFFU;
    tmpVal.bitVal.words.wordL = 0xFFFFFFFFU;
    nan = tmpVal.fltVal;
  }

  return nan;
}

/*
 * Initialize rtNaNF needed by the generated code.
 * NaN is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetNaNF(void)
{
  IEEESingle nanF = { { 0 } };

  nanF.wordL.wordLuint = 0x7FFFFFFFU;
  return nanF.wordL.wordLreal;
}

/*
 * Initialize the rtInf, rtMinusInf, and rtNaN needed by the
 * generated code. NaN is initialized as non-signaling. Assumes IEEE.
 */
static void rt_InitInfAndNaN(size_t realSize)
{
  (void) (realSize);
  rtNaN = rtGetNaN();
  rtNaNF = rtGetNaNF();
  rtInf = rtGetInf();
  rtInfF = rtGetInfF();
  rtMinusInf = rtGetMinusInf();
  rtMinusInfF = rtGetMinusInfF();
}

/* Test if value is infinite */
static boolean_T rtIsInf(real_T value)
{
  return (boolean_T)((value==rtInf || value==rtMinusInf) ? 1U : 0U);
}

/* Test if single-precision value is infinite */
static boolean_T rtIsInfF(real32_T value)
{
  return (boolean_T)(((value)==rtInfF || (value)==rtMinusInfF) ? 1U : 0U);
}

/* Test if value is not a number */
static boolean_T rtIsNaN(real_T value)
{
  boolean_T result = (boolean_T) 0;
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  if (bitsPerReal == 32U) {
    result = rtIsNaNF((real32_T)value);
  } else {
    union {
      BigEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.fltVal = value;
    result = (boolean_T)((tmpVal.bitVal.words.wordH & 0x7FF00000) == 0x7FF00000 &&
                         ( (tmpVal.bitVal.words.wordH & 0x000FFFFF) != 0 ||
                          (tmpVal.bitVal.words.wordL != 0) ));
  }

  return result;
}

/* Test if single-precision value is not a number */
static boolean_T rtIsNaNF(real32_T value)
{
  IEEESingle tmp;
  tmp.wordL.wordLreal = value;
  return (boolean_T)( (tmp.wordL.wordLuint & 0x7F800000) == 0x7F800000 &&
                     (tmp.wordL.wordLuint & 0x007FFFFF) != 0 );
}

/*
 * Initialize rtInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T inf = 0.0;
  if (bitsPerReal == 32U) {
    inf = rtGetInfF();
  } else {
    union {
      BigEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0x7FF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    inf = tmpVal.fltVal;
  }

  return inf;
}

/*
 * Initialize rtInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetInfF(void)
{
  IEEESingle infF;
  infF.wordL.wordLuint = 0x7F800000U;
  return infF.wordL.wordLreal;
}

/*
 * Initialize rtMinusInf needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real_T rtGetMinusInf(void)
{
  size_t bitsPerReal = sizeof(real_T) * (NumBitsPerChar);
  real_T minf = 0.0;
  if (bitsPerReal == 32U) {
    minf = rtGetMinusInfF();
  } else {
    union {
      BigEndianIEEEDouble bitVal;
      real_T fltVal;
    } tmpVal;

    tmpVal.bitVal.words.wordH = 0xFFF00000U;
    tmpVal.bitVal.words.wordL = 0x00000000U;
    minf = tmpVal.fltVal;
  }

  return minf;
}

/*
 * Initialize rtMinusInfF needed by the generated code.
 * Inf is initialized as non-signaling. Assumes IEEE.
 */
static real32_T rtGetMinusInfF(void)
{
  IEEESingle minfF;
  minfF.wordL.wordLuint = 0xFF800000U;
  return minfF.wordL.wordLreal;
}

static int16_T look1_is16lu32n32Ds32_linlcas(int16_T u0, const int16_T bp0[],
  const int16_T table[], uint32_T maxIndex)
{
  int16_T y;
  uint32_T frac;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'linear'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u0 <= bp0[0U]) {
    bpIdx = 0U;
    frac = 0U;
  } else if (u0 < bp0[maxIndex]) {
    /* Linear Search */
    for (bpIdx = maxIndex >> 1U; u0 < bp0[bpIdx]; bpIdx--) {
    }

    while (u0 >= bp0[bpIdx + 1U]) {
      bpIdx++;
    }

    frac = (uint32_T)(((uint64_T)(uint16_T)(u0 - bp0[bpIdx]) << 32) / (uint16_T)
                      (bp0[bpIdx + 1U] - bp0[bpIdx]));
  } else {
    bpIdx = maxIndex;
    frac = 0U;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  if (bpIdx == maxIndex) {
    y = table[bpIdx];
  } else {
    y = (int16_T)((int16_T)(((int64_T)(table[bpIdx + 1U] - table[bpIdx]) * frac)
      >> 32) + table[bpIdx]);
  }

  return y;
}

static int16_T intrp1d_s16s32s32u32u32n32la_s(uint32_T bpIndex, uint32_T frac,
  const int16_T table[], uint32_T maxIndex)
{
  int16_T y;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  if (bpIndex == maxIndex) {
    y = table[bpIndex];
  } else {
    y = (int16_T)((int16_T)(((int64_T)(table[bpIndex + 1U] - table[bpIndex]) *
      frac) >> 32) + table[bpIndex]);
  }

  return y;
}

static real32_T look1_iflf_plinlca(real32_T u0, const real32_T bp0[], const
  real32_T table[], uint32_T prevIndex[], uint32_T maxIndex)
{
  real32_T y;
  real32_T frac;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'linear'
     Use previous index: 'on'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Extrapolation method: 'Clip'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    bpIdx = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex]) {
    /* Linear Search */
    for (bpIdx = prevIndex[0U]; u0 < bp0[bpIdx]; bpIdx--) {
    }

    while (u0 >= bp0[bpIdx + 1U]) {
      bpIdx++;
    }

    frac = (u0 - bp0[bpIdx]) / (bp0[bpIdx + 1U] - bp0[bpIdx]);
  } else {
    bpIdx = maxIndex;
    frac = 0.0F;
  }

  prevIndex[0U] = bpIdx;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'wrapping'
   */
  if (bpIdx == maxIndex) {
    y = table[bpIdx];
  } else {
    y = (table[bpIdx + 1U] - table[bpIdx]) * frac + table[bpIdx];
  }

  return y;
}

static real32_T look1_iflf_linlca(real32_T u0, const real32_T bp0[], const
  real32_T table[], uint32_T maxIndex)
{
  real32_T y;
  real32_T frac;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'linear'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    bpIdx = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex]) {
    /* Linear Search */
    for (bpIdx = maxIndex >> 1U; u0 < bp0[bpIdx]; bpIdx--) {
    }

    while (u0 >= bp0[bpIdx + 1U]) {
      bpIdx++;
    }

    frac = (u0 - bp0[bpIdx]) / (bp0[bpIdx + 1U] - bp0[bpIdx]);
  } else {
    bpIdx = maxIndex;
    frac = 0.0F;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'wrapping'
   */
  if (bpIdx == maxIndex) {
    y = table[bpIdx];
  } else {
    y = (table[bpIdx + 1U] - table[bpIdx]) * frac + table[bpIdx];
  }

  return y;
}

static int32_T look2_iu16bs32lu32n32t_BzWkcOQY(uint16_T u0, uint16_T u1, const
  int32_T bp0[], const int32_T bp1[], const int32_T table[], const uint32_T
  maxIndex[], uint32_T stride)
{
  int32_T y;
  uint32_T frac;
  uint32_T bpIndices[2];
  uint32_T fractions[2];
  int32_T uCast;
  uint32_T offset_1d;
  uint32_T bpIdx;

  /* Column-major Lookup 2-D
     Canonical function name: look2_iu16bs32lu32n32ts32Ds64ds64_linlcar
     Search method: 'linear'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'round'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'round'
   */
  uCast = u0;
  if (u0 < bp0[0U]) {
    bpIdx = 0U;
    frac = 0U;
  } else if (uCast < bp0[maxIndex[0U]]) {
    /* Linear Search */
    for (bpIdx = maxIndex[0U] >> 1U; uCast < bp0[bpIdx]; bpIdx--) {
    }

    while (uCast >= bp0[bpIdx + 1U]) {
      bpIdx++;
    }

    frac = (uint32_T)div_nzp_u64_round((uint64_T)((uint32_T)u0 - bp0[bpIdx]) <<
      32, (uint32_T)bp0[bpIdx + 1U] - bp0[bpIdx]);
  } else {
    bpIdx = maxIndex[0U];
    frac = 0U;
  }

  fractions[0U] = frac;
  bpIndices[0U] = bpIdx;

  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'round'
   */
  uCast = u1;
  if (u1 < bp1[0U]) {
    bpIdx = 0U;
    frac = 0U;
  } else if (uCast < bp1[maxIndex[1U]]) {
    /* Linear Search */
    for (bpIdx = maxIndex[1U] >> 1U; uCast < bp1[bpIdx]; bpIdx--) {
    }

    while (uCast >= bp1[bpIdx + 1U]) {
      bpIdx++;
    }

    frac = (uint32_T)div_nzp_u64_round((uint64_T)((uint32_T)u1 - bp1[bpIdx]) <<
      32, (uint32_T)bp1[bpIdx + 1U] - bp1[bpIdx]);
  } else {
    bpIdx = maxIndex[1U];
    frac = 0U;
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'round'
     Overflow mode: 'wrapping'
   */
  offset_1d = bpIdx * stride + bpIndices[0U];
  if (bpIndices[0U] == maxIndex[0U]) {
    y = table[offset_1d];
  } else {
    y = (int32_T)mul_ssu64_loSR_round((int64_T)table[offset_1d + 1U] -
      table[offset_1d], fractions[0U], 32ULL) + table[offset_1d];
  }

  if (bpIdx == maxIndex[1U]) {
  } else {
    bpIdx = offset_1d + stride;
    if (bpIndices[0U] == maxIndex[0U]) {
      uCast = table[bpIdx];
    } else {
      uCast = (int32_T)mul_ssu64_loSR_round((int64_T)table[bpIdx + 1U] -
        table[bpIdx], fractions[0U], 32ULL) + table[bpIdx];
    }

    y += (int32_T)mul_ssu64_loSR_round((int64_T)uCast - y, frac, 32ULL);
  }

  return y;
}

static int16_T look1_iu16lu64n48ts16D_7ZfpVqQH(uint16_T u0, const uint16_T bp0[],
  const int16_T table[], uint32_T maxIndex)
{
  int16_T y;
  uint64_T frac;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Canonical function name: look1_iu16lu64n48ts16Ds32_linlcar
     Search method: 'linear'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'round'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'round'
   */
  if (u0 <= bp0[0U]) {
    bpIdx = 0U;
    frac = 0ULL;
  } else if (u0 < bp0[maxIndex]) {
    /* Linear Search */
    for (bpIdx = maxIndex >> 1U; u0 < bp0[bpIdx]; bpIdx--) {
    }

    while (u0 >= bp0[bpIdx + 1U]) {
      bpIdx++;
    }

    frac = div_nzp_u64_round((uint64_T)(uint16_T)((uint32_T)u0 - bp0[bpIdx]) <<
      48, (uint16_T)((uint32_T)bp0[bpIdx + 1U] - bp0[bpIdx]));
  } else {
    bpIdx = maxIndex;
    frac = 0ULL;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'round'
     Overflow mode: 'wrapping'
   */
  if (bpIdx == maxIndex) {
    y = table[bpIdx];
  } else {
    y = (int16_T)((int16_T)mul_ssu64_loSR_round(table[bpIdx + 1U] - table[bpIdx],
      frac, 48ULL) + table[bpIdx]);
  }

  return y;
}

static real32_T look1_iflf_binlx(real32_T u0, const real32_T bp0[], const
  real32_T table[], uint32_T maxIndex)
{
  real32_T frac;
  uint32_T iRght;
  uint32_T iLeft;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'binary'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Linear'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'binary'
     Extrapolation method: 'Linear'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'off'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    iLeft = 0U;
    frac = (u0 - bp0[0U]) / (bp0[1U] - bp0[0U]);
  } else if (u0 < bp0[maxIndex]) {
    /* Binary Search */
    bpIdx = maxIndex >> 1U;
    iLeft = 0U;
    iRght = maxIndex;
    while (iRght - iLeft > 1U) {
      if (u0 < bp0[bpIdx]) {
        iRght = bpIdx;
      } else {
        iLeft = bpIdx;
      }

      bpIdx = (iRght + iLeft) >> 1U;
    }

    frac = (u0 - bp0[iLeft]) / (bp0[iLeft + 1U] - bp0[iLeft]);
  } else {
    iLeft = maxIndex - 1U;
    frac = (u0 - bp0[maxIndex - 1U]) / (bp0[maxIndex] - bp0[maxIndex - 1U]);
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'off'
     Overflow mode: 'wrapping'
   */
  return (table[iLeft + 1U] - table[iLeft]) * frac + table[iLeft];
}

static int16_T look1_iu16bs16lu32n32t_Ji2sqUY0(uint16_T u0, const int16_T bp0[],
  const int16_T table[], uint32_T maxIndex)
{
  int16_T y;
  uint32_T frac;
  int16_T uCast;
  uint32_T bpIdx;
  uint16_T tmp;

  /* Column-major Lookup 1-D
     Canonical function name: look1_iu16bs16lu32n32ts16Ds32_linlcas
     Search method: 'linear'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  tmp = u0;
  if (u0 > 32767) {
    tmp = 32767U;
  }

  uCast = (int16_T)tmp;
  if (u0 < bp0[0U]) {
    bpIdx = 0U;
    frac = 0U;
  } else if (uCast < bp0[maxIndex]) {
    /* Linear Search */
    for (bpIdx = maxIndex >> 1U; uCast < bp0[bpIdx]; bpIdx--) {
    }

    while (uCast >= bp0[bpIdx + 1U]) {
      bpIdx++;
    }

    frac = (uint32_T)(((uint64_T)((uint32_T)u0 - bp0[bpIdx]) << 32) / (uint16_T)
                      (bp0[bpIdx + 1U] - bp0[bpIdx]));
  } else {
    bpIdx = maxIndex;
    frac = 0U;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  if (bpIdx == maxIndex) {
    y = table[bpIdx];
  } else {
    y = (int16_T)((int16_T)(((int64_T)(table[bpIdx + 1U] - table[bpIdx]) * frac)
      >> 32) + table[bpIdx]);
  }

  return y;
}

static int16_T look1_iu16lu64n48ts16D_Xu1w5Bqg(uint16_T u0, const uint16_T bp0[],
  const int16_T table[], uint32_T maxIndex)
{
  int16_T y;
  uint64_T frac;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Canonical function name: look1_iu16lu64n48ts16Ds32_linlcas
     Search method: 'linear'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u0 <= bp0[0U]) {
    bpIdx = 0U;
    frac = 0ULL;
  } else if (u0 < bp0[maxIndex]) {
    /* Linear Search */
    for (bpIdx = maxIndex >> 1U; u0 < bp0[bpIdx]; bpIdx--) {
    }

    while (u0 >= bp0[bpIdx + 1U]) {
      bpIdx++;
    }

    frac = ((uint64_T)(uint16_T)((uint32_T)u0 - bp0[bpIdx]) << 48) / (uint16_T)
      ((uint32_T)bp0[bpIdx + 1U] - bp0[bpIdx]);
  } else {
    bpIdx = maxIndex;
    frac = 0ULL;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  if (bpIdx == maxIndex) {
    y = table[bpIdx];
  } else {
    y = (int16_T)((int16_T)(((table[bpIdx + 1U] - table[bpIdx]) * (int64_T)frac)
      >> 48) + table[bpIdx]);
  }

  return y;
}

static real32_T look1_iu16lftf_linlca(uint16_T u0, const uint16_T bp0[], const
  real32_T table[], uint32_T maxIndex)
{
  real32_T y;
  real32_T frac;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'linear'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u0 <= bp0[0U]) {
    bpIdx = 0U;
    frac = 0.0F;
  } else if (u0 < bp0[maxIndex]) {
    /* Linear Search */
    for (bpIdx = maxIndex >> 1U; u0 < bp0[bpIdx]; bpIdx--) {
    }

    while (u0 >= bp0[bpIdx + 1U]) {
      bpIdx++;
    }

    frac = (real32_T)(uint16_T)((uint32_T)u0 - bp0[bpIdx]) / (real32_T)(uint16_T)
      ((uint32_T)bp0[bpIdx + 1U] - bp0[bpIdx]);
  } else {
    bpIdx = maxIndex;
    frac = 0.0F;
  }

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Overflow mode: 'wrapping'
   */
  if (bpIdx == maxIndex) {
    y = table[bpIdx];
  } else {
    y = (table[bpIdx + 1U] - table[bpIdx]) * frac + table[bpIdx];
  }

  return y;
}

static int16_T look2_is16lu32n32Ds32d_VMYn7zgN(int16_T u0, int16_T u1, const
  int16_T bp0[], const int16_T bp1[], const int16_T table[], const uint32_T
  maxIndex[], uint32_T stride)
{
  int16_T y;
  uint32_T frac;
  uint32_T bpIndices[2];
  uint32_T fractions[2];
  int16_T yR_1d;
  uint32_T offset_1d;
  uint32_T bpIdx;

  /* Column-major Lookup 2-D
     Canonical function name: look2_is16lu32n32Ds32ds32_linlcas
     Search method: 'linear'
     Use previous index: 'off'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u0 <= bp0[0U]) {
    bpIdx = 0U;
    frac = 0U;
  } else if (u0 < bp0[maxIndex[0U]]) {
    /* Linear Search */
    for (bpIdx = maxIndex[0U] >> 1U; u0 < bp0[bpIdx]; bpIdx--) {
    }

    while (u0 >= bp0[bpIdx + 1U]) {
      bpIdx++;
    }

    frac = (uint32_T)(((uint64_T)(uint16_T)(u0 - bp0[bpIdx]) << 32) / (uint16_T)
                      (bp0[bpIdx + 1U] - bp0[bpIdx]));
  } else {
    bpIdx = maxIndex[0U];
    frac = 0U;
  }

  fractions[0U] = frac;
  bpIndices[0U] = bpIdx;

  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Extrapolation method: 'Clip'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u1 <= bp1[0U]) {
    bpIdx = 0U;
    frac = 0U;
  } else if (u1 < bp1[maxIndex[1U]]) {
    /* Linear Search */
    for (bpIdx = maxIndex[1U] >> 1U; u1 < bp1[bpIdx]; bpIdx--) {
    }

    while (u1 >= bp1[bpIdx + 1U]) {
      bpIdx++;
    }

    frac = (uint32_T)(((uint64_T)(uint16_T)(u1 - bp1[bpIdx]) << 32) / (uint16_T)
                      (bp1[bpIdx + 1U] - bp1[bpIdx]));
  } else {
    bpIdx = maxIndex[1U];
    frac = 0U;
  }

  /* Column-major Interpolation 2-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  offset_1d = bpIdx * stride + bpIndices[0U];
  if (bpIndices[0U] == maxIndex[0U]) {
    y = table[offset_1d];
  } else {
    y = (int16_T)((int16_T)(((int64_T)(table[offset_1d + 1U] - table[offset_1d])
      * fractions[0U]) >> 32) + table[offset_1d]);
  }

  if (bpIdx == maxIndex[1U]) {
  } else {
    bpIdx = offset_1d + stride;
    if (bpIndices[0U] == maxIndex[0U]) {
      yR_1d = table[bpIdx];
    } else {
      yR_1d = (int16_T)((int16_T)(((int64_T)(table[bpIdx + 1U] - table[bpIdx]) *
        fractions[0U]) >> 32) + table[bpIdx]);
    }

    y += (int16_T)(((int64_T)(yR_1d - y) * frac) >> 32);
  }

  return y;
}

static uint16_T look1_iu16lu64n48_plinlcase(uint16_T u0, const uint16_T bp0[],
  const uint16_T table[], uint32_T prevIndex[], uint32_T maxIndex)
{
  uint16_T y;
  uint64_T frac;
  uint16_T yR_0d0;
  uint32_T bpIdx;

  /* Column-major Lookup 1-D
     Search method: 'linear'
     Use previous index: 'on'
     Interpolation method: 'Linear point-slope'
     Extrapolation method: 'Clip'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  /* Prelookup - Index and Fraction
     Index Search method: 'linear'
     Extrapolation method: 'Clip'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
     Rounding mode: 'simplest'
   */
  if (u0 <= bp0[0U]) {
    bpIdx = 0U;
    frac = 0ULL;
  } else if (u0 < bp0[maxIndex]) {
    /* Linear Search */
    for (bpIdx = prevIndex[0U]; u0 < bp0[bpIdx]; bpIdx--) {
    }

    while (u0 >= bp0[bpIdx + 1U]) {
      bpIdx++;
    }

    frac = ((uint64_T)(uint16_T)((uint32_T)u0 - bp0[bpIdx]) << 48) / (uint16_T)
      ((uint32_T)bp0[bpIdx + 1U] - bp0[bpIdx]);
  } else {
    bpIdx = maxIndex;
    frac = 0ULL;
  }

  prevIndex[0U] = bpIdx;

  /* Column-major Interpolation 1-D
     Interpolation method: 'Linear point-slope'
     Use last breakpoint for index at or above upper limit: 'on'
     Rounding mode: 'simplest'
     Overflow mode: 'wrapping'
   */
  if (bpIdx == maxIndex) {
    y = table[bpIdx];
  } else {
    yR_0d0 = table[bpIdx + 1U];
    if (yR_0d0 >= table[bpIdx]) {
      y = (uint16_T)((uint32_T)(uint16_T)(((uint16_T)((uint32_T)yR_0d0 -
        table[bpIdx]) * frac) >> 48) + table[bpIdx]);
    } else {
      y = (uint16_T)((uint32_T)table[bpIdx] - (uint16_T)(((uint16_T)((uint32_T)
        table[bpIdx] - yR_0d0) * frac) >> 48));
    }
  }

  return y;
}

static uint32_T plook_u32u8s16u32n32_evenca_gs(uint8_T u, int16_T bp0, uint16_T
  bpSpace, uint32_T *fraction)
{
  uint32_T bpIndex;
  uint32_T uAdjust;

  /* Prelookup - Index and Fraction
     Index Search method: 'even'
     Use previous index: 'off'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'on'
     Rounding mode: 'simplest'
   */
  uAdjust = (uint32_T)u - bp0;
  bpIndex = uAdjust / bpSpace;
  *fraction = (uint32_T)(((uint64_T)(uAdjust - (uint16_T)(bpIndex * bpSpace)) <<
    32) / bpSpace);
  return bpIndex;
}

static uint32_T plook_u32f_linckpa(real32_T u, const real32_T bp[], uint32_T
  maxIndex, uint32_T *prevIndex)
{
  uint32_T bpIndex;

  /* Prelookup - Index only
     Index Search method: 'linear'
     Extrapolation method: 'Clip'
     Use previous index: 'on'
     Use last breakpoint for index at or above upper limit: 'on'
     Remove protection against out-of-range input in generated code: 'off'
   */
  if (u <= bp[0U]) {
    bpIndex = 0U;
  } else if (u < bp[maxIndex]) {
    bpIndex = linsearch_u32f(u, bp, *prevIndex);
  } else {
    bpIndex = maxIndex;
  }

  *prevIndex = bpIndex;
  return bpIndex;
}

static uint32_T linsearch_u32f(real32_T u, const real32_T bp[], uint32_T
  startIndex)
{
  uint32_T bpIndex;

  /* Linear Search */
  for (bpIndex = startIndex; u < bp[bpIndex]; bpIndex--) {
  }

  while (u >= bp[bpIndex + 1U]) {
    bpIndex++;
  }

  return bpIndex;
}

static int64_T div_nzp_s64_round(int64_T numerator, int64_T denominator)
{
  uint64_T absNumerator;
  uint64_T absDenominator;
  uint64_T tempAbsQuotient;
  absNumerator = numerator < 0LL ? ~(uint64_T)numerator + 1ULL : (uint64_T)
    numerator;
  absDenominator = denominator < 0LL ? ~(uint64_T)denominator + 1ULL : (uint64_T)
    denominator;
  tempAbsQuotient = absNumerator / absDenominator;
  absNumerator %= absDenominator;
  absNumerator <<= 1ULL;
  if (absNumerator >= absDenominator) {
    tempAbsQuotient++;
  }

  return (numerator < 0LL) != (denominator < 0LL) ? -(int64_T)tempAbsQuotient :
    (int64_T)tempAbsQuotient;
}

static int32_T div_nzp_s32_round(int32_T numerator, int32_T denominator)
{
  uint32_T absNumerator;
  uint32_T absDenominator;
  uint32_T tempAbsQuotient;
  absNumerator = numerator < 0 ? ~(uint32_T)numerator + 1U : (uint32_T)numerator;
  absDenominator = denominator < 0 ? ~(uint32_T)denominator + 1U : (uint32_T)
    denominator;
  tempAbsQuotient = absNumerator / absDenominator;
  absNumerator %= absDenominator;
  absNumerator <<= 1U;
  if (absNumerator >= absDenominator) {
    tempAbsQuotient++;
  }

  return (numerator < 0) != (denominator < 0) ? -(int32_T)tempAbsQuotient :
    (int32_T)tempAbsQuotient;
}

static uint32_T div_nzp_us32_sat_round(int32_T numerator, int32_T denominator)
{
  uint32_T quotient;
  uint32_T absNumerator;
  uint32_T absDenominator;
  absNumerator = numerator < 0 ? ~(uint32_T)numerator + 1U : (uint32_T)numerator;
  absDenominator = denominator < 0 ? ~(uint32_T)denominator + 1U : (uint32_T)
    denominator;
  if ((numerator < 0) != (denominator < 0)) {
    quotient = 0U;
  } else {
    quotient = absNumerator / absDenominator;
    absNumerator %= absDenominator;
    absNumerator <<= 1U;
    if (absNumerator >= absDenominator) {
      quotient++;
    }
  }

  return quotient;
}

static uint32_T div_nzp_u32_round(uint32_T numerator, uint32_T denominator)
{
  uint32_T quotient;
  quotient = numerator / denominator;
  numerator %= denominator;
  if (numerator > 2147483647U) {
    quotient++;
  } else {
    numerator <<= 1U;
    if (numerator >= denominator) {
      quotient++;
    }
  }

  return quotient;
}

static int32_T div_nde_s32_floor(int32_T numerator, int32_T denominator)
{
  return (((numerator < 0) != (denominator < 0)) && (numerator % denominator !=
           0) ? -1 : 0) + numerator / denominator;
}

static void mul_wide_su64(int64_T in0, uint64_T in1, uint64_T *ptrOutBitsHi,
  uint64_T *ptrOutBitsLo)
{
  uint64_T outBitsLo;
  uint64_T absIn0;
  uint64_T in0Hi;
  uint64_T in1Lo;
  uint64_T in1Hi;
  uint64_T productHiLo;
  uint64_T productLoHi;
  absIn0 = in0 < 0LL ? ~(uint64_T)in0 + 1ULL : (uint64_T)in0;
  in0Hi = absIn0 >> 32ULL;
  absIn0 &= 4294967295ULL;
  in1Hi = in1 >> 32ULL;
  in1Lo = in1 & 4294967295ULL;
  productHiLo = in0Hi * in1Lo;
  productLoHi = absIn0 * in1Hi;
  absIn0 *= in1Lo;
  in1Lo = 0ULL;
  outBitsLo = (productLoHi << 32ULL) + absIn0;
  if (outBitsLo < absIn0) {
    in1Lo = 1ULL;
  }

  absIn0 = outBitsLo;
  outBitsLo += productHiLo << 32ULL;
  if (outBitsLo < absIn0) {
    in1Lo++;
  }

  absIn0 = (((productLoHi >> 32ULL) + (productHiLo >> 32ULL)) + in0Hi * in1Hi) +
    in1Lo;
  if ((in1 != 0ULL) && (in0 < 0LL)) {
    absIn0 = ~absIn0;
    outBitsLo = ~outBitsLo;
    outBitsLo++;
    if (outBitsLo == 0ULL) {
      absIn0++;
    }
  }

  *ptrOutBitsHi = absIn0;
  *ptrOutBitsLo = outBitsLo;
}

static int64_T mul_ssu64_loSR_round(int64_T a, uint64_T b, uint64_T aShift)
{
  uint64_T u64_chi;
  uint64_T u64_clo;
  mul_wide_su64(a, b, &u64_chi, &u64_clo);
  u64_clo = (((1ULL << (aShift - 1ULL) & u64_clo) != 0ULL) && (((int64_T)u64_chi
    >= 0LL) || ((((1ULL << (aShift - 1ULL)) - 1ULL) & u64_clo) != 0ULL))) +
    (u64_chi << (64ULL - aShift) | u64_clo >> aShift);
  return (int64_T)u64_clo;
}

static uint64_T div_nzp_u64_round(uint64_T numerator, uint64_T denominator)
{
  uint64_T quotient;
  quotient = numerator / denominator;
  numerator %= denominator;
  if (numerator > 9223372036854775807ULL) {
    quotient++;
  } else {
    numerator <<= 1ULL;
    if (numerator >= denominator) {
      quotient++;
    }
  }

  return quotient;
}

/*
 * Output and update for atomic system:
 *    '<S31>/Subsystem1'
 *    '<S31>/Subsystem2'
 */
static int16_T Subsystem1(int16_T rtu_Reqtrqmax)
{
  int16_T rty_LimMaxTrq_0;
  uint8_T tmp;

  /* Saturate: '<S32>/Saturation' incorporates:
   *  DataStoreRead: '<S32>/numGearEngaged'
   */
  if (numGearEngaged_vlc > 9) {
    tmp = 9U;
  } else if (numGearEngaged_vlc < 1) {
    tmp = 1U;
  } else {
    tmp = numGearEngaged_vlc;
  }

  /* End of Saturate: '<S32>/Saturation' */

  /* Lookup_n-D: '<S32>/trqLimits' incorporates:
   *  DataTypeConversion: '<S32>/Data Type Conversion'
   */
  rty_LimMaxTrq_0 = look1_is16lu32n32Ds32_linlcas(tmp, (&(GearNumber[0])),
    (&(trqLimits[0])), 8U);

  /* Switch: '<S32>/Switch_trqLimits' incorporates:
   *  RelationalOperator: '<S32>/Relational_Operator_trqLimits'
   */
  if (rtu_Reqtrqmax <= rty_LimMaxTrq_0) {
    rty_LimMaxTrq_0 = rtu_Reqtrqmax;
  }

  /* End of Switch: '<S32>/Switch_trqLimits' */
  return rty_LimMaxTrq_0;
}

real32_T rt_roundf_snf(real32_T u)
{
  real32_T y;
  if ((real32_T)fabs(u) < 8.388608E+6F) {
    if (u >= 0.5F) {
      y = (real32_T)floor(u + 0.5F);
    } else if (u > -0.5F) {
      y = u * 0.0F;
    } else {
      y = (real32_T)ceil(u - 0.5F);
    }
  } else {
    y = u;
  }

  return y;
}

real_T rt_roundd_snf(real_T u)
{
  real_T y;
  if (fabs(u) < 4.503599627370496E+15) {
    if (u >= 0.5) {
      y = floor(u + 0.5);
    } else if (u > -0.5) {
      y = u * 0.0;
    } else {
      y = ceil(u - 0.5);
    }
  } else {
    y = u;
  }

  return y;
}

/* Model step function */
void VLCforADAS_UMP_step(void)
{
  uint32_T frac;
  int8_T rtPrevAction;
  int8_T rtAction;
  int16_T rtb_EngineTorque;
  real32_T rtb_Divide1_b;
  real32_T rtb_Divide1_l;
  real32_T rtb_Divide_c;
  real32_T rtb_Divide6;
  real32_T rtb_Divide;
  real32_T rtb_slip_koef;
  real32_T rtb_Gain6;
  real32_T rtb_Saturation_pc;
  real32_T rtb_Add3_ag;
  real32_T rtb_Add_lz;
  real32_T rtb_DataTypeConversion2_f;
  boolean_T rtb_RelationalOperator1_ce;
  uint8_T rtb_gsinalpha;
  boolean_T rtb_RelationalOperator2_d;
  real32_T rtb_Subtract_hq;
  uint8_T rtb_Switch1_k;
  uint8_T rtb_Switch1_fs;
  int32_T rtb_Saturation2;
  boolean_T rtb_LessThan[9];
  boolean_T rtb_RelationalOperator2_md;
  uint16_T rtb_DataTypeConversion_ai;
  uint32_T rtb_EngineRPM;
  int32_T rtb_Product1_l;
  int16_T rtb_Switch_e;
  int16_T rtb_DataTypeConversion_j;
  int16_T rtb_Saturation_o;
  int16_T rtb_Abs1;
  int16_T rtb_Abs_g;
  uint32_T rtb_DataTypeConversion_hs;
  uint16_T rtb_Switch1_hj;
  int64_T tmp;
  int64_T tmp_0;
  uint64_T tmp_1;
  uint32_T tmp_2;
  real32_T u0;
  uint8_T rtb_Switch1_dn;
  uint16_T tmp_3;
  uint16_T tmp_4;
  real_T rtb_OLD_NEW_ACCSTAT_p_tmp;

  /* Outputs for Atomic SubSystem: '<S1>/Input Processing1' */
  /* Outputs for Atomic SubSystem: '<S4>/VehicleSpeed_Processing1' */
  /* DataTypeConversion: '<S111>/Data Type Conversion' incorporates:
   *  Constant: '<S111>/Constant2'
   *  Constant: '<S111>/Constant4'
   *  DataStoreRead: '<S1>/wheelSpeedFL'
   *  DataStoreRead: '<S1>/wheelSpeedFR'
   *  Product: '<S111>/Divide1'
   *  Product: '<S111>/Divide3'
   *  Sum: '<S111>/Add'
   */
  rtb_DataTypeConversion_ai = (uint16_T)rt_roundf_snf((WheelSpdFrontLeft +
    WheelSpdFrontRight) / 2.0F / 3.6F * 100.0F);

  /* End of Outputs for SubSystem: '<S4>/VehicleSpeed_Processing1' */

  /* DataStoreWrite: '<S4>/objectSpeed' */
  objectSpeed = rtb_DataTypeConversion_ai;

  /* DataStoreWrite: '<S4>/numGearEngaged' incorporates:
   *  DataStoreRead: '<S1>/numGearEngaged'
   *  SignalConversion: '<S4>/TmpSignal ConversionAtData Type Conversion6Inport1'
   */
  numGearEngaged_vlc = GearEngNum;

  /* DataTypeConversion: '<S4>/Data Type Conversion5' incorporates:
   *  DataStoreRead: '<S1>/M_MotClutch'
   */
  rtb_EngineTorque = (int16_T)rt_roundf_snf(TrqClutch);

  /* DataStoreWrite: '<S4>/EngineTorque' */
  EngineTorque = rtb_EngineTorque;

  /* DataTypeConversion: '<S4>/Data Type Conversion2' incorporates:
   *  DataStoreRead: '<S1>/nICEngineSpeed1'
   *  DataStoreWrite: '<S4>/EngineRPM'
   *  DataTypeConversion: '<S4>/Data Type Conversion4'
   */
  rtb_Switch1_hj = (uint16_T)rt_roundf_snf(EngineSpeed);
  EngineRPM = rtb_Switch1_hj;

  /* Outputs for Atomic SubSystem: '<S4>/LongitudinalAccelerationProc_Processing' */
  /* Product: '<S107>/Divide1' incorporates:
   *  Constant: '<S107>/Constant1'
   *  DataStoreRead: '<S1>/AX'
   */
  rtb_Divide1_b = LongAccel * 9.81F;

  /* End of Outputs for SubSystem: '<S4>/LongitudinalAccelerationProc_Processing' */

  /* DataStoreWrite: '<S4>/Data Store Write1' */
  LongitudinalAccelerationProc = rtb_Divide1_b;

  /* DataStoreWrite: '<S4>/ACCStat' incorporates:
   *  DataStoreRead: '<S1>/pWheelRR1'
   *  Inport: '<S4>/ACCStat_in'
   */
  ACCStat = AccActive;

  /* Outputs for Atomic SubSystem: '<S4>/LateralAccelerationProc_Processing' */
  /* Product: '<S106>/Divide1' incorporates:
   *  Constant: '<S106>/Constant1'
   *  DataStoreRead: '<S1>/AX1'
   */
  rtb_Divide1_l = LateralAccel * 9.81F;

  /* End of Outputs for SubSystem: '<S4>/LateralAccelerationProc_Processing' */

  /* DataStoreWrite: '<S4>/AY' */
  AY_vlc = rtb_Divide1_l;

  /* Outputs for Atomic SubSystem: '<S4>/PSIP_Processing' */
  /* Product: '<S109>/Divide' incorporates:
   *  Constant: '<S109>/Const_180(1)'
   *  Constant: '<S109>/Pi'
   *  DataStoreRead: '<S1>/AX2'
   *  Product: '<S109>/Divide1'
   */
  rtb_Divide_c = YawRate * 3.14F / 180.0F;

  /* End of Outputs for SubSystem: '<S4>/PSIP_Processing' */

  /* DataStoreWrite: '<S4>/PSIP' */
  PSIP = rtb_Divide_c;

  /* DataStoreWrite: '<S4>/PSIP1' incorporates:
   *  DataStoreRead: '<S1>/AX3'
   *  SignalConversion: '<S4>/TmpSignal ConversionAtData Type Conversion18Inport1'
   */
  SAS_angle_vlc = SasAng;

  /* Outputs for Atomic SubSystem: '<S4>/M_MotDrug_Processing' */
  /* DataTypeConversion: '<S108>/Data Type Conversion' incorporates:
   *  DataStoreRead: '<S1>/M_MotDrag'
   *  DataStoreWrite: '<S4>/EngineDrag'
   */
  EngineDrag = (int16_T)rt_roundf_snf(DragTrq);

  /* End of Outputs for SubSystem: '<S4>/M_MotDrug_Processing' */

  /* DataTypeConversion: '<S4>/Data Type Conversion4' incorporates:
   *  DataStoreWrite: '<S4>/nICEngineSpeed2'
   */
  nICEngineSpeed_vlc = rtb_Switch1_hj;

  /* DataTypeConversion: '<S4>/Data Type Conversion3' incorporates:
   *  DataStoreRead: '<S1>/ratAccPed'
   *  DataStoreWrite: '<S4>/accelerationPedal'
   */
  accelerationPedal = (uint16_T)rt_roundf_snf(AccelPedalPos * 8.0F);

  /* DataTypeConversion: '<S4>/Data Type Conversion1' incorporates:
   *  DataStoreRead: '<S1>/VehicleSpeed'
   *  DataStoreWrite: '<S4>/VehicleSpeed'
   */
  VehicleSpeed_VLCInt = (uint16_T)rt_roundf_snf(VehicleSpd * 100.0F);

  /* DataStoreWrite: '<S4>/numGearTarget_in' incorporates:
   *  DataStoreRead: '<S1>/numGearTarget'
   */
  numGearTarget_vlc = GearTargetNum;

  /* DataStoreWrite: '<S4>/pWheelFL_in' incorporates:
   *  DataStoreRead: '<S1>/pWheelFL'
   */
  pWheelFL_vlc = WheelBrakePressureFrontLeft;

  /* DataStoreWrite: '<S4>/pWheelFR_in' incorporates:
   *  DataStoreRead: '<S1>/pWheelFR'
   */
  pWheelFR_vlc = WheelBrakePressureFrontRight;

  /* DataStoreWrite: '<S4>/pWheelFL_in1' incorporates:
   *  DataStoreRead: '<S1>/pWheelRL'
   */
  pWheelRL_vlc = WheelBrakePressureRearLeft;

  /* DataStoreWrite: '<S4>/pWheelRR_in' incorporates:
   *  DataStoreRead: '<S1>/pWheelRR'
   */
  pWheelRR_vlc = WheelBrakePressureRearRight;

  /* DataTypeConversion: '<S4>/Data Type Conversion16' incorporates:
   *  DataStoreRead: '<S4>/gearChangeSPDphase'
   *  DataStoreWrite: '<S4>/gearShift'
   */
  gearShift = GearChange;

  /* DataStoreWrite: '<S4>/VLC_Available' incorporates:
   *  DataStoreRead: '<S4>/VLC_RX.ACCMotIncReqFlag_read'
   */
  VLC_Available = VlcTrqActive;

  /* DataTypeConversion: '<S4>/Data Type Conversion7' incorporates:
   *  DataStoreRead: '<S1>/reqAcceleration_in'
   *  DataStoreWrite: '<S1>/reqAcceleration'
   */
  reqAcceleration = (int16_T)rt_roundf_snf(AccelReq * 100.0F);

  /* Outputs for Atomic SubSystem: '<S4>/targetSpeed_Processing' */
  /* Outputs for Atomic SubSystem: '<S113>/targetSpeed_ICrecalculation' */
  /* Product: '<S113>/Divide' incorporates:
   *  Constant: '<S114>/Constant3'
   *  DataStoreRead: '<S1>/targetSpeed_in'
   *  DataStoreWrite: '<S1>/targetSpeed'
   *  Sum: '<S114>/Subtract1'
   */
  tmp_2 = (uint16_T)div_nzp_u32_round((uint32_T)(uint16_T)((uint32_T)(uint16_T)
    rt_roundf_snf(SpeedTarget * 100.0F) + TargetSpdOffSet) << 1, 9U) * 5U;

  /* End of Outputs for SubSystem: '<S113>/targetSpeed_ICrecalculation' */
  targetSpeed = (uint16_T)(((tmp_2 & 2U) != 0U) + (tmp_2 >> 2));

  /* End of Outputs for SubSystem: '<S4>/targetSpeed_Processing' */

  /* Outputs for Atomic SubSystem: '<S4>/VehicleSpeed_Processing2' */
  /* Product: '<S112>/Divide1' incorporates:
   *  Constant: '<S112>/Constant2'
   *  DataStoreRead: '<S1>/wheelSpeedRL'
   *  DataStoreRead: '<S1>/wheelSpeedRR'
   *  Sum: '<S112>/Add'
   */
  u0 = (WheelSpdRearRight + WheelSpdRearLeft) / 2.0F;

  /* Saturate: '<S112>/Saturation' */
  if (u0 > 200.0F) {
    u0 = 200.0F;
  } else {
    if (u0 < 2.0F) {
      u0 = 2.0F;
    }
  }

  /* End of Saturate: '<S112>/Saturation' */

  /* DataTypeConversion: '<S112>/Data Type Conversion' incorporates:
   *  Constant: '<S112>/Constant4'
   *  DataStoreWrite: '<S1>/cardanSpeed'
   *  Product: '<S112>/Divide3'
   */
  cardanSpeed = (uint16_T)rt_roundf_snf(u0 / 3.6F * 100.0F);

  /* End of Outputs for SubSystem: '<S4>/VehicleSpeed_Processing2' */

  /* DataTypeConversion: '<S4>/Data Type Conversion8' incorporates:
   *  DataStoreRead: '<S1>/nICEngineSpeed1'
   */
  rtb_EngineRPM = (uint32_T)rt_roundf_snf(EngineSpeed * 100.0F);

  /* End of Outputs for SubSystem: '<S1>/Input Processing1' */

  /* Delay: '<S1>/Delay1' incorporates:
   *  DataStoreWrite: '<S1>/targetSpeed2'
   */
  targetSpeedDelay = rtDW.Delay1_DSTATE_c;

  /* Outputs for Atomic SubSystem: '<S1>/Road Grade Calculation' */
  /* Saturate: '<S6>/Saturation' incorporates:
   *  DataTypeConversion: '<S133>/Data Type Conversion'
   *  Product: '<S133>/Product2'
   */
  rtb_Saturation_pc = (real32_T)rtb_DataTypeConversion_ai * 0.01F;
  if (rtb_Saturation_pc > VehicleSpeed_SlopeGradMaxSpd) {
    rtb_slip_koef = VehicleSpeed_SlopeGradMaxSpd;
  } else {
    rtb_slip_koef = rtb_Saturation_pc;
  }

  /* End of Saturate: '<S6>/Saturation' */

  /* Lookup_n-D: '<S6>/VehicleSpeed_SlopeGrad' */
  rtb_Divide6 = look1_iflf_plinlca(rtb_slip_koef, (&(VehicleSpeed_SlopeGradBP[0])),
    (&(VehicleSpeed_SlopeGradTD[0])), &rtDW.m_bpIndex, 6U);

  /* Gain: '<S6>/Gain6' */
  rtb_Gain6 = 0.01F * rtb_Divide6;

  /* Delay: '<S133>/Delay' */
  if (rtDW.icLoad != 0) {
    rtDW.Delay_DSTATE = rtb_Saturation_pc;
  }

  /* Sum: '<S133>/Add3' incorporates:
   *  Constant: '<S133>/Constant3'
   *  Constant: '<S133>/Constant4'
   *  Delay: '<S133>/Delay'
   *  Product: '<S133>/Product2'
   *  Product: '<S133>/Product5'
   *  Sum: '<S133>/Add2'
   */
  rtb_Divide6 = rtb_Saturation_pc * VehicleSpeed_f + (1.0F - VehicleSpeed_f) *
    rtDW.Delay_DSTATE;

  /* Saturate: '<S133>/Saturation' */
  if (rtb_Divide6 > 250.0F) {
    rtb_Saturation_pc = 250.0F;
  } else if (rtb_Divide6 < 0.0F) {
    rtb_Saturation_pc = 0.0F;
  } else {
    rtb_Saturation_pc = rtb_Divide6;
  }

  /* End of Saturate: '<S133>/Saturation' */

  /* Product: '<S6>/Divide' incorporates:
   *  Constant: '<S6>/Constant'
   *  Delay: '<S6>/Delay1'
   *  Delay: '<S6>/Delay2'
   *  Gain: '<S6>/Gain'
   *  Gain: '<S6>/Gain1'
   *  Sum: '<S6>/Add4'
   */
  rtb_Divide = (real32_T)(((3.0F * rtb_Saturation_pc - 4.0F * rtDW.Delay2_DSTATE)
    + rtDW.Delay1_DSTATE[0]) / 0.02);

  /* Delay: '<S131>/Delay' */
  if (rtDW.icLoad_c != 0) {
    rtDW.Delay_DSTATE_j = rtb_Divide;
  }

  /* Sum: '<S131>/Add3' incorporates:
   *  Constant: '<S131>/Constant3'
   *  Constant: '<S131>/Constant4'
   *  Delay: '<S131>/Delay'
   *  Product: '<S131>/Product2'
   *  Product: '<S131>/Product5'
   *  Sum: '<S131>/Add2'
   */
  rtb_Add3_ag = rtb_Divide * 0.1F + 0.9F * rtDW.Delay_DSTATE_j;

  /* Saturate: '<S131>/Saturation' */
  if (rtb_Add3_ag > 9.81F) {
    u0 = 9.81F;
  } else if (rtb_Add3_ag < -9.81F) {
    u0 = -9.81F;
  } else {
    u0 = rtb_Add3_ag;
  }

  /* End of Saturate: '<S131>/Saturation' */

  /* Sum: '<S6>/Add' */
  rtb_Add_lz = rtb_Divide1_b - u0;

  /* Delay: '<S6>/Delay8' */
  if (rtDW.icLoad_m != 0) {
    rtDW.Delay8_DSTATE = rtb_Add_lz;
  }

  /* Delay: '<S6>/Delay3' */
  if (rtDW.icLoad_mz != 0) {
    rtDW.Delay3_DSTATE = rtb_Add_lz;
  }

  /* Delay: '<S6>/Delay6' */
  if (rtDW.icLoad_n != 0) {
    rtDW.Delay6_DSTATE = rtb_Add_lz;
  }

  /* Gain: '<S6>/Gain2' incorporates:
   *  Delay: '<S6>/Delay3'
   *  Delay: '<S6>/Delay6'
   *  Sum: '<S6>/Add8'
   */
  rtb_OLD_NEW_ACCSTAT_p_tmp = ((rtb_Add_lz + rtDW.Delay3_DSTATE) +
    rtDW.Delay6_DSTATE) * 0.3333333432674408;

  /* Delay: '<S6>/Delay5' */
  if (rtDW.icLoad_e != 0) {
    rtDW.Delay5_DSTATE = rtb_Add_lz;
  }

  /* Switch: '<S6>/Switch1' incorporates:
   *  Abs: '<S6>/Abs1'
   *  Abs: '<S6>/Abs2'
   *  Constant: '<S127>/Constant'
   *  Constant: '<S128>/Constant'
   *  DataTypeConversion: '<S6>/Data Type Conversion2'
   *  Delay: '<S6>/Delay5'
   *  Delay: '<S6>/Delay8'
   *  Logic: '<S6>/Logical Operator'
   *  RelationalOperator: '<S127>/Compare'
   *  RelationalOperator: '<S128>/Compare'
   *  Sum: '<S6>/Add1'
   *  Sum: '<S6>/Add2'
   */
  if (((real32_T)fabs((real32_T)rtb_OLD_NEW_ACCSTAT_p_tmp - rtb_Add_lz) >=
       0.005F) && ((real32_T)fabs(rtDW.Delay5_DSTATE - (real32_T)
        rtb_OLD_NEW_ACCSTAT_p_tmp) <= 0.1F)) {
    rtb_DataTypeConversion2_f = rtDW.Delay8_DSTATE;
  } else {
    rtb_DataTypeConversion2_f = rtb_Add_lz;
  }

  /* End of Switch: '<S6>/Switch1' */

  /* Outputs for Atomic SubSystem: '<S6>/LinearGradeControl2' */
  /* Delay: '<S134>/Delay1' */
  if (rtDW.icLoad_k != 0) {
    rtDW.Delay1_DSTATE_p = rtb_DataTypeConversion2_f;
  }

  /* Sum: '<S134>/Subtract' incorporates:
   *  Delay: '<S134>/Delay1'
   */
  rtb_Subtract_hq = rtb_DataTypeConversion2_f - rtDW.Delay1_DSTATE_p;

  /* Switch: '<S134>/Switch' incorporates:
   *  RelationalOperator: '<S134>/Relational Operator'
   */
  if (!(rtb_Gain6 < rtb_Subtract_hq)) {
    /* Gain: '<S6>/Gain9' */
    rtb_Gain6 = -rtb_Gain6;

    /* Switch: '<S134>/Switch1' incorporates:
     *  RelationalOperator: '<S134>/Relational Operator1'
     */
    if (rtb_Subtract_hq > rtb_Gain6) {
      rtb_Gain6 = rtb_Subtract_hq;
    }

    /* End of Switch: '<S134>/Switch1' */
  }

  /* End of Switch: '<S134>/Switch' */

  /* Sum: '<S134>/Add' incorporates:
   *  Delay: '<S134>/Delay1'
   */
  rtb_Subtract_hq = rtb_Gain6 + rtDW.Delay1_DSTATE_p;

  /* Update for Delay: '<S134>/Delay1' */
  rtDW.icLoad_k = 0U;
  rtDW.Delay1_DSTATE_p = rtb_Subtract_hq;

  /* End of Outputs for SubSystem: '<S6>/LinearGradeControl2' */

  /* Abs: '<S6>/Abs3' */
  rtb_Gain6 = (real32_T)fabs(rtb_Subtract_hq);

  /* RelationalOperator: '<S6>/Relational Operator1' incorporates:
   *  Constant: '<S6>/SlopeHystInc'
   *  Delay: '<S6>/Delay'
   *  Sum: '<S6>/Subtract2'
   */
  rtb_RelationalOperator1_ce = (rtb_Gain6 > SlopeHystInc + rtDW.SlopeOutput);

  /* Lookup_n-D: '<S6>/VehicleSpeed_SlopeGrad1' */
  rtb_slip_koef = look1_iflf_plinlca(rtb_slip_koef, (&(VehicleSpeed_SlopeGradBP
    [0])), (&(SlopeApproveTmr[0])), &rtDW.m_bpIndex_b, 6U);

  /* DataTypeConversion: '<S6>/Data Type Conversion5' */
  rtb_gsinalpha = (uint8_T)rt_roundf_snf(rtb_slip_koef);

  /* Outputs for Atomic SubSystem: '<S6>/Protection timer3' */
  /* Delay: '<S137>/Delay1' */
  if (rtDW.icLoad_g != 0) {
    rtDW.Delay1_DSTATE_g = rtb_RelationalOperator1_ce;
  }

  /* Switch: '<S137>/Switch1' incorporates:
   *  Constant: '<S137>/Constant2'
   *  Delay: '<S137>/Delay1'
   *  RelationalOperator: '<S137>/Relational Operator2'
   */
  if (rtb_RelationalOperator1_ce == rtDW.Delay1_DSTATE_g) {
    /* Switch: '<S137>/Switch2' incorporates:
     *  Constant: '<S137>/Constant1'
     *  Delay: '<S137>/Delay'
     *  RelationalOperator: '<S137>/Relational Operator1'
     *  Sum: '<S137>/Add'
     */
    if (rtDW.Delay_DSTATE_o1 < rtb_gsinalpha) {
      rtb_Switch1_k = (uint8_T)(rtDW.Delay_DSTATE_o1 + 1U);
    } else {
      rtb_Switch1_k = rtb_gsinalpha;
    }

    /* End of Switch: '<S137>/Switch2' */
  } else {
    rtb_Switch1_k = 0U;
  }

  /* End of Switch: '<S137>/Switch1' */

  /* Update for Delay: '<S137>/Delay' */
  rtDW.Delay_DSTATE_o1 = rtb_Switch1_k;

  /* Update for Delay: '<S137>/Delay1' */
  rtDW.icLoad_g = 0U;
  rtDW.Delay1_DSTATE_g = rtb_RelationalOperator1_ce;

  /* End of Outputs for SubSystem: '<S6>/Protection timer3' */

  /* RelationalOperator: '<S6>/Relational Operator2' incorporates:
   *  Constant: '<S6>/SlopeHystDec'
   *  Delay: '<S6>/Delay'
   *  Sum: '<S6>/Subtract1'
   */
  rtb_RelationalOperator2_d = (rtDW.SlopeOutput + SlopeHystDec > rtb_Gain6);

  /* Outputs for Atomic SubSystem: '<S6>/Protection timer2' */
  /* Delay: '<S136>/Delay1' */
  if (rtDW.icLoad_ov != 0) {
    rtDW.Delay1_DSTATE_cg = rtb_RelationalOperator2_d;
  }

  /* Switch: '<S136>/Switch1' incorporates:
   *  Constant: '<S136>/Constant2'
   *  Delay: '<S136>/Delay1'
   *  RelationalOperator: '<S136>/Relational Operator2'
   */
  if (rtb_RelationalOperator2_d == rtDW.Delay1_DSTATE_cg) {
    /* Switch: '<S136>/Switch2' incorporates:
     *  Constant: '<S136>/Constant1'
     *  Delay: '<S136>/Delay'
     *  RelationalOperator: '<S136>/Relational Operator1'
     *  Sum: '<S136>/Add'
     */
    if (rtDW.Delay_DSTATE_fu < rtb_gsinalpha) {
      rtb_Switch1_fs = (uint8_T)(rtDW.Delay_DSTATE_fu + 1U);
    } else {
      rtb_Switch1_fs = rtb_gsinalpha;
    }

    /* End of Switch: '<S136>/Switch2' */
  } else {
    rtb_Switch1_fs = 0U;
  }

  /* End of Switch: '<S136>/Switch1' */

  /* Update for Delay: '<S136>/Delay' */
  rtDW.Delay_DSTATE_fu = rtb_Switch1_fs;

  /* Update for Delay: '<S136>/Delay1' */
  rtDW.icLoad_ov = 0U;
  rtDW.Delay1_DSTATE_cg = rtb_RelationalOperator2_d;

  /* End of Outputs for SubSystem: '<S6>/Protection timer2' */

  /* Chart: '<S6>/Chart' incorporates:
   *  Delay: '<S6>/Delay'
   *  RelationalOperator: '<S136>/Relational Operator'
   *  RelationalOperator: '<S137>/Relational Operator'
   *  Switch: '<S136>/Switch'
   *  Switch: '<S137>/Switch'
   */
  /* Gateway: andrukhe/Road Grade Calculation/Chart */
  /* During: andrukhe/Road Grade Calculation/Chart */
  if (rtDW.is_active_c2_VLCforADAS_UMP == 0U) {
    /* Entry: andrukhe/Road Grade Calculation/Chart */
    rtDW.is_active_c2_VLCforADAS_UMP = 1U;

    /* Entry Internal: andrukhe/Road Grade Calculation/Chart */
    /* Transition: '<S126>:6' */
    rtDW.is_c2_VLCforADAS_UMP = IN_Hold;

    /* Entry 'Hold': '<S126>:5' */
  } else {
    switch (rtDW.is_c2_VLCforADAS_UMP) {
     case IN_Dec:
      /* During 'Dec': '<S126>:7' */
      if (rtDW.SlopeOutput == rtDW.SlopeOutput) {
        /* Transition: '<S126>:8' */
        rtDW.is_c2_VLCforADAS_UMP = IN_Hold;

        /* Entry 'Hold': '<S126>:5' */
      }
      break;

     case IN_Hold:
      /* Outputs for Atomic SubSystem: '<S6>/Protection timer2' */
      /* During 'Hold': '<S126>:5' */
      if ((rtb_Switch1_fs == rtb_gsinalpha) && rtb_RelationalOperator2_d) {
        /* Transition: '<S126>:9' */
        rtDW.is_c2_VLCforADAS_UMP = IN_Dec;

        /* Entry 'Dec': '<S126>:7' */
        rtDW.SlopeOutput -= 0.2F;
      } else {
        /* Outputs for Atomic SubSystem: '<S6>/Protection timer3' */
        if ((rtb_Switch1_k == rtb_gsinalpha) && rtb_RelationalOperator1_ce) {
          /* Transition: '<S126>:11' */
          rtDW.is_c2_VLCforADAS_UMP = IN_Inc;

          /* Entry 'Inc': '<S126>:10' */
          rtDW.SlopeOutput += 0.2F;
        }

        /* End of Outputs for SubSystem: '<S6>/Protection timer3' */
      }

      /* End of Outputs for SubSystem: '<S6>/Protection timer2' */
      break;

     default:
      /* During 'Inc': '<S126>:10' */
      if (rtDW.SlopeOutput == rtDW.SlopeOutput) {
        /* Transition: '<S126>:12' */
        rtDW.is_c2_VLCforADAS_UMP = IN_Hold;

        /* Entry 'Hold': '<S126>:5' */
      }
      break;
    }
  }

  /* End of Chart: '<S6>/Chart' */

  /* Signum: '<S6>/Sign1' */
  if (rtb_Subtract_hq < 0.0F) {
    rtb_slip_koef = -1.0F;
  } else if (rtb_Subtract_hq > 0.0F) {
    rtb_slip_koef = 1.0F;
  } else if (rtb_Subtract_hq == 0.0F) {
    rtb_slip_koef = 0.0F;
  } else {
    rtb_slip_koef = (rtNaNF);
  }

  /* End of Signum: '<S6>/Sign1' */

  /* Outputs for Atomic SubSystem: '<S6>/Protection timer1' */
  /* Delay: '<S135>/Delay1' */
  if (rtDW.icLoad_b != 0) {
    rtDW.Delay1_DSTATE_f = rtb_slip_koef;
  }

  /* Switch: '<S135>/Switch1' incorporates:
   *  Constant: '<S135>/Constant2'
   *  Delay: '<S135>/Delay1'
   *  RelationalOperator: '<S135>/Relational Operator2'
   */
  if (rtb_slip_koef == rtDW.Delay1_DSTATE_f) {
    /* Switch: '<S135>/Switch2' incorporates:
     *  Constant: '<S135>/Constant1'
     *  Delay: '<S135>/Delay'
     *  RelationalOperator: '<S135>/Relational Operator1'
     *  Sum: '<S135>/Add'
     */
    if (rtDW.Delay_DSTATE_m < rtb_gsinalpha) {
      rtb_Switch1_k = (uint8_T)(rtDW.Delay_DSTATE_m + 1U);
    } else {
      rtb_Switch1_k = rtb_gsinalpha;
    }

    /* End of Switch: '<S135>/Switch2' */
  } else {
    rtb_Switch1_k = 0U;
  }

  /* End of Switch: '<S135>/Switch1' */

  /* Switch: '<S135>/Switch' incorporates:
   *  Delay: '<S135>/Delay2'
   *  RelationalOperator: '<S135>/Relational Operator'
   */
  if (rtb_Switch1_k == rtb_gsinalpha) {
    rtb_Gain6 = rtb_slip_koef;
  } else {
    rtb_Gain6 = rtDW.Delay2_DSTATE_n;
  }

  /* End of Switch: '<S135>/Switch' */

  /* Update for Delay: '<S135>/Delay' */
  rtDW.Delay_DSTATE_m = rtb_Switch1_k;

  /* Update for Delay: '<S135>/Delay1' */
  rtDW.icLoad_b = 0U;
  rtDW.Delay1_DSTATE_f = rtb_slip_koef;

  /* Update for Delay: '<S135>/Delay2' */
  rtDW.Delay2_DSTATE_n = rtb_Gain6;

  /* End of Outputs for SubSystem: '<S6>/Protection timer1' */

  /* Product: '<S6>/Product2' */
  rtb_slip_koef = rtDW.SlopeOutput * rtb_Gain6;

  /* DataStoreWrite: '<S6>/AngleEstimation_fin' */
  AngEstimate = rtb_slip_koef;

  /* Delay: '<S129>/Delay' */
  if (rtDW.icLoad_nf != 0) {
    rtDW.Delay_DSTATE_p = rtb_Divide1_b;
  }

  /* Sum: '<S129>/Add3' incorporates:
   *  Constant: '<S129>/Constant3'
   *  Constant: '<S129>/Constant4'
   *  Delay: '<S129>/Delay'
   *  Product: '<S129>/Product2'
   *  Product: '<S129>/Product5'
   *  Sum: '<S129>/Add2'
   */
  rtb_Divide1_b = (1.0F - AX_YRS_f) * rtDW.Delay_DSTATE_p + rtb_Divide1_b *
    AX_YRS_f;

  /* Delay: '<S130>/Delay' */
  if (rtDW.icLoad_n1 != 0) {
    rtDW.Delay_DSTATE_l = rtb_Divide;
  }

  /* Sum: '<S130>/Add3' incorporates:
   *  Constant: '<S130>/Constant3'
   *  Constant: '<S130>/Constant4'
   *  Delay: '<S130>/Delay'
   *  Product: '<S130>/Product2'
   *  Product: '<S130>/Product5'
   *  Sum: '<S130>/Add2'
   */
  rtb_Divide = (1.0F - LongitudinalAcceleration_f) * rtDW.Delay_DSTATE_l +
    rtb_Divide * LongitudinalAcceleration_f;

  /* Saturate: '<S129>/Saturation' */
  if (rtb_Divide1_b > 9.81F) {
    rtb_Gain6 = 9.81F;
  } else if (rtb_Divide1_b < -9.81F) {
    rtb_Gain6 = -9.81F;
  } else {
    rtb_Gain6 = rtb_Divide1_b;
  }

  /* End of Saturate: '<S129>/Saturation' */

  /* Saturate: '<S130>/Saturation' */
  if (rtb_Divide > 9.81F) {
    u0 = 9.81F;
  } else if (rtb_Divide < -9.81F) {
    u0 = -9.81F;
  } else {
    u0 = rtb_Divide;
  }

  /* End of Saturate: '<S130>/Saturation' */

  /* Sum: '<S6>/Subtract' */
  rtb_Subtract_hq = rtb_Gain6 - u0;

  /* Delay: '<S132>/Delay' */
  if (rtDW.icLoad_o != 0) {
    rtDW.Delay_DSTATE_c = rtb_Subtract_hq;
  }

  /* Sum: '<S132>/Add3' incorporates:
   *  Constant: '<S132>/Constant3'
   *  Constant: '<S132>/Constant4'
   *  Delay: '<S132>/Delay'
   *  Product: '<S132>/Product2'
   *  Product: '<S132>/Product5'
   *  Sum: '<S132>/Add2'
   */
  rtb_Subtract_hq = (1.0F - RoadangleAcceleration_f) * rtDW.Delay_DSTATE_c +
    rtb_Subtract_hq * RoadangleAcceleration_f;

  /* Saturate: '<S132>/Saturation' */
  if (rtb_Subtract_hq > 9.81F) {
    rtb_Gain6 = 9.81F;
  } else if (rtb_Subtract_hq < -9.81F) {
    rtb_Gain6 = -9.81F;
  } else {
    rtb_Gain6 = rtb_Subtract_hq;
  }

  /* End of Saturate: '<S132>/Saturation' */

  /* Switch: '<S138>/Switch' incorporates:
   *  DataStoreRead: '<S138>/CrsCtlAndAcc'
   *  DataStoreRead: '<S138>/reqAcceleration'
   *  DataStoreRead: '<S138>/reqAccelerationLimited'
   */
  if (VlcActive > 0) {
    u0 = (real32_T)reqAccelerationLimited * 0.001953125F;
  } else {
    u0 = (real32_T)reqAcceleration * 0.01F;
  }

  /* End of Switch: '<S138>/Switch' */

  /* Sum: '<S138>/Add1' incorporates:
   *  DataStoreWrite: '<S6>/Data Store Write'
   *  Lookup_n-D: '<S138>/RoadgradeOffset_LT'
   */
  AngleEstimation = rtb_Gain6 - look1_iflf_linlca(u0,
    (&(Offset_roadgrade_accelerations[0])), (&(Offset_roadgrade_table[0])), 10U);

  /* Update for Delay: '<S133>/Delay' */
  rtDW.icLoad = 0U;
  rtDW.Delay_DSTATE = rtb_Divide6;

  /* Update for Delay: '<S6>/Delay2' */
  rtDW.Delay2_DSTATE = rtb_Saturation_pc;

  /* Update for Delay: '<S6>/Delay1' */
  rtDW.Delay1_DSTATE[0] = rtDW.Delay1_DSTATE[1];
  rtDW.Delay1_DSTATE[1] = rtb_Saturation_pc;

  /* Update for Delay: '<S131>/Delay' */
  rtDW.icLoad_c = 0U;
  rtDW.Delay_DSTATE_j = rtb_Add3_ag;

  /* Update for Delay: '<S6>/Delay8' */
  rtDW.icLoad_m = 0U;
  rtDW.Delay8_DSTATE = rtb_DataTypeConversion2_f;

  /* Update for Delay: '<S6>/Delay3' */
  rtDW.icLoad_mz = 0U;
  rtDW.Delay3_DSTATE = rtb_Add_lz;

  /* Update for Delay: '<S6>/Delay6' incorporates:
   *  DataTypeConversion: '<S6>/Data Type Conversion2'
   *  Gain: '<S6>/Gain2'
   */
  rtDW.icLoad_n = 0U;
  rtDW.Delay6_DSTATE = (real32_T)rtb_OLD_NEW_ACCSTAT_p_tmp;

  /* Update for Delay: '<S6>/Delay5' */
  rtDW.icLoad_e = 0U;
  rtDW.Delay5_DSTATE = rtb_DataTypeConversion2_f;

  /* Update for Delay: '<S129>/Delay' */
  rtDW.icLoad_nf = 0U;
  rtDW.Delay_DSTATE_p = rtb_Divide1_b;

  /* Update for Delay: '<S130>/Delay' */
  rtDW.icLoad_n1 = 0U;
  rtDW.Delay_DSTATE_l = rtb_Divide;

  /* Update for Delay: '<S132>/Delay' */
  rtDW.icLoad_o = 0U;
  rtDW.Delay_DSTATE_c = rtb_Subtract_hq;

  /* End of Outputs for SubSystem: '<S1>/Road Grade Calculation' */

  /* If: '<S1>/If3' incorporates:
   *  Constant: '<S1>/Constant3'
   *  Constant: '<S28>/Constant'
   *  DataStoreRead: '<S1>/CruiseControlType'
   *  DataStoreRead: '<S1>/PilotlessPermit1'
   *  Logic: '<S1>/AND'
   *  RelationalOperator: '<S1>/Relational Operator4'
   */
  rtPrevAction = rtDW.If3_ActiveSubsystem;
  rtAction = (int8_T)((CruiseControlType <= 0) || (VlcActive == 0));
  rtDW.If3_ActiveSubsystem = rtAction;
  if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
    /* Disable for If: '<S3>/If' */
    if (rtDW.If_ActiveSubsystem == 0) {
      /* Disable for Atomic SubSystem: '<S15>/VLC_BL0.0.1' */
      /* Disable for If: '<S49>/If' */
      rtDW.If_ActiveSubsystem_j = -1;

      /* End of Disable for SubSystem: '<S15>/VLC_BL0.0.1' */
    }

    rtDW.If_ActiveSubsystem = -1;

    /* End of Disable for If: '<S3>/If' */
  }

  if (rtAction == 0) {
    /* Outputs for IfAction SubSystem: '<S1>/If Action Subsystem' incorporates:
     *  ActionPort: '<S3>/Action Port'
     */
    /* Sum: '<S19>/tSp-vSp' incorporates:
     *  DataStoreRead: '<S19>/targetSpeed1'
     */
    rtb_Product1_l = targetSpeed - rtb_DataTypeConversion_ai;

    /* Abs: '<S98>/Abs' */
    if (rtb_Product1_l < 0) {
      rtb_Saturation2 = -rtb_Product1_l;
    } else {
      rtb_Saturation2 = rtb_Product1_l;
    }

    /* End of Abs: '<S98>/Abs' */

    /* DataTypeConversion: '<S100>/Data Type Conversion' incorporates:
     *  Constant: '<S98>/Constant'
     *  RelationalOperator: '<S98>/Relational Operator2'
     */
    rtb_Switch1_k = (uint8_T)((real32_T)rtb_Saturation2 * 0.01F >= AZ5);

    /* Switch: '<S100>/Switch1' incorporates:
     *  Constant: '<S100>/Constant2'
     */
    if (rtb_Switch1_k > 0) {
      /* Switch: '<S100>/Switch2' incorporates:
       *  Constant: '<S100>/Constant'
       *  Constant: '<S100>/Constant1'
       *  Delay: '<S100>/Delay'
       *  RelationalOperator: '<S100>/Relational Operator1'
       *  Sum: '<S100>/Add'
       */
      if (rtDW.Delay_DSTATE_a < 11) {
        rtb_gsinalpha = (uint8_T)(rtDW.Delay_DSTATE_a + 1U);
      } else {
        rtb_gsinalpha = 11U;
      }

      /* End of Switch: '<S100>/Switch2' */
    } else {
      rtb_gsinalpha = 0U;
    }

    /* End of Switch: '<S100>/Switch1' */

    /* Switch: '<S100>/Switch' incorporates:
     *  Constant: '<S100>/Constant'
     *  Constant: '<S100>/Constant3'
     *  RelationalOperator: '<S100>/Relational Operator'
     */
    if (rtb_gsinalpha < 11) {
      rtb_Switch1_k = 0U;
    }

    /* End of Switch: '<S100>/Switch' */

    /* Switch: '<S98>/Switch1' incorporates:
     *  Constant: '<S98>/Constant3'
     */
    if (rtb_Switch1_k <= 0) {
      rtb_Product1_l = 0;
    }

    /* End of Switch: '<S98>/Switch1' */

    /* Saturate: '<S19>/Saturation' */
    if (rtb_Product1_l >= 1000) {
      rtb_Switch1_hj = 1000U;
    } else if (rtb_Product1_l <= 0) {
      rtb_Switch1_hj = 0U;
    } else {
      rtb_Switch1_hj = (uint16_T)rtb_Product1_l;
    }

    /* End of Saturate: '<S19>/Saturation' */

    /* Lookup_n-D: '<S19>/OLBCLimAccMap' */
    rtb_Product1_l = look2_iu16bs32lu32n32t_BzWkcOQY(rtb_DataTypeConversion_ai,
      rtb_Switch1_hj, (&(vehSpeed[0])), (&(OLBCAccSpd[0])), (&(OLBCAccLim[0])),
      rtConstP.OLBCLimAccMap_maxIndex, 2U);

    /* Switch: '<S19>/Switch' incorporates:
     *  DataStoreRead: '<S3>/reqAcceleration'
     *  RelationalOperator: '<S19>/Relational Operator'
     */
    if (reqAcceleration < rtb_Product1_l) {
      rtb_Switch_e = reqAcceleration;
    } else {
      rtb_Switch_e = (int16_T)rtb_Product1_l;
    }

    /* End of Switch: '<S19>/Switch' */

    /* DataTypeConversion: '<S19>/Data Type Conversion1' incorporates:
     *  DataStoreWrite: '<S19>/reqAccelerationLimited'
     */
    rtb_Saturation2 = rtb_Switch_e * 5243;
    reqAccelerationLimited = (int16_T)((((rtb_Saturation2 & 512U) != 0U) &&
      (((rtb_Saturation2 & 511U) != 0U) || (rtb_Saturation2 > 0))) +
      (rtb_Saturation2 >> 10));

    /* Outputs for Atomic SubSystem: '<S19>/reqAccelerationFiltered' */
    /* Outputs for Atomic SubSystem: '<S99>/Discrete filter min' */
    /* Saturate: '<S102>/Saturation' incorporates:
     *  DataStoreWrite: '<S19>/reqAccelerationLimited'
     */
    if (reqAccelerationLimited > 2560) {
      rtb_Abs_g = 2560;
    } else if (reqAccelerationLimited < -2560) {
      rtb_Abs_g = -2560;
    } else {
      rtb_Abs_g = reqAccelerationLimited;
    }

    /* End of Saturate: '<S102>/Saturation' */

    /* Product: '<S102>/Product' incorporates:
     *  Constant: '<S102>/Constant'
     */
    tmp = rtb_Abs_g * jrk_fmin * 125LL;

    /* Outputs for Atomic SubSystem: '<S99>/Discrete filter max' */
    /* Outputs for Atomic SubSystem: '<S101>/Discrete filter' */
    /* Sum: '<S102>/Add' incorporates:
     *  Constant: '<S102>/Constant1'
     *  Sum: '<S104>/Add'
     */
    rtb_Saturation2 = (int32_T)(c_1 * 100000ULL);

    /* End of Outputs for SubSystem: '<S101>/Discrete filter' */
    /* End of Outputs for SubSystem: '<S99>/Discrete filter max' */

    /* Product: '<S102>/Product1' incorporates:
     *  Constant: '<S102>/Constant'
     *  Sum: '<S102>/Add'
     *  UnitDelay: '<S102>/Unit Delay'
     */
    tmp_0 = (int64_T)(rtb_Saturation2 - jrk_fmin * 1000) *
      rtDW.UnitDelay_DSTATE_j;
    tmp_0 = (int32_T)((((tmp_0 & 65536ULL) != 0ULL) && (((tmp_0 & 65535ULL) !=
      0ULL) || (tmp_0 > 0LL))) + (tmp_0 >> 17)) * 351843721LL;

    /* Sum: '<S102>/Add1' incorporates:
     *  Product: '<S102>/Product'
     *  Product: '<S102>/Product1'
     */
    rtb_Product1_l = (int32_T)((((tmp & 32ULL) != 0ULL) && (((tmp & 31ULL) !=
      0ULL) || (tmp > 0LL))) + (tmp >> 6)) + (int32_T)((((tmp_0 & 134217728ULL)
      != 0ULL) && (((tmp_0 & 134217727ULL) != 0ULL) || (tmp_0 > 0LL))) + (tmp_0 >>
      28));

    /* DataTypeConversion: '<S102>/Data Type Conversion' */
    tmp = rtb_Product1_l * 351843721LL;
    rtb_DataTypeConversion_j = (int16_T)((((tmp & 34359738368ULL) != 0ULL) &&
      (((tmp & 34359738367ULL) != 0ULL) || (tmp > 0LL))) + (tmp >> 36));

    /* DataStoreWrite: '<S102>/reqAccelerationMIN' */
    reqAccelerationMIN = rtb_DataTypeConversion_j;

    /* Update for UnitDelay: '<S102>/Unit Delay' */
    rtDW.UnitDelay_DSTATE_j = rtb_Product1_l;

    /* End of Outputs for SubSystem: '<S99>/Discrete filter min' */

    /* Outputs for Atomic SubSystem: '<S99>/Discrete filter max' */
    /* Saturate: '<S101>/Saturation' */
    if (rtb_DataTypeConversion_j > 2560) {
      rtb_Saturation_o = 2560;
    } else if (rtb_DataTypeConversion_j < -2560) {
      rtb_Saturation_o = -2560;
    } else {
      rtb_Saturation_o = rtb_DataTypeConversion_j;
    }

    /* End of Saturate: '<S101>/Saturation' */

    /* Outputs for Atomic SubSystem: '<S101>/Discrete filter' */
    /* Saturate: '<S104>/Saturation' */
    rtb_Abs1 = rtb_Saturation_o;

    /* Product: '<S104>/Product' incorporates:
     *  Constant: '<S104>/Constant'
     */
    tmp = rtb_Abs1 * jrk_fmax * 125LL;

    /* Product: '<S104>/Product1' incorporates:
     *  Constant: '<S104>/Constant'
     *  Sum: '<S104>/Add'
     *  UnitDelay: '<S104>/Unit Delay'
     */
    tmp_0 = (int64_T)(rtb_Saturation2 - jrk_fmax * 1000) *
      rtDW.UnitDelay_DSTATE_o;
    tmp_0 = (int32_T)((((tmp_0 & 65536ULL) != 0ULL) && (((tmp_0 & 65535ULL) !=
      0ULL) || (tmp_0 > 0LL))) + (tmp_0 >> 17)) * 351843721LL;

    /* Sum: '<S104>/Add1' incorporates:
     *  Product: '<S104>/Product'
     *  Product: '<S104>/Product1'
     */
    rtb_Product1_l = (int32_T)((((tmp & 32ULL) != 0ULL) && (((tmp & 31ULL) !=
      0ULL) || (tmp > 0LL))) + (tmp >> 6)) + (int32_T)((((tmp_0 & 134217728ULL)
      != 0ULL) && (((tmp_0 & 134217727ULL) != 0ULL) || (tmp_0 > 0LL))) + (tmp_0 >>
      28));

    /* Update for UnitDelay: '<S104>/Unit Delay' */
    rtDW.UnitDelay_DSTATE_o = rtb_Product1_l;

    /* DataTypeConversion: '<S104>/Data Type Conversion' */
    tmp = rtb_Product1_l * 351843721LL;

    /* Sum: '<S101>/Add1' incorporates:
     *  DataTypeConversion: '<S104>/Data Type Conversion'
     *  Sum: '<S101>/Add'
     */
    rtb_Saturation_o -= (int16_T)((int16_T)((((tmp & 34359738368ULL) != 0ULL) &&
      (((tmp & 34359738367ULL) != 0ULL) || (tmp > 0LL))) + (tmp >> 36)) -
      rtb_Saturation_o);

    /* End of Outputs for SubSystem: '<S101>/Discrete filter' */

    /* DataStoreWrite: '<S101>/reqAccelerationMAX' */
    reqAccelerationMAX = rtb_Saturation_o;

    /* End of Outputs for SubSystem: '<S99>/Discrete filter max' */

    /* Outputs for Atomic SubSystem: '<S99>/Jerk filter' */
    /* Logic: '<S103>/Logical Operator2' incorporates:
     *  DataStoreWrite: '<S19>/reqAccelerationLimited'
     *  Logic: '<S103>/Logical Operator'
     *  Logic: '<S103>/Logical Operator1'
     *  RelationalOperator: '<S103>/Relational Operator'
     *  RelationalOperator: '<S103>/Relational Operator1'
     *  RelationalOperator: '<S103>/Relational Operator2'
     *  RelationalOperator: '<S103>/Relational Operator3'
     */
    rtb_RelationalOperator1_ce = (((reqAccelerationLimited <= rtb_Saturation_o) &&
      (reqAccelerationLimited >= rtb_DataTypeConversion_j)) ||
      ((reqAccelerationLimited <= rtb_DataTypeConversion_j) &&
       (reqAccelerationLimited >= rtb_Saturation_o)));

    /* DataTypeConversion: '<S103>/Data Type Conversion' incorporates:
     *  DataStoreWrite: '<S103>/Data Store Write'
     *  RelationalOperator: '<S105>/Compare'
     */
    jerkFlag = (uint8_T)!rtb_RelationalOperator1_ce;

    /* Switch: '<S103>/Switch' incorporates:
     *  DataStoreWrite: '<S19>/jerkAcceleration'
     *  DataStoreWrite: '<S19>/reqAccelerationLimited'
     */
    if (rtb_RelationalOperator1_ce) {
      jerkAcceleration = reqAccelerationLimited;
    } else {
      /* Sum: '<S103>/Subtract1' incorporates:
       *  DataStoreWrite: '<S19>/reqAccelerationLimited'
       */
      rtb_Abs1 = (int16_T)(rtb_DataTypeConversion_j - reqAccelerationLimited);

      /* Abs: '<S103>/Abs1' */
      if (rtb_Abs1 < 0) {
        rtb_Abs1 = (int16_T)-rtb_Abs1;
      }

      /* End of Abs: '<S103>/Abs1' */

      /* Sum: '<S103>/Subtract' incorporates:
       *  DataStoreWrite: '<S19>/reqAccelerationLimited'
       */
      rtb_Abs_g = (int16_T)(rtb_Saturation_o - reqAccelerationLimited);

      /* Abs: '<S103>/Abs' */
      if (rtb_Abs_g < 0) {
        rtb_Abs_g = (int16_T)-rtb_Abs_g;
      }

      /* End of Abs: '<S103>/Abs' */

      /* Switch: '<S103>/Switch1' incorporates:
       *  DataStoreWrite: '<S19>/jerkAcceleration'
       *  RelationalOperator: '<S103>/Relational Operator4'
       */
      if (rtb_Abs_g < rtb_Abs1) {
        jerkAcceleration = rtb_Saturation_o;
      } else {
        jerkAcceleration = rtb_DataTypeConversion_j;
      }

      /* End of Switch: '<S103>/Switch1' */
    }

    /* End of Switch: '<S103>/Switch' */
    /* End of Outputs for SubSystem: '<S99>/Jerk filter' */
    /* End of Outputs for SubSystem: '<S19>/reqAccelerationFiltered' */

    /* Outputs for Atomic SubSystem: '<S3>/BasicModel' */
    /* Outputs for Atomic SubSystem: '<S12>/TrqRatio' */
    /* Switch: '<S24>/Switch' incorporates:
     *  Constant: '<S36>/Constant'
     *  DataStoreRead: '<S1>/numGearEngaged'
     *  DataStoreRead: '<S24>/Data Store Read7'
     *  DataStoreRead: '<S24>/numGearTarget'
     *  RelationalOperator: '<S36>/Compare'
     *  SignalConversion: '<S4>/TmpSignal ConversionAtData Type Conversion6Inport1'
     */
    if (numGearSwitch > 0) {
      /* Outputs for Atomic SubSystem: '<S1>/Input Processing1' */
      rtb_Switch1_k = GearEngNum;

      /* End of Outputs for SubSystem: '<S1>/Input Processing1' */
    } else {
      rtb_Switch1_k = numGearTarget_vlc;
    }

    /* End of Switch: '<S24>/Switch' */

    /* Saturate: '<S24>/Saturation' */
    if (rtb_Switch1_k > 9) {
      rtb_Switch1_k = 9U;
    } else {
      if (rtb_Switch1_k < 1) {
        rtb_Switch1_k = 1U;
      }
    }

    /* End of Saturate: '<S24>/Saturation' */

    /* Lookup_n-D: '<S24>/Gear_ratio_LT' */
    rtb_DataTypeConversion_hs = plook_u32u8s16u32n32_evenca_gs(rtb_Switch1_k,
      GearNumber[0], (uint16_T)(GearNumber[1] - GearNumber[0]), &frac);
    rtb_DataTypeConversion_j = intrp1d_s16s32s32u32u32n32la_s
      (rtb_DataTypeConversion_hs, frac, (&(GearRatio[0])), 8U);

    /* Gain: '<S24>/Gain1' */
    if (MainGearRatio > 511) {
      rtb_Abs_g = MAX_int16_T;
    } else {
      rtb_Abs_g = (int16_T)(MainGearRatio << 6);
    }

    /* DataTypeConversion: '<S24>/Data Type Conversion' incorporates:
     *  DataStoreWrite: '<S24>/curTrqRation'
     *  Gain: '<S24>/Gain1'
     */
    curTrqRatio = (uint16_T)((real32_T)rtb_Abs_g * 0.000244140625F * ((real32_T)
      rtb_DataTypeConversion_j * 0.001F) * 1000.0F);

    /* Outputs for Atomic SubSystem: '<S1>/Input Processing1' */
    /* RelationalOperator: '<S34>/Compare' incorporates:
     *  Constant: '<S34>/Constant'
     *  DataStoreRead: '<S1>/numGearEngaged'
     *  DataStoreRead: '<S24>/numGearTarget'
     *  DataTypeConversion: '<S24>/Data Type Conversion17'
     *  DataTypeConversion: '<S24>/Data Type Conversion18'
     *  SignalConversion: '<S4>/TmpSignal ConversionAtData Type Conversion6Inport1'
     *  Sum: '<S24>/Subtract'
     */
    rtb_RelationalOperator1_ce = ((int8_T)GearEngNum - (int8_T)numGearTarget_vlc
      == 0);

    /* End of Outputs for SubSystem: '<S1>/Input Processing1' */

    /* Switch: '<S37>/Switch1' incorporates:
     *  Constant: '<S37>/Constant2'
     */
    if (rtb_RelationalOperator1_ce) {
      /* Switch: '<S37>/Switch2' incorporates:
       *  Constant: '<S37>/Constant1'
       *  Constant: '<S37>/GearTimer'
       *  Delay: '<S37>/Delay'
       *  RelationalOperator: '<S37>/Relational Operator1'
       *  Sum: '<S37>/Add'
       */
      if (rtDW.Delay_DSTATE_az < GearTimerThreshold) {
        rtb_Switch1_k = (uint8_T)(rtDW.Delay_DSTATE_az + 1U);
      } else {
        rtb_Switch1_k = GearTimerThreshold;
      }

      /* End of Switch: '<S37>/Switch2' */
    } else {
      rtb_Switch1_k = 0U;
    }

    /* End of Switch: '<S37>/Switch1' */

    /* Gain: '<S24>/Gain' */
    rtb_Divide6 = (real32_T)rtb_EngineRPM * 0.01F * 0.104666665F;

    /* Outputs for Atomic SubSystem: '<S24>/TrqRatio' */
    /* DataTypeConversion: '<S41>/Data Type Conversion1' incorporates:
     *  Constant: '<S41>/TorqueRatioTmrMax'
     *  DataStoreRead: '<S41>/TorqueRatioTmr'
     *  RelationalOperator: '<S41>/Relational Operator'
     */
    rtb_Switch1_fs = (uint8_T)(TorqueRatioTmr >= TorqueRatioTmrMax);

    /* DataStoreWrite: '<S40>/Clutched_status' */
    Clutched_Status = rtb_Switch1_fs;

    /* Switch: '<S41>/Switch' incorporates:
     *  Constant: '<S41>/EngineSPDmin'
     *  RelationalOperator: '<S41>/rel1'
     */
    if (!(rtb_Divide6 >= EngineSPDmin)) {
      rtb_Divide6 = EngineSPDmin;
    }

    /* End of Switch: '<S41>/Switch' */
    /* End of Outputs for SubSystem: '<S24>/TrqRatio' */

    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S15>/VLC_BL0.0.1' */
    /* Outputs for IfAction SubSystem: '<S49>/VLC_Active' incorporates:
     *  ActionPort: '<S51>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S51>/BoostController1' */
    /* Outputs for Atomic SubSystem: '<S53>/DirectAX' */
    /* Outputs for Atomic SubSystem: '<S12>/WheelsInertia' */
    /* If: '<S3>/If' incorporates:
     *  Constant: '<S24>/Constant'
     *  Gain: '<S55>/Gain'
     *  If: '<S49>/If'
     *  Product: '<S24>/Divide'
     *  Product: '<S25>/Divide'
     */
    rtb_Gain6 = (real32_T)rd * 0.01F;

    /* End of Outputs for SubSystem: '<S12>/WheelsInertia' */
    /* End of Outputs for SubSystem: '<S53>/DirectAX' */
    /* End of Outputs for SubSystem: '<S51>/BoostController1' */
    /* End of Outputs for SubSystem: '<S49>/VLC_Active' */
    /* End of Outputs for SubSystem: '<S15>/VLC_BL0.0.1' */
    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem1' */

    /* Outputs for Atomic SubSystem: '<S24>/TrqRatio' */
    /* Product: '<S41>/Divide' incorporates:
     *  Constant: '<S24>/Constant1'
     *  DataStoreRead: '<S3>/cardanSpeed'
     *  Product: '<S24>/Divide'
     *  Product: '<S24>/Product'
     */
    rtb_Divide6 = (real32_T)cardanSpeed * 0.01F / rtb_Gain6 * ((real32_T)
      MainGearRatio * 0.015625F) / rtb_Divide6;

    /* DataTypeConversion: '<S41>/Data Type Conversion2' incorporates:
     *  DataStoreWrite: '<S40>/TorqueRatio'
     */
    TorqueRatio = (uint32_T)rt_roundf_snf(rtb_Divide6 * 1000.0F);

    /* RelationalOperator: '<S41>/Less Than' incorporates:
     *  Abs: '<S41>/Abs'
     *  Constant: '<S41>/TorqueRatioThreshold'
     *  Math: '<S41>/MathFunction'
     *  Sum: '<S41>/Minus'
     *
     * About '<S41>/MathFunction':
     *  Operator: reciprocal
     */
    for (rtb_Product1_l = 0; rtb_Product1_l < 9; rtb_Product1_l++) {
      /* Math: '<S41>/MathFunction' incorporates:
       *  Constant: '<S41>/GearRatio'
       *
       * About '<S41>/MathFunction':
       *  Operator: reciprocal
       */
      rtb_Saturation2 = div_nde_s32_floor(1048576, GearRatio[rtb_Product1_l]);
      if (rtb_Saturation2 > 32767) {
        rtb_Saturation2 = 32767;
      } else {
        if (rtb_Saturation2 < -32768) {
          rtb_Saturation2 = -32768;
        }
      }

      rtb_LessThan[rtb_Product1_l] = ((real32_T)TorqueRatioThreshold * 0.001F >
        (real32_T)fabs((real32_T)(int16_T)((rtb_Saturation2 * 15625) >> 14) *
                       0.001F - rtb_Divide6));
    }

    /* End of RelationalOperator: '<S41>/Less Than' */

    /* Logic: '<S41>/Logical Operator' */
    rtb_RelationalOperator2_d = rtb_LessThan[0];
    for (rtb_Product1_l = 0; rtb_Product1_l < 8; rtb_Product1_l++) {
      rtb_RelationalOperator2_d = (rtb_RelationalOperator2_d ||
        rtb_LessThan[rtb_Product1_l + 1]);
    }

    /* If: '<S41>/If' incorporates:
     *  Logic: '<S41>/Logical Operator'
     */
    if (rtb_RelationalOperator2_d) {
      /* Outputs for IfAction SubSystem: '<S41>/TorqueRatioTmr_inc' incorporates:
       *  ActionPort: '<S42>/Action Port'
       */
      /* Saturate: '<S42>/Saturation' incorporates:
       *  DataStoreRead: '<S42>/TorqueRatioTmr_in'
       */
      if (TorqueRatioTmr < TorqueRatioTmrMax) {
        tmp_2 = TorqueRatioTmr;
      } else {
        tmp_2 = TorqueRatioTmrMax;
      }

      /* End of Saturate: '<S42>/Saturation' */

      /* Sum: '<S42>/Add' incorporates:
       *  Constant: '<S42>/Constant'
       *  DataStoreWrite: '<S42>/TorqueRatioTmr_out'
       */
      TorqueRatioTmr = tmp_2 + 1U;

      /* End of Outputs for SubSystem: '<S41>/TorqueRatioTmr_inc' */
    } else {
      /* Outputs for IfAction SubSystem: '<S41>/TorqueRatioTmr_nul' incorporates:
       *  ActionPort: '<S43>/Action Port'
       */
      /* DataStoreWrite: '<S43>/TorqueRatioTmr_out' incorporates:
       *  Constant: '<S43>/Constant'
       */
      TorqueRatioTmr = 0U;

      /* End of Outputs for SubSystem: '<S41>/TorqueRatioTmr_nul' */
    }

    /* End of If: '<S41>/If' */
    /* End of Outputs for SubSystem: '<S24>/TrqRatio' */

    /* Switch: '<S37>/Switch' incorporates:
     *  Constant: '<S37>/Constant3'
     *  Constant: '<S37>/GearTimer'
     *  RelationalOperator: '<S37>/Relational Operator'
     */
    if (rtb_Switch1_k < GearTimerThreshold) {
      rtb_Switch1_dn = rtb_RelationalOperator1_ce;
    } else {
      rtb_Switch1_dn = 0U;
    }

    /* End of Switch: '<S37>/Switch' */

    /* Logic: '<S24>/Logical Operator' incorporates:
     *  Constant: '<S35>/Constant'
     *  RelationalOperator: '<S35>/Compare'
     */
    rtb_RelationalOperator1_ce = ((rtb_Switch1_dn != 0) && (rtb_Switch1_fs != 0));

    /* Outputs for Triggered SubSystem: '<S24>/Triggered Subsystem' incorporates:
     *  TriggerPort: '<S38>/Trigger'
     */
    if ((!rtb_RelationalOperator1_ce) &&
        (rtPrevZCX.TriggeredSubsystem_Trig_ZCE_h != ZERO_ZCSIG)) {
      /* DataStoreWrite: '<S38>/Data Store Write13' incorporates:
       *  Constant: '<S38>/Constant'
       */
      numGearSwitch = 1U;
    }

    rtPrevZCX.TriggeredSubsystem_Trig_ZCE_h = rtb_RelationalOperator1_ce;

    /* End of Outputs for SubSystem: '<S24>/Triggered Subsystem' */

    /* Outputs for Triggered SubSystem: '<S24>/Triggered Subsystem1' incorporates:
     *  TriggerPort: '<S39>/Trigger'
     */
    if (rtb_RelationalOperator1_ce && (rtPrevZCX.TriggeredSubsystem1_Trig_ZCE_k
         != POS_ZCSIG)) {
      /* DataStoreWrite: '<S39>/Data Store Write13' incorporates:
       *  Constant: '<S39>/Constant'
       */
      numGearSwitch = 0U;
    }

    rtPrevZCX.TriggeredSubsystem1_Trig_ZCE_k = rtb_RelationalOperator1_ce;

    /* End of Outputs for SubSystem: '<S24>/Triggered Subsystem1' */

    /* Update for Delay: '<S37>/Delay' */
    rtDW.Delay_DSTATE_az = rtb_Switch1_k;

    /* End of Outputs for SubSystem: '<S12>/TrqRatio' */

    /* Outputs for Atomic SubSystem: '<S12>/TransmissionDragModel-01' */
    /* DataStoreWrite: '<S23>/M_MotClutch_TDM' */
    M_MotClutch_TDM = 0;

    /* End of Outputs for SubSystem: '<S12>/TransmissionDragModel-01' */

    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S15>/VLC_BL0.0.1' */
    /* Outputs for IfAction SubSystem: '<S49>/VLC_Active' incorporates:
     *  ActionPort: '<S51>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S51>/BoostController1' */
    /* Outputs for Atomic SubSystem: '<S53>/Torque_request_subsystem1' */
    /* Outputs for Atomic SubSystem: '<S57>/CLBC_PI_2.0' */
    /* Outputs for Atomic SubSystem: '<S12>/PreControl' */
    /* If: '<S3>/If' incorporates:
     *  Constant: '<S28>/Constant'
     *  If: '<S49>/If'
     *  MultiPortSwitch: '<S59>/Multiport Switch2'
     */
    tmp_2 = c_0 * 100U;

    /* End of Outputs for SubSystem: '<S57>/CLBC_PI_2.0' */
    /* End of Outputs for SubSystem: '<S53>/Torque_request_subsystem1' */
    /* End of Outputs for SubSystem: '<S51>/BoostController1' */
    /* End of Outputs for SubSystem: '<S49>/VLC_Active' */
    /* End of Outputs for SubSystem: '<S15>/VLC_BL0.0.1' */
    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem1' */
    rtb_DataTypeConversion_hs = tmp_2;
    if (tmp_2 > 32767U) {
      rtb_DataTypeConversion_hs = 32767U;
    }

    /* If: '<S21>/If1' incorporates:
     *  Constant: '<S28>/Constant'
     *  Product: '<S31>/Req trq max'
     *  Product: '<S31>/Req trq min'
     *  RelationalOperator: '<S28>/Compare'
     */
    if (rtb_Switch_e > (int32_T)rtb_DataTypeConversion_hs) {
      /* Outputs for IfAction SubSystem: '<S21>/Basic calculation' incorporates:
       *  ActionPort: '<S27>/Action Port'
       */
      /* DataTypeConversion: '<S31>/Data Type Conversion' incorporates:
       *  Constant: '<S31>/rd'
       */
      rtb_Saturation_o = (int16_T)rd;

      /* Product: '<S31>/M_max*a' incorporates:
       *  Constant: '<S31>/WghtFull'
       *  DataTypeConversion: '<S31>/Data Type Conversion1'
       */
      rtb_Saturation2 = (int16_T)WghtFull * rtb_Switch_e;
      rtb_Saturation2 = (int16_T)((((rtb_Saturation2 & 64U) != 0U) &&
        (((rtb_Saturation2 & 63U) != 0U) || (rtb_Saturation2 > 0))) +
        (rtb_Saturation2 >> 7)) * 5243;

      /* Product: '<S31>/Trq max' incorporates:
       *  Product: '<S31>/M_max*a'
       */
      rtb_Saturation2 = (int16_T)((((rtb_Saturation2 & 2048U) != 0U) &&
        (((rtb_Saturation2 & 2047U) != 0U) || (rtb_Saturation2 > 0))) +
        (rtb_Saturation2 >> 12)) * rtb_Saturation_o;
      rtb_Saturation2 = (int16_T)((((rtb_Saturation2 & 64U) != 0U) &&
        (((rtb_Saturation2 & 63U) != 0U) || (rtb_Saturation2 > 0))) +
        (rtb_Saturation2 >> 7)) * 5243;

      /* Product: '<S31>/Req trq max' incorporates:
       *  DataStoreRead: '<S31>/curTrqRatio'
       *  Product: '<S31>/Trq max'
       */
      rtb_Saturation2 = (int16_T)div_nzp_s32_round((int16_T)((((rtb_Saturation2
        & 2048U) != 0U) && (((rtb_Saturation2 & 2047U) != 0U) ||
                            (rtb_Saturation2 > 0))) + (rtb_Saturation2 >> 12)) <<
        9, curTrqRatio) * 125;

      /* Outputs for Atomic SubSystem: '<S31>/Subsystem1' */
      rtb_DataTypeConversion_j = Subsystem1((int16_T)((((rtb_Saturation2 & 32U)
        != 0U) && (((rtb_Saturation2 & 31U) != 0U) || (rtb_Saturation2 > 0))) +
        (rtb_Saturation2 >> 6)));

      /* End of Outputs for SubSystem: '<S31>/Subsystem1' */

      /* Product: '<S31>/M_min*a' incorporates:
       *  Constant: '<S31>/WghtCurb'
       *  DataTypeConversion: '<S31>/Data Type Conversion2'
       *  Product: '<S31>/Req trq max'
       */
      rtb_Saturation2 = rtb_Switch_e * (int16_T)WghtCurb;
      rtb_Saturation2 = (int16_T)((((rtb_Saturation2 & 64U) != 0U) &&
        (((rtb_Saturation2 & 63U) != 0U) || (rtb_Saturation2 > 0))) +
        (rtb_Saturation2 >> 7)) * 5243;

      /* Product: '<S31>/Trq min' incorporates:
       *  Product: '<S31>/M_min*a'
       */
      rtb_Saturation2 = (int16_T)((((rtb_Saturation2 & 2048U) != 0U) &&
        (((rtb_Saturation2 & 2047U) != 0U) || (rtb_Saturation2 > 0))) +
        (rtb_Saturation2 >> 12)) * rtb_Saturation_o;
      rtb_Saturation2 = (int16_T)((((rtb_Saturation2 & 64U) != 0U) &&
        (((rtb_Saturation2 & 63U) != 0U) || (rtb_Saturation2 > 0))) +
        (rtb_Saturation2 >> 7)) * 5243;
      rtb_Saturation_o = (int16_T)((((rtb_Saturation2 & 2048U) != 0U) &&
        (((rtb_Saturation2 & 2047U) != 0U) || (rtb_Saturation2 > 0))) +
        (rtb_Saturation2 >> 12));

      /* Product: '<S31>/Req trq min' incorporates:
       *  DataStoreRead: '<S31>/curTrqRatio'
       */
      rtb_Saturation2 = (int16_T)div_nzp_s32_round(rtb_Saturation_o << 9,
        curTrqRatio) * 125;

      /* Outputs for Atomic SubSystem: '<S31>/Subsystem2' */
      rtb_Saturation_o = Subsystem1((int16_T)((((rtb_Saturation2 & 32U) != 0U) &&
        (((rtb_Saturation2 & 31U) != 0U) || (rtb_Saturation2 > 0))) +
        (rtb_Saturation2 >> 6)));

      /* End of Outputs for SubSystem: '<S31>/Subsystem2' */

      /* Outputs for Atomic SubSystem: '<S27>/Adaptation' */
      /* Product: '<S30>/(1-alfa)Tmax' incorporates:
       *  Constant: '<S30>/c_1'
       *  Constant: '<S30>/parametrOLBC_mdlCompensation'
       *  Product: '<S31>/Req trq min'
       *  Sum: '<S30>/1-alfa'
       */
      rtb_Saturation2 = (int16_T)((int16_T)(c_1 * 100U) - (int16_T)
        parametrOLBC_mdlCompensation) * rtb_DataTypeConversion_j;
      rtb_Saturation2 = (int16_T)((((rtb_Saturation2 & 8U) != 0U) &&
        (((rtb_Saturation2 & 7U) != 0U) || (rtb_Saturation2 > 0))) +
        (rtb_Saturation2 >> 4)) * 13107;

      /* Product: '<S30>/alfa*Tmin' incorporates:
       *  Constant: '<S30>/parametrOLBC_mdlCompensation'
       */
      rtb_Product1_l = parametrOLBC_mdlCompensation * rtb_Saturation_o;
      rtb_Product1_l = (int16_T)((((rtb_Product1_l & 8U) != 0U) &&
        (((rtb_Product1_l & 7U) != 0U) || (rtb_Product1_l > 0))) +
        (rtb_Product1_l >> 4)) * 13107;

      /* Sum: '<S30>/Subtract1' incorporates:
       *  Product: '<S30>/(1-alfa)Tmax'
       *  Product: '<S30>/alfa*Tmin'
       */
      rtb_Saturation_o = (int16_T)((int16_T)((((rtb_Saturation2 & 4096U) != 0U) &&
        (((rtb_Saturation2 & 4095U) != 0U) || (rtb_Saturation2 > 0))) +
        (rtb_Saturation2 >> 13)) + (int16_T)((((rtb_Product1_l & 4096U) != 0U) &&
        (((rtb_Product1_l & 4095U) != 0U) || (rtb_Product1_l > 0))) +
        (rtb_Product1_l >> 13)));

      /* Outputs for Atomic SubSystem: '<S1>/Input Processing1' */
      /* Lookup_n-D: '<S30>/Gear MASS factor' incorporates:
       *  DataStoreRead: '<S1>/numGearEngaged'
       *  SignalConversion: '<S4>/TmpSignal ConversionAtData Type Conversion6Inport1'
       */
      rtb_DataTypeConversion_hs = plook_u32u8s16u32n32_evenca_gs(GearEngNum,
        GearNumber[0], (uint16_T)(GearNumber[1] - GearNumber[0]), &frac);

      /* End of Outputs for SubSystem: '<S1>/Input Processing1' */
      rtb_DataTypeConversion_j = intrp1d_s16s32s32u32u32n32la_s
        (rtb_DataTypeConversion_hs, frac, (&(MassFactor_MAP[0])), 8U);

      /* Product: '<S30>/(1-alfa)Tmax1' */
      rtb_Saturation2 = rtb_Saturation_o * rtb_DataTypeConversion_j;
      tmp = ((((rtb_Saturation2 & 8U) != 0U) && (((rtb_Saturation2 & 7U) != 0U) ||
               (rtb_Saturation2 > 0))) + (rtb_Saturation2 >> 4)) * 858993459LL;

      /* Sum: '<S30>/Add1' incorporates:
       *  Product: '<S30>/(1-alfa)Tmax1'
       */
      tmp = (int32_T)((((tmp & 268435456ULL) != 0ULL) && (((tmp & 268435455ULL)
        != 0ULL) || (tmp > 0LL))) + (tmp >> 29)) * 858993459LL;

      /* End of Outputs for SubSystem: '<S27>/Adaptation' */

      /* Sum: '<S31>/Add_DragForces' incorporates:
       *  DataStoreRead: '<S31>/FreeRollingDragForce_BC'
       */
      rtb_Saturation2 = FreeRollingDragForce_BC * 13107;

      /* Outputs for Atomic SubSystem: '<S27>/Adaptation' */
      /* DataTypeConversion: '<S30>/Data Type Conversion' incorporates:
       *  DataStoreRead: '<S31>/M_MotClutch_TDM'
       *  DataStoreRead: '<S31>/M_MotClutch_WI'
       *  DataStoreRead: '<S31>/SlopeDragTorque'
       *  DataStoreWrite: '<S30>/M_MotClutch_OLBC'
       *  Sum: '<S30>/Add1'
       *  Sum: '<S31>/Add_DragForces'
       */
      M_MotClutch_OLBC = (int16_T)(((int16_T)((int16_T)((((tmp & 4294967296ULL)
        != 0ULL) && (((tmp & 4294967295ULL) != 0ULL) || (tmp > 0LL))) + (tmp >>
        33)) - (int16_T)((int16_T)((int16_T)((int16_T)(((((rtb_Saturation2 &
        65536U) != 0U) && (((rtb_Saturation2 & 65535U) != 0U) ||
                           (rtb_Saturation2 > 0))) + (rtb_Saturation2 >> 17)) +
        M_MotClutch_TDM) + M_MotClutch_WI) - SlopeDragTorque) * 10)) * 13107) >>
        17);

      /* End of Outputs for SubSystem: '<S27>/Adaptation' */
      /* End of Outputs for SubSystem: '<S21>/Basic calculation' */
    } else {
      /* Outputs for IfAction SubSystem: '<S21>/Drag forces' incorporates:
       *  ActionPort: '<S29>/Action Port'
       */
      /* Sum: '<S29>/Add' incorporates:
       *  DataStoreRead: '<S29>/FreeRollingDragForce_BC'
       *  DataStoreRead: '<S29>/M_MotClutch_TDM'
       *  DataStoreRead: '<S29>/M_MotClutch_WI'
       *  DataStoreRead: '<S29>/SlopeDragTorque'
       *  DataStoreWrite: '<S29>/Data Store Write'
       */
      rtb_Saturation2 = FreeRollingDragForce_BC * 13107;
      M_MotClutch_OLBC = (int16_T)((int16_T)((int16_T)(SlopeDragTorque -
        ((((rtb_Saturation2 & 65536U) != 0U) && (((rtb_Saturation2 & 65535U) !=
        0U) || (rtb_Saturation2 > 0))) + (rtb_Saturation2 >> 17))) -
        M_MotClutch_TDM) - M_MotClutch_WI);

      /* End of Outputs for SubSystem: '<S21>/Drag forces' */
    }

    /* End of If: '<S21>/If1' */
    /* End of Outputs for SubSystem: '<S12>/PreControl' */

    /* Outputs for Atomic SubSystem: '<S12>/WheelsInertia' */
    /* Product: '<S25>/Divide' incorporates:
     *  Gain: '<S25>/Gain2'
     */
    rtb_Divide6 = -((real32_T)rtb_Switch_e * 0.01F) / rtb_Gain6;

    /* Gain: '<S25>/Gain' incorporates:
     *  Constant: '<S25>/J_Wheel_FA'
     *  DataStoreWrite: '<S25>/WheelInertia_FA'
     *  Product: '<S25>/Product'
     */
    WheelInertia_FA = J_Wheel_FA * rtb_Divide6 * 2.0F;

    /* Product: '<S25>/Product1' incorporates:
     *  Constant: '<S25>/J_Wheel_RA'
     */
    rtb_Divide6 *= J_Wheel_RA;

    /* Gain: '<S25>/Gain1' incorporates:
     *  DataStoreWrite: '<S25>/WheelInertia_RA'
     */
    WheelInertia_RA = 2.0F * rtb_Divide6;

    /* Product: '<S25>/Product2' incorporates:
     *  Constant: '<S25>/dbg_wheels'
     *  DataStoreWrite: '<S25>/M_MotClutch_WI'
     *  DataStoreWrite: '<S25>/WheelInertia_FA'
     *  DataStoreWrite: '<S25>/WheelInertia_RA'
     *  DataTypeConversion: '<S25>/Data Type Conversion3'
     *  Sum: '<S25>/Add'
     */
    M_MotClutch_WI = (int16_T)((int16_T)(real32_T)floor(WheelInertia_FA +
      WheelInertia_RA) * dbg_wheels);

    /* End of Outputs for SubSystem: '<S12>/WheelsInertia' */

    /* Outputs for Atomic SubSystem: '<S12>/FreeRollingDragModel' */
    /* Lookup_n-D: '<S20>/FreeRollingModel1' */
    rtb_DataTypeConversion_j = look1_iu16lu64n48ts16D_7ZfpVqQH
      (rtb_DataTypeConversion_ai, (&(FreeRollingResistanceBP[0])),
       (&(FreeRollingResistanceTD[0])), 15U);

    /* Switch: '<S26>/Switch2' incorporates:
     *  Constant: '<S20>/Constant'
     *  DataStoreRead: '<S20>/reqAcceleration'
     *  RelationalOperator: '<S26>/LowerRelop1'
     *  RelationalOperator: '<S26>/UpperRelop'
     *  Switch: '<S26>/Switch'
     */
    if (reqAcceleration > 0) {
      rtb_Switch_e = 0;
    } else if (((int64_T)reqAcceleration << 17) < rtb_DataTypeConversion_j *
               13107) {
      /* Switch: '<S26>/Switch' */
      rtb_Saturation2 = rtb_DataTypeConversion_j * 13107;
      rtb_Switch_e = (int16_T)((((rtb_Saturation2 & 65536U) != 0U) &&
        (((rtb_Saturation2 & 65535U) != 0U) || (rtb_Saturation2 > 0))) +
        (rtb_Saturation2 >> 17));
    } else {
      rtb_Switch_e = reqAcceleration;
    }

    /* End of Switch: '<S26>/Switch2' */

    /* Switch: '<S20>/Switch' incorporates:
     *  Sum: '<S20>/Add'
     */
    if (rtb_Switch_e < 0) {
      rtb_DataTypeConversion_j = (int16_T)(rtb_DataTypeConversion_j -
        rtb_Switch_e * 10);
    }

    /* End of Switch: '<S20>/Switch' */

    /* Product: '<S20>/Product' incorporates:
     *  Constant: '<S20>/WghtCurb'
     *  DataTypeConversion: '<S20>/Data Type Conversion'
     */
    rtb_Saturation2 = rtb_DataTypeConversion_j * (int16_T)WghtCurb;
    rtb_Saturation2 = (int16_T)((((rtb_Saturation2 & 64U) != 0U) &&
      (((rtb_Saturation2 & 63U) != 0U) || (rtb_Saturation2 > 0))) +
      (rtb_Saturation2 >> 7)) * 5243;

    /* Product: '<S20>/Divide1' incorporates:
     *  DataStoreRead: '<S20>/curTrqRatio'
     *  Product: '<S20>/Product'
     */
    rtb_Saturation2 = (int16_T)div_nzp_s32_round((int16_T)((((rtb_Saturation2 &
      2048U) != 0U) && (((rtb_Saturation2 & 2047U) != 0U) || (rtb_Saturation2 >
      0))) + (rtb_Saturation2 >> 12)) << 9, curTrqRatio) * 125;

    /* Product: '<S20>/Product1' incorporates:
     *  Constant: '<S20>/rd'
     *  DataStoreWrite: '<S20>/FreeRollingDragForce_BC1'
     *  Product: '<S20>/Divide1'
     */
    rtb_Saturation2 = (int16_T)((((rtb_Saturation2 & 32U) != 0U) &&
      (((rtb_Saturation2 & 31U) != 0U) || (rtb_Saturation2 > 0))) +
      (rtb_Saturation2 >> 6)) * rd;
    rtb_Saturation2 = (int16_T)((((rtb_Saturation2 & 64U) != 0U) &&
      (((rtb_Saturation2 & 63U) != 0U) || (rtb_Saturation2 > 0))) +
      (rtb_Saturation2 >> 7)) * 5243;
    FreeRollingDragForce_BC = (int16_T)((((rtb_Saturation2 & 2048U) != 0U) &&
      (((rtb_Saturation2 & 2047U) != 0U) || (rtb_Saturation2 > 0))) +
      (rtb_Saturation2 >> 12));

    /* End of Outputs for SubSystem: '<S12>/FreeRollingDragModel' */

    /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem1' incorporates:
     *  ActionPort: '<S15>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S15>/VLC_BL0.0.1' */
    /* Outputs for IfAction SubSystem: '<S49>/VLC_Active' incorporates:
     *  ActionPort: '<S51>/Action Port'
     */
    /* Outputs for Atomic SubSystem: '<S51>/BoostController1' */
    /* Outputs for Atomic SubSystem: '<S53>/DirectAX' */
    /* Outputs for Atomic SubSystem: '<S12>/SlopeDragTorque' */
    /* If: '<S3>/If' incorporates:
     *  DataStoreRead: '<S22>/curTrqRatio'
     *  DataTypeConversion: '<S22>/Data Type Conversion1'
     *  If: '<S49>/If'
     *  Product: '<S55>/Divide'
     */
    rtb_Saturation_pc = (real32_T)curTrqRatio * 0.001F;

    /* End of Outputs for SubSystem: '<S53>/DirectAX' */
    /* End of Outputs for SubSystem: '<S51>/BoostController1' */
    /* End of Outputs for SubSystem: '<S49>/VLC_Active' */
    /* End of Outputs for SubSystem: '<S15>/VLC_BL0.0.1' */
    /* End of Outputs for SubSystem: '<S3>/If Action Subsystem1' */

    /* Product: '<S22>/Product2' incorporates:
     *  Constant: '<S22>/WghtCurb'
     *  Constant: '<S22>/dbg_slope'
     *  Constant: '<S22>/rd'
     *  DataTypeConversion: '<S22>/Data Type Conversion'
     *  DataTypeConversion: '<S22>/Data Type Conversion1'
     *  DataTypeConversion: '<S22>/Data Type Conversion2'
     *  DataTypeConversion: '<S22>/Data Type Conversion3'
     *  Product: '<S22>/Divide1'
     *  Product: '<S22>/Product'
     *  Product: '<S22>/Product1'
     */
    u0 = rtb_slip_koef * (real32_T)(int16_T)WghtCurb / rtb_Saturation_pc *
      ((real32_T)(rd * 10U) * 0.001F) * (real32_T)dbg_slope;

    /* Saturate: '<S22>/Saturation' incorporates:
     *  DataStoreWrite: '<S22>/SlopeDragTorque1'
     */
    if (u0 > 32767.0F) {
      u0 = 32767.0F;
    } else {
      if (u0 < -32767.0F) {
        u0 = -32767.0F;
      }
    }

    SlopeDragTorque = (int16_T)rt_roundf_snf(u0);

    /* End of Saturate: '<S22>/Saturation' */
    /* End of Outputs for SubSystem: '<S12>/SlopeDragTorque' */
    /* End of Outputs for SubSystem: '<S3>/BasicModel' */

    /* Chart: '<S3>/MainVestaChart' incorporates:
     *  DataStoreRead: '<S3>/StandStillRequest'
     *  DataStoreRead: '<S3>/VehSpd_timer_in'
     *  DataStoreRead: '<S3>/VehicleSpeed'
     *  DataStoreRead: '<S3>/reqDriveOff'
     */
    /* Gateway: andrukhe/If Action
       Subsystem/MainVestaChart */
    /* During: andrukhe/If Action
       Subsystem/MainVestaChart */
    if (rtDW.is_active_c1_VLCforADAS_UMP == 0U) {
      /* Entry: andrukhe/If Action
         Subsystem/MainVestaChart */
      rtDW.is_active_c1_VLCforADAS_UMP = 1U;

      /* Entry Internal: andrukhe/If Action
         Subsystem/MainVestaChart */
      /* Transition: '<S16>:89' */
      rtDW.is_c1_VLCforADAS_UMP = IN_Init;

      /* Entry 'Init': '<S16>:88' */
      rtDW.VLC_Mode_n = 0U;
    } else {
      switch (rtDW.is_c1_VLCforADAS_UMP) {
       case IN_Init:
        /* During 'Init': '<S16>:88' */
        if (VehicleSpeed_VLCInt < DOV_VehSpdMax) {
          /* Transition: '<S16>:87' */
          rtDW.is_c1_VLCforADAS_UMP = IN_SSM;

          /* Entry 'SSM': '<S16>:226' */
          rtDW.VLC_Mode_n = 7U;

          /* Entry Internal 'SSM': '<S16>:226' */
          /* Transition: '<S16>:220' */
          rtDW.is_SSM = IN_in_SSM;
        } else if ((StandStillReq == 1) && (VehicleSpeed_VLCInt <= DOV_VehSpdMin))
        {
          /* Transition: '<S16>:90' */
          rtDW.is_c1_VLCforADAS_UMP = IN_SSR;

          /* Entry 'SSR': '<S16>:51' */
          rtDW.VLC_Mode_n = 8U;
        } else {
          if ((VehicleSpeed_VLCInt >= DOV_VehSpdMax) || (VehicleSpeed_VLCInt >=
               DOV_VehSpdMin)) {
            /* Transition: '<S16>:91' */
            rtDW.is_c1_VLCforADAS_UMP = IN_VLC_CDD;

            /* Entry 'VLC_CDD': '<S16>:67' */
            rtDW.VLC_Mode_n = 4U;
            rtDW.DriveOff_Mode_d = 0U;
          }
        }
        break;

       case IN_SSM:
        /* During 'SSM': '<S16>:226' */
        if (VehicleSpeed_VLCInt >= DOV_VehSpdMax) {
          /* Transition: '<S16>:73' */
          /* Exit Internal 'SSM': '<S16>:226' */
          rtDW.is_SSM = IN_NO_ACTIVE_CHILD;
          rtDW.is_c1_VLCforADAS_UMP = IN_VLC_CDD;

          /* Entry 'VLC_CDD': '<S16>:67' */
          rtDW.VLC_Mode_n = 4U;
          rtDW.DriveOff_Mode_d = 0U;
        } else {
          switch (rtDW.is_SSM) {
           case IN_Drive_off:
            rtDW.DriveOff_Mode_d = 11U;

            /* During 'Drive_off': '<S16>:238' */
            if ((StandStillReq == 1) && (DO_SSR_err_tmr >= DO_SSR_err_tmr_max))
            {
              /* Transition: '<S16>:86' */
              rtDW.is_SSM = IN_NO_ACTIVE_CHILD;
              rtDW.is_c1_VLCforADAS_UMP = IN_SSR;

              /* Entry 'SSR': '<S16>:51' */
              rtDW.VLC_Mode_n = 8U;
            }
            break;

           case IN_Stop:
            rtDW.DriveOff_Mode_d = 0U;

            /* During 'Stop': '<S16>:229' */
            if ((DriveOffReq == 1) && (DO_SSR_err_tmr >= DO_SSR_err_tmr_max)) {
              /* Transition: '<S16>:54' */
              rtDW.is_SSM = IN_Drive_off;

              /* Entry 'Drive_off': '<S16>:238' */
              rtDW.VLC_Mode_n = 2U;
              rtDW.DriveOff_Mode_d = 11U;
            }
            break;

           default:
            /* During 'in_SSM': '<S16>:224' */
            if (SSR_timer >= SSR_tmr_max) {
              /* Transition: '<S16>:241' */
              rtDW.is_SSM = IN_Stop;

              /* Entry 'Stop': '<S16>:229' */
              rtDW.VLC_Mode_n = 1U;
              rtDW.DriveOff_Mode_d = 0U;
            } else {
              if ((DriveOffReq == 1) && (DO_SSR_err_tmr >= DO_SSR_err_tmr_max) &&
                  (SSR_timer < SSR_tmr_max)) {
                /* Transition: '<S16>:242' */
                rtDW.is_SSM = IN_Drive_off;

                /* Entry 'Drive_off': '<S16>:238' */
                rtDW.VLC_Mode_n = 2U;
                rtDW.DriveOff_Mode_d = 11U;
              }
            }
            break;
          }
        }
        break;

       case IN_SSR:
        /* During 'SSR': '<S16>:51' */
        if (((StandStillReq == 1) && (VehicleSpeed_VLCInt == 0)) || (DriveOffReq
             == 1)) {
          /* Transition: '<S16>:56' */
          rtDW.is_c1_VLCforADAS_UMP = IN_SSM;

          /* Entry 'SSM': '<S16>:226' */
          rtDW.VLC_Mode_n = 7U;

          /* Entry Internal 'SSM': '<S16>:226' */
          /* Transition: '<S16>:220' */
          rtDW.is_SSM = IN_in_SSM;
        } else {
          if (VehicleSpeed_VLCInt >= DOV_VehSpdMax) {
            /* Transition: '<S16>:260' */
            rtDW.is_c1_VLCforADAS_UMP = IN_VLC_CDD;

            /* Entry 'VLC_CDD': '<S16>:67' */
            rtDW.VLC_Mode_n = 4U;
            rtDW.DriveOff_Mode_d = 0U;
          }
        }
        break;

       default:
        rtDW.DriveOff_Mode_d = 0U;

        /* During 'VLC_CDD': '<S16>:67' */
        if (VehicleSpeed_VLCInt <= DOV_VehSpdMin) {
          /* Transition: '<S16>:71' */
          rtDW.is_c1_VLCforADAS_UMP = IN_SSR;

          /* Entry 'SSR': '<S16>:51' */
          rtDW.VLC_Mode_n = 8U;
        } else {
          if (VehSpd_timer >= VehSpd_tmr_max) {
            /* Transition: '<S16>:102' */
            rtDW.is_c1_VLCforADAS_UMP = IN_SSM;

            /* Entry 'SSM': '<S16>:226' */
            rtDW.VLC_Mode_n = 7U;

            /* Entry Internal 'SSM': '<S16>:226' */
            /* Transition: '<S16>:220' */
            rtDW.is_SSM = IN_in_SSM;
          }
        }
        break;
      }
    }

    /* End of Chart: '<S3>/MainVestaChart' */

    /* Outputs for Atomic SubSystem: '<S3>/Subsystem' */
    /* DataTypeConversion: '<S71>/Data Type Conversion1' incorporates:
     *  Constant: '<S71>/DOV_TimerThreshold'
     *  DataStoreRead: '<S71>/DOV_ApprovalTimer'
     *  DataStoreWrite: '<S17>/DOV_ApprovalFlag'
     *  RelationalOperator: '<S71>/Relational Operator'
     */
    BrakeReleaseReq = (uint8_T)(DOV_ApprovalTimer >= DOV_TimerThreshold);

    /* DataStoreWrite: '<S17>/DriveOff_Mode' */
    DriveOff_Mode = rtDW.DriveOff_Mode_d;

    /* DataStoreWrite: '<S17>/VLC_Mode' incorporates:
     *  Inport: '<S17>/VLC_Mode_In'
     */
    VLC_Mode = rtDW.VLC_Mode_n;

    /* Sum: '<S17>/Add1' incorporates:
     *  DataStoreRead: '<S17>/Data Store Read2'
     */
    tmp_1 = refSpeed * 25ULL;
    rtb_DataTypeConversion_j = (int16_T)((int16_T)(((tmp_1 & 65536ULL) != 0ULL)
      + (tmp_1 >> 17)) - (int16_T)rtb_DataTypeConversion_ai);

    /* Outputs for Atomic SubSystem: '<S17>/CLBC_PI_2.0' */
    /* Saturate: '<S68>/Saturation' incorporates:
     *  DataStoreRead: '<S68>/numGearEngaged'
     */
    if (numGearEngaged_vlc > 9) {
      rtb_Switch1_k = 9U;
    } else if (numGearEngaged_vlc < 1) {
      rtb_Switch1_k = 1U;
    } else {
      rtb_Switch1_k = numGearEngaged_vlc;
    }

    /* End of Saturate: '<S68>/Saturation' */

    /* Saturate: '<S68>/Saturation4' incorporates:
     *  Constant: '<S68>/DOV_bkpCal'
     */
    if (DOV_bkpCal < 600) {
      rtb_Switch1_hj = DOV_bkpCal;
    } else {
      rtb_Switch1_hj = 600U;
    }

    /* End of Saturate: '<S68>/Saturation4' */

    /* Product: '<S68>/Product' incorporates:
     *  DataTypeConversion: '<S68>/Data Type Conversion2'
     *  Lookup_n-D: '<S68>/Boost_map'
     */
    rtb_Saturation2 = look1_is16lu32n32Ds32_linlcas((int16_T)(rtb_Switch1_k *
      100U), (&(Gb_MAP[0])), (&(B_MAP[0])), 8U) * rtb_Switch1_hj;
    rtb_Saturation2 = (int16_T)((((rtb_Saturation2 & 512U) != 0U) &&
      (((rtb_Saturation2 & 511U) != 0U) || (rtb_Saturation2 > 0))) +
      (rtb_Saturation2 >> 10)) * 16777;
    rtb_Switch_e = (int16_T)((((rtb_Saturation2 & 8192U) != 0U) &&
      (((rtb_Saturation2 & 8191U) != 0U) || (rtb_Saturation2 > 0))) +
      (rtb_Saturation2 >> 14));

    /* Saturate: '<S68>/Saturation6' */
    if (rtb_Switch_e > 18000) {
      rtb_Switch_e = 18000;
    } else {
      if (rtb_Switch_e < -18000) {
        rtb_Switch_e = -18000;
      }
    }

    /* End of Saturate: '<S68>/Saturation6' */

    /* Saturate: '<S68>/Saturation1' */
    if (rtb_DataTypeConversion_j > 1000) {
      rtb_DataTypeConversion_j = 1000;
    } else {
      if (rtb_DataTypeConversion_j < -1000) {
        rtb_DataTypeConversion_j = -1000;
      }
    }

    /* End of Saturate: '<S68>/Saturation1' */

    /* Product: '<S68>/Divide4' */
    rtb_Saturation2 = rtb_Switch_e * rtb_DataTypeConversion_j;
    tmp = ((((rtb_Saturation2 & 8U) != 0U) && (((rtb_Saturation2 & 7U) != 0U) ||
             (rtb_Saturation2 > 0))) + (rtb_Saturation2 >> 4)) * 858993459LL;
    rtb_Saturation2 = (int32_T)((((tmp & 268435456ULL) != 0ULL) && (((tmp &
      268435455ULL) != 0ULL) || (tmp > 0LL))) + (tmp >> 29));

    /* Saturate: '<S68>/Saturation2' */
    if (rtb_Saturation2 >= 100000) {
      rtb_Switch_e = 1000;
    } else if (rtb_Saturation2 <= -100000) {
      rtb_Switch_e = -1000;
    } else {
      tmp = rtb_Saturation2 * 1374389535LL;
      rtb_Switch_e = (int16_T)((((tmp & 68719476736ULL) != 0ULL) && (((tmp &
        68719476735ULL) != 0ULL) || (tmp > 0LL))) + (tmp >> 37));
    }

    /* End of Saturate: '<S68>/Saturation2' */

    /* Outputs for Atomic SubSystem: '<S68>/Boost_I' */
    /* Saturate: '<S75>/Saturation1' */
    if (rtb_DataTypeConversion_j > 500) {
      rtb_DataTypeConversion_j = 500;
    } else {
      if (rtb_DataTypeConversion_j < -500) {
        rtb_DataTypeConversion_j = -500;
      }
    }

    /* End of Saturate: '<S75>/Saturation1' */

    /* Outputs for Atomic SubSystem: '<S75>/Integration' */
    /* Product: '<S77>/Product' incorporates:
     *  Constant: '<S77>/Constant'
     *  Delay: '<S77>/Delay'
     *  Sum: '<S77>/Add'
     */
    rtb_Saturation2 = (int16_T)(rtb_DataTypeConversion_j + rtDW.Delay_DSTATE_kj)
      * B_pidC_h;
    rtb_Saturation2 = (int16_T)((((rtb_Saturation2 & 64U) != 0U) &&
      (((rtb_Saturation2 & 63U) != 0U) || (rtb_Saturation2 > 0))) +
      (rtb_Saturation2 >> 7)) * 5243;

    /* Sum: '<S77>/Add3' incorporates:
     *  Constant: '<S77>/Constant2'
     *  DataStoreRead: '<S77>/DOV_bPID_int_in'
     *  Product: '<S77>/Divide'
     *  Product: '<S77>/Product'
     */
    rtb_Saturation2 = (int16_T)div_nzp_s32_round((int16_T)((((rtb_Saturation2 &
      2048U) != 0U) && (((rtb_Saturation2 & 2047U) != 0U) || (rtb_Saturation2 >
      0))) + (rtb_Saturation2 >> 12)), c_2) * 13107;
    rtb_Saturation_o = (int16_T)(((((rtb_Saturation2 & 65536U) != 0U) &&
      (((rtb_Saturation2 & 65535U) != 0U) || (rtb_Saturation2 > 0))) +
      (rtb_Saturation2 >> 17)) + DOV_bPID_int);

    /* Saturate: '<S77>/Saturation1' */
    rtb_Saturation2 = BoostIntegrationLowerSat * 1000;
    if (rtb_Saturation2 > 32767) {
      rtb_Saturation2 = 32767;
    } else {
      if (rtb_Saturation2 < -32768) {
        rtb_Saturation2 = -32768;
      }
    }

    rtb_Product1_l = BoostIntegrationUpperSat * 1000;
    if (rtb_Product1_l > 32767) {
      rtb_Product1_l = 32767;
    } else {
      if (rtb_Product1_l < -32768) {
        rtb_Product1_l = -32768;
      }
    }

    if (rtb_Saturation_o > (int16_T)rtb_Product1_l) {
      rtb_Saturation_o = (int16_T)rtb_Product1_l;
    } else {
      if (rtb_Saturation_o < (int16_T)rtb_Saturation2) {
        rtb_Saturation_o = (int16_T)rtb_Saturation2;
      }
    }

    /* End of Saturate: '<S77>/Saturation1' */

    /* DataStoreWrite: '<S77>/DOV_bPID_int_out' */
    DOV_bPID_int = rtb_Saturation_o;

    /* Update for Delay: '<S77>/Delay' */
    rtDW.Delay_DSTATE_kj = rtb_DataTypeConversion_j;

    /* End of Outputs for SubSystem: '<S75>/Integration' */

    /* Saturate: '<S75>/Saturation' incorporates:
     *  DataStoreRead: '<S75>/numGearEngaged'
     */
    if (numGearEngaged_vlc > 9) {
      rtb_Switch1_k = 9U;
    } else if (numGearEngaged_vlc < 1) {
      rtb_Switch1_k = 1U;
    } else {
      rtb_Switch1_k = numGearEngaged_vlc;
    }

    /* End of Saturate: '<S75>/Saturation' */

    /* Saturate: '<S75>/Saturation2' incorporates:
     *  Constant: '<S75>/DOV_bkiCal'
     */
    if (DOV_bkiCal < 500) {
      rtb_Switch1_hj = DOV_bkiCal;
    } else {
      rtb_Switch1_hj = 500U;
    }

    /* End of Saturate: '<S75>/Saturation2' */

    /* Product: '<S75>/Product1' incorporates:
     *  DataTypeConversion: '<S75>/Data Type Conversion'
     *  Lookup_n-D: '<S75>/Boost_map'
     */
    rtb_Saturation2 = look1_is16lu32n32Ds32_linlcas((int16_T)(rtb_Switch1_k *
      100U), (&(Gb_MAP[0])), (&(B_MAP[0])), 8U) * rtb_Switch1_hj;
    rtb_Saturation2 = (int16_T)((((rtb_Saturation2 & 512U) != 0U) &&
      (((rtb_Saturation2 & 511U) != 0U) || (rtb_Saturation2 > 0))) +
      (rtb_Saturation2 >> 10)) * 16777;

    /* Product: '<S75>/Product2' incorporates:
     *  Product: '<S75>/Product1'
     */
    rtb_Saturation2 = (int16_T)((((rtb_Saturation2 & 8192U) != 0U) &&
      (((rtb_Saturation2 & 8191U) != 0U) || (rtb_Saturation2 > 0))) +
      (rtb_Saturation2 >> 14)) * rtb_DataTypeConversion_j;
    rtb_Saturation2 = (int16_T)((((rtb_Saturation2 & 64U) != 0U) &&
      (((rtb_Saturation2 & 63U) != 0U) || (rtb_Saturation2 > 0))) +
      (rtb_Saturation2 >> 7)) * 5243;

    /* Product: '<S75>/Product' incorporates:
     *  Product: '<S75>/Product2'
     */
    rtb_Saturation2 = (int16_T)((((rtb_Saturation2 & 2048U) != 0U) &&
      (((rtb_Saturation2 & 2047U) != 0U) || (rtb_Saturation2 > 0))) +
      (rtb_Saturation2 >> 12)) * rtb_Saturation_o;
    tmp = ((((rtb_Saturation2 & 64U) != 0U) && (((rtb_Saturation2 & 63U) != 0U) ||
             (rtb_Saturation2 > 0))) + (rtb_Saturation2 >> 7)) * 1374389535LL;
    rtb_Saturation2 = (int32_T)((((tmp & 536870912ULL) != 0ULL) && (((tmp &
      536870911ULL) != 0ULL) || (tmp > 0LL))) + (tmp >> 30));

    /* Saturate: '<S75>/Saturation3' */
    if (rtb_Saturation2 >= 100000) {
      rtb_DataTypeConversion_j = 1000;
    } else if (rtb_Saturation2 <= -100000) {
      rtb_DataTypeConversion_j = -1000;
    } else {
      tmp = rtb_Saturation2 * 1374389535LL;
      rtb_DataTypeConversion_j = (int16_T)((((tmp & 68719476736ULL) != 0ULL) &&
        (((tmp & 68719476735ULL) != 0ULL) || (tmp > 0LL))) + (tmp >> 37));
    }

    /* End of Saturate: '<S75>/Saturation3' */

    /* Outputs for Atomic SubSystem: '<S75>/Upper_SAT' */
    /* Sum: '<S79>/Add' incorporates:
     *  Delay: '<S68>/Delay1'
     */
    rtb_Saturation_o = (int16_T)(rtDW.Delay1_DSTATE_l - rtb_Switch_e);

    /* End of Outputs for SubSystem: '<S75>/Upper_SAT' */

    /* Switch: '<S78>/Switch2' incorporates:
     *  RelationalOperator: '<S78>/LowerRelop1'
     */
    if (rtb_DataTypeConversion_j <= rtb_Saturation_o) {
      /* Outputs for Atomic SubSystem: '<S75>/Upper_SAT1' */
      /* Sum: '<S80>/Add' incorporates:
       *  Delay: '<S68>/Delay'
       */
      rtb_Saturation_o = (int16_T)(rtDW.Delay_DSTATE_k - rtb_Switch_e);

      /* End of Outputs for SubSystem: '<S75>/Upper_SAT1' */

      /* Switch: '<S78>/Switch' incorporates:
       *  RelationalOperator: '<S78>/UpperRelop'
       */
      if (rtb_DataTypeConversion_j >= rtb_Saturation_o) {
        rtb_Saturation_o = rtb_DataTypeConversion_j;
      }

      /* End of Switch: '<S78>/Switch' */
    }

    /* End of Switch: '<S78>/Switch2' */
    /* End of Outputs for SubSystem: '<S68>/Boost_I' */

    /* Sum: '<S68>/Add1' */
    rtb_Saturation_o += rtb_Switch_e;

    /* Outputs for Atomic SubSystem: '<S68>/Subsystem' */
    /* Saturate: '<S76>/Saturation' incorporates:
     *  DataStoreRead: '<S76>/numGearEngaged'
     */
    if (numGearEngaged_vlc > 9) {
      rtb_Switch1_k = 9U;
    } else if (numGearEngaged_vlc < 1) {
      rtb_Switch1_k = 1U;
    } else {
      rtb_Switch1_k = numGearEngaged_vlc;
    }

    /* End of Saturate: '<S76>/Saturation' */

    /* Lookup_n-D: '<S76>/trqLimits1' incorporates:
     *  DataTypeConversion: '<S76>/Data Type Conversion4'
     */
    rtb_Switch_e = look1_is16lu32n32Ds32_linlcas(rtb_Switch1_k, (&(GearNumber[0])),
      (&(trqLimits_PI_Boost[0])), 8U);

    /* Product: '<S76>/Product3' incorporates:
     *  Constant: '<S76>/Constant1'
     *  Constant: '<S76>/MinimumPIDTrqReq'
     *  Sum: '<S76>/Add2'
     */
    rtb_DataTypeConversion_j = (int16_T)((int16_T)(MinimumPIDTrqReq +
      rtb_Switch_e) * c_n_1);

    /* Switch: '<S76>/Switch_trqLimits1' incorporates:
     *  RelationalOperator: '<S76>/Relational_Operator_trqLimits1'
     */
    if (rtb_Saturation_o <= rtb_Switch_e) {
      /* Switch: '<S76>/Switch_trqLimits3' incorporates:
       *  RelationalOperator: '<S76>/Relational_Operator_trqLimits3'
       */
      if (rtb_DataTypeConversion_j >= rtb_Saturation_o) {
        rtb_Saturation_o = rtb_DataTypeConversion_j;
      }

      /* End of Switch: '<S76>/Switch_trqLimits3' */
    } else {
      rtb_Saturation_o = rtb_Switch_e;
    }

    /* End of Switch: '<S76>/Switch_trqLimits1' */
    /* End of Outputs for SubSystem: '<S68>/Subsystem' */

    /* DataStoreWrite: '<S68>/DOV_trqPID' */
    DOV_trqPID = rtb_Saturation_o;

    /* Update for Delay: '<S68>/Delay1' */
    rtDW.Delay1_DSTATE_l = rtb_Switch_e;

    /* Update for Delay: '<S68>/Delay' */
    rtDW.Delay_DSTATE_k = rtb_DataTypeConversion_j;

    /* End of Outputs for SubSystem: '<S17>/CLBC_PI_2.0' */

    /* RelationalOperator: '<S17>/Relational Operator3' incorporates:
     *  Constant: '<S17>/Constant3'
     */
    rtb_RelationalOperator1_ce = (rtDW.DriveOff_Mode_d == 11);

    /* Switch: '<S17>/Switch' */
    if (rtb_RelationalOperator1_ce) {
      /* Saturate: '<S17>/Saturation3' incorporates:
       *  DataStoreRead: '<S17>/M_MotClutch_OLBC'
       */
      if (M_MotClutch_OLBC > 650) {
        rtb_Abs_g = 650;
      } else if (M_MotClutch_OLBC < 0) {
        rtb_Abs_g = 0;
      } else {
        rtb_Abs_g = M_MotClutch_OLBC;
      }

      /* End of Saturate: '<S17>/Saturation3' */

      /* Sum: '<S72>/Add' incorporates:
       *  Constant: '<S72>/DOV_TrqOffset'
       *  Sum: '<S17>/Add2'
       */
      rtb_Product1_l = (rtb_Saturation_o + rtb_Abs_g) + DOV_TrqOffset;

      /* Saturate: '<S17>/Saturation1' incorporates:
       *  DataStoreWrite: '<S17>/VLC_TargetEngTorque'
       */
      if (rtb_Product1_l > 650) {
        VLC_TargetEngTorque = 650;
      } else if (rtb_Product1_l < 0) {
        VLC_TargetEngTorque = 0;
      } else {
        VLC_TargetEngTorque = (int16_T)rtb_Product1_l;
      }

      /* End of Saturate: '<S17>/Saturation1' */
    }

    /* End of Switch: '<S17>/Switch' */

    /* Switch: '<S17>/Switch4' incorporates:
     *  Constant: '<S17>/OLD_NEW_ACCSTAT'
     *  Constant: '<S69>/Constant'
     *  Constant: '<S70>/Constant'
     *  DataStoreRead: '<S1>/pWheelRR1'
     *  Inport: '<S4>/ACCStat_in'
     *  RelationalOperator: '<S69>/Compare'
     *  RelationalOperator: '<S70>/Compare'
     */
    if (NewAccStatReqs > 0) {
      /* Outputs for Atomic SubSystem: '<S1>/Input Processing1' */
      rtb_RelationalOperator2_d = (AccActive >= 2);

      /* End of Outputs for SubSystem: '<S1>/Input Processing1' */
    } else {
      /* Outputs for Atomic SubSystem: '<S1>/Input Processing1' */
      rtb_RelationalOperator2_d = (AccActive == 2);

      /* End of Outputs for SubSystem: '<S1>/Input Processing1' */
    }

    /* End of Switch: '<S17>/Switch4' */

    /* If: '<S17>/If' incorporates:
     *  Constant: '<S17>/Constant'
     *  Constant: '<S17>/Constant1'
     *  Inport: '<S17>/VLC_Mode_In'
     *  Logic: '<S17>/Logical Operator'
     *  Logic: '<S17>/Logical Operator1'
     *  Logic: '<S17>/Logical Operator2'
     *  RelationalOperator: '<S17>/Relational Operator'
     *  RelationalOperator: '<S17>/Relational Operator1'
     */
    if (((rtDW.VLC_Mode_n == 4) || (rtDW.VLC_Mode_n == 8) ||
         rtb_RelationalOperator1_ce) && rtb_RelationalOperator2_d) {
      /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem' incorporates:
       *  ActionPort: '<S73>/Action Port'
       */
      /* Outputs for Atomic SubSystem: '<S73>/CLBC_Flaw1' */
      /* Switch: '<S84>/Switch4' incorporates:
       *  Constant: '<S84>/Constant7'
       *  Constant: '<S84>/speedOffsetSlipCntrl'
       *  DataStoreRead: '<S84>/cardanSpeed'
       *  DataStoreWrite: '<S84>/Data Store Write2'
       *  RelationalOperator: '<S84>/Relational Operator4'
       */
      if (cardanSpeed < speedOffsetSlipCntrl) {
        targetSlipSt = 0U;
      } else {
        /* Sum: '<S84>/Add' incorporates:
         *  Constant: '<S84>/Constant5'
         *  Lookup_n-D: '<S84>/1-D Lookup Table1'
         *  Product: '<S84>/Product'
         */
        rtb_Switch_e = (int16_T)((int16_T)(((int16_T)((rtb_DataTypeConversion_ai
          * look1_is16lu32n32Ds32_linlcas(0, (&(muTable[0])), (&(targetSlip[0])),
          4U)) >> 7) * 5243) >> 12) + (int16_T)rtb_DataTypeConversion_ai);

        /* Switch: '<S84>/Switch2' incorporates:
         *  Constant: '<S84>/targetSlipFactor'
         *  Product: '<S84>/Product1'
         *  RelationalOperator: '<S84>/Relational Operator1'
         *  RelationalOperator: '<S84>/Relational Operator2'
         *  Switch: '<S84>/Switch1'
         */
        if (cardanSpeed > rtb_Switch_e) {
          /* DataStoreWrite: '<S84>/Data Store Write2' incorporates:
           *  Constant: '<S84>/Constant3'
           */
          targetSlipSt = 1U;
        } else {
          if (cardanSpeed < (int16_T)(((int16_T)((rtb_Switch_e *
                  targetSlipFactor) >> 7) * 5243) >> 12)) {
            /* DataStoreWrite: '<S84>/Data Store Write2' incorporates:
             *  Constant: '<S84>/Constant1'
             *  Switch: '<S84>/Switch1'
             */
            targetSlipSt = 0U;
          }
        }

        /* End of Switch: '<S84>/Switch2' */
      }

      /* End of Switch: '<S84>/Switch4' */

      /* Switch: '<S84>/Switch5' incorporates:
       *  Constant: '<S84>/Constant8'
       *  Constant: '<S84>/Constant9'
       *  DataStoreRead: '<S17>/jerkAcceleration'
       *  DataStoreWrite: '<S84>/Data Store Write2'
       *  RelationalOperator: '<S84>/Relational Operator5'
       */
      if (1 == targetSlipSt) {
        rtb_Switch_e = 819;
      } else {
        rtb_Switch_e = jerkAcceleration;
      }

      /* End of Switch: '<S84>/Switch5' */

      /* Switch: '<S84>/Switch3' incorporates:
       *  DataStoreRead: '<S17>/jerkAcceleration'
       *  RelationalOperator: '<S84>/Relational Operator3'
       */
      if (jerkAcceleration <= rtb_Switch_e) {
        rtb_Switch_e = jerkAcceleration;
      }

      /* End of Switch: '<S84>/Switch3' */

      /* Outputs for Atomic SubSystem: '<S83>/refSpeedCalculation' */
      /* Product: '<S85>/Product' incorporates:
       *  Constant: '<S85>/B_pidC_h'
       *  Delay: '<S85>/Delay3'
       *  Sum: '<S85>/Add1'
       */
      rtb_Saturation2 = (int16_T)(rtb_Switch_e + rtDW.Delay3_DSTATE_k) *
        B_pidC_h;
      rtb_Saturation2 = (int16_T)((((rtb_Saturation2 & 16U) != 0U) &&
        (((rtb_Saturation2 & 15U) != 0U) || (rtb_Saturation2 > 0))) +
        (rtb_Saturation2 >> 5)) * 6711;

      /* Sum: '<S85>/Add' incorporates:
       *  Constant: '<S85>/C_2'
       *  DataStoreRead: '<S85>/refSpeed'
       *  DataTypeConversion: '<S85>/Data Type Conversion1'
       *  DataTypeConversion: '<S85>/Data Type Conversion2'
       *  Product: '<S85>/Divide'
       *  Product: '<S85>/Product'
       */
      rtb_Product1_l = (int16_T)div_nzp_s32_round((int16_T)((((rtb_Saturation2 &
        2048U) != 0U) && (((rtb_Saturation2 & 2047U) != 0U) || (rtb_Saturation2 >
        0))) + (rtb_Saturation2 >> 12)) << 1, (int16_T)c_2) + (int32_T)refSpeed;

      /* Saturate: '<S85>/Saturation1' */
      if (rtb_Product1_l > 37224448) {
        rtb_Product1_l = 37224448;
      } else {
        if (rtb_Product1_l < 0) {
          rtb_Product1_l = 0;
        }
      }

      /* End of Saturate: '<S85>/Saturation1' */

      /* DataTypeConversion: '<S85>/Data Type Conversion' */
      rtb_DataTypeConversion_hs = (uint32_T)rtb_Product1_l;

      /* Update for Delay: '<S85>/Delay3' */
      rtDW.Delay3_DSTATE_k = rtb_Switch_e;

      /* End of Outputs for SubSystem: '<S83>/refSpeedCalculation' */

      /* Outputs for Atomic SubSystem: '<S83>/refSpeedSubsystem' */
      /* Sum: '<S86>/Add' incorporates:
       *  Constant: '<S86>/Constant3'
       *  Lookup_n-D: '<S86>/1-D Lookup Table1'
       *  Lookup_n-D: '<S86>/1-D Lookup Table2'
       *  Lookup_n-D: '<S86>/1-D Lookup Table3'
       *  Product: '<S86>/Product'
       */
      rtb_Product1_l = ((int16_T)(((int16_T)(((int16_T)
        ((rtb_DataTypeConversion_ai * look1_is16lu32n32Ds32_linlcas(100,
        (&(muTable[0])), (&(targetSlip[0])), 4U)) >> 7) *
        look1_iu16bs16lu32n32t_Ji2sqUY0(rtb_DataTypeConversion_ai,
        (&(SpeedSlipFactorSpd[0])), (&(SpeedSlipFactor[0])), 15U)) >> 7) * 6711)
        >> 12) + rtb_DataTypeConversion_ai) + look1_iu16lu64n48ts16D_Xu1w5Bqg
        (rtb_DataTypeConversion_ai, (&(FreeRollingResistanceBP[0])),
         (&(slipSpeedOffset[0])), 15U);

      /* Saturate: '<S86>/Saturation' */
      if (rtb_Product1_l > 7000) {
        rtb_Saturation2 = 7000;
      } else if (rtb_Product1_l < 0) {
        rtb_Saturation2 = 0;
      } else {
        rtb_Saturation2 = rtb_Product1_l;
      }

      /* End of Saturate: '<S86>/Saturation' */

      /* Switch: '<S86>/Switch1' incorporates:
       *  DataTypeConversion: '<S86>/Data Type Conversion'
       *  RelationalOperator: '<S86>/Relational Operator1'
       */
      if ((int64_T)(rtb_DataTypeConversion_hs * 25ULL) >= ((int64_T)
           rtb_Saturation2 << 17)) {
        rtb_DataTypeConversion_hs = (uint32_T)((rtb_Product1_l * 1374389535LL) >>
          18);
      }

      /* End of Switch: '<S86>/Switch1' */

      /* Outputs for Atomic SubSystem: '<S86>/Subsystem1' */
      /* Switch: '<S92>/Switch' incorporates:
       *  Constant: '<S92>/Constant1'
       *  Constant: '<S92>/Constant3'
       *  DataStoreRead: '<S92>/targetSpeed1'
       *  DataStoreRead: '<S92>/targetSpeed2'
       *  Sum: '<S92>/Add'
       */
      if (targetSpeedTmrFlag > 0) {
        rtb_Switch1_k = (uint8_T)(targetSpeedTmr + 1U);
      } else {
        rtb_Switch1_k = 0U;
      }

      /* End of Switch: '<S92>/Switch' */

      /* Saturate: '<S92>/Saturation' */
      if (rtb_Switch1_k < 200) {
        targetSpeedTmr = rtb_Switch1_k;
      } else {
        targetSpeedTmr = 200U;
      }

      /* End of Saturate: '<S92>/Saturation' */

      /* DataStoreRead: '<S92>/targetSpeed3' */
      rtb_Switch1_k = targetSpeedTmrFlag;

      /* Switch: '<S92>/Switch1' incorporates:
       *  DataStoreRead: '<S17>/targetSpeed'
       *  DataStoreRead: '<S92>/targetSpeed3'
       *  DataStoreRead: '<S92>/targetSpeed4'
       */
      if (targetSpeedTmrFlag > 0) {
        rtb_Switch1_hj = targetSpeedTemp;
      } else {
        rtb_Switch1_hj = targetSpeed;
      }

      /* End of Switch: '<S92>/Switch1' */

      /* RelationalOperator: '<S92>/Relational Operator' */
      rtb_RelationalOperator1_ce = (((uint64_T)rtb_DataTypeConversion_hs << 3) <=
        rtb_Switch1_hj * 41943U);

      /* Logic: '<S92>/Logical Operator3' */
      rtb_RelationalOperator2_d = !rtb_RelationalOperator1_ce;

      /* Outputs for Triggered SubSystem: '<S92>/Triggered Subsystem' incorporates:
       *  TriggerPort: '<S94>/Trigger'
       */
      if (rtb_RelationalOperator2_d && (rtPrevZCX.TriggeredSubsystem_Trig_ZCE_j
           != POS_ZCSIG)) {
        /* DataStoreWrite: '<S94>/Data Store Write' incorporates:
         *  Constant: '<S94>/Constant3'
         */
        targetSpeedTmrFlag = 1U;

        /* DataStoreWrite: '<S94>/Data Store Write1' incorporates:
         *  DataStoreRead: '<S94>/targetSpeedDelay'
         */
        targetSpeedTemp = targetSpeedDelay;
      }

      rtPrevZCX.TriggeredSubsystem_Trig_ZCE_j = rtb_RelationalOperator2_d;

      /* End of Outputs for SubSystem: '<S92>/Triggered Subsystem' */

      /* RelationalOperator: '<S92>/Relational Operator2' incorporates:
       *  Constant: '<S92>/Constant2'
       *  DataStoreWrite: '<S92>/Data Store Write'
       */
      rtb_RelationalOperator2_md = (targetSpeedTmr >= 30);

      /* Outputs for Triggered SubSystem: '<S92>/Triggered Subsystem1' incorporates:
       *  TriggerPort: '<S95>/Trigger'
       */
      if (rtb_RelationalOperator2_md && (rtPrevZCX.TriggeredSubsystem1_Trig_ZCE
           != POS_ZCSIG)) {
        /* DataStoreWrite: '<S95>/Data Store Write' incorporates:
         *  Constant: '<S95>/Constant3'
         */
        targetSpeedTmrFlag = 0U;

        /* DataStoreWrite: '<S95>/Data Store Write1' incorporates:
         *  DataStoreRead: '<S95>/targetSpeedDelay'
         */
        targetSpeedTemp = targetSpeed;
      }

      rtPrevZCX.TriggeredSubsystem1_Trig_ZCE = rtb_RelationalOperator2_md;

      /* End of Outputs for SubSystem: '<S92>/Triggered Subsystem1' */
      /* End of Outputs for SubSystem: '<S86>/Subsystem1' */

      /* Switch: '<S86>/Switch4' incorporates:
       *  Constant: '<S88>/Constant'
       *  Constant: '<S89>/Constant'
       *  Constant: '<S90>/Constant'
       *  DataStoreRead: '<S86>/DriveOff_Mode'
       *  DataStoreRead: '<S86>/VLC_Available'
       *  DataStoreRead: '<S86>/gearShift'
       *  DataStoreRead: '<S86>/reqAcceleration'
       *  DataStoreRead: '<S86>/reqAcceleration1'
       *  DataStoreWrite: '<S86>/refSpeed_out'
       *  DataTypeConversion: '<S86>/Data Type Conversion1'
       *  Logic: '<S86>/Logical Operator'
       *  Logic: '<S86>/Logical Operator2'
       *  Logic: '<S86>/Logical Operator3'
       *  Logic: '<S92>/Logical Operator1'
       *  Logic: '<S92>/Logical Operator2'
       *  Logic: '<S92>/Logical Operator4'
       *  Logic: '<S92>/Logical Operator5'
       *  RelationalOperator: '<S87>/Compare'
       *  RelationalOperator: '<S88>/Compare'
       *  RelationalOperator: '<S89>/Compare'
       *  RelationalOperator: '<S90>/Compare'
       *  RelationalOperator: '<S93>/Compare'
       *  Switch: '<S86>/Switch'
       */
      if (((gearShift == 1) && (reqAcceleration > 11)) || ((VLC_Available == 0) &&
           (DriveOff_Mode == 0))) {
        /* DataTypeConversion: '<S86>/Data Type Conversion1' */
        rtb_DataTypeConversion_hs = rtb_DataTypeConversion_ai * 41943U;
        refSpeed = ((rtb_DataTypeConversion_hs & 4U) != 0U) +
          (rtb_DataTypeConversion_hs >> 3);
      } else {
        /* Outputs for Atomic SubSystem: '<S86>/Subsystem1' */
        if (rtb_RelationalOperator1_ce || (rtb_RelationalOperator2_d &&
             (reqAcceleration < 0)) || ((rtb_Switch1_k != 0) &&
             (!rtb_RelationalOperator2_md))) {
          /* Switch: '<S86>/Switch' incorporates:
           *  DataStoreWrite: '<S86>/refSpeed_out'
           */
          refSpeed = rtb_DataTypeConversion_hs;
        } else {
          /* Switch: '<S86>/Switch' incorporates:
           *  DataStoreRead: '<S17>/targetSpeed'
           */
          rtb_DataTypeConversion_hs = targetSpeed * 41943U;
          refSpeed = ((rtb_DataTypeConversion_hs & 4U) != 0U) +
            (rtb_DataTypeConversion_hs >> 3);
        }

        /* End of Outputs for SubSystem: '<S86>/Subsystem1' */
      }

      /* End of Switch: '<S86>/Switch4' */
      /* End of Outputs for SubSystem: '<S83>/refSpeedSubsystem' */
      /* End of Outputs for SubSystem: '<S73>/CLBC_Flaw1' */
      /* End of Outputs for SubSystem: '<S17>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S17>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S74>/Action Port'
       */
      /* DataTypeConversion: '<S74>/Data Type Conversion' incorporates:
       *  DataStoreWrite: '<S74>/refSpeed'
       */
      rtb_DataTypeConversion_hs = rtb_DataTypeConversion_ai * 41943U;
      refSpeed = ((rtb_DataTypeConversion_hs & 4U) != 0U) +
        (rtb_DataTypeConversion_hs >> 3);

      /* DataStoreWrite: '<S74>/Data Store Write1' incorporates:
       *  Constant: '<S74>/Constant1'
       */
      targetSlipSt = 0U;

      /* End of Outputs for SubSystem: '<S17>/If Action Subsystem1' */
    }

    /* End of If: '<S17>/If' */

    /* Sum: '<S17>/Add3' incorporates:
     *  Constant: '<S17>/DOV_ApprovTrqFactor'
     *  Constant: '<S17>/DOV_ApprovTrqOffSet'
     *  DataStoreWrite: '<S17>/VLC_TargetEngTorque'
     *  Product: '<S17>/Divide4'
     */
    rtb_Saturation2 = (int32_T)(DOV_ApprovTrqOffSet * 100LL) +
      VLC_TargetEngTorque * DOV_ApprovTrqFactor;

    /* Saturate: '<S17>/Saturation2' */
    tmp = rtb_Saturation2 * 1374389535LL;
    rtb_Product1_l = (int32_T)((((tmp & 68719476736ULL) != 0ULL) && (((tmp &
      68719476735ULL) != 0ULL) || (tmp > 0LL))) + (tmp >> 37));
    if (rtb_Product1_l >= 650) {
      rtb_Saturation2 = 650;
    } else if (rtb_Product1_l <= 0) {
      rtb_Saturation2 = 0;
    } else {
      tmp = rtb_Saturation2 * 1374389535LL;
      rtb_Saturation2 = (int32_T)((((tmp & 68719476736ULL) != 0ULL) && (((tmp &
        68719476735ULL) != 0ULL) || (tmp > 0LL))) + (tmp >> 37));
    }

    /* End of Saturate: '<S17>/Saturation2' */

    /* If: '<S71>/If' incorporates:
     *  DataStoreRead: '<S82>/DOV_ApprovalTimer_0'
     *  RelationalOperator: '<S17>/Relational Operator2'
     *  Saturate: '<S82>/Saturation'
     */
    if (rtb_Saturation2 <= rtb_EngineTorque) {
      /* Outputs for IfAction SubSystem: '<S71>/If Action Subsystem' incorporates:
       *  ActionPort: '<S81>/Action Port'
       */
      /* Saturate: '<S81>/Saturation' incorporates:
       *  DataStoreRead: '<S81>/DOV_ApprovalTimer_0'
       */
      if (DOV_ApprovalTimer < DOV_TimerMax) {
        rtb_Switch1_k = DOV_ApprovalTimer;
      } else {
        rtb_Switch1_k = DOV_TimerMax;
      }

      /* End of Saturate: '<S81>/Saturation' */

      /* Sum: '<S81>/Add' incorporates:
       *  Constant: '<S81>/Constant'
       *  DataStoreWrite: '<S81>/DOV_ApprovalTimer'
       *  DataTypeConversion: '<S81>/Data Type Conversion'
       */
      DOV_ApprovalTimer = (uint8_T)(rtb_Switch1_k + 1);

      /* End of Outputs for SubSystem: '<S71>/If Action Subsystem' */
    } else {
      /* Outputs for IfAction SubSystem: '<S71>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S82>/Action Port'
       */
      if (DOV_ApprovalTimer > DOV_TimerMax) {
        /* Saturate: '<S82>/Saturation' */
        rtb_Switch1_k = DOV_TimerMax;
      } else if (DOV_ApprovalTimer < 1) {
        /* Saturate: '<S82>/Saturation' */
        rtb_Switch1_k = 1U;
      } else {
        /* Saturate: '<S82>/Saturation' incorporates:
         *  DataStoreRead: '<S82>/DOV_ApprovalTimer_0'
         */
        rtb_Switch1_k = DOV_ApprovalTimer;
      }

      /* Sum: '<S82>/Add' incorporates:
       *  Constant: '<S82>/Constant'
       *  DataStoreRead: '<S82>/DOV_ApprovalTimer_0'
       *  DataStoreWrite: '<S82>/DOV_ApprovalTimer'
       *  DataTypeConversion: '<S82>/Data Type Conversion'
       *  Saturate: '<S82>/Saturation'
       */
      DOV_ApprovalTimer = (uint8_T)(rtb_Switch1_k - 1);

      /* End of Outputs for SubSystem: '<S71>/If Action Subsystem1' */
    }

    /* End of If: '<S71>/If' */
    /* End of Outputs for SubSystem: '<S3>/Subsystem' */

    /* If: '<S3>/If' incorporates:
     *  Inport: '<S17>/VLC_Mode_In'
     */
    rtPrevAction = rtDW.If_ActiveSubsystem;

    /* Outputs for Atomic SubSystem: '<S3>/Subsystem' */
    rtAction = (int8_T)(rtDW.VLC_Mode_n <= 2);

    /* End of Outputs for SubSystem: '<S3>/Subsystem' */
    rtDW.If_ActiveSubsystem = rtAction;
    if ((rtPrevAction != rtAction) && (rtPrevAction == 0)) {
      /* Disable for Atomic SubSystem: '<S15>/VLC_BL0.0.1' */
      /* Disable for If: '<S49>/If' */
      rtDW.If_ActiveSubsystem_j = -1;

      /* End of Disable for SubSystem: '<S15>/VLC_BL0.0.1' */
    }

    if (rtAction == 0) {
      /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem1' incorporates:
       *  ActionPort: '<S15>/Action Port'
       */
      /* Outputs for Atomic SubSystem: '<S15>/VLC_BL0.0.1' */
      /* DataStoreWrite: '<S49>/MotFlag' incorporates:
       *  DataStoreRead: '<S15>/Data Store Read1'
       */
      MotFlag = VLC_Available;

      /* If: '<S49>/If' incorporates:
       *  Constant: '<S50>/Constant'
       *  Constant: '<S52>/dbg2EngineModel'
       *  DataStoreRead: '<S15>/Data Store Read1'
       *  DataStoreRead: '<S49>/Data Store Read'
       *  Logic: '<S49>/Logical Operator'
       *  RelationalOperator: '<S50>/Compare'
       *  Switch: '<S52>/Switch1'
       */
      rtPrevAction = rtDW.If_ActiveSubsystem_j;
      rtAction = (int8_T)((VLC_Available == 0) || (VLC_Mode != 4));
      rtDW.If_ActiveSubsystem_j = rtAction;
      if (rtAction == 0) {
        if (0 != rtPrevAction) {
          /* SystemReset for IfAction SubSystem: '<S49>/VLC_Active' incorporates:
           *  ActionPort: '<S51>/Action Port'
           */
          /* SystemReset for Atomic SubSystem: '<S51>/BoostController1' */
          /* SystemReset for Atomic SubSystem: '<S53>/Torque_request_subsystem1' */
          /* SystemReset for Atomic SubSystem: '<S57>/CLBC_PI_2.0' */
          /* SystemReset for Atomic SubSystem: '<S59>/LinearGradeControl' */
          /* SystemReset for If: '<S49>/If' incorporates:
           *  Delay: '<S61>/Delay1'
           *  Delay: '<S67>/Delay'
           *  Delay: '<S67>/Delay1'
           *  Delay: '<S67>/Delay2'
           *  UnitDelay: '<S60>/Unit Delay'
           */
          rtDW.icLoad_nu = 1U;

          /* End of SystemReset for SubSystem: '<S59>/LinearGradeControl' */

          /* SystemReset for Atomic SubSystem: '<S63>/Protection timer' */
          rtDW.Delay_DSTATE_jl = 0U;
          rtDW.icLoad_kt = 1U;
          rtDW.Delay2_DSTATE_f = 0.0F;

          /* End of SystemReset for SubSystem: '<S63>/Protection timer' */

          /* SystemReset for Atomic SubSystem: '<S59>/Integrator_v02' */
          rtDW.UnitDelay_DSTATE_c = 0;

          /* End of SystemReset for SubSystem: '<S59>/Integrator_v02' */
          /* End of SystemReset for SubSystem: '<S57>/CLBC_PI_2.0' */
          /* End of SystemReset for SubSystem: '<S53>/Torque_request_subsystem1' */
          /* End of SystemReset for SubSystem: '<S51>/BoostController1' */
          /* End of SystemReset for SubSystem: '<S49>/VLC_Active' */
        }

        /* Outputs for IfAction SubSystem: '<S49>/VLC_Active' incorporates:
         *  ActionPort: '<S51>/Action Port'
         */
        /* Outputs for Atomic SubSystem: '<S51>/BoostController1' */
        /* Outputs for Atomic SubSystem: '<S53>/DirectAX' */
        /* Switch: '<S55>/Switch' incorporates:
         *  Constant: '<S55>/speedVariant'
         *  DataStoreRead: '<S51>/jerkAcceleration'
         *  DataStoreRead: '<S55>/refSpeed1'
         *  Sum: '<S55>/Subtract1'
         */
        if (speedVariant > 0) {
          /* Sum: '<S55>/Subtract1' incorporates:
           *  DataStoreRead: '<S55>/refSpeed'
           */
          tmp_1 = refSpeed * 25ULL;
          rtb_DataTypeConversion_j = (int16_T)((int32_T)(((tmp_1 & 65536ULL) !=
            0ULL) + (tmp_1 >> 17)) - targetSpeed);
        } else {
          rtb_DataTypeConversion_j = (int16_T)((jerkAcceleration * 25) >> 7);
        }

        /* End of Switch: '<S55>/Switch' */

        /* Abs: '<S55>/Abs' */
        if (rtb_DataTypeConversion_j < 0) {
          rtb_DataTypeConversion_j = (int16_T)-rtb_DataTypeConversion_j;
        }

        /* End of Abs: '<S55>/Abs' */

        /* Lookup_n-D: '<S55>/Bost_map1' */
        rtb_DataTypeConversion_j = look1_is16lu32n32Ds32_linlcas
          (rtb_DataTypeConversion_j, (&(SP_I_ACC_MAP[0])), (&(SP_I_MAX_MAP[0])),
           4U);

        /* End of Outputs for SubSystem: '<S53>/DirectAX' */

        /* Switch: '<S53>/Switch' incorporates:
         *  Constant: '<S54>/Constant'
         *  DataStoreRead: '<S51>/jerkAcceleration'
         *  DataStoreRead: '<S53>/Clutched_Status'
         *  DataStoreRead: '<S53>/estAX'
         *  RelationalOperator: '<S54>/Compare'
         */
        if (Clutched_Status == 0) {
          u0 = (real32_T)jerkAcceleration * 0.001953125F;
        } else {
          u0 = estAX;
        }

        /* End of Switch: '<S53>/Switch' */

        /* Outputs for Atomic SubSystem: '<S53>/DirectAX' */
        /* Product: '<S55>/Product2' incorporates:
         *  Constant: '<S55>/Constant'
         *  DataStoreRead: '<S51>/jerkAcceleration'
         *  DataStoreRead: '<S55>/Ga_OLBC'
         *  Gain: '<S55>/Gain'
         *  Gain: '<S55>/Gain1'
         *  Lookup_n-D: '<S55>/Bost_map2'
         *  Product: '<S55>/Divide'
         *  Product: '<S55>/Product'
         *  Product: '<S55>/Product1'
         *  Sum: '<S55>/Subtract'
         *  Sum: '<S55>/Subtract2'
         */
        rtb_Divide6 = (real32_T)(int16_T)rt_roundf_snf(((real32_T)
          jerkAcceleration * 0.001953125F - u0) * 10.0F) * 0.1F * (0.10193634F *
          (real32_T)Ga_OLBC) * rtb_Gain6 / rtb_Saturation_pc *
          look1_iu16lftf_linlca(rtb_DataTypeConversion_ai,
          (&(FreeRollingResistanceBP[0])), (&(directAX_P[0])), 15U) * (1.0F -
          (real32_T)rtb_DataTypeConversion_j * 0.01F);

        /* Saturate: '<S55>/Saturation' */
        if (rtb_Divide6 > 500.0F) {
          rtb_Divide6 = 500.0F;
        } else {
          if (rtb_Divide6 < -500.0F) {
            rtb_Divide6 = -500.0F;
          }
        }

        /* End of Saturate: '<S55>/Saturation' */

        /* DataTypeConversion: '<S55>/Data Type Conversion' incorporates:
         *  DataStoreWrite: '<S55>/M_MotClutch_DirAx'
         */
        M_MotClutch_DirAx = (int32_T)rt_roundf_snf(rtb_Divide6);

        /* End of Outputs for SubSystem: '<S53>/DirectAX' */

        /* Outputs for Atomic SubSystem: '<S53>/Torque_request_subsystem1' */
        /* Outputs for Atomic SubSystem: '<S57>/CLBC_Flaw1' */
        /* Sum: '<S58>/Subtract' incorporates:
         *  DataStoreRead: '<S58>/refSpeed'
         */
        tmp_1 = refSpeed * 25ULL;
        rtb_DataTypeConversion_j = (int16_T)((int16_T)(((tmp_1 & 65536ULL) !=
          0ULL) + (tmp_1 >> 17)) - (int16_T)rtb_DataTypeConversion_ai);

        /* End of Outputs for SubSystem: '<S57>/CLBC_Flaw1' */

        /* Outputs for Atomic SubSystem: '<S57>/CLBC_PI_2.0' */
        /* Outputs for Atomic SubSystem: '<S1>/Input Processing1' */
        /* Saturate: '<S59>/Saturation' incorporates:
         *  DataStoreRead: '<S1>/numGearEngaged'
         *  SignalConversion: '<S4>/TmpSignal ConversionAtData Type Conversion6Inport1'
         */
        if (GearEngNum > 9) {
          rtb_Switch1_k = 9U;
        } else if (GearEngNum < 1) {
          rtb_Switch1_k = 1U;
        } else {
          rtb_Switch1_k = GearEngNum;
        }

        /* End of Saturate: '<S59>/Saturation' */
        /* End of Outputs for SubSystem: '<S1>/Input Processing1' */

        /* DataTypeConversion: '<S59>/Data Type Conversion2' */
        rtb_Switch_e = (int16_T)(rtb_Switch1_k * 100U);

        /* Saturate: '<S59>/Saturation7' */
        if (rtb_DataTypeConversion_ai < 3333) {
          rtb_Switch1_hj = rtb_DataTypeConversion_ai;
        } else {
          rtb_Switch1_hj = 3333U;
        }

        /* End of Saturate: '<S59>/Saturation7' */

        /* Lookup_n-D: '<S59>/VehicleSpeed_SlopeGrad' */
        rtb_Switch1_hj = look1_iu16lu64n48_plinlcase(rtb_Switch1_hj,
          (&(VehicleSpeed_BKPGradBP[0])), (&(VehicleSpeed_BKPGradTD[0])),
          &rtDW.m_bpIndex_o, 7U);

        /* Gain: '<S59>/Gain6' */
        rtb_Add3_ag = (real32_T)rtb_Switch1_hj * 0.01F * 0.01F;

        /* Saturate: '<S59>/Saturation1' */
        if (rtb_DataTypeConversion_j > 1000) {
          rtb_Saturation_o = 1000;
        } else if (rtb_DataTypeConversion_j < -1000) {
          rtb_Saturation_o = -1000;
        } else {
          rtb_Saturation_o = rtb_DataTypeConversion_j;
        }

        /* End of Saturate: '<S59>/Saturation1' */

        /* Outputs for Atomic SubSystem: '<S59>/LinearGradeControl' */
        /* Delay: '<S61>/Delay1' incorporates:
         *  DataTypeConversion: '<S61>/Data Type Conversion1'
         */
        if (rtDW.icLoad_nu != 0) {
          rtDW.Delay1_DSTATE_j = (real32_T)rtb_Saturation_o * 0.01F;
        }

        /* Sum: '<S61>/Subtract' incorporates:
         *  DataTypeConversion: '<S61>/Data Type Conversion1'
         *  Delay: '<S61>/Delay1'
         */
        rtb_Saturation_pc = (real32_T)rtb_Saturation_o * 0.01F -
          rtDW.Delay1_DSTATE_j;

        /* Switch: '<S61>/Switch' incorporates:
         *  RelationalOperator: '<S61>/Relational Operator'
         */
        if (!(rtb_Add3_ag < rtb_Saturation_pc)) {
          /* Gain: '<S59>/Gain5' */
          rtb_Add3_ag = -rtb_Add3_ag;

          /* Switch: '<S61>/Switch1' incorporates:
           *  RelationalOperator: '<S61>/Relational Operator1'
           */
          if (rtb_Saturation_pc > rtb_Add3_ag) {
            rtb_Add3_ag = rtb_Saturation_pc;
          }

          /* End of Switch: '<S61>/Switch1' */
        }

        /* End of Switch: '<S61>/Switch' */

        /* Sum: '<S61>/Add' incorporates:
         *  Delay: '<S61>/Delay1'
         */
        rtb_Saturation_pc = rtb_Add3_ag + rtDW.Delay1_DSTATE_j;

        /* DataTypeConversion: '<S61>/Data Type Conversion' */
        rtb_DataTypeConversion_j = (int16_T)rt_roundf_snf(rtb_Saturation_pc *
          100.0F);

        /* Update for Delay: '<S61>/Delay1' */
        rtDW.icLoad_nu = 0U;
        rtDW.Delay1_DSTATE_j = rtb_Saturation_pc;

        /* End of Outputs for SubSystem: '<S59>/LinearGradeControl' */

        /* Saturate: '<S59>/Saturation4' incorporates:
         *  Constant: '<S59>/boostCalibration1'
         */
        if (bkp_cal_coef > 600) {
          rtb_Abs_g = 600;
        } else if (bkp_cal_coef < 0) {
          rtb_Abs_g = 0;
        } else {
          rtb_Abs_g = bkp_cal_coef;
        }

        /* End of Saturate: '<S59>/Saturation4' */

        /* Product: '<S59>/Product' incorporates:
         *  Lookup_n-D: '<S59>/Boost_map'
         */
        rtb_Saturation2 = look1_is16lu32n32Ds32_linlcas(rtb_Switch_e, (&(Gb_MAP
          [0])), (&(B_MAP[0])), 8U) * rtb_Abs_g;
        rtb_Saturation2 = (int16_T)((((rtb_Saturation2 & 512U) != 0U) &&
          (((rtb_Saturation2 & 511U) != 0U) || (rtb_Saturation2 > 0))) +
          (rtb_Saturation2 >> 10)) * 16777;

        /* Product: '<S59>/Product2' incorporates:
         *  Lookup_n-D: '<S59>/FlawSignMap'
         *  Product: '<S59>/Product'
         */
        rtb_Saturation2 = (int16_T)((((rtb_Saturation2 & 8192U) != 0U) &&
          (((rtb_Saturation2 & 8191U) != 0U) || (rtb_Saturation2 > 0))) +
          (rtb_Saturation2 >> 14)) * look1_is16lu32n32Ds32_linlcas
          (rtb_DataTypeConversion_j, (&(bkpf[0])), (&(bkpt[0])), 9U);
        rtb_Saturation2 = (int16_T)((((rtb_Saturation2 & 64U) != 0U) &&
          (((rtb_Saturation2 & 63U) != 0U) || (rtb_Saturation2 > 0))) +
          (rtb_Saturation2 >> 7)) * 5243;
        rtb_Abs1 = (int16_T)((((rtb_Saturation2 & 2048U) != 0U) &&
                              (((rtb_Saturation2 & 2047U) != 0U) ||
          (rtb_Saturation2 > 0))) + (rtb_Saturation2 >> 12));

        /* Saturate: '<S59>/Saturation6' */
        if (rtb_Abs1 > 18000) {
          rtb_Abs1 = 18000;
        } else {
          if (rtb_Abs1 < -18000) {
            rtb_Abs1 = -18000;
          }
        }

        /* End of Saturate: '<S59>/Saturation6' */

        /* Gain: '<S63>/Gain' incorporates:
         *  Abs: '<S63>/Abs'
         *  DataStoreRead: '<S59>/AngleEstimation_fin'
         *  DataStoreWrite: '<S63>/SlopeForPID'
         */
        SlopeForPID = (uint32_T)rt_roundf_snf(10.0F * (real32_T)fabs(AngEstimate));

        /* Lookup_n-D: '<S63>/Slope_BKP_Gain1' incorporates:
         *  DataStoreWrite: '<S63>/SlopeCoef'
         *  DataStoreWrite: '<S63>/SlopeForPID'
         *  DataTypeConversion: '<S63>/Data Type Conversion'
         */
        rtb_DataTypeConversion_hs = plook_u32f_linckpa((real32_T)SlopeForPID,
          (&(Slope_BP[0])), 9U, &rtDW.m_bpIndex_g);
        SlopeCoef = Slope_KI_Gain[rtb_DataTypeConversion_hs];

        /* Lookup_n-D: '<S63>/VehicleSpeed_SlopeGrad1' */
        rtb_Switch1_hj = look1_iu16lu64n48_plinlcase(rtb_DataTypeConversion_ai,
          rtConstP.VehicleSpeed_SlopeGrad1_bp01Dat,
          rtConstP.VehicleSpeed_SlopeGrad1_tableDa, &rtDW.m_bpIndex_g5, 6U);

        /* DataTypeConversion: '<S63>/Data Type Conversion4' */
        rtb_DataTypeConversion_hs = rtb_Switch1_hj * 41943U;
        rtb_Switch1_k = (uint8_T)(((rtb_DataTypeConversion_hs & 2097152U) != 0U)
          + (rtb_DataTypeConversion_hs >> 22));

        /* Outputs for Atomic SubSystem: '<S63>/Protection timer' */
        /* Delay: '<S67>/Delay1' incorporates:
         *  DataStoreWrite: '<S63>/SlopeCoef'
         */
        if (rtDW.icLoad_kt != 0) {
          rtDW.Delay1_DSTATE_e = SlopeCoef;
        }

        /* Switch: '<S67>/Switch1' incorporates:
         *  Constant: '<S67>/Constant2'
         *  DataStoreWrite: '<S63>/SlopeCoef'
         *  Delay: '<S67>/Delay1'
         *  RelationalOperator: '<S67>/Relational Operator2'
         */
        if (SlopeCoef == rtDW.Delay1_DSTATE_e) {
          /* Switch: '<S67>/Switch2' incorporates:
           *  Constant: '<S67>/Constant1'
           *  Delay: '<S67>/Delay'
           *  RelationalOperator: '<S67>/Relational Operator1'
           *  Sum: '<S67>/Add'
           */
          if (rtDW.Delay_DSTATE_jl < rtb_Switch1_k) {
            rtb_Switch1_fs = (uint8_T)(rtDW.Delay_DSTATE_jl + 1U);
          } else {
            rtb_Switch1_fs = rtb_Switch1_k;
          }

          /* End of Switch: '<S67>/Switch2' */
        } else {
          rtb_Switch1_fs = 0U;
        }

        /* End of Switch: '<S67>/Switch1' */

        /* Switch: '<S67>/Switch' incorporates:
         *  DataStoreWrite: '<S63>/SlopeCoef'
         *  DataStoreWrite: '<S63>/SlopeCoefProt'
         *  Delay: '<S67>/Delay2'
         *  RelationalOperator: '<S67>/Relational Operator'
         */
        if (rtb_Switch1_fs == rtb_Switch1_k) {
          SlopeCoefProt = SlopeCoef;
        } else {
          SlopeCoefProt = rtDW.Delay2_DSTATE_f;
        }

        /* End of Switch: '<S67>/Switch' */

        /* Update for Delay: '<S67>/Delay' */
        rtDW.Delay_DSTATE_jl = rtb_Switch1_fs;

        /* Update for Delay: '<S67>/Delay1' incorporates:
         *  DataStoreWrite: '<S63>/SlopeCoef'
         */
        rtDW.icLoad_kt = 0U;
        rtDW.Delay1_DSTATE_e = SlopeCoef;

        /* Update for Delay: '<S67>/Delay2' incorporates:
         *  DataStoreWrite: '<S63>/SlopeCoefProt'
         */
        rtDW.Delay2_DSTATE_f = SlopeCoefProt;

        /* End of Outputs for SubSystem: '<S63>/Protection timer' */

        /* Product: '<S59>/Product1' incorporates:
         *  Constant: '<S59>/boostCalibration'
         *  Lookup_n-D: '<S59>/JerkMAP'
         */
        rtb_Saturation2 = look2_is16lu32n32Ds32d_VMYn7zgN(rtb_Switch_e,
          boostCalibration, (&(Gb_MAP[0])), (&(JerMAP[0])), (&(JerFcn[0])),
          rtConstP.JerkMAP_maxIndex, 9U) * rtb_Abs1;
        rtb_Saturation2 = (int16_T)((((rtb_Saturation2 & 64U) != 0U) &&
          (((rtb_Saturation2 & 63U) != 0U) || (rtb_Saturation2 > 0))) +
          (rtb_Saturation2 >> 7)) * 5243;

        /* Product: '<S59>/Divide4' incorporates:
         *  Constant: '<S59>/Slope_KP_Gain'
         *  DataStoreWrite: '<S63>/SlopeCoefProt'
         *  Product: '<S59>/Product1'
         *  Product: '<S59>/Product3'
         */
        rtb_Saturation2 = (int16_T)((((rtb_Saturation2 & 2048U) != 0U) &&
          (((rtb_Saturation2 & 2047U) != 0U) || (rtb_Saturation2 > 0))) +
          (rtb_Saturation2 >> 12)) * rtb_DataTypeConversion_j;
        rtb_Saturation2 = (int16_T)rt_roundf_snf((real32_T)(int16_T)
          ((((rtb_Saturation2 & 1024U) != 0U) && (((rtb_Saturation2 & 1023U) !=
          0U) || (rtb_Saturation2 > 0))) + (rtb_Saturation2 >> 11)) *
          (Slope_KP_Gain * SlopeCoefProt)) * 16777;
        rtb_Abs_g = (int16_T)((((rtb_Saturation2 & 4096U) != 0U) &&
          (((rtb_Saturation2 & 4095U) != 0U) || (rtb_Saturation2 > 0))) +
                              (rtb_Saturation2 >> 13));

        /* Saturate: '<S59>/Saturation2' */
        if (rtb_Abs_g > 1000) {
          trqP_PID = 1000;
        } else if (rtb_Abs_g < -1000) {
          trqP_PID = -1000;
        } else {
          trqP_PID = rtb_Abs_g;
        }

        /* End of Saturate: '<S59>/Saturation2' */

        /* Lookup_n-D: '<S59>/SpeedControllerLT' */
        rtb_Switch_e = look1_is16lu32n32Ds32_linlcas(rtb_Switch_e, (&(Gb_MAP[0])),
          (&(I_boost[0])), 8U);

        /* MultiPortSwitch: '<S59>/Multiport Switch2' incorporates:
         *  DataStoreRead: '<S59>/Data Store Read6'
         */
        if (VLC_Available == 0) {
          rtb_Saturation_o = (int16_T)tmp_2;
        }

        /* Outputs for Atomic SubSystem: '<S59>/Integrator_v02' */
        /* Switch: '<S60>/Switch' incorporates:
         *  Constant: '<S60>/speedVariant'
         *  DataStoreRead: '<S51>/jerkAcceleration'
         *  DataStoreRead: '<S51>/targetSpeed'
         *  Sum: '<S60>/Subtract'
         */
        if (speedVariant > 0) {
          /* Sum: '<S60>/Subtract' incorporates:
           *  DataStoreRead: '<S60>/refSpeed'
           */
          tmp_1 = refSpeed * 25ULL;
          rtb_DataTypeConversion_j = (int16_T)((int32_T)(((tmp_1 & 65536ULL) !=
            0ULL) + (tmp_1 >> 17)) - targetSpeed);
        } else {
          rtb_DataTypeConversion_j = (int16_T)((jerkAcceleration * 25) >> 7);
        }

        /* End of Switch: '<S60>/Switch' */

        /* Abs: '<S60>/Abs' */
        if (rtb_DataTypeConversion_j < 0) {
          rtb_DataTypeConversion_j = (int16_T)-rtb_DataTypeConversion_j;
        }

        /* End of Abs: '<S60>/Abs' */

        /* Saturate: '<S60>/Saturation1' */
        if (rtb_Saturation_o > 500) {
          rtb_Saturation_o = 500;
        } else {
          if (rtb_Saturation_o < -500) {
            rtb_Saturation_o = -500;
          }
        }

        /* End of Saturate: '<S60>/Saturation1' */

        /* Product: '<S60>/Divide2' incorporates:
         *  Constant: '<S60>/Constant1'
         *  Sum: '<S60>/Add1'
         *  UnitDelay: '<S60>/Unit Delay'
         */
        rtb_Saturation2 = (int16_T)((rtb_Saturation_o << 1) + (int16_T)
          (rtDW.UnitDelay_DSTATE_c << 1)) * S_pidC_h;
        rtb_Saturation2 = (int16_T)((((rtb_Saturation2 & 256U) != 0U) &&
          (((rtb_Saturation2 & 255U) != 0U) || (rtb_Saturation2 > 0))) +
          (rtb_Saturation2 >> 9)) * 5243;

        /* Sum: '<S60>/Add2' incorporates:
         *  Constant: '<S60>/Constant3'
         *  DataStoreRead: '<S60>/Data Store Read'
         *  DataTypeConversion: '<S60>/Data Type Conversion4'
         *  Product: '<S60>/Divide1'
         *  Product: '<S60>/Divide2'
         */
        rtb_Abs1 = (int16_T)((int16_T)div_nzp_s32_round((int16_T)
          ((((rtb_Saturation2 & 2048U) != 0U) && (((rtb_Saturation2 & 2047U) !=
          0U) || (rtb_Saturation2 > 0))) + (rtb_Saturation2 >> 12)) << 1,
          (int16_T)c_2) + resultOfIntPID);

        /* Lookup_n-D: '<S60>/Bost_map1' */
        rtb_DataTypeConversion_j = look1_is16lu32n32Ds32_linlcas
          (rtb_DataTypeConversion_j, (&(SP_I_ACC_MAP[0])), (&(SP_I_MAX_MAP[0])),
           4U);

        /* Switch: '<S64>/Switch2' incorporates:
         *  RelationalOperator: '<S64>/LowerRelop1'
         */
        if (rtb_Abs1 * 5243 > ((int64_T)rtb_DataTypeConversion_j << 19)) {
          rtb_Abs1 = (int16_T)(rtb_DataTypeConversion_j * 100);
        } else {
          /* Product: '<S60>/Product' incorporates:
           *  Constant: '<S60>/Constant'
           */
          rtb_Saturation2 = rtb_DataTypeConversion_j * c_n_1;
          rtb_Saturation2 = (int16_T)((((rtb_Saturation2 & 8U) != 0U) &&
            (((rtb_Saturation2 & 7U) != 0U) || (rtb_Saturation2 > 0))) +
            (rtb_Saturation2 >> 4)) * 13107;
          rtb_DataTypeConversion_j = (int16_T)((((rtb_Saturation2 & 4096U) != 0U)
            && (((rtb_Saturation2 & 4095U) != 0U) || (rtb_Saturation2 > 0))) +
            (rtb_Saturation2 >> 13));

          /* Switch: '<S64>/Switch' incorporates:
           *  RelationalOperator: '<S64>/UpperRelop'
           */
          if (rtb_Abs1 * 16777 < ((int64_T)rtb_DataTypeConversion_j << 24)) {
            rtb_Abs1 = (int16_T)(rtb_DataTypeConversion_j * 1000);
          }

          /* End of Switch: '<S64>/Switch' */
        }

        /* End of Switch: '<S64>/Switch2' */

        /* Update for UnitDelay: '<S60>/Unit Delay' */
        rtDW.UnitDelay_DSTATE_c = rtb_Saturation_o;

        /* End of Outputs for SubSystem: '<S59>/Integrator_v02' */

        /* Saturate: '<S59>/Saturation5' incorporates:
         *  Constant: '<S59>/boostCalibration2'
         */
        if (speedCalibration > 500) {
          rtb_Abs_g = 500;
        } else if (speedCalibration < 0) {
          rtb_Abs_g = 0;
        } else {
          rtb_Abs_g = speedCalibration;
        }

        /* End of Saturate: '<S59>/Saturation5' */

        /* Product: '<S59>/Divide' incorporates:
         *  DataStoreWrite: '<S63>/SlopeCoefProt'
         */
        rtb_Saturation2 = (int16_T)rt_roundf_snf((real32_T)rtb_Switch_e *
          0.0078125F * SlopeCoefProt * 16.0F) * rtb_Abs_g;
        rtb_Saturation2 = (int16_T)((((rtb_Saturation2 & 64U) != 0U) &&
          (((rtb_Saturation2 & 63U) != 0U) || (rtb_Saturation2 > 0))) +
          (rtb_Saturation2 >> 7)) * 16777;

        /* Product: '<S59>/Divide1' incorporates:
         *  Product: '<S59>/Divide'
         */
        rtb_Saturation2 = (int16_T)((((rtb_Saturation2 & 8192U) != 0U) &&
          (((rtb_Saturation2 & 8191U) != 0U) || (rtb_Saturation2 > 0))) +
          (rtb_Saturation2 >> 14)) * rtb_Abs1;
        rtb_Saturation2 = ((((rtb_Saturation2 & 65536U) != 0U) &&
                            (((rtb_Saturation2 & 65535U) != 0U) ||
                             (rtb_Saturation2 > 0))) + (rtb_Saturation2 >> 17)) *
          21475;

        /* Saturate: '<S59>/Saturation3' incorporates:
         *  Product: '<S59>/Divide1'
         */
        rtb_Abs_g = (int16_T)((((rtb_Saturation2 & 8192U) != 0U) &&
          (((rtb_Saturation2 & 8191U) != 0U) || (rtb_Saturation2 > 0))) +
                              (rtb_Saturation2 >> 14));
        if (rtb_Abs_g > 1000) {
          trqI_PID = 1000;
        } else if (rtb_Abs_g < -1000) {
          trqI_PID = -1000;
        } else {
          trqI_PID = rtb_Abs_g;
        }

        /* End of Saturate: '<S59>/Saturation3' */

        /* Sum: '<S59>/Add' incorporates:
         *  DataStoreWrite: '<S59>/trqI_PID_in'
         *  DataStoreWrite: '<S59>/trqP_PID'
         */
        rtb_Switch_e = (int16_T)(trqP_PID + trqI_PID);

        /* Outputs for Atomic SubSystem: '<S59>/Subsystem' */
        /* Saturate: '<S62>/Saturation' incorporates:
         *  DataStoreRead: '<S62>/numGearEngaged'
         */
        if (numGearEngaged_vlc > 9) {
          rtb_Switch1_k = 9U;
        } else if (numGearEngaged_vlc < 1) {
          rtb_Switch1_k = 1U;
        } else {
          rtb_Switch1_k = numGearEngaged_vlc;
        }

        /* End of Saturate: '<S62>/Saturation' */

        /* Lookup_n-D: '<S62>/trqLimits1' incorporates:
         *  DataTypeConversion: '<S62>/Data Type Conversion4'
         */
        rtb_DataTypeConversion_j = look1_is16lu32n32Ds32_linlcas(rtb_Switch1_k,
          (&(GearNumber[0])), (&(trqLimits_PI_Boost[0])), 8U);

        /* Switch: '<S62>/Switch_trqLimits1' incorporates:
         *  RelationalOperator: '<S62>/Relational_Operator_trqLimits1'
         */
        if (rtb_Switch_e > rtb_DataTypeConversion_j) {
          rtb_Switch_e = rtb_DataTypeConversion_j;
        }

        /* End of Switch: '<S62>/Switch_trqLimits1' */
        /* End of Outputs for SubSystem: '<S59>/Subsystem' */

        /* DataStoreWrite: '<S59>/M_MotClutch_PID_Boost_in' */
        M_MotClutch_PID_Boost = rtb_Switch_e;

        /* DataStoreWrite: '<S59>/trqI_PID_in1' */
        resultOfIntPID = rtb_Abs1;

        /* End of Outputs for SubSystem: '<S57>/CLBC_PI_2.0' */
        /* End of Outputs for SubSystem: '<S53>/Torque_request_subsystem1' */

        /* Outputs for Atomic SubSystem: '<S53>/Torque_request_subsystem' */
        /* Sum: '<S56>/Add1' incorporates:
         *  DataStoreRead: '<S56>/M_MotClutch_OLBC'
         */
        rtb_Abs_g = (int16_T)((int16_T)(M_MotClutch_OLBC + rtb_Switch_e) +
                              (int16_T)rt_roundf_snf(rtb_Divide6));

        /* Saturate: '<S56>/Saturation2' */
        if (rtb_Abs_g > 880) {
          rtb_DataTypeConversion_j = 880;
        } else if (rtb_Abs_g < -100) {
          rtb_DataTypeConversion_j = -100;
        } else {
          rtb_DataTypeConversion_j = rtb_Abs_g;
        }

        /* End of Saturate: '<S56>/Saturation2' */

        /* Saturate: '<S56>/Saturation' incorporates:
         *  DataStoreRead: '<S56>/numGearEngaged'
         */
        if (numGearEngaged_vlc > 9) {
          rtb_Switch1_k = 9U;
        } else if (numGearEngaged_vlc < 1) {
          rtb_Switch1_k = 1U;
        } else {
          rtb_Switch1_k = numGearEngaged_vlc;
        }

        /* End of Saturate: '<S56>/Saturation' */

        /* Lookup_n-D: '<S56>/trqLimits' incorporates:
         *  DataTypeConversion: '<S56>/Data Type Conversion1'
         */
        rtb_Switch_e = look1_is16lu32n32Ds32_linlcas(rtb_Switch1_k,
          (&(GearNumber[0])), (&(trqLimits[0])), 8U);

        /* Switch: '<S56>/Switch_trqLimits' incorporates:
         *  RelationalOperator: '<S56>/Relational_Operator_trqLimits'
         */
        if (rtb_DataTypeConversion_j > rtb_Switch_e) {
          rtb_DataTypeConversion_j = rtb_Switch_e;
        }

        /* End of Switch: '<S56>/Switch_trqLimits' */

        /* Lookup_n-D: '<S56>/engTrqLimits' incorporates:
         *  DataStoreRead: '<S56>/nICEngineSpeed1_vlc'
         */
        rtb_Switch_e = look1_iu16bs16lu32n32t_Ji2sqUY0(nICEngineSpeed_vlc,
          (&(rpm[0])), (&(engTrqLimits[0])), 12U);

        /* Switch: '<S56>/Switch_trqLimits1' incorporates:
         *  DataStoreWrite: '<S51>/VLC_TargetEngTorque1'
         *  RelationalOperator: '<S56>/Relational_Operator_trqLimits1'
         */
        if (rtb_DataTypeConversion_j <= rtb_Switch_e) {
          VLC_TargetEngTorque = rtb_DataTypeConversion_j;
        } else {
          VLC_TargetEngTorque = rtb_Switch_e;
        }

        /* End of Switch: '<S56>/Switch_trqLimits1' */
        /* End of Outputs for SubSystem: '<S53>/Torque_request_subsystem' */
        /* End of Outputs for SubSystem: '<S51>/BoostController1' */

        /* DataStoreWrite: '<S51>/ASRinRegulation' incorporates:
         *  Constant: '<S51>/c_1'
         */
        ASRinRegulation = 1U;

        /* End of Outputs for SubSystem: '<S49>/VLC_Active' */
      } else {
        /* Outputs for IfAction SubSystem: '<S49>/VLC_Inactive' incorporates:
         *  ActionPort: '<S52>/Action Port'
         */
        if (dbg2EngineModel > 0) {
          /* DataTypeConversion: '<S52>/Data Type Conversion9' incorporates:
           *  DataStoreRead: '<S52>/Data Store Read'
           *  Switch: '<S52>/Switch1'
           */
          rtb_Saturation2 = EngineInertiaTrq * 5243;

          /* Switch: '<S52>/Switch1' incorporates:
           *  DataTypeConversion: '<S52>/Data Type Conversion9'
           */
          rtb_Switch_e = (int16_T)((((rtb_Saturation2 & 262144U) != 0U) &&
            (((rtb_Saturation2 & 262143U) != 0U) || (rtb_Saturation2 > 0))) +
            (rtb_Saturation2 >> 19));
        } else {
          /* Switch: '<S52>/Switch1' incorporates:
           *  Constant: '<S52>/Constant1'
           */
          rtb_Switch_e = 0;
        }

        /* Sum: '<S52>/Add3' incorporates:
         *  DataStoreWrite: '<S52>/VLC_TargetEngTorque'
         */
        VLC_TargetEngTorque = (int16_T)(rtb_EngineTorque + rtb_Switch_e);

        /* DataTypeConversion: '<S52>/Data Type Conversion8' incorporates:
         *  Constant: '<S52>/C_0'
         *  DataStoreWrite: '<S52>/ASRinRegulation'
         */
        ASRinRegulation = 0U;

        /* DataTypeConversion: '<S52>/Data Type Conversion3' incorporates:
         *  Constant: '<S52>/C_0'
         *  DataStoreWrite: '<S52>/M_MotClutch_DirAx'
         */
        M_MotClutch_DirAx = 0;

        /* DataTypeConversion: '<S52>/Data Type Conversion5' incorporates:
         *  Constant: '<S52>/C_0'
         *  DataStoreWrite: '<S52>/M_MotClutch_PID_Speed1'
         */
        M_MotClutch_PID_Boost = 0;

        /* DataTypeConversion: '<S52>/Data Type Conversion21' incorporates:
         *  Constant: '<S52>/C_0'
         *  DataStoreWrite: '<S52>/bPID_int'
         */
        bPID_int = 0;

        /* DataTypeConversion: '<S52>/Data Type Conversion7' incorporates:
         *  Constant: '<S52>/C_0'
         *  DataStoreWrite: '<S52>/resultOfIntPID'
         */
        resultOfIntPID = 0;

        /* DataTypeConversion: '<S52>/Data Type Conversion1' incorporates:
         *  Constant: '<S52>/C_0'
         *  DataStoreWrite: '<S52>/targetSlipSt'
         */
        targetSlipSt = 0U;

        /* DataTypeConversion: '<S52>/Data Type Conversion6' incorporates:
         *  Constant: '<S52>/C_0'
         *  DataStoreWrite: '<S52>/trqI_PID'
         */
        trqI_PID = 0;

        /* DataTypeConversion: '<S52>/Data Type Conversion2' incorporates:
         *  Constant: '<S52>/C_0'
         *  DataStoreWrite: '<S52>/trqI_PID1'
         */
        trqP_PID = 0;

        /* End of Outputs for SubSystem: '<S49>/VLC_Inactive' */
      }

      /* End of Outputs for SubSystem: '<S15>/VLC_BL0.0.1' */
      /* End of Outputs for SubSystem: '<S3>/If Action Subsystem1' */
    } else {
      /* Outputs for IfAction SubSystem: '<S3>/If Action Subsystem' incorporates:
       *  ActionPort: '<S14>/Action Port'
       */
      /* DataTypeConversion: '<S14>/Data Type Conversion3' incorporates:
       *  Constant: '<S14>/C_0'
       *  DataStoreWrite: '<S14>/M_MotClutch_DirAx'
       */
      M_MotClutch_DirAx = 0;

      /* DataTypeConversion: '<S14>/Data Type Conversion5' incorporates:
       *  Constant: '<S14>/C_0'
       *  DataStoreWrite: '<S14>/M_MotClutch_PID_Speed1'
       */
      M_MotClutch_PID_Boost = 0;

      /* DataTypeConversion: '<S14>/Data Type Conversion21' incorporates:
       *  Constant: '<S14>/C_0'
       *  DataStoreWrite: '<S14>/bPID_int'
       */
      bPID_int = 0;

      /* DataTypeConversion: '<S14>/Data Type Conversion7' incorporates:
       *  Constant: '<S14>/C_0'
       *  DataStoreWrite: '<S14>/resultOfIntPID'
       */
      resultOfIntPID = 0;

      /* DataTypeConversion: '<S14>/Data Type Conversion1' incorporates:
       *  Constant: '<S14>/C_0'
       *  DataStoreWrite: '<S14>/targetSlipSt'
       */
      targetSlipSt = 0U;

      /* DataTypeConversion: '<S14>/Data Type Conversion6' incorporates:
       *  Constant: '<S14>/C_0'
       *  DataStoreWrite: '<S14>/trqI_PID'
       */
      trqI_PID = 0;

      /* Outputs for Atomic SubSystem: '<S3>/Subsystem' */
      /* If: '<S14>/If' incorporates:
       *  Constant: '<S46>/Constant'
       *  RelationalOperator: '<S46>/Compare'
       */
      if (rtDW.VLC_Mode_n == 2) {
        /* Outputs for IfAction SubSystem: '<S14>/DriveOff' incorporates:
         *  ActionPort: '<S47>/Action Port'
         */
        /* DataStoreWrite: '<S47>/ASRinRegulation' incorporates:
         *  Constant: '<S47>/Constant'
         */
        ASRinRegulation = 1U;

        /* End of Outputs for SubSystem: '<S14>/DriveOff' */
      } else {
        /* Outputs for IfAction SubSystem: '<S14>/NoDriveOff' incorporates:
         *  ActionPort: '<S48>/Action Port'
         */
        /* DataTypeConversion: '<S48>/Data Type Conversion1' incorporates:
         *  Constant: '<S48>/Constant1'
         *  DataStoreWrite: '<S48>/ASRinRegulation'
         */
        ASRinRegulation = 0U;

        /* Switch: '<S48>/Switch1' incorporates:
         *  Constant: '<S48>/Constant1'
         *  Constant: '<S48>/dbg2EngineModel'
         *  DataTypeConversion: '<S48>/Data Type Conversion9'
         */
        if (dbg2EngineModel > 0) {
          /* DataTypeConversion: '<S48>/Data Type Conversion9' incorporates:
           *  DataStoreRead: '<S48>/Data Store Read'
           */
          rtb_Saturation2 = EngineInertiaTrq * 5243;
          rtb_Switch_e = (int16_T)((((rtb_Saturation2 & 262144U) != 0U) &&
            (((rtb_Saturation2 & 262143U) != 0U) || (rtb_Saturation2 > 0))) +
            (rtb_Saturation2 >> 19));
        } else {
          rtb_Switch_e = 0;
        }

        /* End of Switch: '<S48>/Switch1' */

        /* Sum: '<S48>/Add3' incorporates:
         *  DataStoreWrite: '<S48>/Data Store Write1'
         */
        VLC_TargetEngTorque = (int16_T)(rtb_EngineTorque + rtb_Switch_e);

        /* End of Outputs for SubSystem: '<S14>/NoDriveOff' */
      }

      /* End of If: '<S14>/If' */
      /* End of Outputs for SubSystem: '<S3>/Subsystem' */
      /* End of Outputs for SubSystem: '<S3>/If Action Subsystem' */
    }

    /* Outputs for Atomic SubSystem: '<S3>/DO SSR timer' */
    /* If: '<S13>/If' incorporates:
     *  DataStoreRead: '<S13>/StandStillRequest'
     *  DataStoreRead: '<S13>/reqDriveOff'
     *  Logic: '<S13>/Logical Operator'
     */
    if ((boolean_T)((DriveOffReq != 0) ^ (StandStillReq != 0))) {
      /* Outputs for IfAction SubSystem: '<S13>/START DO SSR trm' incorporates:
       *  ActionPort: '<S44>/Action Port'
       */
      /* Saturate: '<S44>/Saturation' incorporates:
       *  DataStoreRead: '<S44>/DO_SSR_err_tmr_in'
       */
      if (DO_SSR_err_tmr < 10000) {
        rtb_Switch1_hj = DO_SSR_err_tmr;
      } else {
        rtb_Switch1_hj = 10000U;
      }

      /* End of Saturate: '<S44>/Saturation' */

      /* Sum: '<S44>/uint16' incorporates:
       *  Constant: '<S44>/1'
       *  DataStoreWrite: '<S44>/DO_SSR_err_tmr_out'
       */
      DO_SSR_err_tmr = (uint16_T)((uint32_T)rtb_Switch1_hj + c_1);

      /* End of Outputs for SubSystem: '<S13>/START DO SSR trm' */
    } else {
      /* Outputs for IfAction SubSystem: '<S13>/ZERO DO SSR trm' incorporates:
       *  ActionPort: '<S45>/Action Port'
       */
      /* DataStoreWrite: '<S45>/DO_SSR_err_tmr_out' incorporates:
       *  Constant: '<S45>/0'
       */
      DO_SSR_err_tmr = c_0;

      /* End of Outputs for SubSystem: '<S13>/ZERO DO SSR trm' */
    }

    /* End of If: '<S13>/If' */
    /* End of Outputs for SubSystem: '<S3>/DO SSR timer' */

    /* Outputs for Atomic SubSystem: '<S3>/VehSpd timer' */
    /* RelationalOperator: '<S18>/Vtmr > max' incorporates:
     *  Constant: '<S18>/VehSpd_tmr_max'
     *  DataStoreRead: '<S18>/VehSpd_timer_in'
     *  DataStoreWrite: '<S18>/VehSpd_tmr_flg'
     */
    VehSpd_tmr_flg = (uint8_T)(VehSpd_timer >= VehSpd_tmr_max);

    /* If: '<S18>/If1' incorporates:
     *  Constant: '<S18>/Mode'
     *  DataStoreRead: '<S18>/VLC_Mode'
     *  DataStoreRead: '<S18>/VehicleSpeed'
     *  Logic: '<S18>/Logical Operator'
     *  RelationalOperator: '<S18>/M 4'
     *  RelationalOperator: '<S18>/V 0'
     */
    if ((VLC_Mode * 100U == 400U) && (VehicleSpeed_VLCInt == 0)) {
      /* Outputs for IfAction SubSystem: '<S18>/START V0 trm' incorporates:
       *  ActionPort: '<S96>/Action Port'
       */
      /* Saturate: '<S96>/Saturation' incorporates:
       *  DataStoreRead: '<S96>/VehSpd_timer_in'
       */
      if (VehSpd_timer < 10000) {
        rtb_Switch1_hj = VehSpd_timer;
      } else {
        rtb_Switch1_hj = 10000U;
      }

      /* End of Saturate: '<S96>/Saturation' */

      /* Sum: '<S96>/uint16' incorporates:
       *  Constant: '<S96>/1'
       *  DataStoreWrite: '<S96>/VehSpd_timer_out'
       */
      VehSpd_timer = (uint16_T)((uint32_T)rtb_Switch1_hj + c_1);

      /* End of Outputs for SubSystem: '<S18>/START V0 trm' */
    } else {
      /* Outputs for IfAction SubSystem: '<S18>/ZERO V0  trm' incorporates:
       *  ActionPort: '<S97>/Action Port'
       */
      /* DataStoreWrite: '<S97>/VehSpd_timer_out' incorporates:
       *  Constant: '<S97>/0'
       */
      VehSpd_timer = c_0;

      /* End of Outputs for SubSystem: '<S18>/ZERO V0  trm' */
    }

    /* End of If: '<S18>/If1' */
    /* End of Outputs for SubSystem: '<S3>/VehSpd timer' */

    /* Update for Delay: '<S100>/Delay' */
    rtDW.Delay_DSTATE_a = rtb_gsinalpha;

    /* End of Outputs for SubSystem: '<S1>/If Action Subsystem' */
  } else {
    /* Outputs for IfAction SubSystem: '<S1>/VLC_Inactive' incorporates:
     *  ActionPort: '<S9>/Action Port'
     */
    /* DataTypeConversion: '<S9>/Data Type Conversion' incorporates:
     *  DataStoreWrite: '<S9>/refSpeed'
     */
    tmp_2 = rtb_DataTypeConversion_ai * 41943U;
    refSpeed = ((tmp_2 & 4U) != 0U) + (tmp_2 >> 3);

    /* Switch: '<S9>/Switch1' incorporates:
     *  Constant: '<S9>/Constant1'
     *  Constant: '<S9>/dbg2EngineModel'
     *  DataTypeConversion: '<S9>/Data Type Conversion9'
     */
    if (dbg2EngineModel > 0) {
      /* DataTypeConversion: '<S9>/Data Type Conversion9' incorporates:
       *  DataStoreRead: '<S9>/Data Store Read'
       */
      rtb_Saturation2 = EngineInertiaTrq * 5243;
      rtb_Switch_e = (int16_T)((((rtb_Saturation2 & 262144U) != 0U) &&
        (((rtb_Saturation2 & 262143U) != 0U) || (rtb_Saturation2 > 0))) +
        (rtb_Saturation2 >> 19));
    } else {
      rtb_Switch_e = 0;
    }

    /* End of Switch: '<S9>/Switch1' */

    /* Sum: '<S9>/Add3' incorporates:
     *  DataStoreWrite: '<S9>/Data Store Write1'
     */
    VLC_TargetEngTorque = (int16_T)(rtb_EngineTorque + rtb_Switch_e);

    /* DataTypeConversion: '<S9>/Data Type Conversion29' incorporates:
     *  Constant: '<S9>/C_0'
     *  DataStoreWrite: '<S9>/ASRinRegulation'
     */
    ASRinRegulation = 0U;

    /* DataTypeConversion: '<S9>/Data Type Conversion1' incorporates:
     *  Constant: '<S9>/C_0'
     *  DataStoreWrite: '<S9>/Clutched_Status'
     */
    Clutched_Status = 0U;

    /* DataTypeConversion: '<S9>/Data Type Conversion7' incorporates:
     *  Constant: '<S9>/C_0'
     *  DataStoreWrite: '<S9>/DOV_ApprovalFlag'
     */
    BrakeReleaseReq = 0U;

    /* DataTypeConversion: '<S9>/Data Type Conversion6' incorporates:
     *  Constant: '<S9>/C_0'
     *  DataStoreWrite: '<S9>/DOV_ApprovalTimer'
     */
    DOV_ApprovalTimer = 0U;

    /* DataTypeConversion: '<S9>/Data Type Conversion5' incorporates:
     *  Constant: '<S9>/C_0'
     *  DataStoreWrite: '<S9>/DO_SSR_err_tmr'
     */
    DO_SSR_err_tmr = 0U;

    /* DataTypeConversion: '<S9>/Data Type Conversion30' incorporates:
     *  Constant: '<S9>/C_0'
     *  DataStoreWrite: '<S9>/FreeRollingDragForce_BC'
     */
    FreeRollingDragForce_BC = 0;

    /* DataStoreWrite: '<S9>/M_MotClutch_DirAx' incorporates:
     *  Constant: '<S9>/C_0'
     */
    M_MotClutch_DirAx = 0;

    /* DataTypeConversion: '<S9>/Data Type Conversion17' incorporates:
     *  Constant: '<S9>/C_0'
     *  DataStoreWrite: '<S9>/M_MotClutch_OLBC'
     */
    M_MotClutch_OLBC = 0;

    /* DataTypeConversion: '<S9>/Data Type Conversion26' incorporates:
     *  Constant: '<S9>/C_0'
     *  DataStoreWrite: '<S9>/M_MotClutch_PID_Speed2'
     */
    M_MotClutch_PID_Boost = 0;

    /* DataTypeConversion: '<S9>/Data Type Conversion22' incorporates:
     *  Constant: '<S9>/C_0'
     *  DataStoreWrite: '<S9>/M_MotClutch_WI'
     */
    M_MotClutch_WI = 0;

    /* DataTypeConversion: '<S9>/Data Type Conversion15' incorporates:
     *  Constant: '<S9>/C_0'
     *  DataStoreWrite: '<S9>/SlopeDragTorque'
     */
    SlopeDragTorque = 0;

    /* DataTypeConversion: '<S9>/Data Type Conversion2' incorporates:
     *  Constant: '<S9>/C_0'
     *  DataStoreWrite: '<S9>/TorqueRatioTmr'
     */
    TorqueRatioTmr = 0U;

    /* DataTypeConversion: '<S9>/Data Type Conversion3' incorporates:
     *  Constant: '<S9>/C_0'
     *  DataStoreWrite: '<S9>/VehSpd_timer'
     */
    VehSpd_timer = 0U;

    /* DataTypeConversion: '<S9>/Data Type Conversion24' incorporates:
     *  Constant: '<S9>/C_0'
     *  DataStoreWrite: '<S9>/bPID_int'
     */
    bPID_int = 0;

    /* DataTypeConversion: '<S9>/Data Type Conversion35' incorporates:
     *  Constant: '<S9>/C_0'
     *  DataStoreWrite: '<S9>/jerkAcceleration'
     */
    jerkAcceleration = 0;

    /* DataTypeConversion: '<S9>/Data Type Conversion32' incorporates:
     *  Constant: '<S9>/C_0'
     *  DataStoreWrite: '<S9>/reqAccelerationLimited'
     */
    reqAccelerationLimited = 0;

    /* DataTypeConversion: '<S9>/Data Type Conversion34' incorporates:
     *  Constant: '<S9>/C_0'
     *  DataStoreWrite: '<S9>/reqAccelerationMAX'
     */
    reqAccelerationMAX = 0;

    /* DataTypeConversion: '<S9>/Data Type Conversion33' incorporates:
     *  Constant: '<S9>/C_0'
     *  DataStoreWrite: '<S9>/reqAccelerationMIN'
     */
    reqAccelerationMIN = 0;

    /* DataTypeConversion: '<S9>/Data Type Conversion28' incorporates:
     *  Constant: '<S9>/C_0'
     *  DataStoreWrite: '<S9>/resultOfIntPID'
     */
    resultOfIntPID = 0;

    /* DataTypeConversion: '<S9>/Data Type Conversion16' incorporates:
     *  Constant: '<S9>/C_0'
     *  DataStoreWrite: '<S9>/targetSlipSt'
     */
    targetSlipSt = 0U;

    /* DataTypeConversion: '<S9>/Data Type Conversion4' incorporates:
     *  Constant: '<S9>/C_0'
     *  DataStoreWrite: '<S9>/targetSpeedTmrFlag'
     */
    targetSpeedTmrFlag = 0U;

    /* DataTypeConversion: '<S9>/Data Type Conversion27' incorporates:
     *  Constant: '<S9>/C_0'
     *  DataStoreWrite: '<S9>/trqI_PID'
     */
    trqI_PID = 0;

    /* DataTypeConversion: '<S9>/Data Type Conversion8' incorporates:
     *  Constant: '<S9>/C_1'
     *  DataStoreWrite: '<S9>/VLC_Mode'
     */
    VLC_Mode = 0U;

    /* Saturate: '<S9>/Saturation' incorporates:
     *  DataStoreRead: '<S9>/numGearEngaged'
     */
    if (numGearEngaged_vlc > 9) {
      rtb_Switch1_k = 9U;
    } else if (numGearEngaged_vlc < 1) {
      rtb_Switch1_k = 1U;
    } else {
      rtb_Switch1_k = numGearEngaged_vlc;
    }

    /* End of Saturate: '<S9>/Saturation' */

    /* Lookup_n-D: '<S9>/Gear_ratio_LT' */
    rtb_DataTypeConversion_hs = plook_u32u8s16u32n32_evenca_gs(rtb_Switch1_k,
      GearNumber[0], (uint16_T)(GearNumber[1] - GearNumber[0]), &frac);
    rtb_Switch_e = intrp1d_s16s32s32u32u32n32la_s(rtb_DataTypeConversion_hs,
      frac, (&(GearRatio[0])), 8U);

    /* Math: '<S9>/Math Function' incorporates:
     *  DataStoreWrite: '<S9>/TorqueRatio'
     *
     * About '<S9>/Math Function':
     *  Operator: reciprocal
     */
    tmp_1 = div_nzp_us32_sat_round(1048576, rtb_Switch_e) * 15625ULL;
    tmp_1 = ((tmp_1 & 8192ULL) != 0ULL) + (tmp_1 >> 14);
    if (tmp_1 > 4294967295ULL) {
      tmp_1 = 4294967295ULL;
    }

    TorqueRatio = (uint32_T)tmp_1;

    /* End of Math: '<S9>/Math Function' */

    /* Product: '<S9>/Product' incorporates:
     *  Constant: '<S9>/MainGearRatio'
     *  DataStoreWrite: '<S9>/curTrqRatio'
     */
    rtb_Saturation2 = rtb_Switch_e * MainGearRatio;
    curTrqRatio = (uint16_T)((((rtb_Saturation2 & 32U) != 0U) &&
      (((rtb_Saturation2 & 31U) != 0U) || (rtb_Saturation2 > 0))) +
      (rtb_Saturation2 >> 6));

    /* DataStoreWrite: '<S9>/targetSpeedTemp' incorporates:
     *  DataStoreRead: '<S9>/targetSpeed'
     */
    targetSpeedTemp = targetSpeed;

    /* End of Outputs for SubSystem: '<S1>/VLC_Inactive' */
  }

  /* End of If: '<S1>/If3' */

  /* RelationalOperator: '<S1>/Relational Operator' incorporates:
   *  DataStoreWrite: '<S1>/targetSpeed'
   *  DataStoreWrite: '<S1>/targetSpeed2'
   */
  rtb_RelationalOperator1_ce = (targetSpeed > targetSpeedDelay);

  /* Outputs for Triggered SubSystem: '<S1>/Triggered Subsystem' incorporates:
   *  TriggerPort: '<S7>/Trigger'
   */
  if (rtb_RelationalOperator1_ce && (rtPrevZCX.TriggeredSubsystem_Trig_ZCE !=
       POS_ZCSIG)) {
    /* DataStoreWrite: '<S7>/Data Store Write' incorporates:
     *  Constant: '<S7>/Constant3'
     */
    targetSpeedTmrFlag = 0U;

    /* DataStoreWrite: '<S7>/Data Store Write1' incorporates:
     *  DataStoreRead: '<S7>/targetSpeedDelay'
     */
    targetSpeedTemp = targetSpeed;
  }

  rtPrevZCX.TriggeredSubsystem_Trig_ZCE = rtb_RelationalOperator1_ce;

  /* End of Outputs for SubSystem: '<S1>/Triggered Subsystem' */

  /* Outputs for Atomic SubSystem: '<S1>/Engine Model Subsystem' */
  /* Outputs for Atomic SubSystem: '<S2>/Discrete filter' */
  /* Saturate: '<S10>/Saturation' */
  if (rtb_EngineRPM >= 100000U) {
    rtb_EngineRPM = 100000U;
  }

  /* End of Saturate: '<S10>/Saturation' */

  /* Product: '<S10>/Product' incorporates:
   *  Constant: '<S10>/EngineSpdFilter'
   */
  tmp_1 = (uint64_T)rtb_EngineRPM * EngineSpdFilter;
  tmp = (int32_T)(((tmp_1 & 64ULL) != 0ULL) + (tmp_1 >> 7)) * 1374389535LL;

  /* Product: '<S10>/Product1' incorporates:
   *  Constant: '<S10>/Constant1'
   *  Constant: '<S10>/EngineSpdFilter'
   *  Sum: '<S10>/Add'
   *  UnitDelay: '<S10>/Unit Delay'
   */
  tmp_0 = (int64_T)(int16_T)(100 - (int16_T)EngineSpdFilter) *
    rtDW.UnitDelay_DSTATE_f;
  tmp_0 = (int32_T)((((tmp_0 & 64ULL) != 0ULL) && (((tmp_0 & 63ULL) != 0ULL) ||
    (tmp_0 > 0LL))) + (tmp_0 >> 7)) * 1374389535LL;

  /* Sum: '<S10>/Add1' incorporates:
   *  Product: '<S10>/Product'
   *  Product: '<S10>/Product1'
   */
  rtb_Product1_l = (int32_T)((((tmp & 536870912ULL) != 0ULL) && (((tmp &
    536870911ULL) != 0ULL) || (tmp > 0LL))) + (tmp >> 30)) + (int32_T)((((tmp_0
    & 536870912ULL) != 0ULL) && (((tmp_0 & 536870911ULL) != 0ULL) || (tmp_0 >
    0LL))) + (tmp_0 >> 30));

  /* DataTypeConversion: '<S10>/Data Type Conversion' */
  rtb_EngineRPM = (uint32_T)rtb_Product1_l;

  /* Update for UnitDelay: '<S10>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_f = rtb_Product1_l;

  /* End of Outputs for SubSystem: '<S2>/Discrete filter' */

  /* Product: '<S2>/Divide' incorporates:
   *  Constant: '<S2>/Constant'
   *  Delay: '<S2>/Delay'
   *  Delay: '<S2>/Delay1'
   *  Gain: '<S2>/Gain'
   *  Gain: '<S2>/Gain1'
   *  Sum: '<S2>/Add'
   */
  rtb_Product1_l = (int32_T)rt_roundd_snf((real_T)(((int32_T)(3U * rtb_EngineRPM)
    - (int32_T)(rtDW.Delay1_DSTATE_i << 2)) + (int32_T)rtDW.Delay_DSTATE_o[0]) *
    0.01 / 0.02 * 100.0);

  /* Outputs for Atomic SubSystem: '<S2>/Discrete filter3' */
  /* Saturate: '<S11>/Saturation' */
  if (rtb_Product1_l > 700000) {
    rtb_Product1_l = 700000;
  } else {
    if (rtb_Product1_l < -700000) {
      rtb_Product1_l = -700000;
    }
  }

  /* End of Saturate: '<S11>/Saturation' */

  /* Product: '<S11>/Product' incorporates:
   *  Constant: '<S11>/EngineAccelFilter'
   */
  tmp = (int64_T)rtb_Product1_l * EngineAccelFilter;
  tmp = (int32_T)((((tmp & 64ULL) != 0ULL) && (((tmp & 63ULL) != 0ULL) || (tmp >
    0LL))) + (tmp >> 7)) * 1374389535LL;

  /* Product: '<S11>/Product1' incorporates:
   *  Constant: '<S11>/Constant1'
   *  Constant: '<S11>/EngineAccelFilter'
   *  Sum: '<S11>/Add'
   *  UnitDelay: '<S11>/Unit Delay'
   */
  tmp_0 = (int64_T)(int16_T)(100 - (int16_T)EngineAccelFilter) *
    rtDW.UnitDelay_DSTATE_p;
  tmp_0 = (int32_T)((((tmp_0 & 64ULL) != 0ULL) && (((tmp_0 & 63ULL) != 0ULL) ||
    (tmp_0 > 0LL))) + (tmp_0 >> 7)) * 1374389535LL;

  /* Sum: '<S11>/Add1' incorporates:
   *  Product: '<S11>/Product'
   *  Product: '<S11>/Product1'
   */
  rtb_Product1_l = (int32_T)((((tmp & 536870912ULL) != 0ULL) && (((tmp &
    536870911ULL) != 0ULL) || (tmp > 0LL))) + (tmp >> 30)) + (int32_T)((((tmp_0
    & 536870912ULL) != 0ULL) && (((tmp_0 & 536870911ULL) != 0ULL) || (tmp_0 >
    0LL))) + (tmp_0 >> 30));

  /* Update for UnitDelay: '<S11>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_p = rtb_Product1_l;

  /* End of Outputs for SubSystem: '<S2>/Discrete filter3' */

  /* Product: '<S2>/Divide2' incorporates:
   *  Constant: '<S2>/EngineInertia'
   */
  tmp = (int64_T)rtb_Product1_l * EngineInertia;
  tmp = (int32_T)((((tmp & 64ULL) != 0ULL) && (((tmp & 63ULL) != 0ULL) || (tmp >
    0LL))) + (tmp >> 7)) * 1374389535LL;

  /* Sum: '<S2>/Add3' incorporates:
   *  Constant: '<S2>/Constant2'
   *  Product: '<S2>/Divide2'
   */
  rtb_Product1_l = (int32_T)((((tmp & 536870912ULL) != 0ULL) && (((tmp &
    536870911ULL) != 0ULL) || (tmp > 0LL))) + (tmp >> 30)) + 200;

  /* Saturate: '<S2>/Saturation' */
  if (rtb_Product1_l >= 10000) {
    rtb_Switch_e = 10000;
  } else if (rtb_Product1_l <= -10000) {
    rtb_Switch_e = -10000;
  } else {
    rtb_Switch_e = (int16_T)rtb_Product1_l;
  }

  /* End of Saturate: '<S2>/Saturation' */

  /* Product: '<S2>/Product2' incorporates:
   *  Constant: '<S2>/dbg_eng'
   *  DataTypeConversion: '<S2>/Data Type Conversion3'
   */
  rtb_Switch_e *= dbg_eng;

  /* DataStoreWrite: '<S2>/EngineInertiaTrq1' */
  EngineInertiaTrq = rtb_Switch_e;

  /* Update for Delay: '<S2>/Delay1' */
  rtDW.Delay1_DSTATE_i = rtb_EngineRPM;

  /* Update for Delay: '<S2>/Delay' */
  rtDW.Delay_DSTATE_o[0] = rtDW.Delay_DSTATE_o[1];
  rtDW.Delay_DSTATE_o[1] = rtb_EngineRPM;

  /* End of Outputs for SubSystem: '<S1>/Engine Model Subsystem' */

  /* Outputs for Atomic SubSystem: '<S1>/Observers' */
  /* Outputs for Atomic SubSystem: '<S5>/Ax' */
  /* Gain: '<S115>/Gain1' incorporates:
   *  Gain: '<S115>/Gain2'
   */
  tmp_2 = g * 41943U;
  rtb_DataTypeConversion_hs = ((tmp_2 & 512U) != 0U) + (tmp_2 >> 10);
  if (rtb_DataTypeConversion_hs > 65535U) {
    rtb_DataTypeConversion_hs = 65535U;
  }

  /* Product: '<S119>/(1-alfa)Ga_max' incorporates:
   *  Constant: '<S115>/WghtFull'
   *  Constant: '<S119>/c_1'
   *  Constant: '<S119>/parametrOLBC_mdlCompensation'
   *  Gain: '<S115>/Gain1'
   *  Sum: '<S119>/1-alfa'
   */
  tmp_1 = (uint64_T)(uint16_T)(1000 - (int16_T)(parametrOLBC_mdlCompensation *
    10U)) * (rtb_DataTypeConversion_hs * WghtFull);
  tmp_1 = (uint32_T)(((tmp_1 & 512ULL) != 0ULL) + (tmp_1 >> 10)) * 274877907ULL;

  /* Sum: '<S119>/Subtract1' incorporates:
   *  Product: '<S119>/(1-alfa)Ga_max'
   */
  rtb_DataTypeConversion_hs = (uint32_T)(((tmp_1 & 134217728ULL) != 0ULL) +
    (tmp_1 >> 28));

  /* Gain: '<S115>/Gain2' */
  tmp_2 = ((tmp_2 & 512U) != 0U) + (tmp_2 >> 10);
  if (tmp_2 > 65535U) {
    tmp_2 = 65535U;
  }

  /* Product: '<S119>/alfa*Ga_min' incorporates:
   *  Constant: '<S115>/WghtCurb'
   *  Constant: '<S119>/parametrOLBC_mdlCompensation'
   *  Gain: '<S115>/Gain2'
   */
  tmp_1 = (uint64_T)(tmp_2 * WghtCurb) * parametrOLBC_mdlCompensation;
  tmp_1 = (uint32_T)(((tmp_1 & 64ULL) != 0ULL) + (tmp_1 >> 7)) * 2748779069ULL;

  /* Sum: '<S119>/Subtract1' incorporates:
   *  DataStoreWrite: '<S119>/Ga_OLBC'
   *  Product: '<S119>/alfa*Ga_min'
   */
  tmp_2 = (uint32_T)(((tmp_1 & 1073741824ULL) != 0ULL) + (tmp_1 >> 31));
  Ga_OLBC = (uint16_T)((uint32_T)(uint16_T)(((rtb_DataTypeConversion_hs & 2048U)
    != 0U) + (rtb_DataTypeConversion_hs >> 12)) + (uint16_T)(((tmp_2 & 2048U) !=
    0U) + (tmp_2 >> 12)));

  /* Math: '<S115>/Math Function' incorporates:
   *  DataStoreRead: '<S115>/Data Store Read'
   *
   * About '<S115>/Math Function':
   *  Operator: reciprocal
   */
  rtb_EngineRPM = (uint32_T)((1048576U / TorqueRatio * 15625ULL) >> 14);

  /* Saturate: '<S115>/Saturation' */
  if (rtb_EngineRPM >= 5850U) {
    rtb_EngineRPM = 5850U;
  }

  /* End of Saturate: '<S115>/Saturation' */

  /* Product: '<S120>/div2' incorporates:
   *  Constant: '<S120>/mu_pad'
   */
  rtb_Gain6 = (real32_T)mu_pad * 0.01F * 2.0F;

  /* Math: '<S123>/Math Function2' incorporates:
   *  Constant: '<S123>/Rear_pistons_1'
   *  Math: '<S124>/Math Function2'
   *
   * About '<S123>/Math Function2':
   *  Operator: magnitude^2
   *
   * About '<S124>/Math Function2':
   *  Operator: magnitude^2
   */
  u0 = BrakePistonR_R1 * BrakePistonR_R1 * 1.0E+6F;

  /* Math: '<S123>/Math Function3' incorporates:
   *  Constant: '<S123>/Rear_pistons_2'
   *  Math: '<S124>/Math Function3'
   *
   * About '<S123>/Math Function3':
   *  Operator: magnitude^2
   *
   * About '<S124>/Math Function3':
   *  Operator: magnitude^2
   */
  rtb_Add3_ag = BrakePistonR_R2 * BrakePistonR_R2 * 1.0E+6F;

  /* Math: '<S121>/Math Function3' incorporates:
   *  Constant: '<S121>/Front_pistons_1'
   *  Math: '<S122>/Math Function3'
   *
   * About '<S121>/Math Function3':
   *  Operator: magnitude^2
   *
   * About '<S122>/Math Function3':
   *  Operator: magnitude^2
   */
  rtb_slip_koef = BrakePistonR_F1 * BrakePistonR_F1 * 1.0E+6F;

  /* Math: '<S121>/Math Function4' incorporates:
   *  Constant: '<S121>/Front_pistons_2'
   *  Math: '<S122>/Math Function4'
   *
   * About '<S121>/Math Function4':
   *  Operator: magnitude^2
   *
   * About '<S122>/Math Function4':
   *  Operator: magnitude^2
   */
  rtb_Saturation_pc = BrakePistonR_F2 * BrakePistonR_F2 * 1.0E+6F;

  /* Math: '<S121>/Math Function5' incorporates:
   *  Constant: '<S121>/Front_pistons_3'
   *  Math: '<S122>/Math Function5'
   *
   * About '<S121>/Math Function5':
   *  Operator: magnitude^2
   *
   * About '<S122>/Math Function5':
   *  Operator: magnitude^2
   */
  rtb_Divide = BrakePistonR_F3 * BrakePistonR_F3 * 1.0E+6F;

  /* Math: '<S123>/Math Function2'
   *
   * About '<S123>/Math Function2':
   *  Operator: magnitude^2
   */
  if (u0 < 65536.0F) {
    if (u0 >= 0.0F) {
      rtb_Switch1_hj = (uint16_T)u0;
    } else {
      rtb_Switch1_hj = 0U;
    }
  } else {
    rtb_Switch1_hj = MAX_uint16_T;
  }

  /* Math: '<S123>/Math Function3'
   *
   * About '<S123>/Math Function3':
   *  Operator: magnitude^2
   */
  if (rtb_Add3_ag < 65536.0F) {
    if (rtb_Add3_ag >= 0.0F) {
      tmp_3 = (uint16_T)rtb_Add3_ag;
    } else {
      tmp_3 = 0U;
    }
  } else {
    tmp_3 = MAX_uint16_T;
  }

  /* Product: '<S120>/div1' incorporates:
   *  Constant: '<S123>/1//4'
   *  Constant: '<S123>/BrakeDiskR_R'
   *  Constant: '<S123>/Pi'
   *  DataStoreRead: '<S115>/ESP_07_pWheelRRFromCAN'
   *  Product: '<S120>/Pa'
   *  Product: '<S123>/Divide3'
   *  Product: '<S123>/Divide4'
   *  Product: '<S123>/Divide5'
   *  Product: '<S123>/div2'
   *  Product: '<S123>/div3'
   *  Sum: '<S123>/Add2'
   */
  rtb_Divide6 = ((real32_T)rtb_Switch1_hj * 1.0E-6F * 3.14F + (real32_T)tmp_3 *
                 1.0E-6F * 3.14F) * 0.25F * (real32_T)(uint32_T)rt_roundf_snf
    (pWheelFL_vlc * 100000.0F) * BrakeDiskR_R * rtb_Gain6;
  rtb_Divide1_b = (real32_T)fabs(rtb_Divide6);

  /* Math: '<S124>/Math Function2'
   *
   * About '<S124>/Math Function2':
   *  Operator: magnitude^2
   */
  if (u0 < 65536.0F) {
    if (u0 >= 0.0F) {
      rtb_Switch1_hj = (uint16_T)u0;
    } else {
      rtb_Switch1_hj = 0U;
    }
  } else {
    rtb_Switch1_hj = MAX_uint16_T;
  }

  /* Math: '<S124>/Math Function3'
   *
   * About '<S124>/Math Function3':
   *  Operator: magnitude^2
   */
  if (rtb_Add3_ag < 65536.0F) {
    if (rtb_Add3_ag >= 0.0F) {
      tmp_3 = (uint16_T)rtb_Add3_ag;
    } else {
      tmp_3 = 0U;
    }
  } else {
    tmp_3 = MAX_uint16_T;
  }

  /* Product: '<S120>/div3' incorporates:
   *  Constant: '<S124>/1//4'
   *  Constant: '<S124>/BrakeDiskR_R'
   *  Constant: '<S124>/Pi'
   *  DataStoreRead: '<S115>/ESP_07_pWheelRRFromCAN1'
   *  Product: '<S120>/Pa1'
   *  Product: '<S124>/Divide3'
   *  Product: '<S124>/Divide4'
   *  Product: '<S124>/Divide5'
   *  Product: '<S124>/div2'
   *  Product: '<S124>/div3'
   *  Sum: '<S124>/Add2'
   */
  u0 = ((real32_T)rtb_Switch1_hj * 1.0E-6F * 3.14F + (real32_T)tmp_3 * 1.0E-6F *
        3.14F) * 0.25F * (real32_T)(uint32_T)rt_roundf_snf(pWheelFR_vlc *
    100000.0F) * BrakeDiskR_R * rtb_Gain6;
  rtb_Add3_ag = (real32_T)fabs(u0);

  /* Math: '<S121>/Math Function3'
   *
   * About '<S121>/Math Function3':
   *  Operator: magnitude^2
   */
  if (rtb_slip_koef < 65536.0F) {
    if (rtb_slip_koef >= 0.0F) {
      rtb_Switch1_hj = (uint16_T)rtb_slip_koef;
    } else {
      rtb_Switch1_hj = 0U;
    }
  } else {
    rtb_Switch1_hj = MAX_uint16_T;
  }

  /* Math: '<S121>/Math Function4'
   *
   * About '<S121>/Math Function4':
   *  Operator: magnitude^2
   */
  if (rtb_Saturation_pc < 65536.0F) {
    if (rtb_Saturation_pc >= 0.0F) {
      tmp_3 = (uint16_T)rtb_Saturation_pc;
    } else {
      tmp_3 = 0U;
    }
  } else {
    tmp_3 = MAX_uint16_T;
  }

  /* Math: '<S121>/Math Function5'
   *
   * About '<S121>/Math Function5':
   *  Operator: magnitude^2
   */
  if (rtb_Divide < 65536.0F) {
    if (rtb_Divide >= 0.0F) {
      tmp_4 = (uint16_T)rtb_Divide;
    } else {
      tmp_4 = 0U;
    }
  } else {
    tmp_4 = MAX_uint16_T;
  }

  /* Product: '<S120>/div4' incorporates:
   *  Constant: '<S121>/1//4'
   *  Constant: '<S121>/BrakeDiskR_F'
   *  Constant: '<S121>/Pi'
   *  DataStoreRead: '<S115>/ESP_07_pWheelRRFromCAN2'
   *  Product: '<S120>/Pa2'
   *  Product: '<S121>/Divide4'
   *  Product: '<S121>/Divide5'
   *  Product: '<S121>/Divide6'
   *  Product: '<S121>/Divide7'
   *  Product: '<S121>/div2'
   *  Product: '<S121>/div3'
   *  Sum: '<S121>/Add2'
   */
  rtb_Add_lz = (((real32_T)rtb_Switch1_hj * 1.0E-6F * 3.14F + (real32_T)tmp_3 *
                 1.0E-6F * 3.14F) + (real32_T)tmp_4 * 1.0E-6F * 3.14F) * 0.25F *
    (real32_T)(uint32_T)rt_roundf_snf(pWheelRL_vlc * 100000.0F) * BrakeDiskR_F *
    rtb_Gain6;
  rtb_DataTypeConversion2_f = (real32_T)fabs(rtb_Add_lz);

  /* Math: '<S122>/Math Function3'
   *
   * About '<S122>/Math Function3':
   *  Operator: magnitude^2
   */
  if (rtb_slip_koef < 65536.0F) {
    if (rtb_slip_koef >= 0.0F) {
      rtb_Switch1_hj = (uint16_T)rtb_slip_koef;
    } else {
      rtb_Switch1_hj = 0U;
    }
  } else {
    rtb_Switch1_hj = MAX_uint16_T;
  }

  /* Math: '<S122>/Math Function4'
   *
   * About '<S122>/Math Function4':
   *  Operator: magnitude^2
   */
  if (rtb_Saturation_pc < 65536.0F) {
    if (rtb_Saturation_pc >= 0.0F) {
      tmp_3 = (uint16_T)rtb_Saturation_pc;
    } else {
      tmp_3 = 0U;
    }
  } else {
    tmp_3 = MAX_uint16_T;
  }

  /* Math: '<S122>/Math Function5'
   *
   * About '<S122>/Math Function5':
   *  Operator: magnitude^2
   */
  if (rtb_Divide < 65536.0F) {
    if (rtb_Divide >= 0.0F) {
      tmp_4 = (uint16_T)rtb_Divide;
    } else {
      tmp_4 = 0U;
    }
  } else {
    tmp_4 = MAX_uint16_T;
  }

  /* Product: '<S120>/div5' incorporates:
   *  Constant: '<S122>/1//4'
   *  Constant: '<S122>/BrakeDiskR_F'
   *  Constant: '<S122>/Pi'
   *  DataStoreRead: '<S115>/ESP_07_pWheelRRFromCAN3'
   *  Product: '<S120>/Pa3'
   *  Product: '<S122>/Divide4'
   *  Product: '<S122>/Divide5'
   *  Product: '<S122>/Divide6'
   *  Product: '<S122>/Divide7'
   *  Product: '<S122>/div2'
   *  Product: '<S122>/div3'
   *  Sum: '<S122>/Add2'
   */
  rtb_Gain6 *= (((real32_T)rtb_Switch1_hj * 1.0E-6F * 3.14F + (real32_T)tmp_3 *
                 1.0E-6F * 3.14F) + (real32_T)tmp_4 * 1.0E-6F * 3.14F) * 0.25F *
    (real32_T)(uint32_T)rt_roundf_snf(pWheelRR_vlc * 100000.0F) * BrakeDiskR_F;
  rtb_slip_koef = (real32_T)fabs(rtb_Gain6);

  /* Product: '<S120>/div1' */
  if (rtb_Divide1_b < 8.388608E+6F) {
    if (rtb_Divide1_b >= 0.5F) {
      rtb_Divide6 = (real32_T)floor(rtb_Divide6 + 0.5F);
    } else {
      rtb_Divide6 *= 0.0F;
    }
  }

  /* Product: '<S120>/div3' */
  if (rtb_Add3_ag < 8.388608E+6F) {
    if (rtb_Add3_ag >= 0.5F) {
      u0 = (real32_T)floor(u0 + 0.5F);
    } else {
      u0 *= 0.0F;
    }
  }

  /* Product: '<S120>/div4' */
  if (rtb_DataTypeConversion2_f < 8.388608E+6F) {
    if (rtb_DataTypeConversion2_f >= 0.5F) {
      rtb_Add_lz = (real32_T)floor(rtb_Add_lz + 0.5F);
    } else {
      rtb_Add_lz *= 0.0F;
    }
  }

  /* Product: '<S120>/div5' */
  if (rtb_slip_koef < 8.388608E+6F) {
    if (rtb_slip_koef >= 0.5F) {
      rtb_Gain6 = (real32_T)floor(rtb_Gain6 + 0.5F);
    } else {
      rtb_Gain6 *= 0.0F;
    }
  }

  /* Product: '<S115>/FRllDrg Force2' incorporates:
   *  Constant: '<S115>/rd2'
   *  Gain: '<S115>/Gain'
   *  Product: '<S115>/div'
   *  Product: '<S120>/div1'
   *  Product: '<S120>/div3'
   *  Product: '<S120>/div4'
   *  Product: '<S120>/div5'
   *  RelationalOperator: '<S117>/Compare'
   *  Sum: '<S115>/Add1'
   *  Sum: '<S115>/Add5'
   */
  tmp = (int32_T)div_nzp_s64_round((int64_T)((int32_T)((((uint32_T)rtb_Divide6 +
    (uint32_T)u0) + (uint32_T)rtb_Add_lz) + (uint32_T)rtb_Gain6) *
    -(rtb_DataTypeConversion_ai > 0)) << 19, rd) * 25LL;

  /* Product: '<S115>/afr2' incorporates:
   *  Constant: '<S115>/g1'
   *  Product: '<S115>/afr1'
   */
  rtb_Gain6 = (real32_T)g * 0.01F;

  /* Sum: '<S115>/Add' incorporates:
   *  Constant: '<S115>/Constant1'
   *  Constant: '<S115>/rd1'
   *  DataStoreRead: '<S115>/M_MotClutch_WI'
   *  DataStoreRead: '<S5>/Data Store Read'
   *  DataStoreWrite: '<S119>/Ga_OLBC'
   *  Lookup_n-D: '<S5>/FreeRollingModel1'
   *  Product: '<S115>/FRllDrg Force1'
   *  Product: '<S115>/FRllDrg Force2'
   *  Product: '<S115>/Prod'
   *  Product: '<S115>/Prod1'
   *  Product: '<S115>/Product'
   *  Product: '<S115>/a//g1'
   *  Product: '<S115>/a//g2'
   *  Product: '<S115>/afr1'
   *  Product: '<S115>/afr2'
   *  RelationalOperator: '<S118>/Compare'
   *  Sum: '<S115>/Subtract'
   */
  rtb_Divide6 = (((real32_T)(int32_T)div_nzp_s64_round((int64_T)(int32_T)((((tmp
    & 8ULL) != 0ULL) && (((tmp & 7ULL) != 0ULL) || (tmp > 0LL))) + (tmp >> 4)) <<
    4, Ga_OLBC) * 7.62939453E-6F * rtb_Gain6 + (real32_T)
                  ((rtb_DataTypeConversion_ai > 0) * (rtb_EngineTorque +
    M_MotClutch_WI)) * ((real32_T)rtb_EngineRPM * 0.001F * ((real32_T)
    MainGearRatio * 0.015625F)) / ((real32_T)rd * 0.01F) / (real32_T)Ga_OLBC *
                  rtb_Gain6) + (real32_T)look1_iu16lu64n48ts16D_7ZfpVqQH
                 (rtb_DataTypeConversion_ai, (&(FreeRollingResistanceBP[0])),
                  (&(FreeRollingResistanceTD[0])), 15U) * 0.001F) - AngEstimate;

  /* End of Outputs for SubSystem: '<S5>/Ax' */

  /* DataStoreWrite: '<S5>/estAX' */
  estAX = rtb_Divide6;

  /* Outputs for Atomic SubSystem: '<S1>/Input Processing1' */
  /* Product: '<S116>/Divide5' incorporates:
   *  Constant: '<S116>/Const_1'
   *  Constant: '<S116>/Pi1'
   *  Constant: '<S116>/steerGearRat'
   *  DataStoreRead: '<S1>/AX3'
   *  Product: '<S116>/Divide4'
   *  Product: '<S116>/Product4'
   *  SignalConversion: '<S4>/TmpSignal ConversionAtData Type Conversion18Inport1'
   */
  rtb_Gain6 = SasAng / ((real32_T)steerGearRat * 0.01F) * 3.14F / 180.0F;

  /* End of Outputs for SubSystem: '<S1>/Input Processing1' */

  /* Product: '<S125>/Divide4' incorporates:
   *  Constant: '<S125>/vehicleBase'
   *  Product: '<S116>/Divide6'
   */
  u0 = (real32_T)vehicleBase * 0.1F;

  /* Product: '<S125>/Divide1' incorporates:
   *  Constant: '<S125>/Pi2'
   *  DataStoreRead: '<S125>/VehicleSpeed'
   *  Product: '<S116>/Divide1'
   */
  rtb_Divide1_b = (real32_T)VehicleSpeed_VLCInt * 0.01F / 3.6F;

  /* Product: '<S125>/Product2' incorporates:
   *  DataStoreWrite: '<S5>/yawRateSS1'
   *  Product: '<S125>/Divide1'
   *  Product: '<S125>/Divide4'
   */
  yawRateSS = rtb_Divide1_b * (rtb_Gain6 / u0);

  /* Sum: '<S116>/Add1' incorporates:
   *  Constant: '<S116>/slip_koef'
   *  Lookup_n-D: '<S116>/1-D Lookup Table2'
   *  Product: '<S116>/Product1'
   *  Product: '<S116>/Product2'
   */
  rtb_Gain6 += (real32_T)sideslip_angle_koef * 0.01F * look1_iflf_binlx
    (rtb_Divide1_l, (&(lateralLoud[0])), (&(sideSlipAngle[0])), 14U) *
    rtb_Divide_c;

  /* Product: '<S116>/Product5' incorporates:
   *  DataStoreWrite: '<S5>/yawRateSSwithSlip1'
   *  Product: '<S116>/Divide6'
   */
  yawRateSSwithSlip = rtb_Divide1_b * (rtb_Gain6 / u0);

  /* End of Outputs for SubSystem: '<S1>/Observers' */

  /* Outputs for Atomic SubSystem: '<S1>/VLC Decision making machine' */
  /* Switch: '<S8>/Switch4' incorporates:
   *  Constant: '<S143>/Constant'
   *  Constant: '<S144>/Constant'
   *  Constant: '<S8>/OLD_NEW_ACCSTAT'
   *  DataStoreRead: '<S1>/pWheelRR1'
   *  Inport: '<S4>/ACCStat_in'
   *  RelationalOperator: '<S143>/Compare'
   *  RelationalOperator: '<S144>/Compare'
   */
  if (NewAccStatReqs > 0) {
    /* Outputs for Atomic SubSystem: '<S1>/Input Processing1' */
    rtb_RelationalOperator2_d = (AccActive >= 2);

    /* End of Outputs for SubSystem: '<S1>/Input Processing1' */
  } else {
    /* Outputs for Atomic SubSystem: '<S1>/Input Processing1' */
    rtb_RelationalOperator2_d = (AccActive == 2);

    /* End of Outputs for SubSystem: '<S1>/Input Processing1' */
  }

  /* End of Switch: '<S8>/Switch4' */

  /* Switch: '<S8>/Switch3' incorporates:
   *  Constant: '<S8>/NUUUULLLL'
   *  DataStoreRead: '<S8>/ASRinRegulation1'
   *  DataStoreWrite: '<S8>/ACCMotInc1'
   */
  if (rtb_RelationalOperator2_d) {
    AccTrqAvailable = ASRinRegulation;
  } else {
    AccTrqAvailable = 0U;
  }

  /* End of Switch: '<S8>/Switch3' */

  /* Outputs for Atomic SubSystem: '<S8>/Discrete filter1' */
  /* Outputs for Atomic SubSystem: '<S8>/VLC_TargetEngTorque processing1' */
  /* Outputs for Atomic SubSystem: '<S151>/Discrete filter' */
  /* Sum: '<S156>/Add' incorporates:
   *  Constant: '<S156>/Constant1'
   *  Sum: '<S147>/Add'
   */
  rtb_Saturation2 = (int16_T)(c_1 * 100U);

  /* End of Outputs for SubSystem: '<S8>/Discrete filter1' */

  /* Product: '<S156>/Product1' incorporates:
   *  Constant: '<S156>/Constant2'
   *  Sum: '<S156>/Add'
   *  UnitDelay: '<S156>/Unit Delay'
   */
  tmp = (int64_T)(int16_T)(rtb_Saturation2 - trq_f) * rtDW.UnitDelay_DSTATE;
  tmp = (int32_T)((((tmp & 64ULL) != 0ULL) && (((tmp & 63ULL) != 0ULL) || (tmp >
    0LL))) + (tmp >> 7)) * 1374389535LL;

  /* Saturate: '<S156>/Saturation' incorporates:
   *  DataStoreRead: '<S8>/VLC_TargetEngTorque'
   */
  if (VLC_TargetEngTorque > 1000) {
    rtb_Abs_g = 1000;
  } else if (VLC_TargetEngTorque < -300) {
    rtb_Abs_g = -300;
  } else {
    rtb_Abs_g = VLC_TargetEngTorque;
  }

  /* End of Saturate: '<S156>/Saturation' */

  /* Sum: '<S156>/Add1' incorporates:
   *  Constant: '<S156>/Constant2'
   *  Product: '<S156>/Product'
   *  Product: '<S156>/Product1'
   */
  rtb_Product1_l = (int32_T)((((tmp & 536870912ULL) != 0ULL) && (((tmp &
    536870911ULL) != 0ULL) || (tmp > 0LL))) + (tmp >> 30)) + (int16_T)(rtb_Abs_g
    * trq_f);

  /* Update for UnitDelay: '<S156>/Unit Delay' */
  rtDW.UnitDelay_DSTATE = rtb_Product1_l;

  /* End of Outputs for SubSystem: '<S151>/Discrete filter' */

  /* Switch: '<S151>/Switch' incorporates:
   *  DataStoreRead: '<S151>/torqueCutOff'
   *  DataStoreRead: '<S8>/VLC_TargetEngTorque'
   *  DataTypeConversion: '<S156>/Data Type Conversion'
   */
  if (torqueCutOff > 0) {
    rtb_EngineTorque = VLC_TargetEngTorque;
  } else {
    /* Outputs for Atomic SubSystem: '<S151>/Discrete filter' */
    /* DataTypeConversion: '<S156>/Data Type Conversion' */
    tmp = rtb_Product1_l * 1374389535LL;
    rtb_EngineTorque = (int16_T)((((tmp & 68719476736ULL) != 0ULL) && (((tmp &
      68719476735ULL) != 0ULL) || (tmp > 0LL))) + (tmp >> 37));

    /* End of Outputs for SubSystem: '<S151>/Discrete filter' */
  }

  /* End of Switch: '<S151>/Switch' */
  /* End of Outputs for SubSystem: '<S8>/VLC_TargetEngTorque processing1' */

  /* Switch: '<S8>/Switch2' incorporates:
   *  Constant: '<S141>/Constant'
   *  Constant: '<S8>/Constant'
   *  DataStoreRead: '<S8>/Data Store Read'
   *  DataStoreRead: '<S8>/Data Store Read1'
   *  DataStoreRead: '<S8>/EngineDrag'
   *  DataStoreRead: '<S8>/numGearEngaged'
   *  DataTypeConversion: '<S8>/Data Type Conversion4'
   *  Logic: '<S8>/Logical Operator1'
   *  Logic: '<S8>/Logical Operator2'
   *  Lookup_n-D: '<S8>/engTrqLimits'
   *  RelationalOperator: '<S141>/Compare'
   *  RelationalOperator: '<S8>/Relational Operator1'
   */
  if ((nICEngineSpeed_vlc > engRPMThreshold_DTC) || (numGearEngaged_vlc > 3)) {
    rtb_DataTypeConversion_j = EngineDrag;
  } else {
    rtb_DataTypeConversion_j = look1_is16lu32n32Ds32_linlcas((int16_T)
      nICEngineSpeed_vlc, (&(engDTCrpm[0])), (&(engDTCLimits[0])), 12U);
  }

  /* End of Switch: '<S8>/Switch2' */

  /* RelationalOperator: '<S8>/Relational Operator2' */
  rtb_RelationalOperator1_ce = (rtb_EngineTorque > rtb_DataTypeConversion_j);

  /* Switch: '<S8>/Switch' incorporates:
   *  Constant: '<S142>/Constant'
   *  Constant: '<S8>/C_1647'
   *  DataStoreRead: '<S8>/ASRinRegulation'
   *  DataStoreWrite: '<S8>/ACCMotInc3'
   *  Logic: '<S8>/Logical Operator3'
   *  RelationalOperator: '<S142>/Compare'
   *  Sum: '<S8>/Add3'
   */
  if ((ASRinRegulation == 1) && rtb_RelationalOperator2_d) {
    /* Switch: '<S8>/Switch1' incorporates:
     *  Constant: '<S8>/Constant1'
     *  Constant: '<S8>/dbg1EngineModel'
     *  DataTypeConversion: '<S8>/Data Type Conversion2'
     */
    if (dbg1EngineModel > 0) {
      /* DataTypeConversion: '<S8>/Data Type Conversion2' */
      rtb_Product1_l = rtb_Switch_e * 5243;
      rtb_Switch_e = (int16_T)((((rtb_Product1_l & 262144U) != 0U) &&
        (((rtb_Product1_l & 262143U) != 0U) || (rtb_Product1_l > 0))) +
        (rtb_Product1_l >> 19));
    } else {
      rtb_Switch_e = 0;
    }

    /* End of Switch: '<S8>/Switch1' */

    /* Switch: '<S8>/Switch5' */
    if (!rtb_RelationalOperator1_ce) {
      rtb_EngineTorque = rtb_DataTypeConversion_j;
    }

    /* End of Switch: '<S8>/Switch5' */
    ACCMotInc_vlc = (int16_T)(rtb_EngineTorque + rtb_Switch_e);
  } else {
    ACCMotInc_vlc = 0;
  }

  /* End of Switch: '<S8>/Switch' */

  /* DataTypeConversion: '<S8>/Data Type Conversion' incorporates:
   *  DataStoreWrite: '<S8>/ACCMotInc2'
   *  DataStoreWrite: '<S8>/ACCMotInc3'
   */
  AccTrqReq = (real32_T)ACCMotInc_vlc;

  /* RelationalOperator: '<S8>/Relational Operator' incorporates:
   *  Constant: '<S8>/AX_offSet'
   *  DataStoreRead: '<S8>/reqAcceleration'
   *  Sum: '<S8>/Add'
   */
  rtb_RelationalOperator2_d = (rtb_Divide6 - (real32_T)reqAcceleration * 0.01F >
    AX_offSet);

  /* DataTypeConversion: '<S8>/Data Type Conversion9' incorporates:
   *  Constant: '<S146>/Constant'
   *  DataStoreRead: '<S8>/VLC_Mode'
   *  DataStoreWrite: '<S8>/decelPlausibility'
   *  Logic: '<S8>/Logical Operator'
   *  Logic: '<S8>/Logical Operator4'
   *  RelationalOperator: '<S145>/Compare'
   *  RelationalOperator: '<S146>/Compare'
   */
  decelPlausibility = (uint8_T)(((!rtb_RelationalOperator1_ce) ||
    rtb_RelationalOperator2_d) && (VLC_Mode != 0));

  /* Outputs for Atomic SubSystem: '<S8>/Subsystem' */
  /* Switch: '<S148>/Switch2' incorporates:
   *  DataStoreWrite: '<S8>/decelPlausibility'
   *  Sum: '<S153>/Req force min2'
   */
  if (decelPlausibility > 0) {
    /* Saturate: '<S153>/Saturation1' incorporates:
     *  DataStoreRead: '<S153>/AXPlausibilityCounter_in'
     */
    if (VLC_DecelPlausibilityCounter < 100) {
      rtb_Switch1_hj = VLC_DecelPlausibilityCounter;
    } else {
      rtb_Switch1_hj = 100U;
    }

    /* End of Saturate: '<S153>/Saturation1' */

    /* Switch: '<S153>/Switch' incorporates:
     *  Constant: '<S153>/PlausibilityInc_ax'
     *  Constant: '<S153>/PlausibilityInc_trq'
     */
    if (rtb_RelationalOperator2_d) {
      rtb_DataTypeConversion_ai = PlausibilityInc_ax;
    } else {
      rtb_DataTypeConversion_ai = PlausibilityInc_trq;
    }

    /* End of Switch: '<S153>/Switch' */
    rtb_DataTypeConversion_ai = (uint16_T)((uint32_T)rtb_Switch1_hj +
      rtb_DataTypeConversion_ai);
  } else {
    /* Sum: '<S152>/Req force min2' incorporates:
     *  Constant: '<S152>/c_0_1'
     */
    tmp_2 = PlausibilityDec * 52429U;

    /* Saturate: '<S152>/Saturation1' incorporates:
     *  DataStoreRead: '<S152>/decelPlausibilityCounter_in'
     */
    if (VLC_DecelPlausibilityCounter < 100) {
      rtb_Switch1_hj = VLC_DecelPlausibilityCounter;
    } else {
      rtb_Switch1_hj = 100U;
    }

    /* End of Saturate: '<S152>/Saturation1' */

    /* Sum: '<S152>/Req force min2' */
    rtb_Product1_l = (rtb_Switch1_hj - (int32_T)(tmp_2 >> 19)) - ((tmp_2 &
      262144U) != 0U);

    /* Saturate: '<S152>/Saturation3' */
    if (rtb_Product1_l < 0) {
      rtb_DataTypeConversion_ai = 0U;
    } else {
      rtb_DataTypeConversion_ai = (uint16_T)rtb_Product1_l;
    }

    /* End of Saturate: '<S152>/Saturation3' */
  }

  /* End of Switch: '<S148>/Switch2' */

  /* Saturate: '<S148>/Saturation2' */
  if (rtb_DataTypeConversion_ai < 100) {
    VLC_DecelPlausibilityCounter = rtb_DataTypeConversion_ai;
  } else {
    VLC_DecelPlausibilityCounter = 100U;
  }

  /* End of Saturate: '<S148>/Saturation2' */

  /* DataTypeConversion: '<S148>/Data Type Conversion' incorporates:
   *  DataStoreWrite: '<S148>/decelPlausibilityCounter'
   *  DataStoreWrite: '<S148>/decelPlausibilityCounter_out'
   */
  DecelPlausblCount = (uint8_T)VLC_DecelPlausibilityCounter;

  /* End of Outputs for SubSystem: '<S8>/Subsystem' */

  /* Outputs for Atomic SubSystem: '<S8>/Discrete filter1' */
  /* Product: '<S147>/Product1' incorporates:
   *  Constant: '<S147>/PlaussibFltCnst'
   *  Sum: '<S147>/Add'
   *  UnitDelay: '<S147>/Unit Delay'
   */
  tmp = (int64_T)(int16_T)(rtb_Saturation2 - (int16_T)PlaussibFltCnst) *
    rtDW.UnitDelay_DSTATE_a;
  tmp = (int32_T)((((tmp & 64ULL) != 0ULL) && (((tmp & 63ULL) != 0ULL) || (tmp >
    0LL))) + (tmp >> 7)) * 1374389535LL;

  /* Sum: '<S147>/Add1' incorporates:
   *  Constant: '<S147>/PlaussibFltCnst'
   *  DataStoreWrite: '<S8>/decelPlausibility'
   *  Product: '<S147>/Product'
   *  Product: '<S147>/Product1'
   */
  rtb_Product1_l = (int32_T)((((tmp & 536870912ULL) != 0ULL) && (((tmp &
    536870911ULL) != 0ULL) || (tmp > 0LL))) + (tmp >> 30)) + (int16_T)((uint32_T)
    decelPlausibility * PlaussibFltCnst);

  /* DataTypeConversion: '<S147>/Data Type Conversion' */
  tmp = rtb_Product1_l * 1374389535LL;
  rtb_EngineTorque = (int16_T)((((tmp & 68719476736ULL) != 0ULL) && (((tmp &
    68719476735ULL) != 0ULL) || (tmp > 0LL))) + (tmp >> 37));

  /* Update for UnitDelay: '<S147>/Unit Delay' */
  rtDW.UnitDelay_DSTATE_a = rtb_Product1_l;

  /* End of Outputs for SubSystem: '<S8>/Discrete filter1' */

  /* If: '<S8>/If' incorporates:
   *  Delay: '<S8>/Delay'
   */
  if (rtb_EngineTorque < rtDW.Delay_DSTATE_ck) {
    /* Outputs for IfAction SubSystem: '<S8>/Trq is Down' incorporates:
     *  ActionPort: '<S149>/Action Port'
     */
    /* Sum: '<S149>/Add' incorporates:
     *  Constant: '<S149>/1'
     *  DataStoreRead: '<S149>/TrqDwnCntr'
     */
    rtb_DataTypeConversion_ai = (uint16_T)(TrqDwnCntr + 1U);

    /* DataStoreWrite: '<S149>/ TrqDwnCntr ' */
    TrqDwnCntr = rtb_DataTypeConversion_ai;

    /* Outputs for IfAction SubSystem: '<S149>/Else Plaussib_down' incorporates:
     *  ActionPort: '<S154>/Action Port'
     */
    /* Outputs for IfAction SubSystem: '<S149>/If Plaussib_down' incorporates:
     *  ActionPort: '<S155>/Action Port'
     */
    /* If: '<S149>/If' incorporates:
     *  Constant: '<S149>/TrqDwnCntrMax'
     *  DataStoreWrite: '<S154>/Plaussib_down'
     *  DataStoreWrite: '<S155>/Plaussib_down'
     */
    Plaussib_down = (uint8_T)(rtb_DataTypeConversion_ai >= TrqDwnCntrMax);

    /* End of Outputs for SubSystem: '<S149>/If Plaussib_down' */
    /* End of Outputs for SubSystem: '<S149>/Else Plaussib_down' */
    /* End of Outputs for SubSystem: '<S8>/Trq is Down' */
  } else {
    /* Outputs for IfAction SubSystem: '<S8>/Trq isn't down' incorporates:
     *  ActionPort: '<S150>/Action Port'
     */
    /* DataStoreWrite: '<S150>/Plaussib_down' incorporates:
     *  Constant: '<S150>/ 0 '
     */
    Plaussib_down = 0U;

    /* DataStoreWrite: '<S150>/Data Store Write' incorporates:
     *  Constant: '<S150>/0'
     */
    TrqDwnCntr = 0U;

    /* End of Outputs for SubSystem: '<S8>/Trq isn't down' */
  }

  /* End of If: '<S8>/If' */

  /* Update for Delay: '<S8>/Delay' */
  rtDW.Delay_DSTATE_ck = rtb_EngineTorque;

  /* End of Outputs for SubSystem: '<S1>/VLC Decision making machine' */

  /* Update for Delay: '<S1>/Delay1' incorporates:
   *  DataStoreWrite: '<S1>/targetSpeed'
   */
  rtDW.Delay1_DSTATE_c = targetSpeed;
}

/* Model initialize function */
void VLCforADAS_UMP_initialize(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* Start for If: '<S1>/If3' */
  rtDW.If3_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S1>/If Action Subsystem' */
  /* Start for If: '<S3>/If' */
  rtDW.If_ActiveSubsystem = -1;

  /* Start for IfAction SubSystem: '<S3>/If Action Subsystem1' */
  /* Start for Atomic SubSystem: '<S15>/VLC_BL0.0.1' */
  /* Start for If: '<S49>/If' */
  rtDW.If_ActiveSubsystem_j = -1;

  /* End of Start for SubSystem: '<S15>/VLC_BL0.0.1' */
  /* End of Start for SubSystem: '<S3>/If Action Subsystem1' */
  /* End of Start for SubSystem: '<S1>/If Action Subsystem' */
  rtPrevZCX.TriggeredSubsystem_Trig_ZCE_h = ZERO_ZCSIG;
  rtPrevZCX.TriggeredSubsystem1_Trig_ZCE_k = POS_ZCSIG;
  rtPrevZCX.TriggeredSubsystem_Trig_ZCE_j = POS_ZCSIG;
  rtPrevZCX.TriggeredSubsystem1_Trig_ZCE = POS_ZCSIG;
  rtPrevZCX.TriggeredSubsystem_Trig_ZCE = POS_ZCSIG;

  /* SystemInitialize for Atomic SubSystem: '<S1>/Road Grade Calculation' */
  /* InitializeConditions for Delay: '<S133>/Delay' */
  rtDW.icLoad = 1U;

  /* InitializeConditions for Delay: '<S131>/Delay' */
  rtDW.icLoad_c = 1U;

  /* InitializeConditions for Delay: '<S6>/Delay8' */
  rtDW.icLoad_m = 1U;

  /* InitializeConditions for Delay: '<S6>/Delay3' */
  rtDW.icLoad_mz = 1U;

  /* InitializeConditions for Delay: '<S6>/Delay6' */
  rtDW.icLoad_n = 1U;

  /* InitializeConditions for Delay: '<S6>/Delay5' */
  rtDW.icLoad_e = 1U;

  /* InitializeConditions for Delay: '<S129>/Delay' */
  rtDW.icLoad_nf = 1U;

  /* InitializeConditions for Delay: '<S130>/Delay' */
  rtDW.icLoad_n1 = 1U;

  /* InitializeConditions for Delay: '<S132>/Delay' */
  rtDW.icLoad_o = 1U;

  /* SystemInitialize for Atomic SubSystem: '<S6>/LinearGradeControl2' */
  /* InitializeConditions for Delay: '<S134>/Delay1' */
  rtDW.icLoad_k = 1U;

  /* End of SystemInitialize for SubSystem: '<S6>/LinearGradeControl2' */

  /* SystemInitialize for Atomic SubSystem: '<S6>/Protection timer3' */
  /* InitializeConditions for Delay: '<S137>/Delay1' */
  rtDW.icLoad_g = 1U;

  /* End of SystemInitialize for SubSystem: '<S6>/Protection timer3' */

  /* SystemInitialize for Atomic SubSystem: '<S6>/Protection timer2' */
  /* InitializeConditions for Delay: '<S136>/Delay1' */
  rtDW.icLoad_ov = 1U;

  /* End of SystemInitialize for SubSystem: '<S6>/Protection timer2' */

  /* SystemInitialize for Atomic SubSystem: '<S6>/Protection timer1' */
  /* InitializeConditions for Delay: '<S135>/Delay1' */
  rtDW.icLoad_b = 1U;

  /* End of SystemInitialize for SubSystem: '<S6>/Protection timer1' */
  /* End of SystemInitialize for SubSystem: '<S1>/Road Grade Calculation' */

  /* SystemInitialize for IfAction SubSystem: '<S1>/If Action Subsystem' */
  /* SystemInitialize for IfAction SubSystem: '<S3>/If Action Subsystem1' */
  /* SystemInitialize for Atomic SubSystem: '<S15>/VLC_BL0.0.1' */
  /* SystemInitialize for IfAction SubSystem: '<S49>/VLC_Active' */
  /* SystemInitialize for Atomic SubSystem: '<S51>/BoostController1' */
  /* SystemInitialize for Atomic SubSystem: '<S53>/Torque_request_subsystem1' */
  /* SystemInitialize for Atomic SubSystem: '<S57>/CLBC_PI_2.0' */
  /* SystemInitialize for Atomic SubSystem: '<S59>/LinearGradeControl' */
  /* InitializeConditions for Delay: '<S61>/Delay1' */
  rtDW.icLoad_nu = 1U;

  /* End of SystemInitialize for SubSystem: '<S59>/LinearGradeControl' */

  /* SystemInitialize for Atomic SubSystem: '<S63>/Protection timer' */
  /* InitializeConditions for Delay: '<S67>/Delay1' */
  rtDW.icLoad_kt = 1U;

  /* End of SystemInitialize for SubSystem: '<S63>/Protection timer' */
  /* End of SystemInitialize for SubSystem: '<S57>/CLBC_PI_2.0' */
  /* End of SystemInitialize for SubSystem: '<S53>/Torque_request_subsystem1' */
  /* End of SystemInitialize for SubSystem: '<S51>/BoostController1' */
  /* End of SystemInitialize for SubSystem: '<S49>/VLC_Active' */
  /* End of SystemInitialize for SubSystem: '<S15>/VLC_BL0.0.1' */
  /* End of SystemInitialize for SubSystem: '<S3>/If Action Subsystem1' */
  /* End of SystemInitialize for SubSystem: '<S1>/If Action Subsystem' */
}

/*
 * File trailer for generated code.
 *
 * [EOF]
 */
