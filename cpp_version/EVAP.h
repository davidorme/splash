#include <vector>
#include "etr.h"

/* \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
 * EVAP.h
 * 
 * 2015-02-07 -- created
 * 2015-08-22 -- last updated
 * 
 * ~~~~~~~~~
 * citation:
 * ~~~~~~~~~
 * T. W. Davis, I. C. Prentice, B. D. Stocker, R. J. Whitley, H. Wang, B. J.
 * Evans, A. V. Gallego-Sala, M. T. Sykes, and W. Cramer, Simple process-led
 * algorithms for simulating habitats (SPLASH): Modelling radiation evapo-
 * transpiration and plant-available moisture, Geoscientific Model Development, 
 * 2015 (in progress)
 * 
 * ~~~~~~~~~~~~
 * description:
 * ~~~~~~~~~~~~
 * This is the C++ header file for the EVAP class.
 * 
 * ~~~~~~~~~~
 * changelog:
 * ~~~~~~~~~~
 * 01. removed kCw and kWm from constants (moved to SPLASH class) [15.02.17]
 * 02. changed get_cn to get_cond [15.02.17]
 * 03. added all necessary inputs from cpp file [15.02.19]
 * 04. created header guard [15.02.19]
 * 05. added etr struct to include list [15.02.19]
 * 06. removed the unnecessary get() functions [15.02.19]
 * 
 * //////////////////////////////////////////////////////////////////////// */
#ifndef EVAP_H
#define EVAP_H
class EVAP {
    private:
        // Constants:
        double kA;       // constant for Rnl
        double kalb_sw;  // shortwave albedo
        double kalb_vis; // visible light albedo
        double kb;       // constant for Rnl
        double kc;       // cloudy transmittivity
        double kd;       // angular coefficient of transmittivity
        double ke;       // eccentricity
        double keps;     // obliquity, degrees 
        double kfFEC;    // from flux to energy conversion, umol/J 
        double kG;       // gravitational acceleration, m/s^2 
        double kGsc;     // solar constant, W/m^2 
        double kL;       // temperature lapse rate, K/m 
        double kMa;      // molecular weight of dry air, kg/mol 
        double kMv;      // molecular weight of water vapor, kg/mol 
        double kPo;      // standard atmosphere, Pa 
        double kR;       // universal gas constant, J/mol/K 
        double kTo;      // base temperature, K 
        double kw;       // entrainment factor
        double komega;   // longitude of perihelion, degrees 
        double kPI;      // pi
        
        // Variables:
        int kN;                    // days in year
        double my_nu;              // true anomaly, degrees
        double my_lambda;          // true longitude, degrees
        double my_rho;             // rel. earth-sun distance
        double dr;                 // distance factor
        double delta;              // declination, degrees
        double ru, rv, rw, rx;     // variable substitutions
        double hs, hn, hi;         // hour angles, degrees
        double ra_d;               // daily solar irradiation, J/m^2
        double tau_o;              // surface transmittivity
        double tau;                // elv. corrected transmittivity
        double ppfd_d;             // daily PPFD, mol/m^2
        double rnl;                // longwave radiation flux, W/m^2
        double rn_d;               // daily net radiation, J/m^2
        double rnn_d;              // daily nighttime net radiation, J/m^2
        double s;                  // slope sat. vap. press. temp. curve, Pa/K
        double lv;                 // enthalpy of vaporization, J/kg
        double pw;                 // density of water, kg/m^3
        double g;                  // psychrometric constant, Pa/K
        double econ;               // water-to-energy conversion, m^3/J
        double cn;                 // daily condensation, mm
        double eet_d, pet_d, aet_d; // daily ET, mm
        double cos_hi;             // cosine of hour angle, hi
        etr d_etr;               // daily etr struct 
        
        // Functions:
        double dcos(double x);
        double dsin(double x);
        std::vector<double> berger_tls(int n);
        int julian_day(int y, int m, int i);
        double sat_slope(double tc);
        double enthalpy_vap(double tc);
        double elv2pres(double z);
        double density_h2o(double tc, double p);
        double psychro(double tc, double p);
    
    public:
        // Constructors
        //EVAP(double lat, int n, double elv);  // default constructor
        //EVAP(double lat, int n, double elv, int y);  // default w/ year
        EVAP(double lat, int n, double elv, int y, double sf, double tc, 
             double sw);
        
        // Get Variable Functions:
        etr get_vals();
        
        // Print variables to screen:
        void display();
};
#endif
