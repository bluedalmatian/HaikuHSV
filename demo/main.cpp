
#include <string>
#include "HSVDemoApplication.h"


int main(int argc, char *argv[])
{

	std::string exe_invocation_path=argv[0]; //this is the path to this program, from the users shell prompts current working dir
	//trim exe_invocation_path from end back to last '/' so we have dir name without this prog name on the end
	//before we look for the '/' which separated this  prog name from the dir path ,we need to chomp off the last char in case its a trailing '/'
	exe_invocation_path.erase(exe_invocation_path.length()-1); //length returns num chars so length()-1 is index of last char	
	int lastslashindex = exe_invocation_path.rfind("/");  //find index of last '/'
	exe_invocation_path.erase(lastslashindex); //deletes from last '/' upto end of string

	HSVDemoApplication* app = new HSVDemoApplication(exe_invocation_path);
	app->Run();
	return 0;
}
