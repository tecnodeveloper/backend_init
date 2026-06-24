#include <iostream>
#include <SQLiteCpp/SQLiteCpp.h>

int main() {
    try {
        // 1. Open or create a database file
        SQLite::Database db("test.db3", SQLite::OPEN_READWRITE | SQLite::OPEN_CREATE);
        std::cout << "Database opened successfully: " << db.getFilename() << std::endl;

        // 2. Create a simple table
        db.exec("CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY, name TEXT)");

        // 3. Insert data securely using a transaction and bind parameters
        SQLite::Transaction transaction(db);
        SQLite::Statement query(db, "INSERT INTO users (name) VALUES (?)");
        query.bind(1, "Alice");
        query.executeStep();
        transaction.commit(); // Save changes

        // 4. Query the data back
        SQLite::Statement selectQuery(db, "SELECT id, name FROM users");
        while (selectQuery.executeStep()) {
            int id = selectQuery.getColumn(0);
            std::string name = selectQuery.getColumn(1).getText();
            std::cout << "User [" << id << "]: " << name << std::endl;
        }
    }
    catch (std::exception& e) {
        std::cerr << "SQLite exception: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
