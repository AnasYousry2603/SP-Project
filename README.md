# Mini Hotel Reservation System

A console-based C++ hotel reservation system built as the main project entry point in `Final-Version/latesthotel.cpp`.

## Overview

This project simulates a hotel reservation application with separate admin and customer workflows. It provides a text-based menu interface for both roles and stores application data persistently in the `Final-Version` folder.

- Language: C++ (targeting modern C++ concepts though using simple language features for portability)
- Build system: compiler-driven, no external dependencies
- Data storage: file-based persistence with `std::ifstream` / `std::ofstream`
- Core data organization: custom structs, fixed-size arrays, and manual state tracking
- User interaction: command-line menus and console input validation
- Business logic: reservation lifecycle, date handling, availability checks, customer reviews, and admin reservation management

## Implementation Details

- `latesthotel.cpp` contains the full application implementation, including:
  - `Admin`, `Customer`, `Review`, `stRoom`, `Date`, and `stPeriod` structs
  - Menu-driven admin and customer interfaces
  - File I/O for loading and saving `admins.txt`, `customers.txt`, `reviews.txt`, and `rooms.txt`
  - Reservation management functions: create, edit, cancel, and review bookings
  - Date validation and comparison utilities for booking windows
  - Default fallback data for first-run initialization

- The hotel is statically modeled with:
  - `5` floors
  - `10` rooms per floor
  - up to `500` customers
  - up to `1,000` reviews


## Main Features

- Admin capabilities:
  - login using predefined or loaded admin accounts
  - add room reservations for customers
  - edit existing reservations
  - view room reviews
  - logout and save all application state

- Customer capabilities:
  - sign up and login
  - reserve rooms
  - add room reviews
  - cancel reservations
  - validate booking periods and room availability

- Persistence:
  - saved lists of admins, customers, rooms, and reviews
  - fallback sample accounts if data files do not exist on first run

## Project Structure

- `Final-Version/latesthotel.cpp` – main application file
- `Final-Version/admins.txt` – admin account storage
- `Final-Version/customers.txt` – customer account storage
- `Final-Version/reviews.txt` – review storage
- `Final-Version/rooms.txt` – room status storage
- `contributions/` – additional project contributions and alternate implementations

## Contributing

This repository includes additional contributions in the `contributions/` folder. The main project entry point for the hotel system is `Final-Version/latesthotel.cpp`.
