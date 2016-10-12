#include "Person.h"

class Employee : public Person
{
	char job[50];
public:
	void PersonInfo() override;
};
