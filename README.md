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

---
## File Structure
```
└── dexter88xd-minitalk/
    ├── README.md
    ├── LICENSE
    ├── Makefile
    ├── minitalk.h
    ├── libft/
    │   ├── Makefile
    │   ├── ft_atoi.c
    │   ├── ft_bzero.c
    │   ├── ft_calloc.c
    │   ├── ft_isalnum.c
    │   ├── ft_isalpha.c
    │   ├── ft_isascii.c
    │   ├── ft_isdigit.c
    │   ├── ft_isprint.c
    │   ├── ft_itoa.c
    │   ├── ft_lstadd_back_bonus.c
    │   ├── ft_lstadd_front_bonus.c
    │   ├── ft_lstclear_bonus.c
    │   ├── ft_lstdelone_bonus.c
    │   ├── ft_lstiter_bonus.c
    │   ├── ft_lstlast_bonus.c
    │   ├── ft_lstmap_bonus.c
    │   ├── ft_lstnew_bonus.c
    │   ├── ft_lstsize_bonus.c
    │   ├── ft_memchr.c
    │   ├── ft_memcmp.c
    │   ├── ft_memcpy.c
    │   ├── ft_memmove.c
    │   ├── ft_memset.c
    │   ├── ft_printf.c
    │   ├── ft_putchar_fd.c
    │   ├── ft_putendl_fd.c
    │   ├── ft_putnbr_fd.c
    │   ├── ft_putstr_fd.c
    │   ├── ft_split.c
    │   ├── ft_strchr.c
    │   ├── ft_strdup.c
    │   ├── ft_striteri.c
    │   ├── ft_strjoin.c
    │   ├── ft_strlcat.c
    │   ├── ft_strlcpy.c
    │   ├── ft_strlen.c
    │   ├── ft_strmapi.c
    │   ├── ft_strncmp.c
    │   ├── ft_strnstr.c
    │   ├── ft_strrchr.c
    │   ├── ft_strtrim.c
    │   ├── ft_substr.c
    │   ├── ft_tolower.c
    │   ├── ft_toupper.c
    │   ├── get_next_line.c
    │   ├── get_next_line_utils.c
    │   └── libft.h
    └── src/
        ├── client.c
        ├── server.c
        └── bonus/
            ├── client.c
            ├── client_bonus.c
            └── server_bonus.c
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

