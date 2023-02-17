#include <iostream>
#include <iomanip>
#include <pqxx/pqxx> 

using namespace std;

int main(int argc, char* argv[]) {

   // Connect To Database.
   // Note the connection type cannot be returned from a function.
   pqxx::connection Con("dbname = pg_cpp_example \
                         user     = jonathan \
                         password = password \
                         hostaddr = 127.0.0.1 \
                         port     = 5432");

   if (Con.is_open()) 
      cout << "Opened database successfully: " << Con.dbname() << endl;
   else {
      cout << "Can't open database" << endl;
      return 1;
   }

   // ----------------------------------------------------------------------------------------------
   // Create a Table.

   string sql;
   pqxx::work workload(Con);
   
   try {

      sql = 
         "CREATE TABLE COMPANY("  \
            "ID INT PRIMARY KEY     NOT NULL," \
            "NAME           TEXT    NOT NULL," \
            "AGE            INT     NOT NULL," \
            "ADDRESS        TEXT," \
            "SALARY         REAL );";

      workload.exec(sql);

      // -------------------------------------------------------------------------------------------
      // Insert Data Into Table.

      sql = 
         "INSERT INTO COMPANY (ID, NAME, AGE, ADDRESS, SALARY) "  \
            "VALUES (1, 'Paul', 32, 'California', 20000.00 ); " \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY) "  \
            "VALUES (2, 'Allen', 25, 'Texas', 15000.00 ); "     \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
            "VALUES (3, 'Teddy', 23, 'Norway', 20000.00 );" \
         "INSERT INTO COMPANY (ID,NAME,AGE,ADDRESS,SALARY)" \
            "VALUES (4, 'Mark', 25, 'Rich-Mond', 65000.00 );";

      workload.exec(sql);
      workload.commit();   // You may add worload.exec(sql) commands until you are ready to commit.

      // -------------------------------------------------------------------------------------------
      // Query Data in Table.

      sql = "SELECT * from COMPANY";

      pqxx::nontransaction getData(Con);
      pqxx::result output(getData.exec(sql));
      
      int colWidth = 12;
      cout << setw(5) << "ID" << setw(colWidth) << "Name" << setw(5)
           << "Age" << setw(colWidth) << "Address" << setw(colWidth) << "Salary" << "\n";
      cout << "----------------------------------------------\n";
      for (pqxx::result::const_iterator i = output.begin(); i != output.end(); i++) {
         cout << setw(5) << i[0].as<int>() << setw(colWidth) << i[1].as<string>() 
              << setw(5) << i[2].as<int>() << setw(colWidth) << i[3].as<string>() 
              << setw(colWidth) << i[4].as<int>() << "\n";
      }

      Con.disconnect ();
      
   } catch (const std::exception &e) {
      cerr << e.what() << endl;
      return 1;
   }

   return 0;
}