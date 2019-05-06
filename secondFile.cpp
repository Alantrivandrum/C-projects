#include <Iostream>
using namespace std;

class human {

public:
	void speak(int x)
	{
		switch (x)
		{
		case 0:
			cout << " Hi am a human" << endl;
			break;
		case 1:
			cout << "I am 18 years old" << endl ;
			break;
		case 2:
			cout << " I enjoy eating food" << endl;
			break;
		case 3:
			cout << " Goodbye " << endl;
			break;




		}

	}
};

	int main()
	{
		
		human myHuman;
		for(int a = 0; a <= INT16_MAX; a++)
		{
			cout <<  "Please enter any number from 0-3 or the letter 'e' to exit program " << endl;
			if (cin.get() == 'e')
			{
				cout << " Thanks for talking to me";
				break;
			}
			int x = 0;
			std::cin >> x;
			myHuman.speak(x);


		}




	}





