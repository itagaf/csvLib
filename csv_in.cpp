#include "csvLib.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdio>
#include <cerrno>
#include <cstdlib>
#include <cstring>

using std::string;


CSV_IN::CSV_IN(const string& input_path, char sep): _inPath(input_path), _sep(sep)
{
	read_csv();
}

void CSV_IN::set_pref(int cols, bool row_index, bool has_header)
{
	_pref._set_nCols = cols;
	_pref._row_index = row_index;
	_pref._has_header = has_header;
}

Prefs* CSV_IN::set_pref()
{
	return &_pref;
}


void CSV_IN::countCols(std::ifstream& inFile, char sep) {
	string line;
	std::getline(inFile, line);
	_nCols = std::count(line.begin(), line.end(), sep) + 1;
	if (_pref._has_header)
	{

	}
	else {
		inFile.clear();
		inFile.seekg(0);
	}
}


mat CSV_IN::absorb_to_mat()
{
	std::ifstream inFile;
	inFile.open(_inPath, std::ios::in);
	mat m;
	string line, cell;

	if (_pref._has_header)
	{
		std::getline(inFile, line);
	}

	//size_t col_count;
	
	while (inFile)
	{

		std::getline(inFile, line);
		std::stringstream linestream(line);

		std::vector<double> col;
		
		//col_count = (int)_pref._row_index;
		while (std::getline(linestream, cell, _sep))
		{
			
			col.push_back(std::stod(cell));
			//++col_count;
			
		}
		m.push_back(col);
		
		_nRows++;
	}
	--_nRows;

	std::cout << _nRows << " " << _pref._has_header <<  std::endl;

	return m;
}


int CSV_IN::read_csv() {
	
	std::ifstream inFile;
	inFile.open(_inPath, std::ios::in);

	if (!inFile) 
	{
		std::cerr << "could not read file" << std::endl;
		return 1;
	}
	else 
	{
		if (_pref._set_nCols == -1)
		{
			countCols(inFile, _sep); // updates _nCols if not set in _perf
		}
	}

	return 0;
}

