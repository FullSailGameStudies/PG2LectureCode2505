#pragma once
#include <string>
#include <vector>
class FullSailCourse
{
public:
	const std::string& GetName() const
	{ 
		//SetName("Bruce Wayne");
		int num = 5;
		num++;//const does NOT affect local variables
		//name = "Bruce Wayne";//const prevents changes to CLASS members
		return name; 
	}
	void SetName(const std::string& newName);

	void FillGrades(std::vector<float>& course) const;


private:
	std::string name;
};

