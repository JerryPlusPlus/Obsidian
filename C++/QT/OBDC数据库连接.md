![[ODBC中的mysql连接界面.png]]

```C++
QStringList drivers = QSqlDatabase::drivers();
for( QString driver: drivers)
{
    qDebug() << driver;
}
QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
db.setDatabaseName("Ubuntu_mysql");
db.setUserName("root");
db.setPassword("123456");
if (db.open())
    qDebug() << "数据库连接成功";
else
    qDebug() << "数据库连接失败";
QSqlQuery query;
if (!query.exec("select host,user from mysql.user;")) {
    qDebug() << "查询执行失败: " << query.lastError().text();
}

qDebug() << "query.size():"<<query.size();
while (query.next())
{
	qDebug() << query.value(0).toString() << query.value(1).toString();

}
```