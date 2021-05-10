#include "Lab2.h"

namespace lab2
{    
    void PrintIntegers(std::istream& in, std::ostream& out)
    {
        out << setw(12) << "oct" << setw(11) << "dec" << setw(10) << "hex" << endl;
        out << setw(13) << setfill('-') << "." << setw(11) << "." << setw(10) << "." << setfill(' ');
                
        int cnt = 0;
        char str[BUFSIZ];
        bool checkPrint = false;
        char c;
        while (in.get(c))
        {            
            if (IsInteger(c))
            {
                str[cnt++] = c;
                checkPrint = true;
            }
            else if(checkPrint)
            {
                str[cnt] = '\0';
                int outValue = atoi(str);
                out << endl << setw(12) << oct << outValue << setw(11) << dec << outValue << setw(10) << hex << uppercase << outValue ;
                
                cnt = 0;
                memset(str, '\0', BUFSIZ);
                checkPrint = false;
            }
        }
        if (cnt != 0)
        {
            str[cnt] = '\0';
            int outValue = atoi(str);
            out << endl <<setw(12) << oct << outValue << setw(11) << dec << outValue << setw(10) << hex << outValue;
        }
    }

    void PrintMaxFloat(std::istream& in, std::ostream& out)
    {
        
    }

    bool IsInteger(const char c)
    {
        int val = (int)c;

        //DEC 0~9 : ASCII 48~57
        if (val >= 48 && val <= 57)
            return true;
        else
            return false;
    }
}