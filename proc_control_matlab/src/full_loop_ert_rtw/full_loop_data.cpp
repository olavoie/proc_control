//
// Academic License - for use in teaching, academic research, and meeting
// course requirements at degree granting institutions only.  Not for
// government, commercial, or other organizational use.
//
// File: full_loop_data.cpp
//
// Code generated for Simulink model 'full_loop'.
//
// Model version                  : 1.488
// Simulink Coder version         : 9.3 (R2020a) 18-Nov-2019
// C/C++ source code generated on : Tue Feb 23 16:32:45 2021
//
// Target selection: ert.tlc
// Embedded hardware selection: ARM Compatible->ARM 8
// Code generation objectives: Unspecified
// Validation result: Not run
//
#include "full_loop.h"
#include "full_loop_private.h"

// Block parameters (default storage)
full_loopModelClass::P_full_loop_T full_loopModelClass::full_loop_P = {
  // Variable: N
  //  Referenced by:
  //    '<S5>/N to PWM'
  //    '<S10>/N to PWM'

  { -39.921561783600005, -39.7361560536, -39.4691718024, -38.8907059248,
    -38.267742672, -37.956261045599994, -37.5112872936, -37.288800417600008,
    -36.7993292904, -36.4433502888, -35.8648844112, -35.1974237832,
    -34.5299631552, -33.8625025272, -33.328534024800007, -32.483083896000004,
    -31.9046180184, -31.4151468912, -30.480702012000002, -29.813241384,
    -29.368267632, -28.834299129600005, -28.077843751199996, -27.6773673744,
    -27.1878962472, -26.5649329944, -26.075461867200005, -25.319006488800007,
    -25.0075248624, -24.6070484856, -24.073079983200003, -23.361121980000004,
    -23.094137728800003, -22.337682350399998, -21.937205973599998,
    -21.5367295968, -20.780274218400002, -20.4242952168, -19.8458293392,
    -19.400855587200002, -19.0448765856, -18.243923832, -17.79895008,
    -17.309478952800003, -16.6865157, -16.375034073600002, -15.796568196,
    -15.262599693600002, -14.8621233168, -14.5951390656, -14.1056679384,
    -13.705191561600001, -13.215720434400001, -12.7707466824, -12.3257729304,
    -11.791804428, -11.3913280512, -10.9908516744, -10.812862173600001,
    -10.3233910464, -10.011909420000002, -9.6114330432000017, -9.2554540416,
    -8.8549776648, -8.5434960384, -8.0540249112, -7.6980459095999993,
    -7.2975695328, -7.0305852816000005, -6.67460628, -6.3631246536,
    -6.0516430272000008, -5.6956640256, -5.2951876488, -5.0282033976,
    -4.7167217712000005, -4.3607427696, -4.0937585184000005, -3.782276892,
    -3.4707952656000005, -3.1593136392, -2.8923293880000003, -2.5363503863999997,
    -2.3138635104, -2.0468792592000002, -1.7798950080000002, -1.4684133816000002,
    -1.2459265056000004, -1.0234396296000001, -0.84545012880000014, -0.667460628,
    -0.4894711272, -0.3559790016, -0.0007, -0.0006, -0.0005, -0.0004, -0.0003,
    -0.0002, -0.0001, 0.0, 0.0001, 0.0002, 0.0003, 0.0004, 0.0005, 0.0006,
    0.0007, 0.4004763768, 0.5339685024, 0.7564553784000001, 0.9789422544,
    1.2459265056, 1.5129107568, 1.779895008, 2.1358740096, 2.4473556359999997,
    2.8478320128, 3.1593136392, 3.5152926408000003, 3.9157690176, 4.2717480192,
    4.6277270208, 5.0282033976, 5.4731771496, 5.9181509016, 6.2741299032,
    6.67460628, 7.0750826568, 7.6090511592000007, 8.009527536, 8.5434960384,
    8.89947504, 9.299951416799999, 9.7449251688, 10.145401545599999,
    10.7683647984, 11.213338550400001, 11.6138149272, 12.1477834296,
    12.5482598064, 13.037730933600002, 13.6161968112, 14.1056679384,
    14.5506416904, 15.084610192800001, 15.574081320000001, 16.197044572800003,
    16.5975209496, 17.2649815776, 17.887944830400002, 18.421913332800003,
    18.955881835200003, 19.534347712800002, 20.068316215200003,
    20.824771593600005, 21.358740096000005, 21.759216472800002,
    22.337682350400005, 23.361121980000004, 23.8505931072, 24.696043236000005,
    25.274509113600004, 26.030964492000006, 26.787419870400004,
    27.054404121600005, 27.855356875200005, 28.3448280024, 29.190278131200003,
    29.9467335096, 30.480702012000005, 31.103665264800004, 31.548639016800003,
    32.394089145600006, 33.1060471488, 33.5510209008, 34.4409684048,
    35.375413284000004, 36.1318686624, 36.6658371648, 37.4667899184,
    38.134250546400004, 38.801711174400005, 39.825150804, 40.670600932800006,
    41.738537937600007, 42.228009064800005, 42.984464443200004,
    44.230390948800007, 44.4083804496, 45.609809580000004, 46.188275457600007,
    46.944730836000005, 47.434201963199996, 48.368646842400004,
    49.169599596000005, 49.7925628488, 50.4600234768, 50.771505103200006,
    51.2164788552, 51.4537981896 },

  // Variable: dMaxX
  //  Referenced by: '<S9>/X Drift'

  0.7818852444633283,

  // Variable: dMaxY
  //  Referenced by: '<S9>/Y Drift'

  1.6516812093821325,

  // Variable: dMinX
  //  Referenced by: '<S9>/X Drift'

  -0.28730109116621594,

  // Variable: dMinY
  //  Referenced by: '<S9>/Y Drift'

  -1.0103461703320409,

  // Variable: dSeedX
  //  Referenced by: '<S9>/X Drift'

  8.0,

  // Variable: dSeedY
  //  Referenced by: '<S9>/Y Drift'

  9.0,

  // Variable: tmax
  //  Referenced by: '<S26>/Constant6'

  32.0,

  // Variable: tmin
  //  Referenced by: '<S26>/Constant'

  -26.0,

  // Variable: waPhi
  //  Referenced by: '<S9>/Roll Wave'

  1.0,

  // Variable: waPsi
  //  Referenced by: '<S9>/Yaw Wave'

  1.0,

  // Variable: waTheta
  //  Referenced by: '<S9>/Pitch Wave'

  1.0,

  // Variable: waX
  //  Referenced by: '<S9>/X Wave'

  1.0,

  // Variable: waY
  //  Referenced by: '<S9>/Y Wave'

  2.0,

  // Variable: waZ
  //  Referenced by: '<S9>/Z Wave'

  3.0,

  // Variable: wfPhi
  //  Referenced by: '<S9>/Roll Wave'

  1.5707963267948966,

  // Variable: wfPsi
  //  Referenced by: '<S9>/Yaw Wave'

  1.5707963267948966,

  // Variable: wfTheta
  //  Referenced by: '<S9>/Pitch Wave'

  1.5707963267948966,

  // Variable: wfX
  //  Referenced by: '<S9>/X Wave'

  1.5707963267948966,

  // Variable: wfY
  //  Referenced by: '<S9>/Y Wave'

  1.5707963267948966,

  // Variable: wfZ
  //  Referenced by: '<S9>/Z Wave'

  1.5707963267948966,

  // Variable: wpPhi
  //  Referenced by: '<S9>/Roll Wave'

  0.0,

  // Variable: wpPsi
  //  Referenced by: '<S9>/Yaw Wave'

  3.1415926535897931,

  // Variable: wpTheta
  //  Referenced by: '<S9>/Pitch Wave'

  1.5707963267948966,

  // Variable: wpX
  //  Referenced by: '<S9>/X Wave'

  0.0,

  // Variable: wpY
  //  Referenced by: '<S9>/Y Wave'

  1.5707963267948966,

  // Variable: wpZ
  //  Referenced by: '<S9>/Z Wave'

  3.1415926535897931,

  // Variable: PWM
  //  Referenced by:
  //    '<S5>/N to PWM'
  //    '<S10>/N to PWM'

  { 1100U, 1104U, 1108U, 1112U, 1116U, 1120U, 1124U, 1128U, 1132U, 1136U, 1140U,
    1144U, 1148U, 1152U, 1156U, 1160U, 1164U, 1168U, 1172U, 1176U, 1180U, 1184U,
    1188U, 1192U, 1196U, 1200U, 1204U, 1208U, 1212U, 1216U, 1220U, 1224U, 1228U,
    1232U, 1236U, 1240U, 1244U, 1248U, 1252U, 1256U, 1260U, 1264U, 1268U, 1272U,
    1276U, 1280U, 1284U, 1288U, 1292U, 1296U, 1300U, 1304U, 1308U, 1312U, 1316U,
    1320U, 1324U, 1328U, 1332U, 1336U, 1340U, 1344U, 1348U, 1352U, 1356U, 1360U,
    1364U, 1368U, 1372U, 1376U, 1380U, 1384U, 1388U, 1392U, 1396U, 1400U, 1404U,
    1408U, 1412U, 1416U, 1420U, 1424U, 1428U, 1432U, 1436U, 1440U, 1444U, 1448U,
    1452U, 1456U, 1460U, 1464U, 1468U, 1472U, 1476U, 1480U, 1484U, 1488U, 1492U,
    1496U, 1500U, 1504U, 1508U, 1512U, 1516U, 1520U, 1524U, 1528U, 1532U, 1536U,
    1540U, 1544U, 1548U, 1552U, 1556U, 1560U, 1564U, 1568U, 1572U, 1576U, 1580U,
    1584U, 1588U, 1592U, 1596U, 1600U, 1604U, 1608U, 1612U, 1616U, 1620U, 1624U,
    1628U, 1632U, 1636U, 1640U, 1644U, 1648U, 1652U, 1656U, 1660U, 1664U, 1668U,
    1672U, 1676U, 1680U, 1684U, 1688U, 1692U, 1696U, 1700U, 1704U, 1708U, 1712U,
    1716U, 1720U, 1724U, 1728U, 1732U, 1736U, 1740U, 1744U, 1748U, 1752U, 1756U,
    1760U, 1764U, 1768U, 1772U, 1776U, 1780U, 1784U, 1788U, 1792U, 1796U, 1800U,
    1804U, 1808U, 1812U, 1816U, 1820U, 1824U, 1828U, 1832U, 1836U, 1840U, 1844U,
    1848U, 1852U, 1856U, 1860U, 1864U, 1868U, 1872U, 1876U, 1880U, 1884U, 1888U,
    1892U, 1896U, 1900U },

  // Mask Parameter: BandLimitedWhiteNoise_Cov
  //  Referenced by: '<S21>/Output'

  2.5E-10,

  // Mask Parameter: BandLimitedWhiteNoise1_Cov
  //  Referenced by: '<S22>/Output'

  4.0E-10,

  // Mask Parameter: BandLimitedWhiteNoise_seed
  //  Referenced by: '<S21>/White Noise'

  23341.0,

  // Mask Parameter: BandLimitedWhiteNoise1_seed
  //  Referenced by: '<S22>/White Noise'

  23341.0,

  // Computed Parameter: Constant_Value
  //  Referenced by: '<S23>/Constant'

  {
    {
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U,
      0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U, 0U }
    ,                                  // Pwm

    {
      0U,                              // CurrentLength
      0U                               // ReceivedLength
    }                                  // Pwm_SL_Info
  },

  // Expression: zeros(1,8)
  //  Referenced by: '<S5>/Constant1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 1
  //  Referenced by: '<S66>/Constant'

  1.0,

  // Expression: 1
  //  Referenced by: '<S67>/Constant'

  1.0,

  // Expression: [0,0,0]
  //  Referenced by: '<S1>/Initial Body velocity '

  { 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S21>/White Noise'

  0.0,

  // Computed Parameter: WhiteNoise_StdDev
  //  Referenced by: '<S21>/White Noise'

  1.0,

  // Expression: [1,0,0,0]
  //  Referenced by: '<Root>/Constant1'

  { 1.0, 0.0, 0.0, 0.0 },

  // Expression: 0.5
  //  Referenced by: '<S57>/Constant'

  0.5,

  // Expression: 2
  //  Referenced by: '<S57>/Gain2'

  2.0,

  // Expression: 2
  //  Referenced by: '<S57>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S57>/Gain1'

  2.0,

  // Expression: 2
  //  Referenced by: '<S58>/Gain'

  2.0,

  // Expression: 0.5
  //  Referenced by: '<S58>/Constant'

  0.5,

  // Expression: 2
  //  Referenced by: '<S58>/Gain2'

  2.0,

  // Expression: 2
  //  Referenced by: '<S58>/Gain1'

  2.0,

  // Expression: 2
  //  Referenced by: '<S59>/Gain'

  2.0,

  // Expression: 2
  //  Referenced by: '<S59>/Gain1'

  2.0,

  // Expression: 0.5
  //  Referenced by: '<S59>/Constant'

  0.5,

  // Expression: 2
  //  Referenced by: '<S59>/Gain2'

  2.0,

  // Computed Parameter: DiscreteTimeIntegrator_gainval
  //  Referenced by: '<S6>/Discrete-Time Integrator'

  0.0025,

  // Expression: 0
  //  Referenced by: '<S6>/Discrete-Time Integrator'

  0.0,

  // Expression: 1
  //  Referenced by: '<S6>/Gain1'

  1.0,

  // Expression: 0
  //  Referenced by: '<S22>/White Noise'

  0.0,

  // Computed Parameter: WhiteNoise_StdDev_f
  //  Referenced by: '<S22>/White Noise'

  1.0,

  // Expression: [0,0,0]
  //  Referenced by: '<S1>/Initial Angular Rates'

  { 0.0, 0.0, 0.0 },

  // Expression: [0,0,0,0,0,0,0,0].'
  //  Referenced by: '<S26>/Memory1'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(1,1)
  //  Referenced by: '<S28>/md_zero'

  0.0,

  // Expression: zeros(8,1)
  //  Referenced by: '<S28>/mv.target_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(13,1)
  //  Referenced by: '<S28>/y.min_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(13,1)
  //  Referenced by: '<S28>/y.max_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(8,1)
  //  Referenced by: '<S28>/dmv.min_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(8,1)
  //  Referenced by: '<S28>/dmv.max_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(13,1)
  //  Referenced by: '<S28>/x.min_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(13,1)
  //  Referenced by: '<S28>/x.max_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(13,1)
  //  Referenced by: '<S28>/y.wt_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(8,1)
  //  Referenced by: '<S28>/mv.wt_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(8,1)
  //  Referenced by: '<S28>/dmv.wt_zero'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: zeros(1,1)
  //  Referenced by: '<S28>/ecr.wt_zero'

  0.0,

  // Expression: zeros(1,1)
  //  Referenced by: '<S28>/params_zero'

  0.0,

  // Expression: zeros(1,8)
  //  Referenced by: '<S26>/Constant2'

  { 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: [0,0,0.2272,1,0,0,0,0,0,0,0,0,0]
  //  Referenced by: '<S26>/Constant1'

  { 0.0, 0.0, 0.2272, 1.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0, 0.0 },

  // Expression: 0
  //  Referenced by: '<S26>/Zero'

  0.0,

  // Expression: 1
  //  Referenced by: '<S5>/Constant'

  1.0,

  // Computed Parameter: TransferFcn_A
  //  Referenced by: '<S13>/Transfer Fcn'

  -6.666666666666667,

  // Computed Parameter: TransferFcn_C
  //  Referenced by: '<S13>/Transfer Fcn'

  6.666666666666667,

  // Computed Parameter: TransferFcn_A_h
  //  Referenced by: '<S14>/Transfer Fcn'

  -6.666666666666667,

  // Computed Parameter: TransferFcn_C_m
  //  Referenced by: '<S14>/Transfer Fcn'

  6.666666666666667,

  // Computed Parameter: TransferFcn_A_k
  //  Referenced by: '<S15>/Transfer Fcn'

  -6.666666666666667,

  // Computed Parameter: TransferFcn_C_a
  //  Referenced by: '<S15>/Transfer Fcn'

  6.666666666666667,

  // Computed Parameter: TransferFcn_A_j
  //  Referenced by: '<S16>/Transfer Fcn'

  -6.666666666666667,

  // Computed Parameter: TransferFcn_C_j
  //  Referenced by: '<S16>/Transfer Fcn'

  6.666666666666667,

  // Computed Parameter: TransferFcn_A_n
  //  Referenced by: '<S17>/Transfer Fcn'

  -6.666666666666667,

  // Computed Parameter: TransferFcn_C_d
  //  Referenced by: '<S17>/Transfer Fcn'

  6.666666666666667,

  // Computed Parameter: TransferFcn_A_l
  //  Referenced by: '<S18>/Transfer Fcn'

  -6.666666666666667,

  // Computed Parameter: TransferFcn_C_k
  //  Referenced by: '<S18>/Transfer Fcn'

  6.666666666666667,

  // Computed Parameter: TransferFcn_A_j1
  //  Referenced by: '<S19>/Transfer Fcn'

  -6.666666666666667,

  // Computed Parameter: TransferFcn_C_g
  //  Referenced by: '<S19>/Transfer Fcn'

  6.666666666666667,

  // Computed Parameter: TransferFcn_A_d
  //  Referenced by: '<S20>/Transfer Fcn'

  -6.666666666666667,

  // Computed Parameter: TransferFcn_C_c
  //  Referenced by: '<S20>/Transfer Fcn'

  6.666666666666667,

  // Expression: 0
  //  Referenced by: '<S9>/Z Drift'

  0.0,

  // Expression: 0
  //  Referenced by: '<S9>/X Wave'

  0.0,

  // Expression: 0
  //  Referenced by: '<S9>/Y Wave'

  0.0,

  // Expression: 0
  //  Referenced by: '<S9>/Z Wave'

  0.0,

  // Expression: 0
  //  Referenced by: '<S9>/Roll Wave'

  0.0,

  // Expression: 0
  //  Referenced by: '<S9>/Pitch Wave'

  0.0,

  // Expression: 0
  //  Referenced by: '<S9>/Yaw Wave'

  0.0,

  // Expression: [0,0,.2272]
  //  Referenced by: '<Root>/Constant'

  { 0.0, 0.0, 0.2272 }
};

//
// File trailer for generated code.
//
// [EOF]
//
