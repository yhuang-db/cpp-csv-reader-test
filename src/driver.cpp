//
// Created by Yuchuan Huang on 4/23/21.
//
#include "driver.h"

using csvmonkey::CsvCell;
using csvmonkey::CsvCursor;
using csvmonkey::CsvReader;
using csvmonkey::MappedFileCursor;

void use_fast_cpp_csv_parser_with_header() {
    std::string file = "../data/with_header.csv";
    io::CSVReader<3> in(file);
    in.read_header(io::ignore_extra_column, "id", "time", "val");
    int id;
    std::string time;
    double val;

    while (in.read_row(id, time, val)) {
        std::cout << id << "," << time << "," << val << std::endl;
    }
}

void use_fast_cpp_csv_parser_without_header() {
    std::string file = "../data/no_header.csv";
    io::CSVReader<3> in(file);
    in.set_header("id", "time", "val");
    int id;
    std::string time;
    double val;

    while (in.read_row(id, time, val)) {
        std::cout << id << "," << time << "," << val << std::endl;
    }
}

void use_csvmonkey_with_header() {
    std::string file = "../data/with_header.csv";
    MappedFileCursor stream;
    CsvReader<MappedFileCursor> reader(stream);
    stream.open(file.c_str());
    CsvCursor &row = reader.row();
    if (!reader.read_row()) {
        std::cerr << "Cannot read header row" << std::endl;
    }

    CsvCell *id;
    if (!row.by_value("id", id)) {
        std::cerr << "Cannot read column id" << std::endl;
    }
    CsvCell *time;
    if (!row.by_value("time", time)) {
        std::cerr << "Cannot read column time" << std::endl;
    }
    CsvCell *val;
    if (!row.by_value("val", val)) {
        std::cerr << "Cannot read column val" << std::endl;
    }

    while (reader.read_row()) {
        std::cout << (int) id->as_double() << "," << time->as_str() << "," << val->as_double() << std::endl;
    }
}
