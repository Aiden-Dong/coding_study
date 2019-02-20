# include <iostream>

using namespace std;

double warming = 0.3 ; 

void update (double dt);
void local ();

int main ()
{
	cout << "Global warming is  " << warming << " degrees." << endl;

	update (0.1);

	cout << "Global warming is  " << warming << " degrees." << endl;

	local ();

	cout << "Global warming is  " << warming << " degrees." << endl;

	return 0;

}
/*
在 VC++ 6.0 中的输出结果是 ：
============================
Global warming is  0.3 degrees.
Updating global warming to 0.4 degrees.
Global warming is  0.4 degrees.
local warming is  0.8 degrees.
But global warming = 0.4
Global warming is  0.4 degrees.
Press any key to continue
============================
*/