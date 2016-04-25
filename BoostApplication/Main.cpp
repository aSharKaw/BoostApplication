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
	cout << format("%1%%2%%3%") % "save/セーブ\n" % "copy/セーブデータのコピー\n" % "delete/セーブデータの削除\n" << endl;
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
		cout << "ファイルが既にあるけど上書きする？ y/n";
		cin >> flag;
		if (flag == "y")
		{
			fs::copy_file(path, dest, fs::copy_option::overwrite_if_exists);
			cout << format("%1% %2% %3% %4%") % origin_save % "を" % copy_save % "に上書きしました。" << endl;
		}
		else
		{
			cout << "キャンセルしました。" << endl;
		}

		//throw;
	}
}

void SaveDelete(string savePath)
{
	namespace fs = boost::filesystem;
	string flag;

	const fs::path path(savePath);

	cout << format("%1% %2%") % savePath % "を削除しますか y/n" << endl;
	cin >> flag;
	
	if (flag == "y")
	{
		fs::remove(path);
		cout << format("%1% %2%") % savePath % "を削除しました。" << endl;
	}
	else
	{
		cout << "キャンセルしました。" << endl;
	}
	
}

void LastDay()
{
	int year = 0;
	int month = 0;

	using namespace gregorian;

	cout << "西暦は？";
	cin >> year;
	cout << "月は？";
	cin >> month;


	BOOST_ASSERT_MSG(month < 12, "不正な値入力　プログラムを終了します。");


	const int printDay = gregorian_calendar::end_of_month_day(year, month);
	std::cout << format("%1% %2%　%3% %4% %5%") % year % "年" % month % "月の最終日は" % printDay << endl;

}


/////////////////////////


//BOOST_ASSERT(1 == 1);

//プログラムエラーで終了させる
//BOOST_ASSERT(1 != 1);

//文字表示
//cout << format("%1%") % "Hello!!" << endl;
