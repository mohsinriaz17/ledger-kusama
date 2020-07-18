/*******************************************************************************
*   (c) 2018 Zondax GmbH
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
********************************************************************************/
#include "zxmacros.h"
#include "timeutils.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stddef.h>

const uint8_t monthDays[] = {
        31,
        28,
        31,
        30,
        31,
        30,
        31,
        31,
        30,
        31,
        30,
        31
};

const uint32_t yearLookup[] = {
        0,
        365,
        730,
        1096,
        1461,
        1826,
        2191,
        2557,
        2922,
        3287,
        3652,
        4018,
        4383,
        4748,
        5113,
        5479,
        5844,
        6209,
        6574,
        6940,
        7305,
        7670,
        8035,
        8401,
        8766,
        9131,
        9496,
        9862,
        10227,
        10592,
        10957,
        11323,
        11688,
        12053,
        12418,
        12784,
        13149,
        13514,
        13879,
        14245,
        14610,
        14975,
        15340,
        15706,
        16071,
        16436,
        16801,
        17167,
        17532,
        17897,
        18262,
        18628,
        18993,
        19358,
        19723,
        20089,
        20454,
        20819,
        21184,
        21550,
        21915,
        22280,
        22645,
        23011,
        23376,
        23741,
        24106,
        24472,
        24837,
        25202,
        25567,
        25933,
        26298,
        26663,
        27028,
        27394,
        27759,
        28124,
        28489,
        28855,
        29220,
        29585,
        29950,
        30316,
        30681,
        31046,
        31411,
        31777,
        32142,
        32507,
        32872,
        33238,
        33603,
        33968,
        34333,
        34699,
        35064,
        35429,
        35794,
        36160,
        36525,
        36890,
        37255,
        37621,
        37986,
        38351,
        38716,
        39082,
        39447,
        39812,
        40177,
        40543,
        40908,
        41273,
        41638,
        42004,
        42369,
        42734,
        43099,
        43465,
        43830,
        44195,
        44560,
        44926,
        45291,
        45656,
        46021,
        46387,
        46752,
        47117,
        47482,
        47847,
        48212,
        48577,
        48942,
        49308,
        49673,
        50038,
        50403,
        50769,
        51134,
        51499,
        51864,
        52230,
        52595,
        52960,
        53325,
        53691,
        54056,
        54421,
        54786,
        55152,
        55517,
        55882,
        56247,
        56613,
        56978,
        57343,
        57708,
        58074,
        58439,
        58804,
        59169,
        59535,
        59900,
        60265,
        60630,
        60996,
        61361,
        61726,
        62091,
        62457,
        62822,
        63187,
        63552,
        63918,
        64283,
        64648,
        65013,
        65379,
        65744,
        66109,
        66474,
        66840,
        67205,
        67570,
        67935,
        68301,
        68666,
        69031,
        69396,
        69762,
        70127,
        70492,
        70857,
        71223,
        71588,
        71953,
        72318,
        72684,
        73049,
        73414,
        73779,
        74145,
        74510,
        74875,
        75240,
        75606,
        75971,
        76336,
        76701,
        77067,
        77432,
        77797,
        78162,
        78528,
        78893,
        79258,
        79623,
        79989,
        80354,
        80719,
        81084,
        81450,
        81815,
        82180,
        82545,
        82911,
        83276,
        83641,
        84006,
        84371,
        84736,
        85101,
        85466,
        85832,
        86197,
        86562,
        86927,
        87293,
        87658,
        88023,
        88388,
        88754,
        89119,
        89484,
        89849,
        90215,
        90580,
        90945,
        91310,
        91676,
        92041,
        92406,
        92771,
        93137,
        93502,
        93867,
        94232,
        94598,
        94963,
        95328,
        95693,
        96059,
        96424,
        96789,
        97154,
        97520,
        97885,
        98250,
        98615,
        98981,
        99346,
        99711,
        100076,
        100442,
        100807,
        101172,
        101537,
        101903,
        102268,
        102633,
        102998,
        103364,
        103729,
        104094,
        104459,
        104825,
        105190,
        105555,
        105920,
        106286,
        106651,
        107016,
        107381,
        107747,
        108112,
        108477,
        108842,
        109208,
        109573,
        109938,
        110303,
        110669,
        111034,
        111399,
        111764,
        112130,
        112495,
        112860,
        113225,
        113591,
        113956,
        114321,
        114686,
        115052,
        115417,
        115782,
        116147,
        116513,
        116878,
        117243,
        117608,
        117974,
        118339,
        118704,
        119069,
        119435,
        119800,
        120165,
        120530,
        120895,
        121260,
        121625,
        121990,
        122356,
        122721,
        123086,
        123451,
        123817,
        124182,
        124547,
        124912,
        125278,
        125643,
        126008,
        126373,
        126739,
        127104,
        127469,
        127834,
        128200,
        128565,
        128930,
        129295,
        129661,
        130026,
        130391,
        130756,
        131122,
        131487,
        131852,
        132217,
        132583,
        132948,
        133313,
        133678,
        134044,
        134409,
        134774,
        135139,
        135505,
        135870,
        136235,
        136600,
        136966,
        137331,
        137696,
        138061,
        138427,
        138792,
        139157,
        139522,
        139888,
        140253,
        140618,
        140983,
        141349,
        141714,
        142079,
        142444,
        142810,
        143175,
        143540,
        143905,
        144271,
        144636,
        145001,
        145366,
        145732,
};

// ARM does not implement gmtime. This is a simple alternative implementation
// based on section 4.16
// https://pubs.opengroup.org/onlinepubs/9699919799/basedefs/V1_chap04.html
zxerr_t printTime(char *out, uint16_t outLen, uint64_t t) {
    uint8_t tm_sec = 0;
    uint8_t tm_min = 0;
    uint8_t tm_hour = 0;
    uint16_t tm_day = 0;
    uint8_t tm_mon = 0;
    uint16_t tm_year = 0;

    tm_sec = t % 60;
    t -= tm_sec;
    t /= 60;

    tm_min = t % 60;
    t -= tm_min;
    t /= 60;

    tm_hour = t % 24;
    t -= tm_hour;
    t /= 24;

    // Look up tm_year
    tm_year = 0;
    const uint16_t yearLookupSize = sizeof(yearLookup)/sizeof(yearLookup[0]);
    while (tm_year < yearLookupSize && yearLookup[tm_year] <= t) tm_year++;

    if (tm_year == 0 || tm_year == yearLookupSize) {
        return zxerr_out_of_bounds;
    }
    tm_year--;

    tm_day = t - yearLookup[tm_year] + 1;
    tm_year = 1970 + tm_year;

    // Get day/month
    uint8_t leap = (tm_year % 4 == 0 && (tm_year % 100 != 0 || tm_year % 400 == 0) ? 1 : 0);

    for (tm_mon = 0; tm_mon < 12; tm_mon++) {
        uint8_t tmp = monthDays[tm_mon];
        tmp += (tm_mon == 1 ? leap : 0);
        if (tm_day <= tmp) {
            break;
        }
        tm_day -= tmp;
    }
    tm_mon++;

    const char *monthName = getMonth(tm_mon);

    // YYYYmmdd HH:MM:SS
    snprintf(out, outLen, "%02d%s%04d %02d:%02d:%02dUTC",
             tm_day,
             monthName,
             tm_year,
             tm_hour, tm_min, tm_sec
    );

    return zxerr_ok;
}

#ifdef __cplusplus
}
#endif