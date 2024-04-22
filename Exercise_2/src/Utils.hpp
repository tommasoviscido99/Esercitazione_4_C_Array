#pragma once
#include <iostream>

using namespace std;

bool ImportData(const string& inputFilePath,
                double& S,
                size_t& n,
                double*& w,
                double*& r);

double DotProduct(const size_t& n,
                        const double* const& v1,
                        const double* const& v2);

void ExportResult(ostream& out,
                const double& S,
                const size_t& n,
                const double* const& w,
                const double* const& r,
                const double& rateOfReturn,
                const double& V);

string ArrayToString(const size_t& n,
                     const double* const& v);
