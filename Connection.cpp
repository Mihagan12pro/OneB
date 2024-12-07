#include "pch.h"
#include "Connection.h"
Connection::Connection()
{

}

void Connection::Connect()
{
	conn = mysql_init(NULL);
	if (conn == NULL)
	{

	}
	// Подключаемся к серверу
	if (!mysql_real_connect(conn, "localhost", "root", "7kjwf*jaksdfVHJ8ds", "logistic", NULL, NULL, 0))
	{

	}
	else
	{

	}
	mysql_set_character_set(conn, "cp1251");
}
void Connection::DisConnectr()
{
	mysql_close(conn);
}
vector<vector<CString>> Connection::SELECT(string sql)
{
	mysql_query(conn,sql.c_str());

	res = mysql_store_result(conn);

	vector<vector<CString>> items;

	while (row = mysql_fetch_row(res))
	{
		vector<CString> subitems;
		for (int i = 0; i < mysql_num_fields(res);i++)
		{
			subitems.push_back(CString(row[i]));
		}
		items.push_back(subitems);

	}
	return items;
}