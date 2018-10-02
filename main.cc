#include <iostream>
#include <boost/bind.hpp>
#include <boost/function.hpp>

class ViewOptionsWidget;

class Preset{
public:
	void static f(int s, int t);
	void static set_preview(ViewOptionsWidget * w, int choice);
};

void Preset::f(int s, int t){
			std::cout << "f function print:"<< t <<std::endl;
}



class SelectionList{
public:
	typedef boost::function< void () > SelectionCallback;
};

class ViewOptionsWidget{
public:
	int check;
	ViewOptionsWidget(int i);
};



ViewOptionsWidget::ViewOptionsWidget(int i){
	check = 2;
	//&Preset::f;

	SelectionList::SelectionCallback cb =
	boost::bind(&Preset::f, 3, 4 );
	std::cout<<"calling ViewOptionsWidget constructor"<<std::endl;
	SelectionList::SelectionCallback cb1 =
	boost::bind(&Preset::f, 4, 3);
	SelectionList::SelectionCallback cb2 =
	boost::bind(&Preset::set_preview, this, 3);
	cb();
	cb1();
	cb2();
}
void Preset::set_preview(ViewOptionsWidget * w, int choice){
	w->check =4;
	std::cout<<"You choose " << choice<<std::endl;
}


int main(){

	typedef enum {
		PRESET_1 = 0,
		PRESET_2,
		PRESET_3,
		NUM_PRESETS      ///< Trick to remember how many modes there are
	} PresetMode;

	PresetMode m = PRESET_1;
	std::cout<<"PRESET:"<<PresetMode(2)<<std::endl;

	ViewOptionsWidget w(2);
	//SelectionList::SelectionCallback cb = boost::bind(&Preset::f, 4);

	//cb();

	std::cout<<"check:"<<w.check<<std::endl;




	std::cout<<"end of program"<<std::endl;

}
