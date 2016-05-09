#pragma once
#include <iostream>
#include <boost/format.hpp>
#include <boost/date_time/gregorian/gregorian.hpp>
#include <boost/assert.hpp>
#include <boost/filesystem.hpp>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/ini_parser.hpp>
using namespace std;
using namespace boost;

namespace fs = boost::filesystem;


class Save
{
public:
	Save();
	
	void SaveManager(string, int);


private:
	string saveData1, saveData2, saveData3;
	//string saveData2;
	//string saveData3;
	
	//void Saving(string, string, int);
	//void SaveOverWrite(string, string);
	//void SaveDelete(string);

};