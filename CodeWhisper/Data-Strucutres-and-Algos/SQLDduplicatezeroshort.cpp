#include <iostream>
#include <fstream>
#include <sqlite3.h>


// function to delete duplicate emials from the database and keep emails with minimum ID lenght
void deleteduplicateEmails(sqlite3 *db)
{
char *zErrMsg = 0;
    int rc;
    char *sql;
    sql = "CREATE TABLE IF NOT EXISTS temp(id INTEGER PRIMARY KEY AUTOINCREMENT, email TEXT UNIQUE)";
    rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
        cout<<"Error creating table: "<<zErrMsg<<endl;
        sqlite3_free(zErrMsg);
        delete from Emails where Id NOT IN (SELECT MIN(Id) FROM Emails GROUP BY Email);
        return;
    }
}
int main()
{

    // open database connection 
    sqlite3 *db;
    int rc = sqlite3_open("test.db", &db);
    if( rc ){
        cout<<"Can't open database: "<<sqlite3_errmsg(db)<<endl;
        return(0);
    }
    else{
        cout<<"Opened database successfully"<<endl;
        deleteduplicateEmails(db);
        sqlite3_close(db);
        return 0;
    }
    // create table in database for Emails list 
    char *zErrMsg = 0;
    int rc;
    char *sql;
    sql = "CREATE TABLE IF NOT EXISTS Emails(id INTEGER PRIMARY KEY AUTOINCREMENT, email TEXT UNIQUE)";
    rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);
    if( rc != SQLITE_OK ){
        cout<<"Error creating table: "<<zErrMsg<<endl;
        sqlite3_free(zErrMsg);
        return 0;
    }

    //  read file and insert Emails data with emails and IDs 
    ifstream file("emails.txt");
    ifstream infile("Emails.txt");
    string line;
    int id = 0;
        while (getline(infile, line))
    {
    // insert into eamils.text
string insertEmails = "INSERT INTO Emails(id, email) VALUES(?, ?)";
    sqlite3_stmt *stmt;
    rc = sqlite3_prepare_v2(db, insertEmails.c_str(), -1, &stmt, NULL);
    if (rc != SQLITE_OK)
    
    cout<<"failed to insert";
    
    }
    infile.close();
   // call delete duplicate Emails
deleteduplicateEmails(db);

ofstream outfile("Emails.txt");
sqlite3_stmt* stm;
string selectSQL= "Select Emails from Emails, order by ID";
if(sqlite3_prepare_v2(db, selectSQL.c_str(), -1, &stm, NULL)!=SQLITE_OK)
{
    while (sqlite3_step(stm) == SQLITE_ROW)

    {
        string email = (char*)sqlite3_column_text(stm, 0);
        outfile << sqlite3_column_text(stm, 0) << endl;
        outfile.close();

    }
    sqlite3_finalize(stm);
    sqlite3_close(db);
    return 0;

    
}
}    
















