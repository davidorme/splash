#include <string>
#include <vector>

using namespace std;

/* \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
 * DATA.h
 * 
 * written by Tyler W. Davis
 * Imperial College London
 * 
 * 2015-02-08 -- created
 * 2015-02-08 -- last updated
 * 
 * ------------
 * description:
 * ------------
 * This is the header file for the DATA C++ class.
 * 
 * //////////////////////////////////////////////////////////////////////// */

class DATA {
    private:
        // Variables:
        string file_name;
        int num_lines;                  // number of lines read from file
        vector<double> sf_vec;          // sun hours fraction
        vector<double> tair_vec;        // air temperature, deg C
        vector<double> pn_vec;          // precipitation, mm
        
        // Functions:
        int count_lines(string fname);
        bool inValidDouble(string mystring);
    
    public:
        // Constructors:
        DATA(string fname);
        
        // Functions:
        vector<double> get_all_sf();
        vector<double> get_all_tair();
        vector<double> get_all_pn();
        double get_one_sf(int n);
        double get_one_tair(int n);
        double get_one_pn(int n);
        int nlines();
};