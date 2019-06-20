#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	srand(time(0));
	int randomAct;
	do
	{
		randomAct = rand();
	} while (!(randomAct <= 3 && randomAct > 0));

	string command;
	cin >> command;

	if (command == "brother" || command == "Brother")
	{
		switch (randomAct)
		{
			case 1:
				cout << "Praise your brother directly, success or failure, present or past." << endl;
				break;
			case 2:
				cout << "Let your brother know how much of a friend he is to you." << endl;
				break;
			case 3:
				cout << "Pass something down to your brother if he is younger than you." << endl;
		}
	}
	else if (command == "sister" || command == "Sister")
	{
		switch (randomAct)
		{
			case 1:
				cout << "Buy your sister a small meaningfull gift. It doesn't have to be her birthday." << endl;
				break;
			case 2:
				cout << "Contact your sister to get to know how she's doing." << endl;
				break;
			case 3:
				cout << "Let your sister know she's beautiful." << endl;
		}
	}
	else if (command == "mother" || command == "Mother")
	{
		switch (randomAct)
		{
			case 1:
				cout << "Thank your mother for being there for you, especially if you don't live with her anymore." << endl;
				break;
			case 2:
				cout << "Do some chores or help your mother out with something maintaining a positive attitude." << endl;
				break;
			case 3:
				cout << "Get in contact with your mother, it is heartwarming when a mother hears her child." << endl;
		}
	}
	else if (command == "father" || command == "Father")
	{
		switch (randomAct)
		{
			case 1:
				cout << "Take the liberty of mowing the lawn, or helping your father with whatever project he's working on." << endl;
				break;
			case 2:
				cout << "Appreciate your father for supporting you for the decisions you took and are taking." << endl;
				break;
			case 3:
				cout << "Let your father know much you care about him even if you never really got along well." << endl;
		}
	}
	else if (command == "aunt" || command == "Aunt")
	{
		switch (randomAct)
		{
			case 1:
				cout << "Visit your aunt, it feels great when her siblings children visit her." << endl;
				break;
			case 2:
				cout << "Invite your aunt over, you'll get to know her more and understand appreciate the stories she had with your father/mother." << endl;
				break;
			case 3:
				cout << "Ask your aunt if you can come over. Bake something and have fun!" << endl;
		}
	}
	else if (command == "uncle" || command == "Uncle")
	{
		switch (randomAct)
		{
			case 1:
				cout << "Ask your uncle for advice you wouldn't want to tell your father." << endl;
				break;
			case 2:
				cout << "Go on an outdoors trip with your uncle." << endl;
				break;
			case 3:
				cout << "Play games with your uncle!" << endl;
		}
	}
	else if (command == "grandmother" || command == "Grandmother")
	{
		switch (randomAct)
		{
			case 1:
				cout << "Visit your grandmother unnoticed, she'll be overjoyed seeing you." << endl;
				break;
			case 2:
				cout << "Look at baby books or family books in general, with your grandmother." << endl;
				break;
			case 3:
				cout << "Buy your grandmother flowers on mother's day." << endl;
		}
	}
	else if (command == "grandfather" || command == "Grandfather")
	{
		switch (randomAct)
		{
			case 1:
				cout << "Go fishing with your grandfather." << endl;
				break;
			case 2:
				cout << "Play cards with your grandfather." << endl;
				break;
			case 3:
				cout << "Meet up with your grandfather, he has plenty of stories he'd love to tell you." << endl;
		}
	}
	else if (command == "cousin" || command == "Cousin")
	{
		switch (randomAct)
		{
			case 1:
				cout << "Offer to babysit their children if they need it." << endl;
				break;
			case 2:
				cout << "Don't just send birthday cards, call them and get up to date with them. Make them feel important to you." << endl;
				break;
			case 3:
				cout << "Go hiking, or some other similar activity with your cousin." << endl;
		}
	}
	else if (command == "daughter" || command == "Daughter")
	{
		switch (randomAct)
		{
			case 1:
				cout << "Take your daughter walking, she'll love the scenery." << endl;
				break;
			case 2:
				cout << "Always, take wholeheated consideration of what you daughter tells you."  << endl;
				break;
			case 3:
				cout << "Tell your daughter you love her every day." << endl;
		}
	}
	else if (command == "son" || command == "Son")
	{
		switch (randomAct)
		{
			case 1:
				cout << "Give him meaningful adive when he needs it. He may not understand something you're saying, so clear things up." << endl;
				break;
			case 2:
				cout << "Play outside and inside games with your son." << endl;
				break;
			case 3:
				cout << "Always, take wholeheated consideration of what you son tells you." << endl;
		}
	}
	else if (command == "spouse" || command == "Spouse")
	{
		switch (randomAct)
		{
			case 1:
				cout << "Take note of important dates, your spouse will appreciate it." << endl;
				break;
			case 2:
				cout << "Take the kids on walk while your spouse rests." << endl;
				break;
			case 3:
				cout << "Hug your spouse for about three minutes." << endl;
		}
	}
	else if (command == "grandchildren" || command == "Grandchildren")
	{
		switch (randomAct)
		{
			case 1:
				cout << "Go fishing with your grandchildren." << endl;
				break;
			case 2:
				cout << "Play games similar to chess with your grandchildren." << endl;
				break;
			case 3:
				cout << "Watch a sunset with your grandchildren." << endl;
		}
	}
	else if (command == "nephew" || command == "Nephew")
	{
		switch (randomAct)
		{
			case 1:
				cout << "Have fun with your nephew, even if you have to play a bit dangerously." << endl;
				break;
			case 2:
				cout << "Build something with your nephew." << endl;
				break;
			case 3:
				cout << "Acknoledge what you nephew does for fun, go do what he likes with him." << endl;
		}
	}
	else if (command == "niece" || command == "Niece")
	{
		switch (randomAct)
		{
		case 1:
			cout << "Have fun with your niece, make up imaginary stories." << endl;
			break;
		case 2:
			cout << "Decorate white t-shirts with your niece." << endl;
			break;
		case 3:
			cout << "Fly a kite with your niece! " << endl;
		}
	}

	else
		cout << "You incorrectly entered a family relative term.";

	return 0;
}