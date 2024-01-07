#include <msclr/marshal_cppstd.h>
#include <iostream>
#include <vector>

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Data;

// Assuming parsedData is a vector of pairs containing your initial data
std::vector<std::pair<std::string, std::string>> parsedData = /* your initial data */;

void Update2DMapFromDataGridView() {
    // Assuming your 2D map is a vector of vectors of strings
    std::vector<std::vector<std::string>> mapFromDataGrid;

    for (int row = 0; row < dataGridView1->Rows->Count; row++) {
        std::vector<std::string> rowData;

        for (int col = 0; col < dataGridView1->Columns->Count; col++) {
            String^ cellValue = safe_cast<String^>(dataGridView1->Rows[row]->Cells[col]->Value);
            rowData.push_back(msclr::interop::marshal_as<std::string>(cellValue));
        }

        mapFromDataGrid.push_back(rowData);
    }

    // Now mapFromDataGrid is your updated 2D map
    // You can use it as needed
}

// Event handler for CellValueChanged event
System::Void dataGridView1_CellValueChanged(System::Object^ sender, DataGridViewCellEventArgs^ e) {
    // Check if the change happened in a valid cell
    if (e->RowIndex >= 0 && e->ColumnIndex >= 0) {
        // Assuming the cell value is a string
        String^ modifiedValue = safe_cast<String^>(dataGridView1->Rows[e->RowIndex]->Cells[e->ColumnIndex]->Value);

        // Update the corresponding value in the 2D map
        parsedData[e->RowIndex][e->ColumnIndex] = msclr::interop::marshal_as<std::string>(modifiedValue);

        // You can now use parsedData or call Update2DMapFromDataGridView() as needed
    }
}

int main() {
    // Assuming you have a Form with a DataGridView named dataGridView1
    DataGridView^ dataGridView1 = gcnew DataGridView();

    // Attach the CellValueChanged event handler
    dataGridView1->CellValueChanged += gcnew DataGridViewCellEventHandler(&dataGridView1_CellValueChanged);

    // Assuming parsedData is a vector of pairs containing your initial data
    std::vector<std::pair<std::string, std::string>> parsedData = /* your initial data */;

    // ... (Code to populate dataGridView1 from parsedData)

    // Now dataGridView1 is populated with your initial data

    // Run the application
    Application::Run(dataGridView1);

    return 0;
}
