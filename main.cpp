/*

    +-------------------------------------------------+
    |    AMPassword - Password Generator ver 1.0.0    |
    +-------------------------------------------------+
    |           Release Date: 9th Nov 2013            |
    |                                                 |
    |  This software is provided `as-is` and does not |
    |  include any type of warranty.  Misuse of this  |
    |  software is at the risk and liability of the   |
    |  user.  The engineer/author Anthony Musgrove    |
    |  is NOT liable for any misuse of this code. Use |
    |  at own RISK.                                   |
    |                                                 |
    +-------------------------------------------------+
    |  LICENCE                                        |
    +-------------------------------------------------+
    |  This software is licenced under GPLv3, which   |
    |  essentially means that this code can be used   |
    |  for commercial and private use, HOWEVER, this  |
    |  notice MUST remain in tact, and this software  |
    |  MUST be provided FREE-OF-CHARGE.   If you wish |
    |  to distribute this software as part of a       |
    |  ToolKit, you MUST gain authorisation from the  |
    |  author, Anthony Musgrove.  Contact details for |
    |  the author are shown BELOW.                    |
    |                                                 |
    |  If this code is released in ANY software whet- |
    |  her PRIVATE or COMMERCIAL, credit MUST be      |
    |  given to the original author of the software   |
    |  in a PROMINENT location to the users of the    |
    |  software product.  An example of such credit   |
    |  is also SHOWN BELOW.                           |
    +-------------------------------------------------+
    |  CREDIT TO BE DISPLAYED ON END USER PRODUCT:    |
    |                                                 |
    |  This software incorporates a key-generator     |
    |  algorithm developed by Mr Anthony Musgrove     |
    |  Email: me@anthonymusgrove.id.au                |
    |                                                 |
    |  You can download this open-source generator    |
    |  algorithm FREE OF CHARGE, at:                  |
    |                                                 |
    |     http://www.anthonymusgrove.id.au/ampwd      |
    |                                                 |
    +-------------------------------------------------+
    | (C) Anthony Musgrove [me@anthonymusgrove.id.au  |
    +-------------------------------------------------+

*/

#include <iostream>
#include <windows.h>
#include <time.h>

using namespace std;

int main(int argc, char **argv)
{

    // Usage =  ampwd <minchar> <maxchar> <maxlength> [OPTIONAL: <sleep time in ms>]

    char minchar=' ', maxchar = ' ';
    int maxlen=0;

    if(argc < 4)
    { cout << "ampwd> Invalid Parameters." << endl; cout << "ampwd> Usage: ampwd <minchar> <maxchar> <maxlength> [<sleep_between in ms>]" << endl; return(1); }

    if(argv == NULL)
        return(1);

    minchar = (char)*argv[1];
    maxchar = (char)*argv[2];
    maxlen = atoi(argv[3]);

    int sleeptime=0;

    if(argc > 4)
        sleeptime=atoi(argv[4]);

    if(maxchar < minchar)
    {cout << "ampwd> MaxChar needs to be greater than MinChar" << endl; return(1); }

    if(maxlen < 1)
    {cout << "ampwd> MaxLength needs to be greater than zero" << endl; return(1); }

//  full range:
//    char minchar=' ';
//    char maxchar='~';

    if(maxchar < minchar)
    {
        //eventually swap them over.
    }

    long ts_start = time(NULL);
    int total_combinations = 0;
    char initchar=(minchar-1);

    char pwd[maxlen-1];

    int ctr=0;

    for(ctr=0; ctr<maxlen; ctr++)
        pwd[ctr] = initchar;


    bool isDone=FALSE;

    while(!(isDone))
    {

        total_combinations++;

        cout << "Word: ";

        int zctr=0; int mlen=maxlen; bool lRst=FALSE;

        int xctr=0; bool ifnd=FALSE;

        for(xctr=0; xctr<mlen; xctr++)
        {
            if(pwd[xctr] < maxchar)
            { ifnd=FALSE; break; }

            else
            { ifnd=TRUE; }
        }

        isDone=ifnd;

        for(zctr=mlen-1; zctr > -1; zctr--)
        {
            pwd[zctr]++;

            if(lRst==TRUE)
            { pwd[zctr+1]++; lRst=FALSE; }

            else if(pwd[zctr] > maxchar)
            { pwd[zctr]=minchar; pwd[zctr+1]++; }

            else
            { break; }
        }

        if(isDone != TRUE)
        {
            int shw=0;

            for(shw=0; shw < maxlen; shw++)
            {
                if(pwd[shw] != initchar)
                { cout << pwd[shw]; }

                else
                { cout << "ú"; }
            }

            cout << endl;
        }

        Sleep(sleeptime);
    }

    cout << "Combinations Created: " << total_combinations << endl;
    cout << "Time Taken: " << (time(NULL) - ts_start) << " seconds." << endl;
    return(0);
}

