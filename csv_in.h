#ifndef CSV_IN_H
#define CSV_IN_H


#include <string>
#include <cstdlib>
#include <cstring>
#include <sstream>
#include <vector>
#include "csvLib.h"



using std::string;

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

public:

	CSV_IN()
	{

	}

	CSV_IN(const string& input_path, char sep = ',')
	{
		read_csv(input_path, sep);
	}

	int read_csv(const string& input_path, char sep);

	void countCols(std::ifstream& inFile, char sep);

	void set_pref(int cols, bool row_index, bool has_header);

	virtual void absorb_data(std::ifstream& inFile, char sep);

};

#endif // !CSV_IN_H