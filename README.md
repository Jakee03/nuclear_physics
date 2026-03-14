To compile this program on a standard Linux/Unix terminal:

g++ -o Assignment3 Main.cpp Detector.cpp Source.cpp

--------------------------------------------------------------------

This program simulates a radioactive source and detector and prints:

Detector Name (e.g Geiger_Counter)
Source ID (e.g 1001 (unique per source))
Source Type (e.g Na-22)
Activity (in Bq/kg)
Detected Counts (2 significant figures)

The counts are randomized using the time as a seed so each rerun of the code will generate a new value for the count (varying 1-10% of the initial activity to represent environmental effects and detector efficiency).

--------------------------------------------------------------------

This program was built by creating a skeleton code for both the RadioactiveSource and RadiationDetector classes. 
Initially only constructors/destructors were present then the getters/setters were added
A static member is used to automate ID generation
High activity sources caused integer overflow so now use long long and double for output
Implimented validation and graceful exits from incorrect inputs (empty strings/negative activity)
Changed from hardcoded variables to an external Sources.txt file

--------------------------------------------------------------------

Sources.txt must follow the following format:

Detector_Name (must be single string)
Source_Name Aqcuisition_Date Activity(scientific notation e.g: 13e14)

There can only be a single detector however new radioactive sources can be added to new lines in the text file.