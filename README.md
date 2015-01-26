# README
---------------

* LAST UPDATED: 2015-01-26
* TEAM: labprentice
* REPO: stash (private)

## Contents
--------------------
### data/
This directory holds a script for producing input data for the STASH 2.0 code.

* __stash_getdata.py__
    * Script that produces a CSV with daily input data (i.e., sunshine fraction, air temperature, and precipitation)
* __example_data.csv__
    * Example daily data for San Francisco, United States (37.7 N, 122.4 W, 142 m, 2000 CE)

### doc/
This directory holds the current documentation for the STASH 2.0 code.

* __stash_doc.pdf__
    * The current PDF build of the documentation
* __stash_doc.tex__
    * The main LaTeX document file
* __stash.bib__
    * The BibLatex file for documentation references
* __img/__
    * Contains the EPS figures for the documentation
* __tex/__
    * Contains the modular LaTeX chapter files (and appendix)

### f90_version/
This directory holds the FORTRAN90 version of the STASH 2.0 code. 

* __Makefile__ 
    * Use to compile the stash.F script.

* __stash.F__ 
    * TBA.

### py_version/
This directory holds the Python version of the STASH 2.0 code. 

* __stash.py__ 
    * Implements the EVAP class for point-based processing 
    * Inputs include:
        * latitude, degrees
        * day of year
        * elevation (optional), meters
        * year (optional)
        * sunshine fraction (optional), decimal
        * mean daily air temperature (optional), °C
        * evaporative supply rate (optional), mm/h
    * Input data must be imported separately by user (example data is available in the script).

* __stash_grid.py__ 
    * Implements the EVAP_G class for grid-based processing 
    * Inputs include:
        * day of year
        * elevation (360x720 array), meters
        * sunshine fraction (360x720 array), decimal
        * mean daily air temperature (360x720 array), °C
        * evaporative supply rate (360x720 array), mm/h
        * year (optional)
    * CRU-based input data is used (user must have a copy of data files and specify their location)

### r_version/
This directory holds the R version of the STASH 2.0 code. 

* __stash.R__ 
    * Implements the EVAP function for point-based processing 
    * Inputs include:
        * latitude, degrees
        * day of year
        * elevation (optional), meters
        * year (optional)
        * sunshine fraction (optional), decimal
        * mean daily air temperature (optional), °C
        * evaporative supply rate (optional), mm/h
    * Input data must be imported separately by user (example data is available in the script)
    * Includes plotting examples of monthly and daily results


## STASH 2.0: Evapotranspiration and Radiation Module
----------------------------------------------------------------------------
This work aims to model monthly global radiation, evaporation, and soil moisture quantities and indexes using simple but theoretically-based simulation. The methodology follows the pseudo-code presented by Cramer & Prentice (1988).

### Key Outputs
* monthly photosynthetic photon flux density (PPFD), mol/m^2
* monthly equilibrium evapotranspiration (EET), mm
* monthly potential evapotranspiration (PET), mm
* monthly Cramer-Prentice bioclimatic moisture index, α (CPA), unitless
* monthly climatic water deficit (ΔE), mm

### Model Inputs
For radiation, the basic geographic coordinates and time parameters needed are:

* year (y)
* month (m)
* day of month (i)
* longitude (θlon), degrees
* latitude (φ), degrees
* elevation (z), meters

For evapotranspiration, the basic meteorological variables needed are:

* mean daily air temperature (Tc), °C
* daily precipitation (Pn), mm
* fraction of sunshine hours (Sf), %

For spatial analyses, the 0.5° x 0.5° gridded [CRU TS 3.21](http://badc.nerc.ac.uk/view/badc.nerc.ac.uk__ATOM__ACTIVITY_0c08abfc-f2d5-11e2-a948-00163e251233) data sets may be used, for example: TMP (monthly mean daily air temperature); PRE (monthly precipitation totals); CLD (cloudiness fraction); and CRU TS 3.0 ELV (mean pixel elevation).

### Theory
The model theory is as follows:

1. Estimate the evaporative supply rate (Sw)
2. Calculate (or estimate) the heliocentric longitudes (ν and λ)
3. Calculate (or estimate) the distance factor (dr)
4. Calculate (or estimate) the declination angle (δ)
5. Calculate the sunset angle (Hs)
6. Calculate daily extraterrestrial solar radiation flux (RDa)
7. Estimate transmittivity (τ) 
8. Calculate daily photosynthetic photon flux density (PPFDD)
9. Estimate net longwave radiation flux (Rnl)
10. Calculate net radiation cross-over hour angle (Hn)
11. Calculate daytime net radiation (RDn)
12. Calculate nighttime net radiation (RDnn) 
13. Calculate energy conversion factor (Econ)
14. Estimate daily condensation (Wc)
15. Estimate daily equilibrium evapotranspiration (EETD)
16. Estimate daily potential evapotranspiration (PETD)
17. Calculate the intersection hour angle (Hi) 
18. Estimate daily actual evapotranspiration (AETD)
19. Update daily soil moisture (Wn) 

## References
--------------------
* Cramer, W. and I. C. Prentice (1988) Simulation of regional soil moisture deficits on a European scale, _Norsk Geografisk Tidsskrift - Norwegian Journal of Geography_, 42:2-3, pp. 149-151.