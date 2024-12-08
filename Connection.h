#pragma once
#include "mysql.h"
#include <locale>
#include <string>
#include <lm.h>
#include"tables.h"
#include<vector>
using namespace std;
class CCarsTable;

class Connection
{
	protected:
		friend class CCarsTable;
	private:
		MYSQL* conn;
		MYSQL_RES* res, * reslogon, * reslogoff;
		MYSQL_ROW row;
		
	public:
		Connection();

		void Connect();
		void DisConnectr();

		vector<vector<CString>> SELECT(string sql);
		void UPDATE(string sql);
		void INSERT(string sql);
};

