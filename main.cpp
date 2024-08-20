#include <iostream>
#include <cstdlib>
#include <cstring>

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

int calcD(int fn, int e, int d)
{
    long int k = 1;
    while(1)
    {
        k = k + fn;
        if (k % e == 0)
        {
            return (k / e);
        }
    }
}

int calcE(int fn, int e, int p, int q, int d)
{
    long int flag;
    for(int i = 2; i < fn; i++)
    {
        if (fn % i == 0) continue;

        if (checkPrimeNumber(i) && i != p && i != q)
        {
            e = i;
            flag = calcD(fn, e, d);
            if (flag > 0)
            {
                d = flag;
                break;
            }
        }
    }
    return e;
}

int main(void)
{
    long int p, q, n, fn, e, d, m, c;
    int i;

    char oMSG[100], eMSG[100], dMSG[100];

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

    e = calcE(fn, e, p, q, d);

    cout << "Input message: ";
    cin >> oMSG;

    for(i = 0; oMSG[i] != '\0'; i++)
    {
        m = oMSG[i];
        long int k = 1;
        for(int j = 0; j < e; j++)
        {
            k = k * m;
            k = k % n;
        }
        c = k;
        eMSG[i] = c;
    }

    cout << "Encrypted: ";
    for(int i = 0; i < strlen(eMSG); i++)
    {
        cout << eMSG[i];
    }

    cout << endl << "public key - " << "{" << e << ", " << n << "}\n";
    cout << "private key - " << "{" << d << ", " << n << "}";
}


