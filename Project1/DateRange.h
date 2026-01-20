///////////////////////////////////////////////////////////
//  DateRange.h
//  Implementation of the Class DateRange
//  Created on:      19-???-2026 11:27:08
//  Original author: tkryb
///////////////////////////////////////////////////////////

#if !defined(EA_600BDD39_392E_43b5_BFA7_2951E3408516__INCLUDED_)
#define EA_600BDD39_392E_43b5_BFA7_2951E3408516__INCLUDED_

/**
 * ===================== ??????????????? ?????? =====================
 */
#include <ctime>
#include <memory>
class DateRange
{

public:
	DateRange();
	virtual ~DateRange();

private:
	std::tm endDate {};
	std::tm startDate {};

};
#endif // !defined(EA_600BDD39_392E_43b5_BFA7_2951E3408516__INCLUDED_)
