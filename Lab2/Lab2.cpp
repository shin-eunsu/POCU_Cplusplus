#include "Lab2.h"

namespace lab2
{
    void PrintIntegers(std::istream& in, std::ostream& out)
    {
        out << setw(12) << "oct" << setw(11) << "dec" << setw(9) << "hex" << endl;
        out << setw(13) << setfill('-') << " " << setw(11) << " " << setw(8) << "-" << setfill(' ');
                
        int cnt = 0;
        char str[BUFSIZ];
        bool bCheckPrint = false;
        char c;
        while (in.get(c))
        {            
            if (IsInteger(c))
            {
                str[cnt++] = c;
                bCheckPrint = true;
            }
            else if(bCheckPrint)
            {
                str[cnt] = '\0';
                int outValue = atoi(str);
                out << endl << setw(12) << oct << outValue << setw(11) << dec << outValue << setw(9) << hex << uppercase << outValue ;
                
                cnt = 0;
                memset(str, '\0', BUFSIZ);
                bCheckPrint = false;
            }
        }
        if (cnt != 0)
        {
            str[cnt] = '\0';
            int outValue = atoi(str);
            out << endl <<setw(12) << oct << outValue << setw(11) << dec << outValue << setw(9) << hex << uppercase << outValue;
        }
    }

    void PrintMaxFloat(std::istream& in, std::ostream& out)
    {        
    }

    bool IsInteger(const char c)
    {
        int val = static_cast<int>(c);
        if (val >= 48 && val <= 57)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool IsFloat(const char c)
    {
        bool bReturnVal = false;
        bool bDot = false;
        int val = static_cast<int>(c);

        if (val >= 48 && val <= 57 || val == 46)
        {
            return true;
        }
        else
        {
        }

        return bReturnVal;
    }
}