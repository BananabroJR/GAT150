#pragma once
#include<string>

namespace Skyers
{
	class Resource
	{
	public:
		virtual bool Create(std:: string filename, ...) = 0;

	};
}