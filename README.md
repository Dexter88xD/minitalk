# Minitalk

``Minitalk`` is a simple communication program that enables message exchange between a client and a server using UNIX signals. It is designed as part of the 42 school curriculum to deepen understanding of signal handling and interprocess communication.

---
## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [File Structure](#file-structure)
- [Installation](#installation)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

---
## Introduction
Minitalk is a project that demonstrates interprocess communication by sending messages from a client to a server using **SIGUSR1** and **SIGUSR2** signals. The server receives and deciphers these signals into readable text. The project also includes a **bonus** version with additional enhancements.

---
## Features
### **1. Core Functionality**
- Send messages from a client to a server using UNIX signals.
- Display messages in real-time on the server.
- Support for multi-character messages.
- Utilises a custom **libft** for enhanced string manipulation and memory management.

### **2. Bonus Version**
- Acknowledgment messages for successful transmission.
- Send messages from a client to a server using UNIX and UNICODE signals.

---
## File Structure
```
└── dexter88xd-minitalk/
    ├── README.md
    ├── LICENSE
    ├── Makefile
    ├── minitalk.h
    ├── bonus/
    │   ├── client_bonus.c
    │   └── server_bonus.c
    ├── libft/
    │   ├── Makefile
    │   ├── libft.h
    │   └── src/
    └── src/
        ├── client.c
        └── server.c
```

---
## Installation
### **Step 1: Clone the Repository**
```bash
git clone https://github.com/Dexter88xD/minitalk.git
cd minitalk
```

### **Step 2: Build the Project**
- Compile the standard version:
  ```bash
  make
  ```
- Compile the bonus version:
  ```bash
  make bonus
  ```

### **Step 3: Cleaning Up**
- Remove object files:
  ```bash
  make clean
  ```
- Remove executables and object files:
  ```bash
  make fclean
  ```

---
## Usage
### **Starting the Server**
Before running the client, start the server by executing:
```bash
./server
```
The server will print its **PID** (Process ID), which you will need to send messages from the client.

### **Sending Messages with the Client**
Once the server is running, open another terminal and run:
```bash
./client <server_pid> "Your message here"
```
Replace `<server_pid>` with the actual PID displayed by the server.

### **Bonus Version**
The bonus version extends functionality by handling additional cases, such as acknowledgements and robustness improvements. Run the bonus programs similarly:
```bash
./server_bonus
./client_bonus <server_pid> "Your message here"
```

---
## Contributing
Contributions are welcome! Feel free to submit pull requests or open issues for discussion.

---
## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

