#include "Lab2.h"

namespace lab2
{
    void PrintIntegers(std::istream& in, std::ostream& out)
    {
        out << setw(12) << "oct" << setw(11) << "dec" << setw(9) << "hex" << endl;
        out << setw(13) << setfill('-') << " " << setw(11) << " " << setw(8) << "-" << setfill(' ') << endl;
        
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
            else if (bCheckPrint)
            {
                str[cnt] = '\0';
                int outValue = atoi(str);
                out << setw(12) << oct << outValue << setw(11) << dec << outValue << setw(9) << hex << uppercase << outValue << endl;
            
                cnt = 0;
                memset(str, '\0', BUFSIZ);
                bCheckPrint = false;
            }
        }
        if (cnt != 0)
        {
            str[cnt] = '\0';
            int outValue = atoi(str);
            out << setw(12) << oct << outValue << setw(11) << dec << outValue << setw(9) << hex << uppercase << outValue << endl;
        }
    }

    void PrintMaxFloat(std::istream & in, std::ostream & out)
    {
        int strCnt = 0;
        int arrayCnt = 0;
        char str[BUFSIZ];
        bool bCheckPrint = false;
        char c;
        float inputVal[BUFSIZ];

        while (in.get(c))
        {
            if (IsFloat(c))
            {
                str[strCnt++] = c;
                bCheckPrint = true;
            }
            else if (bCheckPrint)
            {
                str[strCnt] = '\0';
                float outVal = atof(str);
                inputVal[arrayCnt++] = outVal;

                out << setw(5) << " " << setw(15) << internal << showpos << fixed << setprecision(3) << outVal << endl;

                strCnt = 0;
                memset(str, '\0', BUFSIZ);
                bCheckPrint = false;
            }
        }
        if (strCnt != 0)
        {
            str[strCnt] = '\0';
            float outVal = atof(str);
            inputVal[arrayCnt++] = outVal;

            out << setw(5) << " " << setw(15) << internal << showpos << fixed << setprecision(3) << outVal << endl;
        }

        out << "max: " << setw(15) << internal << showpos << fixed << setprecision(3) << GetMaxVal(inputVal, arrayCnt) << endl;
    }

    bool IsInteger(const char c)
    {
        int val = static_cast<int>(c);
        if ((val >= 48 && val <= 57) || val == 45)
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

        if ((val >= 48 && val <= 57) || val == 46 || val == 45)
        {
            return true;
        }
        else
        {
            return false;
        }
        return bReturnVal;
    }

    float GetMaxVal(float val[], int cnt)
    {
        float returnVal = val[0];

        for (int i = 0; i < cnt - 1; i++)
        {
            if (val[i] < val[i + 1])
                returnVal = val[i + 1];
        }
        return returnVal;
    }
}