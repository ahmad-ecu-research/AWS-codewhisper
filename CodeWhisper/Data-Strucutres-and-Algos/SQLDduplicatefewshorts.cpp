#include <iostream>
#include <fstream>
#include <sqlite3.h>


// function to delete duplicate emials from the database and keep emails with minimum ID lenght
void deleteDuplicateEmails(sqlite3 *db)
{
    char *zErrMsg = 0;
    int rc;
    const char *sql;

    // Assign the SQL query string
    sql = "DELETE FROM Emails WHERE Id NOT IN (SELECT MIN(Id) FROM Emails GROUP BY Email);";

    // Execute the SQL query
    rc = sqlite3_exec(db, sql, 0, 0, &zErrMsg);

    // Check for errors
    if (rc != SQLITE_OK)
    {
        // Handle the error, print an error message, or log it
        std::cerr << "SQL error: " << zErrMsg << std::endl;

        // Free the error message string
        sqlite3_free(zErrMsg);
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
        DeleteduplicateEmails(db);
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
    //ifstream file("emails.txt");
    ifstream infile("Emails.txt");
    string line;
    int id = 0;
        while (getline(infile, line))
    {
    // insert into eamils.text
// Insert data with parameterized query
    const char* insertEmailsSQL = "INSERT INTO Emails(id, email) VALUES(?, ?)";
    sqlite3_stmt* stmt;
    int rc = sqlite3_prepare_v2(db, insertEmailsSQL, -1, &stmt, nullptr);

    if (rc != SQLITE_OK) {
        std::cerr << "Error preparing insert statement." << std::endl;
        return 1;
    }

    // Assuming id and email are variables holding  data

    // few shorts 1 function for getting binding parameter values through user input
   
void getuservalues(int& id, std::string& email, sqlite3_stmt* stmt) {
    // Prompt user for input
    cout << "Please enter your ID: ";
    cin >> id;
    cout << "Please enter your email: ";
    cin >> email;

    // Bind values to SQLite statement
    sqlite3_bind_int(stmt, 1, id);
    sqlite3_bind_text(stmt, 2, email.c_str(), -1, SQLITE_STATIC);

    // few shorts 2, Execute the SQLite statement
    int rc = sqlite3_step(stmt);
    // Add error handling for SQLite operations
    if (rc != SQLITE_DONE) {
        std::cerr << "Error executing SQLite statement: " << sqlite3_errmsg(sqlite3_db_handle(stmt)) << std::endl;
    }
}

    if (rc != SQLITE_DONE) {
        std::cerr << "Error executing insert statement." << std::endl;
        return 1;
    }

    infile.close();
   // call delete duplicate Emails
deleteduplicateEmails(db);

ofstream outfile("Emails.txt");
sqlite3_stmt* stm;
string selectSQL= "Select Emails From Emails, ORDER BY ID";
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

















