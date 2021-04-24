//
// Created by Yuchuan Huang on 4/23/21.
//
#include "csv.h"
#include "csv_parser.h"
#include "rapidcsv.h"
#include "csvmonkey.h"

#ifndef CPP_CSV_READERS_DRIVER_H
#define CPP_CSV_READERS_DRIVER_H

// ben-strasser/fast-cpp-csv-parser
void use_fast_cpp_csv_parser_with_header();

void use_fast_cpp_csv_parser_without_header();

// vincentlaucsb/csv-parser
void use_csv_parser_with_header();

void use_csv_parser_without_header();

// d99kris/rapidcsv
void use_rapidcsv_with_header();

void use_rapidcsv_without_header();

// dw/csvmonkey
void use_csvmonkey_with_header();

#endif //CPP_CSV_READERS_DRIVER_H
