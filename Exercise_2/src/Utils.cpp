#include "Utils.hpp"

#include "iostream"
#include "fstream"
#include "sstream"
#include "iomanip"

using namespace std;

bool ImportData(const string& inputFilePath,
                double& S,
                size_t& n,
                double*& w,
                double*& r)
{
    ifstream file;
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    string line;
    if (!file.eof())
    {
        getline(file, line, ';');
        getline(file,line);
    }

    istringstream convertS;
    convertS.str(line);
    convertS >> S;

    if (!file.eof())
    {
        getline(file, line, ';');
        getline(file,line);
    }

    istringstream convertN;
    convertN.str(line);
    convertN >> n;

    getline(file,line);

    w = new double[n];
    r = new double[n];

    for (size_t i = 0; i < n; i++)
    {
        getline(file, line, ';');
        istringstream convertW;
        convertW.str(line);
        convertW >> w[i];

        getline(file, line);
        istringstream convertR;
        convertR.str(line);
        convertR >> r[i];
    }

    file.close();

    return true;
}


double DotProduct(const size_t& n,
                        const double* const& v1,
                        const double* const& v2)
{
    double dotProduct = 0;
    for (unsigned int i = 0; i < n; i++)
        dotProduct += v1[i] * v2[i];
    return dotProduct;
}

void ExportResult(ostream& out,
                const double& S,
                const size_t& n,
                const double* const& w,
                const double* const& r,
                const double& rateOfReturn,
                const double& V)
{
    out << "S = " << fixed << setprecision(2) << S << ", n = " << n << endl;
    out << "w = " << ArrayToString(n, w) << endl;
    out << "r = " << ArrayToString(n, r) << endl;
    out << "Rate of return of the portfolio: " << fixed << setprecision(4) << rateOfReturn << endl;
    out << "V: " << fixed << setprecision(2) << V << endl;
}

string ArrayToString(const size_t& n,
                     const double* const& v)
{
    string str;
    ostringstream toString;
    toString << "[ ";
    for (unsigned int i = 0; i < n; i++)
        toString<< v[i]<< " ";
    toString << "]";

    return toString.str();
}
