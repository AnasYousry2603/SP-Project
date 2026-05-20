# Mini Hotel Reservation System

A console-based C++ hotel reservation system built as the main project entry point in `Final-Version/latesthotel.cpp`.

## Overview

This project simulates a hotel booking platform with separate admin and customer modes. It supports login/signup, room reservations, reservation edits, cancellations, and customer reviews.

## Main Features

- Admin account login
- Add and edit room reservations
- View room reviews
- Customer login and sign-up
- Add room reviews
- Cancel reservations
- Persistent data storage to text files

## Project Structure

- `Final-Version/latesthotel.cpp` - main C++ implementation
- `Final-Version/admins.txt` - saved admin credentials
- `Final-Version/customers.txt` - saved customer accounts
- `Final-Version/reviews.txt` - saved customer reviews
- `Final-Version/rooms.txt` - saved room availability and booking status

## Usage

When you run the program, it will load existing data from the `Final-Version` text files if available. If the files do not exist, the program initializes with sample admin and customer accounts.

The system provides a menu-based interface for:

- Admin actions: view reviews, add reservations, edit reservations, logout
- Customer actions: login, sign up, add reviews, cancel reservations

## Notes

- The application is designed for a 5-floor hotel with 10 rooms per floor.
- Sample admin usernames include `yahia`, `omarEmad`, `omarOsama`, `anas`, `moaz`, and `m7md`.
- Data persistence is handled through text files in the `Final-Version` folder.

## Contributing

This repository includes additional contributions in the `contributions/` folder. The main project entry point for the hotel system is `Final-Version/latesthotel.cpp`.
