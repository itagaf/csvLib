#ifndef CSVLIB_H
#define CSVLIB_H

#include <string>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <vector>
#include <map>
#include <any>

using std::string;

typedef std::vector<std::vector<double>> mat;


struct Prefs
{
	int _set_nCols = -1;
	bool _row_index;
	bool _has_header = false;
};


class CSV_IN
{
private:
	Prefs _pref;
	int _nCols = -1;
	int _nRows = -1;
	char _sep;
	std::string _inPath;
public:

	CSV_IN();
	

	CSV_IN(const string& input_path, char sep = ',');
	
private:
	int read_csv();

public:
	void countCols(std::ifstream& inFile, char sep = ',');

	void set_pref(int cols, bool row_index, bool has_header);

	Prefs* set_pref();

	mat absorb_to_mat();

};


#endif // !CSVLIB_H
