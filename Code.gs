// Fungsi doPost untuk menangani permintaan POST dari formulir web
const spreadsheet = SpreadsheetApp.getActive()
function doGet(e) {
  // Pastikan permintaan memiliki parameter 'kwh'
  if (e.parameter) {
    var watt = e.parameter.watt; // Ambil nilai kWh dari parameter 'watt'
    var ampere = e.parameter.ampere; // Ambil nilai kWh dari parameter 'ampere'
    var kwh = e.parameter.kwh; // Ambil nilai kWh dari parameter 'kwh'

    // Mendapatkan objek sheet berdasarkan nama
    var sheet = spreadsheet.getSheetByName('kost');

    // Menuliskan nilai kWh ke kolom C pada baris terakhir
    sheet.getRange('C3').setValue(watt);
    sheet.getRange('D3').setValue(ampere);
    sheet.getRange('E3').setValue(kwh);

    // Kirim respons balik (opsional)
    return ContentService.createTextOutput("Data kWh berhasil disimpan.");
  } else {
    // Jika parameter 'kwh' tidak ditemukan, kirim respons error
    return ContentService.createTextOutput("Parameter 'kwh' diperlukan.").setStatusCode(400);
  }
}
