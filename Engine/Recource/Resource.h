#pragma once
#include<string>

namespace Skyers
{
	class Resource
	{
	public:
		virtual bool Create(const std:: string& filename, void* data = nullptr) = 0;

	};
}