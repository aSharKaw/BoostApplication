#include <iostream>
//#include <boost/date_time/gregorian/gregorian.hpp>
//#include <boost/assert.hpp>
#include "Save.h"
#include "Load.h"

using namespace std;
//using namespace boost;


void main(int args, char* argv[])
{
	Save save;
	Load load;

	string player;
	int level = 0;

	while (1)
	{

		string mode;


		cin >> mode;
		if (mode == "name")
		{
			cin >> player;
		}
		else if (mode == "level")
		{
			level++;
		}
		else if (mode == "load")
		{
			player = load.getName();
			level = load.getLevel();

		}
		else if (mode == "save")
		{
			save.SaveManager(player, level);
		}

		cout << player << endl;
		cout << level << endl;

	}

}




//int SaveConfirmation(string saveFile_name, string player_name, int player_level)
//{
//	namespace propertyTree = boost::property_tree;
//
//	propertyTree::ptree pt;
//	read_ini(saveFile_name, pt);
//
//	if (boost::optional<string> value = pt.get_optional<string>("Data.Name"))
//	{
//		cout << "Name : " << value.get() << endl;
//		player_name = value.get();
//		//return player_level;
//	}
//	else
//	{
//		cout << "Name : �f�[�^����" << endl;
//	}
//	if (boost::optional<int> value = pt.get_optional<int>("Data.Level"))
//	{
//		cout << "Level : " << value.get() << endl;
//		player_level = value.get();
//		//return player_level;
//	}
//	else
//	{
//		cout << "Level : �f�[�^����" << endl;
//	}
//}





//void LastDay()
//{
//	int year = 0;
//	int month = 0;
//
//	using namespace gregorian;
//
//	cout << "����́H";
//	cin >> year;
//	cout << "���́H";
//	cin >> month;
//
//
//	BOOST_ASSERT_MSG(month < 12, "�s���Ȓl���́@�v���O�������I�����܂��B");
//
//
//	const int printDay = gregorian_calendar::end_of_month_day(year, month);
//	std::cout << format("%1% %2%�@%3% %4% %5%") % year % "�N" % month % "���̍ŏI����" % printDay << endl;
//
//}


/////////////////////////


//BOOST_ASSERT(1 == 1);

//�v���O�����G���[�ŏI��������
//BOOST_ASSERT(1 != 1);

//�����\��
//cout << format("%1%") % "Hello!!" << endl;
