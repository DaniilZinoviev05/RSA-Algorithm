#include <iostream>
#include <cstdlib>

#ifdef _WIN32
    #define CLEAR "cls"
#else
    #define CLEAR "clear"
#endif

using namespace std;

bool checkPrimeNumber(int num)
{
    for(int i = 2; i <= (num/2); i++)
    {
        if (num % i == 0)
        {
            system(CLEAR);
            return false;
        }
    }
    return true;
}

int calcE(int fn, int e, int p, int q)
{
    for(int i = 2; i < fn; i++)
    {
        if (fn % i == 0) continue;

        if (checkPrimeNumber(i) && i != p && i != q)
        {
            e = i;
        }
    }
    return e;
}

int main(void)
{
    int p, q, n, fn, e;

    char oMSG, eMSG, dMSG;

    while(true)
    {
        cout << "Input p: ";
        cin >> p;
        if (checkPrimeNumber(p))
        {
            break;
        }
        else
        {
            cout << p << " is not prime number" << endl;
        }
    }

    while(true)
    {
        cout << "Input q: ";
        cin >> q;
        if (checkPrimeNumber(q))
        {
            break;
        }
        else
        {
            cout << q << " is not prime number" << endl;
        }
    }

    n = p * q;
    fn = (p - 1) * (q - 1);

    e = calcE(fn, e, p, q);
}


