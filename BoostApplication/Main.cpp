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

void SaveManager();


void main(int args, char* argv[])
{

	SaveManager();
	//Saving(saveData1, "taro", 10);
	//SaveOverWrite("sample1.txt", "sample2.txt");
	//SaveDelete("");
}




void Saving(string, string, int);
void SaveOverWrite(string, string);
void SaveDelete(string);

void SaveManager()
{
	string saveData1 = "save1.ini";
	string saveData2 = "save2.ini";
	string saveData3 = "save3.ini";


	string mode;
	cout << format("%1%%2%%3%") % "save/�Z�[�u\n" % "copy/�Z�[�u�f�[�^�̃R�s�[\n" % "delete/�Z�[�u�f�[�^�̍폜\n" << endl;
	cin >> mode;
	
	if (mode == "save")
	{
		Saving()
	}
}

void Saving(string savefile, string name, int level)
{
	namespace propertyTree = boost::property_tree;

	propertyTree::ptree pt;

	pt.put("Date.Name", name);
	pt.put("Data.Level", level);

	write_ini(savefile, pt);

}

void SaveOverWrite(string origin_save, string copy_save)
{
	namespace fs = boost::filesystem;


	const fs::path path(origin_save);
	const fs::path dest(copy_save);

	try
	{
		fs::copy_file(path, dest);
	}
	catch (fs::filesystem_error& ex)
	{
		string flag;
		cout << "�t�@�C�������ɂ��邯�Ǐ㏑������H y/n";
		cin >> flag;
		if (flag == "y")
		{
			fs::copy_file(path, dest, fs::copy_option::overwrite_if_exists);
			cout << format("%1% %2% %3% %4%") % origin_save % "��" % copy_save % "�ɏ㏑�����܂����B" << endl;
		}
		else
		{
			cout << "�L�����Z�����܂����B" << endl;
		}

		//throw;
	}
}

void SaveDelete(string savePath)
{
	namespace fs = boost::filesystem;
	string flag;

	const fs::path path(savePath);

	cout << format("%1% %2%") % savePath % "���폜���܂��� y/n" << endl;
	cin >> flag;
	
	if (flag == "y")
	{
		fs::remove(path);
		cout << format("%1% %2%") % savePath % "���폜���܂����B" << endl;
	}
	else
	{
		cout << "�L�����Z�����܂����B" << endl;
	}
	
}

void LastDay()
{
	int year = 0;
	int month = 0;

	using namespace gregorian;

	cout << "����́H";
	cin >> year;
	cout << "���́H";
	cin >> month;


	BOOST_ASSERT_MSG(month < 12, "�s���Ȓl���́@�v���O�������I�����܂��B");


	const int printDay = gregorian_calendar::end_of_month_day(year, month);
	std::cout << format("%1% %2%�@%3% %4% %5%") % year % "�N" % month % "���̍ŏI����" % printDay << endl;

}


/////////////////////////


//BOOST_ASSERT(1 == 1);

//�v���O�����G���[�ŏI��������
//BOOST_ASSERT(1 != 1);

//�����\��
//cout << format("%1%") % "Hello!!" << endl;
