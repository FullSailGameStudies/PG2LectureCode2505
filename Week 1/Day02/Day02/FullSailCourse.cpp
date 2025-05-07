#include "FullSailCourse.h"

void FullSailCourse::SetName(const std::string& newName)
{
	if (newName.size() > 0 && newName.size() < 32)
		name = newName;
}

void FullSailCourse::FillGrades(std::vector<float>& course) const
{
    //add 10 grades to the course variable
    for (int i = 0; i < 10; i++)
    {
        course.push_back(rand() % 10001 / 100.0F);
    }
}
