# Password Manager

## Overview

This project is a Password Manager application developed in C++ that allows users to securely store, encrypt, and retrieve their passwords. The application uses SQLite3 for database management and OpenSSL for encryption, ensuring that sensitive user information is well-protected.

## Features

- **Secure Storage**: Passwords are stored securely in a SQLite3 database.
- **AES-256 Encryption**: All passwords are encrypted using OpenSSL’s AES-256 algorithm before being stored.
- **Command-Line Interface**: The application provides a user-friendly CLI for managing passwords.
- **Cross-Platform**: Works on Windows, Linux, and macOS.

## Prerequisites

To build and run the Password Manager, you need the following:

- C++ Compiler (e.g., g++, clang++)
- SQLite3 library and headers
- OpenSSL library and headers

## Installation

### 1. Clone the Repository

```bash
git clone https://github.com/yourusername/PasswordManager.git
cd PasswordManager
sudo apt-get install libsqlite3-dev libssl-dev
g++ -o PasswordManager main.cpp DatabaseManager.cpp PasswordManager.cpp -lsqlite3 -lssl -lcrypto
./PasswordManager
```bash
## Usage
### 1. Add a Password:

. The application prompts for the account name and password.
. The password is encrypted and stored in the database.
### 2. Retrieve a Password:

. Provide the account name to retrieve the corresponding decrypted password.
### 3. Delete a Password:

. Select the account name to delete its associated password from the database.

## Future Enhancements
### GUI Version: Transition from CLI to a graphical user interface.
### Enhanced Security: Implement multi-factor authentication for added security.

## Author
### Saketh Malladi
