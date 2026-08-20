#include "calendar.h"

#include <string.h>
#include <strings.h>
#include <string>
#include <vector>
#include "algorithm.hpp"


using namespace dynsocc;
using namespace std;

string Calendar::azWeekday[7] = { "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday" };
int Calendar::azYearDay[2] = { 365, 366 };
int Calendar::azMonthSize[2][13] = { 
    { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }, 
    { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

// Month  by Day of Year
int Calendar::azMonthByDoY[2][13] = {
    { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365 },
    { 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366 }
};

int rotate_fw_weekday(int nWeekday) {
    nWeekday++;

    if (nWeekday == 7) {
        nWeekday = 0;
    }
    return nWeekday;
}

int rotate_bw_weekday(int nWeekday) {
    nWeekday--;

    if (nWeekday < 0) {
        nWeekday = 6;
    }
    return nWeekday;
}

Calendar::Calendar() {
    yearcount = 0;
}

int Calendar::Copy54Int(int* pdest, int* psource) {
    memcpy(pdest, psource, sizeof(int)*54);
    return 0;
}

int Calendar::printint2D(/*int[][54] a*/) {
    return 0;
}

int Calendar::build_solar_years(int year, int month, int day, const char* day_of_week) {
    /*============================================================
     * 
     *============================================================*/

    /*============================================================
     *  API1. Year/Month/Day => Weekday
     *  API2. The Next Weekday StartingFrom Year/Month/Day
     *  API3. The Nth-Next Weekday StartingFrom Year/Month/Day
     *============================================================*/

    // API1. 
    /* One Solar calndar Year */
    

    /*------------------------------
        BuildOneYear (BOY)
        BOY1. 
            AnchorDay 
        BOY2. 
            AnchorDay++ => EndYear
        BOY3. 
            AnchorDay-- => BeginningOfYear

        Output:
            weekr[54]

        BOY4. 
            WeekID = ceil(DayOfYear / 7)
     *------------------------------*/

    int doy = date_to_dayofyear(year, month, day); // Day of Year
    int wdy = Weekday(day_of_week);
    int doy_sd = doy + (6 - wdy); // This Sunday 
    int doy_1sd;  // The first sunday in year
    int yweekr[54];  // yweekr[3] = 21 <=> The end of week 3 is the 21-th day of year
    int nweek = 0;
    int nLeap = (year % 4 == 0);



    if (doy_sd > azYearDay[nLeap]) { 
        doy_sd -= 7; 
    }

    doy_1sd = doy_sd % 7;  // The 1st Sunday
    if (doy_1sd == 0) {
        doy_1sd = 7;
    }

    printf("%d;%d;%d;%d\r\n", doy, wdy, nLeap, doy_1sd);

    int i = doy_1sd;
    int j = 1;

    while (i < azYearDay[nLeap]) {
        yweekr[j++] = i;
        i += 7;
    }
    nweek = j-1;

    /* One year ago */
    int yweekr_1[54]; // One year ago
    int nweek1 = 0;
    int nLeap1 = ((year-1) % 4 == 0);

    int doy_sd1 =(yweekr[1] + azYearDay[nLeap1] - 7); // First sunday - 7 day = Last Sunday of The Previous year 
    int doy_1sd1 = doy_sd1 % 7;

    if (doy_1sd1 == 0) {
        doy_1sd1 = 7;
    }

    printf("%d;%d;%d;\r\n", doy_sd1, doy_1sd1, nLeap1);


    i = doy_1sd1;
    j = 1;
    while ( i < azYearDay[nLeap1]) {
        yweekr_1[j++] = i;
        i += 7;
    }
    nweek1 = j-1;

    // Print 
    printf("Year: %d. nweek=%d\r\n", year, nweek);
    for (i = 1; i<= nweek; i++ ) {
        printf("%d;", yweekr[i]);
    }
    printf("\r\n");
    printf("Year: %d. nweek=%d\r\n", year-1, nweek1);
    for (i = 1; i<= nweek1; i++ ) {
        printf("%d;", yweekr_1[i]);
    }
    printf("\r\n");

    // Skip
    /*
    algorithm::put_map<int, int*>(  
        year,   // Key
        yweekr, // Value int* 
        yearl,  // Map Key
        year_weekr,  // Map Vaue   year_week[4] = int[54]*
        Copy54Int,    
        yearcount);
    */

    int iwd;
    string str1 = weekday_of_date(2025, 9, 02, yweekr_1, nweek1, iwd);
    doy = date_to_dayofyear(2025, 9, 2);
    doy_sd = doy + (6 - iwd);
    printf("Weekday = %s\r\n", str1.c_str());


    year = 2025;
    nLeap = (year % 4) == 0;
    int month1;
    int day1;
    for (i=1; i <= 24; i++) {
        dayofyear_to_date(doy_sd, year, month1, day1);

        printf("sunday[%d]=%04d/%02d/%02d\r\n", i, year, month1, day1);

        doy_sd += 7;
        if (doy_sd > azYearDay[nLeap]) {
            doy_sd -= azYearDay[nLeap];
            year++;
        }
    }


    // int dow = Weekday(weekday);
    // int doy = date_to_dayofyear(year, month, day);
    return 0;
}

int Calendar::Weekday(const char* weekday) {

    int nFound = -1;
    for (int i=0; i<7; i++) {
        if (strcasecmp(azWeekday[i].c_str(), weekday) == 0) {
            nFound = i;
            break;
        }
    }

    return nFound;
}

int Calendar::date_to_dayofyear(int year, int month, int day) {
    int nLeap = (year % 4 == 0);

    return azMonthByDoY[nLeap][month-1] + day; // End of Last Month + day
}

int Calendar::dayofyear_to_date(int doy, int year, int &month, int & day) {
    int nLeap = (year % 4 == 0);
    if (doy > azMonthByDoY[nLeap][12]) {
        return -1;
    }

    month = 1;
    while (month <= 12 && azMonthByDoY[nLeap][month] < doy) {
        month++;
    }

    day = doy - azMonthByDoY[nLeap][month-1];

    return 0;
}

int Calendar::weeknumber(int dayofyear, int* yweeked, int nWeek) {

    /* 
        yweeked[] { 0, 3, 10, 17, ... }
     */

    int i = 1;
    int iW = -1;
    while ( i < nWeek) {
        if (yweeked[i-1] < dayofyear && yweeked[i] >= dayofyear) {
            iW = i;
            break;
        }
        i++;
    }

    return iW;
}


std::string Calendar::weekday_of_date(int year, int month, int day, int* yweeked, int nWeek, int& wdid) {

    int i = 0;
    int j = 0;

    int doy = date_to_dayofyear(year, month, day);

    int weeknum = weeknumber(doy, yweeked, nWeek);

    int isun = yweeked[weeknum]; // Sunday Index
    int ibegin = yweeked[weeknum-1] + 1;
    
    /*------------------------------
        weeknum=1 (The firstweek)
            => The end of week  is Sunday
                (yweek[weeknum])
        weeknum=nWeek (The last week)
            => The beginning of week is Monday
                (yweek[weenum-1] + 1)
        weeknum in [2,nWeek-1] (Middle week)
            => The beginning of the week is Monday
                The end of the week is Sunday
     *------------------------------*/
    int iwd = (doy - yweeked[weeknum-1] - 1);  // Index-weekday

    if (weeknum == 1) {
        iwd = 6 /* sunday */ - (yweeked[weeknum] - doy);
    }
    else {
        iwd = 0 /* Monday */ + (doy - yweeked[weeknum-1] - 1);
    }
    
    wdid = iwd;
    return azWeekday[iwd];
}